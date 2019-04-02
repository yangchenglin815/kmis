#include "BarCodeScaleWidget.h"
#include "ui_BarCodeScaleWidget.h"
#include <QDebug>


BarCodeScaleWidget::BarCodeScaleWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BarCodeScaleWidget)
    , m_pCtrl(NULL)
{
    ui->setupUi(this);
    initConnect();
}

BarCodeScaleWidget::~BarCodeScaleWidget()
{
    delete ui;
}

void BarCodeScaleWidget::test()
{
    if (m_pCtrl == NULL)
    {
        m_pCtrl = new BarCodeScalesCtrl;
        ui->bcsPage->setCtrl(m_pCtrl);
        ui->bcsGoodsSelectPage->setCtrl(m_pCtrl);
    }
    ui->bcsGoodsSelectPage->init();
    ui->bcsPage->init();
}

void BarCodeScaleWidget::slot_returnHomePage()
{
    emit sigReturnClicked();
}

void BarCodeScaleWidget::slot_returnBcsPage()
{
    ui->stackedWidget->setCurrentWidget(ui->bcsPage);
}

void BarCodeScaleWidget::slot_editBcsGroup(int nGroupId)
{
    ui->bcsGoodsSelectPage->setGroupId(nGroupId);
    ui->stackedWidget->setCurrentWidget(ui->bcsGoodsSelectPage); 
}

//void BarCodeScaleWidget::slot_addBcsGroup()
//{
//    ui->stackedWidget->setCurrentWidget(ui->bcsGoodsSelectPage);
//}

void BarCodeScaleWidget::initConnect()
{
    connect(ui->bcsPage, SIGNAL(sigReturnClicked()), this, SLOT(slot_returnHomePage()));
    connect(ui->bcsPage, SIGNAL(sigEditBcsGroup(int)), this, SLOT(slot_editBcsGroup(int)));
//    connect(ui->bcsPage, SIGNAL(sigAddBcsGroup()), this, SLOT(slot_addBcsGroup()));
    connect(ui->bcsGoodsSelectPage, SIGNAL(sigReturnClicked()), this, SLOT(slot_returnBcsPage()));
}




