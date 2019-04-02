#include "GoodsRefundListWidget.h"
#include "ui_GoodsRefundListWidget.h"
#include "../Agent/SaleDetailsAgent.h"
#include "../Agent/SaleHeadAgent.h"
#include "../Agent/LoginKPosAgent.h"
#include "../Agent/SatementAgent.h"
#include "../util/KPosIni.h"
#include "../util/CommonFun.h"
#include "../data/constData.h"
#include "KPosServerIni.h"
#include <QMessageBox>
#include <QDebug>

GoodsRefundListWidget::GoodsRefundListWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GoodsRefundListWidget)
    , m_nOnePageCount(5)
    , m_nCurPage(1)
    , m_nTotalPage(1)
    , m_pModifyGoodsNumDlg(NULL)
    , m_bMemSell(false)
    , m_bReceipRefund(false)
    , m_pSaleCtrl(NULL)
    , m_fIntegralPayMoney(0.0f)
    , m_nIntegralPay(0)
{
    ui->setupUi(this);
    initConnect();
    ui->lastPageButton->setEnabled(false);
    ui->nextPageButton->setEnabled(false);
}

GoodsRefundListWidget::~GoodsRefundListWidget()
{
    delete ui;
}

void GoodsRefundListWidget::initCtrl(SaleCtrl *pSaleCtrl)
{
    if (m_pSaleCtrl == NULL)
    {
        m_pSaleCtrl = pSaleCtrl;
    }
}

void GoodsRefundListWidget::initData(const SaleHead &saleHead, const QList<SaleDetails> &saleDetailsList, float fIntegralPayMoney, int nIntegralPay)
{
    m_fIntegralPayMoney = fIntegralPayMoney;
    m_nIntegralPay = nIntegralPay;
    m_bReceipRefund = true;
    m_saleHead = saleHead;
    converToReceiptRefundSaleHead(m_saleHead);
    m_saleDetailsList = saleDetailsList;
    int nLen = m_saleDetailsList.length();
    SaleHeadAgent::Instance()->insertSaleHeadTable(m_saleHead);
    for (int i = 0; i < nLen; i++)
    {
        m_saleDetailsList[i].goodsInfo.fPrice = m_saleDetailsList[i].fSwapPrice;
        m_saleDetailsList[i].goodsInfo.sSumPrice = CommonFun::handleMoneyCoin(m_saleDetailsList[i].strSwapAmt.toFloat());
        m_saleDetailsList[i].goodsInfo.fRefundPrice = m_saleDetailsList[i].fSwapPrice;
        m_saleDetailsList[i].goodsInfo.fRefundNumber = 0.0f;
        m_saleDetailsList[i].goodsInfo.sRefundSumPrice = "";
        m_saleDetailsList[i].strSwapAmt = "";
        m_saleDetailsList[i].nSaleDetailPos = SaleDetailsAgent::Instance()->getLastSaleDetailsPos() + 1 + i;
        m_saleDetailsList[i].goodsInfo.nSaleDetailPos = m_saleDetailsList[i].nSaleDetailPos;
        m_saleDetailsList[i].strOrderNum = m_saleHead.strOrderNum;
        m_saleDetailsList[i].nStatus = c_nFinishSaleGoods;
//        SaleDetailsAgent::Instance()->insertSaleDetailsTable(m_saleDetailsList[i]);
    }
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    m_nCurPage = m_nTotalPage;
    checkCurPageButtonState();
    generateUI();
}

