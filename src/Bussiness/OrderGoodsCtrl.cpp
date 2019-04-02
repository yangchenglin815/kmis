#include "OrderGoodsCtrl.h"
#include "../Agent/OrderGoodsAgent.h"
#include "../util/HttpSignal.h"

OrderGoodsCtrl::OrderGoodsCtrl(QObject *parent)
    : QObject(parent)
{
    initConnect();
}

void OrderGoodsCtrl::getOrderCategoryRequest()
{
    OrderGoodsAgent::instance()->getOrderCategoryRequest();
}

void OrderGoodsCtrl::getOrderGoodsRequest(int nCategoryBigId)
{
    int nOffset = -1;
    int nLimit = -1;
    QList<int> leafCategoryIdList;
    OrderGoodsAgent::instance()->getLeafCategoryIdListRequest(nCategoryBigId, leafCategoryIdList);
    OrderGoodsAgent::instance()->getOrderGoodsRequest("", nLimit, nOffset, leafCategoryIdList, "req_num", "asc", nCategoryBigId);
}

void OrderGoodsCtrl::createOrderCardRequest(const QList<OrderGoodsInfo *> &orderGoodsInfoList)
{
    OrderGoodsAgent::instance()->createOrderCardRequest(orderGoodsInfoList);
}

void OrderGoodsCtrl::slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> categoryBigInfoList)
{
    emit sigOnGetOrderCategory(nCode, sMsg, categoryBigInfoList);
//    if (categoryBigInfoList.length() > 0)
//    {
//        int nCategoryBigId = categoryBigInfoList[0].nId;
//        getOrderGoodsRequest(nCategoryBigId);
//    }
}

void OrderGoodsCtrl::initConnect()
{
    qRegisterMetaType<QList<OrderCategoryBigInfo_s> >("QList<OrderCategoryBigInfo_s>");
    connect(OrderGoodsAgent::instance(), SIGNAL(sigOnGetOrderCategory(int,QString, QList<OrderCategoryBigInfo_s>))
            , this, SLOT(slot_onGetOrderCategory(int,QString, QList<OrderCategoryBigInfo_s>)));

    qRegisterMetaType<QList<OrderGoodsInfo_s> >("QList<OrderGoodsInfo_s>");
    connect(OrderGoodsAgent::instance(), SIGNAL(sigOnGetOrderGoods(int,QString,QList<OrderGoodsInfo_s>,int))
            , this, SIGNAL(sigOnGetOrderGoods(int,QString,QList<OrderGoodsInfo_s>, int)));

    connect(OrderGoodsAgent::instance(), SIGNAL(sigOnCreateOrderCard(int,QString))
            , this, SIGNAL(sigOnCreateOrderCard(int,QString)));
}

