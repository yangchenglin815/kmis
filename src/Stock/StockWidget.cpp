#include "StockWidget.h"
#include "ui_StockWidget.h"
#include <QMessageBox>
#include "TipsDlg.h"

StockWidget::StockWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StockWidget)
    , m_pStockCtrl(NULL)
{
    ui->setupUi(this);
    initConnect();
    init();
}

StockWidget::~StockWidget()
{
    delete ui;
}

void StockWidget::test()
{
    if (m_pStockCtrl == NULL)
    {
        m_pStockCtrl = new StockCtrl;
        qRegisterMetaType<QList<StockOrderSearchInfo> >("QList<StockOrderSearchInfo>");
        connect(m_pStockCtrl, SIGNAL(sigOnSearchStockOrder(int,QString,QList<StockOrderSearchInfo>))
                , this, SLOT(slot_onSearchStockOrder(int,QString,QList<StockOrderSearchInfo>)));
        connect(m_pStockCtrl, SIGNAL(sigOnEditStockOrder(int,QString,QList<StockOrderSearchInfo>,int))
                , this, SLOT(slot_onEditStockOrder(int,QString,QList<StockOrderSearchInfo>,int)));
        ui->stockOrderPage->initStockCtrl(m_pStockCtrl);
        ui->stockOrderCheckPage->initStockCtrl(m_pStockCtrl);
    }
    ui->stockOrderPage->getStockOrderListRequest();
}

void StockWidget::setCategoryList(QList<CategoryInfo *> categoryInfoList)
{
    ui->stockOrderCheckPage->setCategoryList(categoryInfoList);
}

void StockWidget::slot_returnClicked()
{
    if (ui->stackedWidget->currentWidget() == ui->stockOrderPage)
    {
        ui->stockOrderPage->hideCalendarWidget();
        emit sigReturnClicked();
    }
    else
    {
        ui->stackedWidget->setCurrentWidget(ui->stockOrderPage);
    }
}

void StockWidget::slot_addStockOrder()
{
    ui->stockOrderCheckPage->setOrderId(-1);
    ui->stockOrderCheckPage->clearGoodsSelectWidgetData();
    ui->stackedWidget->setCurrentWidget(ui->stockOrderCheckPage);
}

void StockWidget::slot_onSearchStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> searchInfoList)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("盘点单查看失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->stockOrderSearchPage->initData(searchInfoList);
        ui->stackedWidget->setCurrentWidget(ui->stockOrderSearchPage);
    }
}

void StockWidget::slot_onEditStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> searchInfoList, int nOrderId)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("盘点单查看失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->stockOrderCheckPage->initSelectGoodsData(searchInfoList, nOrderId);
        ui->stackedWidget->setCurrentWidget(ui->stockOrderCheckPage);
    }
}

void StockWidget::slot_updateOrder()
{
    test();
    ui->stackedWidget->setCurrentWidget(ui->stockOrderPage);
}

void StockWidget::slot_printAll(QList<StockSelectGoodsInfo> goodsInfoList, int nOrderId)
{
    ui->stockOrderPage->printAllStockOrder(goodsInfoList, nOrderId);
}

void StockWidget::slot_printAdded(QList<StockSelectGoodsInfo> addedGoodsList, QList<StockSelectGoodsInfo> removedGoodsList
                                  , QList<StockSelectGoodsInfo> updatedGoodsList, int nOrderId)
{
    ui->stockOrderPage->printAddedStockOrder(addedGoodsList, removedGoodsList, updatedGoodsList, nOrderId);
}

//void StockWidget::slot_checkStockSuccess()
//{

//}

void StockWidget::init()
{
    ui->stackedWidget->setCurrentWidget(ui->stockOrderPage);
}

void StockWidget::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SLOT(slot_returnClicked()));
    connect(ui->stockOrderPage, SIGNAL(sigAddStockOrder()), this, SLOT(slot_addStockOrder()));
    connect(ui->stockOrderPage, SIGNAL(sigCheckStockSuccess()), this, SLOT(slot_updateOrder()));
    connect(ui->stockOrderCheckPage, SIGNAL(sigSaveOrderSuccess()), this, SLOT(slot_updateOrder()));
    connect(ui->stockOrderCheckPage, SIGNAL(sigPrintAll(QList<StockSelectGoodsInfo>, int))
            , this, SLOT(slot_printAll(QList<StockSelectGoodsInfo>, int)));
    connect(ui->stockOrderCheckPage, SIGNAL(sigPrintAdded(QList<StockSelectGoodsInfo>,QList<StockSelectGoodsInfo>,QList<StockSelectGoodsInfo>,int))
            , this, SLOT(slot_printAdded(QList<StockSelectGoodsInfo>,QList<StockSelectGoodsInfo>,QList<StockSelectGoodsInfo>,int)));

//    void sigPrintAll(QList<StockSelectGoodsInfo> goodsInfoList);
//    void sigPrintAdded(QList<StockSelectGoodsInfo> addedGoodsList,
//                       QList<StockSelectGoodsInfo> removedGoodsList, QList<StockSelectGoodsInfo> updatedGoodsList);
}
