#include "HttpGetSaleDetialOrderList.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>
#include "QScriptValueIterator"

HttpGetSaleDetialOrderList::HttpGetSaleDetialOrderList(QString sToken, QString sCropID, QString sUuid)
{
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3").arg(sToken).arg(sCropID).arg(sUuid);
    QString systemParam = CommonFun::generateSystemParams(c_sGetSaleDetialOrderListAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetSaleDetialOrderList::processResponse(QString strResult)
{
    qDebug()<<"GetSaleDetial:"<<strResult;
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if(!sc.property("code").isValid()){
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetSaleDetialOrder 返回值json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if(nCode != e_success){
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    QList<ReceiptInfo> orderInfoList;
    if(sc.property("data").isArray()){
        ReceiptInfo orderInfo;
        QScriptValueIterator it(sc.property("data"));
        while(it.hasNext()){
            it.next();
            orderInfo.bScode = it.value().property("sales_num").toString();
            if(orderInfo.bScode.isEmpty()){
                continue;
            }
            orderInfo.salemanId = it.value().property("cashier_code").toString();
            orderInfo.bSaleman = it.value().property("cashier_name").toString();
            orderInfo.saleGuideId = it.value().property("assistant_code").toString();
            orderInfo.bSaleGuide = it.value().property("assistant_name").toString();
            orderInfo.bDealTime = it.value().property("deal_complete_at").toString();
            orderInfo.state = it.value().property("deal_status").toInt32();
            orderInfo.type = it.value().property("genre").toInt32();
            orderInfoList.append(orderInfo);
        }
    }
    HttpSignal::instance()->sigOnGetSaleDetialOrderList(nCode, sMsg, orderInfoList);
    this->deleteLater();
}

void HttpGetSaleDetialOrderList::processError()
{
    QList<ReceiptInfo> orderInfoList;
    HttpSignal::instance()->sigOnGetSaleDetialOrderList(e_connectServerError, c_sNetError, orderInfoList);
    this->deleteLater();
}