void GoodsRefundListWidget::appendData(const GoodsInfo &goodsInfo, float fNumber)
{ 
    m_bReceipRefund = false;

    if(m_saleDetailsList.count() < 1)
    {
        initSaleHead("");
        SaleHeadAgent::Instance()->insertSaleHeadTable(m_saleHead);
    }

    int nFindPos = -1;

    if (goodsInfo.bStandard &&goodsInfo.sCode != "9999999")
    {
        int nLen = m_saleDetailsList.length();
        for (int i = 0; i < nLen; i++)
        {
            if (m_saleDetailsList[i].goodsInfo.nGoodsId == goodsInfo.nId)
            {
                nFindPos = i;
                break;
            }
        }
        if (nFindPos >= 0)
        {
            m_saleDetailsList[nFindPos].goodsInfo.fRefundNumber--;
            m_saleHead.fOughtAmt -= m_saleDetailsList[nFindPos].goodsInfo.fRefundPrice; // 累加算总价
            m_nCurPage = nFindPos / m_nOnePageCount + ((nFindPos % m_nOnePageCount == 0) ? 0 : 1);
//            SaleDetailsAgent::Instance()->insertSaleDetailsTable(m_saleDetailsList[nFindPos]);
        }
    }

    if (nFindPos < 0) // 非标品,大码商品或新的标品直接添加
    {
        SaleDetails saleDetails;
        saleDetails.goodsInfo.fRefundNumber = -fNumber;
        if (goodsInfo.bStandard)
        {
            saleDetails.goodsInfo.fRefundNumber = -1;
        }
        saleDetails.nSaleDetailPos = SaleDetailsAgent::Instance()->getLastSaleDetailsPos() + 1;
        noReceiptGoodsToSaleDetail(saleDetails, goodsInfo);
//        m_saleHead.fOughtAmt += saleDetails.goodsInfo.fRefundNumber * saleDetails.goodsInfo.fRefundPrice; // 累加算总价
        //加入数据库
//        SaleDetailsAgent::Instance()->insertSaleDetailsTable(saleDetails);

        m_saleDetailsList.append(saleDetails);
        int nLen = m_saleDetailsList.length();
        m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
        m_nCurPage = m_nTotalPage;
    }

    checkCurPageButtonState();
    generateUI();
}

QList<int> GoodsRefundListWidget::getSelectIdList()
{
    return ui->listView->getSelectIdList();
}

int GoodsRefundListWidget::getSaleDetailsListLengh()
{
    return m_saleDetailsList.length();
}

void GoodsRefundListWidget::modifyRefundGoodsNum()
{
    QList<int> selectIdList = getSelectIdList();
    if (selectIdList.length() > 0)
    {
        int nLen = m_saleDetailsList.length();
        for (int i = 0; i < nLen; i++)
        {
            if (m_saleDetailsList[i].nSaleDetailPos == selectIdList[0])
            {
                if (m_pModifyGoodsNumDlg == NULL)
                {
                    m_pModifyGoodsNumDlg = new ModifyGoodsNumDlg;
                    connect(m_pModifyGoodsNumDlg, SIGNAL(sig_modifyGoodsNum(int,QString)), this, SLOT(slot_modifyGoodsNum(int,QString)));
                }
                GoodsDetailInfo stGoodsDetailsInfo = m_saleDetailsList[i].goodsInfo;
                stGoodsDetailsInfo.fNumber = -m_saleDetailsList[i].goodsInfo.fRefundNumber;
                m_pModifyGoodsNumDlg->setGoodsDetailInfo(stGoodsDetailsInfo);
                m_pModifyGoodsNumDlg->exec();
                return;
            }
        }
    }
}

void GoodsRefundListWidget::refundGoods()
{
    QList<int> selectIdList = getSelectIdList();
    if (selectIdList.length() > 0)
    {
        int nLen = m_saleDetailsList.length();
        for (int i = 0; i < nLen; i++)
        {
            if (selectIdList.contains(m_saleDetailsList[i].nSaleDetailPos))
            {
                m_saleDetailsList[i].goodsInfo.fRefundNumber = -m_saleDetailsList[i].goodsInfo.fNumber;
//                m_saleDetailsList[i].goodsInfo.sRefundSumPrice = QString("-%1").arg(m_saleDetailsList[i].goodsInfo.sSumPrice);
            }
        }
        generateUI();
    }
}

void GoodsRefundListWidget::refundAllGoods()
{
    int nLen = m_saleDetailsList.length();
    for (int i = 0; i < nLen; i++)
    {
        m_saleDetailsList[i].goodsInfo.fRefundNumber = -m_saleDetailsList[i].goodsInfo.fNumber;
//        m_saleDetailsList[i].goodsInfo.sRefundSumPrice = QString("-%1").arg(m_saleDetailsList[i].goodsInfo.sSumPrice);

    }
    generateUI();
}

