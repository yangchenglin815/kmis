#include "HttpGetReceiveGoodsDetail.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include <QScriptEngine>

HttpGetReceiveGoodsDetail::HttpGetReceiveGoodsDetail(QString sToken, int nDeliveryGoodId)
{
    m_nDeliveryGoodId = nDeliveryGoodId;

    QString userParam = QString("&access_token=%1&delivery_content_id=%2").arg(sToken).arg(nDeliveryGoodId);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetReceiveGoodsDetailAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetReceiveGoodsDetail::processResponse(QString strResult)
{

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetReceiveGoodsDetail 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    ReceiveGoodsDetail_s receiveGoodsDetail;
    receiveGoodsDetail.bStandardGoods = sc.property("data").property("is_standard").toBool(); // 是否标品
    if (receiveGoodsDetail.bStandardGoods)
    {
        receiveGoodsDetail.standardInfo.fStandardWeight = sc.property("data").property("suttle_spec").toString().toFloat(); // 规格
        receiveGoodsDetail.standardInfo.nReceiveNum = sc.property("data").property("b_package").toInt32(); // 采购件数
        receiveGoodsDetail.standardInfo.fReciveSumValue = sc.property("data").property("b_quantity").toString().toFloat(); // 采购数量
        receiveGoodsDetail.standardInfo.fPrice = sc.property("data").property("unit_price").toString().toFloat(); // 单价
    }
    else
    {
        receiveGoodsDetail.bFixWeight = (sc.property("data").property("weight_ascertainable").toInt32() == 1); // 重量是否固定
        receiveGoodsDetail.bDisperseWeight = (sc.property("data").property("type").toInt32() == 2); // 是否散斤称重
        if (receiveGoodsDetail.bDisperseWeight)
        {
            receiveGoodsDetail.disperseInfo.fPrice = sc.property("data").property("unit_price").toString().toFloat(); // 单价
            receiveGoodsDetail.disperseInfo.fReciveSumValue = sc.property("data").property("b_quantity").toString().toFloat(); // 实采数量

        }
        else
        {
            receiveGoodsDetail.noStandardInfo.fAllWeidght = sc.property("data").property("gross_weight").toString().toFloat(); // 毛重
            receiveGoodsDetail.noStandardInfo.fPeelWeight = sc.property("data").property("unit_tare").toString().toFloat(); // 皮重
            receiveGoodsDetail.noStandardInfo.nReceiveNum = sc.property("data").property("b_package").toInt32(); // 采购件数
            receiveGoodsDetail.noStandardInfo.fPrice = sc.property("data").property("unit_price").toString().toFloat(); // 单价
        }
    }

    HttpSignal::instance()->sigOnGetReceiveGoodsDetail(nCode, sMsg, receiveGoodsDetail, m_nDeliveryGoodId);

    this->deleteLater();
}

void HttpGetReceiveGoodsDetail::processError()
{

    this->deleteLater();
}

