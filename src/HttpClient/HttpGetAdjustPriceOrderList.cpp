#include "HttpGetAdjustPriceOrderList.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/adjustpricedata.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetAdjustPriceOrderList::HttpGetAdjustPriceOrderList(QString sToken, QString sCorpID, QString sUUID,
                                                         QString sStartDate, QString sEndDate
                                                         , QString searchPatter, int nLimit, int nOffset)
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

    QString systemParam = CommonFun::generateSystemParams(c_sGetAdjustPriceOrderListAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetAdjustPriceOrderList::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpCheckAdjustPriceOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<AdjustPriceOrderInfo> orderInfoList;
    if (sc.property("data").isArray())
    {

        AdjustPriceOrderInfo orderInfo;
        QScriptValueIterator it(sc.property("data"));
        while (it.hasNext())
        {
            it.next();
            orderInfo.nOrderId = it.value().property("order_id").toInt32(); // 单号id
            if (orderInfo.nOrderId <= 0)
            {
                continue;
            }
            orderInfo.sOrderNum = it.value().property("order_code").toString(); // 单号
            orderInfo.sMaker = it.value().property("creator_name").toString(); // 制单人
            orderInfo.sChecker = it.value().property("confirmor_name").toString(); // 审核人
            orderInfo.sMakeTime = it.value().property("created_at").toString(); // 制单时间
            orderInfo.sEffectTime = it.value().property("effect_date").toString(); // 生效时间
            orderInfo.nState = it.value().property("confirmed").toInt32(); // 状态
            orderInfoList.append(orderInfo);
        }
    }
    HttpSignal::instance()->sigOnGetAdjustPriceOrderList(nCode, sMsg, orderInfoList);
    this->deleteLater();
}

void HttpGetAdjustPriceOrderList::processError()
{
    QList<AdjustPriceOrderInfo> orderInfoList;
    HttpSignal::instance()->sigOnGetAdjustPriceOrderList(e_connectServerError, c_sNetError, orderInfoList);
    this->deleteLater();
}

