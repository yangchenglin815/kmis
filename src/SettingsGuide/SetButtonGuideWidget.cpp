#include "SetButtonGuideWidget.h"
#include "ui_SetButtonGuideWidget.h"

SetButtonGuideWidget::SetButtonGuideWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetButtonGuideWidget)
{
    ui->setupUi(this);
    setStyleSheet("#widget{border-image:url(:/KPosSetGuideImage/szxd_2.png);}");
}

SetButtonGuideWidget::~SetButtonGuideWidget()
{
    delete ui;
}

void SetButtonGuideWidget::on_pushButton_clicked()
{
    emit sigOnShowGoodsPage();
}
