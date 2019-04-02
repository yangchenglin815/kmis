#include "HttpSaveStockOrder.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>

HttpSaveStockOrder::HttpSaveStockOrder(QString sToken, QString sCorpID, QString sUUID, int nOrderId
                                                   , const QList<StockSelectGoodsInfo> &selectGoodsList)
{
    QString goodsListJson = createGoodsListJson(selectGoodsList);
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&product_lists=%4").arg(sToken).arg(sCorpID).arg(sUUID).arg(goodsListJson);
    if (nOrderId > 0)
    {
        userParam.append(QString("&order_id=%1").arg(nOrderId));
    }
    QString systemParam = CommonFun::generateSystemParams(c_sSaveStockOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpSaveStockOrder::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSaveStockOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnSaveStockOrder(nCode, sMsg);
    this->deleteLater();
}

void HttpSaveStockOrder::processError()
{
    HttpSignal::instance()->sigOnSaveStockOrder(e_connectServerError, c_sNetError);
    this->deleteLater();
}

QString HttpSaveStockOrder::createGoodsListJson(const QList<StockSelectGoodsInfo> &selectGoodsList)
{
    QJsonArray jsonArray;
    int nLen = selectGoodsList.length();
    StockSelectGoodsInfo goodsInfo;
    for (int i = 0; i < nLen; i++)
    {
        goodsInfo = selectGoodsList[i];
        QJsonObject dataJson;
        dataJson.insert("product_id", goodsInfo.nId); // 商品ID
        dataJson.insert("book_inventory_num", goodsInfo.fShouldStockNum); // 账盘数量
        dataJson.insert("actual_inventory_num", goodsInfo.fRealStockNum);// 实盘数量
        dataJson.insert("diff_pur_price", goodsInfo.fBuyDifferPrice);// 进价差异额
        dataJson.insert("batch_id", goodsInfo.nBatchId);// 最新批次ID
        dataJson.insert("batch_price", goodsInfo.fBatchPrice);// 最新批次进价
        jsonArray.insert(i, dataJson);
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

