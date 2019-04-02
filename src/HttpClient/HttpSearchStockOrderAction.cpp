#include "HttpSearchStockOrder.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpSearchStockOrder::HttpSearchStockOrder(QString sToken, QString sUUID, QString sCorpID, int nOrderId, int searchType)
{
    m_nSearchType = searchType;
    m_nOrderId = nOrderId;

    QString userParam = QString("&access_token=%1&hq_code=%2&order_id=%3&uuid=%4")
            .arg(sToken).arg(sCorpID).arg(nOrderId).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sSearchStockOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpSearchStockOrder::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSearchStockOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<StockOrderSearchInfo> searchInfoList;
    if (sc.property("data").isArray())
    {
        StockOrderSearchInfo searchInfo;
        QScriptValueIterator it(sc.property("data"));

        while (it.hasNext())
        {
            it.next();
            searchInfo.nId = it.value().property("product_id").toInt32(); // 商品id
            if (searchInfo.nId <= 0)
            {
                continue;
            }
            searchInfo.sName = it.value().property("product_name").toString(); // 商品名称
            searchInfo.sCode = it.value().property("product_code").toString(); // 商品编码
            searchInfo.sBelongCategory = it.value().property("product_cate_name").toString(); // 所属分类
            searchInfo.sBarCode = it.value().property("product_base_code").toString(); // 商品条码/plu码
            searchInfo.sShortName = it.value().property("aka").toString(); // 商品简称
            searchInfo.sPinYinName = it.value().property("mnemonic_pinyin").toString(); // 拼音助记码
            searchInfo.sWuBiName = it.value().property("mnemonic_wubi").toString(); // 五笔助记码
            searchInfo.sWeighUnit = it.value().property("sales_unit").toString(); // 称重单位
            searchInfo.fShouldStockNum = it.value().property("book_inventory_num").toString().toFloat(); // 账盘数量
            searchInfo.fRealStockNum = it.value().property("actual_inventory_num").toString().toFloat(); // 实盘数量
            searchInfo.fStockDifferNum = it.value().property("diff_inventory_num").toString().toFloat(); // 差异数量
            searchInfo.fBuyDifferPrice = it.value().property("diff_pur_price").toString().toFloat(); // 进价差异金额
            searchInfo.nBatchId = it.value().property("batch_id").toInt32(); // 最新批次ID
            searchInfo.fBatchPrice = it.value().property("batch_price").toString().toFloat(); //最新批次进价
            searchInfoList.append(searchInfo);
        }
    }
    if (m_nSearchType == e_searchStockForSearch)
    {
        HttpSignal::instance()->sigOnSearchStockOrder(nCode, sMsg, searchInfoList);
    }
    else if (m_nSearchType == e_searchStockForEdit)
    {
        HttpSignal::instance()->sigOnEditStockOrder(nCode, sMsg, searchInfoList, m_nOrderId);
    }
    else if (m_nSearchType == e_searchStockForPrint)
    {
        HttpSignal::instance()->sigOnPrintStockOrder(nCode, sMsg, searchInfoList, m_nOrderId);
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSearchStockOrder 类型填写不明确"));
    }

    this->deleteLater();
}

void HttpSearchStockOrder::processError()
{
    QList<StockOrderSearchInfo> searchInfoList;
    if (m_nSearchType == e_searchStockForSearch)
    {
        HttpSignal::instance()->sigOnSearchStockOrder(e_connectServerError, c_sNetError, searchInfoList);
    }
    else if (m_nSearchType == e_searchStockForEdit)
    {
        HttpSignal::instance()->sigOnEditStockOrder(e_connectServerError, c_sNetError, searchInfoList, m_nOrderId);
    }
    else if (m_nSearchType == e_searchStockForPrint)
    {
        HttpSignal::instance()->sigOnPrintStockOrder(e_connectServerError, c_sNetError, searchInfoList, m_nOrderId);
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSearchStockOrder 类型填写不明确"));
    }
    this->deleteLater();
}

