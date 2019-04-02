#include "OrderGoodsCheckCtrl.h"
#include "../Agent/OrderGoodsCheckAgent.h"
#include <QDateTime>

OrderGoodsCheckCtrl::OrderGoodsCheckCtrl(QObject *parent) : QObject(parent)
{
    initConnect();
}

void OrderGoodsCheckCtrl::getOrderCategoryRequest()
{
    OrderGoodsCheckAgent::instance()->getOrderCategoryRequest();
}

void OrderGoodsCheckCtrl::getOrderCardListRequest(const QList<int> &categoryIdList, QString sStartDate, QString sEndDate, QString sSearchText)
{
    int nLimit = -1;
    int nOffset = -1;
    OrderGoodsCheckAgent::instance()->getOrderCardListRequest(nLimit, nOffset, categoryIdList, sStartDate, sEndDate, sSearchText);
}

void OrderGoodsCheckCtrl::getOrderCardListDetailRequest(const QList<int> &orderCardIdList, bool bUploadFinish)
{
    OrderGoodsCheckAgent::instance()->getOrderCardListDetailRequest(orderCardIdList, bUploadFinish);
}

void OrderGoodsCheckCtrl::updateOrderCardListDetailRequest(const QMap<int, int> &changedNumMap, const QList<int> &orderCardIdList)
{
    OrderGoodsCheckAgent::instance()->updateOrderCardListDetailRequest(changedNumMap, orderCardIdList);
}

void OrderGoodsCheckCtrl::uploadOrderCardRequest(const QList<int> &orderCardIdList)
{
    OrderGoodsCheckAgent::instance()->uploadOrderCardRequest(orderCardIdList);
}

void OrderGoodsCheckCtrl::removeOrderCardRequest(const QList<int> orderIdList)
{
    OrderGoodsCheckAgent::instance()->removeOrderCardRequest(orderIdList);
}

void OrderGoodsCheckCtrl::initConnect()
{
    qRegisterMetaType<QList<OrderCategoryBigInfo_s> >("QList<OrderCategoryBigInfo_s>");
    connect(OrderGoodsCheckAgent::instance(), SIGNAL(sigOnGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>))
            , this, SIGNAL(sigOnGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>)));
    qRegisterMetaType<QList<OrderCardInfo_s> >("QList<OrderCardlInfo_s>");
    connect(OrderGoodsCheckAgent::instance(), SIGNAL(sigOnGetOrderCardList(int,QString,QList<OrderCardInfo_s>))
            , this, SIGNAL(sigOnGetOrderCardList(int,QString,QList<OrderCardInfo_s>)));
    qRegisterMetaType<QList<OrderCardDetailInfo_s> >("QList<OrderCardDetailInfo_s>");
    connect(OrderGoodsCheckAgent::instance(), SIGNAL(sigOnGetOrderCardListDetail(int,QString,QList<OrderCardDetailInfo_s>, bool,QList<int>))
            , this, SIGNAL(sigOnGetOrderCardListDetail(int,QString,QList<OrderCardDetailInfo_s>, bool,QList<int>)));
    connect(OrderGoodsCheckAgent::instance(), SIGNAL(sigOnUpdateOrderCardListDetail(int,QString))
            , this, SIGNAL(sigOnUpdateOrderCardListDetail(int,QString)));
    connect(OrderGoodsCheckAgent::instance(), SIGNAL(sigOnUploadOrderCard(int,QString,QList<int>)), this, SIGNAL(sigOnUploadOrderCard(int,QString,QList<int>)));
    connect(OrderGoodsCheckAgent::instance(), SIGNAL(sigOnRemoveOrderCard(int,QString)), this, SIGNAL(sigOnRemoveOrderCard(int,QString)));
}

