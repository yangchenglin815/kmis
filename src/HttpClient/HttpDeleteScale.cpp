#include "HttpDeleteScale.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include <QScriptEngine>
#include <QScriptValue>

HttpDeleteScale::HttpDeleteScale(QString sCorpID, QString sToken, QString sUUID, QString scaleId)
{
    m_nScaleId = scaleId;
    QString userParam = QString("&hq_code=%1&access_token=%2&uuid=%3&scale_id=%5")
            .arg(sCorpID).arg(sToken).arg(sUUID).arg(scaleId);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpDeleteScaleAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpDeleteScale::processResponse(QString strResult)
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

    HttpSignal::instance()->sigOnDeleteScale(nCode, sMsg, m_nScaleId);
    this->deleteLater();
}

void HttpDeleteScale::processError()
{
    HttpSignal::instance()->sigOnDeleteScale(e_connectServerError, c_sNetError, m_nScaleId);
    this->deleteLater();
}

