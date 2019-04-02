#include "SetParamGuideWidget.h"
#include "ui_SetParamGuideWidget.h"

SetParamGuideWidget::SetParamGuideWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetParamGuideWidget)
{
    ui->setupUi(this);
    setStyleSheet("#widget{border-image:url(:/KPosSetGuideImage/szxd_6.png);}");
}

SetParamGuideWidget::~SetParamGuideWidget()
{
    delete ui;
}

void SetParamGuideWidget::on_pushButton_clicked()
{
    emit sigOnShowHomePage();
}
