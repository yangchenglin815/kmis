#include "ReceiptPictureMaker.h"
#include <QPen>
#include <QBrush>
#include <QDebug>
#include <QDateTime>
#include "../util/FilePathManage.h"
#include "../util/KPosServerIni.h"
#include "../util/KPosIni.h"
#include "../util/EnumToString.h"
#include "../util/KPosServerIni.h"
#include "../data/constData.h"
#include "../data/adjustpricedata.h"
#include "../data/enumData.h"
#include "ZIntDll.h"
#include "BalanceManage.h"
#include "CommonFun.h"

//const int m_nRealWidth = 174; // 效果图的实际宽度
//const int m_nZoomWidth = 450; // 打印机的缩放宽度， 打印机的dll会将450的图片缩放到174大小

const int c_nFontSize1 = 28;
const int c_nFontSize2 = 12;
const int c_nFontSize3 = 10;

ReceiptPictureMaker* ReceiptPictureMaker::m_pInstance = NULL;
ReceiptSet ReceiptPictureMaker::m_receiptSet;

const QString c_sFontFamily = "黑体";

ReceiptPictureMaker::ReceiptPictureMaker()
    : m_nLeftXPos(6)
    , m_nPictureMaxHeight(1200)
    , m_pPainter(NULL)
    , m_pPixmap(NULL)
    , m_nSequence(0)
    , m_nZoomWidth(450) // 打印机的缩放宽度， 打印机的dll会将450的图片缩放到174大小
    , m_nRealWidth(174) // 效果图的实际宽度
    , m_nPaintWidth(m_nRealWidth - 2*m_nLeftXPos)
{
    m_nPictureMaxHeight = KPosServerIni::getReceiptHeight();
    m_nZoomWidth = KPosServerIni::getReceiptZoomWidth();
    m_nRealWidth = KPosServerIni::getReceiptRealWidth();
    m_nLeftXPos = m_nLeftXPos * m_nZoomWidth / m_nRealWidth;
    m_nPaintWidth = m_nZoomWidth - 2 * m_nLeftXPos;
}

ReceiptPictureMaker *ReceiptPictureMaker::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new ReceiptPictureMaker;
    }
    return m_pInstance;
}

void ReceiptPictureMaker::setReceiptPrintOption(const ReceiptSet &receiptSet)
{
    m_receiptSet = receiptSet;
}

void ReceiptPictureMaker::printReceipt(const ReceiptPrintData &receiptPrintData)
{
    m_receiptPrintData = receiptPrintData;

    ZIntDll::createReceiptBarCode(m_receiptPrintData.sBarcode);
    beginPrint();

    const int nXPos = m_nLeftXPos;
    const int nTopSpace = 16;
    int nYPos = nTopSpace;

    paintBarCode(nXPos, nYPos);
    paintHeadContent(nXPos, nYPos);
    paintHeadWords(nXPos, nYPos);
    paintShopInfo(nXPos, nYPos);
    paintSaleGoodsInfoList(nXPos, nYPos);
    paintCategoryCountList(nXPos, nYPos);
    paintSettlementInfo(nXPos, nYPos);
    paintSettleTypeCount(nXPos, nYPos);
    paintMemberInfo(nXPos, nYPos);
    paintTailContent(nXPos, nYPos);
    if (KPosServerIni::getKPosUserType() == e_tianMaoVersion)
    {
        paintQRCode(nXPos, nYPos);
    }

    const int bottomSpace = 30 * m_nZoomWidth / m_nRealWidth;
    nYPos += bottomSpace;
    printDashLine(nXPos, nYPos); // 剪裁分割线
    nYPos += bottomSpace;

    savePixmap(nYPos);
    m_pPainter->end();
    delete m_pPainter;
    m_pPainter = NULL;
    delete m_pPixmap;
    m_pPixmap = NULL;

    printReceipt();
}

void ReceiptPictureMaker::printMemRechargeReceipt(const MemRechargePrintInfo &stMemRechargePrintInfo )
{
    m_stMemRechargePrintInfo = stMemRechargePrintInfo;
    beginPrint();

    const int nXPos = m_nLeftXPos;
    const int nTopSpace = 16;
    int nYPos = nTopSpace;

    //paintMemHeadWords(nXPos, nYPos);
    paintMemHeadContent(nXPos, nYPos);
    paintMemShopInfo(nXPos, nYPos);
    paintRechargeMemInfo(nXPos, nYPos);
    paintRechargeInfo(nXPos, nYPos);
    paintMemSigned( nXPos, nYPos );

    const int bottomSpace = 30 * m_nZoomWidth / m_nRealWidth;
    nYPos += bottomSpace;
    printDashLine(nXPos, nYPos); // 剪裁分割线
    nYPos += bottomSpace;

    savePixmap(nYPos);
    m_pPainter->end();
    delete m_pPainter;
    m_pPainter = NULL;
    delete m_pPixmap;
    m_pPixmap = NULL;

    printReceipt();
}

void ReceiptPictureMaker::printAdjustPriceInfoReceipt(const AdjustPricePrintData &adjustPricePrintData)
{
    m_adjustPricePrintData = adjustPricePrintData;

    beginPrint();

    const int nXPos = m_nLeftXPos;
    const int nTopSpace = 16;
    int nYPos = nTopSpace;

    paintAdjustPriceTopInfo(nXPos, nYPos); // 打印门店信息
    paintAdjustPriceGoodsList(nXPos, nYPos); // 打印改价商品列表
    paintAdjustEndInfo(nXPos, nYPos); // 打印结尾信息

    const int bottomSpace = 30 * m_nZoomWidth / m_nRealWidth;
    nYPos += bottomSpace;
    printDashLine(nXPos, nYPos); // 剪裁分割线
    nYPos += bottomSpace;

    savePixmap(nYPos);
    m_pPainter->end();
    delete m_pPainter;
    m_pPainter = NULL;
    delete m_pPixmap;
    m_pPixmap = NULL;

    printReceipt();
}

void ReceiptPictureMaker::printReportLossInfoReceipt(const ReportLossPrintData &reportLossPrintData)
{
    m_reportLossPrintData = reportLossPrintData;

    beginPrint();

    const int nXPos = m_nLeftXPos;
    const int nTopSpace = 16;
    int nYPos = nTopSpace;

    paintReportLossTopInfo(nXPos, nYPos); // 打印门店信息
    paintReportLossListInfo(nXPos, nYPos); // 打印改价商品列表
    paintReportLossEndInfo(nXPos, nYPos); // 打印结尾信息

    const int bottomSpace = 30 * m_nZoomWidth / m_nRealWidth;
    nYPos += bottomSpace;
    printDashLine(nXPos, nYPos); // 剪裁分割线
    nYPos += bottomSpace;

    savePixmap(nYPos);
    m_pPainter->end();
    delete m_pPainter;
    m_pPainter = NULL;
    delete m_pPixmap;
    m_pPixmap = NULL;

    printReceipt();
}

void ReceiptPictureMaker::printAllStockInfoReceipt(const StockPrintData &stockPrintData)
{
    m_stockPrintData = stockPrintData;

    beginPrint();

    const int nXPos = m_nLeftXPos;
    const int nTopSpace = 16;
    int nYPos = nTopSpace;

    paintStockTopInfo(nXPos, nYPos); // 打印门店信息
    paintAllStockGoodsList(nXPos, nYPos); // 打印盘点商品列表
    paintStockEndInfo(nXPos, nYPos); // 打印结尾信息

    const int bottomSpace = 30 * m_nZoomWidth / m_nRealWidth;
    nYPos += bottomSpace;
    printDashLine(nXPos, nYPos); // 剪裁分割线
    nYPos += bottomSpace;

    savePixmap(nYPos);
    m_pPainter->end();
    delete m_pPainter;
    m_pPainter = NULL;
    delete m_pPixmap;
    m_pPixmap = NULL;

    printReceipt();
}

void ReceiptPictureMaker::printInStockInfoReceipt(const InStockPrintData &stockPrintData)
{
    m_instockPrintData = stockPrintData;
    qDebug()<<"186-inprint";
    beginPrint();

    const int nXPos = m_nLeftXPos;
    const int nTopSpace = 16;
    int nYPos = nTopSpace;

    paintInStockTopInfo(nXPos, nYPos); // 打印门店信息
    paintInStockGoodsList(nXPos, nYPos); // 打印盘点商品列表
    paintInStockEndInfo(nXPos, nYPos); // 打印结尾信息

    const int bottomSpace = 30 * m_nZoomWidth / m_nRealWidth;
    nYPos += bottomSpace;
    printDashLine(nXPos, nYPos); // 剪裁分割线
    nYPos += bottomSpace;

    savePixmap(nYPos);
    m_pPainter->end();
    delete m_pPainter;
    m_pPainter = NULL;
    delete m_pPixmap;
    m_pPixmap = NULL;

    printReceipt();
}

void ReceiptPictureMaker::printOutStockInfoReceipt(const OutStockPrintData &stockPrintData)
{

    m_outstockPrintData = stockPrintData;
    qDebug()<<"216-inprint";
    beginPrint();

    const int nXPos = m_nLeftXPos;
    const int nTopSpace = 16;
    int nYPos = nTopSpace;

    paintOutStockTopInfo(nXPos, nYPos); // 打印门店信息
    paintOutStockGoodsList(nXPos, nYPos); // 打印盘点商品列表
    paintOutStockEndInfo(nXPos, nYPos); // 打印结尾信息

    const int bottomSpace = 30 * m_nZoomWidth / m_nRealWidth;
    nYPos += bottomSpace;
    printDashLine(nXPos, nYPos); // 剪裁分割线
    nYPos += bottomSpace;

    savePixmap(nYPos);
    m_pPainter->end();
    delete m_pPainter;
    m_pPainter = NULL;
    delete m_pPixmap;
    m_pPixmap = NULL;

    printReceipt();
}

void ReceiptPictureMaker::printAddedStockInfoReceipt(const StockPrintData &stockPrintData)
{
    m_stockPrintData = stockPrintData;

    beginPrint();

    const int nXPos = m_nLeftXPos;
    const int nTopSpace = 16;
    int nYPos = nTopSpace;

    paintStockTopInfo(nXPos, nYPos); // 打印门店信息
    paintAddedStockGoodsList(nXPos, nYPos); // 打印盘点商品列表
    paintStockEndInfo(nXPos, nYPos); // 打印结尾信息

    const int bottomSpace = 30 * m_nZoomWidth / m_nRealWidth;
    nYPos += bottomSpace;
    printDashLine(nXPos, nYPos); // 剪裁分割线
    nYPos += bottomSpace;

    savePixmap(nYPos);
    m_pPainter->end();
    delete m_pPainter;
    m_pPainter = NULL;
    delete m_pPixmap;
    m_pPixmap = NULL;

    printReceipt();
}

