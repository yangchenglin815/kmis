#include "HttpRemoveStockOrder.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpRemoveStockOrder::HttpRemoveStockOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId)
{
    m_nOrderId = nOrderId;

    QString userParam = QString("&access_token=%1&hq_code=%2&order_id=%3&uuid=%4")
            .arg(sToken).arg(sCorpID).arg(nOrderId).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sRemoveStockOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpRemoveStockOrder::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpRemoveStockOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnRemoveStockOrder(nCode, sMsg, m_nOrderId);
    this->deleteLater();
}

void HttpRemoveStockOrder::processError()
{
    HttpSignal::instance()->sigOnRemoveStockOrder(e_connectServerError, c_sNetError, m_nOrderId);
    this->deleteLater();
}

