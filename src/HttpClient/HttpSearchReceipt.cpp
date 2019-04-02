#include "HttpSearchReceipt.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "../util/CommonFun.h"
#include "../data/constData.h"
#include "../data/enumData.h"
#include "../data/structData.h"
#include "EnumToString.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpSearchReceipt::HttpSearchReceipt(QString sToken, QString sCorpID, QString sUUID, QString sOrderNum, bool isSaleDetial)
{
    m_sOrderNum = sOrderNum;
    m_isSaleDetial = isSaleDetial;
    QString userParam = QString("&hq_code=%1&order_num=%2&access_token=%4&uuid=%5")
            .arg(sCorpID).arg(sOrderNum).arg(sToken).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpSearchReceiptAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpSearchReceipt::processResponse(QString strResult)
{
    KPosLog::instance()->writeErrorLog(this->getTestUrl());
    KPosLog::instance()->writeErrorLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpSearchReceipt 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    SaleHead saleHead;
    QScriptValue saleInfoValue = sc.property("data").property("sale_info");
    saleHead.nShopId = saleInfoValue.property("orgz_id").toInt32();//门店号
    saleHead.strPosId = saleInfoValue.property("client_code").toString();//款机号
    saleHead.strCashierName = saleInfoValue.property("cashier_name").toString();//收银员姓名
    saleHead.strShoppingName = saleInfoValue.property("assistant_name").toString();//导购员姓名
    saleHead.strOrderNum = saleInfoValue.property("sales_num").toString();//单号
    saleHead.fCouponDisAmt = saleInfoValue.property("coupon_amount").toString().toFloat();//优惠券金额
    saleHead.nSaleTotalNum = saleInfoValue.property("product_amount").toInt32();//商品总数
    saleHead.sSmallChangeAmt = saleInfoValue.property("clear_amount").toString();//抹零金额
    saleHead.actChange = saleInfoValue.property("change_amount").toString().toFloat();
    QString time = saleInfoValue.property("deal_complete_at").toString(); //交易时间
    saleHead.dtCompleteTime = QDateTime::fromString(time, "yyyy-MM-dd hh:mm:ss");
    saleHead.fOughtAmt = saleInfoValue.property("ought_amount").toString().toFloat();//应付金额 // 应该服务器或本地数据库给
    saleHead.fFactorAmt = saleInfoValue.property("actual_amount").toString().toFloat();//实付金额： // 应该服务器或本地数据库给
    saleHead.strDisReason = saleInfoValue.property("discount_reason").toString();//折扣原因 // 应该服务器或本地数据库给 暂时无需求
    saleHead.fGrantDisRate = saleInfoValue.property("temp_discount").toString().toFloat();//临时折扣率 // 应该服务器或本地数据库给 暂时无需求
    saleHead.fProfitLoss = saleInfoValue.property("profit_loss").toString().toFloat();//收银损益(实际支付的钱- 找零-应付金额) // 应该服务器或本地数据库给 暂时无需求
    saleHead.nType = saleInfoValue.property("shopping_type").toInt32();//购物类型:0.现购，1.网购，2.团购，// 应该服务器或本地数据库给 暂时无需求
    saleHead.strReturnOrderNum = m_sOrderNum;//退货订单号
    saleHead.fCouponDisAmt = saleInfoValue.property("coupon_amount").toString().toFloat();
    saleHead.sSmallChangeAmt = saleInfoValue.property("clear_amount").toString();

    QScriptValue vipInfoValue = sc.property("data").property("vip_info");
    saleHead.fOddChange = vipInfoValue.property("last_changes").toString().toFloat();//找零 // 应该服务器或本地数据库给
    saleHead.strMemCardId = vipInfoValue.property("card_no").toString();//会员卡号 // 应该服务器或本地数据库给
    saleHead.strMemName = vipInfoValue.property("vip_name").toString();
    saleHead.strLastShopping = vipInfoValue.property("last_shopping").toString();
    saleHead.strLastCharge = vipInfoValue.property("last_changes").toString();
    saleHead.fAllDisAmt = vipInfoValue.property("last_discount").toString().toFloat();//所有优惠金额 // 应该服务器或本地数据库给 暂时无需求

    QList<PaymentDetailInfo> paymentInfoList;
    if(sc.property("data").property("payment_details").isArray()){
        PaymentDetailInfo paymentInfo;
        QScriptValueIterator it(sc.property("data").property("payment_details"));
        while(it.hasNext()){
            it.next();
            int id = it.value().property("id").toInt32();
            if(id <= 0){
                continue;
            }
            paymentInfo.ePayMethod = EnumToString::payMethodToEnum(it.value().property("mode_id").toString());
            paymentInfo.fPaymentSum = it.value().property("payment_amount").toString().toFloat();
            paymentInfoList.append(paymentInfo);
        }
    }

    float fIntegralPayMoney = sc.property("data").property("integral_pay").property("payment_amount").toString().toFloat();
    int nIntegralPay = sc.property("data").property("integral_pay").property("payment_integral").toInt32();

    QList<SaleDetails> saleDetailsList;
    if (sc.property("data").property("sales_details").isArray())
    {
        SaleDetails saleDetails;
        QScriptValueIterator it(sc.property("data").property("sales_details"));
        while (it.hasNext())
        {
            it.next();
            // saleDetails.nSaleDetailPos; //销售明细id // 自己生成
            // saleDetails.strOrderNum; //单号 // 后期关联SaleHead
            saleDetails.nGoodsId = it.value().property("product_id").toInt32(); //商品id
            if (saleDetails.nGoodsId <= 0)
            {
                continue;
            }
            saleDetails.strGoodsScode = it.value().property("product_code").toString(); //商品编号
            saleDetails.strBarCode = it.value().property("product_bar_plu").toString(); //商品条码
            saleDetails.strGoodsName = it.value().property("product_name").toString(); //商品名称

            saleDetails.strGoodsSpec = it.value().property("sale_unit").toString(); //商品规格
            saleDetails.fSwapPrice = it.value().property("deal_unit_price").toString().toFloat();     //实际成交单价
            saleDetails.strSwapAmt = it.value().property("deal_amount").toString();    //实际成交金额
            saleDetails.fPopDisAmt = 0.0f;    //促销折扣,后台没有给，暂时也不需要
            saleDetails.fPopDisRate = 0.0f;   //促销折扣率,8折，后台没有给，暂时也不需要

            saleDetails.fGrantDisRate = it.value().property("temp_discount").toString().toFloat();//临时折扣率
            saleDetails.fAllDisAmt = it.value().property("discount_amount").toString().toFloat();   //所有优惠金额
            saleDetails.fTaxRate = it.value().property("tex_rate").toString().toFloat();       //税率
            saleDetails.strInpBarCode = it.value().property("scan_bar_code").toString();  //扫描条码
            saleDetails.strBatchNo = it.value().property("prom_activity_no").toString();   //促销活动号（SJ使用中）

            saleDetails.strPromPrice = ""; //促销改价单号, 后台没有给，暂时也不需要
            // saleDetails.dtCreateTime = it.value().property("product_id").toString();//创建时间
            saleDetails.nStatus = it.value().property("deal_status").toInt32();//商品状态
            saleDetails.pStatus = it.value().property("price_changed").toInt32();//订单状态
            saleDetails.fPrice = it.value().property("sale_unit_price").toString().toFloat();//原单价
            saleDetails.fMemPrice = it.value().property("member_price").toString().toFloat(); //会员价

            // saleDetails.strOrgSum = it.value().property("product_id").toString();//原总金额
            // saleDetails.strOrgMemSum = it.value().property("product_id").toString();//原会员价总金额
            // saleDetails.goodsInfo.nPos = it.value().property("product_id").toString();//列表序号
            // saleDetails.goodsInfo.nSaleDetailPos;//销售明细序号
            saleDetails.goodsInfo.nGoodsId = saleDetails.nGoodsId; //商品id
            saleDetails.goodsInfo.strGoodsCode = saleDetails.strBarCode;//商品编码id, 此处赋值不对要改成编码
            saleDetails.goodsInfo.sGoodsId = saleDetails.strGoodsScode; //商品编号
            saleDetails.goodsInfo.sGoodsName = saleDetails.strGoodsName;//商品名字
            saleDetails.goodsInfo.strGoodsShortName = saleDetails.strGoodsName;//商品简称, 此处赋值不对
            saleDetails.goodsInfo.fPrice = saleDetails.fSwapPrice;//显示单价
            saleDetails.goodsInfo.fNumber = it.value().property("sale_quantity").toString().toFloat();//销售数量
            saleDetails.goodsInfo.sSumPrice = it.value().property("sale_amount").toString();//显示总价
            saleDetails.goodsInfo.sUnit = it.value().property("sale_unit").toString();//单位
            saleDetails.goodsInfo.fHaveRefundNum = it.value().property("returned_num").toString().toFloat();//单位
            // saleDetails.goodsInfo.bPromotion = it.value().property("member_price").toString();//是否促销
            // saleDetails.goodsInfo.bDisCount = it.value().property("member_price").toString(); // 是否折扣
            // saleDetails.goodsInfo.bRefund = it.value().property("member_price").toString(); // 是否退货
            // saleDetails.goodsInfo.nTasteType = it.value().property("member_price").toString();//商品口味分级
            // saleDetails.goodsInfo.bStandard = it.value().property("member_price").toString();//商品类型
            // saleDetails.goodsInfo.nCategoryId = it.value().property("member_price").toString();//商品分类id
            saleDetails.goodsInfo.fRefundPrice = saleDetails.fSwapPrice;//退款金额
            saleDetails.goodsInfo.fRefundNumber = 0.0f;//退款数量
            saleDetails.goodsInfo.sRefundSumPrice = "";//退款总价
            // saleDetails.goodsInfo.bSelectStatus;//商品选中状态
            saleDetails.strLog = "";        //日志
            saleDetailsList.append(saleDetails);
        }
    }
    if(m_isSaleDetial){
        HttpSignal::instance()->sigOnGetSaleReceiptOrderList(nCode, sMsg, saleHead, saleDetailsList, paymentInfoList);
    }
    else
    {
        HttpSignal::instance()->sigOnSearchReceipt(nCode, sMsg, saleHead, saleDetailsList, fIntegralPayMoney, nIntegralPay);
    }
    this->deleteLater();
}

void HttpSearchReceipt::processError()
{
//    if(m_isSaleDetial){
//        HttpSignal::instance()->sigOnGetSaleReceiptOrderList(nCode, sMsg, saleHead, saleDetailsList, paymentInfoList);
//    }
//    else
//    {
//        HttpSignal::instance()->sigOnSearchReceipt(nCode, sMsg, saleHead, saleDetailsList, fIntegralPayMoney, nIntegralPay);
//    }
    this->deleteLater();
}

