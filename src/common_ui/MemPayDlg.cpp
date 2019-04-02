#include "MemPayDlg.h"
#include "ui_MemPayDlg.h"
#include "CommonFun.h"

int gPwdPos = 6;

MemPayDlg::MemPayDlg(QWidget *parent,QString strPayPwd)
    : QDialog(parent)
    , ui(new Ui::MemPayDlg)
    , m_sMemPwd( strPayPwd )
    , m_sPayPwd( "" )
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    setModal( true );
    initCtrl();
    initConnect();

    ui->titleWidget->setTitleText( "会员卡" );
    setWindowTitle( "会员支付" );
}

MemPayDlg::~MemPayDlg()
{
    delete ui;
}

void MemPayDlg::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED( event )

    if( event->key() == Qt::Key_Backspace ) {
        m_sPayPwd = m_sPayPwd.left( m_sPayPwd.size() - 1 );
        setPayPwd();
        return;
    } else if( event->key() == Qt::Key_Clear ) {
        m_sPayPwd = "";
        setPayPwd();
        return;
    } else if( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return ) {
        slot_sure();
        return;
    }

    if( event->text().toInt() > 9 ) return;

    if( m_sPayPwd.size() <= gPwdPos ) {
        m_sPayPwd += event->text();

        setPayPwd();
    }
}

void MemPayDlg::initCtrl()
{
    QRegExp regx("[0-9]");
    QRegExpValidator *pReg = new QRegExpValidator( regx, this);
    ui->lineEdit_1->setValidator( pReg );
    ui->lineEdit_2->setValidator( pReg );
    ui->lineEdit_3->setValidator( pReg );
    ui->lineEdit_4->setValidator( pReg );
    ui->lineEdit_5->setValidator( pReg );
    ui->lineEdit_6->setValidator( pReg );

    m_listPayPwd.append( ui->lineEdit_1 );
    m_listPayPwd.append( ui->lineEdit_2 );
    m_listPayPwd.append( ui->lineEdit_3 );
    m_listPayPwd.append( ui->lineEdit_4 );
    m_listPayPwd.append( ui->lineEdit_5 );
    m_listPayPwd.append( ui->lineEdit_6 );
}

void MemPayDlg::initConnect()
{
    connect( ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(close()) );
    connect( ui->sureButton, SIGNAL(clicked()), this, SLOT( slot_sure() ) );
    connect( ui->cancelButton, SIGNAL(clicked()), this, SLOT(close()) );
//    connect( ui->titleWidget, SIGNAL(clicked()), this, SLOT(close()) );
}

void MemPayDlg::slot_sure()
{
    if( m_sPayPwd.size() == 6 ) {
        accept();
    } else if( m_sPayPwd.isEmpty() ) {
        ui->pwdErrorLabel->setText( "！密码不能为空");
    } else {
        ui->pwdErrorLabel->setText( "！密码错误请重新输入");
        m_sPayPwd = "";
        clearPayPwd();
    }
}

QString MemPayDlg::getPayPwd()
{
    QString strPayPwd = ui->lineEdit_1->text() + ui->lineEdit_2->text() + ui->lineEdit_3->text() \
            + ui->lineEdit_4->text() + ui->lineEdit_5->text() + ui->lineEdit_6->text();
    return strPayPwd;
}

void MemPayDlg::setPayPwd()
{
    clearPayPwd();

    QList<QLineEdit*>::iterator it = m_listPayPwd.begin();
    for( int i = 0; it != m_listPayPwd.end(); ++it, ++i ) {
        if( i >= m_sPayPwd.size() ) break;
        QString strPwd = m_sPayPwd.mid( i, 1 );
        (*it)->setText( strPwd );
    }
}

void MemPayDlg::clearPayPwd()
{
    QList<QLineEdit*>::iterator it = m_listPayPwd.begin();
    for( ; it != m_listPayPwd.end(); ++it ) {
        (*it)->setText( "" );
    }
}



