#include "OutStockCtrl.h"

#include "../Agent/OutStockAgent.h"

OutStockCtrl::OutStockCtrl(QObject *parent) : QObject(parent)
{
    initConnect();
}

void OutStockCtrl::getOutStockOrderListRequest(QString sStartDate, QString sEndDate, QString sSearchPatter)
{
    OutStockAgent::instance()->getOutStockOrderListRequest(sStartDate, sEndDate, sSearchPatter);
}

void OutStockCtrl::checkOutStockOrderRequest(int nOrderId)
{
    OutStockAgent::instance()->checkOutStockOrderRequest(nOrderId);
}

void OutStockCtrl::removeOutStockOrderRequest(int nOrderId)
{
    OutStockAgent::instance()->removeOutStockOrderRequest(nOrderId);
}

void OutStockCtrl::searchOutStockOrderRequest(int nOrderId)
{
    OutStockAgent::instance()->searchOutStockOrderRequest(nOrderId);
}

void OutStockCtrl::editOutStockOrderRequest(int nOrderId)
{
    OutStockAgent::instance()->editOutStockOrderRequest(nOrderId);
}

void OutStockCtrl::printOutStockOrderRequest(int nOrderId)
{
    OutStockAgent::instance()->printOutStockOrderRequest(nOrderId);
}

void OutStockCtrl::saveOutStockOrderRequest(int nOrderId, const QList<OutStockSelectGoodsInfo> &selectGoodsInfoList)
{
    OutStockAgent::instance()->saveOutStockOrderRequest(nOrderId, selectGoodsInfoList);
}

void OutStockCtrl::getStockGoodsInfoRequest(int nGoodsId)
{
    OutStockAgent::instance()->getStockGoodsInfoRequest(nGoodsId);
}

void OutStockCtrl::initConnect()
{
//    connect(OutStockAgent::instance(), SIGNAL(sigOnGetOutStockGoodsInfo(QString,float)), this, SIGNAL(sigOnGetOutStockGoodsInfo(QString,float)));
    qRegisterMetaType<QList<OutStockOrderInfo> >("QList<OutStockOrderInfo>");
    connect(OutStockAgent::instance(), SIGNAL(sigOnGetOutStockOrderList(int,QString,QList<OutStockOrderInfo>))
            , this, SIGNAL(sigOnGetOutStockOrderList(int,QString,QList<OutStockOrderInfo>)));
    connect(OutStockAgent::instance(), SIGNAL(sigOnCheckOutStockOrder(int,QString)), this, SIGNAL(sigOnCheckOutStockOrder(int,QString)));
    connect(OutStockAgent::instance(), SIGNAL(sigOnRemoveOutStockOrder(int,QString,int)), this, SIGNAL(sigOnRemoveOutStockOrder(int,QString,int)));
    qRegisterMetaType<QList<OutStockOrderSearchInfo> >("QList<OutStockOrderSearchInfo>");
    connect(OutStockAgent::instance(), SIGNAL(sigOnSearchOutStockOrder(int,QString,QString,QList<OutStockOrderSearchInfo>))
            , this, SIGNAL(sigOnSearchOutStockOrder(int,QString,QString,QList<OutStockOrderSearchInfo>)));
    connect(OutStockAgent::instance(), SIGNAL(sigOnEditOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>,int))
            , this, SIGNAL(sigOnEditOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>,int)));
    connect(OutStockAgent::instance(), SIGNAL(sigOnPrintOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>,int))
            , this, SIGNAL(sigOnPrintOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>,int)));
    connect(OutStockAgent::instance(), SIGNAL(sigOnSaveOutStockOrder(int,QString)), this, SIGNAL(sigOnSaveOutStockOrder(int,QString)));
}

