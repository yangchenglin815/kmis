#include "HttpUploadClientCashSubmitSync.h"
#include "PosDBFactory.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include <QScriptEngine>
#include <QDebug>


HttpUploadClientCashSubmitSync::HttpUploadClientCashSubmitSync(QString sToken, QString sCorpID, QString sSubmitAmount,QString sUUID, QString sOperateAt,
                                                               QString sLastSubmitAt,QString sUserCode,QString login_at,QString logout_at,QString submit_code)
{
    QString userParam = QString("&access_token=%1&hq_code=%2&submit_amount=%3&uuid=%4&submit_at=%5&last_submit_at=%6&cashier_id=%7&login_at=%8"
                                "&logout_at=%9&submit_code=%10")
            .arg(sToken).arg(sCorpID).arg(sSubmitAmount).arg(sUUID).arg(sOperateAt).arg(sLastSubmitAt).arg(sUserCode).arg(login_at).arg(logout_at).arg(submit_code);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpUploadClientCashSubmitSync);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpUploadClientCashSubmitSync::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    QString submit_code = sc.property("submit_code").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpUploadClientCashSubmit 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    if(submit_code != ""){

        PosDBFactory::getPosDB()->m_pClientCashSubmitTable->updateClentCashStatus(submit_code);
    }


    HttpSignal::instance()->sigOnUploadClientCashSubmit(nCode, sMsg);
    this->deleteLater();
}

void HttpUploadClientCashSubmitSync::processError()
{
    HttpSignal::instance()->sigOnUploadClientCashSubmit(e_connectServerError, c_sNetError);
    this->deleteLater();
}

