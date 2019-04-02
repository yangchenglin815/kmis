#ifndef RECEIPTPICTUREMAKER_H
#define RECEIPTPICTUREMAKER_H

#include <QObject>
#include <QPainter>
#include "../data/setstructdata.h"
#include "structData.h"

class ReceiptPictureMaker : public QObject
{
    Q_OBJECT
public:
    static ReceiptPictureMaker* instance();
    static void setReceiptPrintOption(const ReceiptSet &receiptSet);
    void printReceipt(const ReceiptPrintData& receiptPrintData); // 打印销售小票
    void printMemRechargeReceipt(const MemRechargePrintInfo& stMemRechargePrintInfo );//打印会员充值小票
    void printAdjustPriceInfoReceipt(const AdjustPricePrintData& adjustPricePrintData); // 打印调价商品信息
    void printReportLossInfoReceipt(const ReportLossPrintData& reportLossPrintData);
    void printAllStockInfoReceipt(const StockPrintData& stockPrintData); // 打印库存信息小票
    void printInStockInfoReceipt(const InStockPrintData& stockPrintData); // 打印入库信息小票
    void printOutStockInfoReceipt(const OutStockPrintData& stockPrintData); // 打印出库信息小票
    void printAddedStockInfoReceipt(const StockPrintData& stockPrintData); // 打印库存新增信息小票
    void printLogoutReceipt(const LogoutPrintData& printData); // 登出小票
    void printSaleDetialReceipt(const SaleHead& saleHead, QList<PaymentDetailInfo>& paymentInfoList, QList<SaleDetails>& saleInfoList); // 打印销售明细小票
    //    void test();
    //    void testPrintReceipt(); // 测试用
    //    void initData(); // 测试用

private:
    explicit ReceiptPictureMaker();
    // 小票打印
    void paintBarCode(const int &nXPos, int &nYPos);//画条码
    void paintHeadContent(const int &nXPos, int &nYPos);//画头部文字
    void paintHeadWords(const int &nXPos, int &nYPos);//画头部语
    void paintShopInfo(const int &nXPos, int &nYPos);//画门店信息
    void printDashLine(const int &nXPos, int &nYPos);
    void paintSaleGoodsInfoList(const int &nXPos, int &nYPos);
    void paintGoodsInfoTitle(const int &nXPos, int &nYPos);
    void paintGoodsInfo(const int &nXPos, int &nYPos, int nRowNum, const ReceiptSaleGoodsInfo& receiptSaleGoodsInfo);
    void paintCategoryCountList(const int &nXPos, int &nYPos);
    void paintCategoryCount(const int &nXPos, int &nYPos, ReceiptCategoryCount& receiptCategoryCount);
    void paintSettlementInfo(const int &nXPos, int &nYPos);
    void paintSettleTypeCount(const int &nXPos, int &nYPos);
    void paintMemberInfo(const int &nXPos, int &nYPos);
    void paintTailContent(const int &nXPos, int &nYPos);
    void paintQRCode(const int &nXPos, int &nYPos); // 画二维码
    void checkYPos(int &nYPos);
    void savePixmap(const int nYPos);
    void printReceipt();
    void paintSaleDetialInfo(const int &nXPos, int &nYPos);

    // 会员充值小票打印
    void paintMemHeadWords( const int &nXPos, int &nYPos );
    void paintMemHeadContent( const int &nXPos, int &nYPos );
    void paintMemShopInfo( const int &nXPos, int &nYPos );
    void paintRechargeMemInfo( const int &nXPos, int &nYPos );
    void paintRechargeInfo( const int &nXPos, int &nYPos );
    void paintMemSigned( const int &nXPos, int &nYPos );//签字

    // 改价小票打印
    void paintAdjustPriceTopInfo(const int &nXPos, int &nYPos); // 打印门店信息
    void paintAdjustPriceGoodsTitle(const int &nXPos, int &nYPos); // 打印改价商品列表标题
    void paintAdjustPriceGoodsList(const int &nXPos, int &nYPos); // 打印改价商品列表
    void paintAdjustPriceGoods(const int &nXPos, int &nYPos, int nRowNum, const AdjustPriceGoodsInfo& goodsInfo); // 打印商品信息
    void paintAdjustEndInfo(const int &nXPos, int &nYPos); // 打印结尾信息

