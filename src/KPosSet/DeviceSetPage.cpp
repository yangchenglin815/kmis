#include "DeviceSetPage.h"
#include "ui_DeviceSetPage.h"
#include "../util/KPosServerIni.h"
#include "../data/constData.h"
#include "QDebug"
DeviceSetPage::DeviceSetPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceSetPage)
{
    ui->setupUi(this);
    initConnect();
}

DeviceSetPage::~DeviceSetPage()
{
    delete ui;
}

void DeviceSetPage::initConnect()
{
    int machineType = KPosServerIni::getMachineType();
    if(machineType == c_sIntegratedScale){
        ui->typeButton1->setChecked(true);
        on_typeButton1_clicked();
    }
    else if(machineType == c_sAssembleScale){
        ui->typeButton2->setChecked(true);
        on_typeButton2_clicked();
    }

    int n_pricingScaleType = KPosServerIni::getPricingScaleType();
    ui->pricingScaleType->setCurrentIndex(n_pricingScaleType );

    int n_pricingScalePort = KPosServerIni::getPricingScalePort();
    ui->pricingScalePort->setCurrentIndex(n_pricingScalePort);

}

void DeviceSetPage::on_typeButton1_clicked()//选择pc一体秤
{

    ui->widget_2->hide();
    ui->widget_3->hide();
    ui->widget_4->hide();
    ui->widget_8->hide();
    KPosServerIni::setMachineType(c_sIntegratedScale);
}

void DeviceSetPage::on_typeButton2_clicked()//选择组装显示器
{
    ui->widget_1->show();
    ui->widget_3->show();
    ui->widget_4->show();
    ui->widget_8->show();
    KPosServerIni::setMachineType(c_sAssembleScale);
}

void DeviceSetPage::on_pricingScaleType_currentIndexChanged(int index)
{
    KPosServerIni::setPricingScaleType(index);
}


void DeviceSetPage::on_pricingScalePort_currentIndexChanged(int index)
{
    KPosServerIni::setPricingScalePort(index);
}
