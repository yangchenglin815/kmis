#include "HttpGetAllGoodsPrice.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include "../data/httpstructdata.h"
#include "../data/enumData.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetAllGoodsPrice::HttpGetAllGoodsPrice(QString sUUID, QString sToken, QString sCorpID, QString sLastTime)
{
    QString userParam = QString("&access_token=%1&hq_code=%2&uuid=%3").arg(sToken).arg(sCorpID).arg(sUUID);
    if (!sLastTime.isEmpty())
    {
        userParam.append(QString("&last_download_time=%1").arg(sLastTime));
    }

    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetAllGoodsPriceAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetAllGoodsPrice::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetAllGoodsPrice 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    bool bPriceError = false;

    QString sUpdateTime = sc.property("date").toString();

    QMap<QString, GoodsPriceInfo_s> goodsPriceInfoMap;  
    if (sc.property("data").property("product_data").isValid())
    {
        if (sc.property("data").property("product_data").isArray())
        {
            QScriptValueIterator it(sc.property("data").property("product_data"));
            GoodsPriceInfo_s goodsPriceInfo;
            while (it.hasNext())
            {
                it.next();
                QString sBarCode = it.value().property("product_bar_code").toString();
                if (sBarCode.isEmpty())
                {
                    continue;
                }
                goodsPriceInfo.fPrice = it.value().property("price").toString().toFloat();//商品价格
                if (goodsPriceInfo.fPrice < 0.00001f)
                {
                    bPriceError = true;
                }
                goodsPriceInfo.fMemberPrice = it.value().property("vip_price").toString().toFloat(); // 会员价
                goodsPriceInfo.sUpdateTime = it.value().property("created_at").toString(); // 价格更新时间

                goodsPriceInfoMap.insert(sBarCode, goodsPriceInfo);
            }
        }
        if ((nCode == e_success) && (goodsPriceInfoMap.count() == 0))
        {
            KPosLog::instance()->writeErrorLog(this->getTestUrl());
            KPosLog::instance()->writeErrorLog(strResult);
        }
    }
    else if (sc.property("data").property("product_add_data").isValid())
    {
        if (sc.property("data").property("product_add_data").isArray())
        {
            QScriptValueIterator it(sc.property("data").property("product_data"));
            GoodsPriceInfo_s goodsPriceInfo;
            while (it.hasNext())
            {
                it.next();
                QString sBarCode = it.value().property("product_bar_code").toString();
                if (sBarCode.isEmpty())
                {
                    continue;
                }
                goodsPriceInfo.fPrice = it.value().property("price").toString().toFloat();//商品价格
                if (goodsPriceInfo.fPrice < 0.00001f)
                {
                    bPriceError = true;
                }
                goodsPriceInfo.fMemberPrice = it.value().property("vip_price").toString().toFloat(); // 会员价
                goodsPriceInfo.sUpdateTime = it.value().property("created_at").toString(); // 价格更新时间

                goodsPriceInfoMap.insert(sBarCode, goodsPriceInfo);
            }
        }
    }

    if (goodsPriceInfoMap.size() > 0)
    {
        KPosLog::instance()->writeTestLog(QStringLiteral("商品价格有变化"));
        KPosLog::instance()->writeTestLog(this->getTestUrl());
        KPosLog::instance()->writeTestLog(strResult);
    }
    if (bPriceError)
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("价格有异常:").arg(this->getTestUrl()));
        KPosLog::instance()->writeErrorLog(strResult);
    }

    HttpSignal::instance()->sigOnGetAllGoodsPrice(nCode, sMsg, goodsPriceInfoMap, sUpdateTime);

    this->deleteLater();
}

void HttpGetAllGoodsPrice::processError()
{
    QMap<QString, GoodsPriceInfo_s> goodsPriceInfoMap;
    HttpSignal::instance()->sigOnGetAllGoodsPrice(e_connectServerError, c_sNetError, goodsPriceInfoMap, "");
    this->deleteLater();
}

