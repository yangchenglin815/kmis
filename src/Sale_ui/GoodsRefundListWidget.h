#ifndef GOODSREFUNDLISTWIDGET_H
#define GOODSREFUNDLISTWIDGET_H

#include <QWidget>
#include "../data/structData.h"
#include "../Bussiness/SaleCtrl.h"
#include "ModifyGoodsNumDlg.h"

namespace Ui {
class GoodsRefundListWidget;
}

class GoodsRefundListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsRefundListWidget(QWidget *parent = 0);
    ~GoodsRefundListWidget();
    void initCtrl(SaleCtrl *pSaleCtrl);
    void initData(const SaleHead &saleHead, const QList<SaleDetails> &saleDetailsList, float fIntegralPayMoney, int nIntegralPay); // 有小票
    void appendData(const GoodsInfo& goodsInfo, float fNumber); // 无小票
    QList<int> getSelectIdList();
    int getSaleDetailsListLengh();
    void modifyRefundGoodsNum();
    void refundGoods();
    void refundAllGoods();
    int removeSelectGoods();
    void clearAllGoods();
    void setMemStatus(bool bMemStatus);
    bool getMemStatus();
    float getRefundCash();
    bool isMemberRefund(); // 是否是会员退货
    float getIntegralPayMoney(); // 获取积分抵现金额
    int getPayIntegral(); // 获取本地积分
    void confirmRefund(int reasonId, MemRegisterInfo_s memRegInfo);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void slot_modifyGoodsNum(int nSaleDetailPos, QString strGoodsNum);

private:
    void generateUI();
    void checkCurPageButtonState();
    void noReceiptGoodsToSaleDetail(SaleDetails& saleDetails, const GoodsInfo& goodsInfo);
    void initSaleHead(QString sReturnOrderNum);
    void initConnect();
    void converToReceiptRefundSaleHead(SaleHead &saleHead);
    void updateData();

signals:
    void sigClickItem();
    void sigUpdateSumPrice(QString sSumPrice, QString sDisAmt);

private:
    Ui::GoodsRefundListWidget *ui;
    QList<SaleDetails> m_saleDetailsList;
    int m_nOnePageCount;
    int m_nCurPage;
    int m_nTotalPage;
    SaleHead m_saleHead;
    ModifyGoodsNumDlg *m_pModifyGoodsNumDlg;
    bool m_bMemSell;//会员销售状态
    bool m_bReceipRefund;
    SaleCtrl *m_pSaleCtrl;
    float m_fIntegralPayMoney;
    int m_nIntegralPay;
};

#endif // GOODSREFUNDLISTWIDGET_H
