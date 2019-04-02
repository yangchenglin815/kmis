#include "HttpReplaceCard.h"
#include "CommonFun.h"
#include "KPosLog.h"
#include <QScriptEngine>
#include "HttpSignal.h"
#include "enumData.h"

HttpReplaceCard::HttpReplaceCard( QString sCorpCode, QString strOldCardNo, QString strNewCardNo )
{
    QString userParam = QString("&hq_code=%1&old_card_no=%2&new_card_no=%3") \
            .arg(sCorpCode).arg( strOldCardNo ).arg( strNewCardNo );
    QString systemParam = CommonFun::generateSystemParams( c_sHttpReplaceCard );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);

    KPosLog::instance()->writeDebugLog( allParam );
}

void HttpReplaceCard::processResponse(QString strResult)
{
    //    qDebug()<<strResult;
//    KPosLog::instance()->writeTestLog(strResult);
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpDownloadKPosSet 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnMemReplaceCard( nCode, sMsg );

    this->deleteLater();
}

void HttpReplaceCard::processError()
{
    HttpSignal::instance()->sigOnMemReplaceCard( e_connectServerError, QStringLiteral("网络异常") );
    this->deleteLater();
}
