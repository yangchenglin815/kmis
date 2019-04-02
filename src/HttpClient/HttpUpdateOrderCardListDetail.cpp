#include "HttpUpdateOrderCardListDetail.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include <QScriptEngine>

HttpUpdateOrderCardListDetail::HttpUpdateOrderCardListDetail(QString sToken, QString sCorpID, QString sUUID,const QMap<int, int>& changedNumMap
                                                             , const QList<int>& orderCardIdList)
{
    QString changedNumMapJson = createChangedNumMapJson(changedNumMap);
    QString orderCardIdListJson = createOrderCardIdListJson(orderCardIdList);

    QString userParam = QString("&access_token=%1&hq_code=%2&product_lists=%3&req_order_lists=%4&uuid=%5")
            .arg(sToken).arg(sCorpID).arg(changedNumMapJson).arg(orderCardIdListJson).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpUpdateOrderCardListDetatilAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpUpdateOrderCardListDetail::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpUpdateOrderCardListDetatil 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnUpdateOrderCardListDetail(nCode, sMsg);
    this->deleteLater();
}

void HttpUpdateOrderCardListDetail::processError()
{
    HttpSignal::instance()->sigOnUpdateOrderCardListDetail(e_connectServerError, c_sNetError);
    this->deleteLater();
}

QString HttpUpdateOrderCardListDetail::createChangedNumMapJson(const QMap<int, int> &changedNumMap)
{
    QJsonArray jsonArray;
    QList<int> keysList = changedNumMap.keys();
    int nLen = keysList.length();
    int nKey = -1;
    int nValue = -1;
    for (int i = 0; i < nLen; i++)
    {
        nKey = keysList[i];
        nValue = changedNumMap.value(nKey);
        QJsonObject dataJson;
        dataJson.insert("product_id", nKey);
        dataJson.insert("req_package", nValue);
        jsonArray.insert(i, dataJson); //
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

QString HttpUpdateOrderCardListDetail::createOrderCardIdListJson(const QList<int> &orderCardIdList)
{
    QJsonArray jsonArray;
    int nLen = orderCardIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        QJsonObject dataJson;
        dataJson.insert("req_order_id", orderCardIdList[i]);
        jsonArray.insert(i, dataJson); //
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}



