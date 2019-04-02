#include "WarningDlg.h"
#include "ui_WarningDlg.h"

WarningDlg::WarningDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarningDlg)
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint ); //隐藏标题栏
    this->setAttribute(Qt::WA_DeleteOnClose);//添加了这条属性，窗口close，内存会被销毁
    setModal( true );
    initConnect();
}

WarningDlg::~WarningDlg()
{
    delete ui;
}

void WarningDlg::initConnect()
{
    connect( ui->deleteBtn, SIGNAL(clicked()), this, SLOT( close() ) );
    connect( ui->sureBtn, SIGNAL( clicked()), this, SLOT( close() ) );
}

void WarningDlg::setTitle( QString strTitle )
{
    ui->titleLabel->setText( strTitle );
}

QString WarningDlg::getTitle()
{
    QString strText = ui->titleLabel->text().trimmed();//去空格
    return strText;
}

void WarningDlg::setContent( QString strContent )
{
    ui->contextLabel->setText( strContent );
}

QString WarningDlg::getContent()
{
    return ui->contextLabel->text();
}

void WarningDlg::slotSure()
{
    accept();
}
