#include "HttpGetOrderCategory.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/ordergoodsdata.h"
#include "../data/enumData.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetOrderCategory::HttpGetOrderCategory(QString sToken, QString sCorpID, int nLevel, int nType, QString sUUID)
{
    m_nType = nType;

    QString userParam = QString("&access_token=%1&hq_code=%2&level=%3&uuid=%4").arg(sToken).arg(sCorpID).arg(nLevel).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetOrderCategoryAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetOrderCategory::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetOrderCategory 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<OrderCategoryBigInfo_s> orderCategoryBigList;
    OrderCategoryBigInfo_s orderCategoryBigInfo;
    OrderCategorySmallInfo_s orderCategorySmallInfo;
    if (sc.property("data").isArray())
    {
        QScriptValueIterator bigIt(sc.property("data"));

        while (bigIt.hasNext())
        {
            bigIt.next();
            orderCategoryBigInfo.nId = bigIt.value().property("category_id").toInt32();
            if (orderCategoryBigInfo.nId == 0)
            {
                continue;
            }
            orderCategoryBigInfo.smallCategoryList.clear();
            orderCategoryBigInfo.sName = bigIt.value().property("category_name").toString();
            if (bigIt.value().property("list").isArray())
            {
                QScriptValueIterator smallIt(bigIt.value().property("list"));
                while(smallIt.hasNext())
                {
                    smallIt.next();
                    orderCategorySmallInfo.nId = smallIt.value().property("category_id").toInt32();
                    if (orderCategorySmallInfo.nId == 0)
                    {
                        continue;
                    }
                    orderCategorySmallInfo.sName = smallIt.value().property("category_name").toString();
                    QScriptValue listScriptValue = smallIt.value().property("list");
                    addSmallCategoryIdList(listScriptValue, orderCategorySmallInfo.leafCategoryIdList);
                    if (orderCategorySmallInfo.leafCategoryIdList.length() == 0)
                    {
                        orderCategorySmallInfo.leafCategoryIdList.append(orderCategorySmallInfo.nId);
                    }
                    orderCategoryBigInfo.smallCategoryList.append(orderCategorySmallInfo);                    
                    orderCategorySmallInfo.leafCategoryIdList.clear();
                }
            }
            orderCategoryBigList.append(orderCategoryBigInfo);
        }
    }

    if (m_nType == e_getCategoryForOrder)
    {
       HttpSignal::instance()->sigOnGetOrderCategory(nCode, sMsg, orderCategoryBigList);
    }
    else if (m_nType == e_getCategoryForCheck)
    {
       HttpSignal::instance()->sigOnGetOrderCategoryForCheck(nCode, sMsg, orderCategoryBigList);
    }

    this->deleteLater();
}

void HttpGetOrderCategory::processError()
{
    QList<OrderCategoryBigInfo_s> orderCategoryBigList;
    HttpSignal::instance()->sigOnGetOrderCategoryForCheck(e_connectServerError, c_sNetError, orderCategoryBigList);
    this->deleteLater();
}

void HttpGetOrderCategory::addSmallCategoryIdList(QScriptValue &listScriptValue, QList<int> &list)
{
    if (listScriptValue.isArray())
    {
        QScriptValueIterator it(listScriptValue);
        while(it.hasNext())
        {
            it.next();
            int nId = it.value().property("category_id").toInt32();
            if (nId == 0)
            {
                continue;
            }
            list.append(nId);
            QScriptValue nextScriptValue = it.value().property("list");
            addSmallCategoryIdList(nextScriptValue, list);
        }
    }
}

