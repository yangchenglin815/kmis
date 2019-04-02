#include "OrderAndCheckWidget.h"
#include "ui_OrderAndCheckWidget.h"

OrderAndCheckWidget::OrderAndCheckWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderAndCheckWidget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->checkOrderPage);
    initConnect();
}

OrderAndCheckWidget::~OrderAndCheckWidget()
{
    delete ui;
}

void OrderAndCheckWidget::test()
{
    if (ui->stackedWidget->currentWidget() == ui->checkOrderPage)
    {
        ui->checkOrderPage->test();
    }
    ui->orderGoodsPage->setReInitData();
}

void OrderAndCheckWidget::slot_showOrderGoodsPage()
{
    ui->orderGoodsPage->test();
    ui->stackedWidget->setCurrentWidget(ui->orderGoodsPage);
}

void OrderAndCheckWidget::slot_backCheckOrderPage(bool bOrderCardChanged)
{
    if (bOrderCardChanged)
    {
        ui->checkOrderPage->test();
    }
    ui->stackedWidget->setCurrentWidget(ui->checkOrderPage);
}

void OrderAndCheckWidget::initConnect()
{
    connect(ui->checkOrderPage, SIGNAL(sigReturnClicked()), this, SIGNAL(sig_backHomePage()));
    connect(ui->checkOrderPage, SIGNAL(sigAddCheckOrder()), this, SLOT(slot_showOrderGoodsPage()));
    connect(ui->orderGoodsPage, SIGNAL(sigReturnClicked(bool)), this, SLOT(slot_backCheckOrderPage(bool)));
}
