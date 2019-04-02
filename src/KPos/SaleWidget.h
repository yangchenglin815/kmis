#ifndef SALEWIDGET_H
#define SALEWIDGET_H

#include <QDialog>
#include "SaleCtrl.h"
#include "SellRefundCtr.h"
#include "PendingDlg.h"
#include "StatementDlg.h"
#include "MemberDlg.h"
#include "QuickAddDlg.h"
#include "OtherOperateWidget.h"
#include "../Sale_ui/RefundGoodsReasonDlg.h"
#include "../Sale_ui/NoReceiptRefundDlg.h"
#include "../Sale_ui/ReceiptRefundDlg.h"
#include <QTimer>

class SingleDiscountDlg;
class SaleDiscountDlg;
class SalemanInfoDlg;

namespace Ui {
class SaleWidget;
}
/**
 * @brief The SaleWidget class   销售类
 */
class SaleWidget : public QDialog
{
    Q_OBJECT

public:
    explicit SaleWidget(QWidget *parent = 0);
    ~SaleWidget();
public:
    void setRation( float fRatioWidth, float fRatioHeight );//设置窗口宽高比例
    void getCategoryInfoList(QList<CategoryInfo *> &categoryInfoList); // 获取已经初始化后的商品分类及商品数据
    void clearMemInfo();//清空会员信息
    void beginSale();//进入销售界面
    void setKPosSet( KPosSet &stKPosSet );//设置字段更新
    void updateOperatorBtn(const QList<KeySetInfo> &listHomeKey);//更新操作按钮
    void reInit();

private slots:
    void slot_backHomePage();//返回主页
    void slot_searchGoods(const QString &strGoods);//搜索商品
    void slot_getGoodsList( QString strCategoryId );//获取商品列表
    void slot_addGoodsToSaleList( GoodsInfo st_goodsInfo );//加载商品到销售明细表中
    void slot_stableInfo( EBalanceStandard_Ex balanceStandard_Ex, bool bStable );//更新台秤信息

    void slot_showOtherOperatorWidget();//显示其他操作按钮
    void slot_showMemDlg();//显示会员对话框
    void slot_showPendingDlg();//挂单解单对话框
    void slot_deleteSelectGoods();//删除选中商品
    void slot_clearAllGoods();//整单取消
    void slot_discount();//单品折扣，多品折扣
    void slot_saleDiscount();//整单折扣
    void slot_openCashBox();//钱箱
    void slot_refundGoods(); // 退货
    void slot_printLastReceipt();//打印上张小票
    void slot_fastCreateDocument(); // 快速建档
    void slot_peeling();//去皮
    void slot_otherOperator( int nKeyId );//按钮类型槽
    void slot_OtherOPeratorWidgetHide();//其他按钮隐藏
    void slot_closeDlg();
    void slot_Sure();

    void slot_addSaleHead( const QString& strOrderNum );//加载订单数据
    void slot_hidePendingDlg();//隐藏挂单对话框
    void slot_showStatementDlg(); // 显示结算对话框
    void slot_updateGoodsSumPrice(QString strSumPrice , QString strDisAmt);//更新商品合计金额

    void slot_updateSaleHead( StatementInfo stStatementInfo );//更新订单主表信息
    void slot_updateMemInfo( MemRegisterInfo_s stMemRegInfo );//更新会员信息
    void slot_replaceMemCard( QString strOldCardId, QString strNewCardId );//会员换卡

    void slot_categoryGoodsChanged();//分类商品信息更改处理
    void slot_keySetChanged();//按键设置修改

    void slot_onGetRefundGoodsReasonList(int nCode, QString sMsg, QList<RefundGoodsReason> reasonList);
    void slot_onSearchReceipt(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> saleDetailsList, float fIntegralPayMoney, int nIntegralPay);
    void slot_onMemInfoQueryForRefund(int nCode, QString sMsg, MemRegisterInfo_s memRegisterInfo);
    void slot_clickRefundReason(int nReasonId); // 点击退款原因
    void slot_confirmNoReceiptRefund(int nReasonId); // 确定无小票退款

    //关闭结算窗口
    void slot_closeStatementWnd();
    void slot_oddChange( QString strOddChange );//找零金额
    void slot_clickRefundItem();
    void on_refund1Button_clicked();
    void on_refund2Button_clicked();
    void on_refund3Button_clicked();
    void on_refund4Button_clicked();
    void on_refund5Button_clicked();
    void slot_updateCurTimer();//更新当前时间


    void slot_onChangeGoodsPrice();//商品数据修改

protected:
    void showEvent(QShowEvent *);

private:
    void init();
    void initCategoryWidget();//初始化分类窗口
    void initGoodsWidget();//初始化商品窗口
    void initShoppingInfo();
    void initConnect();
    void initDiscountWidget();
    void initMemInfo();
    void updateCategoryGoodsShow();
    bool isDiscount( const QList<SaleDetails> &listSaleDetails );
    void startCurTimer();
    void stopCurTimer();
    void refundButtonClick(QString sText);
    void initRefundButtonList(QList<QString> strList);
    void initNoReceiptKeyPage();
    bool searchSaleByPrice(QString sSearchText);
    bool searchRefundReceipt(QString sSearchText); // 搜索退货退货
    bool searchBarcodeScalesGoods(QString strGoods); // 搜索条码秤商品

signals:
    void sig_backHomePage();
    void sig_addGoodsToSaleList( SaleDetails stSaleDetailsInfo );
    void sig_delGoodsToSaleList( int nSaleDetailPos );
    void sig_clearGoodsToSaleList();
    void sig_loginMem( bool bMember );//登录会员
    void sig_lockScreen();//锁屏信号
    void sigCategoryGoodsChanged();

private:
    Ui::SaleWidget *ui;
    SaleCtrl *m_pSaleCtrl;//销售控制
    PendingDlg *m_pPendingDlg;//挂单对话框
    StatementDlg *m_pStatementDlg;//结算对话框
    MemberDlg *m_pMemberDlg;//会员对话框
    RefundGoodsReasonDlg* m_pRefundGoodsReasonDlg;
    NoReceiptRefundDlg* m_pNoReceiptRefundDlg;
    ReceiptRefundDlg* m_pReceiptRefundDlg;
    EBalanceStandard_Ex m_stBalanceStandardEx;//台秤
    int m_nCategoryColumn;
    int m_nGoodsOnePageCount;
    MemRegisterInfo_s m_stMemRegInfo;

    OtherOperateWidget *m_pOtherOperator;//其他操作按钮窗口
    SingleDiscountDlg *m_pSingleDisDlg;//单品打折对话框
    SaleDiscountDlg *m_pSaleDisDlg;//整单打折对话框
    bool m_bCategoryGoodsChanged;//分类商品修改状态
    bool m_bGoodsChangedDlg;//商品修改状态提示
    SalemanInfoDlg *m_pSalemanDlg;//业务员信息对话框

    KPosSet m_stKPosSet;
    bool m_bKeySetChanged;
    int m_nSellState; // 销售状态
    QList<QPushButton*> m_refundButtonList;
//    bool m_bSearchReceiptAgain;
    QTimer m_curTimer;
    int m_nTimerId;
    int m_nTimerCount;//按秒计数
    QuickAddDlg* m_pQuickAddDlg;
};

#endif // SALEWIDGET_H
