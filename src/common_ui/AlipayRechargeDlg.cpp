#include "AlipayRechargeDlg.h"
#include "ui_AlipayRechargeDlg.h"
#include "KPosLog.h"
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>

const int c_nAutoQueryLimit = 5;

AlipayRechargeDlg::AlipayRechargeDlg(QWidget *parent, EPayMethod ePayMethod, bool bRefund, QString strPayOrderNum) :
    QDialog(parent),
    ui(new Ui::AlipayRechargeDlg)
  , m_ePayMethod( ePayMethod )
  , m_eStatementStatus( StatementScaning )
  , m_sPayAmt( "" )
  , m_sBarCode( "" )
  , m_sOldCode( "" )
  , m_sPayOrderNum( strPayOrderNum )
  , m_pBarCodeTimer( NULL )
  , m_nTime( 0 )
  , m_nTimerId( -1 )
  , m_pGetPayStatusTimer( NULL )
  , m_nPayStatusTimerId( -1 )
  , m_pCloseWndTimer( NULL )
  , m_bRefund( bRefund )
  , m_pDlg(NULL)
  , m_nQueryCount(1)
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( true );

    initTitle();
    initCtrl();
    initConnect();
}

AlipayRechargeDlg::~AlipayRechargeDlg()
{
    delete ui;
}

//18位数字，没输入一位数字，处理时间为9毫秒，大概花费为200毫秒时间
void AlipayRechargeDlg::keyPressEvent( QKeyEvent *event )
{
    //如果为支付宝付款或者微信支付
    if( m_eStatementStatus == StatementSuc ) return;

    if( m_nTime >= 1 ) {
        stopTimer();
        m_sBarCode = "";
    }

    switch( m_ePayMethod ) {
    case PayAlipay:
    case PayWeChat:
    {
        if( m_sBarCode.length() < 18 ) {
            m_sBarCode = m_sBarCode + event->text();
        } else if( m_sBarCode.length() == 18 ) {
            emit sig_barCode();
            //发送付款码给后台
            //emit sig_createPayInfo( m_ePayMethod, m_sBarCode, m_sPayAmt );
//            ui->cancelButton->setEnabled( false );
//            ui->titleWnd->setCloseButtonEnabled( false );
        } else {
            startTimer();
        }
    }
        break;
    case ApplePay:
        break;
    case JdWallet:
        break;
    default:
        m_sBarCode = "";
        break;
    }

    //qDebug() << "AlipayRechargeDlg::keyPressEvent:" << m_sBarCode<<event->text();
}

void AlipayRechargeDlg::setAmtLabelText( QString strAmtLabelText )
{
    ui->rechargeLabel->setText( strAmtLabelText );
}

void AlipayRechargeDlg::setTitle( QString strTitle )
{
    ui->titleWnd->setTitleText( strTitle );
    setWindowTitle( strTitle );
}

void AlipayRechargeDlg::setContext( const QString &strAmt,  const EStatementStatus &eStatementStatus )
{
    ui->rechargeAmtLabel->setText( "￥" + strAmt );
    m_sPayAmt = strAmt;
    m_eStatementStatus = eStatementStatus;
    m_sBarCode = "";
    m_sOldCode = "";

    QString strStatementStatus = enumToString( eStatementStatus );
    setStatusStyle( eStatementStatus );
    ui->statusValueLabel->setText( strStatementStatus );
}

void AlipayRechargeDlg::setStatus( const EStatementStatus &eStatementStatus )
{
    m_eStatementStatus = eStatementStatus;

    QString strStatementStatus = enumToString( eStatementStatus );
    setStatusStyle( eStatementStatus );
    ui->statusValueLabel->setText( strStatementStatus );
}

//void AlipayRechargeDlg::setRefresh(bool Status)
//{
//    ui->refreshButton->setEnabled(Status);
//}

EStatementStatus AlipayRechargeDlg::getStatus()
{
    return m_eStatementStatus;
}

//void AlipayRechargeDlg::setPayMethod( const EPayMethod &ePayMethod )
//{
//    m_ePayMethod = ePayMethod;
//}

EPayMethod AlipayRechargeDlg::getPayMethod()
{
    return m_ePayMethod;
}

bool AlipayRechargeDlg::getRefund()
{
    return m_bRefund;
}

QString AlipayRechargeDlg::getOrderNum()
{
    return m_sPayOrderNum;
}