int GoodsRefundListWidget::removeSelectGoods()
{
    QList<int> selectIdList = getSelectIdList();
    if (selectIdList.length() > 0)
    {
        ui->listView->clearSelectIdList();

        int nLen = m_saleDetailsList.length();
        for (int i = nLen - 1; i >= 0; i--)
        {
            if (selectIdList.contains(m_saleDetailsList[i].nSaleDetailPos))
            {
                m_saleDetailsList[i].nStatus = c_nCancelSaleGoods;
                m_saleHead.fOughtAmt -= m_saleDetailsList[i].goodsInfo.fRefundNumber * m_saleDetailsList[i].goodsInfo.fRefundPrice; // 累加算总价
                SaleDetailsAgent::Instance()->insertSaleDetailsTable(m_saleDetailsList[i]);
                m_saleDetailsList.removeAt(i);
            }
        }
        nLen = m_saleDetailsList.length();
        m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
        if (m_nTotalPage <= 0)
        {
            m_nTotalPage = 1;
        }
        checkCurPageButtonState();
        generateUI();
    }

    if (m_saleDetailsList.length() == 0)
    {
        m_saleHead.nStatus = e_headCancel;
        SaleHeadAgent::Instance()->insertSaleHeadTable(m_saleHead);
    }

    return m_saleDetailsList.length();
}

void GoodsRefundListWidget::clearAllGoods()
{
    if (m_saleDetailsList.length() > 0)
    {
        int nLen = m_saleDetailsList.length();
        if (m_saleHead.nStatus != e_headComplete)
        {
            for (int i = 0; i < nLen; i++)
            {
                m_saleHead.fOughtAmt = 0.0f; // 累加算总价
                m_saleDetailsList[i].nStatus = c_nCancelSaleGoods;
                SaleDetailsAgent::Instance()->insertSaleDetailsTable(m_saleDetailsList[i]);
            }
            m_saleHead.nStatus = e_headCancel;
            SaleHeadAgent::Instance()->insertSaleHeadTable(m_saleHead);
        }

        ui->listView->clearSelectIdList();
        m_saleDetailsList.clear();
        m_nCurPage = 1;
        m_nTotalPage = 1;
        checkCurPageButtonState();
        ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
        ui->listView->clearItems();
    }
}

void GoodsRefundListWidget::setMemStatus(bool bMemStatus)
{
    m_bMemSell = bMemStatus;
}

bool GoodsRefundListWidget::getMemStatus()
{
    return m_bMemSell;
}

float GoodsRefundListWidget::getRefundCash()
{
//    QString str = CommonFun::handleCash(m_saleHead.fOughtAmt, eRounding);
//    m_saleHead.fOughtAmt = str.toFloat();
    return m_saleHead.fFactorAmt;
}

bool GoodsRefundListWidget::isMemberRefund()
{
    return (!m_saleHead.strMemCardId.isEmpty());
}

float GoodsRefundListWidget::getIntegralPayMoney()
{
    float fMoney = 0.0f;
    if (m_nIntegralPay == 0)
    {
        if (m_pSaleCtrl != NULL && (!m_saleHead.strMemCardId.isEmpty()))
        {
            m_pSaleCtrl->getIntegralPayMoney(fMoney, m_saleHead.strReturnOrderNum);
        }
    }
    else
    {
       fMoney = m_fIntegralPayMoney;
    }

    return -fMoney;
}

int GoodsRefundListWidget::getPayIntegral()
{
    int nIntegral = 0;
    if (m_nIntegralPay == 0)
    {
        if (m_pSaleCtrl != NULL && (!m_saleHead.strMemCardId.isEmpty()))
        {
            m_pSaleCtrl->getPayIntegral(nIntegral, m_saleHead.strReturnOrderNum);
        }
    }
    else
    {
       nIntegral = m_nIntegralPay;
    }

    return -nIntegral;
}