void ReceiptPictureMaker::printLogoutReceipt(const LogoutPrintData &printData)
{
    m_logoutPrintData = printData;
    beginPrint();

    const int nXPos = m_nLeftXPos;
    const int nTopSpace = 16;
    int nYPos = nTopSpace;

    paintLogoutTopInfo(nXPos, nYPos);

    const int bottomSpace = 30 * m_nZoomWidth / m_nRealWidth;
    nYPos += bottomSpace;
    printDashLine(nXPos, nYPos); // 剪裁分割线
    nYPos += bottomSpace;

    savePixmap(nYPos);
    m_pPainter->end();
    delete m_pPainter;
    m_pPainter = NULL;
    delete m_pPixmap;
    m_pPixmap = NULL;

    printReceipt();
}

void ReceiptPictureMaker::printSaleDetialReceipt(const SaleHead &saleHead, QList<PaymentDetailInfo> &paymentInfoList, QList<SaleDetails> &saleInfoList)
{
    m_saleDetialPrintData.saleHead = saleHead;
    m_saleDetialPrintData.paymentInfoList = paymentInfoList;
    m_saleDetialPrintData.itemInfoList = saleInfoList;
    m_saleDetialPrintData.sPrintTime = CommonFun::getCurDateTime();
    beginPrint();

    const int nXPos = m_nLeftXPos;
    const int nTopSpace = 16;
    int nYPos = nTopSpace;

    paintSaleDetialInfo(nXPos, nYPos);

    const int bottomSpace = 30 * m_nZoomWidth / m_nRealWidth;
    nYPos += bottomSpace;

    savePixmap(nYPos);
    m_pPainter->end();
    delete m_pPainter;
    m_pPainter = NULL;
    delete m_pPixmap;
    m_pPixmap = NULL;

    printReceipt();
}

//void ReceiptPictureMaker::testPrintReceipt()
//{
//    initData();
//    m_nSequence = 0;
//    m_pPixmap = new QPixmap(c_nZoomWidth, m_nPictureMaxHeight);
//    m_pPainter = new QPainter(m_pPixmap);
//    m_pPainter->setBrush(QBrush(QColor("#ffffff")));
//    m_pPainter->setPen(QPen(QColor("#ffffff")));
//    m_pPainter->drawRect(m_pPixmap->rect());
//    m_pPainter->setPen(QPen(QColor("#000000")));

//    const int nXPos = m_nLeftXPos;
//    const int nTopSpace = 16;
//    int nYPos = nTopSpace;
//    paintBarCode(nXPos, nYPos);
//    paintHeadContent(nXPos, nYPos);
//    paintHeadWords(nXPos, nYPos);
//    paintShopInfo(nXPos, nYPos);
//    paintSaleGoodsInfoList(nXPos, nYPos);
//    paintCategoryCountList(nXPos, nYPos); // 分类小计
//    paintSettlementInfo(nXPos, nYPos);
//    paintSettleTypeCount(nXPos, nYPos);
//    paintMemberInfo(nXPos, nYPos);
//    paintTailContent(nXPos, nYPos);

//    const int bottomSpace = 30 * c_nZoomWidth / c_nRealWidth;
//    nYPos += bottomSpace;
//    printDashLine(nXPos, nYPos); // 剪裁分割线
//    nYPos += bottomSpace;

//    savePixmap(nYPos);
//    m_pPainter->end();
//    delete m_pPainter;
//    m_pPainter = NULL;
//    delete m_pPixmap;
//    m_pPixmap = NULL;

//    printReceipt();
//}

//void ReceiptPictureMaker::initData()
//{
//    m_receiptPrintData.sBarcode = "1234567890"; // 条形码数据
//    m_receiptPrintData.sQRCode = "http://www.bejson.com/"; // 二维码数据
//    m_receiptPrintData.sHeadContent = QStringLiteral("给顾客");
//    m_receiptPrintData.sHeadWords = QStringLiteral("门店名称");
//    m_receiptPrintData.sTailContent = QStringLiteral("本店商品无质量问题不可以退换");
//    m_receiptPrintData.sPicturePath = "";
//    m_receiptPrintData.option.bGoodsCode = true; // 打印商品编码
//    m_receiptPrintData.option.bCountCategory = true; // 打印分类小计
//    m_receiptPrintData.option.bAddGoodsNumAfterGoodsName = true; // 商品数量(x1)添加到商品名后
//    m_receiptPrintData.option.bPrice = true; // 打印单价
//    m_receiptPrintData.option.bGoodsNameInOneRow = true; // 商品名称独占一行
//    m_receiptPrintData.option.bUnit = true; // 打印单位
//    m_receiptPrintData.option.bForbidBigFont = true; // 禁止大写字体
//    m_receiptPrintData.option.memberInfo.bShowInfo = true; // 是否显示会员信息
//    m_receiptPrintData.option.memberInfo.bShowIntegral = true; // 是否显示积分
//    m_receiptPrintData.option.memberInfo.bShowAccountAndRemain = true; // 显示账号和余额
//    m_receiptPrintData.shopInfo.sShopCode = QStringLiteral("Z0006"); // 门店号
//    m_receiptPrintData.shopInfo.sKPosCode = QStringLiteral("668"); // 款机号
//    m_receiptPrintData.shopInfo.sSaleman = QStringLiteral("001"); // 销售员
//    m_receiptPrintData.shopInfo.sSequence = QStringLiteral("20160511000006"); // 流水号
//    m_receiptPrintData.shopInfo.sDealTime = QStringLiteral("2016-05-11 14:06:43"); // 交易时间

//    for (int i = 0; i < 3; i++)
//    {
//        ReceiptCategoryCount receiptCategoryCount;// 小票分类统计
//        receiptCategoryCount.nTotalNum = i; // 总量
//        receiptCategoryCount.strTotalPrice = QString::number( i ); // 总价
//        receiptCategoryCount.sCategoryName = QStringLiteral("分类%1").arg(i); // 分类名字
//        m_receiptPrintData.saleInfo.categoryCountList.append(receiptCategoryCount); // 分类统计列表
//    }

//    for (int i = 0; i < 10; i++)
//    {
//        ReceiptSaleGoodsInfo receiptSaleGoodsInfo; // 销售物品的信息
//        receiptSaleGoodsInfo.sGoodsName = QString(QStringLiteral("名称aaaaaaaaaaaaaaa%1")).arg(i); // 名称
//        receiptSaleGoodsInfo.sGoodsUnit = QString(QStringLiteral("个")); // 单位
//        receiptSaleGoodsInfo.sGoodsNum = QString(QStringLiteral("%1")).arg(i); // 数量
//        receiptSaleGoodsInfo.sGoodsPrice = QString(QStringLiteral("%1")).arg(i); // 单价
//        receiptSaleGoodsInfo.sGoodsSumPrice = QString(QStringLiteral("%1")).arg(i); // 总价
//        m_receiptPrintData.saleInfo.saleGoodsInfoList.append(receiptSaleGoodsInfo); // 物品销售列表
//    }

//    m_receiptPrintData.settlementInfo.sSumPrice = "1000.00"; // 总计金额
//    m_receiptPrintData.settlementInfo.sSumNumber = "10.00"; // 总计数量
//    //m_receiptPrintData.settlementInfo.sMemberCutMoney = "100.00"; // 会员优惠
//   // m_receiptPrintData.settlementInfo.sDiscountMoney = "0.00"; // 折扣金额
//    m_receiptPrintData.settlementInfo.sAllDisAmt = "0.00";//总优惠金额
//    m_receiptPrintData.settlementInfo.sWantGetPrice = "1000.00"; // 应收金额
//    m_receiptPrintData.settlementInfo.sRealGetPrice = "900.00"; // 实收金额
//    m_receiptPrintData.settlementInfo.sReturnMoney = "11.10"; // 找零金额

//    m_receiptPrintData.settleTypeCount.sOnlineSettleMoney = "800"; // 线上支付
//    m_receiptPrintData.settleTypeCount.sCashSettleMoney = "100"; // 现金支付

//    m_receiptPrintData.memberInfo.sAccount = "15245614211";// 会员账号
//    m_receiptPrintData.memberInfo.sBalance = "10000.00";// 当前余额
//    m_receiptPrintData.memberInfo.sGetIntegral = "100";// 本次积分
//    m_receiptPrintData.memberInfo.sTotalIntegral = "100";// 剩余积分


//    ZIntDll::createReceiptBarCode(m_receiptPrintData.sBarcode);
//    ZIntDll::createReceiptQRCode(m_receiptPrintData.sQRCode);
//}

