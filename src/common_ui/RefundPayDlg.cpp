#include "RefundPayDlg.h"
#include "ui_RefundPayDlg.h"
#include <QDateTime>
#include <QDebug>
#include "DlgCommon.h"

RefundPayDlg::RefundPayDlg(QWidget *parent, EPayMethod ePayMethod, QString strPayOrderNum) :
    QDialog(parent),
    ui(new Ui::RefundPayDlg)
  , m_ePayMethod( ePayMethod )
  , m_eRefundStatus( RefundWaiting )
  , m_sPayAmt( "" )
  , m_sBarCode( "" )
  , m_sPayOrderNum( strPayOrderNum )
  , m_pGetPayStatusTimer( NULL )
  , m_nPayStatusTimerId( -1 )
  , m_pCloseWndTimer( NULL )
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( true );

    initTitle();
    initCtrl();
    initConnect();
    setWindowTitle( "退款" );
}

RefundPayDlg::~RefundPayDlg()
{
    delete ui;
}

void RefundPayDlg::setAmtLabelText( QString strAmtLabelText )
{
    ui->rechargeLabel->setText( strAmtLabelText );
}

void RefundPayDlg::setTitle( QString strTitle )
{
    ui->titleWnd->setTitleText( strTitle );
}

void RefundPayDlg::setContext( const QString &strAmt,  const ERefundStatus &eRefundStatus )
{
    ui->rechargeAmtLabel->setText( "￥" + strAmt );
    m_sPayAmt = strAmt;
    m_eRefundStatus = eRefundStatus;

    QString strStatementStatus = enumToString( eRefundStatus );
    setStatusStyle( eRefundStatus );
    ui->statusValueLabel->setText( strStatementStatus );
}

void RefundPayDlg::setStatus( const ERefundStatus &eRefundStatus )
{
    m_eRefundStatus = eRefundStatus;

    QString strStatementStatus = enumToString( eRefundStatus );
    setStatusStyle( eRefundStatus );
    ui->statusValueLabel->setText( strStatementStatus );
}

ERefundStatus RefundPayDlg::getStatus()
{
    return m_eRefundStatus;
}

void RefundPayDlg::setPayMethod( const EPayMethod &ePayMethod )
{
    m_ePayMethod = ePayMethod;
}

EPayMethod RefundPayDlg::getPayMethod()
{
    return m_ePayMethod;
}

QString RefundPayDlg::getOrderNum()
{
    return m_sPayOrderNum;
}

void RefundPayDlg::slot_GetCreatePayInfo( int nCode, QString strMsg \
                                 , QString strOrderNumS, QString strAuthCode)
{
    Q_UNUSED( strMsg )

    if( strAuthCode == m_sBarCode && nCode == e_success ) {
        m_eRefundStatus = RefundWaiting;
        startQueryStatusTimer();
    } else {
        m_eRefundStatus = RefundFailed;
        stopQueryStatusTimer();
    }
    m_sPayOrderNum = strOrderNumS;
    setStatusStyle( m_eRefundStatus );
    ui->statusValueLabel->setText( enumToString( m_eRefundStatus )  );

}

void RefundPayDlg::slot_RevokePay(int nCode, QString strMsg, QString strOrderNumS, int nRevokeStatus)
{
    Q_UNUSED( strMsg )
    if( m_sPayOrderNum != strOrderNumS ) {
        return;
    }

    if(  nCode == e_success ) {
        switch( nRevokeStatus ) {
        case 0:
        {
            m_eRefundStatus =RefundFailed;
            emit sig_payInfo( strOrderNumS, RefundFailed );
            stopQueryStatusTimer();
        }
            break;
        case 1:
            m_eRefundStatus = RefundSuc;
            emit sig_payInfo( strOrderNumS, RefundSuc );
            stopQueryStatusTimer();
            m_pCloseWndTimer->start( 1000 );
            break;
        default:
            stopQueryStatusTimer();
            break;
        }
    } else {
        m_eRefundStatus = RefundFailed;
        stopQueryStatusTimer();
    }
    setStatusStyle( m_eRefundStatus );
    ui->statusValueLabel->setText( enumToString( m_eRefundStatus )  );
}

void RefundPayDlg::slot_MemRevokePay(int nCode, QString strMsg, QString strOrderNumS, int nRevokeStatus, QString strMemCardBalance, int nMemCardIntegral )
{
    Q_UNUSED( strMemCardBalance )
    Q_UNUSED( nMemCardIntegral )

    slot_RevokePay( nCode, strMsg, strOrderNumS, nRevokeStatus );
}

