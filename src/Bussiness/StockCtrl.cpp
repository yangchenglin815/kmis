#include "StockCtrl.h"
#include "../Agent/StockAgent.h"

StockCtrl::StockCtrl(QObject *parent) : QObject(parent)
{
    initConnect();
}

void StockCtrl::getStockOrderListRequest(QString sStartDate, QString sEndDate, QString sSearchPatter)
{
    StockAgent::instance()->getStockOrderListRequest(sStartDate, sEndDate, sSearchPatter);
}

void StockCtrl::checkStockOrderRequest(int nOrderId)
{
    StockAgent::instance()->checkStockOrderRequest(nOrderId);
}

void StockCtrl::removeStockOrderRequest(int nOrderId)
{
    StockAgent::instance()->removeStockOrderRequest(nOrderId);
}

void StockCtrl::searchStockOrderRequest(int nOrderId)
{
    StockAgent::instance()->searchStockOrderRequest(nOrderId);
}

void StockCtrl::editStockOrderRequest(int nOrderId)
{
    StockAgent::instance()->editStockOrderRequest(nOrderId);
}

void StockCtrl::printStockOrderRequest(int nOrderId)
{
    StockAgent::instance()->printStockOrderRequest(nOrderId);
}

void StockCtrl::saveStockOrderRequest(int nOrderId, const QList<StockSelectGoodsInfo> &selectGoodsInfoList)
{
    StockAgent::instance()->saveStockOrderRequest(nOrderId, selectGoodsInfoList);
}

void StockCtrl::getStockGoodsInfoRequest(int nGoodsId)
{
    StockAgent::instance()->getStockGoodsInfoRequest(nGoodsId);
}

void StockCtrl::initConnect()
{
    qRegisterMetaType<QList<StockOrderInfo> >("QList<StockOrderInfo>");
    connect(StockAgent::instance(), SIGNAL(sigOnGetStockOrderList(int,QString,QList<StockOrderInfo>))
            , this, SIGNAL(sigOnGetStockOrderList(int,QString,QList<StockOrderInfo>)));
    connect(StockAgent::instance(), SIGNAL(sigOnCheckStockOrder(int,QString)), this, SIGNAL(sigOnCheckStockOrder(int,QString)));
    connect(StockAgent::instance(), SIGNAL(sigOnRemoveStockOrder(int,QString,int)), this, SIGNAL(sigOnRemoveStockOrder(int,QString,int)));
    qRegisterMetaType<QList<StockOrderSearchInfo> >("QList<StockOrderSearchInfo>");
    connect(StockAgent::instance(), SIGNAL(sigOnSearchStockOrder(int,QString,QList<StockOrderSearchInfo>))
            , this, SIGNAL(sigOnSearchStockOrder(int,QString,QList<StockOrderSearchInfo>)));
    connect(StockAgent::instance(), SIGNAL(sigOnEditStockOrder(int,QString,QList<StockOrderSearchInfo>,int))
            , this, SIGNAL(sigOnEditStockOrder(int,QString,QList<StockOrderSearchInfo>,int)));
    connect(StockAgent::instance(), SIGNAL(sigOnPrintStockOrder(int,QString,QList<StockOrderSearchInfo>,int))
            , this, SIGNAL(sigOnPrintStockOrder(int,QString,QList<StockOrderSearchInfo>,int)));
    connect(StockAgent::instance(), SIGNAL(sigOnSaveStockOrder(int,QString)), this, SIGNAL(sigOnSaveStockOrder(int,QString)));
    qRegisterMetaType<GoodsStockInfo>("GoodsStockInfo");
    connect(StockAgent::instance(), SIGNAL(sigOnGetStockGoodsInfo(int,QString,GoodsStockInfo))
            , this, SIGNAL(sigOnGetStockGoodsInfo(int,QString,GoodsStockInfo)));
}

