#include "HttpGetEmployeeManageOrderList.h"

#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include "../data/stockdata.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetEmployeeManageOrderList::HttpGetEmployeeManageOrderList(QString sToken, QString sCorpID, QString sUUID, QString searchPatter, int nLimit, int nOffset)
{
   QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3").arg(sToken).arg(sCorpID).arg(sUUID);
   if(!searchPatter.isEmpty()){
       userParam.append(QString("&search_pattern=%1").arg(searchPatter));
   }
   if (nLimit > 0)
   {
       userParam.append(QString("&limit=%1&offset=%2").arg(nLimit).arg(nOffset));
   }

   QString systemParam = CommonFun::generateSystemParams(c_sGetEmployeeManageOrderListAction);
   QStringList paramList = systemParam.append(userParam).split("&");
   QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
   QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
   QByteArray array;
   array.append(allParam);
   setReqParams(array);
}

void HttpGetEmployeeManageOrderList::processResponse(QString strResult)
{
   qDebug()<<"EmployeeManage:"<<strResult;
   QScriptEngine engine;
   QScriptValue sc = engine.evaluate("value=" + strResult);
   int nCode = sc.property("code").toInt32();
   QString sMsg = sc.property("msg").toString();
   if(!sc.property("code").isValid()){
       KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetEmployManageOrderList 返回值json格式错误"));
       nCode = e_connectServerError;
       sMsg = c_sServerJsonError;
   }
   if(nCode != e_success){
       KPosLog::instance()->writeErrorLog(this->getTestUrl());
       KPosLog::instance()->writeErrorLog(strResult);
   }

   QList<AccountInfo> orderInfoList;
   if(sc.property("data").isArray()){
       AccountInfo orderInfo;
       QScriptValueIterator it(sc.property("data"));
       while(it.hasNext()){
           it.next();
           orderInfo.id = it.value().property("id").toInt32();
           if(orderInfo.id <= 0){
               continue;
           }
           orderInfo.sAccountID = it.value().property("user_code").toString();
           orderInfo.sName = it.value().property("realname").toString();
           orderInfo.sTelnumber = it.value().property("mobile").toString();
           orderInfo.sPower = it.value().property("role_code").toString();
           orderInfo.status = it.value().property("status").toInt32();
           orderInfoList.append(orderInfo);
       }
   }
   HttpSignal::instance()->sigOnGetEmployeeManageOrderList(nCode, sMsg, orderInfoList);
   this->deleteLater();
}

void HttpGetEmployeeManageOrderList::processError()
{
   QList<AccountInfo> orderInfoList;
   HttpSignal::instance()->sigOnGetEmployeeManageOrderList(e_connectServerError, c_sNetError, orderInfoList);
   this->deleteLater();
}

