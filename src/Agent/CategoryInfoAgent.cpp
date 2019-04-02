#include "CategoryInfoAgent.h"
#include "HttpClient.h"
#include "../util/HttpSignal.h"
#include "../util/ThreadManager.h"
#include "../util/KPosIni.h"
#include "../data/enumData.h"
#include "../data/constData.h"
#include "../Database/PosDBFactory.h"
#include "OnlineStateAgent.h"
#include <QDebug>

CategoryInfoAgent* CategoryInfoAgent::m_pInstance = NULL;

CategoryInfoAgent::CategoryInfoAgent()
    : m_bInitFinish(false)
    , m_bCategoryGoodsChanged(false)
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

CategoryInfoAgent *CategoryInfoAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new CategoryInfoAgent;
    }
    return m_pInstance;
}

void CategoryInfoAgent::getCategoryRequest()
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        QString sLastTime = "";
        if (m_bInitFinish)
        {
            sLastTime = KPosIni::getCategoryLastUpdateTime();
        }
        HttpClient::instance()->getCategory(sLastTime);
    }
    else
    {
        emit sigGetLocalCategory();
    }
}

void CategoryInfoAgent::getAllGoodsInfoRequest(bool bFinish)
{
    m_bCategoryGoodsChanged = false;
    m_bInitFinish = bFinish;
    if (OnlineStateAgent::instance()->isOnline())
    {
        QString sLastTime = "";
        if (bFinish)
        {
           sLastTime = KPosIni::getGoodsLastUpdateTime();
        }
        HttpClient::instance()->getAllGoods(sLastTime);
    }
    else
    {
        emit sigGetLocalAllGoods();
    }
}

void CategoryInfoAgent::getAllGoodsPriceRequest()
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        QString sLastTime = "";
        if (m_bInitFinish)
        {
            sLastTime = KPosIni::getGoodsPriceLastUpdateTime();
        }
        HttpClient::instance()->getAllGoodsPrice(sLastTime);
    }
    else
    {
        emit sigGetLocalCategory();
    }
}

void CategoryInfoAgent::slot_onGetAllGoods(int nCode, QString sMsg, QMap<QString, GoodsInfo_s> goodsInfoMap, QString sLastTime)
{
    if (nCode == e_success)
    {
        if (goodsInfoMap.size() > 0)
        {
            m_bCategoryGoodsChanged = true;
            qDebug()<<QStringLiteral("slot_onGetAllGoods -- 商品全量有变化");

//            m_goodsInfoMap = goodsInfoMap;
            setGoodsInfoMap(goodsInfoMap);

            bool bSuccess = PosDBFactory::getPosDB()->m_pGoodsInfoTable->initAllGoods(goodsInfoMap.values());
            if (bSuccess)
            {
                KPosIni::setGoodsLastUpdateTime(sLastTime);
            }
            emit sigOnGetAllGoods(nCode, sMsg);
        }
        else
        {
            slot_localGetAllGoods();
        }
    }
    else
    {
        slot_localGetAllGoods();
    }
}