void GoodsRefundListWidget::confirmRefund(int reasonId, MemRegisterInfo_s memRegInfo)
{
    float fIntegralMoney = getIntegralPayMoney();
    int nIntegralPay = getPayIntegral();
    float fFactorMoney = 0.0f;

    PayDetail_s payDetails;
    payDetails.strOrderNum = m_saleHead.strOrderNum;//小票单号
    payDetails.strPaymentOrderNum = KPosIni::getPosCode() + QDateTime::currentDateTime().toString("yyMMddhhmmss");//支付单号（现金支付单号：pos号+时间yyMMddhhmmss)
    payDetails.nPayMethod = PayCash;//支付方式
    payDetails.fPayMoney = CommonFun::handleCash(m_saleHead.fFactorAmt - fIntegralMoney).toFloat();//支付金额
    fFactorMoney += payDetails.fPayMoney;
    payDetails.nPayIntegral = 0;//支付积分
    payDetails.nStatus = e_PayRefund;//支付状态
    payDetails.fIntToAmt = 0.0f;//积分抵现
    payDetails.nPayType = e_Refund;//支付类型1：付款  2：退款
    payDetails.bVirtual = false;//虚拟支付
    payDetails.dtCreate = QDateTime::currentDateTime();//创建时间
    payDetails.dtComplete = payDetails.dtCreate;//完成时间
    payDetails.strComment = "";//备注信息
    payDetails.strIntExchangeAmt = "";//1积分抵价
    payDetails.strAuthCode = "";//支付授权码
    SatementAgent::Instance()->insertPayDetailData(payDetails);
    QList<PayDetail_s> payDetailsList;
    payDetailsList.append(payDetails);
    if (fIntegralMoney != 0)
    {
        payDetails.nPayMethod = IntegralToCansh;
        payDetails.fPayMoney = fIntegralMoney;
        fFactorMoney += payDetails.fPayMoney;
        payDetails.nPayIntegral = nIntegralPay;
        SatementAgent::Instance()->insertPayDetailData(payDetails);
        payDetailsList.append(payDetails);
    }

    m_saleHead.fFactorAmt = fFactorMoney;
    m_saleHead.fProfitLoss = m_saleHead.fFactorAmt - m_saleHead.fOughtAmt;

    m_saleHead.nSaleTotalNum = m_saleDetailsList.length();
    m_saleHead.strReturnReason = QString::number(reasonId);
    m_saleHead.nStatus = e_headComplete;
    m_saleHead.fOddChange = 0.0f;
    SaleHeadAgent::Instance()->insertSaleHeadTable(m_saleHead);

    if (m_pSaleCtrl != NULL)
    {
        m_pSaleCtrl->printRefundReceipt(m_saleHead.strOrderNum, m_saleHead, m_saleDetailsList, payDetailsList, memRegInfo);
        if (!m_saleHead.strMemCardId.isEmpty())
        {
            m_pSaleCtrl->updateMemberIntegralRequest(m_saleHead.fFactorAmt - fIntegralMoney, m_saleHead.strMemCardId
                                             , m_saleHead.strReturnOrderNum, m_saleHead.strOrderNum);
        }
    }

    clearAllGoods();

    m_fIntegralPayMoney = 0.0f;
    m_nIntegralPay = 0;
}

void GoodsRefundListWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void GoodsRefundListWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void GoodsRefundListWidget::slot_modifyGoodsNum(int nSaleDetailPos, QString strGoodsNum)
{
    int nLen = m_saleDetailsList.length();
    for (int i = 0; i < nLen; i++)
    {
        SaleDetails& saleDetails = m_saleDetailsList[i];
        if (saleDetails.nSaleDetailPos == nSaleDetailPos)
        {
            saleDetails.goodsInfo.fRefundNumber = -strGoodsNum.toFloat();
            if ((!saleDetails.goodsInfo.sSumPrice.isEmpty()) // 有小票
                    && (-saleDetails.goodsInfo.fRefundNumber > saleDetails.goodsInfo.fNumber))
            {
                saleDetails.goodsInfo.fRefundNumber = -saleDetails.goodsInfo.fNumber;
            }

//            float fSumPrice = saleDetails.goodsInfo.fRefundNumber * saleDetails.goodsInfo.fRefundPrice;
//            saleDetails.goodsInfo.sRefundSumPrice = QString::number(fSumPrice, 'f', 2);
            generateUI();
            return;
        }
    } 
}

void GoodsRefundListWidget::generateUI()
{
    updateData();

    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_saleDetailsList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        m_saleDetailsList[i].goodsInfo.nPos = i + 1;
        ui->listView->appendItem(m_saleDetailsList[i].goodsInfo);
    }
}

void GoodsRefundListWidget::checkCurPageButtonState()
{
    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        ui->lastPageButton->setEnabled(false);
    }
    else
    {
        ui->lastPageButton->setEnabled(true);
    }

    if (m_nCurPage < m_nTotalPage)
    {
        ui->nextPageButton->setEnabled(true);
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        ui->nextPageButton->setEnabled(false);
    }
}

