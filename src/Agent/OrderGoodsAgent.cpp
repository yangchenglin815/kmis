#include "OrderGoodsAgent.h"
#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "ThreadManager.h"

OrderGoodsAgent* OrderGoodsAgent::m_pInstance = NULL;

OrderGoodsAgent::OrderGoodsAgent()
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

OrderGoodsAgent *OrderGoodsAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new OrderGoodsAgent;
    }
    return m_pInstance;
}

void OrderGoodsAgent::getOrderCategoryRequest()
{
    HttpClient::instance()->getOrderCategory();
}

void OrderGoodsAgent::getOrderGoodsRequest(QString searchPattern, int nLimit, int nOffset, const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId)
{
    HttpClient::instance()->getOrderGoods(searchPattern, nLimit, nOffset, categoryIdList, sSortBy, sSort, nCategoryBigId);
}

void OrderGoodsAgent::getLeafCategoryIdListRequest(int nBigCategoryId, QList<int> &leafCategoryIdList)
{
    int nLen = m_categoryBigInfoList.length();
    int nLen2 = 0;
    OrderCategoryBigInfo_s orderCategoryBigInfo;
    OrderCategorySmallInfo_s orderCategorySmallInfo;
    for (int i = 0; i < nLen; i++)
    {
        if (m_categoryBigInfoList[i].nId == nBigCategoryId)
        {
            orderCategoryBigInfo = m_categoryBigInfoList[i];
            nLen2 = orderCategoryBigInfo.smallCategoryList.length();
            QList<int> templist;
            for (int j = 0; j < nLen2; j++)
            {
                orderCategorySmallInfo = orderCategoryBigInfo.smallCategoryList[j];
                templist = orderCategorySmallInfo.leafCategoryIdList;
                leafCategoryIdList.append(orderCategorySmallInfo.leafCategoryIdList);
            }
            if (leafCategoryIdList.length() == 0)
            {
                leafCategoryIdList.append(nBigCategoryId);
            }
            break;
        }
    }
}

void OrderGoodsAgent::createOrderCardRequest(const QList<OrderGoodsInfo *> &orderGoodsInfoList)
{
    HttpClient::instance()->createOrderCardRequest(orderGoodsInfoList);
}

void OrderGoodsAgent::slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> categoryBigInfoList)
{
    m_categoryBigInfoList = categoryBigInfoList;
    emit sigOnGetOrderCategory(nCode, sMsg, categoryBigInfoList);
}

void OrderGoodsAgent::initConnect()
{
    qRegisterMetaType<QList<OrderCategoryBigInfo_s> >("QList<OrderCategoryBigInfo_s>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>))
            , this, SLOT(slot_onGetOrderCategory(int,QString,QList<OrderCategoryBigInfo_s>)));

    qRegisterMetaType<QList<OrderGoodsInfo_s> >("QList<OrderGoodsInfo_s>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetOrderGoods(int,QString,QList<OrderGoodsInfo_s>,int))
            , this, SIGNAL(sigOnGetOrderGoods(int,QString,QList<OrderGoodsInfo_s>,int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnCreateOrderCard(int,QString)), this, SIGNAL(sigOnCreateOrderCard(int,QString)));
}

