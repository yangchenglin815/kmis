#include "SetPaymentGuideWidget.h"
#include "ui_SetPaymentGuideWidget.h"

SetPaymentGuideWidget::SetPaymentGuideWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetPaymentGuideWidget)
{
    ui->setupUi(this);
    setStyleSheet("#widget{border-image:url(:/KPosSetGuideImage/szxd_5.png);}");
}

SetPaymentGuideWidget::~SetPaymentGuideWidget()
{
    delete ui;
}

void SetPaymentGuideWidget::on_pushButton_clicked()
{
    emit sigOnShowParamPage();
}
