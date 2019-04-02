#ifndef PAYMENTDETAILDLG_H
#define PAYMENTDETAILDLG_H

#include <QDialog>
#include "structData.h"

namespace Ui {
class PaymentDetailDlg;
}

/**
 * @brief The PaymentDetailDlg class 支付详情对话框类
 */
class PaymentDetailDlg : public QDialog
{
    Q_OBJECT

public:
    explicit PaymentDetailDlg(QWidget *parent = 0);
    ~PaymentDetailDlg();
public:
    void initData( QString strOrderNum, QString strSimpleAmt, QString strPaid, QString strReceive );
    void setPayDetailsList( QList<PaymentDetailInfo *> &listPayDetails );//数值支付详情列表
public slots:
    void slotPress(EPayMethod ePayMethod, QString strPayOrderNum, float fPayMoney , bool bVirtual);
    void slot_RevokePay( int nCode, QString strMsg, QString strPayOrderNum , int nRevoked);//撤销支付
    //会员卡撤销支付
    void slot_MemCardRevokePay( int nCode, QString strMsg, QString strPayOrderNum, int nRevoked, QString strMemCardBalance, int nMemCardIntegral );
    void slot_revokeAllAmt();//对所有已收金额退款
signals:
    void sig_closeDlg();
    void sigButtonPress( EPayMethod ePayMethod, QString strPayOrderNum, float fPayMoney, bool bVirtual );
    void sigButtonRelease( EPayMethod ePayMethod, QString strPayOrderNum );
    void sig_RevokePay( QString strPayOrderNum, QString strPaidAmt );
    /**
     * @brief sig_revokeAllAmt
     * @param strOrderNum   销售订单号
     * @param strPaidAmt    该订单已付金额
     */
    void sig_revokeAllAmt( QString strOrderNum, QString strPaidAmt );
    void sig_MemCardRevokePay( QString strPayOrderNum, QString strPayMoney, QString strMemCardBalance, int nMemCardIntegral );
private:
    void initCtrl();
    void initConnect();

private:
    Ui::PaymentDetailDlg *ui;
    QString m_sOrderNum;
    int m_nTitleHeight;
};

#endif // PAYMENTDETAILDLG_H
