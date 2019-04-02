#include "HttpGetBarcodeScaleCode.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include <QScriptEngine>

HttpGetBarcodeScaleCode::HttpGetBarcodeScaleCode(QString sCorpID, QString sToken, QString sUUID)
{
    QString userParam = QString("&hq_code=%1&access_token=%2&uuid=%3").arg(sCorpID).arg(sToken).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetBarcodeScaleCodeAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetBarcodeScaleCode::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();//状态值
    QString sMsg = sc.property("msg").toString();//返回消息
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetBarcodeScaleCode 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QString sBcsCode = sc.property("data").toString();
    HttpSignal::instance()->sigOnGetBarcodeScaleCode(nCode, sMsg, sBcsCode);

    this->deleteLater();
}

void HttpGetBarcodeScaleCode::processError()
{
    HttpSignal::instance()->sigOnGetBarcodeScaleCode(e_connectServerError, c_sNetError, "");
    this->deleteLater();
}

