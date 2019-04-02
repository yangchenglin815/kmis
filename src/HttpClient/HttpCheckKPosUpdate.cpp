#include "HttpCheckKPosUpdate.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include "../data/constData.h"
#include "../data/httpstructdata.h"
#include "../data/enumData.h"
#include <QScriptEngine>
#include "KPosServerIni.h"

HttpCheckKPosUpdate::HttpCheckKPosUpdate(QString sCorpID, QString sUUID, QString sAppVersion)
{
    QString userParam = QString("&hq_code=%1&uuid=%2&app_version=%3").arg(sCorpID).arg(sUUID).arg(sAppVersion);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpCheckKPosUpdateAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpCheckKPosUpdate::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpCheckKPosUpdate 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    KPosUpdateInfo kPosUpdateInfo;
    kPosUpdateInfo.nUpdateType = sc.property("data").property("updateType").toInt32();
    kPosUpdateInfo.sAddress = KPosServerIni::getServerIp() + "/" + sc.property("data").property("url").toString();
    HttpSignal::instance()->sigOnCheckKPosUpdate(nCode, sMsg, kPosUpdateInfo);
    this->deleteLater();
}

void HttpCheckKPosUpdate::processError()
{
    KPosUpdateInfo kPosUpdateInfo;
    HttpSignal::instance()->sigOnCheckKPosUpdate(e_connectServerError, c_sNetError, kPosUpdateInfo);
    this->deleteLater();
}
