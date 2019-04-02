#include "HttpUploadOrderCard.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/enumData.h"
#include "../data/constData.h"
#include <QScriptEngine>

HttpUploadOrderCard::HttpUploadOrderCard(QString sToken, QString sCorpID, QString sUUID, const QList<int> &orderCardIdList)
{
    m_orderCardIdList = orderCardIdList;

    QString sOrderIdListJson = createOrderIdListJson(orderCardIdList);

    QString userParam = QString("&access_token=%1&hq_code=%2&req_order_lists=%3&uuid=%4").arg(sToken).arg(sCorpID).arg(sOrderIdListJson).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpUploadOrderCardAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpUploadOrderCard::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpUploadOrderCard 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnUploadOrderCard(nCode, sMsg, m_orderCardIdList);
    this->deleteLater();
}

void HttpUploadOrderCard::processError()
{
    HttpSignal::instance()->sigOnUploadOrderCard(e_connectServerError, c_sNetError, m_orderCardIdList);
    this->deleteLater();
}

QString HttpUploadOrderCard::createOrderIdListJson(const QList<int> &orderCardIdList)
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

