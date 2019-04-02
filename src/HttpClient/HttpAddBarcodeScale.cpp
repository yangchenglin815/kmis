#include "HttpAddBarcodeScale.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpAddBarcodeScale::HttpAddBarcodeScale(QString sCorpID, QString sToken, QString sUUID, QString sCode, QString sType, QString sIp, int nGroupId)
{
    QString sBcsJosn = createBcsInfoJson(sCode, sType, sIp, nGroupId);

    QString userParam = QString("&hq_code=%1&access_token=%2&uuid=%3&scale_info=%4")
            .arg(sCorpID).arg(sToken).arg(sUUID).arg(sBcsJosn);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpAddBarcodeScaleAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpAddBarcodeScale::processResponse(QString strResult)
{
//    KPosLog::instance()->writeErrorLog(this->getTestUrl());
//    KPosLog::instance()->writeErrorLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpCreateGoodsGroup 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnAddBarcodeScale(nCode, sMsg);

    this->deleteLater();

}

void HttpAddBarcodeScale::processError()
{
    HttpSignal::instance()->sigOnAddBarcodeScale(e_connectServerError, c_sNetError);
    this->deleteLater();

}

QString HttpAddBarcodeScale::createBcsInfoJson(QString sCode, QString sType, QString sIp, int nGroupId)
{
    QJsonObject dataJson;
    dataJson.insert("code", sCode);
    dataJson.insert("scale_type", sType);
    dataJson.insert("IP", sIp);
    dataJson.insert("group_id", nGroupId);

    QJsonDocument document;
    document.setObject(dataJson);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

