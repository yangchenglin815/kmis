#include "ShopInfoDlg.h"
#include "ui_ShopInfoDlg.h"

ShopInfoDlg::ShopInfoDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShopInfoDlg)
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint );//去掉标题栏
    setModal( true );
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SIGNAL(sigCanncel()));
    ui->titleWidget->setTitleText("");
}

ShopInfoDlg::~ShopInfoDlg()
{
    delete ui;
}

void ShopInfoDlg::setShopInfo(QString sCorpName, QString sShopName)
{
    ui->corpNameLabel->setText(sCorpName);
    ui->shopNameLabel->setText(sShopName);
}

QString ShopInfoDlg::getCorpName()
{
    return m_sCorpName;
}

QString ShopInfoDlg::getShopName()
{
    return m_sShopName;
}

void ShopInfoDlg::on_confirmButton_clicked()
{
    emit sigConfirm();
}

void ShopInfoDlg::on_cancellButton_clicked()
{
    emit sigCanncel();
}
