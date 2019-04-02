#include "HttpReceiveGoodsStart.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include <QScriptEngine>

HttpReceiveGoodsStart::HttpReceiveGoodsStart(QString sToken, int nDeliveryId)
{
    m_nDeliveryId = nDeliveryId;

    QString userParam = QString("&access_token=%1&delivery_order_id=%2").arg(sToken).arg(nDeliveryId);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpReceiveGoodsStartAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpReceiveGoodsStart::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpReceiveGoodsStart 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnStartReceiveGoods(nCode, sMsg, m_nDeliveryId);

    this->deleteLater();
}

void HttpReceiveGoodsStart::processError()
{
    HttpSignal::instance()->sigOnStartReceiveGoods(e_connectServerError, c_sNetError, c_nNegativeNumber);
    this->deleteLater();
}

