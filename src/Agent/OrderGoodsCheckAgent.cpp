#include "OrderGoodsCheckAgent.h"
#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "ThreadManager.h"
#include <QDebug>

OrderGoodsCheckAgent* OrderGoodsCheckAgent::m_pInstance = NULL;

OrderGoodsCheckAgent::OrderGoodsCheckAgent()
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

OrderGoodsCheckAgent *OrderGoodsCheckAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new OrderGoodsCheckAgent;
    }
    return m_pInstance;
}

void OrderGoodsCheckAgent::getOrderCategoryRequest()
{
    HttpClient::instance()->getOrderCategoryForCheck();
}

void OrderGoodsCheckAgent::getOrderCardListRequest(int nLimit, int nOffset, const QList<int> &categoryIdList, QString sStartDate, QString sEndDate, QString sSearchText)
{
    HttpClient::instance()->getOrderCardList(nLimit, nOffset, categoryIdList, sStartDate, sEndDate, sSearchText);
}

void OrderGoodsCheckAgent::getOrderCardListDetailRequest(const QList<int> &orderCardIdList, bool bUploadFinish)
{
    HttpClient::instance()->getOrderCardListDetail(orderCardIdList, bUploadFinish);
}

void OrderGoodsCheckAgent::updateOrderCardListDetailRequest(const QMap<int, int> &changedNumMap, const QList<int> &orderCardIdList)
{
    HttpClient::instance()->updateOrderCardListDetail(changedNumMap, orderCardIdList);
}

void OrderGoodsCheckAgent::uploadOrderCardRequest(const QList<int> &orderCardIdList)
{
    HttpClient::instance()->uploadOrderCard(orderCardIdList);
}

void OrderGoodsCheckAgent::removeOrderCardRequest(const QList<int> orderIdList)
{
    HttpClient::instance()->removeOrderCard(orderIdList);
}

void OrderGoodsCheckAgent::slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> categoryBigInfoList)
{
    emit sigOnGetOrderCategory(nCode, sMsg, categoryBigInfoList);
}

void OrderGoodsCheckAgent::initConnect()
{
    qRegisterMetaType<QList<OrderCategoryBigInfo_s> >("QList<OrderCategoryBigInfo_s>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetOrderCategoryForCheck(int,QString,QList<OrderCategoryBigInfo_s>))
            , this, SLOT(slot_onGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>)));
    qRegisterMetaType<QList<OrderCardInfo_s> >("QList<OrderCardInfo_s>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetOrderCardList(int,QString,QList<OrderCardInfo_s>))
            , this, SIGNAL(sigOnGetOrderCardList(int,QString,QList<OrderCardInfo_s>)));
    qRegisterMetaType<QList<OrderCardDetailInfo_s> >("QList<OrderCardDetailInfo_s>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetOrderCardListDetail(int,QString,QList<OrderCardDetailInfo_s>,bool,QList<int>))
            , this, SIGNAL(sigOnGetOrderCardListDetail(int,QString,QList<OrderCardDetailInfo_s>,bool,QList<int>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnUpdateOrderCardListDetail(int,QString))
            , this, SIGNAL(sigOnUpdateOrderCardListDetail(int,QString)));
    connect(HttpSignal::instance(), SIGNAL(sigOnUploadOrderCard(int,QString,QList<int>)), this, SIGNAL(sigOnUploadOrderCard(int,QString,QList<int>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnRemoveOrderCard(int,QString)), this, SIGNAL(sigOnRemoveOrderCard(int,QString)));
}