void RefundPayDlg::slot_GetPayStatus( int nCode, QString strMsg \
                                         , QString strOrderNumS, int nTradeState)
{
    Q_UNUSED( strMsg )

    if( m_sPayOrderNum != strOrderNumS ) {
        return;
    }

    if(  nCode == e_success ) {
        switch( nTradeState ) {
//        case eTradeSuc:
//        {
//            m_eRefundStatus = RefundSuc;
//            //等待1s，关闭窗口
//            emit sig_payInfo( strOrderNumS, RefundSuc );
//            stopQueryStatusTimer();
//            m_pCloseWndTimer->start( 1000 );
//        }
//            break;
//        case eTradeWaiting:
//            m_eRefundStatus = RefundWaiting;
//            break;
//        case eTradeFailed:
//            m_eRefundStatus =RefundFailed;
//            emit sig_payInfo( strOrderNumS, RefundFailed );
//            stopQueryStatusTimer();
//            break;
        case eTradeRevoke:
            m_eRefundStatus = RefundSuc;
            emit sig_payInfo( strOrderNumS, RefundSuc );
            stopQueryStatusTimer();
            m_pCloseWndTimer->start( 1000 );
            break;
        case eTradeTransferRefund://退款中
            m_eRefundStatus = RefundWaiting;
            break;
        case eTradeNoPay://未支付
            break;
        case eTradeClosed://已关闭
            break;
        case eTradeRefund://7.未付款交易超时关闭，或支付完成后全额退款
            if( m_ePayMethod == PayAlipay ) {
                m_eRefundStatus = RefundSuc;
                emit sig_payInfo( strOrderNumS, RefundSuc );
                stopQueryStatusTimer();
                m_pCloseWndTimer->start( 1000 );
            }
            break;
        default:
            stopQueryStatusTimer();
            break;
        }
    } else {
        m_eRefundStatus = RefundFailed;
        stopQueryStatusTimer();
    }
    setStatusStyle( m_eRefundStatus );
    ui->statusValueLabel->setText( enumToString( m_eRefundStatus )  );
}

void RefundPayDlg::initTitle()
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

void RefundPayDlg::initCtrl()
{
    initTimer();
}

void RefundPayDlg::initTimer()
{
    m_pGetPayStatusTimer = new QTimer( this );
    m_pCloseWndTimer = new QTimer( this );
}

void RefundPayDlg::initConnect()
{
    connect( ui->refreshButton, SIGNAL(clicked()), this, SLOT( slot_payInfo() ) );
    connect( ui->cancelButton, SIGNAL(clicked()), this, SLOT( slot_closeWnd()) );
    connect( ui->titleWnd, SIGNAL(sig_close_wnd()), this, SLOT( slot_closeWnd()) );

    connect( m_pGetPayStatusTimer, SIGNAL(timeout()), this, SLOT( slot_getPayStatus() ) );
    connect( m_pCloseWndTimer, SIGNAL(timeout()), this, SIGNAL( sig_closeWnd() ) );
}

void RefundPayDlg::setStatusStyle( const ERefundStatus &eRefundStatus )
{
    switch( eRefundStatus ) {
    case RefundWaiting:
        ui->statusValueLabel->setStyleSheet( "font-size:14px;color: rgb(234, 136, 82);");
        break;
    case RefundSuc:
        ui->statusValueLabel->setStyleSheet( "font-size:14px;color: rgb(117, 171, 87);" );
        break;
    case RefundFailed:
        ui->statusValueLabel->setStyleSheet( "font-size:14px;color: rgb(250, 122, 122);" );
        break;
    default:
        break;
    }
}

QString RefundPayDlg::enumToString( const ERefundStatus &eRefundStatus )
{
    QString strStatusText = "";
    switch( eRefundStatus ) {
    case RefundWaiting:
        strStatusText = "退款中";
        break;
    case RefundSuc:
        strStatusText = "退款成功";
        break;
    case RefundFailed:
        strStatusText = "退款失败";
        break;
    default:
        break;
    }

    return strStatusText;
}

void RefundPayDlg::startQueryStatusTimer()
{
    if( m_nPayStatusTimerId < 0 ) {
        m_pGetPayStatusTimer->start( 5000 );
        m_nPayStatusTimerId = m_pGetPayStatusTimer->timerId();
    }
}

void RefundPayDlg::stopQueryStatusTimer()
{
    if( m_nPayStatusTimerId> 0 ) {
        m_pGetPayStatusTimer->stop();
        m_nPayStatusTimerId = -1;
    }
}

void RefundPayDlg::slot_payInfo()
{
    switch( m_eRefundStatus ) {
    case RefundSuc:
        return;
        break;
    case RefundWaiting:
        slot_getPayStatus();
        break;
    case RefundFailed:
    {
        emit sig_payRevoke( m_sPayOrderNum );
        m_eRefundStatus = RefundWaiting;
        setStatusStyle( m_eRefundStatus );
        ui->statusValueLabel->setText( enumToString( m_eRefundStatus )  );
    }
        break;
    default:
        break;
    }
}

void RefundPayDlg::slot_getPayStatus()
{
    //发送查询状态的信息
    emit sig_getPayStatus( m_ePayMethod, m_sPayOrderNum );
}

void RefundPayDlg::slot_closeWnd()
{
    if( m_eRefundStatus == RefundWaiting ) {
        DlgCommon *pDlg = new DlgCommon();
        pDlg->set_title( "支付" );
        pDlg->set_content( "是否取消支付？" );
        connect( pDlg, SIGNAL(sig_dlg_close()), this, SLOT( slot_closeDlg() ) );
        connect( pDlg, SIGNAL(sig_btn_cancel()), this, SLOT( slot_closeDlg() ) );
        connect( pDlg, SIGNAL(sig_btn_sure()), this, SLOT( slot_sure() ) );
        pDlg->show();
    } else {
        emit sig_closeWnd();
    }
}

void RefundPayDlg::slot_closeDlg()
{
    QObject *pObj = QObject::sender();
    if( pObj ) {
        delete pObj;
        pObj = NULL;
    }
}

void RefundPayDlg::slot_sure()
{
    QObject *pObj = QObject::sender();
    if( pObj ) {
        delete pObj;
        pObj = NULL;
    }

    switch ( m_eRefundStatus ) {
    case RefundWaiting:
    case RefundSuc:
    {
        emit sig_payRevoke( m_sPayOrderNum );
        emit sig_closeWnd();
    }
        break;
    default:
        break;
    }


}
