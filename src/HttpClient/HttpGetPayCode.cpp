#include "HttpGetPayCode.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include <QScriptEngine>

HttpGetPayCode::HttpGetPayCode(QString sCardNum)
{
    QString userParam = QString("&card_pay_code=%1").arg(sCardNum);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetPayCodeAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetPayCode::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetPayCode 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    PayStoreCardInfo payStoreCardInfo;
    payStoreCardInfo.sCardID = sc.property("data").property("card_id").toString();
    payStoreCardInfo.sCardNum = sc.property("data").property("card_printed_num").toString();
    payStoreCardInfo.fCardBalance = sc.property("data").property("card_balance").toString().toFloat();
    HttpSignal::instance()->sigOnPayStoreCardInfo(nCode, sMsg, payStoreCardInfo);
    this->deleteLater();
}

void HttpGetPayCode::processError()
{
    this->deleteLater();
}

