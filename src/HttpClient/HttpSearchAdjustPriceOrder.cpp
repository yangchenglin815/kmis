#include "HttpSearchAdjustPriceOrder.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpSearchAdjustPriceOrder::HttpSearchAdjustPriceOrder(QString sToken, QString sCorpID, QString sUUID,
                                                       int nOrderId, int searchType)
{
    m_nSearchType = searchType;
    m_nOrderId = nOrderId;

    QString userParam = QString("&access_token=%1&hq_code=%2&order_id=%3&uuid=%4")
            .arg(sToken).arg(sCorpID).arg(nOrderId).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sSearchAdjustPriceOrderAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpSearchAdjustPriceOrder::processResponse(QString strResult)
{
    //    KPosLog::instance()->writeTestLog(this->getTestUrl());
    //    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSearchAdjustPriceOrder 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<AdjustPriceOrderSearchInfo> searchInfoList;
    if (sc.property("data").isArray())
    {    
        AdjustPriceOrderSearchInfo searchInfo;
        QScriptValueIterator it(sc.property("data"));
        //int i = 1;
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
            searchInfo.sBarCode = it.value().property("product_base_code").toString(); // 商品条码/plu码
            searchInfo.sShortName = it.value().property("aka").toString(); // 商品简称
            searchInfo.sPinYinName = it.value().property("mnemonic_pinyin").toString(); // 拼音助记码
            searchInfo.sWuBiName = it.value().property("mnemonic_wubi").toString(); // 五笔助记码
            searchInfo.sWeighUnit = it.value().property("sales_unit").toString(); // 称重单位
            searchInfo.fOldPrice = it.value().property("original_price").toString().toFloat(); // 原售价
            searchInfo.fNowPrice = it.value().property("current_price").toString().toFloat(); // 现售价
            searchInfo.fOldMemberPrice = it.value().property("original_member_price").toString().toFloat(); // 原会员价
            searchInfo.fNowMemberPrice = it.value().property("current_member_price").toString().toFloat(); // 现会员价
            searchInfoList.append(searchInfo);
        }
    }
    if (m_nSearchType == e_searchAdjustForSearch)
    {
        HttpSignal::instance()->sigOnSearchAdjustPriceOrder(nCode, sMsg, searchInfoList);
    }
    else if (m_nSearchType == e_searchAdjustForEdit)
    {
        HttpSignal::instance()->sigOnEditAdjustPriceOrder(nCode, sMsg, searchInfoList, m_nOrderId);
    }
    else
    {
        HttpSignal::instance()->sigOnPrintAdjustPriceOrder(nCode, sMsg, searchInfoList, m_nOrderId);
    }

    this->deleteLater();
}

void HttpSearchAdjustPriceOrder::processError()
{
    QList<AdjustPriceOrderSearchInfo> searchInfoList;
    if (m_nSearchType == e_searchAdjustForSearch)
    {
        HttpSignal::instance()->sigOnSearchAdjustPriceOrder(e_connectServerError, c_sNetError, searchInfoList);
    }
    else if (m_nSearchType == e_searchAdjustForEdit)
    {
        HttpSignal::instance()->sigOnEditAdjustPriceOrder(e_connectServerError, c_sNetError, searchInfoList, m_nOrderId);
    }
    else
    {
        HttpSignal::instance()->sigOnPrintAdjustPriceOrder(e_connectServerError, c_sNetError, searchInfoList, m_nOrderId);
    }

    this->deleteLater();
}