void ReceiptPictureMaker::paintBarCode(const int &nXPos, int &nYPos)
{
    const int nPictureWidth = 160 * m_nZoomWidth / m_nRealWidth;
    const int nPictureHeight = 50 * m_nZoomWidth / m_nRealWidth;
    QString sBarcodePath = FilePathManage::instance()->getReceiptPath() + c_sReceiptBarCodeName;
    QPixmap barCodePixmap(sBarcodePath);
    barCodePixmap = barCodePixmap.scaled(nPictureWidth, nPictureHeight);
    int nStartXPos = nXPos + (m_nPaintWidth - nPictureWidth) / 2;
    m_pPainter->drawPixmap(nStartXPos, nYPos, nPictureWidth, nPictureHeight, barCodePixmap);
    nYPos += nPictureHeight;
    checkYPos(nYPos);
    const int nOffY = 16; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintHeadContent(const int &nXPos, int &nYPos)
{
    int nfontSize = c_nFontSize1 * m_nZoomWidth / m_nRealWidth;
    if (m_receiptSet.option.bForbidBigFont) // 禁止打印大写字体
    {
        nfontSize = c_nFontSize2 * m_nZoomWidth / m_nRealWidth;
    }
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);//设置字体大小
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QRect textRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, m_receiptSet.sHeadContent);
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintHeadWords(const int &nXPos, int &nYPos)
{
    const int nOffY = 10; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize2 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QRect textRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(textRect, Qt::AlignCenter, KPosIni::getReceiptShopName());
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintShopInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nSpace = 2;
    // 门店号
    QString sShopCode = QString(QStringLiteral("门店号：%1")).arg(m_receiptPrintData.shopInfo.sShopCode);
    QRect shopCodeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopCodeRect, Qt::AlignLeft | Qt::AlignVCenter, sShopCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 款机号
    QString sKPosCode = QString(QStringLiteral("款机号：%1")).arg(m_receiptPrintData.shopInfo.sKPosCode);
    QRect kPosCodeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(kPosCodeRect, Qt::AlignLeft | Qt::AlignVCenter, sKPosCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 收银员
    QString sSaleman = QString(QStringLiteral("收银员：%1")).arg(m_receiptPrintData.shopInfo.sSaleman);
    QRect salemanRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(salemanRect, Qt::AlignLeft | Qt::AlignVCenter, sSaleman);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 导购员
    QString sSaleGuide = QString(QStringLiteral("导购员：%1")).arg(m_receiptPrintData.shopInfo.sSaleGuide);
    QRect saleGuideRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(saleGuideRect, Qt::AlignLeft | Qt::AlignVCenter, sSaleGuide);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 流水号
    QString sSequence = QString(QStringLiteral("流水号：%1")).arg(m_receiptPrintData.shopInfo.sSequence);
    QRect sequenceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(sequenceRect, Qt::AlignLeft | Qt::AlignVCenter, sSequence);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 交易时间
    QString sDealTime = QString(QStringLiteral("交易时间：%1")).arg(m_receiptPrintData.shopInfo.sDealTime);
    QRect dealTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(dealTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sDealTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::printDashLine(const int &nXPos, int &nYPos)
{
    QPen pen(QBrush(QColor("#000000")), 1, Qt::DashLine);
    m_pPainter->setPen(pen);
    const int nLineHeight = 1;
    m_pPainter->drawLine(nXPos, nYPos, m_nPaintWidth, nYPos);
    nYPos += nLineHeight;
    checkYPos(nYPos);
    m_pPainter->setPen(QPen(QColor("#000000"))); // 恢复默认QPen
}

void ReceiptPictureMaker::paintSaleGoodsInfoList(const int &nXPos, int &nYPos)
{
    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    // 标题
    paintGoodsInfoTitle(nXPos, nYPos);

    const int nOffy2 = 2;
    nYPos += nOffy2; // 微调, 标题与销售信息之间的间距
    checkYPos(nYPos);

    // 销售信息
    int nLen = m_receiptPrintData.saleInfo.saleGoodsInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        paintGoodsInfo(nXPos, nYPos, i + 1, m_receiptPrintData.saleInfo.saleGoodsInfoList[i]);
    }
}

void ReceiptPictureMaker::paintGoodsInfoTitle(const int &nXPos, int &nYPos)
{
    const int nOffY = 0; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;

    const int nGoodsNameWidth = 60 * m_nZoomWidth / m_nRealWidth; // 品名
    const int nGoodsPriceWidth = 32 * m_nZoomWidth / m_nRealWidth; // 单价
    const int nGoodsNumberWidth = 40 * m_nZoomWidth / m_nRealWidth; // 数量
    const int nGoodsSumPriceWidth = m_nPaintWidth - nGoodsNameWidth - nGoodsNumberWidth - nGoodsPriceWidth; // 金额

    int nStartXPos = nXPos;
    // 品名
    QRect goodsNameRect(nStartXPos, nYPos, nGoodsNameWidth, nTextHeight);
    m_pPainter->drawText(goodsNameRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("品名"));
    nStartXPos += nGoodsNameWidth;
    // 单价
    if (m_receiptSet.option.bPrice)
    {
        QRect goodsPriceRect(nStartXPos, nYPos, nGoodsPriceWidth, nTextHeight);
        m_pPainter->drawText(goodsPriceRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("单价"));
    }
    nStartXPos += nGoodsPriceWidth;

    // 数量
    if (!m_receiptSet.option.bAddGoodsNumAfterGoodsName)
    {
        QRect goodsNumberRect(nStartXPos, nYPos, nGoodsNumberWidth, nTextHeight);
        m_pPainter->drawText(goodsNumberRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("数量"));
    }
    nStartXPos += nGoodsNumberWidth;
    // 金额
    QRect goodsSumPriceRect(nStartXPos, nYPos, nGoodsSumPriceWidth, nTextHeight);
    m_pPainter->drawText(goodsSumPriceRect, Qt::AlignRight | Qt::AlignVCenter, QStringLiteral("金额"));

    //
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintGoodsInfo(const int &nXPos, int &nYPos, int nRowNum, const ReceiptSaleGoodsInfo &receiptSaleGoodsInfo)
{
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QRect textRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    QString sShowGoodsName = receiptSaleGoodsInfo.sGoodsName;
    if (m_receiptSet.option.bShortGoodsName)
    {
        sShowGoodsName = receiptSaleGoodsInfo.sGoodsShortName;
    }
    QString goodsContent = QString("%1：%2").arg(nRowNum).arg(sShowGoodsName);
    if (m_receiptSet.option.bGoodsCode)
    {
        goodsContent = QString("%1:[%2]%3").arg(nRowNum).arg(receiptSaleGoodsInfo.sGoodsCode).arg(sShowGoodsName);
    }
    if (m_receiptSet.option.bAddGoodsNumAfterGoodsName)
    {
        goodsContent.append(QString("x%1").arg(receiptSaleGoodsInfo.sGoodsNum));
    }

    m_pPainter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, goodsContent);
    nYPos += nTextHeight;
    checkYPos(nYPos);
    const int nRowSpace = 2; // 行间距
    nYPos += nRowSpace;
    checkYPos(nYPos);

    int nStartXPos = nXPos;
    int nPriceWidth = 80 * m_nZoomWidth / m_nRealWidth; // 单价
    int nNumberWidth = 46 * m_nZoomWidth / m_nRealWidth; // 数量
    int nSumPriceWidth = m_nPaintWidth - nNumberWidth - nPriceWidth; // 金额

    // 单价
    if (m_receiptSet.option.bPrice)
    {
        QString sShowPrice = receiptSaleGoodsInfo.sGoodsPrice;
        if (m_receiptSet.option.bUnit)
        {
            sShowPrice = QString("%1/%2").arg(receiptSaleGoodsInfo.sGoodsPrice).arg(receiptSaleGoodsInfo.sGoodsUnit);
        }

        QRect priceRect(nStartXPos, nYPos, nPriceWidth, nTextHeight);
        m_pPainter->drawText(priceRect, Qt::AlignRight | Qt::AlignVCenter, sShowPrice);
    }
    nStartXPos += nPriceWidth;

    // 数量
    if (!m_receiptSet.option.bAddGoodsNumAfterGoodsName)
    {
        QRect numberRect(nStartXPos, nYPos, nNumberWidth, nTextHeight);
        m_pPainter->drawText(numberRect, Qt::AlignCenter, receiptSaleGoodsInfo.sGoodsNum);
    }
    nStartXPos += nNumberWidth;

    // 金额
    QRect sumPriceRect(nStartXPos, nYPos, nSumPriceWidth, nTextHeight);
    m_pPainter->drawText(sumPriceRect, Qt::AlignRight | Qt::AlignVCenter, receiptSaleGoodsInfo.sGoodsSumPrice);

    //
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintCategoryCountList(const int &nXPos, int &nYPos)
{
    if (!m_receiptSet.option.bCountCategory)
    {
        return;
    }

    // 虚线
    const int nOffY = 4; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    QPen pen(QBrush(QColor("#000000")), 1, Qt::SolidLine);
    m_pPainter->setPen(pen);
    const int nLineHeight = 1;
    m_pPainter->drawLine(nXPos, nYPos, m_nPaintWidth, nYPos);
    nYPos += nLineHeight + nOffY;
    checkYPos(nYPos);
    m_pPainter->setPen(QPen(QColor("#000000"))); // 恢复默认QPen

    int nLen = m_receiptPrintData.saleInfo.categoryCountList.length();
    for (int i = 0; i < nLen; i++)
    {
        paintCategoryCount(nXPos, nYPos, m_receiptPrintData.saleInfo.categoryCountList[i]);
    }
}

void ReceiptPictureMaker::paintCategoryCount(const int &nXPos, int &nYPos, ReceiptCategoryCount &receiptCategoryCount)
{
    const int nOffY = 0; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QString sLeftCountContent = QString("%1分类(%2项)").arg(receiptCategoryCount.sCategoryName).arg(receiptCategoryCount.nTotalNum);
    QRect leftRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(leftRect, Qt::AlignLeft | Qt::AlignVCenter, sLeftCountContent);
    QString sRightCountContent = receiptCategoryCount.strTotalPrice;
    const int nOffRightSpace = 5; // 右侧距离微调
    QRect rightRect(nXPos, nYPos, m_nPaintWidth - nOffRightSpace, nTextHeight);
    m_pPainter->drawText(rightRect, Qt::AlignRight | Qt::AlignVCenter, sRightCountContent);

    nYPos += nTextHeight;
    checkYPos(nYPos);
    const int nRowSpace = 2; // 行间距
    nYPos += nRowSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintSettlementInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nRowSpace = 2;

    // 总计金额
    QString sSumPrice = QString("总计金额：%1").arg(m_receiptPrintData.settlementInfo.sSumPrice); // 总计金额
    QRect sumPriceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(sumPriceRect, Qt::AlignLeft | Qt::AlignVCenter, sSumPrice);
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);

    // 总计数量
    QString sSumNumber = QString("总计数量：%1").arg(m_receiptPrintData.settlementInfo.sSumNumber); // 总计数量
    QRect sumNumberRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(sumNumberRect, Qt::AlignLeft | Qt::AlignVCenter, sSumNumber);
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);

    // 会员优惠
    QString sAllDisPrice = QString("总优惠金额：%1").arg(m_receiptPrintData.settlementInfo.sAllDisAmt ); // 会员优惠
    QRect AllDisPriceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(AllDisPriceRect, Qt::AlignLeft | Qt::AlignVCenter, sAllDisPrice);
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);

    //    // 会员优惠
    //    QString sMemberCutPrice = QString("会员优惠：%1").arg(m_receiptPrintData.settlementInfo.sMemberCutMoney); // 会员优惠
    //    QRect memberCutPriceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    //    m_pPainter->drawText(memberCutPriceRect, Qt::AlignLeft | Qt::AlignVCenter, sMemberCutPrice);
    //    nYPos += nTextHeight + nRowSpace;
    //    checkYPos(nYPos);

    // 折扣金额
    //    QString sDiscountPrice = QString("折扣金额：%1").arg(m_receiptPrintData.settlementInfo.sDiscountMoney); // 折扣金额
    //    QRect discountPriceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    //    m_pPainter->drawText(discountPriceRect, Qt::AlignLeft | Qt::AlignVCenter, sDiscountPrice);
    //    nYPos += nTextHeight + nRowSpace;
    //    checkYPos(nYPos);

    // 应收金额
    QString sWantGetPrice = QString("应收金额：%1").arg(m_receiptPrintData.settlementInfo.sWantGetPrice); // 应收金额
    QRect wantGetPriceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(wantGetPriceRect, Qt::AlignLeft | Qt::AlignVCenter, sWantGetPrice);
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);

    // 实收金额
    QString sRealGetPrice = QString("实收金额：%1").arg(m_receiptPrintData.settlementInfo.sRealGetPrice); // 实收金额
    QRect realGetPriceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(realGetPriceRect, Qt::AlignLeft | Qt::AlignVCenter, sRealGetPrice);
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
    // 找零金额
    QString sReturnMoney = QString("找零金额：%1").arg(m_receiptPrintData.settlementInfo.sReturnMoney); // 找零金额
    QRect returnMoneyRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(returnMoneyRect, Qt::AlignLeft | Qt::AlignVCenter, sReturnMoney);
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintSettleTypeCount(const int &nXPos, int &nYPos)
{
    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nRowSpace = 2;

    // 付款方式
    QRect realGetPriceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(realGetPriceRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("付款方式"));
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);

    QList<QString> keyList = m_receiptPrintData.settleTypeMap.keys();
    int nLen = keyList.length();
    QString sKey = "";
    for (int i = 0; i < nLen; i++)
    {
        sKey = keyList[i];
        QString sOnlineSettleMoney = QString("%1：%2").arg(sKey).arg(m_receiptPrintData.settleTypeMap.value(sKey)); // 线上支付
        QRect onlineSettleMoneyRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
        m_pPainter->drawText(onlineSettleMoneyRect, Qt::AlignLeft | Qt::AlignVCenter, sOnlineSettleMoney);
        nYPos += nTextHeight + nRowSpace;
        checkYPos(nYPos);
    }

    //    // 线上支付
    //    QString sOnlineSettleMoney = QString("线上支付：%1").arg(m_receiptPrintData.settleTypeCount.sOnlineSettleMoney); // 线上支付
    //    QRect onlineSettleMoneyRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    //    m_pPainter->drawText(onlineSettleMoneyRect, Qt::AlignLeft | Qt::AlignVCenter, sOnlineSettleMoney);
    //    nYPos += nTextHeight + nRowSpace;
    //    checkYPos(nYPos);

    //    // 现金支付
    //    QString sCashSettleMoney = QString("现金支付：%1").arg(m_receiptPrintData.settleTypeCount.sCashSettleMoney); // 现金支付
    //    QRect cashSettleMoneyRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    //    m_pPainter->drawText(cashSettleMoneyRect, Qt::AlignLeft | Qt::AlignVCenter, sCashSettleMoney);
    //    nYPos += nTextHeight + nRowSpace;
    //    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintMemberInfo(const int &nXPos, int &nYPos)
{
    if (!m_receiptSet.option.memberInfo.bShowInfo)
    {
        return;
    }

    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nRowSpace = 2;

    if (m_receiptSet.option.memberInfo.bShowAccountAndRemain)
    {
        // 会员账号
        QString sAccount = QString("会员账号：%1").arg(m_receiptPrintData.memberInfo.sAccount); // 会员账号
        QRect accountRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
        m_pPainter->drawText(accountRect, Qt::AlignLeft | Qt::AlignVCenter, sAccount);
        nYPos += nTextHeight + nRowSpace;
        checkYPos(nYPos);
        // 当前余额
        QString sBalance = QString("当前余额：%1").arg(m_receiptPrintData.memberInfo.sBalance); // 当前余额
        QRect balanceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
        m_pPainter->drawText(balanceRect, Qt::AlignLeft | Qt::AlignVCenter, sBalance);
        nYPos += nTextHeight + nRowSpace;
        checkYPos(nYPos);
    }

    if (m_receiptSet.option.memberInfo.bShowIntegral)
    {
        // 本次积分
        QString sGetIntegral = QString("本次积分：%1").arg(m_receiptPrintData.memberInfo.sGetIntegral); // 本次积分
        QRect getIntegralRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
        m_pPainter->drawText(getIntegralRect, Qt::AlignLeft | Qt::AlignVCenter, sGetIntegral);
        nYPos += nTextHeight + nRowSpace;
        checkYPos(nYPos);
        // 剩余积分
        QString sTotalIntegral = QString("剩余积分：%1").arg(m_receiptPrintData.memberInfo.sTotalIntegral); // 剩余积分
        QRect totalIntegralRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
        m_pPainter->drawText(totalIntegralRect, Qt::AlignLeft | Qt::AlignVCenter, sTotalIntegral);
        nYPos += nTextHeight;
        checkYPos(nYPos);
    }
}

