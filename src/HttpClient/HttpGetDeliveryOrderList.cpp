#include "HttpGetDeliveryOrderList.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/enumData.h"
#include "../data/recievinggoodsdata.h"
#include <QScriptEngine>
#include <QScriptValueIterator>
#include <QDateTime>

HttpGetDeliveryOrderList::HttpGetDeliveryOrderList(QString sToken, int nShopID, int nLimit, int nOffset, int nProviderId, QString sOrderCode
                                                   , QString sOrderType, int nOrderStatus, QString sStartDate, QString sEndDate)
{
    QString userParam = QString("&access_token=%1&orgz_id=%2&limit=%3&offset=%4").arg(sToken).arg(nShopID).arg(nLimit).arg(nOffset);
    if (nProviderId > 0)
    {
        userParam.append(QString("&supplier_id=%1").arg(nProviderId));
    }
    if (!sOrderCode.isEmpty())
    {
        userParam.append(QString("&order_code=%1").arg(sOrderCode));
    }
    if (!sOrderType.isEmpty())
    {
        userParam.append(QString("&order_genre=%1").arg(sOrderType));
    }
    if (nOrderStatus >= 0)
    {
        userParam.append(QString("&order_status=%1").arg(nOrderStatus));
    }
    if ((!sStartDate.isEmpty()) && (!sEndDate.isEmpty()))
    {
        userParam.append(QString("&start_date=%1&end_date=%2").arg(sStartDate).arg(sEndDate));
    }

    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetDeliveryOrderListAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetDeliveryOrderList::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetDeliveryOrderList 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<DeliveryOrderInfo_s> deliveryOrderInfoList;
    DeliveryOrderInfo_s deliveryOrderInfo;
    if (sc.property("data").isArray())
    {
        QScriptValueIterator it(sc.property("data"));
        while (it.hasNext())
        {
            it.next();
            deliveryOrderInfo.nId = it.value().property("order_id").toInt32(); // 送货单id
            if (deliveryOrderInfo.nId == 0)
            {
                continue;
            }
            deliveryOrderInfo.sCode = it.value().property("order_code").toString(); // 送货单编号
            deliveryOrderInfo.nOrderType = it.value().property("order_genre").toInt32(); // 订单类型
            deliveryOrderInfo.sProviderName = it.value().property("supplier_name").toString(); // 提供商名称
            deliveryOrderInfo.sProviderCode = it.value().property("supplier_num").toString(); // 提供商编号
            deliveryOrderInfo.nNeedReceiveSumNum = it.value().property("default_package").toInt32(); // 应收件数
            deliveryOrderInfo.fNeedReceiveSumValue = it.value().property("default_quantity").toString().toFloat(); // 应收数量
            deliveryOrderInfo.nRealReceiveSumNum = it.value().property("b_package").toInt32(); // 实收件数
            deliveryOrderInfo.fRealReceiveSumValue = it.value().property("b_quantity").toString().toFloat(); // 实收数量
            deliveryOrderInfo.fSumPrice = it.value().property("amount").toString().toFloat(); // 金额
            QString sDatetime = it.value().property("created_at").toString();
            QDateTime dateTime = QDateTime::fromString(sDatetime, "yyyy-MM-dd HH:mm:ss"); // 创建日期
            deliveryOrderInfo.sUploadDate = dateTime.date().toString("yyyy-MM-dd"); // 上传日期
            deliveryOrderInfo.sUploadTime = QString("%1:%2").arg(dateTime.time().hour()).arg(dateTime.time().minute()); // 上传时间
            deliveryOrderInfo.nRecieveState = it.value().property("delivery_content_state").toInt32(); // 收货状态 (已完成，收货中，未完成)
            deliveryOrderInfoList.append(deliveryOrderInfo);
        }
    }

    HttpSignal::instance()->sigOnGetDeliveryOrderList(nCode, sMsg, deliveryOrderInfoList);

    this->deleteLater();
}

void HttpGetDeliveryOrderList::processError()
{
    QList<DeliveryOrderInfo_s> deliveryOrderInfoList;
    HttpSignal::instance()->sigOnGetDeliveryOrderList(e_connectServerError, c_sNetError, deliveryOrderInfoList);
    this->deleteLater();
}