void GoodsRefundListWidget::noReceiptGoodsToSaleDetail(SaleDetails &saleDetails, const GoodsInfo &goodsInfo)
{
//    saleDetails.nSaleDetailPos; //销售明细id
    saleDetails.strOrderNum = m_saleHead.strOrderNum;     //单号
    saleDetails.strBarCode = goodsInfo.sBarCode;   //商品条码
    saleDetails.strGoodsName = goodsInfo.sName;     //商品名称
    saleDetails.nGoodsId = goodsInfo.nId;         //商品id

    saleDetails.strGoodsSpec = goodsInfo.sSaleUnit;       //商品规格
    saleDetails.fSwapPrice = 0.0f;     //实际成交单价
    saleDetails.strSwapAmt = "";    //实际成交金额
    saleDetails.fPopDisAmt = 0.0f;    //促销折扣
    saleDetails.fPopDisRate = 10.0f;   //促销折扣率,8折

    saleDetails.fGrantDisRate = 10.0f;//临时折扣率
    saleDetails.fAllDisAmt = 0.0f;   //所有优惠金额
    saleDetails.fTaxRate = 0.0f;       //税率
    saleDetails.strInpBarCode = "";  //扫描条码
    saleDetails.strBatchNo = "";   //促销活动号（SJ使用中）

    saleDetails.strPromPrice = ""; //促销改价单号
    saleDetails.dtCreateTime = QDateTime::currentDateTime();;//创建时间
    saleDetails.nStatus = c_nFinishSaleGoods/*e_headSelling*/;//正在进行，取消，完成
    saleDetails.fPrice = goodsInfo.fPrice;//原单价
    saleDetails.fMemPrice = goodsInfo.fMemberPrice; //会员价

    saleDetails.strOrgSum = "";//原总金额
    saleDetails.strOrgMemSum = "";//原会员价总金额

    saleDetails.goodsInfo.nPos = -1;//列表序号
    saleDetails.goodsInfo.nSaleDetailPos = saleDetails.nSaleDetailPos;//销售明细序号
    saleDetails.goodsInfo.nGoodsId = goodsInfo.nId; //商品id
    saleDetails.goodsInfo.strGoodsCode = goodsInfo.sBarCode;//商品编码id
    saleDetails.goodsInfo.sGoodsName = goodsInfo.sName;//商品名字
    saleDetails.goodsInfo.strGoodsShortName = goodsInfo.sShortName;//商品简称
    saleDetails.goodsInfo.fPrice = goodsInfo.fPrice;//显示单价
    saleDetails.goodsInfo.fNumber = 0.0f;//销售数量
    saleDetails.goodsInfo.sSumPrice = "";//显示总价
    saleDetails.goodsInfo.sUnit = goodsInfo.sSaleUnit;//单位
    saleDetails.goodsInfo.bPromotion = goodsInfo.bPromotion;//是否促销
    saleDetails.goodsInfo.bDisCount = false; // 是否折扣
//    saleDetails.goodsInfo.bRefund = false; // 是否退货
//    saleDetails.goodsInfo.nTasteType = -1;//商品口味分级
    saleDetails.goodsInfo.bStandard = goodsInfo.bStandard;//商品类型
    saleDetails.goodsInfo.nCategoryId = goodsInfo.nCategoryId;//商品分类id
    saleDetails.goodsInfo.fRefundPrice = goodsInfo.fPrice;//退款金额
//    saleDetails.goodsInfo.fRefundNumber;//退款数量
//    saleDetails.goodsInfo.sRefundSumPrice = QString::number(saleDetails.goodsInfo.fRefundPrice*saleDetails.goodsInfo.fRefundNumber, 'f', 2);//退款总价
//    saleDetails.goodsInfo.bSelectStatus;//商品选中状态
    saleDetails.strLog = "";        //日志
}