void ReceiptPictureMaker::paintTailContent(const int &nXPos, int &nYPos)
{
    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    const int nLineRowSpace = 2; // 两条线的间距
    nYPos += nLineRowSpace;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QRect textRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, m_receiptSet.sTailContent);
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintQRCode(const int &nXPos, int &nYPos)
{
    const int nPictureWidth = 75 * m_nZoomWidth / m_nRealWidth;
    const int nPictureHeight = 100 * m_nZoomWidth / m_nRealWidth;
    QString sBarcodePath = /*FilePathManage::instance()->getReceiptPath()+*/  c_sReceiptQRCodeName;
    QPixmap barCodePixmap(sBarcodePath);
    barCodePixmap = barCodePixmap.scaled(nPictureWidth, nPictureHeight);
    int nStartXPos = nXPos + (m_nPaintWidth - nPictureWidth) / 2;
    m_pPainter->drawPixmap(nStartXPos, nYPos, nPictureWidth, nPictureHeight, barCodePixmap);
    nYPos += nPictureHeight;
    checkYPos(nYPos);
    const int nOffY = 16; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::checkYPos(int &nYPos)
{
    if (nYPos > m_nPictureMaxHeight - 30)
    {
        // 保存图片
        savePixmap(nYPos);
        m_pPixmap->fill(QColor("#ffffff")); // 数据清空
        nYPos = 10  * m_nZoomWidth / m_nRealWidth; // 翻页时预留一些起始位置
    }
}

void ReceiptPictureMaker::savePixmap(const int nYPos)
{
    QPixmap pixmap = m_pPixmap->copy(0, 0, m_nPaintWidth + 2*m_nLeftXPos, nYPos);
    //保存图片到本地
    pixmap.save(QString("%1/test%2.bmp").arg(FilePathManage::instance()->getReceiptPath()).arg(m_nSequence));
    m_picturePathList.append(QString("%1/test%2.bmp").arg(FilePathManage::instance()->getReceiptPath()).arg(m_nSequence));
    m_nSequence++;
}

void ReceiptPictureMaker::printReceipt()
{
    int len = m_picturePathList.length();
    for (int i = 0; i < len; i++)
    {
        BalanceManage::instance()->printBitmapFile(m_picturePathList[i]);
    }
    BalanceManage::instance()->cutPage();
    m_picturePathList.clear();
}

void ReceiptPictureMaker::paintMemHeadWords(const int &nXPos, int &nYPos)
{
    const int nfontSize = c_nFontSize1 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);//设置字体大小
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QRect textRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, m_stMemRechargePrintInfo.sHeadWords );
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintMemHeadContent(const int &nXPos, int &nYPos)
{
    const int nOffY = 10; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize2 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QRect textRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(textRect, Qt::AlignCenter, m_stMemRechargePrintInfo.sHeadContent);
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintMemShopInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nSpace = 2;
    // 门店号
    QString sShopCode = QString(QStringLiteral("门店号：%1")).arg(m_stMemRechargePrintInfo.stShopInfo.sShopCode);
    QRect shopCodeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopCodeRect, Qt::AlignLeft | Qt::AlignVCenter, sShopCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 款机号
    QString sKPosCode = QString(QStringLiteral("款机号：%1")).arg(m_stMemRechargePrintInfo.stShopInfo.sKPosCode);
    QRect kPosCodeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(kPosCodeRect, Qt::AlignLeft | Qt::AlignVCenter, sKPosCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    //    // 销售员
    //    QString sSaleman = QString(QStringLiteral("销售员：%1")).arg(m_stMemRechargePrintInfo.stShopInfo.sSaleman);
    //    QRect salemanRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    //    m_pPainter->drawText(salemanRect, Qt::AlignLeft | Qt::AlignVCenter, sSaleman);
    //    nYPos += nTextHeight + nSpace;
    //    checkYPos(nYPos);
    // 交易号
    QString sSequence = QString(QStringLiteral("交易号：%1")).arg(m_stMemRechargePrintInfo.stShopInfo.sSequence);
    QRect sequenceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(sequenceRect, Qt::AlignLeft | Qt::AlignVCenter, sSequence);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    //    // 交易时间
    //    QString sDealTime = QString(QStringLiteral("交易时间：%1")).arg(m_stMemRechargePrintInfo.stShopInfo.sDealTime);
    //    QRect dealTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    //    m_pPainter->drawText(dealTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sDealTime);
    //    nYPos += nTextHeight + nSpace;
    //    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintRechargeMemInfo(const int &nXPos, int &nYPos)
{
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nRowSpace = 2;

    // 会员卡号
    QString sCardNo = QString("会员卡号：%1").arg( m_stMemRechargePrintInfo.stMemberRechargeInfo.strCardNo ); // 会员卡号
    QRect cardRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(cardRect, Qt::AlignLeft | Qt::AlignVCenter, sCardNo);
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
    // 会员姓名
    //    int nSize = m_stMemRechargePrintInfo.stMemberRechargeInfo.strName.size();
    //    QString strName = "";
    //    for( int i=0; i < nSize-1; ++i ) {
    //        strName += "*";
    //    }
    //    strName = m_stMemRechargePrintInfo.stMemberRechargeInfo.strName.left(1) + strName;
    QString sMemName = QString("会员姓名：%1").arg( m_stMemRechargePrintInfo.stMemberRechargeInfo.strName );
    QRect balanceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(balanceRect, Qt::AlignLeft | Qt::AlignVCenter, sMemName );
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
    // 交易时间
    QString sDealTime = QString(QStringLiteral("交易时间：%1")).arg(m_stMemRechargePrintInfo.stShopInfo.sDealTime);
    QRect dealTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(dealTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sDealTime);
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintRechargeInfo(const int &nXPos, int &nYPos)
{
    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nRowSpace = 2;

    // 充值金额
    QString sCardNo = QString("充值金额：%1").arg( m_stMemRechargePrintInfo.stMemberRechargeInfo.strRechargeAmt );
    QRect cardRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(cardRect, Qt::AlignLeft | Qt::AlignVCenter, sCardNo);
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
    // 赠送金额
    QString sGiftAmt = QString("赠送金额：%1").arg( m_stMemRechargePrintInfo.stMemberRechargeInfo.strGiftAmt );
    QRect giftAmtRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(giftAmtRect, Qt::AlignLeft | Qt::AlignVCenter, sGiftAmt);
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
    // 会员余额
    QString sBalance = QString("会员余额：%1").arg( m_stMemRechargePrintInfo.stMemberRechargeInfo.sBalance );
    QRect accountRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(accountRect, Qt::AlignLeft | Qt::AlignVCenter, sBalance);
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
    // 支付方式
    QString sPayMethod = QString("支付方式：%1").arg( m_stMemRechargePrintInfo.stMemberRechargeInfo.strPayMethod );
    QRect balanceRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(balanceRect, Qt::AlignLeft | Qt::AlignVCenter, sPayMethod );
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintMemSigned( const int &nXPos, int &nYPos )
{
    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nRowSpace = 2;

    int nX = nXPos + 30;
    // 签字
    QString sSignWord = QString("签字：");
    QRect cardRect(nX, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(cardRect, Qt::AlignLeft | Qt::AlignVCenter, sSignWord );
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintAdjustPriceTopInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nSpace = 2;
    // 门店
    QString sShopName = QString(QStringLiteral("门店：%1")).arg(m_adjustPricePrintData.sShopName);
    QRect shopNameRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopNameRect, Qt::AlignLeft | Qt::AlignVCenter, sShopName);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 门店号
    QString sShopCode = QString(QStringLiteral("门店号：%1")).arg(m_adjustPricePrintData.sShopCode);
    QRect shopCodeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopCodeRect, Qt::AlignLeft | Qt::AlignVCenter, sShopCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 单号
    QString sOrderNum = QString(QStringLiteral("单号：%1")).arg(m_adjustPricePrintData.adjustOrderInfo.sOrderNum);
    QRect orderNumRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderNumRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderNum);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 制单人
    QString sOrderMaker = QString(QStringLiteral("制单人：%1")).arg(m_adjustPricePrintData.adjustOrderInfo.sMaker);
    QRect orderMakerRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderMakerRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderMaker);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 审核人
    QString sOrderChecker = QString(QStringLiteral("审核人：%1")).arg(m_adjustPricePrintData.adjustOrderInfo.sChecker);
    QRect orderCheckerRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderCheckerRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderChecker);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 状态
    QString sOrderState = QString("状态：%1").arg(EnumToString::adjustPriceStateToString(m_adjustPricePrintData.adjustOrderInfo.nState));
    QRect orderStateRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderStateRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderState);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 生效时间
    QString sEffectTime = QString(QStringLiteral("生效时间：%1")).arg(m_adjustPricePrintData.adjustOrderInfo.sEffectTime);
    QRect effectTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(effectTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sEffectTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintAdjustPriceGoodsTitle(const int &nXPos, int &nYPos)
{
    const int nOffY = 0; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;

    const int nGoodsNameWidth = 60 * m_nZoomWidth / m_nRealWidth; // 品名
    const int nGoodsPriceWidth = 60 * m_nZoomWidth / m_nRealWidth; // 单价
    const int nGoodsMemberPriceWidth = m_nPaintWidth - nGoodsNameWidth - nGoodsPriceWidth; // 会员价

    int nStartXPos = nXPos;
    // 品名
    QRect goodsNameRect(nStartXPos, nYPos, nGoodsNameWidth, nTextHeight);
    m_pPainter->drawText(goodsNameRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("品名"));
    nStartXPos += nGoodsNameWidth;
    // 单价
    QRect goodsUnitRect(nStartXPos, nYPos, nGoodsPriceWidth, nTextHeight);
    m_pPainter->drawText(goodsUnitRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("单价"));
    nStartXPos += nGoodsPriceWidth;
    // 会员价
    QRect goodsNumberRect(nStartXPos, nYPos, nGoodsMemberPriceWidth, nTextHeight);
    m_pPainter->drawText(goodsNumberRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("会员价"));
    nStartXPos += nGoodsMemberPriceWidth;

    //
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintAdjustPriceGoodsList(const int &nXPos, int &nYPos)
{
    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    // 标题
    paintAdjustPriceGoodsTitle(nXPos, nYPos);

    const int nOffy2 = 2;
    nYPos += nOffy2; // 微调, 标题与销售信息之间的间距
    checkYPos(nYPos);

    // 销售信息
    int nLen = m_adjustPricePrintData.adjustPriceInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        paintAdjustPriceGoods(nXPos, nYPos, i + 1, m_adjustPricePrintData.adjustPriceInfoList[i]);
    }
}

void ReceiptPictureMaker::paintAdjustPriceGoods(const int &nXPos, int &nYPos, int nRowNum, const AdjustPriceGoodsInfo &goodsInfo)
{
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QRect textRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    QString goodsContent = QString("%1：%2").arg(nRowNum).arg(goodsInfo.sName);
    m_pPainter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, goodsContent);
    nYPos += nTextHeight;
    checkYPos(nYPos);
    const int nRowSpace = 2; // 行间距
    nYPos += nRowSpace;
    checkYPos(nYPos);

    const int nLeftSpace = 60 * m_nZoomWidth / m_nRealWidth;
    int nStartXPos = nXPos + nLeftSpace;
    int nPriceWidth = 60 * m_nZoomWidth / m_nRealWidth; // 单价
    int nMemberPriceWidth = m_nPaintWidth - nLeftSpace - nPriceWidth ; // 会员价

    // 原单价
    QRect oldPriceRect(nStartXPos, nYPos, nPriceWidth, nTextHeight);
    m_pPainter->drawText(oldPriceRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(goodsInfo.fOldPrice, 'f', 2));
    nStartXPos += nPriceWidth;
    // 原会员价
    QRect oldMemberRect(nStartXPos, nYPos, nMemberPriceWidth, nTextHeight);
    m_pPainter->drawText(oldMemberRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(goodsInfo.fOldMemberPrice, 'f', 2));

    nStartXPos = nXPos + nLeftSpace;
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);

    // 现单价
    QRect nowPriceRect(nStartXPos, nYPos, nPriceWidth, nTextHeight);
    m_pPainter->drawText(nowPriceRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(goodsInfo.fNowPrice, 'f', 2));
    nStartXPos += nPriceWidth;
    // 现会员价
    QRect nowMemberPriceRect(nStartXPos, nYPos, nMemberPriceWidth, nTextHeight);
    m_pPainter->drawText(nowMemberPriceRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(goodsInfo.fNowMemberPrice, 'f', 2));

    //
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintAdjustEndInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 10; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    // 打印时间
    QString sPrintTime = QString(QStringLiteral("打印时间：%1")).arg(m_adjustPricePrintData.sPrintTime);
    QRect printTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(printTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sPrintTime);
}

