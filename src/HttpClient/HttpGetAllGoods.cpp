#include "HttpGetAllGoods.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../util/KPosLog.h"
#include "../data/httpstructdata.h"
#include "../data/enumData.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetAllGoods::HttpGetAllGoods(QString sToken, QString sUUID, QString sCorpID, QString sLastTime)
{
    QString userParam = QString("&uuid=%1&hq_code=%2&access_token=%3").arg(sUUID).arg(sCorpID).arg(sToken);
    if (!sLastTime.isEmpty())
    {
        userParam.append(QString("&last_update_time=%1").arg(sLastTime));
    }

    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetAllGoodsAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetAllGoods::processResponse(QString strResult)
{
//    KPosLog::instance()->writeTestLog(this->getTestUrl());
//    KPosLog::instance()->writeTestLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    QString sUpdateTime = sc.property("update_time").toString();

    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetAllGoods 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
        QMap<QString, GoodsInfo_s> goodsInfoMap;
        HttpSignal::instance()->sigOnGetAllGoods(e_connectServerError, c_sNetError, goodsInfoMap, "");
        this->deleteLater();
        return;
    }

    if (sc.property("data").property("full_update").isValid())
    {
        if (sc.property("data").property("full_update").isArray())
        {
            QMap<QString, GoodsInfo_s> goodsInfoMap;
            QScriptValueIterator it(sc.property("data").property("full_update"));
            GoodsInfo_s goodsInfo;
            while (it.hasNext())
            {
                it.next();
                goodsInfo.nId = it.value().property("product_id").toInt32();//商品id
                if (goodsInfo.nId == 0)
                {
                    continue;
                }
                goodsInfo.sCode = it.value().property("product_code").toString();//商品编码id
                goodsInfo.sBarCode = it.value().property("product_bar_code").toString();//商品条码（唯一主键）
                goodsInfo.sName = it.value().property("product_name").toString();//商品名称
                goodsInfo.sShortName = it.value().property("aka").toString();//商品简称
                goodsInfo.sPinYinName = it.value().property("mnemonic_pinyin").toString(); // 拼音助记码
                goodsInfo.sWuBiName = it.value().property("mnemonic_wubi").toString(); // 五笔助记码
                goodsInfo.sPluCode = it.value().property("plu_code").toString(); // plu码
                goodsInfo.sPluName = it.value().property("product_plu_name").toString(); // 商品Plu名称
                goodsInfo.nPluGrade = it.value().property("plu_grade").toInt32(); // 商品plu等级
                goodsInfo.bStandard = (it.value().property("is_standard").toInt32() == 1);//是否标品
                goodsInfo.sSaleUnit = it.value().property("sale_unit").toString();//销售单位： 元/公斤
                goodsInfo.sSpeUnit = it.value().property("spe_unit").toString();//要货单位： 50个/卷
                goodsInfo.sCategoryName = it.value().property("category_name").toString();//大类： 蔬菜
                goodsInfo.fMarkNum= it.value().property("order_spec_num").toNumber();//量比系数
                // 商品价格从另外的接口再获取
                goodsInfo.goodsPriceInfo.fPrice = 0.0f;//商品价格
                goodsInfo.goodsPriceInfo.fMemberPrice = 0.0f; // 会员价

                goodsInfoMap.insert(goodsInfo.sBarCode, goodsInfo);
            }
            if (!sUpdateTime.isEmpty() && (nCode == e_success) && (goodsInfoMap.count() == 0))
            {
                KPosLog::instance()->writeErrorLog(this->getTestUrl());
                KPosLog::instance()->writeErrorLog(strResult);
            }
            HttpSignal::instance()->sigOnGetAllGoods(nCode, sMsg, goodsInfoMap, sUpdateTime);
        }
    }
    else
    {
        // 增加的
        QMap<QString, GoodsInfo_s> goodsInfoCreateMap;
        if (sc.property("data").property("create_list").isValid())
        {
            if (sc.property("data").property("create_list").isArray())
            {
                QScriptValueIterator it(sc.property("data").property("create_list"));
                GoodsInfo_s goodsInfo;
                while (it.hasNext())
                {
                    it.next();
                    goodsInfo.nId = it.value().property("product_id").toInt32();//商品id
                    if (goodsInfo.nId == 0)
                    {
                        continue;
                    }
                    goodsInfo.sCode = it.value().property("product_code").toString();//商品编码id
                    goodsInfo.sBarCode = it.value().property("product_bar_code").toString();//商品条码（唯一主键）
                    goodsInfo.sName = it.value().property("product_name").toString();//商品名称
                    goodsInfo.sShortName = it.value().property("aka").toString();//商品简称
                    goodsInfo.sPinYinName = it.value().property("mnemonic_pinyin").toString(); // 拼音助记码
                    goodsInfo.sWuBiName = it.value().property("mnemonic_wubi").toString(); // 五笔助记码
                    goodsInfo.sPluCode = it.value().property("plu_code").toString(); // plu码
                    goodsInfo.sPluName = it.value().property("product_plu_name").toString(); // 商品Plu名称
                    goodsInfo.nPluGrade = it.value().property("plu_grade").toInt32(); // 商品plu等级
                    goodsInfo.bStandard = (it.value().property("is_standard").toInt32() == 1);//是否标品
                    goodsInfo.sSaleUnit = it.value().property("sale_unit").toString();//销售单位： 元/公斤
                    // 商品价格从另外的接口再获取
                    goodsInfo.goodsPriceInfo.fPrice = 0.0f;//商品价格
                    goodsInfo.goodsPriceInfo.fMemberPrice = 0.0f; // 会员价

                    goodsInfoCreateMap.insert(goodsInfo.sBarCode, goodsInfo);
                }
            }
        }

        // 修改的
        QMap<QString, GoodsInfo_s> goodsInfoUpdateMap;
        if (sc.property("data").property("update_list").isValid())
        {
            if (sc.property("data").property("update_list").isArray())
            {
                QScriptValueIterator it(sc.property("data").property("update_list"));
                GoodsInfo_s goodsInfo;
                while (it.hasNext())
                {
                    it.next();
                    goodsInfo.nId = it.value().property("product_id").toInt32();//商品id
                    if (goodsInfo.nId == 0)
                    {
                        continue;
                    }
                    goodsInfo.sCode = it.value().property("product_code").toString();//商品编码id
                    goodsInfo.sBarCode = it.value().property("product_bar_code").toString();//商品条码（唯一主键）
                    goodsInfo.sName = it.value().property("product_name").toString();//商品名称
                    goodsInfo.sShortName = it.value().property("aka").toString();//商品简称
                    goodsInfo.sPinYinName = it.value().property("mnemonic_pinyin").toString(); // 拼音助记码
                    goodsInfo.sWuBiName = it.value().property("mnemonic_wubi").toString(); // 五笔助记码
                    goodsInfo.sPluCode = it.value().property("plu_code").toString(); // plu码
                    goodsInfo.sPluName = it.value().property("product_plu_name").toString(); // 商品Plu名称
                    goodsInfo.nPluGrade = it.value().property("plu_grade").toInt32(); // 商品plu等级
                    goodsInfo.bStandard = (it.value().property("is_standard").toInt32() == 1);//是否标品
                    goodsInfo.sSaleUnit = it.value().property("sale_unit").toString();//销售单位： 元/公斤
                    goodsInfoUpdateMap.insert(goodsInfo.sBarCode, goodsInfo);
                }
            }
        }

        // 删除的
        QList<QString> goodsInfodeleteList;
        if (sc.property("data").property("delete_list").isValid())
        {
            if (sc.property("data").property("update_list").isArray())
            {
                QScriptValueIterator it(sc.property("data").property("delete_list"));
                while (it.hasNext())
                {
                    it.next();
                    QString sBarCode = it.value().property("product_bar_code").toString();//商品条码（唯一主键）
                    if (sBarCode.isEmpty())
                    {
                        continue;
                    }
                    goodsInfodeleteList.append(sBarCode);
                }
            }
        }

        if ((goodsInfoCreateMap.size() > 0) || (goodsInfoUpdateMap.size() > 0) || (goodsInfodeleteList.size()) > 0)
        {
            if ((goodsInfoCreateMap.size() > 0))
            {
                KPosLog::instance()->writeTestLog(QStringLiteral("商品有增加"));
            }
            if (goodsInfoUpdateMap.size() > 0)
            {
                KPosLog::instance()->writeTestLog(QStringLiteral("商品有修改"));
            }
            if (goodsInfodeleteList.size() > 0)
            {
                KPosLog::instance()->writeTestLog(QStringLiteral("商品有删除"));
            }
            KPosLog::instance()->writeTestLog(this->getTestUrl());
            KPosLog::instance()->writeTestLog(strResult);
        }

        HttpSignal::instance()->sigOnGetChangedGoods(nCode, sMsg, goodsInfoCreateMap, goodsInfoUpdateMap, goodsInfodeleteList, sUpdateTime);    
    }
    this->deleteLater();
}

void HttpGetAllGoods::processError()
{
    QMap<QString, GoodsInfo_s> goodsInfoMap;
    HttpSignal::instance()->sigOnGetAllGoods(e_connectServerError, c_sNetError, goodsInfoMap, "");
    this->deleteLater();
}
