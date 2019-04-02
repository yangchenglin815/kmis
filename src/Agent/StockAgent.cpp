#include "StockAgent.h"
#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "../util/ThreadManager.h"

StockAgent* StockAgent::m_pInstance = NULL;

StockAgent::StockAgent(QObject *parent) : QObject(parent)
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

StockAgent *StockAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new StockAgent;
    }
    return m_pInstance;
}

void StockAgent::getStockOrderListRequest(QString sStartDate, QString sEndDate, QString sSearchPatter)
{
    HttpClient::instance()->getStockOrderList(sStartDate, sEndDate, sSearchPatter);
}

void StockAgent::checkStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->checkStockOrder(nOrderId);
}

void StockAgent::removeStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->removeStockOrder(nOrderId);
}

void StockAgent::searchStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->searchStockOrder(nOrderId);
}

void StockAgent::editStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->editStockOrder(nOrderId);
}

void StockAgent::printStockOrderRequest(int nOrderId)
{
    HttpClient::instance()->printStockOrder(nOrderId);
}

void StockAgent::saveStockOrderRequest(int nOrderId, const QList<StockSelectGoodsInfo> &selectGoodsList)
{
    HttpClient::instance()->saveStockOrder(nOrderId, selectGoodsList);
}

void StockAgent::getStockGoodsInfoRequest(int nGoodsId)
{
    HttpClient::instance()->getStockGoodsInfo(nGoodsId);
}

void StockAgent::initConnect()
{
    qRegisterMetaType<QList<StockOrderInfo> >("QList<StockOrderInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetStockOrderList(int,QString,QList<StockOrderInfo>))
            , this, SIGNAL(sigOnGetStockOrderList(int,QString,QList<StockOrderInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnCheckStockOrder(int,QString)), this, SIGNAL(sigOnCheckStockOrder(int,QString)));
    connect(HttpSignal::instance(), SIGNAL(sigOnRemoveStockOrder(int,QString,int)), this, SIGNAL(sigOnRemoveStockOrder(int,QString,int)));
    qRegisterMetaType<QList<StockOrderSearchInfo> >("QList<StockOrderSearchInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnSearchStockOrder(int,QString,QList<StockOrderSearchInfo>))
            , this, SIGNAL(sigOnSearchStockOrder(int,QString,QList<StockOrderSearchInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnEditStockOrder(int,QString,QList<StockOrderSearchInfo>, int))
            , this, SIGNAL(sigOnEditStockOrder(int,QString,QList<StockOrderSearchInfo>, int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnPrintStockOrder(int,QString,QList<StockOrderSearchInfo>, int))
            , this, SIGNAL(sigOnPrintStockOrder(int,QString,QList<StockOrderSearchInfo>, int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnSaveStockOrder(int,QString)), this, SIGNAL(sigOnSaveStockOrder(int,QString)));
    qRegisterMetaType<GoodsStockInfo>("GoodsStockInfo");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetStockGoodsInfo(int,QString,GoodsStockInfo))
            , this, SIGNAL(sigOnGetStockGoodsInfo(int,QString,GoodsStockInfo)));
}
