#include "HttpCheckReportLoss.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpCheckReportLoss::HttpCheckReportLoss(QString sToken, QString sCorpID, QString sUuid, int selectId)
{
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&order_id=%4").arg(sToken).arg(sCorpID).arg(sUuid).arg(selectId);
    QString systemParam = CommonFun::generateSystemParams(c_sCheckReportLossOrderListAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpCheckReportLoss::processResponse(QString strResult)
{
    qDebug()<<"CheckReportLoss:"<<strResult;
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpDeleteReportLossOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    HttpSignal::instance()->sigCheckReportLossOrderList(nCode, sMsg);
    this->deleteLater();
}

void HttpCheckReportLoss::processError()
{
    HttpSignal::instance()->sigCheckReportLossOrderList(e_connectServerError, c_sNetError);
    this->deleteLater();
}
