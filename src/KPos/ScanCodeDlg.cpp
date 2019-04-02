#include "ScanCodeDlg.h"
#include "ui_ScanCodeDlg.h"
#include <QDebug>

ScanCodeDlg::ScanCodeDlg(QWidget *parent, QString strTitle, EPayMethod ePayMethod) :
      QDialog(parent)
    , ui(new Ui::ScanCodeDlg)
    , m_ePayMethod( ePayMethod )
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( true );

    setTitle( strTitle );
    initCtrl();
    initConnect();
}

ScanCodeDlg::~ScanCodeDlg()
{
    delete ui;
}

//18位数字，没输入一位数字，处理时间为9毫秒，大概花费为200毫秒时间
void ScanCodeDlg::keyPressEvent( QKeyEvent *event )
{
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
            accept();
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

    qDebug() << "AlipayRechargeDlg::keyPressEvent:" << m_sBarCode<<event->text();
}

void ScanCodeDlg::setTitle( QString strTitle )
{
    ui->titleBar->setTitleText( strTitle );
}

QString ScanCodeDlg::getBarCode()
{
    return m_sBarCode;
}

void ScanCodeDlg::initCtrl()
{
    m_pBarCodeTimer = new QTimer( this );
}

void ScanCodeDlg::initConnect()
{
    connect( m_pBarCodeTimer, SIGNAL(timeout()), this, SLOT( slot_barCodeTimer() ) );
}

void ScanCodeDlg::startTimer()
{
    if( m_nTimerId < 0 ) {
        m_pBarCodeTimer->start( 500 );
        m_nTimerId = m_pBarCodeTimer->timerId();
        m_nTime = 0;
    }
}

void ScanCodeDlg::stopTimer()
{
    if( m_nTimerId> 0 ) {
        m_pBarCodeTimer->stop();
        m_nTimerId = -1;
        m_nTime = 0;
    }
}

void ScanCodeDlg::slot_barCodeTimer()
{
   ++m_nTime;
}

