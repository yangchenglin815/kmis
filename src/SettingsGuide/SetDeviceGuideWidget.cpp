#include "SetDeviceGuideWidget.h"
#include "ui_SetDeviceGuideWidget.h"

SetDeviceGuideWidget::SetDeviceGuideWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetDeviceGuideWidget)
{
    ui->setupUi(this);
    setStyleSheet("#widget{border-image:url(:/KPosSetGuideImage/szxd_4.png);}");
}

SetDeviceGuideWidget::~SetDeviceGuideWidget()
{
    delete ui;
}

void SetDeviceGuideWidget::on_pushButton_clicked()
{
    emit sigOnShowPaymentPage();
}
