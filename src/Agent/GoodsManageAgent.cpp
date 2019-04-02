#include "GoodsManageAgent.h"
#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "ThreadManager.h"

GoodsManageAgent* GoodsManageAgent::m_pInstance = NULL;

GoodsManageAgent *GoodsManageAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new GoodsManageAgent;
    }
    return m_pInstance;
}

void GoodsManageAgent::getGoodsManageListRequest(QString searchPattern, int nLimit, int nOffset, const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId)
{
    HttpClient::instance()->getGoodsManageOrderList(searchPattern, nLimit, nOffset, categoryIdList, sSortBy, sSort, nCategoryBigId);
}

void GoodsManageAgent::getCategoryListRequest()
{
    HttpClient::instance()->getCategoryOrderList();
}

void GoodsManageAgent::getLeafCategoryIdListRequest(int nBigCategoryId, QList<int> &leafCategoryIdList)
{
    int nLen = m_categoryBigInfoList.length();
    int nLen2 = 0;
    CategoryBigInfo_s orderCategoryBigInfo;
    CategorySmallInfo_s orderCategorySmallInfo;
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

void GoodsManageAgent::slot_onGetCategory(int nCode, QString sMsg, QList<CategoryBigInfo_s> categoryBigInfoList)
{
    m_categoryBigInfoList = categoryBigInfoList;
    emit sigOnGetCategoryList(nCode, sMsg, categoryBigInfoList);
}

GoodsManageAgent::GoodsManageAgent()
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

void GoodsManageAgent::initConnect()
{
   qRegisterMetaType<QList<CategoryBigInfo_s> >("QList<CategoryBigInfo_s>");
   connect(HttpSignal::instance(), SIGNAL(sigOnGetGoodsManageCategoryOrderList(int,QString,QList<CategoryBigInfo_s>))
           , this, SLOT(slot_onGetCategory(int,QString,QList<CategoryBigInfo_s>)));
   qRegisterMetaType<QList<sGoodsInfo_s> >("QList<sGoodsInfo_s>");
   connect(HttpSignal::instance(), SIGNAL(sigOnGetGoodsManageGoodsList(int,QString,QList<sGoodsInfo_s>,int))
           , this, SIGNAL(sigOnGetGoodsManageList(int,QString,QList<sGoodsInfo_s>,int)));
}

