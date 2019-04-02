#include "HttpCheckIsOnline.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include "../util/CommonFun.h"
#include <QScriptEngine>

HttpCheckIsOnline::HttpCheckIsOnline(QString sToken, QString sCorpID, QString sUUID)
{
    QString systemParam = QString("app_key=%1&action=%2&timestamp=%3&version=%4").arg("")
            .arg(c_sHttpOnlineCheckAction).arg(CommonFun::getCurDateTime()).arg(c_sHttpServerVersion);
    QStringList paramList = systemParam.split("&");
    paramList.sort();
    int nLen = paramList.length();
    QString sParams;
    for (int i = 0; i < nLen; i++)
    {
        sParams.append(paramList[i].replace("=",""));
    }
    QString appSecretParam = QString("app_secret").append("D41D8CD98F00B204E9800998ECF8427E");
    QByteArray bb = QCryptographicHash::hash(appSecretParam.append(sParams).toUtf8(), QCryptographicHash::Md5);
    QString sMd5Sign = bb.toHex().toUpper();
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpCheckIsOnline::processResponse(QString strResult)
{
//    KPosLog::instance()->writeErrorLog(this->getTestUrl());
//    KPosLog::instance()->writeErrorLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpCheckIsOnline 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    else
    {
        QString sDateTime = sc.property("datetime").toString();
        CommonFun::adjustDateTime(sDateTime);
    }

    HttpSignal::instance()->sigOnlineState(true);
    this->deleteLater();
}

void HttpCheckIsOnline::processError()
{
    HttpSignal::instance()->sigOnlineState(false);
    this->deleteLater();
}
