#include "HttpGetOrderCardList.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/ordergoodsdata.h"
#include "../data/enumData.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetOrderCardList::HttpGetOrderCardList(QString sToken, int nShopID, QString sCorpID, QString sUUID, int nLimit, int nOffset
                                           , const QList<int> &categoryIdList, int nStatus, QString sStartDate,
                                           QString sEndDate, QString sSearchText)
{
    QString categoryIdListJson = createCategoryIdListJson(categoryIdList);

    QString userParam = QString("&access_token=%1&orgz_id=%2&hq_code=%3&category_lists=%4&status=%5&uuid=%6")
            .arg(sToken).arg(nShopID).arg(sCorpID).arg(categoryIdListJson).arg(nStatus).arg(sUUID);
    if (!sStartDate.isEmpty() && !sEndDate.isEmpty())
    {
        userParam.append(QString("&start_date=%1&end_date=%2").arg(sStartDate).arg(sEndDate));
    }
    if (!sSearchText.isEmpty())
    {
        userParam.append(QString("&search_pattern=%1").arg(sSearchText));
    }
    if ((nLimit > 0) && (nOffset > 0))
    {
        userParam.append(QString("&limit=%1&offset=%2").arg(nLimit).arg(nOffset));
    }

    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetOrderCardListAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetOrderCardList::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetOrderCardList 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<OrderCardInfo_s> orderCardList;
    OrderCardInfo_s orderCardInfo;
    if (sc.property("data").isArray())
    {
        QScriptValueIterator it(sc.property("data"));
        while (it.hasNext())
        {
            it.next();        
            orderCardInfo.nOrderCardId  = it.value().property("req_order_id").toInt32();
            if (orderCardInfo.nOrderCardId == 0)
            {
                continue;
            }
            orderCardInfo.sCardOrOrderId = it.value().property("req_order_num").toString(); // 卡号/单号
            orderCardInfo.nCategoryId = it.value().property("category_id").toInt32(); // 分类id
            orderCardInfo.sCategoryName = it.value().property("category_name").toString(); // 分类名
            orderCardInfo.nCategoryNum = it.value().property("total_num").toInt32(); // 分类数量
            int nUploadState = it.value().property("upload_status").toInt32(); // 是否已上传
            orderCardInfo.bUploadFinish = ((nUploadState==0) ? false : true);
            orderCardInfo.sOrderMaker = it.value().property("create_name").toString(); // 制单人
            orderCardInfo.sUploader = it.value().property("auditor_name").toString(); // 上传人
            orderCardInfo.sUpdateTime = it.value().property("confirmed_date").toString(); // 更新时间
            orderCardInfo.sCreateTime = it.value().property("created_at").toString(); // 制单时间
            orderCardInfo.nWantState = it.value().property("card_type").toInt32(); // 时段
            orderCardList.append(orderCardInfo);
        }
    }

    HttpSignal::instance()->sigOnGetOrderCardList(nCode, sMsg, orderCardList);

    this->deleteLater();
}

void HttpGetOrderCardList::processError()
{
    QList<OrderCardInfo_s> orderCardList;
    HttpSignal::instance()->sigOnGetOrderCardList(e_connectServerError, c_sNetError, orderCardList);
    this->deleteLater();
}

QString HttpGetOrderCardList::createCategoryIdListJson(const QList<int> &categoryIdList)
{
    QJsonArray jsonArray;
    int nLen = categoryIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        QJsonObject dataJson;
        dataJson.insert("category_id", categoryIdList[i]);
        jsonArray.insert(i, dataJson); //
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