void CategoryInfoAgent::slot_onGetChangedGoods(int nCode, QString sMsg, QMap<QString, GoodsInfo_s> createGoodsMap
                                               , QMap<QString, GoodsInfo_s> updateGoodsMap, QList<QString> deleteGoodsList, QString sLastTime)
{
    if (nCode == e_success)
    {
        QMap<QString, GoodsInfo_s> goodsInfoMap;
        getGoodsInfoMap(goodsInfoMap);

        // 插入内存
        QList<QString> createKeyList = createGoodsMap.keys();
        int nCreateLen = createKeyList.length();
        QString sKey;
        for (int i = 0; i < nCreateLen; i++)
        {
            sKey = createKeyList[i];
            if (!createGoodsMap.contains(sKey))
            {
                goodsInfoMap.insert(sKey, createGoodsMap.value(sKey));
            }
            else
            {
                GoodsInfo_s tempGoodsInfo = createGoodsMap.value(sKey);
                tempGoodsInfo.goodsPriceInfo = goodsInfoMap.value(sKey).goodsPriceInfo;
                goodsInfoMap.insert(sKey, tempGoodsInfo);
            }
        }
        QList<QString> updateKeyList = updateGoodsMap.keys();
        int nUpdateLen = updateKeyList.length();
        for (int i = 0; i < nUpdateLen; i++)
        {
            sKey = updateKeyList[i];
            if (!updateGoodsMap.contains(sKey))
            {
                goodsInfoMap.insert(sKey, updateGoodsMap.value(sKey));
            }
            else
            {
                GoodsInfo_s tempGoodsInfo = updateGoodsMap.value(sKey);
                tempGoodsInfo.goodsPriceInfo = goodsInfoMap.value(sKey).goodsPriceInfo;
                goodsInfoMap.insert(sKey, tempGoodsInfo);
            }
        }
        int nDeleteLen = deleteGoodsList.length();
        for (int i = 0; i < nDeleteLen; i++)
        {
            goodsInfoMap.remove(deleteGoodsList[i]);
        }
        if ((nCreateLen != 0) || (nUpdateLen != 0) || (nDeleteLen != 0))
        {
            m_bCategoryGoodsChanged = true;
            qDebug()<<QStringLiteral("slot_onGetChangedGoods -- 商品增量有变化");
            // 插入数据库
//            bool bCreateSuccess = true;
//            if (createGoodsMap.size() > 0)
//            {
//                bCreateSuccess = PosDBFactory::getPosDB()->m_pGoodsInfoTable->initAllGoods(createGoodsMap.values(), false);
//            }
//            bool bUpdateSuccess = PosDBFactory::getPosDB()->m_pGoodsInfoTable->initAllGoods(updateGoodsMap.values(), false);
            bool bCreateSuccess =PosDBFactory::getPosDB()->m_pGoodsInfoTable->initAllGoods(goodsInfoMap.values(), false);
            bool bDeleteSuccess = PosDBFactory::getPosDB()->m_pGoodsInfoTable->removeGoods(deleteGoodsList);

            if (bCreateSuccess && bDeleteSuccess)
            {
                KPosIni::setGoodsLastUpdateTime(sLastTime);
            }
        }

        setGoodsInfoMap(goodsInfoMap);
    }
    emit sigOnGetChangedGoods(nCode, sMsg);
}

void CategoryInfoAgent::slot_localGetAllGoods()
{
    if (!m_bInitFinish)
    {
        QMap<QString, GoodsInfo_s> goodsInfoMap;
        getGoodsInfoMap(goodsInfoMap);
        PosDBFactory::getPosDB()->m_pGoodsInfoTable->getAllGoodsInfo(goodsInfoMap);
        setGoodsInfoMap(goodsInfoMap);
    }
    emit sigOnGetAllGoods(e_connectServerError, c_sNetError);
}

void CategoryInfoAgent::slot_onGetAllGoodsPrice(int nCode, QString sMsg, QMap<QString, GoodsPriceInfo_s> goodsPriceInfoMap, QString sUpdateTime)
{
    if (nCode == e_success)
    {
        if (goodsPriceInfoMap.size() > 0)
        {
            m_bCategoryGoodsChanged = true;
            qDebug()<<QStringLiteral("slot_onGetAllGoodsPrice -- 商品价格有变化");
            bool bSuccess = PosDBFactory::getPosDB()->m_pGoodsInfoTable->updateGoodsPrice(goodsPriceInfoMap);
            if (bSuccess)
            {
                KPosIni::setGoodsPriceLastUpdateTime(sUpdateTime);
            }

            QMap<QString, GoodsInfo_s> goodsInfoMap;
            getGoodsInfoMap(goodsInfoMap);
            setGoodsInfoPrice(goodsInfoMap, goodsPriceInfoMap);
            setGoodsInfoMap(goodsInfoMap);
            emit sigOnChangeGoodsPrice();

        }
    }
    else
    {
        // 什么也不做
    }

    emit sigOnGetAllGoodsPrice(nCode, sMsg);
}

