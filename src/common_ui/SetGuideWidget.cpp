#include "SetGuideWidget.h"
#include "ui_SetGuideWidget.h"
#include <QDebug>

SetGuideWidget::SetGuideWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetGuideWidget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    ui->stackedWidget->setCurrentWidget(ui->setHomeGuidePage);
    initconnect();
}

SetGuideWidget::~SetGuideWidget()
{
    delete ui;
}

void SetGuideWidget::showSetBaseGuidePage()
{
    ui->stackedWidget->setCurrentWidget(ui->setBaseGuidePage);
}

void SetGuideWidget::showSetButtonGuidePage()
{
    ui->stackedWidget->setCurrentWidget(ui->setButtonGuidePage);
    emit sigOnShowSetButtonPage();
}

void SetGuideWidget::showSetGoodsGuidePage()
{
    ui->stackedWidget->setCurrentWidget(ui->setGoodsGuidePage);
    emit sigOnShowSetGoodsPage();
}

void SetGuideWidget::showSetDeviceGuidePage()
{
    ui->stackedWidget->setCurrentWidget(ui->setDeviceGuidePage);
    emit sigOnShowSetDevicePage();
}

void SetGuideWidget::showSetPaymentGuidePage()
{
    ui->stackedWidget->setCurrentWidget(ui->setPaymentGuidePage);
    emit sigOnShowSetPaymentPage();
}

void SetGuideWidget::showSetParamGuidePage()
{
    ui->stackedWidget->setCurrentWidget(ui->setParamGuidePage);
    emit sigOnShowSetParamPage();
}

void SetGuideWidget::showHomePage()
{
    emit sigOnShowHomePage();
    this->hide();
}

void SetGuideWidget::initconnect()
{
   connect(ui->setBaseGuidePage, SIGNAL(sigOnShowSetButtonPage()), this, SLOT(showSetButtonGuidePage()));
   connect(ui->setButtonGuidePage, SIGNAL(sigOnShowGoodsPage()), this, SLOT(showSetGoodsGuidePage()));
   connect(ui->setGoodsGuidePage, SIGNAL(sigOnShowSetDevicePage()), this, SLOT(showSetDeviceGuidePage()));
   connect(ui->setDeviceGuidePage, SIGNAL(sigOnShowPaymentPage()), this, SLOT(showSetPaymentGuidePage()));
   connect(ui->setPaymentGuidePage, SIGNAL(sigOnShowParamPage()), this, SLOT(showSetParamGuidePage()));
   connect(ui->setParamGuidePage, SIGNAL(sigOnShowHomePage()), this, SLOT(showHomePage()));
}
