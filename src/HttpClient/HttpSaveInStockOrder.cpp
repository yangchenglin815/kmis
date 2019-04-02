#include "HttpSaveInStockOrder.h"

#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpSaveInStockOrder::HttpSaveInStockOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId
                                           , const QList<InStockSelectGoodsInfo> &selectGoodsList)
{
    QString goodsListJson = createGoodsListJson(selectGoodsList);
    QString systemParam;
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&product_lists=%4").arg(sToken).arg(sCorpID).arg(sUUID).arg(goodsListJson);
    if (nOrderId > 0)
    {//有订单ID则视为编辑，否则为新建
        userParam.append(QString("&order_id=%1").arg(nOrderId));
        systemParam = CommonFun::generateSystemParams(c_sEditInStockOrderAction);
    }else
        systemParam = CommonFun::generateSystemParams(c_sAddInStockOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array="";
    array.append(allParam);
    setReqParams(array);
}

void HttpSaveInStockOrder::processResponse(QString strResult)
{
    //    KPosLog::instance()->writeTestLog(this->getTestUrl());
    //    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSaveInStockOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnSaveInStockOrder(nCode, sMsg);
    this->deleteLater();
}

void HttpSaveInStockOrder::processError()
{
    HttpSignal::instance()->sigOnSaveInStockOrder(e_connectServerError, c_sNetError);
    this->deleteLater();
}

QString HttpSaveInStockOrder::createGoodsListJson(const QList<InStockSelectGoodsInfo> &selectGoodsList)
{
    QJsonArray jsonArray;
    int nLen = selectGoodsList.length();
    InStockSelectGoodsInfo goodsInfo;
    for (int i = 0; i < nLen; i++)
    {
        goodsInfo = selectGoodsList[i];
        QJsonObject dataJson;
        dataJson.insert("product_id", goodsInfo.nId); // 商品ID
        dataJson.insert("price", CommonFun::floatToString(goodsInfo.fBatchPrice)); // 账盘数量
        dataJson.insert("quantity", CommonFun::floatToString(goodsInfo.fShouldCount));// 实盘数量
        dataJson.insert("package", CommonFun::floatToString(goodsInfo.fPackage));// 最新批次进价
        dataJson.insert("amount", CommonFun::floatToString(goodsInfo.fShouldTotal));// 最新小计金额
        dataJson.insert("spec_num", CommonFun::floatToString(goodsInfo.fMarkNum));// 最新小计金额`
        jsonArray.insert(i, dataJson);
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString byte_str=QString::fromUtf8(byte_array);
    KPosLog::instance()->writeErrorLog("原始参数："+byte_str);

    return byte_str;
}



