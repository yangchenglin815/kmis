#include "HttpRegisterPos.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include "../data/enumData.h"
#include <QScriptEngine>
#include <QDebug>

HttpRegisterPos::HttpRegisterPos(QString sCorpCode, QString sShopCode, QString sUUID)
{
    QString userParam = QString("&hq_code=%1&orgz_code=%2&uuid=%3&pos_type=%4&pos_version=%5").arg(sCorpCode).arg(sShopCode).arg(sUUID).arg("hello").arg("1.3");
    QString systemParam = CommonFun::generateSystemParams(c_sHttpRegisterPosAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpRegisterPos::processResponse(QString strResult)
{
//    qDebug()<< strResult;
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpRegisterPos 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnRegisterPos(nCode, sMsg);

    this->deleteLater();
}

void HttpRegisterPos::processError()
{
    int nCode = e_connectServerError;
    QString sMsg = QStringLiteral("网络异常");
    qDebug()<<QString("HttpRegisterPos::processError -- %1").arg(sMsg);
    HttpSignal::instance()->sigOnRegisterPos(nCode, sMsg);
    this->deleteLater();
}
