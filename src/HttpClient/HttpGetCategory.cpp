#include "HttpGetCategory.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include "../data/httpstructdata.h"
#include "../data/enumData.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetCategory::HttpGetCategory(QString sToken, QString sUUID, QString sCorpID, QString sLastTime)
{
    QString userParam = QString("&uuid=%1&hq_code=%2&access_token=%3").arg(sUUID).arg(sCorpID).arg(sToken);
    if (!sLastTime.isEmpty())
    {
        userParam.append(QString("&last_update_time=%2").arg(sLastTime));
    }
    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetCategoryAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetCategory::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetCategory 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QString sUpdateTime = sc.property("update_time").toString();
    QList<CategoryInfo_s> categoryInfoList;
    // 自定义分类数据
    if (sc.property("data").isArray())
    {
        QScriptValueIterator it(sc.property("data"));
        CategoryInfo_s categoryInfo;
        while (it.hasNext())
        {
            it.next();
            categoryInfo.nId = it.value().property("category_id").toInt32();
            if (categoryInfo.nId == 0)
            {
                continue;
            }
            categoryInfo.bCustom = (it.value().property("is_customed").toInt32() == 1);
            categoryInfo.sKeyId = QString("%1+%2").arg(categoryInfo.bCustom ? 1 : 0).arg(categoryInfo.nId);
            categoryInfo.sName = it.value().property("category_name").toString();
            categoryInfo.goodsIdList.clear();
            QString sGoodsIdList = it.value().property("product_id").toString();
            if (!sGoodsIdList.isEmpty())
            {
                QList<QString> goodsIdList = sGoodsIdList.split(",");
                for (int i = 0; i < goodsIdList.length(); i++)
                {
                    categoryInfo.goodsIdList.append(goodsIdList[i].toInt());
                }
            }
            categoryInfoList.append(categoryInfo);
        }
        if (categoryInfoList.size() > 0)
        {
            KPosLog::instance()->writeTestLog(QStringLiteral("分类有变化"));
            KPosLog::instance()->writeTestLog(this->getTestUrl());
            KPosLog::instance()->writeTestLog(strResult);
        }
    }

    if (!sUpdateTime.isEmpty() && (nCode == e_success) && (categoryInfoList.length() == 0))
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnGetCategory(nCode, sMsg, categoryInfoList, sUpdateTime);

    this->deleteLater();
}

void HttpGetCategory::processError()
{
    QList<CategoryInfo_s> categoryInfoList;
    HttpSignal::instance()->sigOnGetCategory(e_connectServerError, c_sNetError, categoryInfoList, "");
    this->deleteLater();
}