void CategoryInfoAgent::slot_onGetCategory(int nCode, QString sMsg, QList<CategoryInfo_s> categoryInfoList, QString sUpdateTime)
{
    if (nCode == e_success)
    {
        if (categoryInfoList.size() > 0)
        {
            m_bCategoryGoodsChanged = true;
            qDebug()<<QStringLiteral("slot_onGetCategory -- 分类有变化");
            m_categoryInfoList = categoryInfoList;
            bool bSuccess = PosDBFactory::getPosDB()->m_pCategoryTable->initCategory(m_categoryInfoList);
            if (bSuccess)
            {
                KPosIni::setCategoryLastUpdateTime(sUpdateTime);
            }

            emit sigOnGetCategory(nCode, sMsg);
            if (m_bCategoryGoodsChanged)
            {
                emit sigCategoryGoodsChanged();
            }
        }
        else if (!sUpdateTime.isEmpty())
        {
            slot_localGetCategory();
        }
        else
        {
            emit sigOnGetCategory(nCode, sMsg);
            if (m_bCategoryGoodsChanged)
            {
                emit sigCategoryGoodsChanged();
            }
        }
    }
    else
    {
        slot_localGetCategory();
    }
}

void CategoryInfoAgent::slot_localGetCategory()
{
    if (!m_bInitFinish)
    {
        PosDBFactory::getPosDB()->m_pCategoryTable->getAllCategoryInfo(m_categoryInfoList);
    }
    emit sigOnGetCategory(e_connectServerError, c_sNetError);
    if (m_bCategoryGoodsChanged)
    {
        emit sigCategoryGoodsChanged();
    }
}

void CategoryInfoAgent::initConnect()
{  
    qRegisterMetaType<QMap<QString, GoodsInfo_s> >("QMap<QString, GoodsInfo_s>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetAllGoods(int,QString,QMap<QString, GoodsInfo_s>, QString))
            , this, SLOT(slot_onGetAllGoods(int,QString,QMap<QString, GoodsInfo_s>, QString)));
    qRegisterMetaType<QList<QString> >("QList<QString>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetChangedGoods(int,QString,QMap<QString,GoodsInfo_s>,QMap<QString,GoodsInfo_s>, QList<QString>, QString))
            , this, SLOT(slot_onGetChangedGoods(int,QString,QMap<QString,GoodsInfo_s>,QMap<QString,GoodsInfo_s>,QList<QString>, QString)));
    qRegisterMetaType<QMap<QString, GoodsPriceInfo_s> >("QMap<QString, GoodsPriceInfo_s>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetAllGoodsPrice(int,QString,QMap<QString, GoodsPriceInfo_s>, QString))
            , this, SLOT(slot_onGetAllGoodsPrice(int,QString,QMap<QString, GoodsPriceInfo_s>, QString)));
    qRegisterMetaType<QList<CategoryInfo_s> >("QList<CategoryInfo_s>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetCategory(int, QString, QList<CategoryInfo_s>, QString))
            , this, SLOT(slot_onGetCategory(int, QString, QList<CategoryInfo_s>, QString)));

    connect(this, SIGNAL(sigGetLocalCategory()), this, SLOT(slot_localGetCategory()));
    connect(this, SIGNAL(sigGetLocalAllGoods()), this, SLOT(slot_localGetAllGoods()));
}

void CategoryInfoAgent::setGoodsInfoPrice(QMap<QString, GoodsInfo_s> &goodsInfoMap, const QMap<QString, GoodsPriceInfo_s> &goodsPriceInfoMap)
{
    QList<QString> keyList = goodsPriceInfoMap.keys();
    int nLen = keyList.length();
    QString sKey;
    QMap<QString, GoodsInfo_s>::iterator goodsInfoIter;
    for (int i = 0; i < nLen; i++)
    {
        sKey = keyList[i];
        if (goodsInfoMap.contains(sKey))
        {
            goodsInfoIter = goodsInfoMap.find(sKey);
            goodsInfoIter->goodsPriceInfo = goodsPriceInfoMap.value(sKey);
        }
    }
}

void CategoryInfoAgent::setGoodsInfoMap(const QMap<QString, GoodsInfo_s> &goodsInfoMap)
{
    m_goodsInfoMapLock.lockForWrite();
    m_goodsInfoMap = goodsInfoMap;
    m_goodsInfoMapLock.unlock();
}

