#include "HttpReplaceMemCard.h"
#include <QScriptEngine>
#include "KPosLog.h"
#include "HttpSignal.h"
#include "CommonFun.h"
#include "enumData.h"

HttpReplaceMemCard::HttpReplaceMemCard( QString strCorpId, QString strOldCardId, QString strNewCardId, QString strUserName )
    : m_sOldCardId( "" )
    , m_sNewCardId( "" )
{
    m_sOldCardId = strOldCardId;
    m_sNewCardId = strNewCardId;

    QString systemParam = CommonFun::generateSystemParams( c_sHttpReplaceCard );
    QString userParam = QString("&hq_code=%1&old_card_no=%2&new_card_no=%3&user_name=%4") \
            .arg(strCorpId).arg( strOldCardId ).arg( strNewCardId ).arg( strUserName );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpReplaceMemCard::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpReplaceMemCard 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnReplaceMemCard( nCode, sMsg, m_sOldCardId, m_sNewCardId );
    this->deleteLater();
}

void HttpReplaceMemCard::processError()
{
    HttpSignal::instance()->sigOnReplaceMemCard( e_connectServerError, "当前没有网络", "", "" );
    this->deleteLater();
}
