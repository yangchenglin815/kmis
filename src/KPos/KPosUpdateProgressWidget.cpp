#include "KPosUpdateProgressWidget.h"
#include "ui_KPosUpdateProgressWidget.h"

KPosUpdateProgressWidget::KPosUpdateProgressWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KPosUpdateProgressWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::FramelessWindowHint/*|Qt::WindowStaysOnTopHint|Qt::Popup*/|Qt::Tool);
}

KPosUpdateProgressWidget::~KPosUpdateProgressWidget()
{
    delete ui;
}

void KPosUpdateProgressWidget::setProgressValue(int nProgressValue)
{
    ui->progressWidget->setProgressValue(nProgressValue);
    if (nProgressValue == 100)
    {
        ui->hintLabel->setText(QStringLiteral("安装包下载完毕。"));
    }
}
