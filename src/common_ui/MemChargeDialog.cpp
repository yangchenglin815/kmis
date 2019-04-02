#include "MemChargeDialog.h"
#include "ui_MemChargeDialog.h"
#include <QDebug>

MemChargeDialog::MemChargeDialog(QWidget *parent, EPayMethod ePayMethod )
    : QDialog(parent)
    , ui(new Ui::MemChargeDialog)
    , m_ePayMethod( ePayMethod )
    , m_eChargeStatus( StatementScaning )
    , m_sBarCode( "" )
    , m_sOldCode( "" )
    , m_sPayOrderNum( "" )
    , m_sChargeAmt( "" )
    , m_sGiftAmt( "" )
    , m_pBarCodeTimer( NULL )
    , m_nTime( 0 )
    , m_nTimerId( -1 )
    , m_pCloseWndTimer( NULL )
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( true );
    setWindowTitle( "会员充值" );

    initCtrl();
    initConnect();
    initTitle();
}

MemChargeDialog::~MemChargeDialog()
{
    delete ui;
}

//18位数字，没输入一位数字，处理时间为9毫秒，大概花费为200毫秒时间
void MemChargeDialog::keyPressEvent( QKeyEvent *event )
{
    //如果为支付宝付款或者微信支付
    if( m_eChargeStatus == StatementSuc ) return;

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
            //发送付款码给后台
            setStatus( StatementWaiting );
            ui->cancelButton->setEnabled( false );
            ui->titleWnd->setCloseButtonEnabled( false );
            emit sig_barCode();
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

    qDebug() << "MemChargeDialog::keyPressEvent:" << m_sBarCode<<event->text();
}

void MemChargeDialog::setAmtLabelText( QString strText )
{
    ui->rechargeLabel->setText( strText );
}

void MemChargeDialog::setContext( QString strChargeAmt, EStatementStatus eChargeStatus )
{
    ui->rechargeAmtLabel->setText( "￥" + strChargeAmt );
    m_sChargeAmt = strChargeAmt;
    m_eChargeStatus = eChargeStatus;
    QString strChargeStatus = enumToString( eChargeStatus );
    setStatusStyle( eChargeStatus );
    ui->statusValueLabel->setText( strChargeStatus );
    m_sBarCode = "";
    m_sOldCode = "";
}

void MemChargeDialog::slot_BarCodeTimer()
{
    ++m_nTime;
}

void MemChargeDialog::slot_closeWnd()
{
    m_pCloseWndTimer->stop();
    accept();
}

void MemChargeDialog::slot_barCode()
{
    if( m_sBarCode == m_sOldCode ) return;

    m_sOldCode = m_sBarCode;
    //发送付款码给后台
    emit sig_memChargeInfo( m_ePayMethod, m_sBarCode, m_sChargeAmt );
}

void MemChargeDialog::initCtrl()
{
    m_pBarCodeTimer = new QTimer( this );
    m_pCloseWndTimer = new QTimer( this );
}

void MemChargeDialog::initConnect()
{
    connect( m_pBarCodeTimer, SIGNAL(timeout()), this, SLOT( slot_BarCodeTimer() ) );
    connect( m_pCloseWndTimer, SIGNAL(timeout()), this, SLOT( slot_closeWnd() ) );

    connect( ui->refreshButton, SIGNAL(clicked()), this, SIGNAL(sig_refreshCharge() ) );
    connect( ui->cancelButton, SIGNAL(clicked()), this, SLOT( accept() ) );
    connect( ui->titleWnd, SIGNAL(sig_close_wnd()), this, SLOT( accept()) );

    connect( this, SIGNAL(sig_barCode()), this, SLOT( slot_barCode() ) );
}

void MemChargeDialog::initTitle()
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

void MemChargeDialog::setStatus( const EStatementStatus eChargeStatus )
{
    m_eChargeStatus = eChargeStatus;

    QString strChargeStatus = enumToString( eChargeStatus );
    setStatusStyle( eChargeStatus );
    ui->statusValueLabel->setText( strChargeStatus );
    if( m_eChargeStatus == StatementFailed ) {
        ui->refreshButton->setEnabled( true );
        ui->cancelButton->setEnabled( true );
        ui->titleWnd->setCloseButtonEnabled( true );
    } else if( m_eChargeStatus == StatementSuc ) {
        ui->refreshButton->setEnabled( false );
        ui->cancelButton->setEnabled( false );
        ui->titleWnd->setCloseButtonEnabled( true );
        m_pCloseWndTimer->start( 500 );
    } else {
        ui->refreshButton->setEnabled( false );
        ui->cancelButton->setEnabled( false );
        ui->titleWnd->setCloseButtonEnabled( false );
    }
}

QString MemChargeDialog::enumToString( const EStatementStatus &eChargeStatus )
{
    QString strStatusText = "";
    switch( eChargeStatus ) {
    case StatementWaiting:
        strStatusText = "支付中";
        break;
    case StatementSuc:
        strStatusText = "支付成功";
        break;
    case StatementFailed:
        strStatusText = "支付失败";
        break;
    case StatementScaning:
        strStatusText = "请扫码";
        break;
    default:
        break;
    }

    return strStatusText;
}

void MemChargeDialog::setStatusStyle( const EStatementStatus &eChargeStatus )
{
    switch( eChargeStatus ) {
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

void MemChargeDialog::setTitle( QString strTitle )
{
    ui->titleWnd->setTitleText( strTitle );
}

void MemChargeDialog::startTimer()
{
    if( m_nTimerId < 0 ) {
        m_pBarCodeTimer->start( 500 );
        m_nTimerId = m_pBarCodeTimer->timerId();
        m_nTime = 0;
    }
}

void MemChargeDialog::stopTimer()
{
    if( m_nTimerId> 0 ) {
        m_pBarCodeTimer->stop();
        m_nTimerId = -1;
        m_nTime = 0;
    }
}