void CategoryInfoAgent::getGoodsInfoMap(QMap<QString, GoodsInfo_s> &goodsInfoMap)
{
    m_goodsInfoMapLock.lockForRead();
    goodsInfoMap = m_goodsInfoMap;
    m_goodsInfoMapLock.unlock();
}

void CategoryInfoAgent::getCategoryList(QList<CategoryInfo_s> &categoryInfoList)
{
    categoryInfoList = m_categoryInfoList;
}

void CategoryInfoAgent::getGoodsList(QMap<int, GoodsInfo_s> &goodsInfoFirstMap, QMap<int, QList<GoodsInfo_s> > &goodsInfoSecondMap)
{
    QMap<QString, GoodsInfo_s> goodsInfoMap;
    getGoodsInfoMap(goodsInfoMap);

    QList<QString> keyList = goodsInfoMap.keys();
    int nLen = keyList.length();
    GoodsInfo_s goodsInfo;
    QMap<int, QList<GoodsInfo_s> >::iterator secondMapIter;
    for (int i = 0; i < nLen; i++)
    {
        goodsInfo = goodsInfoMap.value(keyList[i]);
        if ((goodsInfo.nPluGrade == 0) || (goodsInfo.nPluGrade == 1))
        {
            goodsInfoFirstMap.insert(goodsInfo.nId, goodsInfo);
        }
//        if (!goodsInfo.bStandard && (goodsInfo.nPluGrade >= 1))
        if (goodsInfo.nPluGrade >= 1)
        {
            if (goodsInfoSecondMap.contains(goodsInfo.nId))
            {
                secondMapIter = goodsInfoSecondMap.find(goodsInfo.nId);
                secondMapIter->append(goodsInfo);
            }
            else
            {
                QList<GoodsInfo_s> goodsInfoList;
                goodsInfoList.append(goodsInfo);
                goodsInfoSecondMap.insert(goodsInfo.nId, goodsInfoList);
            }
        }
    }
}

void CategoryInfoAgent::getGoodsList(QMap<int, GoodsInfo_s> &goodsInfoFirstMap)
{
    QMap<QString, GoodsInfo_s> goodsInfoMap;
    getGoodsInfoMap(goodsInfoMap);

    QList<QString> keyList = goodsInfoMap.keys();
    int nLen = keyList.length();
    GoodsInfo_s goodsInfo;
    for (int i = 0; i < nLen; i++)
    {
        goodsInfo = goodsInfoMap.value(keyList[i]);
        if ((goodsInfo.nPluGrade == 0) || (goodsInfo.nPluGrade == 1))
        {
            goodsInfoFirstMap.insert(goodsInfo.nId, goodsInfo);
        }
    }
}

//void CategoryInfoAgent::getWeighGoodsList(int nCategoryId, QMap<int, GoodsInfo_s> goodsInfoMap)
//{
//    int nLen = m_categoryInfoList;
//    QList<int> goodsIdList;
//    for (int i = 0; i < nLen; i++)
//    {
//        if (!m_categoryInfoList[i].bCustom && (m_categoryInfoList[i].nId == nCategoryId))
//        {
//            goodsIdList = m_categoryInfoList[i].goodsIdList;
//            break;
//        }
//    }

//    QMap<QString, GoodsInfo_s> goodsInfoMap;
//    getGoodsInfoMap(goodsInfoMap);
//    QList<GoodsInfo_s> goodsInfoList_s = goodsInfoMap.values();
//    int nLen2 = goodsInfoList_s.length();
//    for (int i = 0; i < nLen2; i++)
//    {
//        if ((!goodsInfoList_s[i].bStandard) && goodsIdList.contains(goodsInfoList_s[i].nId))
//        {

//            goodsInfoMap.insert(nCategoryId, goodsInfoList_s[i]);
//        }
//    }
//}

