#include "HttpMemPasswdModify.h"
#include <QScriptEngine>
#include "KPosLog.h"
#include "HttpSignal.h"
#include "CommonFun.h"
#include "enumData.h"

HttpMemPasswdModify::HttpMemPasswdModify( QString strCorpId, QString strCardId \
                                          , QString strOldPwd, QString strNewPwd )
{
    if( !strOldPwd.isEmpty() ) {
        strOldPwd = CommonFun::getStringMd5( strOldPwd );
    }

    if( !strNewPwd.isEmpty() ) {
        strNewPwd = CommonFun::getStringMd5( strNewPwd );
    }


    QString systemParam = CommonFun::generateSystemParams( c_sHttpPwdModifyMem );
    QString userParam = QString("&hq_code=%1&card_mobile=%2&old_password=%3&new_password=%4") \
            .arg(strCorpId).arg(strCardId).arg( strOldPwd ).arg( strNewPwd );
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpMemPasswdModify::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpMemPasswdModify 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QString strCardNo = sc.property("data").property("card_no").toString();
    int nStatus = sc.property( "data").property("status").toInt32();

    HttpSignal::instance()->sigOnMemPwdModify( nCode, sMsg, strCardNo, nStatus );
    this->deleteLater();
}

void HttpMemPasswdModify::processError()
{
    HttpSignal::instance()->sigOnMemPwdModify( e_connectServerError, "当前没有网络", "", 1 );
    this->deleteLater();
}
