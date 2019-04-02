#include "HttpDownloadKPosSet.h"
#include "../util/KPosLog.h"
#include "../util/CommonFun.h"
#include "../util/HttpSignal.h"
#include "../data/enumData.h"
#include "../data/constData.h"
#include "globaldata.h"
#include <QScriptEngine>
#include <QScriptValueIterator>
#include <QDebug>

HttpDownloadKPosSet::HttpDownloadKPosSet(QString sToken, QString sUUID, QString sCorpID, QString sLastTime)
{
    QString userParam = QString("&uuid=%1&hq_code=%2&access_token=%3").arg(sUUID).arg(sCorpID).arg(sToken);
    if (!sLastTime.isEmpty())
    {
        userParam.append(QString("&last_update_time=%1").arg(sLastTime));
    }
    QString systemParam = CommonFun::generateSystemParams(c_sHttpDownloadKPosSetAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpDownloadKPosSet::processResponse(QString strResult)
{
    //    KPosLog::instance()->writeErrorLog(this->getTestUrl());
    //    KPosLog::instance()->writeErrorLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    QString sUpdateTime = sc.property("update_time").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpDownloadKPosSet 返回参数json格式错误"));
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }
    QScriptValue dataValue = sc.property("data");
    KPosSet kPosSet;
    if (dataValue.isValid())
    {
        analysisKPosSet(dataValue, kPosSet);
        KPosLog::instance()->writeTestLog(QStringLiteral("配置有变化"));
        KPosLog::instance()->writeTestLog(this->getTestUrl());
        KPosLog::instance()->writeTestLog(strResult);
    }
    else
    {
        sUpdateTime = "";
    }

    HttpSignal::instance()->sigOnDownloadKPosSet(nCode, sMsg, kPosSet, sUpdateTime);
    this->deleteLater();
}

void HttpDownloadKPosSet::processError()
{
    KPosSet kPosSet;
    HttpSignal::instance()->sigOnDownloadKPosSet(e_connectServerError, c_sNetError, kPosSet, "");
    this->deleteLater();
}

void HttpDownloadKPosSet::analysisKPosSet(const QScriptValue &dataValue, KPosSet &kPosSet)
{
    analysisPosInfoSet(dataValue, kPosSet.posInfoSet); // pos机信息
    analysisKeySet(dataValue, kPosSet.keySet); // 按键设置
    //    analysisGoodSet(dataValue, kPosSet.goodSet); // 商品设置
    analysisScreenSet(dataValue, kPosSet.screenSet); // 外显设置
    analysisPayWaySet(dataValue, kPosSet.payWaySet); // 支付方式设置
    analysisVirtualPaySet(dataValue, kPosSet.virtualPaySet); // 虚拟支付设置
    analysisParamsSet(dataValue, kPosSet.paramsSet); // 参数设置
    analysisReceipOption(dataValue, kPosSet.receiptSet); // 小票打印选项
    analysisCategoryNodeInfo(dataValue, kPosSet.categoryNodeSet); // 所有分类
//    analysisCategoryUnitInfo(dataValue,kPosSet.unitSet);

}

void HttpDownloadKPosSet::analysisGoodSet(const QScriptValue &dataValue, GoodSet &goodSet)
{
    Q_UNUSED( dataValue )
    Q_UNUSED( goodSet )

    //    if (dataValue.property("pos_pro_info").isArray())
    //    {
    //        QScriptValueIterator it(dataValue.property("pos_pro_info"));
    //        while (it.hasNext())
    //        {
    //            it.next();
    //            if (!it.value().property("categories_id").isValid())
    //            {
    //                continue;
    //            }

    //            CategoryInfoSet categoryInfoSet;
    //            categoryInfoSet.nCategoryId = it.value().property("categories_id").toInt32();
    //            categoryInfoSet.sCategoryName = it.value().property("categories_name").toString();
    //            QString goodsIds = it.value().property("product_ids").toString();
    //            QList<QString> goodsIdList = goodsIds.split(",");
    //            int nLen = goodsIdList.length();
    //            for (int i = 0; i < nLen; i++)
    //            {
    //                if (!goodsIdList[i].isEmpty())
    //                {
    //                    categoryInfoSet.goodsIdList.append(goodsIdList[i].toInt());
    //                }
    //            }

    //            categoryInfoSet.bCustom = it.value().property("is_customed").toBool();
    //            goodSet.categorySetList.append(categoryInfoSet);
    //        }
    //    }
}

void HttpDownloadKPosSet::analysisKeySet(const QScriptValue &dataValue, KeySet &keySet)
{
    keySet.bChanged = false;
    if(!dataValue.property("key_info").isValid())
    {
        return;
    }
    keySet.bChanged = true;

    if (dataValue.property("key_info").property("home_key").isArray())
    {
        QScriptValueIterator it(dataValue.property("key_info").property("home_key"));
        KeySetInfo keySetInfo;
        while (it.hasNext())
        {
            it.next();
            keySetInfo.nKeyId = it.value().property("key_id").toInt32();
            if (keySetInfo.nKeyId == 0 || keySetInfo.nKeyId == e_homeElse)
            {
                continue;
            }
            keySetInfo.bStartUsed = it.value().property("key_values").toBool();
            keySet.homeKeyList.append(keySetInfo);
        }
    }
    //
    if (dataValue.property("key_info").property("refund_key").isArray())
    {
        QScriptValueIterator it(dataValue.property("key_info").property("refund_key"));
        KeySetInfo keySetInfo;
        while (it.hasNext())
        {
            it.next();
            keySetInfo.nKeyId = it.value().property("key_id").toInt32();
            if (keySetInfo.nKeyId == 0)
            {
                continue;
            }
            keySetInfo.bStartUsed = it.value().property("key_values").toBool();
            keySet.refundKeyList.append(keySetInfo);
        }
    }
}

void HttpDownloadKPosSet::analysisParamsSet(const QScriptValue &dataValue, ParamsSet &paramsSet)
{
    paramsSet.bChanged = false;
    if(!dataValue.property("parameter_info").isValid())
    {
        return;
    }
    paramsSet.bChanged = true;
    QScriptValue scriptValue = dataValue.property("parameter_info").property("global_parameter");
    analysisSystemSetParams(scriptValue, paramsSet.systemSetParams); // 系统设置
    scriptValue = dataValue.property("parameter_info").property("orgzs_parameter");
    analysisShopSetParams(scriptValue, paramsSet.shopSetParams); // 门店设置
}

void HttpDownloadKPosSet::analysisSystemSetParams(const QScriptValue &sc, SystemSetParams &systemSetParams)
{
    systemSetParams.nDataSaveDays = sc.property("1").toInt32();
    systemSetParams.nGoodsMaxNumber = sc.property("2").toInt32();
    systemSetParams.bDiscountOnMember = sc.property("3").toBool();
    systemSetParams.bDiscountOnDiscount = sc.property("4").toBool();
    systemSetParams.bDiscardZero = sc.property("5").toBool();
    systemSetParams.bFillReasonForRefund = sc.property("6").toBool();
    systemSetParams.bPriceSale = sc.property("7").toBool();
    systemSetParams.nPriceSaleLimit = sc.property("8").toInt32();
}

void HttpDownloadKPosSet::analysisShopSetParams(const QScriptValue &sc, ShopSetParams &shopSetParams)
{
    shopSetParams.bChangePriceBySeller = sc.property("1").toBool();// 收银员是否有打折改价权限
    shopSetParams.bCreateGoodsBySeller = sc.property("2").toBool();// 是否允许收银员快速建档
    shopSetParams.bOpenCashboxBySeller = sc.property("3").toBool();// 收银员是否有开钱箱权限
    shopSetParams.bSellZeroGoodsBySeller = sc.property("4").toBool();// 前台是否允许销售售价为零的商品
    shopSetParams.bHandinCashBySeller = sc.property("5").toBool();//收银员是否交款
    shopSetParams.bChooseSeller = sc.property("6").toBool();//结算是否选择业务员
    shopSetParams.nPendingListMaxLength = sc.property("7").toInt32();//最大挂单数
    shopSetParams.nLockWaitTimeLenth = sc.property("8").toInt32();// 锁屏等待时间
    shopSetParams.sReceiptShopName = sc.property("9").toString();// 小票门店名称
//    shopSetParams.bSaleByPrice = sc.property("10").toBool();
//    shopSetParams.sPriceRange = sc.property("11").toString();
}

void HttpDownloadKPosSet::analysisPayWaySet(const QScriptValue &dataValue, PayWaySet &payWaySet)
{
    payWaySet.bChanged = false;

    int nUserType = KPosServerIni::getKPosUserType();

    if (nUserType == e_commonVersion)
    {
        if( !dataValue.property("payment_info").isValid() )
        {
            return;
        }
        payWaySet.bChanged = true;
        payWaySet.payWayInfoSetList.clear();

        if (dataValue.property("payment_info").isArray())
        {
            QScriptValueIterator it(dataValue.property("payment_info"));
            while (it.hasNext())
            {
                it.next();
                PayWayInfoSet payWayInfoSet;
                if (!it.value().property("PayType").isValid())
                {
                    continue;
                }
                payWayInfoSet.nPayType = it.value().property("PayType").toInt32();
    //            if ((payWayInfoSet.nPayType == e_PayCash)//现金支付
    //                    || (payWayInfoSet.nPayType == e_PayMemCard) //会员卡支付
    //                    || (payWayInfoSet.nPayType == e_PayAlipay)
    //                    || (payWayInfoSet.nPayType == e_PayWeChat)) //支付宝
    //            {
                    payWayInfoSet.nDropType = it.value().property("DropType").toInt32();
    //                payWayInfoSet.nRefundOrder = it.value().property("seqno").toInt32();
                    payWayInfoSet.bChargeMember = it.value().property("IsChargeMember").toBool();
                    payWayInfoSet.bVirtualPay = it.value().property("IsVirtual").toBool();
                    payWayInfoSet.bStartUse = it.value().property("IsUsed").toInt32();
                    payWaySet.payWayInfoSetList.append(payWayInfoSet);
    //            }
                if (payWayInfoSet.nPayType == e_PayCash)
                {
                    g_cashHandleType = payWayInfoSet.nDropType;
                }
            }
        }
    }
    else if (nUserType == e_tianMaoVersion)
    {
        // 什么也不做用默认值
    }
}

void HttpDownloadKPosSet::analysisVirtualPaySet(const QScriptValue &dataValue, VirtualPaySet &virtualPaySet)
{
    virtualPaySet.bChanged = false;

    int nUserType = KPosServerIni::getKPosUserType();

    if (nUserType == e_commonVersion)
    {
        if( !dataValue.property("virtual_list").isValid() )
        {
            return;
        }
        virtualPaySet.bChanged = true;
        virtualPaySet.virtualList.clear();

        if (dataValue.property("virtual_list").isArray())
        {
            QScriptValueIterator it(dataValue.property("virtual_list"));
            while (it.hasNext())
            {
                it.next();
                VirtualPayInfo virtualPayInfo;
                if (!it.value().property("code").isValid())
                {
                    continue;
                }
                virtualPayInfo.sCode = it.value().property("code").toString();
                virtualPayInfo.sName = it.value().property("name").toString();
                virtualPaySet.virtualList.append(virtualPayInfo);
            }
        }
    }
    else if (nUserType == e_tianMaoVersion)
    {
        // 什么也不做用默认值
    }
}

void HttpDownloadKPosSet::analysisPosInfoSet(const QScriptValue &dataValue, PosInfoSet &posInfoSet)
{
    posInfoSet.bChanged = false;
    QScriptValue posInfoValue = dataValue.property("manage_info");
    if (posInfoValue.isValid())
    {
        posInfoSet.bChanged = true;
        posInfoSet.sShopName = posInfoValue.property("orgz_name").toString();
        posInfoSet.sAppVersion = QString("POS-%1").arg(CommonFun::getAppVersion());
        posInfoSet.sCode = posInfoValue.property("pos_code").toString();
        //        posInfoSet.sPosModel = posInfoValue.property("pos_type").toString();
        posInfoSet.sShopCode = posInfoValue.property("orgz_code").toString();
        //        posInfoSet.nSkinType = posInfoValue.property("skin_type").toInt32();
    }
}

void HttpDownloadKPosSet::analysisScreenSet(const QScriptValue &dataValue, ScreenSet &screenSet)
{
    screenSet.bChanged = false;
    //    QScriptValue screenSetValue = dataValue.property("pos_shows_info").property("show_info");
    //    screenSet.sCardReaderModel = screenSetValue.property("show_card_reader_model").toString();
    //    screenSet.sCardReaderPort = screenSetValue.property("show_card_reader_prot").toString();
    //    screenSet.sClientScreenModel = screenSetValue.property("show_pos_model").toString();
    //    screenSet.sClientScreenPort = screenSetValue.property("show_pos_prot").toString();
    //    screenSet.nClientScreenType = screenSetValue.property("show_type").toInt32();
    //    screenSet.sEBalanceModel = screenSetValue.property("show_balance_model").toString();
    //    screenSet.sEBalancePort = screenSetValue.property("show_balance_prot").toString();
    //    screenSet.sPrinterModel = screenSetValue.property("printer_model").toString();
    //    screenSet.bAllowPrint = screenSetValue.property("is_print").toBool();

    QScriptValue localADValue = dataValue.property("pos_shows_info").property("pos_orgz_ad_info");
    if (localADValue.isArray())
    {
        screenSet.bChanged = true;
        QScriptValueIterator it(localADValue);
        while (it.hasNext())
        {
            it.next();
            MovieAD movieAD;
            movieAD.sPath = it.value().property("picture_url").toString();
            if (movieAD.sPath.isEmpty())
            {
                continue;
            }
            movieAD.nStatus = it.value().property("status").toInt32();
            movieAD.nId = it.value().property("id").toInt32();
            screenSet.localADList.append(movieAD);
        }
    }
    QScriptValue remoteADValue = dataValue.property("pos_shows_info").property("pos_ad_info");
    if (remoteADValue.isArray())
    {
        screenSet.bChanged = true;
        QScriptValueIterator it(remoteADValue);
        while (it.hasNext())
        {
            it.next();
            MovieAD movieAD;
            movieAD.sPath = it.value().property("url").toString();
            if (movieAD.sPath.isEmpty())
            {
                continue;
            }
            if (!movieAD.sPath.startsWith("https://") && !movieAD.sPath.startsWith("http://"))
            {
                movieAD.sPath = KPosServerIni::getServerIp() + "/" + movieAD.sPath;
            }
            movieAD.nStatus = it.value().property("status").toInt32();
            movieAD.nId = it.value().property("id").toInt32();
            screenSet.remoteADList.append(movieAD);
        }
    }
}

void HttpDownloadKPosSet::analysisReceipOption(const QScriptValue &dataValue, ReceiptSet &receiptSet)
{
    receiptSet.bChanged = false;
    QScriptValue optionValue = dataValue.property("receipt_template");
    if (optionValue.isValid())
    {
        receiptSet.bChanged = true;
        receiptSet.sQRCode = ""; // 二维码数据，后台配置
        receiptSet.sHeadContent = optionValue.property("head_words").toString(); // 头部语，后台配置
        receiptSet.sHeadWords = optionValue.property("head_text").toString(); // 头部文字，后台配置
        receiptSet.sTailContent = optionValue.property("tail_content").toString(); // 尾部语，后台配置
        receiptSet.sPicturePath = optionValue.property("picture_url").toString(); // 自定义图片，后台配置
        // 打印选项
        receiptSet.option.bGoodsCode = optionValue.property("is_product_code").toBool(); // 打印商品编码
        receiptSet.option.bCountCategory = optionValue.property("is_category").toBool(); // 打印分类小计
        receiptSet.option.bAddGoodsNumAfterGoodsName = optionValue.property("is_num").toBool(); // 商品数量(x1)添加到商品名后
        receiptSet.option.bPrice = optionValue.property("is_price").toBool(); // 打印单价
        receiptSet.option.bGoodsNameInOneRow = optionValue.property("is_unique_name").toBool(); // 商品名称独占一行 （暂时不做）
        receiptSet.option.bUnit = optionValue.property("is_unit").toBool(); // 打印单位
        receiptSet.option.bForbidBigFont = optionValue.property("is_ban_caps").toBool(); // 禁止大写字体
        receiptSet.option.bShortGoodsName = optionValue.property("is_aka").toBool(); // 打印商品简称
        // 会员的打印选项
        receiptSet.option.memberInfo.bShowInfo = optionValue.property("is_member").toBool(); // 是否显示会员信息
        receiptSet.option.memberInfo.bShowIntegral = optionValue.property("is_member_integra").toBool(); // 是否显示积分
        receiptSet.option.memberInfo.bShowAccountAndRemain = optionValue.property("is_member_account").toBool(); // 显示账号和余额
    }
}

void HttpDownloadKPosSet::analysisCategoryNodeInfo(const QScriptValue &dataValue, CategoryNodeSet &allCategoryInfoSet)
{
    allCategoryInfoSet.bChanged = false;
    QScriptValue categoryValue = dataValue.property("pro_cate_info");
    if (!categoryValue.isValid())
    {
        return;
    }

    allCategoryInfoSet.bChanged = true;
    CategoryInfoNode rootNode;
    generateCategoryNodeList(categoryValue, rootNode);
    allCategoryInfoSet.nodeList = rootNode.nodeyList;
//    qDebug()<<"长度："<<QString::number(rootNode.nodeyList.length());
}

void HttpDownloadKPosSet::analysisCategoryUnitInfo(const QScriptValue &dataValue, CategoryUnitSet &allCategoryUnitSet)
{
    allCategoryUnitSet.bChanged = false;
    QScriptValue categoryValue = dataValue.property("unit_info");
    if (!categoryValue.isValid())
    {
        return;
    }

    allCategoryUnitSet.bChanged = true;
//    CategoryInfoNode rootNode;
//    generateCategoryNodeList(categoryValue, rootNode);
//    allCategoryInfoSet.nodeList = rootNode.nodeyList;
//    qDebug()<<"长度："<<QString::number(rootNode.nodeyList.length());
}

void HttpDownloadKPosSet::generateCategoryNodeList(const QScriptValue &dataValue, CategoryInfoNode &categoryInfoNode)
{
    if (dataValue.isArray())
    {
        categoryInfoNode.nodeyList.clear();
        CategoryInfoNode node;
        QScriptValueIterator it(dataValue);
        while (it.hasNext())
        {
            it.next();
            node.sName = it.value().property("category_name").toString(); // 分类名
            if (node.sName.isEmpty())
            {
                continue;
            }
            node.sId = it.value().property("category_id").toString(); // 分类id
            node.sCode = it.value().property("category_code").toString(); // 分类编码
            node.IdLen=it.value().property("level").toInt32();
            generateCategoryNodeList(it.value().property("list"), node);
            categoryInfoNode.nodeyList.append(node);
        }
    }
}
