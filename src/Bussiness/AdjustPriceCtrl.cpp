#include "AdjustPriceCtrl.h"
#include "../Agent/AdjustPriceAgent.h"
#include "../Agent/CategoryInfoAgent.h"
#include "../Agent/LoginKPosAgent.h"

AdjustPriceCtrl::AdjustPriceCtrl(QObject *parent)
    : QObject(parent)
{
    initConnect();
}

void AdjustPriceCtrl::getAdjustPriceOrderListRequest(QString sStartDate, QString sEndDate, QString searchPatter)
{
    AdjustPriceAgent::instance()->getAdjustPriceOrderListRequest(sStartDate, sEndDate, searchPatter);
}

void AdjustPriceCtrl::checkAdjustPriceOrderRequest(int nOrderId)
{
    AdjustPriceAgent::instance()->checkAdjustPriceOrderRequest(nOrderId);
}

void AdjustPriceCtrl::removeAdjustPriceOrder(int nOrderId)
{
    AdjustPriceAgent::instance()->removeAdjustPriceOrderRequest(nOrderId);
}

void AdjustPriceCtrl::searchAdjustPriceOrder(int nOrderId)
{
    AdjustPriceAgent::instance()->searchAdjustPriceOrder(nOrderId);
}

void AdjustPriceCtrl::editAdjustPriceOrder(int nOrderId)
{
    AdjustPriceAgent::instance()->editAdjustPriceOrder(nOrderId);
}

void AdjustPriceCtrl::printAdjustPriceOrder(int nOrderId)
{
    AdjustPriceAgent::instance()->printAdjustPriceOrder(nOrderId);
}

void AdjustPriceCtrl::saveAdjustPriceOrder(int nOrderId, const QList<AdjustPriceSelectGoodsInfo> &selectGoodsInfoList)
{
    AdjustPriceAgent::instance()->saveAdjustPriceOrder(nOrderId, selectGoodsInfoList);
}

void AdjustPriceCtrl::startUpdateThread()
{
    emit AdjustPriceAgent::instance()->sigStartUpdateThread();
}

void AdjustPriceCtrl::initConnect()
{
    qRegisterMetaType<QList<AdjustPriceOrderInfo> >("QList<AdjustPriceOrderInfo>");
    connect(AdjustPriceAgent::instance(), SIGNAL(sigOnGetAdjustPriceOrderList(int,QString,QList<AdjustPriceOrderInfo>))
            , this, SIGNAL(sigOnGetAdjustPriceOrderList(int,QString,QList<AdjustPriceOrderInfo>)));
    connect(AdjustPriceAgent::instance(), SIGNAL(sigOnCheckAdjustPriceOrder(int,QString,int))
            , this, SIGNAL(sigOnCheckAdjustPriceOrder(int,QString,int)));
    connect(AdjustPriceAgent::instance(), SIGNAL(sigOnRemoveAdjustPriceOrder(int,QString,int))
            , this, SIGNAL(sigOnRemoveAdjustPriceOrder(int,QString,int)));
    qRegisterMetaType<QList<AdjustPriceOrderSearchInfo> >("QList<AdjustPriceOrderSearchInfo>");
    connect(AdjustPriceAgent::instance(), SIGNAL(sigOnSearchAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>))
            , this, SIGNAL(sigOnSearchAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>)));
    connect(AdjustPriceAgent::instance(), SIGNAL(sigOnEditAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int))
            , this, SIGNAL(sigOnEditAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int)));
    connect(AdjustPriceAgent::instance(), SIGNAL(sigOnPrintAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int))
            , this, SIGNAL(sigOnPrintAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int)));
    connect(AdjustPriceAgent::instance(), SIGNAL(sigOnSaveAdjustPriceOrder(int,QString)), this, SIGNAL(sigOnSaveAdjustPriceOrder(int,QString)));
}

