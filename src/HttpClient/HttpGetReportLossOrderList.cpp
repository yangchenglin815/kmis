#include "HttpGetReportLossOrderList.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/httpstructdata.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetReportLossOrderList::HttpGetReportLossOrderList(QString sToken, QString sCorpID, QString sUUID, QString sStartDate, QString sEndDate, QString searchPatter, int nLimit, int nOffset)
{
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3").arg(sToken).arg(sCorpID).arg(sUUID);
    if (!sStartDate.isEmpty() && !sEndDate.isEmpty())
    {
        userParam.append(QString("&start_date=%1&end_date=%2").arg(sStartDate).arg(sEndDate));
    }
    if (!searchPatter.isEmpty())
    {
        userParam.append(QString("&search_pattern=%1").arg(searchPatter));
    }
    if (nLimit > 0)
    {
        userParam.append(QString("&limit=%1&offset=%2").arg(nLimit).arg(nOffset));
    }

    QString systemParam = CommonFun::generateSystemParams(c_sGetReportLossOrderListAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetReportLossOrderList::processResponse(QString strResult)
{
    qDebug()<<"getReportLossList:"<<strResult;
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetReportLossOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<ReportLossInfo> orderInfoList;
    if (sc.property("data").isArray())
    {

        ReportLossInfo orderInfo;
        QScriptValueIterator it(sc.property("data"));
        while (it.hasNext())
        {
            it.next();
            orderInfo.id = it.value().property("order_id").toInt32();// 单号id
            if(orderInfo.id <= 0){
                continue;
            }
            orderInfo.InfoID = it.value().property("order_code").toString(); // 单号
            orderInfo.checkName = it.value().property("auditor_name").toString(); // 审核人姓名
            orderInfo.checkTime = it.value().property("confirmed_date").toString(); // 审核时间
            orderInfo.createName = it.value().property("creator_name").toString(); // 制单人姓名
            orderInfo.createTime = it.value().property("created_at").toString(); // 制单时间
            orderInfo.status = it.value().property("confirmed").toInt32(); // 状态
            orderInfoList.append(orderInfo);
        }
    }
    HttpSignal::instance()->sigOnGetReportLossOrderList(nCode, sMsg, orderInfoList);
    this->deleteLater();
}

void HttpGetReportLossOrderList::processError()
{
    QList<ReportLossInfo> orderInfoList;
    HttpSignal::instance()->sigOnGetReportLossOrderList(e_connectServerError, c_sNetError, orderInfoList);
    this->deleteLater();
}

