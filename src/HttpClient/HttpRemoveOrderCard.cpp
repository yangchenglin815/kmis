#include "HttpRemoveOrderCard.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include "../data/enumData.h"
#include "../data/constData.h"
#include <QScriptEngine>

HttpRemoveOrderCard::HttpRemoveOrderCard(QString sToken, QString sCorpID, QString sUUID, const QList<int> &orderIdList)
{
    QString sOrderIds = createOrderIdListJson(orderIdList);
    QString userParam = QString("&access_token=%1&hq_code=%2&req_order_lists=%3&uuid=%4").arg(sToken).arg(sCorpID).arg(sOrderIds).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpRemoveOrderCardAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpRemoveOrderCard::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpRemoveStockOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnRemoveOrderCard(nCode, sMsg);
    this->deleteLater();
}

void HttpRemoveOrderCard::processError()
{
    HttpSignal::instance()->sigOnRemoveOrderCard(e_connectServerError, c_sNetError);
    this->deleteLater();
}

QString HttpRemoveOrderCard::createOrderIdListJson(const QList<int> &orderIdList)
{
    QJsonArray jsonArray;
    int nLen = orderIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        QJsonObject dataJson;
        dataJson.insert("req_order_id", orderIdList[i]);
        jsonArray.insert(i, dataJson); //
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

