#include "HttpMemSetStatus.h"
#include <QScriptEngine>
#include "HttpSignal.h"
#include "KPosLog.h"
#include "CommonFun.h"
#include "enumData.h"

HttpMemSetStatus::HttpMemSetStatus( QString strCorpId, QString strCardId, int nCardStatus )
{
    QString systemParam = CommonFun::generateSystemParams( c_sHttpSetStatusMemCard );
    QString userParam = QString("&hq_code=%1&card_no=%2&card_status=%3") \
            .arg(strCorpId).arg( strCardId ).arg( nCardStatus );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpMemSetStatus::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpMemSetStatus 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QString strCardNo = sc.property("data").property("card_no").toString();
    int nCardStatus = sc.property("data").property("card_status").toInt32();

    HttpSignal::instance()->sigOnMemStatus( nCode, sMsg, strCardNo, nCardStatus );
    this->deleteLater();
}

void HttpMemSetStatus::processError()
{
    HttpSignal::instance()->sigOnMemStatus( e_connectServerError, "当前没有网络", "", 1 );
    this->deleteLater();
}
