#include "SellRefundCtr.h"
#include "../util/KPosIni.h"
#include "../Agent/SaleHeadAgent.h"
#include "../Agent/LoginKPosAgent.h"

SellRefundCtr::SellRefundCtr(QObject *parent)
    : QObject(parent)
{

}

void SellRefundCtr::createSaleHead(int nSaleType)
{
//    m_stSaleHead.nSerialNum = KPosIni::getSerialNum();
//    m_stSaleHead.nSaleHeadId = m_pSellRefundCtr->getSaleHeadId();
//    m_stSaleHead.dtCreateTime = QDateTime::currentDateTime();
//    m_stSaleHead.strPosId = KPosIni::getPosCode();
//    m_stSaleHead.strOrderNum = m_pSellRefundCtr->getOrderNumber();
//    m_stSaleHead.nSaleTotalNum = 0;
//    m_stSaleHead.fOughtAmt = 0.00;
//    m_stSaleHead.fFactorAmt = 0.00;
//    m_stSaleHead.fOddChange = 0.00;
//    m_stSaleHead.strMemCardId = "";
//    m_stSaleHead.nMemInteger = 0;
//    m_stSaleHead.strDisReason = "";
//    m_stSaleHead.fGrantDisRate = 0.0;
//    m_stSaleHead.fAllDisAmt = 0.00;
//    m_stSaleHead.fProfitLoss = 0.00;
//    m_stSaleHead.nStatus = e_headSelling;//交易状态:正在进行，挂单，完成，取消
//    m_stSaleHead.nType = 0;//购物类型:0.现购，1.网购，2.团购
//    m_stSaleHead.nShopId = KPosIni::getShopId();//门店编号
//    m_stSaleHead.eUploadStatus = eNotUpload;//上传总部状态
//    m_stSaleHead.dtFactorTime = m_stSaleHead.dtCreateTime;//实际交易时间
//    m_stSaleHead.nCostTime = 0;//交易花费时间
//    SalemanInfo stSaleman = LoginKPosAgent::instance()->getLoginKPosInfo().salemanInfo;
//    m_stSaleHead.nCashierId = stSaleman.nUserId;//收款员编号
//    m_stSaleHead.strCashierName = stSaleman.sUsername;//收款员姓名
//    m_stSaleHead.nTranStatus = 0;
//    m_stSaleHead.nSaleType = nSaleType;
//    m_stSaleHead.strReturnOrderNum = "";
//    m_stSaleHead.strReturnReason = "";
//    m_stSaleHead.nSaleMode = 1;//销售方式:默认为Kpos销售
//    m_stSaleHead.strLog = "";
//    SaleHeadAgent::Instance()->insertSaleHeadTable(m_stSaleHead);
}

void SellRefundCtr::convertGoodsDetail(SaleDetails &saleDetails, const GoodsInfo &goodsInfo)
{
//    saleDetails.nSaleDetailPos;       //销售明细id
//    saleDetails.strOrderNum;     //单号
//    saleDetails.strBarCode;   //商品条码
//    saleDetails.strGoodsName;     //商品名称
//    saleDetails.nGoodsId;         //商品id
//    saleDetails.strGoodsSpec;       //商品规格
//    saleDetails.fSwapPrice;     //实际成交单价
//    saleDetails.strSwapAmt;    //实际成交金额
//    saleDetails.fPopDisAmt;    //促销折扣
//    saleDetails.fPopDisRate;   //促销折扣率,8折
//    saleDetails.fGrantDisRate;//临时折扣率
//    saleDetails.fAllDisAmt;   //所有优惠金额
//    saleDetails.fTaxRate;       //税率
//    saleDetails.strInpBarCode;  //扫描条码
//    saleDetails.strBatchNo;   //促销活动号（SJ使用中）
//    saleDetails.strPromPrice; //促销改价单号
//    saleDetails.dtCreateTime;//创建时间
//    saleDetails.nStatus;//正在进行，取消，完成
//    saleDetails.fPrice;//原单价
//    saleDetails.fMemPrice; //会员价
//    saleDetails.strOrgSum;//原总金额
//    saleDetails.strOrgMemSum;//原会员价总金额

//    //    int nPos;//列表序号
//    //    saleDetails.nSaleDetailPos;//销售明细序号
//        saleDetails.st_goodsDetailInfo.nGoodsId = goodsInfo.nId;//商品id
//        saleDetails.st_goodsDetailInfosaleDetails.strGoodsCode = goodsInfo.sCode;//商品编码id
//        saleDetails.st_goodsDetailInfosaleDetails.sGoodsName = goodsInfo.sName;//商品名字
//        saleDetails.st_goodsDetailInfosaleDetails.strGoodsShortName = goodsInfo.sShortName;//商品简称
//    //    saleDetails.fPrice;//显示单价
//    //    saleDetails.fNumber;//销售数量
//    //    saleDetails.sSumPrice = ;//显示总价
//        saleDetails.st_goodsDetailInfo.sUnit = goodsInfo.sSaleUnit;//单位
//        saleDetails.st_goodsDetailInfo.bPromotion = goodsInfo.bPromotion;//是否促销
//        saleDetails.st_goodsDetailInfo.bDisCount; // 是否折扣
//    //    saleDetails.bRefund; // 是否退货
//    //    saleDetails.nTasteType;//商品口味分级
//        saleDetails.st_goodsDetailInfo.bStandard = goodsInfo.bStandard;//商品类型
//        saleDetails.st_goodsDetailInfo.nCategoryId = goodsInfo.nCategoryId;//商品分类id
//        saleDetails.st_goodsDetailInfo.fRefundPrice = goodsInfo.fPrice;//退款金额
//    //    saleDetails.fRefundNumber = ;//退款数量
//        saleDetails.st_goodsDetailInfo.sRefundSumPrice = QString::number(saleDetails.fRefundNumber * goodsInfo.fPrice, 'f', 2);//退款总价
//        //    saleDetails.bSelectStatus;//商品选中状态
}

//int SellRefundCtr::createNewOrderNumber()
//{
//    QString strSerialNum = QString::number(KPosIni::getSerialNum());
//    if( strSerialNum.size() <= 5 ) {
//        int n = 5 - strSerialNum.size();
//        for( int i = 0; i < n; ++i ) {
//            strSerialNum = "0" + strSerialNum;
//        }
//    }
//    return KPosIni::getPosCode() + QDateTime::currentDateTime().toString("yyMMdd") + strSerialNum;
//}

//int SellRefundCtr::createNewSaleHeadId()
//{
//    return SaleHeadAgent::Instance()->getLastSaleHeadId() + 1;
//}