void ReceiptPictureMaker::paintSaleDetialInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 10; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nSpace = 2;

    // *宽度
    const int nWidth = 15;
    for(int i=0; i<m_nPaintWidth/nWidth; i++){
        QRect rect(nXPos+i*nWidth, nYPos, nWidth, nWidth);
        m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, "*");
    }
    nYPos += nWidth + nOffY;
    checkYPos(nYPos);

    QString sShopCode = QStringLiteral("门店号：%1").arg(m_saleDetialPrintData.saleHead.nShopId);
    QRect rect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, sShopCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    QString sPosCode = QStringLiteral("款机号: %1").arg(m_saleDetialPrintData.saleHead.strPosId);
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, sPosCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    QString saleman = QStringLiteral("收银员: %1").arg(m_saleDetialPrintData.saleHead.strCashierName);
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, saleman);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    QString saleGuide = QStringLiteral("导购员: %1").arg(m_saleDetialPrintData.saleHead.strShoppingName);
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, saleGuide);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    QString receiptCode = QStringLiteral("小票编号: %1").arg(m_saleDetialPrintData.saleHead.strOrderNum);
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, receiptCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    QString dealTime = QStringLiteral("交易时间: %1").arg(m_saleDetialPrintData.saleHead.dtCompleteTime.toString("yyyy-MM-dd hh:mm:ss"));
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, dealTime);
    nYPos += nTextHeight + nOffY;
    checkYPos(nYPos);

    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    QString totalPrice = QStringLiteral("总计金额: %1").arg(m_saleDetialPrintData.saleHead.fOughtAmt);
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, totalPrice);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    QString totalNum = QStringLiteral("总计数量: %1").arg(m_saleDetialPrintData.saleHead.nSaleTotalNum);
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, totalNum);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    QString totalMoney = QStringLiteral("总优惠金额: %1").arg(m_saleDetialPrintData.saleHead.fAllDisAmt);
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, totalMoney);
    nYPos += nTextHeight + nSpace + nTextHeight/2;
    checkYPos(nYPos);

    QPen pen;
    pen.setWidth(4);
    m_pPainter->setPen(pen);
    m_pPainter->drawPoint(nXPos + nTextHeight/2, nYPos);
    nYPos -= nTextHeight/2;
    checkYPos(nYPos);

    QString disRate = QStringLiteral("折扣优惠: %1").arg(m_saleDetialPrintData.saleHead.fGrantDisRate);
    rect.setRect(nXPos + nTextHeight, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, disRate);
    nYPos += nTextHeight + nSpace + nTextHeight/2;
    checkYPos(nYPos);

    m_pPainter->setPen(pen);
    m_pPainter->drawPoint(nXPos + nTextHeight/2, nYPos);
    nYPos -= nTextHeight/2;
    checkYPos(nYPos);

    QString sSmallChangeAmt = QStringLiteral("抹零: %1").arg(m_saleDetialPrintData.saleHead.sSmallChangeAmt);
    rect.setRect(nXPos + nTextHeight, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, sSmallChangeAmt);
    nYPos += nTextHeight + nSpace + nTextHeight/2;
    checkYPos(nYPos);

    m_pPainter->setPen(pen);
    m_pPainter->drawPoint(nXPos + nTextHeight/2, nYPos);
    nYPos -= nTextHeight/2;
    checkYPos(nYPos);

    QString fCouponDisAmt = QStringLiteral("优惠券: %1").arg(m_saleDetialPrintData.saleHead.fCouponDisAmt);
    rect.setRect(nXPos + nTextHeight, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, fCouponDisAmt);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    QString fFactorAmt = QStringLiteral("应收金额: %1").arg(m_saleDetialPrintData.saleHead.fFactorAmt);
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, fFactorAmt);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    QString fProfitLoss = QStringLiteral("实收金额: %1").arg(m_saleDetialPrintData.saleHead.fProfitLoss + m_saleDetialPrintData.saleHead.fFactorAmt);
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, fProfitLoss);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    QString actChange = QStringLiteral("找零金额: %1").arg(m_saleDetialPrintData.saleHead.actChange);
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, actChange);
    nYPos += nTextHeight + nOffY;
    checkYPos(nYPos);

    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    QString mode = QStringLiteral("付款方式");
    rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, mode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    int nLen = m_saleDetialPrintData.paymentInfoList.length();
    for(int i=0; i<nLen; i++){
        QString ePayMethod = EnumToString::payMethodToString(m_saleDetialPrintData.paymentInfoList[i].ePayMethod);
        float fPaymentSum = m_saleDetialPrintData.paymentInfoList[i].fPaymentSum;
        rect.setRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
        m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, QString("%1 : %2").arg(ePayMethod).arg(fPaymentSum));
        nYPos += nTextHeight + nSpace;
        checkYPos(nYPos);
    }

    nYPos += nWidth + 2*nOffY;
    checkYPos(nYPos);
    for(int i=0; i<m_nPaintWidth/nWidth; i++){
        QRect rect(nXPos+i*nWidth, nYPos, nWidth, nWidth);
        m_pPainter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, "*");
    }
}

