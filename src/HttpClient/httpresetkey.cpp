#include "httpresetkey.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include <QScriptEngine>
#include <QScriptValue>

HttpResetKey::HttpResetKey(QString sCorpID, QString sToken, QString sUUID, QString oldkey, QString newkey)
{
    QString userParam = QString("&hq_code=%1&uuid=%2&access_token=%3&old_password=%4&new_password=%5")
            .arg(sCorpID).arg(sUUID).arg(sToken).arg(oldkey).arg(newkey);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpResetPasswdAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpResetKey::processResponse(QString strResult)
{
    KPosLog::instance()->writeErrorLog(this->getTestUrl());
    KPosLog::instance()->writeErrorLog(strResult);
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

    HttpSignal::instance()->sigResetPasswd(nCode, sMsg);
    this->deleteLater();
}

void HttpResetKey::processError()
{
    HttpSignal::instance()->sigResetPasswd(e_connectServerError, c_sNetError);
    this->deleteLater();
}
