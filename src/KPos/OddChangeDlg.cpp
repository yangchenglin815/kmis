#include "OddChangeDlg.h"
#include "ui_OddChangeDlg.h"
#include "CommonFun.h"

OddChangeDlg::OddChangeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OddChangeDlg)
  , m_pTimerCloseWnd( NULL )
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint );//去掉标题栏
    setModal( true );
    initCtrl();
}

OddChangeDlg::~OddChangeDlg()
{
    delete ui;
}

void OddChangeDlg::setTitleText( QString strTitleText )
{
    ui->titleWidget->setTitleText( strTitleText );
}

void OddChangeDlg::setData( float fTotalMoney, float fReceivedAmt, float fOddChange )
{
    QString strFact = "￥" + CommonFun::floatToString( fTotalMoney );
    QString strPaid = "￥" + CommonFun::floatToString( fReceivedAmt );
    QString strChange = "￥" + CommonFun::floatToString( fOddChange );
    ui->factValueLabel->setText( strFact );
    ui->receivedValueLable->setText( strPaid );
    ui->oddChangeValueLabel->setText( strChange );
}

void OddChangeDlg::initCtrl()
{
    m_pTimerCloseWnd = new QTimer( this );
    m_pTimerCloseWnd->start( 2*1000 );
    connect( m_pTimerCloseWnd, SIGNAL( timeout() ), this, SIGNAL( sig_wnd_close() ) );
    connect( ui->titleWidget, SIGNAL( sig_close_wnd()), this, SIGNAL( sig_wnd_close() ) );
}
