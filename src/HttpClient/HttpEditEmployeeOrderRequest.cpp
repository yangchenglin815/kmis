#include "HttpEditEmployeeOrderRequest.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpEditEmployeeOrderRequest::HttpEditEmployeeOrderRequest(QString sToken, QString sCorpID, QString sUuid, AccountInfo info, int status)
{
    m_info = info;
    m_status = status;
    QJsonObject dataJson;
    if(m_status == 0){
        dataJson.insert("id", m_info.id);
    }
    dataJson.insert("code", m_info.sAccountID);
    dataJson.insert("realname", m_info.sName);
    dataJson.insert("password", m_info.sPasswd);
    dataJson.insert("mobile", m_info.sTelnumber);
    dataJson.insert("role_code", m_info.sPower);
    QJsonDocument document;
    document.setObject(dataJson);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString byte_str = QString::fromUtf8(byte_array);

    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&user_info=%4&is_new=%5").arg(sToken).arg(sCorpID).arg(sUuid).arg(byte_str).arg(m_status);
    QString systemParam = CommonFun::generateSystemParams(c_sEditEmployeeOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpEditEmployeeOrderRequest::processResponse(QString strResult)
{
    qDebug()<<"EditEmployeeOrder:"<<strResult;
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpEditEmployeeOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    HttpSignal::instance()->sigOnEditEmployeeOrder(nCode, sMsg);
    this->deleteLater();
}

void HttpEditEmployeeOrderRequest::processError()
{
    HttpSignal::instance()->sigOnEditEmployeeOrder(e_connectServerError, c_sNetError);
    this->deleteLater();
}
