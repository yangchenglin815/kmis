#include "HttpRemoveAdjustPriceOrder.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include <QScriptEngine>

HttpRemoveAdjustPriceOrder::HttpRemoveAdjustPriceOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId)
{
    m_nOrderId = nOrderId;

    QString userParam = QString("&access_token=%1&hq_code=%2&order_id=%3&uuid=%4").arg(sToken).arg(sCorpID).arg(nOrderId).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sRemoveAdjustPriceOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpRemoveAdjustPriceOrder::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpRemoveAdjustPriceOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnRemoveAdjustPriceOrder(nCode, sMsg, m_nOrderId);
    this->deleteLater();
}

void HttpRemoveAdjustPriceOrder::processError()
{
    HttpSignal::instance()->sigOnRemoveAdjustPriceOrder(e_connectServerError, c_sNetError, m_nOrderId);
    this->deleteLater();
}

