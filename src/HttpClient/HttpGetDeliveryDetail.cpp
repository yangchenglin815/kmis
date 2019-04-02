#include "HttpGetDeliveryDetail.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetDeliveryDetail::HttpGetDeliveryDetail(QString sToken, int nDeliveryId)
{
    m_nDeliveryId = nDeliveryId;

    QString userParam = QString("&access_token=%1&delivery_order_id=%2").arg(sToken).arg(nDeliveryId);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetDeliveryDetailAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetDeliveryDetail::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetDeliveryDetail 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<DeliveryOrderDetailInfo_s> deliveryOrderDetailInfoList;
    DeliveryOrderDetailInfo_s deliveryOrderDetailInfo;
    if (sc.property("data").isArray())
    {
        QScriptValueIterator it(sc.property("data"));
        while (it.hasNext())
        {
            it.next();
            deliveryOrderDetailInfo.nId = it.value().property("delivery_content_id").toInt32(); // 送货单商品id
            if (deliveryOrderDetailInfo.nId == 0)
            {
                continue;
            }
            deliveryOrderDetailInfo.nGoodsId = it.value().property("product_id").toInt32(); // 商品id
            deliveryOrderDetailInfo.sGoodName = it.value().property("product_name").toString(); // 商品名称
            deliveryOrderDetailInfo.sGoodsCode = it.value().property("product_code").toString(); // 商品编号
            deliveryOrderDetailInfo.sUnitSpecification = it.value().property("spe_unit").toString(); // 规格单位  (如4公斤)
            deliveryOrderDetailInfo.fUnitSpecificationValue = it.value().property("purchase_spec").toString().toFloat(); // 规格单位值  (4 -- 4公斤重的4)
            deliveryOrderDetailInfo.nNeedReceiveSumNum = it.value().property("default_package").toInt32(); // 应收件数
            deliveryOrderDetailInfo.fNeedReceiveSumValue = it.value().property("default_quantity").toString().toFloat(); // 应收数量
            deliveryOrderDetailInfo.nRealReceiveSumNum = it.value().property("b_package").toInt32(); // 实收件数
            deliveryOrderDetailInfo.fRealReceiveSumValue = it.value().property("b_quantity").toString().toFloat(); // 实收数量
            deliveryOrderDetailInfo.fSumPrice = it.value().property("amount").toString().toFloat(); // 收货金额
            deliveryOrderDetailInfo.nRecieveGoodsState = it.value().property("product_id").toInt32(); // 收货商品状态
            deliveryOrderDetailInfoList.append(deliveryOrderDetailInfo);
        }
    }

    HttpSignal::instance()->sigOnGetDeliveryDetail(nCode, sMsg, deliveryOrderDetailInfoList, m_nDeliveryId);
    this->deleteLater();
}

void HttpGetDeliveryDetail::processError()
{
    QList<DeliveryOrderDetailInfo_s> deliveryOrderDetailInfoList;
    HttpSignal::instance()->sigOnGetDeliveryDetail(e_connectServerError, c_sNetError, deliveryOrderDetailInfoList, m_nDeliveryId);
    this->deleteLater();
}

