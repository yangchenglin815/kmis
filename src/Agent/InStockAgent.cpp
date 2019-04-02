#include "InStockAgent.h"

#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "../util/ThreadManager.h"

InStockAgent* InStockAgent::m_pInstance = NULL;

InStockAgent::InStockAgent(QObject *parent) : QObject(parent)
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

InStockAgent *InStockAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new InStockAgent;
    }
    return m_pInstance;
}

void InStockAgent::getInStockOrderListRequest(QString sStartDate, QString sEndDate, QString sSearchPatter)
{
    HttpClient::instance()->getInStockOrderList(sStartDate, sEndDate, sSearchPatter);
}

void InStockAgent::checkInStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->checkInStockOrder(nOrderId);
}

void InStockAgent::removeInStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->removeInStockOrder(nOrderId);
}

void InStockAgent::searchInStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->searchInStockOrder(nOrderId);
}

void InStockAgent::editInStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->editInStockOrder(nOrderId);
}

void InStockAgent::printInStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->printInStockOrder(nOrderId);
}

void InStockAgent::saveInStockOrderRequest(int nOrderId, const QList<InStockSelectGoodsInfo> &selectGoodsList)
{
    HttpClient::instance()->saveInStockOrder(nOrderId, selectGoodsList);
}

void InStockAgent::getStockGoodsInfoRequest(int nGoodsId)
{
    HttpClient::instance()->getStockGoodsInfo(nGoodsId);
}

void InStockAgent::initConnect()
{
    qRegisterMetaType<QList<InStockOrderInfo> >("QList<InStockOrderInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetInStockOrderList(int,QString,QList<InStockOrderInfo>))
            , this, SIGNAL(sigOnGetInStockOrderList(int,QString,QList<InStockOrderInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnCheckInStockOrder(int,QString)), this, SIGNAL(sigOnCheckInStockOrder(int,QString)));
    connect(HttpSignal::instance(), SIGNAL(sigOnRemoveInStockOrder(int,QString,int)), this, SIGNAL(sigOnRemoveInStockOrder(int,QString,int)));
    qRegisterMetaType<QList<InStockOrderSearchInfo> >("QList<InStockOrderSearchInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnSearchInStockOrder(int,QString,QString,QList<InStockOrderSearchInfo>))
            , this, SIGNAL(sigOnSearchInStockOrder(int,QString,QString,QList<InStockOrderSearchInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnEditInStockOrder(int,QString,QList<InStockOrderSearchInfo>, int))
            , this, SIGNAL(sigOnEditInStockOrder(int,QString,QList<InStockOrderSearchInfo>, int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnPrintInStockOrder(int,QString,QList<InStockOrderSearchInfo>, int))
            , this, SIGNAL(sigOnPrintInStockOrder(int,QString,QList<InStockOrderSearchInfo>, int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnSaveInStockOrder(int,QString)), this, SIGNAL(sigOnSaveInStockOrder(int,QString)));
    connect(HttpSignal::instance(), SIGNAL(sigOnSaveQuickAddGoods(int,QString,QString,QString,QString)), this, SIGNAL(sigOnSaveQuickAddGoods(int,QString,QString,QString,QString)));
}