void AlipayRechargeDlg::slot_GetCreatePayInfo( int nCode, QString strMsg \
                                 , QString strOrderNumS, QString strAuthCode, EPayMethod ePayMethod )
{
    if( ePayMethod == PayMemCard ) return;

//    if( strAuthCode == m_sBarCode && nCode == e_success ) {
        m_eStatementStatus = StatementWaiting;
//        startQueryStatusTimer(true);
//    } else {
//        m_eStatementStatus = StatementFailed;
//        stopQueryStatusTimer();
//        ui->cancelButton->setEnabled( true );
//        ui->titleWnd->setCloseButtonEnabled( true );
//    }
    m_sPayOrderNum = strOrderNumS;
    setStatusStyle( m_eStatementStatus );
    ui->statusValueLabel->setText( enumToString( m_eStatementStatus )  );

    KPosLog::instance()->writeDebugLog( "AlipayRechargeDlg::slot_GetCreatePayInfo" + strMsg + "内部付款码：" + strOrderNumS );

    startQueryStatusTimer(true);
}

void AlipayRechargeDlg::slot_GetPayStatus( int nCode, QString strMsg, QString strOrderNumS, int nTradeState)
{
    KPosLog::instance()->writeDebugLog( "AlipayRechargeDlg::slot_GetPayStatus" + strMsg +"付款码："
                                        + strOrderNumS + "状态:" + QString::number(nTradeState));

    if( m_sPayOrderNum.isEmpty() ) {
        m_sPayOrderNum = strOrderNumS;
    }

    if(  nCode == e_success )
    {
        switch( nTradeState ) {
        case eTradeSuc:
            if( !m_bRefund ) {
                m_eStatementStatus = StatementSuc;
                //等待1s，关闭窗口
                emit sig_payInfo( strOrderNumS, StatementSuc, m_sBarCode);
                stopQueryStatusTimer();
                m_pCloseWndTimer->start( 1000 );
                setStatusStyle( m_eStatementStatus );
                ui->statusValueLabel->setText( enumToString( m_eStatementStatus )  );
                return;
            }
            break;
        case eTradeWaiting:
            m_eStatementStatus = StatementWaiting;
            setStatusStyle(m_eStatementStatus);
            startQueryStatusTimer();
            break;
        case eTradeFailed:
        case eTradeRevoke:
        default:
            m_eStatementStatus = StatementFailed;
            setStatusStyle( m_eStatementStatus );
            ui->statusValueLabel->setText( enumToString( m_eStatementStatus )  );
            stopQueryStatusTimer();
            break;
        }
    }
    else
    {
        m_eStatementStatus = StatementWaiting;
        setStatusStyle(m_eStatementStatus);
        ui->statusValueLabel->setText( enumToString( m_eStatementStatus )  );
        startQueryStatusTimer();
    }
}

void AlipayRechargeDlg::initTitle()
{
    switch ( m_ePayMethod ) {
    case PayMemCard:
        break;
    case PayStoreCard:
        break;
    case PayAlipay:
        setTitle( "支付宝" );
        break;
    case PayWeChat:
        setTitle( "微信" );
        break;
    case ApplePay:
        setTitle( "Apple" );
        break;
    case JdWallet:
        setTitle( "京东钱包" );
        break;
    default:
        break;
    }
}

void AlipayRechargeDlg::initCtrl()
{
    initTimer();
}

void AlipayRechargeDlg::initTimer()
{
    m_pBarCodeTimer = new QTimer( this );

    m_pGetPayStatusTimer = new QTimer( this );
    m_pCloseWndTimer = new QTimer( this );
}

void AlipayRechargeDlg::initConnect()
{
    connect( ui->refreshButton, SIGNAL(clicked()), this, SLOT( slot_payInfo() ) );
    connect( ui->cancelButton, SIGNAL(clicked()), this, SLOT( slot_closeWnd()) );
    connect( ui->titleWnd, SIGNAL(sig_close_wnd()), this, SLOT( slot_closeWnd()) );

    connect( m_pBarCodeTimer, SIGNAL(timeout()), this, SLOT( slot_BarCodeTimer() ) );
    connect( m_pGetPayStatusTimer, SIGNAL(timeout()), this, SLOT( slot_getPayStatus() ) );
    connect( m_pCloseWndTimer, SIGNAL(timeout()), this, SIGNAL( sig_closeWnd() ) );

    connect( this, SIGNAL(sig_barCode()), this, SLOT( slot_barCode() ) );
}

