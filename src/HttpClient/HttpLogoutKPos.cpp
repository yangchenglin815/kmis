#include "HttpLogoutKPos.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include <QScriptEngine>

HttpLogoutKPos::HttpLogoutKPos(QString sToken, QString sCorpID, QString sUUID, bool bGetReport)
{
    m_bGetReport = bGetReport;
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3").arg(sToken).arg(sCorpID).arg(sUUID);
    if (bGetReport)
    {
        userParam.append(QString("&print_report=%1").arg(1));
    }

    QString systemParam = CommonFun::generateSystemParams(c_sHttpLogoutKPosAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpLogoutKPos::processResponse(QString strResult)
{
    KPosLog::instance()->writeTestLog(this->getTestUrl());
    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpLogoutKPos 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnLogoutKPos(nCode, sMsg);

    this->deleteLater();
}

void HttpLogoutKPos::processError()
{
    HttpSignal::instance()->sigOnLogoutKPos(e_connectServerError, c_sNetError);
    this->deleteLater();
}