    // 盘点小票打印
    void paintStockTopInfo(const int &nXPos, int &nYPos); // 打印门店信息
    void paintAllStockGoodsList(const int &nXPos, int &nYPos); // 打印盘点商品列表
    void paintAddedStockGoodsList(const int &nXPos, int &nYPos); // 打印新增商品列表
    void paintStockGoodsTitle(const int &nXPos, int &nYPos); // 打印盘点商品列表标题


    void paintStockGoods(const int &nXPos, int &nYPos, int nRowNum, const StockOrderGoodsInfo& goodsInfo); // 打印商品信息

    void paintStockEndInfo(const int &nXPos, int &nYPos); // 打印结尾信息

    //入库部分
    void paintInStockGoods(const int &nXPos, int &nYPos, int nRowNum, const InStockOrderGoodsInfo& receiptSaleGoodsInfo); // 打印商品信息
    void paintInStockTopInfo(const int &nXPos, int &nYPos); // 打印门店信息
    void paintInStockGoodsList(const int &nXPos, int &nYPos); // 打印入库商品列表
    void paintInStockEndInfo(const int &nXPos, int &nYPos); // 打印入库小票结尾信息
    void paintInStockGoodsTitle(const int &nXPos, int &nYPos); // 打印盘点商品列表标题

    //出库部分
    void paintOutStockGoods(const int &nXPos, int &nYPos, int nRowNum, const OutStockOrderGoodsInfo& receiptSaleGoodsInfo); // 打印商品信息
    void paintOutStockTopInfo(const int &nXPos, int &nYPos); // 打印门店信息
    void paintOutStockGoodsList(const int &nXPos, int &nYPos); // 打印入库商品列表
    void paintOutStockEndInfo(const int &nXPos, int &nYPos); // 打印入库小票结尾信息
    void paintOutStockGoodsTitle(const int &nXPos, int &nYPos); // 打印盘点商品列表标题

    // 登出小票打印
    void paintLogoutTopInfo(const int &nXPos, int &nYPos);

    // 报损小票打印
    void paintReportLossTopInfo(const int &nXPos, int &nYPos);
    void paintReportLossEndInfo(const int &nXPos, int &nYPos);
    void paintReportLossListInfo(const int &nXPos, int &nYPos);
    void paintReportLossListTitle(const int &nXPos, int &nYPos);
    void paintReportLossGoods(const int &nXPos, int &nYPos, int nRowNum, const AddReportLossSelectInfo& goodsInfo); // 打印商品信息

    void beginPrint(); // 打印开始

private:
    static ReceiptPictureMaker* m_pInstance;
    static ReceiptSet m_receiptSet;
    ReceiptPrintData m_receiptPrintData; // 销售小票信息
    MemRechargePrintInfo m_stMemRechargePrintInfo; // 会员充值小票
    AdjustPricePrintData m_adjustPricePrintData; // 调价商品
    ReportLossPrintData m_reportLossPrintData; // 报损
    StockPrintData m_stockPrintData;
    InStockPrintData m_instockPrintData;
    OutStockPrintData m_outstockPrintData;
    LogoutPrintData m_logoutPrintData;
    SaleDetialPrintData m_saleDetialPrintData;
    int m_nLeftXPos; // 左边距 
    int m_nPictureMaxHeight; // 图片最大高度
    QPainter* m_pPainter;
    QPixmap* m_pPixmap;
    QList<QString> m_picturePathList;
    int m_nSequence;
    int m_nZoomWidth; // 打印机的缩放宽度， 打印机的dll会将450的图片缩放到174大小
    int m_nRealWidth; // 效果图的实际宽度
    int m_nPaintWidth;
};

#endif // RECEIPTPICTUREMAKER_H
