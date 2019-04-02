#include "HttpSearchOutStockOrder.h"

#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpSearchOutStockOrder::HttpSearchOutStockOrder(QString sToken,QString sCorpID, QString sUUid, int nOrderId, int searchType)
{
    m_nSearchType = searchType;
    m_nOrderId = nOrderId;

    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3&order_id=%4").arg(sToken).arg(sCorpID).arg(sUUid).arg(nOrderId);
    QString systemParam = CommonFun::generateSystemParams(c_sInquireOutStockOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpSearchOutStockOrder::processResponse(QString strResult)
{
    //    KPosLog::instance()->writeTestLog(this->getTestUrl());
    //    KPosLog::instance()->writeTestLog(strResult);
    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSearchOutStockOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QString sTotal = sc.property("total_amount").toString(); // 总金额
    QList<OutStockOrderSearchInfo> searchInfoList;
    if (sc.property("data").isArray())
    {
        OutStockOrderSearchInfo searchInfo;
        QScriptValueIterator it(sc.property("data"));

        while (it.hasNext())
        {
            it.next();
            searchInfo.nId = it.value().property("product_id").toInt32(); // 商品id
            if (searchInfo.nId <= 0)
            {
                continue;
            }
            searchInfo.sCode = it.value().property("product_code").toString(); // 商品条码
            searchInfo.sBelongCategory = it.value().property("product_cate_name").toString(); // 所属分类
            searchInfo.sBarCode = it.value().property("product_base_code").toString(); // 商品条码/plu码
            searchInfo.sName = it.value().property("aka").toString(); // 商品简称
            searchInfo.sPinYinName = it.value().property("mnemonic_pinyin").toString(); // 拼音助记码
            searchInfo.sWuBiName = it.value().property("mnemonic_wubi").toString(); // 五笔助记码
            searchInfo.sWeighUnit = it.value().property("spe_unit").toString(); // 要货规格单位
            searchInfo.sSellUnit = it.value().property("sales_unit").toString(); //销售单位
            searchInfo.sSubTotal = it.value().property("stock_amount").toString(); // 小计金额
            searchInfo.sPrice = it.value().property("unit_price").toString(); // 单价
            searchInfo.sCount = it.value().property("stock_quantity").toString(); // 数量
            searchInfo.fPackage = it.value().property("stock_package").toString().toFloat(); //件数
            searchInfo.isEdited=false;//还没编辑过的状态
            searchInfo.fBatchPrice=CommonFun::StringToFloat(searchInfo.sPrice);
            searchInfo.sBoxNum=CommonFun::floatToString(searchInfo.fPackage);
            searchInfo.fShouldCount=CommonFun::StringToFloat(searchInfo.sCount);
            searchInfo.fShouldTotal=CommonFun::StringToFloat(searchInfo.sSubTotal);
            searchInfoList.append(searchInfo);
        }
    }
    if (m_nSearchType == e_searchStockForSearch)
    {
        HttpSignal::instance()->sigOnSearchOutStockOrder(nCode, sMsg,sTotal,searchInfoList);
    }
    else if (m_nSearchType == e_searchStockForEdit)
    {
        HttpSignal::instance()->sigOnEditOutStockOrder(nCode, sMsg,searchInfoList, m_nOrderId);
    }
    else if (m_nSearchType == e_searchStockForPrint)
    {
        HttpSignal::instance()->sigOnPrintOutStockOrder(nCode, sMsg, searchInfoList, m_nOrderId);
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSearchOutStockOrder 类型填写不明确"));
    }

    this->deleteLater();
}

void HttpSearchOutStockOrder::processError()
{
    QList<OutStockOrderSearchInfo> searchInfoList;
    if (m_nSearchType == e_searchStockForSearch)
    {
        HttpSignal::instance()->sigOnSearchOutStockOrder(e_connectServerError, c_sNetError,"", searchInfoList);
    }
    else if (m_nSearchType == e_searchStockForEdit)
    {
        HttpSignal::instance()->sigOnEditOutStockOrder(e_connectServerError, c_sNetError, searchInfoList, m_nOrderId);
    }
    else if (m_nSearchType == e_searchStockForPrint)
    {
        HttpSignal::instance()->sigOnPrintOutStockOrder(e_connectServerError, c_sNetError, searchInfoList, m_nOrderId);
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSearchOutStockOrder 类型填写不明确"));
    }
    this->deleteLater();
}


