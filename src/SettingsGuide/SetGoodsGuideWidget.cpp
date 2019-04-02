#include "SetGoodsGuideWidget.h"
#include "ui_SetGoodsGuideWidget.h"

SetGoodsGuideWidget::SetGoodsGuideWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetGoodsGuideWidget)
{
    ui->setupUi(this);
    setStyleSheet("#widget{border-image:url(:/KPosSetGuideImage/szxd_3.png);}");
}

SetGoodsGuideWidget::~SetGoodsGuideWidget()
{
    delete ui;
}

void SetGoodsGuideWidget::on_pushButton_clicked()
{
    emit sigOnShowSetDevicePage();
}
