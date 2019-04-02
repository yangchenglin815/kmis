#include "HttpCreateQuickGoods.h"
#include "CommonFun.h"
#include "KPosLog.h"
#include "HttpSignal.h"
#include <QScriptEngine>
#include <QDebug>

HttpCreateQuickGoods::HttpCreateQuickGoods(QString sToken, QString sCorpID, QString sUUID, const ProductInfo &info)
{
    QString goodsJson = createInfoJson(info);
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&product_info=%4")
            .arg(sToken).arg(sCorpID).arg(sUUID).arg(goodsJson);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpCreateQuickGoodsAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpCreateQuickGoods::processResponse(QString strResult)
{
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpCreateQuickGoods 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnCreateQuickGoods(nCode, sMsg);
    this->deleteLater();
}

void HttpCreateQuickGoods::processError()
{
    HttpSignal::instance()->sigOnCreateQuickGoods(e_connectServerError, c_sNetError);
    this->deleteLater();
}

QString HttpCreateQuickGoods::createInfoJson(const ProductInfo &info)
{
    QJsonObject dataJson;
    dataJson.insert("name", info.goodsName); // 商品名
    dataJson.insert("cid", info.cId); // 商品ID
    dataJson.insert("code", info.product_code); // 商品编号
    dataJson.insert("product_base_code", info.product_base_code); // 条码
    dataJson.insert("weight_type", info.weight_type); // 称重类型
    dataJson.insert("min_spec_unit", info.min_spec_unit); // 最小规格单位
    dataJson.insert("order_spec_unit", info.order_spec_unit); // 要货规格单位
    dataJson.insert("order_spec_num", CommonFun::floatToString(info.order_spec_num));// 要货规格值
    dataJson.insert("reference_bid_price", CommonFun::floatToString(info.reference_bid_price)); //参考进价
    dataJson.insert("reference_selling_price", CommonFun::floatToString(info.reference_selling_price));// 售价
    dataJson.insert("member_price", CommonFun::floatToString(info.member_price));// 会员价

    QJsonDocument document;
    document.setObject(dataJson);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString byte_str=QString::fromUtf8(byte_array);

    return byte_str;
}

