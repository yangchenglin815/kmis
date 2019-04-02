#include "HttpChangeEmployeeStatusOrder.h"

#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpChangeEmployeeStatusOrder::HttpChangeEmployeeStatusOrder(QString sToken, QString sCorpID, QString sUuid, QList<int> nOrderIdList, int status)
{
   m_nOrderIdList = nOrderIdList;
   m_nStatus = status;
   QStringList strList;
   int nLen = m_nOrderIdList.length();
   for(int i=0; i<nLen; i++){
       strList.append(QString::number(m_nOrderIdList.at(i)));
   }
   QString nOrderId = strList.join(",");
   QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&user_ids=%4&status=%5").arg(sToken).arg(sCorpID).arg(sUuid).arg(nOrderId).arg(status);
   QString systemParam = CommonFun::generateSystemParams(c_sUpdateEmployeeStatusOrderAction);
   QStringList paramList = systemParam.append(userParam).split("&");
   QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
   QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
   QByteArray array;
   array.append(allParam);
   setReqParams(array);
}

void HttpChangeEmployeeStatusOrder::processResponse(QString strResult)
{
    qDebug()<<"ChangeEmployeeStatuss:"<<strResult;
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpChangeEmployeeStatusOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    HttpSignal::instance()->sigOnChangeEmployeeStatusOrder(nCode, sMsg, m_nOrderIdList, m_nStatus);
    this->deleteLater();
}

void HttpChangeEmployeeStatusOrder::processError()
{
    HttpSignal::instance()->sigOnChangeEmployeeStatusOrder(e_connectServerError, c_sNetError, m_nOrderIdList, m_nStatus);
    this->deleteLater();
}

