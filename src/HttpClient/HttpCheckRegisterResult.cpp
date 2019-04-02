#include "HttpCheckRegisterResult.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include "../data/constData.h"
#include "../data/httpstructdata.h"
#include "../data/enumData.h"
#include <QScriptEngine>
#include <QDebug>

HttpCheckRegisterResult::HttpCheckRegisterResult(QString sUUID)
{
    QString userParam = QString("&uuid=%1").arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpCheckRegisterResultAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpCheckRegisterResult::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpCheckRegisterResult 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    RegistResultInfo registResultInfo;
    registResultInfo.nRegistResult = sc.property("data").property("pos_status").toInt32();
    registResultInfo.sCorpCode = sc.property("data").property("hq_code").toString();
    registResultInfo.sAppKey = sc.property("data").property("app_key").toString(); // 企业授权标识
    registResultInfo.sAppSecret = sc.property("data").property("app_secret").toString(); // 企业认证密匙
//    qDebug()<<"111111111111 -- "<<registResultInfo.sAppKey;
//    qDebug()<<"222222222222 -- "<<registResultInfo.sAppSecret;
    HttpSignal::instance()->sigOnCheckRegisterResult(nCode, sMsg, registResultInfo);
    this->deleteLater();//类似析构
}

void HttpCheckRegisterResult::processError()
{
    RegistResultInfo registResultInfo;
    registResultInfo.nRegistResult = -1;
    registResultInfo.sCorpCode = "";
    HttpSignal::instance()->sigOnCheckRegisterResult(e_connectServerError, c_sNetError, registResultInfo);
    this->deleteLater();
}
