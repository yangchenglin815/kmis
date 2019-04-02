#include "HttpGetEmployeeScodeOrder.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpGetEmployeeScodeOrder::HttpGetEmployeeScodeOrder(QString sToken, QString sCorpID, QString sUuid)
{
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3").arg(sToken).arg(sCorpID).arg(sUuid);
    QString systemParam = CommonFun::generateSystemParams(c_sGetEmployeeScodeOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetEmployeeScodeOrder::processResponse(QString strResult)
{
    qDebug()<<"GetEmployeeScode:"<<strResult;
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if(!sc.property("code").isValid()){
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetEmployScodeOrder 返回值json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if(nCode != e_success){
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    QString nScode;
    if(!sc.property("data").isNull()){
        nScode = sc.property("data").toString();
    }
    HttpSignal::instance()->sigOnGetEmployeeScodeOrder(nCode, sMsg, nScode);
    this->deleteLater();

}

void HttpGetEmployeeScodeOrder::processError()
{
    QString nScode;
    HttpSignal::instance()->sigOnGetEmployeeScodeOrder(e_connectServerError, c_sNetError, nScode);
    this->deleteLater();
}
