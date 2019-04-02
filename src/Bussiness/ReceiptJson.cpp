#include "ReceiptJson.h"
#include <QScriptValueIterator>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include "KPosLog.h"
#include "CommonFun.h"

ReceiptJson::ReceiptJson()
{

}

ReceiptJson::~ReceiptJson()
{

}

//创建支付信息
QString ReceiptJson::createPaySaleHeadJson( const SaleHead &stSaleHead )
{
    QJsonObject dataJson;
    dataJson.insert( "sales_num", stSaleHead.strOrderNum );//订单号
    dataJson.insert("orgz_id", stSaleHead.nShopId);//组织id就是门店id
    dataJson.insert("client_code", stSaleHead.strPosId );//款机号
    dataJson.insert("member_code", stSaleHead.strMemCardId);//会员卡号
    dataJson.insert("cashier_id", stSaleHead.nCashierId);//收款员编号
    dataJson.insert("cashier_name", stSaleHead.strCashierName);//收款员姓名

    QJsonDocument document;
    document.setObject( dataJson );
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

QJsonObject ReceiptJson::createSaleHeadObjectJson( const SaleHead &stSaleHead )
{
//    'orgz_id' => $receipt['StoreId'],
//    'sales_num' => $sales_num,
//    'hq_code' => $hq_code,
//    'client_code' => $receipt['PosId'],
//    'product_amount' => $receipt['SaleTotalNum'],
//    'ought_amount' => $receipt['OughtAmt'],
//    'actual_amount' => $receipt['FactorAmt'],
//    'change_amount' => $receipt['OddChange'],
//    'clear_amount' => '', // 人工抹零
//    'discount_amount' => $receipt['AllDiscountAmt'],
//    'coupon_amount' => '', // 优惠券优惠金额
//    'member_discount' => '', // 会员卡优惠金额
//    'profit_loss' => $receipt['ProfitLoss'],
//    'member_code' => $receipt['MemCardId'],
//    'member_points' => $receipt['MemInteger'],
//    'discount_reason' => $receipt['DisReason'],
//    'temp_discount' => $receipt['GrantDisRate'],
//    'temp_discount_amount' => '',
//    'shopping_type' => $receipt['Type'],
//    'cashier_id' => $receipt['CashierNo'],
//    'cashier_name' => $receipt['CashierName'],
//    'assistant_id' => $receipt['ShoppingNo'],
//    'assistant_name' => $receipt['ShoppingName'],
//    'deal_status' => $receipt['TranStatus'],
//    'deal_begin_time'=> $receipt['FactorTime'],
//    'deal_complete_at' => $receipt['CompleteTime'],
//    'receipts_upload_at' => date('Y-m-d H:i:s'),
//    'source' => $receipt['SaleMode'],
//    'genre' => $receipt['SaleType'],
//    'return_doc_code' => $receipt['ReturnOrderNum'],
//    'return_reason' => $receipt['ReturnReason'],
//    'created_at' => date('Y-m-d H:i:s')

        // 新增
//    `clear_amount` double(8,2) DEFAULT NULL COMMENT '人工抹零：单位(元)',
//    `coupon_amount` double(8,2) DEFAULT NULL COMMENT '优惠券优惠金额：单位(元)',  // 小改暂时不提供
//    `member_discount` double(8,2) DEFAULT NULL COMMENT '会员卡优惠金额：单位(元)', // 小改暂时不提供

    QJsonObject dataJson;
    dataJson.insert( "sales_num", stSaleHead.strOrderNum );//订单号
    dataJson.insert("orgz_id", stSaleHead.nShopId);//组织id就是门店id
    dataJson.insert("client_code", stSaleHead.strPosId );//款机号
    dataJson.insert("product_amount", stSaleHead.nSaleTotalNum);//商品销售总数
    dataJson.insert("ought_amount", stSaleHead.fOughtAmt);//应付金额
    dataJson.insert("actual_amount", stSaleHead.fFactorAmt);//实付金额
    dataJson.insert("change_amount", stSaleHead.fOddChange);//找零
    dataJson.insert("member_code", stSaleHead.strMemCardId);//会员卡号
    dataJson.insert("member_points", stSaleHead.nMemInteger);//会员积分
    dataJson.insert("discount_reason", stSaleHead.strDisReason);//折扣原因
    dataJson.insert("temp_discount", stSaleHead.fGrantDisRate);//临时折扣率
    dataJson.insert("discount_amount", stSaleHead.fAllDisAmt);//所有优惠金额
    dataJson.insert("profit_loss", stSaleHead.fProfitLoss);//收银损益(实际支付的钱- 找零-应付金额)
    dataJson.insert("shopping_type", stSaleHead.nType);//购物类型:网购、现购、团购
    dataJson.insert("cashier_id", stSaleHead.nCashierId);//收款员编号
    dataJson.insert("cashier_name", stSaleHead.strCashierName);//收款员姓名
    dataJson.insert( "assistant_id", stSaleHead.nShoppingId );//导购员ID
    dataJson.insert( "assistant_name", stSaleHead.strShoppingName );//导购员名字
    dataJson.insert("deal_status", stSaleHead.nStatus );//交易状态: -1.取消，0.正在进行，1.完成

    //实际交易时间
    dataJson.insert("deal_begin_time", stSaleHead.dtFactorTime.toString("yyyy-MM-dd hh:mm:ss"));
    dataJson.insert("deal_complete_at", stSaleHead.dtCompleteTime.toString("yyyy-MM-dd hh:mm:ss") );//交易完成时间
//    dataJson.insert("ReceiptUpload", stSaleHead.dtReceiptUpload.toString("yyyy-MM-dd hh:mm:ss") );//小票上传时间
    dataJson.insert("source", stSaleHead.nSaleMode );//销售方式: 1.KeyPos，2.待定
    dataJson.insert( "genre", stSaleHead.nSaleType );//销售类型：0.销售小票，1.退货小票，2.会员充值，3.储值卡充值，4.退充值，5.取消小票
    dataJson.insert( "return_doc_code", stSaleHead.strReturnOrderNum );//退货单据号：退货小票记录，为预退订销售单单号//需要退货的订单号
    dataJson.insert( "return_reason", stSaleHead.strReturnReason );//退货原因：来源Pos参数设置，退货原因
    dataJson.insert("clear_amount", stSaleHead.sSmallChangeAmt); // 找零金额
    dataJson.insert("coupon_amount", stSaleHead.fCouponDisAmt); // 优惠券金额

    return dataJson;

//    QJsonObject dataJson;
//    dataJson.insert( "OrderNum", stSaleHead.strOrderNum );//订单号
//    dataJson.insert("StoreId", stSaleHead.nShopId);//组织id就是门店id
//    dataJson.insert("PosId", stSaleHead.strPosId );//款机号
//    dataJson.insert("SaleTotalNum", stSaleHead.nSaleTotalNum);//商品销售总数
//    dataJson.insert("OughtAmt", stSaleHead.fOughtAmt);//应付金额
//    dataJson.insert("FactorAmt", stSaleHead.fFactorAmt);//实付金额
//    dataJson.insert("OddChange", stSaleHead.fOddChange);//找零
//    dataJson.insert("MemCardId", stSaleHead.strMemCardId);//会员卡号
//    dataJson.insert("MemInteger", stSaleHead.nMemInteger);//会员积分
//    dataJson.insert("DisReason", stSaleHead.strDisReason);//折扣原因
//    dataJson.insert("GrantDisRate", stSaleHead.fGrantDisRate);//临时折扣率
//    dataJson.insert("AllDiscountAmt", stSaleHead.fAllDisAmt);//所有优惠金额
//    dataJson.insert("ProfitLoss", stSaleHead.fProfitLoss);//收银损益(实际支付的钱- 找零-应付金额)
//    dataJson.insert("Type", stSaleHead.nType);//购物类型:网购、现购、团购
//    dataJson.insert("CashierNo", stSaleHead.nCashierId);//收款员编号
//    dataJson.insert("CashierName", stSaleHead.strCashierName);//收款员姓名
//    dataJson.insert( "ShoppingNo", stSaleHead.nShoppingId );//导购员ID
//    dataJson.insert( "ShoppingName", stSaleHead.strShoppingName );//导购员名字
//    dataJson.insert("TranStatus", stSaleHead.nStatus );//交易状态: -1.取消，0.正在进行，1.完成

//    //实际交易时间
//    dataJson.insert("FactorTime", stSaleHead.dtFactorTime.toString("yyyy-MM-dd hh:mm:ss"));
//    dataJson.insert("CompleteTime", stSaleHead.dtCompleteTime.toString("yyyy-MM-dd hh:mm:ss") );//交易完成时间
//    dataJson.insert("ReceiptUpload", stSaleHead.dtReceiptUpload.toString("yyyy-MM-dd hh:mm:ss") );//小票上传时间
//    dataJson.insert("SaleMode", stSaleHead.nSaleMode );//销售方式: 1.KeyPos，2.待定
//    dataJson.insert( "SaleType", stSaleHead.nSaleType );//销售类型：0.销售小票，1.退货小票，2.会员充值，3.储值卡充值，4.退充值，5.取消小票
//    dataJson.insert( "ReturnOrderNum", stSaleHead.strReturnOrderNum );//退货单据号：退货小票记录，为预退订销售单单号//需要退货的订单号
//    dataJson.insert( "ReturnReason", stSaleHead.strReturnReason );//退货原因：来源Pos参数设置，退货原因

//    return dataJson;
}

QJsonArray ReceiptJson::createSaleHeadArrayJson( const QList<SaleHead> &listSaleHead )
{
    QJsonArray jsonArray;
    for (int i = 0; i < listSaleHead.length(); i++)
    {
        jsonArray.append( createSaleHeadObjectJson( listSaleHead[i] ) );
    }

    return jsonArray;
}

QJsonObject ReceiptJson::createSaleDetailsObjectJson(const SaleDetails &saleDetails , bool bRefund)
{
//    'sales_id' => $sales_id,
//    'hq_code' => $hq_code,
//    'orgz_id' => $receipt['StoreId'],
//    'product_id' => $sales_details->GoodsId,
//    'product_name' => $sales_details->GoodsName,
//    'product_bar_plu' => $sales_details->BarCode,
//    'min_spec_unit' => $sales_details->GoodsUnit,
//    'sale_quantity' => $sales_details->SaleNum,
//    'sale_unit_price' => $sales_details->SalePrice,
//    'member_price' => $sales_details->SaleMemPrice,
//    'sale_amount' => $sales_details->SaleAmt,
//    'deal_unit_price' => $sales_details->SwapPrice,
//    'deal_amount' => $sales_details->SwapAmt,
//    'real_amount' => '', // 实际金额
//    'discount_amount' => $sales_details->AllDiscountAmt, // 平摊优惠金额：POS传递的优惠 + （优惠券和抹零的平摊）
//    'temp_discount' => $sales_details->GrantDisRate,
//    'tex_rate' => $sales_details->TaxRate,
//    'scan_bar_code' => $sales_details->InpBarCode,
//    'deal_status' => $sales_details->Status,
//    'created_at' => date('Y-m-d H:i:s'),
//    'member_discount' => '',
//    'temp_disc_amount' => '',
//    // 'price_alter_no' => $sales_details->PromPrice,  暂无促销相关信息
//    // 'prom_disc_rate' => $sales_details->PopDisRate,
//    // 'prom_activity_no' => $sales_details->BatchNo,
//    // 'prom_disc_amount' => '',

    // 新增
//    `real_amount` double(8,2) NOT NULL COMMENT '实际金额：单位(元)', // 后台自己计算，暂时不给
//    `member_discount` double(8,2) DEFAULT NULL COMMENT '会员卡优惠金额: 单位(元)', // 后台自己计算，暂时不给
//    `prom_disc_amount` double(8,2) DEFAULT NULL COMMENT '促销折扣金额: 单位(元)', // 还没做，先不考虑
//    `temp_disc_amount` double(8,2) DEFAULT NULL COMMENT '临时折扣金额: 单位(元)', // 还没做，先不考虑
//    `is_standard` tinyint(4) NOT NULL DEFAULT '1' COMMENT '是否标品：0.否，1.是',
//    `plu_id` int(11) DEFAULT NULL COMMENT 'PLU等级',


    QJsonObject dataJson;
    dataJson.insert("client_content_id", saleDetails.nSaleDetailPos);
//    dataJson.insert("sales_id", saleDetails.strOrderNum);//单号
    dataJson.insert("product_bar_plu", saleDetails.strBarCode);//标品就用商品条码，非标品使用PLU码
    dataJson.insert("product_name", saleDetails.strGoodsName );//商品名称
    dataJson.insert("product_id", saleDetails.nGoodsId);//商品id

    QString strPrice = "";
    strPrice.sprintf( "%.2f", saleDetails.fPrice );
    dataJson.insert("sale_unit_price", strPrice );//原单价
    dataJson.insert("member_price", CommonFun::floatToString( saleDetails.fMemPrice ) );//会员价
//    dataJson.insert("member_amount", CommonFun::handleMoneyCoin(saleDetails.fMemPrice * saleDetails.goodsInfo.fNumber*(bRefund ?-1:1))); // 后台自己算
    dataJson.insert("sale_quantity", bRefund ? saleDetails.goodsInfo.fRefundNumber : saleDetails.goodsInfo.fNumber );//销售数量
//    dataJson.insert("sale_amount", bRefund ? saleDetails.goodsInfo.sRefundSumPrice : saleDetails.goodsInfo.sSumPrice);//原销售金额 // 后台自己算
    dataJson.insert("min_spec_unit", saleDetails.goodsInfo.sUnit );//商品单位
//    dataJson.insert("GoodsSpec", saleDetails.strGoodsSpec);//商品规格
    dataJson.insert("deal_unit_price", saleDetails.fSwapPrice);//实际成交单价
    dataJson.insert("deal_amount", saleDetails.strSwapAmt);//实际成交金额
    dataJson.insert("prom_disc_amount", saleDetails.fPopDisAmt);//促销折扣
    dataJson.insert("prom_disc_rate", saleDetails.fPopDisRate);//促销折扣率
    dataJson.insert("temp_discount", saleDetails.fGrantDisRate);//临时折扣率
    dataJson.insert("discount_amount", saleDetails.fAllDisAmt);//所有优惠金额
    dataJson.insert("tex_rate", saleDetails.fTaxRate);//税率
    dataJson.insert("scan_bar_code", saleDetails.strInpBarCode);//扫描条码：临时称重品条码
    dataJson.insert("prom_activity_no", saleDetails.strBatchNo);//促销活动号（SJ使用中）
    dataJson.insert("price_alter_no", saleDetails.strPromPrice);//促销改价单号
//    dataJson.insert("CreateTime", saleDetails.dtCreateTime.toString("yyyy-MM-dd hh:mm:ss"));//创建时间
    dataJson.insert("deal_status", saleDetails.nStatus);//正在进行，取消，完成
    dataJson.insert("is_standard", saleDetails.goodsInfo.bStandard ? 1 : 0); // 是否标品
    dataJson.insert("plu_id", saleDetails.goodsInfo.nTasteType);

    return dataJson;

//    QJsonObject dataJson;
//    dataJson.insert("OrderNum", saleDetails.strOrderNum);//单号
//    dataJson.insert("BarCode", saleDetails.strBarCode);//标品就用商品条码，非标品使用PLU码
//    dataJson.insert("GoodsName", saleDetails.strGoodsName );//商品名称
//    dataJson.insert("GoodsId", saleDetails.nGoodsId);//商品id

//    QString strPrice = "";
//    strPrice.sprintf( "%.2f", saleDetails.fPrice );
//    dataJson.insert("SalePrice", strPrice );//原单价
//    dataJson.insert("SaleMemPrice", CommonFun::floatToString( saleDetails.fMemPrice ) );//会员价
//    dataJson.insert("SaleNum", bRefund ? saleDetails.goodsInfo.fRefundNumber : saleDetails.goodsInfo.fNumber );//销售数量
//    dataJson.insert("SaleAmt", bRefund ? saleDetails.goodsInfo.sRefundSumPrice : saleDetails.goodsInfo.sSumPrice);//原销售金额
//    dataJson.insert("GoodsUnit", saleDetails.goodsInfo.sUnit );//商品单位
//    dataJson.insert("GoodsSpec", saleDetails.strGoodsSpec);//商品规格
//    dataJson.insert("SwapPrice", saleDetails.fSwapPrice);//实际成交单价
//    dataJson.insert("SwapAmt", saleDetails.strSwapAmt);//实际成交金额
//    dataJson.insert("PopDisAmt", saleDetails.fPopDisAmt);//促销折扣
//    dataJson.insert("PopDisRate", saleDetails.fPopDisRate);//促销折扣率
//    dataJson.insert("GrantDisRate", saleDetails.fGrantDisRate);//临时折扣率
//    dataJson.insert("AllDiscountAmt", saleDetails.fAllDisAmt);//所有优惠金额
//    dataJson.insert("TaxRate", saleDetails.fTaxRate);//税率
//    dataJson.insert("InpBarCode", saleDetails.strInpBarCode);//扫描条码：临时称重品条码
//    dataJson.insert("BatchNo", saleDetails.strBatchNo);//促销活动号（SJ使用中）
//    dataJson.insert("PromPrice", saleDetails.strPromPrice);//促销改价单号
//    dataJson.insert("CreateTime", saleDetails.dtCreateTime.toString("yyyy-MM-dd hh:mm:ss"));//创建时间
//    dataJson.insert("Status", saleDetails.nStatus);//正在进行，取消，完成

//    return dataJson;
}

QJsonArray ReceiptJson::createSaleDetailsArrayJson(const QList<SaleDetails> &listSaleDetails , bool bRefund)
{
    QJsonArray jsonArray;
    for (int i = 0; i < listSaleDetails.length(); i++)
    {
        jsonArray.append( createSaleDetailsObjectJson( listSaleDetails[i], bRefund) );
    }

    return jsonArray;
}

QString ReceiptJson::createSaleDetailsArrayJsonToString(const QList<SaleDetails> &listSaleDetails)
{
    QJsonArray jsonArray;
    for (int i = 0; i < listSaleDetails.length(); i++)
    {
        jsonArray.append( createSaleDetailsObjectJson( listSaleDetails[i], false) );
    }

    QJsonDocument document;
    document.setArray( jsonArray );
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

QJsonObject ReceiptJson::createPayDetailsObjectJson( const PayDetail_s &stPayDetails )
{
//    支付明细：
//    'mode_id' => $payment_details->PayMethod,
//    'is_virtual' => $payment_details->IsVirtual,
//    'hq_code' => $hq_code,
//    'sales_id' => $sales_id,
//    'payment_num' => $payment_details->PaymentOrderNum,
//    'payment_amount' => $payment_details->PayMoney,
//    'payment_integral' => $payment_details->PayIntegral,
//    'integral_exchange_amount' => $payment_details->IntToAmt,
//    'deal_status' => $payment_details->Status,
//    'type' => $payment_details->PayType,
//    'spbill_create_ip' => $spbill_create_ip,
//    'nonce_str' => $nonce_str,
//    'payment_account' => $payment_details->AuthCode,
//    'created_at' => date('Y-m-d H:i:s')

    QJsonObject dataJson;
    dataJson.insert("payment_num", stPayDetails.strPaymentOrderNum);//支付单号
    dataJson.insert("mode_id", stPayDetails.nPayMethod );//支付方式
    dataJson.insert("payment_amount", stPayDetails.fPayMoney );//支付金额
    dataJson.insert( "payment_integral", stPayDetails.nPayIntegral );//支付积分
    float fIntToAmt = 0.00;
    if( stPayDetails.nPayIntegral > 0 && stPayDetails.strIntExchangeAmt.toFloat() > 0 ) {
        fIntToAmt = stPayDetails.nPayIntegral * stPayDetails.strIntExchangeAmt.toFloat();
    }
//    dataJson.insert( "integral_exchange_amount", fIntToAmt );//积分抵现金额：单位(元)
    dataJson.insert( "payment_account", stPayDetails.strAuthCode );//支付授权码
    int nStatus = stPayDetails.nStatus;
    if (nStatus == e_PayRefund)
    {
        nStatus = e_PaySuccess;
    }
    dataJson.insert("deal_status", nStatus );//
    dataJson.insert("type", stPayDetails.nPayType );
    dataJson.insert( "is_virtual", stPayDetails.bVirtual ? 1 : 0);
    return dataJson;

//    QJsonObject dataJson;
//    dataJson.insert("PaymentOrderNum", stPayDetails.strPaymentOrderNum);//支付单号
//    dataJson.insert("PayMethod", stPayDetails.nPayMethod );//支付方式
//    dataJson.insert("PayMoney", stPayDetails.fPayMoney );//支付金额
//    dataJson.insert( "PayIntegral", stPayDetails.nPayIntegral );//支付积分
//    float fIntToAmt = 0.00;
//    if( stPayDetails.nPayIntegral > 0 && stPayDetails.strIntExchangeAmt.toFloat() > 0 ) {
//        fIntToAmt = stPayDetails.nPayIntegral * stPayDetails.strIntExchangeAmt.toFloat();
//    }
//    dataJson.insert( "IntToAmt", fIntToAmt );//积分抵现金额：单位(元)
//    dataJson.insert( "AuthCode", stPayDetails.strAuthCode );//支付授权码
//    int nStatus = stPayDetails.nStatus;
//    if (nStatus == e_PayRefund)
//    {
//        nStatus = e_PaySuccess;
//    }
//    dataJson.insert("Status", nStatus );//
//    dataJson.insert("PayType", stPayDetails.nPayType );
//    dataJson.insert( "IsVirtual", stPayDetails.bVirtual );
//    return dataJson;
}

QJsonArray ReceiptJson::createPayDetailsArrayJson( const QList<PayDetail_s> &listPayDetails )
{
    QJsonArray jsonArray;
    for (int i = 0; i < listPayDetails.length(); i++)
    {
        if (listPayDetails[i].fPayMoney > 0.0001f || listPayDetails[i].fPayMoney < 0) // 过滤掉支付金额为0的支付明细
        {
           jsonArray.append( createPayDetailsObjectJson( listPayDetails[i] ) );
        }
    }

    return jsonArray;
}

QString ReceiptJson::createSaleArrayJson( const SaleHead &stSaleHead, const QList<SaleDetails> listSaleDetails )
{
    QJsonObject dataJson;

    QJsonArray jsonArray;
    dataJson = createSaleHeadObjectJson( stSaleHead );
    dataJson.insert( "SaleDetails", createSaleDetailsArrayJson( listSaleDetails, (stSaleHead.nSaleType == 1) ) );
    jsonArray.append( dataJson );

    QJsonDocument document;
    document.setArray( jsonArray );
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

QString ReceiptJson::createSaleArrayJson( const SaleHead &stSaleHead, const QList<SaleDetails> listSaleDetails, const QList<PayDetail_s> &listPayDetails )
{
    QJsonObject dataJson;

    QJsonArray jsonArray;
    dataJson = createSaleHeadObjectJson( stSaleHead );
    dataJson.insert( "SaleDetails", createSaleDetailsArrayJson( listSaleDetails, (stSaleHead.nSaleType == 1) ));
    dataJson.insert( "PayDetails", createPayDetailsArrayJson( listPayDetails ) );
    jsonArray.append( dataJson );

    QJsonDocument document;
    document.setArray( jsonArray );
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

QString ReceiptJson::createReceiptArrayJson( QList<SaleHead> listSaleHead )
{
    Q_UNUSED( listSaleHead )

    QJsonArray jsonArray;
//    for (int i = 0; i < listSaleHead.length(); i++)
//    {
//        QJsonObject json;
//        json.insert("SaleDetails", createSaleArrayJson( listSaleHead[i] ) );
//        jsonArray.insert(i, json);
//    }
    QJsonDocument document;
    document.setArray(jsonArray);

    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    return QString(byte_array);
}