void GoodsRefundListWidget::initSaleHead(QString sReturnOrderNum)
{
    QString sSerialNum = KPosIni::getSerialNum();
    m_saleHead.nSerialNum = sSerialNum.toInt();

    m_saleHead.nSaleHeadId = SaleHeadAgent::Instance()->getLastSaleHeadId() + 1;
    m_saleHead.dtCreateTime = QDateTime::currentDateTime();
    m_saleHead.strPosId = KPosIni::getPosCode();
    QString strDateTime = QDateTime::currentDateTime().toString( "yyMMdd" );

    m_saleHead.strOrderNum = m_saleHead.strPosId + strDateTime + sSerialNum;
    m_saleHead.nSaleTotalNum = 0;
    m_saleHead.fOughtAmt = 0.00;
    m_saleHead.fFactorAmt = 0.00;
    m_saleHead.fOddChange = 0.00;
    m_saleHead.strMemCardId = "";
    m_saleHead.nMemInteger = 0;

    m_saleHead.strDisReason = "";
    m_saleHead.fGrantDisRate = 0.0;
    m_saleHead.fAllDisAmt = 0.00;
    m_saleHead.fProfitLoss = 0.00;
    m_saleHead.nStatus = e_headSelling;//交易状态:正在进行，挂单，完成，取消

    m_saleHead.nType = 0;//购物类型:0.现购，1.网购，2.团购
    m_saleHead.nShopId = KPosIni::getShopId();//门店编号
    m_saleHead.eUploadStatus = eNotUpload;//上传总部状态
    m_saleHead.dtCreateTime = QDateTime::currentDateTime();//创建时间
    m_saleHead.dtFactorTime = m_saleHead.dtCreateTime;//实际交易时间
    m_saleHead.nCostTime = 0;//交易花费时间
    m_saleHead.dtCompleteTime = m_saleHead.dtCreateTime;//交易完成时间

    SalemanInfo stSaleman = LoginKPosAgent::instance()->getLoginKPosInfo().salemanInfo;
    m_saleHead.nCashierId = stSaleman.nUserId;//收款员编号
    m_saleHead.strCashierName = stSaleman.sUsername;//收款员姓名

    m_saleHead.nTranStatus = 0;
    m_saleHead.nSaleType = 1; // 退货小票
    m_saleHead.strReturnOrderNum = sReturnOrderNum;
    m_saleHead.strReturnReason = "";
    m_saleHead.nSaleMode = 1;//销售方式:默认为Kpos销售
    m_saleHead.strLog = "";
}

void GoodsRefundListWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigClickItem()), this, SIGNAL(sigClickItem()));
}

void GoodsRefundListWidget::converToReceiptRefundSaleHead(SaleHead &saleHead)
{
    QString sSerialNum = KPosIni::getSerialNum();
    saleHead.nSerialNum = sSerialNum.toInt();

    int nLastSaleHeadId = SaleHeadAgent::Instance()->getLastSaleHeadId() + 1;
    saleHead.nSaleHeadId = nLastSaleHeadId;//销售id

    saleHead.strPosId = KPosIni::getPosCode();//款机号
    QString strDateTime = QDateTime::currentDateTime().toString( "yyMMdd" );

    saleHead.strOrderNum = saleHead.strPosId + strDateTime + sSerialNum;//单号（pos号+日期YYMMDD+流水号）

    saleHead.fCouponDisAmt = -saleHead.fCouponDisAmt;
    saleHead.sSmallChangeAmt = QString::number(-saleHead.sSmallChangeAmt.toFloat());

//    saleHead.nSaleTotalNum;//商品总数

//    saleHead.fOughtAmt;//应付金额 // 应该服务器或本地数据库给
//    saleHead.fFactorAmt;//实付金额：// 应该服务器或本地数据库给
//    saleHead.fOddChange;//找零 // 应该服务器或本地数据库给
//    saleHead.strMemCardId;//会员卡号 // 应该服务器或本地数据库给
//    saleHead.nMemInteger;//会员积分 //

//    saleHead.strDisReason;//折扣原因 // 应该服务器或本地数据库给
//    saleHead.fGrantDisRate;//临时折扣率 // 应该服务器或本地数据库给
    saleHead.fAllDisAmt = -saleHead.fAllDisAmt;//所有优惠金额 // 应该服务器或本地数据库给
//    saleHead.fProfitLoss;//收银损益(实际支付的钱- 找零-应付金额) // 应该服务器或本地数据库给
    saleHead.nStatus = e_headSelling;//交易状态:1:完成，-1:取消【已退款】 2:正在进行，3:挂单，

//    saleHead.nType = 0;//购物类型:0.现购，1.网购，2.团购 // 应该服务器或本地数据库给
    saleHead.nShopId = KPosIni::getShopId();//门店编号
    saleHead.eUploadStatus = eNotUpload;//上传总部状态
    saleHead.dtCreateTime = QDateTime::currentDateTime();//创建时间
    saleHead.dtFactorTime = saleHead.dtCreateTime;//实际交易时间

    saleHead.nCostTime = 0;//交易花费时间= saleHead.dtCompleteTime-saleHead.dtFactorTime
    saleHead.dtCompleteTime = saleHead.dtCreateTime;//交易完成时间
//    saleHead.dtReceiptUpload = saleHead.dtCreateTime;//小票上传时间 // 由后台自己赋值
    saleHead.nCashierId = LoginKPosAgent::instance()->getLoginKPosInfo().salemanInfo.nUserId;//收款员编号
    saleHead.strCashierName = LoginKPosAgent::instance()->getLoginKPosInfo().salemanInfo.sUsername;//收款员姓名

//    saleHead.nTranStatus;//交易状态:-1.取消，0.正在进行，1.完成 // 以后不要了
    saleHead.nSaleType = 1;//销售类型：0.销售小票，1.退货小票，2.会员充值，3.储值卡充值，4.退充值，5.取消小票
//    saleHead.strReturnOrderNum; //退货订单号 // Http中赋值
    saleHead.strReturnReason = ""; //退货原因
    saleHead.nSaleMode = 1; //销售方式：：1.KeyPos，2.待定
    saleHead.strLog = "";
}

