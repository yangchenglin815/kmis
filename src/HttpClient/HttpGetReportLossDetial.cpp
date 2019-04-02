#include "HttpGetReportLossDetial.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/httpstructdata.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetReportLossDetial::HttpGetReportLossDetial(QString sToken, QString sCorpID, QString sUUID, int selectId, int mode)
{
    s_mode = mode;
    m_selectId = selectId;
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&order_id=%4").arg(sToken).arg(sCorpID).arg(sUUID).arg(selectId);
    QString systemParam = CommonFun::generateSystemParams(c_sGetReportLossDetialAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetReportLossDetial::processResponse(QString strResult)
{
    qDebug()<<"getReportLossDetialList:"<<strResult;
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetReportLossDetialOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<AddReportLossSelectInfo> orderInfoList;
    if (sc.property("data").isArray())
    {

        AddReportLossSelectInfo orderInfo;
        QScriptValueIterator it(sc.property("data"));
        while (it.hasNext())
        {
            it.next();
            orderInfo.nId = 0;
            orderInfo.sName = it.value().property("product_name").toString();
            if(orderInfo.sName.isEmpty()){
                continue;
            }
            orderInfo.goodsId = it.value().property("content_id").toInt32();
            orderInfo.id = it.value().property("product_id").toInt32();
            orderInfo.sReason = it.value().property("content_remark").toInt32();
            orderInfo.sUnit = it.value().property("unit_name").toString();
            orderInfo.sCode = it.value().property("product_code").toString();
            orderInfo.sCategoryName = it.value().property("product_category").toString();
            orderInfo.sNumber = it.value().property("quantity").toString().toFloat();
            orderInfo.sMoney = it.value().property("total_amount").toString().toFloat();
            orderInfoList.append(orderInfo);
        }
    }
    if(s_mode == 0){
        HttpSignal::instance()->sigOnGetEditReportLossDetialOrderList(nCode, sMsg, orderInfoList, m_selectId);
    }
    else if(s_mode == 1){
        HttpSignal::instance()->sigOnGetReportLossDetialOrderList(nCode, sMsg, orderInfoList);
    }
    else if(s_mode == 2){
        HttpSignal::instance()->sigOnGetPrintReportLossDetialOrderList(nCode, sMsg, orderInfoList, m_selectId);
    }
    this->deleteLater();
}

void HttpGetReportLossDetial::processError()
{
    QList<AddReportLossSelectInfo> orderInfoList;
    if(s_mode == 0){
        HttpSignal::instance()->sigOnGetEditReportLossDetialOrderList(e_connectServerError, c_sNetError, orderInfoList, m_selectId);
    }
    else if(s_mode == 1){
        HttpSignal::instance()->sigOnGetReportLossDetialOrderList(e_connectServerError, c_sNetError, orderInfoList);
    }
    this->deleteLater();
}