void ReceiptPictureMaker::paintStockTopInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nSpace = 2;
    // 门店
    QString sShopName = QStringLiteral("门店：%1").arg(m_stockPrintData.sShopName);
    QRect shopNameRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopNameRect, Qt::AlignLeft | Qt::AlignVCenter, sShopName);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 门店号
    QString sShopCode = QStringLiteral("门店号：%1").arg(m_stockPrintData.sShopCode);
    QRect shopCodeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopCodeRect, Qt::AlignLeft | Qt::AlignVCenter, sShopCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 单号
    QString sOrderNum = QStringLiteral("单号：%1").arg(m_stockPrintData.stockOrderInfo.sOrderNum);
    QRect orderNumRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderNumRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderNum);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 制单人
    QString sOrderMaker = QStringLiteral("制单人：%1").arg(m_stockPrintData.stockOrderInfo.sMaker);
    QRect orderMakerRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderMakerRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderMaker);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 审核人
    QString sOrderChecker = QStringLiteral("审核人：%1").arg(m_stockPrintData.stockOrderInfo.sChecker);
    QRect orderCheckerRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderCheckerRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderChecker);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 状态
    QString sOrderState = QStringLiteral("状态：%1").arg(EnumToString::stockSateToString(m_stockPrintData.stockOrderInfo.nState));
    QRect orderStateRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderStateRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderState);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 生效时间
    QString sEffectTime = QStringLiteral("修改时间：%1").arg(m_stockPrintData.stockOrderInfo.sMakeTime);
    QRect effectTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(effectTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sEffectTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintInStockTopInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nSpace = 2;
    // 门店
    QString sShopName = QStringLiteral("门店：%1").arg(m_instockPrintData.sShopName);
    QRect shopNameRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopNameRect, Qt::AlignLeft | Qt::AlignVCenter, sShopName);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 门店号
    QString sShopCode = QStringLiteral("门店号：%1").arg(m_instockPrintData.sShopCode);
    QRect shopCodeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopCodeRect, Qt::AlignLeft | Qt::AlignVCenter, sShopCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 单号
    QString sOrderNum = QStringLiteral("单号：%1").arg(m_instockPrintData.stockOrderInfo.sOrderNum);
    QRect orderNumRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderNumRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderNum);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 制单人
    QString sOrderMaker = QStringLiteral("制单人：%1").arg(m_instockPrintData.stockOrderInfo.sMaker);
    QRect orderMakerRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderMakerRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderMaker);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 审核人
    QString sOrderChecker = QStringLiteral("审核人：%1").arg(m_instockPrintData.stockOrderInfo.sChecker);
    QRect orderCheckerRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderCheckerRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderChecker);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 状态
    QString sOrderState = QStringLiteral("状态：%1").arg(EnumToString::stockSateToString(m_instockPrintData.stockOrderInfo.nState));
    QRect orderStateRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderStateRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderState);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 制单时间
    QString sEffectTime = QStringLiteral("制单时间：%1").arg(m_instockPrintData.stockOrderInfo.sMakeTime);
    QRect effectTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(effectTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sEffectTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    // 审核时间
    QString sCkTime = QStringLiteral("审核时间：%1").arg(m_instockPrintData.stockOrderInfo.sCheckTime);
    QRect CkRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(CkRect, Qt::AlignLeft | Qt::AlignVCenter, sCkTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintAllStockGoodsList(const int &nXPos, int &nYPos)
{
    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    // 标题
    paintStockGoodsTitle(nXPos, nYPos);

    const int nOffy2 = 2;
    nYPos += nOffy2; // 微调, 标题与销售信息之间的间距
    checkYPos(nYPos);

    // 销售信息
    int nLen = m_stockPrintData.stockInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        paintStockGoods(nXPos, nYPos, i + 1, m_stockPrintData.stockInfoList[i]);
    }
}

void ReceiptPictureMaker::paintInStockGoodsList(const int &nXPos, int &nYPos)
{

    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    // 标题
    paintInStockGoodsTitle(nXPos, nYPos);

    const int nOffy2 = 2;
    nYPos += nOffy2; // 微调, 标题与销售信息之间的间距
    checkYPos(nYPos);

    // 销售信息
    int nLen = m_instockPrintData.stockInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        paintInStockGoods(nXPos, nYPos, i + 1, m_instockPrintData.stockInfoList[i]);
    }
}

void ReceiptPictureMaker::paintAddedStockGoodsList(const int &nXPos, int &nYPos)
{
    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    // 标题
    paintStockGoodsTitle(nXPos, nYPos);

    const int nOffy2 = 2;
    nYPos += nOffy2; // 微调, 标题与销售信息之间的间距
    checkYPos(nYPos);

    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nSpace = 2;
    // 移除的
    int nRemovedLen = m_stockPrintData.removedInfoList.length();
    if (nRemovedLen > 0)
    {
        QString sRemoved = QStringLiteral("----删除的：");
        QRect removedRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
        m_pPainter->drawText(removedRect, Qt::AlignLeft | Qt::AlignVCenter, sRemoved);
        nYPos += nTextHeight + nSpace;
        checkYPos(nYPos);

        for (int i = 0; i < nRemovedLen; i++)
        {
            paintStockGoods(nXPos, nYPos, i + 1, m_stockPrintData.removedInfoList[i]);
        }
    }
    int nUpdatedLen = m_stockPrintData.updateInfoList.length();
    if (nUpdatedLen > 0)
    {
        // 更新的
        QString sUpdated = QStringLiteral("----更新的：");
        QRect updatedRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
        m_pPainter->drawText(updatedRect, Qt::AlignLeft | Qt::AlignVCenter, sUpdated);
        nYPos += nTextHeight + nSpace;
        checkYPos(nYPos);

        for (int i = 0; i < nUpdatedLen; i++)
        {
            paintStockGoods(nXPos, nYPos, i + 1, m_stockPrintData.updateInfoList[i]);
        }
    }
    int nAddedLen = m_stockPrintData.addedInfoList.length();
    if (nAddedLen > 0)
    {
        // 新增的
        QString sAdded = QStringLiteral("----新增的：");
        QRect addedRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
        m_pPainter->drawText(addedRect, Qt::AlignLeft | Qt::AlignVCenter, sAdded);
        nYPos += nTextHeight + nSpace;
        checkYPos(nYPos);

        for (int i = 0; i < nAddedLen; i++)
        {
            paintStockGoods(nXPos, nYPos, i + 1, m_stockPrintData.addedInfoList[i]);
        }
    }
}

