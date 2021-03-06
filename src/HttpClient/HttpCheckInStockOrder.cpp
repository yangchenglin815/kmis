#include "HttpCheckInStockOrder.h"

#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpCheckInStockOrder::HttpCheckInStockOrder(QString sToken, QString sCorpID,QString sUuid,int nOrderId)
{
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&order_id=%4").arg(sToken).arg(sCorpID).arg(sUuid).arg(nOrderId);
    QString systemParam = CommonFun::generateSystemParams(c_sCheckInStockOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpCheckInStockOrder::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpCheckInStockOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnCheckInStockOrder(nCode, sMsg);
    this->deleteLater();
}

void HttpCheckInStockOrder::processError()
{
    HttpSignal::instance()->sigOnCheckInStockOrder(e_connectServerError, c_sNetError);
    this->deleteLater();
}