void CategoryInfoAgent::getAllWeighGoodsList(QMap<int, QList<GoodsInfo_s> > &goodsInfoMap)
{
    QList<int> goodsIdList;
    QMap<QString, GoodsInfo_s> tempGoodsInfoMap;
    getGoodsInfoMap(tempGoodsInfoMap);
    int nLen1 = m_categoryInfoList.length();
    QList<GoodsInfo_s> goodsInfoList_s = tempGoodsInfoMap.values();
    int nLen2 = goodsInfoList_s.length();
    QMap<int, QList<GoodsInfo_s> >::iterator goodsInfoMapIter;
    int nCategoryId = -1;
    for (int i = 0; i < nLen1 && !m_categoryInfoList[i].bCustom; i++)
    {
        goodsIdList = m_categoryInfoList[i].goodsIdList;
        nCategoryId = m_categoryInfoList[i].nId;
        for (int j = 0; j < nLen2 && (!goodsInfoList_s[j].bStandard); j++)
        {
            if (goodsIdList.contains(goodsInfoList_s[j].nId))
            {
                if (goodsInfoMap.contains(nCategoryId))
                {
                    goodsInfoMapIter = goodsInfoMap.find(nCategoryId);
                    goodsInfoMapIter->append(goodsInfoList_s[j]);
                }
                else
                {
                    QList<GoodsInfo_s> goodsInfoList;
                    goodsInfoList.append(goodsInfoList_s[j]);
                    goodsInfoMap.insert(nCategoryId, goodsInfoList);
                }
            }
        }
    }
}

void CategoryInfoAgent::getAllWeighGoodsList(QMap<QString, GoodsInfo_s> &goodsInfoMap)
{
    QMap<QString, GoodsInfo_s> tempGoodsInfoMap;
    getGoodsInfoMap(tempGoodsInfoMap);
    QList<GoodsInfo_s> goodsInfoList = tempGoodsInfoMap.values();
    int nLen = goodsInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (!goodsInfoList[i].bStandard)
        {
            goodsInfoMap.insert(goodsInfoList[i].sBarCode, goodsInfoList[i]);
        }
    }
}

bool CategoryInfoAgent::searchGoods(QString searchText, QList<GoodsInfo_s> &listGoodsInfo )
{
//    return PosDBFactory::getPosDB()->m_pGoodsInfoTable->searchGoods( strGoodsInfo, listGoodsInfo );
//    if( searchText.isEmpty() ) return false;

//    searchText = searchText.toUpper();
//    QList<QString> keyList = m_goodsInfoMap.keys();
//    int nLen = keyList.length();
//    GoodsInfo_s goodsInfo;
//    bool bGoodsBarCode = false;

//    for (int i = 0; i < nLen; i++)
//    {
//        goodsInfo = m_goodsInfoMap.value(keyList[i]);
//        if (goodsInfo.bStandard)
//        {
//            bGoodsBarCode = (searchText.length()==13) && goodsInfo.sBarCode == searchText;
//        }
//        else
//        {
//            bGoodsBarCode = (searchText.length()==7) && goodsInfo.sBarCode == searchText;
//        }

//        if (bGoodsBarCode || goodsInfo.sPluCode == searchText
//                || goodsInfo.sCode == searchText
//                || goodsInfo.sName.contains(searchText)
//                || goodsInfo.sShortName.contains(searchText)
//                || goodsInfo.sPinYinName.contains(searchText) )
////                || goodsInfo.sWuBiName.contains(searchText))
//        {
//            listGoodsInfo.append(goodsInfo);
//        }
//    }
//    return true;


    if( searchText.isEmpty() ) return false;

    searchText = searchText.toUpper();

    QMap<QString, GoodsInfo_s> goodsInfoMap;
    getGoodsInfoMap(goodsInfoMap);

    QList<GoodsInfo_s> goodsInfoList = goodsInfoMap.values();
    int nLen = goodsInfoList.length();
    GoodsInfo_s goodsInfo;

    for (int i = 0; i < nLen; i++)
    {
        goodsInfo = goodsInfoList[i];
        if ((goodsInfo.sBarCode == searchText) || goodsInfo.sPluCode == searchText
                || goodsInfo.sCode == searchText
                || goodsInfo.sName.contains(searchText)
                || goodsInfo.sShortName.contains(searchText)
                || goodsInfo.sPinYinName.contains(searchText) )
        {
            listGoodsInfo.append(goodsInfo);
        }
    }
    return true;
}

void CategoryInfoAgent::reInitFinish()
{
    m_bInitFinish = false;
}