void ReceiptPictureMaker::paintStockGoodsTitle(const int &nXPos, int &nYPos)
{
    const int nOffY = 0; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;

    const int nGoodsNameWidth = 120 * m_nZoomWidth / m_nRealWidth; // 品名
    const int nRealStockNumWidth = m_nPaintWidth - nGoodsNameWidth; // 实盘数量

    int nStartXPos = nXPos;
    // 品名
    QRect goodsNameRect(nStartXPos, nYPos, nGoodsNameWidth, nTextHeight);
    m_pPainter->drawText(goodsNameRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("品名"));
    nStartXPos += nGoodsNameWidth;
    // 实盘数量
    QRect realStockNumRect(nStartXPos, nYPos, nRealStockNumWidth, nTextHeight);
    m_pPainter->drawText(realStockNumRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("实盘数量"));

    //
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintInStockGoodsTitle(const int &nXPos, int &nYPos)
{
    const int nOffY = 0; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;

    const int nGoodsNameWidth = 48* m_nZoomWidth / m_nRealWidth; // 品名
    const int nPriceWidth = 38* m_nZoomWidth / m_nRealWidth; // 单价
    const int nRealStockNumWidth = 38* m_nZoomWidth / m_nRealWidth; // 数量
    const int nAmountWidth = 33* m_nZoomWidth / m_nRealWidth; // 金额

    int nStartXPos = nXPos+c_nFontSize3;
    // 品名
    QRect goodsNameRect(nStartXPos, nYPos, nGoodsNameWidth, nTextHeight);
    m_pPainter->drawText(goodsNameRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("品名"));
    nStartXPos += nGoodsNameWidth;

    // 品名
    QRect priceRect(nStartXPos, nYPos, nPriceWidth, nTextHeight);
    m_pPainter->drawText(priceRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("单价"));
    nStartXPos += nPriceWidth;

    // 数量
    QRect realStockNumRect(nStartXPos, nYPos, nRealStockNumWidth, nTextHeight);
    m_pPainter->drawText(realStockNumRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("数量"));

    nStartXPos += nGoodsNameWidth;

    // 品名
    QRect amountRect(nStartXPos, nYPos, nAmountWidth, nTextHeight);
    m_pPainter->drawText(amountRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("金额"));
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintOutStockGoods(const int &nXPos, int &nYPos, int nRowNum, const OutStockOrderGoodsInfo &receiptSaleGoodsInfo)
{
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QRect textRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    QString goodsContent = QString("%1：%2").arg(nRowNum).arg(receiptSaleGoodsInfo.sName);

    m_pPainter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter,goodsContent );
    nYPos += nTextHeight;
    checkYPos(nYPos);
    const int nRowSpace = 2; // 行间距
    nYPos += nRowSpace;
    checkYPos(nYPos);

    int nStartXPos = nXPos;
    int nPriceWidth = 75 * m_nZoomWidth / m_nRealWidth; // 单价
    int nNumberWidth = 50 * m_nZoomWidth / m_nRealWidth; // 数量
    int nSumPriceWidth = m_nPaintWidth - nNumberWidth - nPriceWidth; // 金额

    // 单价
    QString sShowPrice = QString::number(receiptSaleGoodsInfo.fBatchPrice, 'f', 2);
    QRect priceRect(nStartXPos, nYPos, nPriceWidth, nTextHeight);
    m_pPainter->drawText(priceRect, Qt::AlignRight | Qt::AlignVCenter, sShowPrice);
    nStartXPos += nPriceWidth;

    // 数量

    QString sGoodsNum = QString::number(receiptSaleGoodsInfo.fShouldCount, 'f', 2);
    QRect numberRect(nStartXPos, nYPos, nNumberWidth, nTextHeight);
    m_pPainter->drawText(numberRect, Qt::AlignCenter, sGoodsNum);
    nStartXPos += nNumberWidth;

    // 金额
    QString sGoodsSumPrice = QString::number(receiptSaleGoodsInfo.fShouldTotal, 'f', 2);
    QRect sumPriceRect(nStartXPos, nYPos, nSumPriceWidth, nTextHeight);
    m_pPainter->drawText(sumPriceRect, Qt::AlignRight | Qt::AlignVCenter, sGoodsSumPrice);

    //
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintOutStockTopInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nSpace = 2;
    // 门店
    QString sShopName = QStringLiteral("门店：%1").arg(m_outstockPrintData.sShopName);
    QRect shopNameRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopNameRect, Qt::AlignLeft | Qt::AlignVCenter, sShopName);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 门店号
    QString sShopCode = QStringLiteral("门店号：%1").arg(m_outstockPrintData.sShopCode);
    QRect shopCodeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopCodeRect, Qt::AlignLeft | Qt::AlignVCenter, sShopCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 单号
    QString sOrderNum = QStringLiteral("单号：%1").arg(m_outstockPrintData.stockOrderInfo.sOrderNum);
    QRect orderNumRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderNumRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderNum);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 制单人
    QString sOrderMaker = QStringLiteral("制单人：%1").arg(m_outstockPrintData.stockOrderInfo.sMaker);
    QRect orderMakerRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderMakerRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderMaker);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 审核人
    QString sOrderChecker = QStringLiteral("审核人：%1").arg(m_outstockPrintData.stockOrderInfo.sChecker);
    QRect orderCheckerRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderCheckerRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderChecker);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 状态
    QString sOrderState = QStringLiteral("状态：%1").arg(EnumToString::stockSateToString(m_outstockPrintData.stockOrderInfo.nState));
    QRect orderStateRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderStateRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderState);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 制单时间
    QString sEffectTime = QStringLiteral("制单时间：%1").arg(m_outstockPrintData.stockOrderInfo.sMakeTime);
    QRect effectTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(effectTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sEffectTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    // 审核时间
    QString sCkTime = QStringLiteral("审核时间：%1").arg(m_outstockPrintData.stockOrderInfo.sCheckTime);
    QRect CkRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(CkRect, Qt::AlignLeft | Qt::AlignVCenter, sCkTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintOutStockGoodsList(const int &nXPos, int &nYPos)
{
    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    // 标题
    paintOutStockGoodsTitle(nXPos, nYPos);

    const int nOffy2 = 2;
    nYPos += nOffy2; // 微调, 标题与销售信息之间的间距
    checkYPos(nYPos);

    // 销售信息
    int nLen = m_outstockPrintData.stockInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        paintOutStockGoods(nXPos, nYPos, i + 1, m_outstockPrintData.stockInfoList[i]);
    }
}

void ReceiptPictureMaker::paintOutStockEndInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 10; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    // 打印金额
    QString sAmount = QStringLiteral("总金额：%1").arg(m_outstockPrintData.sTotal);
    QRect AmountRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(AmountRect, Qt::AlignLeft | Qt::AlignVCenter, sAmount);

    nYPos += 3*nOffY;
    // 打印时间
    QString sPrintTime = QStringLiteral("打印时间：%1").arg(m_outstockPrintData.sPrintTime);
    QRect printTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(printTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sPrintTime);
}

void ReceiptPictureMaker::paintOutStockGoodsTitle(const int &nXPos, int &nYPos)
{
    const int nOffY = 0; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;

    const int nGoodsNameWidth = 48* m_nZoomWidth / m_nRealWidth; // 品名
    const int nPriceWidth = 38* m_nZoomWidth / m_nRealWidth; // 单价
    const int nRealStockNumWidth = 38* m_nZoomWidth / m_nRealWidth; // 数量
    const int nAmountWidth = 33* m_nZoomWidth / m_nRealWidth; // 金额

    int nStartXPos = nXPos+c_nFontSize3;
    // 品名
    QRect goodsNameRect(nStartXPos, nYPos, nGoodsNameWidth, nTextHeight);
    m_pPainter->drawText(goodsNameRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("品名"));
    nStartXPos += nGoodsNameWidth;

    // 品名
    QRect priceRect(nStartXPos, nYPos, nPriceWidth, nTextHeight);
    m_pPainter->drawText(priceRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("单价"));
    nStartXPos += nPriceWidth;

    // 数量
    QRect realStockNumRect(nStartXPos, nYPos, nRealStockNumWidth, nTextHeight);
    m_pPainter->drawText(realStockNumRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("数量"));

    nStartXPos += nGoodsNameWidth;

    // 品名
    QRect amountRect(nStartXPos, nYPos, nAmountWidth, nTextHeight);
    m_pPainter->drawText(amountRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("金额"));
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintStockGoods(const int &nXPos, int &nYPos, int nRowNum, const StockOrderGoodsInfo &goodsInfo)
{
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QRect textRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    QString goodsContent = QString("%1：%2").arg(nRowNum).arg(goodsInfo.sName);
    m_pPainter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, goodsContent);
    nYPos += nTextHeight;
    checkYPos(nYPos);
    const int nRowSpace = 2; // 行间距
    nYPos += nRowSpace;
    checkYPos(nYPos);

    const int nLeftSpace = 120 * m_nZoomWidth / m_nRealWidth;
    int nStartXPos = nXPos + nLeftSpace;
    int nRealStockNumWidth = m_nPaintWidth - nLeftSpace; // 实盘数量

    // 实盘数量
    QRect realStockNumRect(nStartXPos, nYPos, nRealStockNumWidth, nTextHeight);
    m_pPainter->drawText(realStockNumRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(goodsInfo.fRealStockNum, 'f', 2));

    //
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintInStockGoods(const int &nXPos, int &nYPos, int nRowNum, const InStockOrderGoodsInfo &receiptSaleGoodsInfo)
{
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QRect textRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    QString goodsContent = QString("%1：%2").arg(nRowNum).arg(receiptSaleGoodsInfo.sName);

    m_pPainter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter,goodsContent );
    nYPos += nTextHeight;
    checkYPos(nYPos);
    const int nRowSpace = 2; // 行间距
    nYPos += nRowSpace;
    checkYPos(nYPos);

    int nStartXPos = nXPos;
    int nPriceWidth = 75 * m_nZoomWidth / m_nRealWidth; // 单价
    int nNumberWidth = 50 * m_nZoomWidth / m_nRealWidth; // 数量
    int nSumPriceWidth = m_nPaintWidth - nNumberWidth - nPriceWidth; // 金额

    // 单价
    QString sShowPrice = QString::number(receiptSaleGoodsInfo.fBatchPrice, 'f', 2);
    QRect priceRect(nStartXPos, nYPos, nPriceWidth, nTextHeight);
    m_pPainter->drawText(priceRect, Qt::AlignRight | Qt::AlignVCenter, sShowPrice);
    nStartXPos += nPriceWidth;

    // 数量

    QString sGoodsNum = QString::number(receiptSaleGoodsInfo.fShouldCount, 'f', 2);
    QRect numberRect(nStartXPos, nYPos, nNumberWidth, nTextHeight);
    m_pPainter->drawText(numberRect, Qt::AlignCenter, sGoodsNum);
    nStartXPos += nNumberWidth;

    // 金额
    QString sGoodsSumPrice = QString::number(receiptSaleGoodsInfo.fShouldTotal, 'f', 2);
    QRect sumPriceRect(nStartXPos, nYPos, nSumPriceWidth, nTextHeight);
    m_pPainter->drawText(sumPriceRect, Qt::AlignRight | Qt::AlignVCenter, sGoodsSumPrice);

    //
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintStockEndInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 10; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    // 打印时间
    QString sPrintTime = QStringLiteral("打印时间：%1").arg(m_stockPrintData.sPrintTime);
    QRect printTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(printTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sPrintTime);
}

void ReceiptPictureMaker::paintInStockEndInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 10; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    // 打印金额
    QString sAmount = QStringLiteral("总金额：%1").arg(m_instockPrintData.sTotal);
    QRect AmountRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(AmountRect, Qt::AlignLeft | Qt::AlignVCenter, sAmount);

    nYPos += 3*nOffY;
    // 打印时间
    QString sPrintTime = QStringLiteral("打印时间：%1").arg(m_instockPrintData.sPrintTime);
    QRect printTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(printTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sPrintTime);
}