void GoodsRefundListWidget::updateData()
{
    int nCount = m_saleDetailsList.length();
    m_saleHead.fOughtAmt = 0.0f;
//    float fMemberDis = 0.0f;
    for (int i = 0; i < nCount; i++)
    {
        float fSumPrice = 0.0f;
        if (-m_saleDetailsList[i].goodsInfo.fRefundNumber > 0.001f)
        {
            fSumPrice = m_saleDetailsList[i].goodsInfo.fRefundPrice * m_saleDetailsList[i].goodsInfo.fRefundNumber;
//            qDebug()<<"ccccc "<<fSumPrice;
            fSumPrice = CommonFun::handleMoneyCoin(fSumPrice).toFloat();
//            qDebug()<<"dddddd "<<fSumPrice;
            m_saleDetailsList[i].goodsInfo.sRefundSumPrice = QString::number(fSumPrice);
            m_saleDetailsList[i].strSwapAmt = m_saleDetailsList[i].goodsInfo.sRefundSumPrice;
        }
        else
        {
            m_saleDetailsList[i].goodsInfo.sRefundSumPrice = "";
            m_saleDetailsList[i].strSwapAmt = "";
        }
//        if ((m_saleDetailsList[i].fPrice - m_saleDetailsList[i].goodsInfo.fRefundPrice > 0.000001f)
//                || (m_saleDetailsList[i].goodsInfo.fRefundPrice - m_saleDetailsList[i].fPrice> 0.000001f))
//        {
//            fMemberDis += (m_saleDetailsList[i].fPrice - m_saleDetailsList[i].goodsInfo.fRefundPrice) * m_saleDetailsList[i].goodsInfo.fNumber;
//            fMemberDis = CommonFun::handleMoneyCoin(fMemberDis).toFloat();
//        }

        SaleDetailsAgent::Instance()->insertSaleDetailsTable(m_saleDetailsList[i]);
        m_saleHead.fOughtAmt += fSumPrice;
    }

//    m_saleHead.fOughtAmt -= m_saleHead.fAllDisAmt + fMemberDis;
    m_saleHead.fAllDisAmt = m_saleHead.fCouponDisAmt + m_saleHead.sSmallChangeAmt.toFloat();
    m_saleHead.fFactorAmt = m_saleHead.fOughtAmt - m_saleHead.fAllDisAmt;

//    SaleHeadAgent::Instance()->insertSaleHeadTable(m_saleHead);
    emit sigUpdateSumPrice(QString::number(m_saleHead.fFactorAmt,'f',2), QString::number(m_saleHead.fAllDisAmt, 'f', 2));
}


