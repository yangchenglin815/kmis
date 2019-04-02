#include "InStockCtrl.h"

#include "../Agent/InStockAgent.h"
#include "../Agent/KPosSetAgent.h"

InStockCtrl::InStockCtrl(QObject *parent) : QObject(parent)
{
    initConnect();
}

void InStockCtrl::getInStockOrderListRequest(QString sStartDate, QString sEndDate, QString sSearchPatter)
{
    InStockAgent::instance()->getInStockOrderListRequest(sStartDate, sEndDate, sSearchPatter);
}

void InStockCtrl::checkInStockOrderRequest(int nOrderId)
{
    InStockAgent::instance()->checkInStockOrderRequest(nOrderId);
}

void InStockCtrl::removeInStockOrderRequest(int nOrderId)
{
    InStockAgent::instance()->removeInStockOrderRequest(nOrderId);
}

void InStockCtrl::searchInStockOrderRequest(int nOrderId)
{
    InStockAgent::instance()->searchInStockOrderRequest(nOrderId);
}

void InStockCtrl::editInStockOrderRequest(int nOrderId)
{
    InStockAgent::instance()->editInStockOrderRequest(nOrderId);
}

void InStockCtrl::printInStockOrderRequest(int nOrderId)
{
    InStockAgent::instance()->printInStockOrderRequest(nOrderId);
}

void InStockCtrl::saveInStockOrderRequest(int nOrderId, const QList<InStockSelectGoodsInfo> &selectGoodsInfoList)
{
    InStockAgent::instance()->saveInStockOrderRequest(nOrderId, selectGoodsInfoList);
}

void InStockCtrl::getStockGoodsInfoRequest(int nGoodsId)
{
    InStockAgent::instance()->getStockGoodsInfoRequest(nGoodsId);
}

void InStockCtrl::initConnect()
{
    qRegisterMetaType<QList<InStockOrderInfo> >("QList<InStockOrderInfo>");
    connect(InStockAgent::instance(), SIGNAL(sigOnGetInStockOrderList(int,QString,QList<InStockOrderInfo>))
            , this, SIGNAL(sigOnGetInStockOrderList(int,QString,QList<InStockOrderInfo>)));
    connect(InStockAgent::instance(), SIGNAL(sigOnCheckInStockOrder(int,QString)), this, SIGNAL(sigOnCheckInStockOrder(int,QString)));
    connect(InStockAgent::instance(), SIGNAL(sigOnRemoveInStockOrder(int,QString,int)), this, SIGNAL(sigOnRemoveInStockOrder(int,QString,int)));
    qRegisterMetaType<QList<InStockOrderSearchInfo> >("QList<InStockOrderSearchInfo>");
    connect(InStockAgent::instance(), SIGNAL(sigOnSearchInStockOrder(int,QString,QString,QList<InStockOrderSearchInfo>))
            , this, SIGNAL(sigOnSearchInStockOrder(int,QString,QString,QList<InStockOrderSearchInfo>)));
    connect(InStockAgent::instance(), SIGNAL(sigOnEditInStockOrder(int,QString,QList<InStockOrderSearchInfo>,int))
            , this, SIGNAL(sigOnEditInStockOrder(int,QString,QList<InStockOrderSearchInfo>,int)));
    connect(InStockAgent::instance(), SIGNAL(sigOnPrintInStockOrder(int,QString,QList<InStockOrderSearchInfo>,int))
            , this, SIGNAL(sigOnPrintInStockOrder(int,QString,QList<InStockOrderSearchInfo>,int)));
    connect(InStockAgent::instance(), SIGNAL(sigOnSaveInStockOrder(int,QString)), this, SIGNAL(sigOnSaveInStockOrder(int,QString)));
}

