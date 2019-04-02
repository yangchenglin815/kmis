#include "AdjustPriceAgent.h"
#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "../util/ThreadManager.h"

AdjustPriceAgent* AdjustPriceAgent::m_pInstance = NULL;

AdjustPriceAgent::AdjustPriceAgent(QObject *parent) : QObject(parent)
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

AdjustPriceAgent *AdjustPriceAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new AdjustPriceAgent;
    }
    return m_pInstance;
}

void AdjustPriceAgent::getAdjustPriceOrderListRequest(QString sStartDate, QString sEndDate, QString searchPatter)
{

    HttpClient::instance()->getAdjustPriceOrderList(sStartDate, sEndDate, searchPatter);
}

void AdjustPriceAgent::checkAdjustPriceOrderRequest(int nOrderId)
{
    HttpClient::instance()->checkAdjustPriceOrder(nOrderId);
}

void AdjustPriceAgent::removeAdjustPriceOrderRequest(int nOrderId)
{
    HttpClient::instance()->removeAdjustPriceOrder(nOrderId);
}

void AdjustPriceAgent::searchAdjustPriceOrder(int nOrderId)
{
    HttpClient::instance()->searchAdjustPriceOrder(nOrderId);
}

void AdjustPriceAgent::editAdjustPriceOrder(int nOrderId)
{
    HttpClient::instance()->editAdjustPriceOrder(nOrderId);
}

void AdjustPriceAgent::printAdjustPriceOrder(int nOrderId)
{
    HttpClient::instance()->printAdjustPriceOrder(nOrderId);
}

void AdjustPriceAgent::saveAdjustPriceOrder(int nOrderId, const QList<AdjustPriceSelectGoodsInfo> &selectGoodsList)
{
    HttpClient::instance()->saveAdjustPriceOrder(nOrderId, selectGoodsList);
}

void AdjustPriceAgent::initConnect()
{
    qRegisterMetaType<QList<AdjustPriceOrderInfo> >("QList<AdjustPriceOrderInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetAdjustPriceOrderList(int,QString,QList<AdjustPriceOrderInfo>))
            , this, SIGNAL(sigOnGetAdjustPriceOrderList(int,QString,QList<AdjustPriceOrderInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnCheckAdjustPriceOrder(int,QString, int))
            , this, SIGNAL(sigOnCheckAdjustPriceOrder(int,QString, int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnRemoveAdjustPriceOrder(int,QString,int))
            , this, SIGNAL(sigOnRemoveAdjustPriceOrder(int,QString,int)));
    qRegisterMetaType<QList<AdjustPriceOrderSearchInfo> >("QList<AdjustPriceOrderSearchInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnSearchAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>))
            , this, SIGNAL(sigOnSearchAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnEditAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int))
            , this, SIGNAL(sigOnEditAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnPrintAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int))
            , this, SIGNAL(sigOnPrintAdjustPriceOrder(int,QString,QList<AdjustPriceOrderSearchInfo>,int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnSaveAdjustPriceOrder(int,QString)), this, SIGNAL(sigOnSaveAdjustPriceOrder(int,QString)));
}
