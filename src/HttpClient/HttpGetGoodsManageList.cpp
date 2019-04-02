#include "HttpGetGoodsManageList.h"
#include <QScriptEngine>
#include <QScriptValueIterator>
#include "goodsmanagedata.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"

HttpGetGoodsManageList::HttpGetGoodsManageList(QString sToken, int nShopID, QString sCorpID, QString searchPattern, int nLimit, int nOffset, const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId, QString sUUID)
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

    QString systemParam = CommonFun::generateSystemParams(c_sGetGoodsManageOrderListAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetGoodsManageList::processResponse(QString strResult)
{
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

    QList<sGoodsInfo_s> orderGoodsInfoList;
    sGoodsInfo_s orderGoodsInfo;
    if (sc.property("data").isArray())
    {
        QScriptValueIterator it(sc.property("data"));
        while (it.hasNext())
        {
            it.next();
            orderGoodsInfo.nId = it.value().property("cid").toInt32();
            orderGoodsInfo.sCode = it.value().property("product_code").toString(); //商品编码
            if(orderGoodsInfo.sCode.isEmpty()){
                continue;
            }
            orderGoodsInfo.nCategoryId = m_nCategoryBigId;
            orderGoodsInfo.sCodeId = it.value().property("product_base_code").toString(); //商品条码
            orderGoodsInfo.sName = it.value().property("product_name").toString(); //商品名称
            orderGoodsInfo.sUnitSpecification = it.value().property("sales_unit").toString(); //销售单位
            orderGoodsInfo.sStockNumber = it.value().property("stock_qty").toString().toFloat(); //库存数量
            orderGoodsInfo.category = it.value().property("weight_type").toInt32(); //称重类型
            orderGoodsInfo.fPrice = it.value().property("price").toString().toFloat(); //原价
            orderGoodsInfo.vPrice = it.value().property("vip_price").toString().toFloat(); //会员价
            orderGoodsInfoList.append(orderGoodsInfo);
        }
    }

    HttpSignal::instance()->sigOnGetGoodsManageGoodsList(nCode, sMsg, orderGoodsInfoList, m_nCategoryBigId);

    this->deleteLater();
}

void HttpGetGoodsManageList::processError()
{
    QList<sGoodsInfo_s> orderGoodsInfoList;
    HttpSignal::instance()->sigOnGetGoodsManageGoodsList(e_connectServerError, c_sNetError, orderGoodsInfoList, m_nCategoryBigId);
    this->deleteLater();
}

QString HttpGetGoodsManageList::createCategoryIdListJson(const QList<int> &categoryIdList)
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

