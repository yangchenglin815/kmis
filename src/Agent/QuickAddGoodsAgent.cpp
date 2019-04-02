#include "QuickAddGoodsAgent.h"
#include "HttpClient.h"
#include "ThreadManager.h"
#include "HttpSignal.h"

QuickAddGoodsAgent* QuickAddGoodsAgent::m_pInstance = NULL;

QuickAddGoodsAgent::QuickAddGoodsAgent(QObject *parent) : QObject(parent)
{
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
    initConnect();
}

QuickAddGoodsAgent *QuickAddGoodsAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new QuickAddGoodsAgent;
    }
    return m_pInstance;
}

void QuickAddGoodsAgent::getQuickGoodsInfoRequest(QString sBigCategoryCode)
{
    HttpClient::instance()->getQuickGoodsInfo(sBigCategoryCode);
}

void QuickAddGoodsAgent::createQuickGoodsRequest(const ProductInfo &info)
{
    HttpClient::instance()->createQuickGoodsRequest(info);
}

void QuickAddGoodsAgent::initConnect()
{
    connect(HttpSignal::instance(), &HttpSignal::sigOnGetQuickGoodsInfo, this, &QuickAddGoodsAgent::sigOnGetQuickGoodsInfo);
    connect(HttpSignal::instance(), &HttpSignal::sigOnCreateQuickGoods, this, &QuickAddGoodsAgent::sigOnCreateQuickGoods);
}

