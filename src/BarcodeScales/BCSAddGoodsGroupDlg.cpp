#include "BCSAddGoodsGroupDlg.h"
#include "ui_BCSAddGoodsGroupDlg.h"

BCSAddGoodsGroupDlg::BCSAddGoodsGroupDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSAddGoodsGroupDlg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->titleWidget->setTitleText(QStringLiteral("商品组名称"));
    initConnect();
}

BCSAddGoodsGroupDlg::~BCSAddGoodsGroupDlg()
{
    delete ui;
}

void BCSAddGoodsGroupDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
}

void BCSAddGoodsGroupDlg::on_confirmButton_clicked()
{
    QString sName = ui->nameWidget->getText();
    if (sName.isEmpty())
    {
        ui->hintLabel->setText("分类名不能为空！");
    }
    else
    {
        emit sigAddGoodsGroup(sName);
    }
}