void AlipayRechargeDlg::setStatusStyle( const EStatementStatus &eStatementStatus )
{
    switch( eStatementStatus ) {
    case StatementWaiting:
        ui->statusValueLabel->setStyleSheet( "font-size:14px;color: rgb(234, 136, 82);");
        break;
    case StatementSuc:
        ui->statusValueLabel->setStyleSheet( "font-size:14px;color: rgb(117, 171, 87);" );
        break;
    case StatementFailed:
        ui->statusValueLabel->setStyleSheet( "font-size:14px;color: rgb(250, 122, 122);" );
        break;
    case StatementScaning:
        ui->statusValueLabel->setStyleSheet( "font-size:14px;color: rgb(81, 139, 234);" );
        break;
    default:
        break;
    }
}

QString AlipayRechargeDlg::enumToString( const EStatementStatus &eStatementStatus )
{
    QString strStatusText = "";
    switch( eStatementStatus ) {
    case StatementWaiting:
        strStatusText = "支付中";
//        ui->refreshButton->setEnabled(false);
        break;
    case StatementSuc:
        strStatusText = "支付成功";
//        ui->refreshButton->setEnabled(false);
        break;
    case StatementFailed:
        strStatusText = "支付失败";
//        ui->refreshButton->setEnabled(true);
        break;
    case StatementScaning:
        strStatusText = "请扫码";
//        ui->refreshButton->setEnabled(false);
        break;
    default:
        break;
    }

    return strStatusText;
}

void AlipayRechargeDlg::startTimer()
{
    if( m_nTimerId < 0 ) {
        m_pBarCodeTimer->start( 1000*10 );//10秒
        m_nTimerId = m_pBarCodeTimer->timerId();
        m_nTime = 0;
    }
}

void AlipayRechargeDlg::stopTimer()
{
    if( m_nTimerId> 0 ) {
        m_pBarCodeTimer->stop();
        m_nTimerId = -1;
        m_nTime = 0;
    }
}

void AlipayRechargeDlg::startQueryStatusTimer(bool bStartNow)
{
    if( m_nPayStatusTimerId < 0 ) {
        if (bStartNow)
        {
            m_nQueryCount = 1;
            ui->cancelButton->setEnabled(true);
            ui->titleWnd->setCloseButtonEnabled(true);
        }
        else
        {
            m_nQueryCount++;
            if (m_nQueryCount >= c_nAutoQueryLimit)
            {
                stopQueryStatusTimer();
                return;
            }
        }
        m_pGetPayStatusTimer->start(bStartNow ? 0 : 2000);
        m_nPayStatusTimerId = m_pGetPayStatusTimer->timerId();
    }
}

void AlipayRechargeDlg::stopQueryStatusTimer()
{
    if( m_nPayStatusTimerId> 0 ) {
        m_pGetPayStatusTimer->stop();
        m_nPayStatusTimerId = -1;
    }
    ui->refreshButton->setEnabled(true);
}

void AlipayRechargeDlg::stopAllTimer()
{
    m_pBarCodeTimer->stop();
    m_pGetPayStatusTimer->stop();
    m_pCloseWndTimer->stop();
    if (m_pDlg != NULL)
    {
        m_pDlg->hide();
    }
}

void AlipayRechargeDlg::setCurPayMethod(EPayMethod ePayMethod)
{
    m_ePayMethod = ePayMethod;
    initTitle();
}

void AlipayRechargeDlg::slot_payInfo()
{
    switch( m_eStatementStatus ) {
    case StatementSuc:
        return;
        break;
    case StatementWaiting:
        slot_getPayStatus();
        break;
    case StatementFailed:
    {
        if( !m_bRefund ) {
            QString strPayNum = "";
            if( m_sPayOrderNum.isEmpty() ) {
                strPayNum = m_sBarCode;
            } else {
                strPayNum = m_sPayOrderNum;
            }
            emit sig_getPayStatus( m_ePayMethod, strPayNum );
            //发送付款码给后台
            //emit sig_createPayInfo( m_ePayMethod, m_sBarCode, m_sPayAmt );
        } else {
            emit sig_payRevoke( m_sPayOrderNum );
        }
        m_eStatementStatus = StatementWaiting;
        setStatusStyle( m_eStatementStatus );
        ui->statusValueLabel->setText( enumToString( m_eStatementStatus )  );
//        ui->cancelButton->setEnabled( true );
//        ui->titleWnd->setCloseButtonEnabled( true );
        qDebug()<<"AlipayRechargeDlg::slot_payInfo"<<m_sPayOrderNum;
    }
        break;
    default:
        break;
    }
}