void ReceiptPictureMaker::paintLogoutTopInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nSpace = 2;
    // 收银销售统计
    QString sSaleTitle = QStringLiteral("收银销售统计");
    QRect saleTitleRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(saleTitleRect, Qt::AlignLeft | Qt::AlignVCenter, sSaleTitle);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    // 门店
    QString sShopName = QString(QStringLiteral("门店：%1")).arg(m_logoutPrintData.sShopName);
    QRect shopNameRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopNameRect, Qt::AlignLeft | Qt::AlignVCenter, sShopName);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 门店号
    QString sShopCode = QString(QStringLiteral("门店号：%1")).arg(m_logoutPrintData.sShopCode);
    QRect shopCodeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopCodeRect, Qt::AlignLeft | Qt::AlignVCenter, sShopCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 款机号
    QString sKPosCode = QString(QStringLiteral("款机号：%1")).arg(m_logoutPrintData.sKPosCode);
    QRect kPosCodeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(kPosCodeRect, Qt::AlignLeft | Qt::AlignVCenter, sKPosCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 收银员
    QString sSaleman = QStringLiteral("收银员：%1").arg(m_logoutPrintData.sSaleman);
    QRect salemanRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(salemanRect, Qt::AlignLeft | Qt::AlignVCenter, sSaleman);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 登入时间
    QString sLoginTime = QString(QStringLiteral("登入时间：%1")).arg(m_logoutPrintData.sLoginTime);
    QRect loginTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(loginTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sLoginTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 登出时间
    QString sLogoutTime = QString(QStringLiteral("登出时间：%1")).arg(m_logoutPrintData.sLogoutTime);
    QRect logoutTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(logoutTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sLogoutTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    // 虚线 -----------------------------
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    QList<QString> keyList = m_logoutPrintData.payMethodMap.keys();
    int nLen = keyList.length();
    QString sKey = "";
    for (int i = 0; i < nLen; i++)
    {
        sKey = keyList[i];
        QString sPayMethodMoney = QString("%1：%2").arg(sKey).arg(m_logoutPrintData.payMethodMap.value(sKey)); // 线上支付
        QRect payMethodRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
        m_pPainter->drawText(payMethodRect, Qt::AlignLeft | Qt::AlignVCenter, sPayMethodMoney);
        nYPos += nTextHeight + nSpace;
        checkYPos(nYPos);
    }

    // 虚线 -----------------------------
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    // 销售笔数
    QString sSaleNum = QString(QStringLiteral("销售笔数：%1")).arg(m_logoutPrintData.nSaleNum);
    QRect saleNumRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(saleNumRect, Qt::AlignLeft | Qt::AlignVCenter, sSaleNum);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 实收金额
    QString sSaleMoney = QString(QStringLiteral("实收金额：%1")).arg(m_logoutPrintData.sSaleMoney);
    QRect saleMoneyRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(saleMoneyRect, Qt::AlignLeft | Qt::AlignVCenter, sSaleMoney);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 退货笔数
    QString sSaleRefund = QString(QStringLiteral("退货笔数：%1")).arg(m_logoutPrintData.nSaleRefundNum);
    QRect saleRefundRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(saleRefundRect, Qt::AlignLeft | Qt::AlignVCenter, sSaleRefund);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 退货金额
    QString sSaleRefundMoney = QString(QStringLiteral("退货金额：%1")).arg(m_logoutPrintData.sSaleRefundMoney);
    QRect saleRefundMoneyRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(saleRefundMoneyRect, Qt::AlignLeft | Qt::AlignVCenter, sSaleRefundMoney);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    // 虚线 -----------------------------
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    // 交款金额
    QString sSubmitSum = QString(QStringLiteral("交款金额：%1")).arg(m_logoutPrintData.sSubmitSum);
    QRect submitSumRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(submitSumRect, Qt::AlignLeft | Qt::AlignVCenter, sSubmitSum);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);

    // 虚线 -----------------------------
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    // 打印时间
    QString sPrintTime = QString(QStringLiteral("打印时间：%1")).arg(m_logoutPrintData.sPrintTime);
    QRect printTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(printTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sPrintTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintReportLossTopInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    const int nSpace = 2;
    // 门店
    QString sShopName = QString(QStringLiteral("门店：%1")).arg(m_reportLossPrintData.sShopName);
    QRect shopNameRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopNameRect, Qt::AlignLeft | Qt::AlignVCenter, sShopName);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 门店号
    QString sShopCode = QString(QStringLiteral("门店号：%1")).arg(m_reportLossPrintData.sShopCode);
    QRect shopCodeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(shopCodeRect, Qt::AlignLeft | Qt::AlignVCenter, sShopCode);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 单号
    QString sOrderNum = QString(QStringLiteral("单号：%1")).arg(m_reportLossPrintData.reportLossInfo.InfoID);
    QRect orderNumRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderNumRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderNum);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 制单人
    QString sOrderMaker = QString(QStringLiteral("制单人：%1")).arg(m_reportLossPrintData.reportLossInfo.createName);
    QRect orderMakerRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderMakerRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderMaker);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 制单时间
    QString createTime = QString(QStringLiteral("制单时间：%1")).arg(m_reportLossPrintData.reportLossInfo.createTime);
    QRect createTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(createTimeRect, Qt::AlignLeft | Qt::AlignVCenter, createTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 审核人
    QString sOrderChecker = QString(QStringLiteral("审核人：%1")).arg(m_reportLossPrintData.reportLossInfo.checkName);
    QRect orderCheckerRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderCheckerRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderChecker);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 审核时间
    QString sEffectTime = QString(QStringLiteral("审核时间：%1")).arg(m_reportLossPrintData.reportLossInfo.checkTime);
    QRect effectTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(effectTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sEffectTime);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
    // 状态
    QString status;
    if(m_reportLossPrintData.reportLossInfo.status == 0){
        status = QStringLiteral("未审核");
    }
    else if(m_reportLossPrintData.reportLossInfo.status == 1){
        status = QStringLiteral("已审核");
    }
    QString sOrderState = QString("状态：%1").arg(status);
    QRect orderStateRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(orderStateRect, Qt::AlignLeft | Qt::AlignVCenter, sOrderState);
    nYPos += nTextHeight + nSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintReportLossEndInfo(const int &nXPos, int &nYPos)
{
    const int nOffY = 10; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    // 打印时间
    QString sPrintTime = QString(QStringLiteral("打印时间：%1")).arg(m_reportLossPrintData.sPrintTime);
    QRect printTimeRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    m_pPainter->drawText(printTimeRect, Qt::AlignLeft | Qt::AlignVCenter, sPrintTime);
}

void ReceiptPictureMaker::paintReportLossListInfo(const int &nXPos, int &nYPos)
{
    // 虚线
    const int nOffY = 6; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    printDashLine(nXPos, nYPos);
    nYPos += nOffY;
    checkYPos(nYPos);

    // 标题
    paintReportLossListTitle(nXPos, nYPos);

    const int nOffy2 = 2;
    nYPos += nOffy2; // 微调, 标题与销售信息之间的间距
    checkYPos(nYPos);

    // 销售信息
    int nLen = m_reportLossPrintData.reportLossInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        paintReportLossGoods(nXPos, nYPos, i + 1, m_reportLossPrintData.reportLossInfoList[i]);
    }
}

void ReceiptPictureMaker::paintReportLossListTitle(const int &nXPos, int &nYPos)
{
    const int nOffY = 0; // 微调
    nYPos += nOffY;
    checkYPos(nYPos);
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;

    const int nGoodsNameWidth = 60 * m_nZoomWidth / m_nRealWidth; // 品名
    const int nGoodsPriceWidth = 32 * m_nZoomWidth / m_nRealWidth; // 单价
    const int nGoodsNumberWidth = 40 * m_nZoomWidth / m_nRealWidth; // 数量
    const int nGoodsSumPriceWidth = m_nPaintWidth - nGoodsNameWidth - nGoodsNumberWidth - nGoodsPriceWidth; // 金额

    int nStartXPos = nXPos;
    // 品名
    QRect goodsNameRect(nStartXPos, nYPos, nGoodsNameWidth, nTextHeight);
    m_pPainter->drawText(goodsNameRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("报损商品"));
    nStartXPos += nGoodsNameWidth;
    // 单价
    QRect goodsPriceRect(nStartXPos, nYPos, nGoodsPriceWidth, nTextHeight);
    m_pPainter->drawText(goodsPriceRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("类别"));
    nStartXPos += nGoodsPriceWidth;

    // 数量
    QRect goodsNumberRect(nStartXPos, nYPos, nGoodsNumberWidth, nTextHeight);
    m_pPainter->drawText(goodsNumberRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral("数量"));
    nStartXPos += nGoodsNumberWidth;
    // 金额
    QRect goodsSumPriceRect(nStartXPos, nYPos, nGoodsSumPriceWidth, nTextHeight);
    m_pPainter->drawText(goodsSumPriceRect, Qt::AlignRight | Qt::AlignVCenter, QStringLiteral("金额"));

    //
    nYPos += nTextHeight;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::paintReportLossGoods(const int &nXPos, int &nYPos, int nRowNum, const AddReportLossSelectInfo &goodsInfo)
{
    const int nfontSize = c_nFontSize3 * m_nZoomWidth / m_nRealWidth;
    QFont font;
    font.setFamily(c_sFontFamily);
    font.setBold(true);
    font.setPixelSize(nfontSize);
    m_pPainter->setFont(font);
    const int nTextHeight = nfontSize;
    QRect textRect(nXPos, nYPos, m_nPaintWidth, nTextHeight);
    QString sShowGoodsName = goodsInfo.sName;
    QString goodsContent = QString("%1:[%2]%3").arg(nRowNum).arg(goodsInfo.sCode).arg(sShowGoodsName);
    m_pPainter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, goodsContent);
    nYPos += nTextHeight;
    checkYPos(nYPos);
    const int nRowSpace = 2; // 行间距
    nYPos += nRowSpace;
    checkYPos(nYPos);

    int nStartXPos = nXPos;
    int nPriceWidth = 80 * m_nZoomWidth / m_nRealWidth; // 单价
    int nNumberWidth = 46 * m_nZoomWidth / m_nRealWidth; // 数量
    int nSumPriceWidth = m_nPaintWidth - nNumberWidth - nPriceWidth; // 金额

    // 单价
    QString sShowPrice = goodsInfo.sCategoryName;
    QRect priceRect(nStartXPos, nYPos, nPriceWidth, nTextHeight);
    m_pPainter->drawText(priceRect, Qt::AlignRight | Qt::AlignVCenter, sShowPrice);
    nStartXPos += nPriceWidth;

    // 数量
    QString num = QString("%1(%2)").arg(goodsInfo.sNumber).arg(goodsInfo.sUnit);
    QRect numberRect(nStartXPos, nYPos, nNumberWidth, nTextHeight);
    m_pPainter->drawText(numberRect, Qt::AlignCenter, num);
    nStartXPos += nNumberWidth;

    // 金额
    QString money = QString::number(goodsInfo.sMoney, 'f', 2);
    QRect sumPriceRect(nStartXPos, nYPos, nSumPriceWidth, nTextHeight);
    m_pPainter->drawText(sumPriceRect, Qt::AlignRight | Qt::AlignVCenter, money);

    //
    nYPos += nTextHeight + nRowSpace;
    checkYPos(nYPos);
}

void ReceiptPictureMaker::beginPrint()
{
    m_nSequence = 0;
    m_pPixmap = new QPixmap(m_nZoomWidth, m_nPictureMaxHeight);
    m_pPainter = new QPainter(m_pPixmap);
    m_pPainter->setBrush(QBrush(QColor("#ffffff")));
    m_pPainter->setPen(QPen(QColor("#ffffff")));
    m_pPainter->drawRect(m_pPixmap->rect());
    m_pPainter->setPen(QPen(QColor("#000000")));
}
