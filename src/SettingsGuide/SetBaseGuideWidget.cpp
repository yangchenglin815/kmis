#include "SetBaseGuideWidget.h"
#include "ui_SetBaseGuideWidget.h"

SetBaseGuideWidget::SetBaseGuideWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetBaseGuideWidget)
{
    ui->setupUi(this);
    setStyleSheet("#widget{border-image:url(:/KPosSetGuideImage/szxd_1.png);}");
}

SetBaseGuideWidget::~SetBaseGuideWidget()
{
    delete ui;
}

void SetBaseGuideWidget::on_pushButton_clicked()
{
    emit sigOnShowSetButtonPage();
}
