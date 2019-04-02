#include "HttpGetOrderGoods.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/enumData.h"
#include "../data/ordergoodsdata.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetOrderGoods::HttpGetOrderGoods(QString sToken, int nShopID, QString sCorpID, QString searchPattern, int nLimit, int nOffset,
                                     const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId,QString sUUID)
{
    m_nCategoryBigId = nCategoryBigId;

    QString categoryIdListJson = createCategoryIdListJson(categoryIdList);

    QString userParam = QString("&access_token=%1&orgz_id=%2&hq_code=%3&category_lists=%4&sorted_by=%5&sort=%6&uuid=%7")
            .arg(sToken).arg(nShopID).arg(sCorpID).arg(categoryIdListJson).arg(sSortBy).arg(sSort).arg(sUUID);
    if (!searchPattern.isEmpty())
    {
        userParam.append(QString("search_pattern=%1").arg(searchPattern));
    }
    if ((nLimit > 0) && (nOffset > 0))
    {
        userParam.append(QString("&limit=%1&offset=%2").arg(nLimit).arg(nOffset));
    }

    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetOrderGoodsAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetOrderGoods::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetOrderGoods 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<OrderGoodsInfo_s> orderGoodsInfoList;
    OrderGoodsInfo_s orderGoodsInfo;
    if (sc.property("data").isArray())
    {
        QScriptValueIterator it(sc.property("data"));
        while (it.hasNext())
        {
            it.next();
            orderGoodsInfo.nId = it.value().property("product_id").toInt32();// 商品id
            if (orderGoodsInfo.nId == 0)
            {
                continue;
            }
            orderGoodsInfo.nCategoryId = it.value().property("cid").toInt32();// 所属分类
            orderGoodsInfo.sName = it.value().property("product_name").toString();// 商品名称
            orderGoodsInfo.sCode = it.value().property("product_bar_code").toString(); // 商品编码
            orderGoodsInfo.sStockNumber = it.value().property("stock_qty").toString();// 库存数量
            orderGoodsInfo.fUnitSpecificationValue = it.value().property("purchase_spec").toString().toFloat(); // 要货规格
            orderGoodsInfo.sUnitSpecification = it.value().property("spe_unit").toString(); // 规格单位
            orderGoodsInfo.nSaleNumberToday = it.value().property("req_num").toInt32(); // 当日已定
            orderGoodsInfo.fPrice = it.value().property("price").toString().toFloat(); // 单件单价
            orderGoodsInfo.sSaleNumberYesterday = it.value().property("yesterday_sale_qty").toString(); // 上日销售数量
            orderGoodsInfo.sSaleNumberLastweek = it.value().property("lastweek_sale_qty").toString(); // 上周销售数量
            orderGoodsInfo.nOrderSaleRate = it.value().property("dx_rate").toInt32(); // 订销差率
            orderGoodsInfo.sSuggestOrderNumber = it.value().property("suggest_package").toString(); // 建议要货件数
            orderGoodsInfoList.append(orderGoodsInfo);
        }
    }

    HttpSignal::instance()->sigOnGetOrderGoods(nCode, sMsg, orderGoodsInfoList, m_nCategoryBigId);

    this->deleteLater();
}

void HttpGetOrderGoods::processError()
{
    QList<OrderGoodsInfo_s> orderGoodsInfoList;
    HttpSignal::instance()->sigOnGetOrderGoods(e_connectServerError, c_sNetError, orderGoodsInfoList, m_nCategoryBigId);
    this->deleteLater();
}

QString HttpGetOrderGoods::createCategoryIdListJson(const QList<int> &categoryIdList)
{
    QJsonArray jsonArray;
    int nLen = categoryIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        QJsonObject dataJson;
        dataJson.insert("category_id", categoryIdList[i]);
        jsonArray.insert(i, dataJson); //
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