void AlipayRechargeDlg::slot_BarCodeTimer()
{
    ++m_nTime;
}

void AlipayRechargeDlg::slot_getPayStatus()
{
    stopQueryStatusTimer();

    QString strPayNum = "";
    if( m_sPayOrderNum.isEmpty() ) {
        strPayNum = m_sBarCode;
    } else {
        strPayNum = m_sPayOrderNum;
    }

    //发送查询状态的信息
    emit sig_getPayStatus( m_ePayMethod, strPayNum );
}

void AlipayRechargeDlg::slot_closeWnd()
{
    if (m_eStatementStatus == StatementScaning)
    {
        emit sig_closeWnd();
        return;
    }

    if( (m_eStatementStatus == StatementWaiting) || (m_eStatementStatus == StatementFailed))
    {
        if ((m_eStatementStatus == StatementWaiting) && (m_nQueryCount < c_nAutoQueryLimit))
        {
            QMessageBox::information(this, QStringLiteral("提示"),
                                     QStringLiteral("需要自动查询%1次，还剩%2次，每次约2秒").arg(c_nAutoQueryLimit).arg(c_nAutoQueryLimit - m_nQueryCount));
            return;
        }

        if (m_pDlg == NULL)
        {
            m_pDlg = new DlgCommon();
            m_pDlg->set_title( "支付" );
    //        pDlg->set_content( "是否取消支付？" );
            m_pDlg->set_content( "请收银员确认对方手机是否支付完成？" );
            m_pDlg->set_btn_sure_text("支付完成");
            m_pDlg->set_btn_cancel_text("未支付");
            connect( m_pDlg, SIGNAL(sig_dlg_close()), this, SLOT( slot_closeDlg() ) );
            connect( m_pDlg, &DlgCommon::sig_btn_cancel, this, &AlipayRechargeDlg::slot_cancleDlg);
            connect( m_pDlg, SIGNAL(sig_btn_sure()), this, SLOT( slot_sure() ) );
        }
        m_pDlg->activateWindow();
        m_pDlg->showNormal();
    } else {
        emit sig_payInfo( m_sBarCode, m_eStatementStatus, m_sBarCode);
        emit sig_closeWnd();
    }
}

void AlipayRechargeDlg::slot_cancleDlg()
{
    KPosLog::instance()->writeErrorLog(QStringLiteral("收银员手动确认未支付."));

    m_pDlg->hide();
    m_eStatementStatus = StatementFailed;
    emit sig_payInfo( m_sBarCode, m_eStatementStatus, m_sBarCode);
    emit sig_closeWnd();
//    m_pDlg->hide();
}

void AlipayRechargeDlg::slot_closeDlg()
{
    m_pDlg->hide();
    this->activateWindow();
    this->showNormal();

////    QObject *pObj = QObject::sender();
////    if( pObj ) {
////        delete pObj;
////        pObj = NULL;
////    }
//    m_pDlg->hide();
//    m_eStatementStatus = StatementFailed;
//    emit sig_payInfo( m_sBarCode, m_eStatementStatus, m_sBarCode);
//    emit sig_closeWnd();
}

void AlipayRechargeDlg::slot_sure()
{
//    QObject *pObj = QObject::sender();
//    if( pObj ) {
//        delete pObj;
//        pObj = NULL;
//    }

//    switch ( m_eStatementStatus ) {
//    case StatementWaiting:
//    case StatementSuc:
//    {
//        emit sig_payRevoke( m_sPayOrderNum );
//        emit sig_closeWnd();
//    }
//        break;
//    default:
//        break;
//    }

    KPosLog::instance()->writeErrorLog(QStringLiteral("收银员手动确认已完成支付."));

    m_pDlg->hide();
    m_eStatementStatus = StatementSuc;
    emit sig_payInfo( m_sBarCode, m_eStatementStatus, m_sBarCode);
    emit sig_closeWnd();
}

void AlipayRechargeDlg::slot_barCode()
{
    if( m_sBarCode == m_sOldCode ) return;

    ui->cancelButton->setEnabled(false);
    ui->titleWnd->setCloseButtonEnabled(false);
    ui->refreshButton->setEnabled(false);
    qDebug()<<"AlipayRechargeDlg::slot_barCode"<<m_sBarCode<<m_sOldCode;

    m_sOldCode = m_sBarCode;
    //发送付款码给后台
    emit sig_createPayInfo( m_ePayMethod, m_sBarCode, m_sPayAmt );
}
