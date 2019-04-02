#include "OutStockAgent.h"

#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "../util/ThreadManager.h"

OutStockAgent* OutStockAgent::m_pInstance = NULL;

OutStockAgent::OutStockAgent(QObject *parent) : QObject(parent)
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

OutStockAgent *OutStockAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new OutStockAgent;
    }
    return m_pInstance;
}

void OutStockAgent::getOutStockOrderListRequest(QString sStartDate, QString sEndDate, QString sSearchPatter)
{
    HttpClient::instance()->getOutStockOrderList(sStartDate, sEndDate, sSearchPatter);
}

void OutStockAgent::checkOutStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->checkOutStockOrder(nOrderId);
}

void OutStockAgent::removeOutStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->removeOutStockOrder(nOrderId);
}

void OutStockAgent::searchOutStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->searchOutStockOrder(nOrderId);
}

void OutStockAgent::editOutStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->editOutStockOrder(nOrderId);
}

void OutStockAgent::printOutStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->printOutStockOrder(nOrderId);
}

void OutStockAgent::saveOutStockOrderRequest(int nOrderId, const QList<OutStockSelectGoodsInfo> &selectGoodsList)
{
    HttpClient::instance()->saveOutStockOrder(nOrderId, selectGoodsList);
}

void OutStockAgent::getStockGoodsInfoRequest(int nGoodsId)
{
    HttpClient::instance()->getStockGoodsInfo(nGoodsId);
}

void OutStockAgent::initConnect()
{
//    connect(HttpSignal::instance(), SIGNAL(sigOnGetOutStockGoodsInfo(QString,float)), this, SIGNAL(sigOnGetOutStockGoodsInfo(QString,float)));
    qRegisterMetaType<QList<OutStockOrderInfo> >("QList<OutStockOrderInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetOutStockOrderList(int,QString,QList<OutStockOrderInfo>))
            , this, SIGNAL(sigOnGetOutStockOrderList(int,QString,QList<OutStockOrderInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnCheckOutStockOrder(int,QString)), this, SIGNAL(sigOnCheckOutStockOrder(int,QString)));
    connect(HttpSignal::instance(), SIGNAL(sigOnRemoveOutStockOrder(int,QString,int)), this, SIGNAL(sigOnRemoveOutStockOrder(int,QString,int)));
    qRegisterMetaType<QList<OutStockOrderSearchInfo> >("QList<OutStockOrderSearchInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnSearchOutStockOrder(int,QString,QString,QList<OutStockOrderSearchInfo>))
            , this, SIGNAL(sigOnSearchOutStockOrder(int,QString,QString,QList<OutStockOrderSearchInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnEditOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>, int))
            , this, SIGNAL(sigOnEditOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>, int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnPrintOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>, int))
            , this, SIGNAL(sigOnPrintOutStockOrder(int,QString,QList<OutStockOrderSearchInfo>, int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnSaveOutStockOrder(int,QString)), this, SIGNAL(sigOnSaveOutStockOrder(int,QString)));
}

