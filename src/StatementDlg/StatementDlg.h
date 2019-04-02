#ifndef STATEMENTDLG_H
#define STATEMENTDLG_H

#include <QDialog>
#include <QLineEdit>
#include "structData.h"
#include "StatementCtr.h"
#include "enumData.h"
#include "StatementMethodButton.h"
#include "PaymentDetailDlg.h"
#include "setstructdata.h"
#include "WarningDlg.h"
#include "AlipayRechargeDlg.h"

/**
 *结算对话框
 */

namespace Ui {
class StatementDlg;
}

class StatementDlg : public QDialog
{
    Q_OBJECT

public:
    explicit StatementDlg(QWidget *parent = 0);
    ~StatementDlg();
public:
    void initPayMethod();
    void updatePayMethod();

    void setStatementInfo( StatementInfo stStatementInfo );
    void setSaleDetailsModify( bool bModify );
    bool getSaleDetailsModify();
    void setMemInfo( MemRegisterInfo_s stMemInfo );
    void setDiscardZero( bool bDiscardZero );
    void updateSaleHeadMemInfo(QString strOrderNum, MemRegisterInfo_s stMemRegInfo);

    bool event( QEvent *event );
signals:
    void sig_wndClose();
    void sig_oddChange( QString strOddChangeAmt );
    void sig_updateSaleHead( StatementInfo stStatementInfo );
public slots:
    void slot_closeWnd();
    void slot_OnlineState( bool bOnline );

    //显示支付类型的窗口
    void slot_showPayMethodWnd();
    void slot_showCashPay();
    void slot_showUnionPay();
    void slot_showMemCardPay();
    void slot_storeCardPay();
    void slot_alipayPay();
    void slot_weChatPay();
    void slot_applePay();
    void slot_jdWalletPay();
    void slot_CouponPayWnd();
    void slot_VirtualPayWnd();
    void slot_virtualPaysWnd(); // 虚拟支付
    void showPayCityCardWnd();
    void slot_frontPage();
    void slot_nextPage();

    void slot_RefundPress(EPayMethod ePayMethod, QString strPayOrderNum , float fPayMoney , bool bVirtual);

private:
    void initCtrl();
    void initMemInfo();
    void initConnect();
    void initUnSelectPayMethod();

    void refreashDiscountMoney();
    void refreshReceivedAndFactMoney();

    void payMethodStatement();
    void updateSelectPayButton();

    void cashStatement();

    void storeCardStatement();

    void networkPayStatement();
    void appleStatement();
    void jdWalletStatement();
    void couponStatement();//优惠券支付
    void virtualPayStatement( QString strText );//虚拟支付
    void virtualPaysStatement(); // 虚拟支付

    void firstClick();
    int findDecimalsNum();
    bool findPoint();
    bool getCurFocusWnd( QLineEdit *&pEditWnd );
    void setPayDetailsText( int nPaySucNum, int nPayTotalNum );
    bool getPayDetail( PaymentDetailInfo &stPaymentDetail, float fFactAmt );
    int getTotalNum();
    void updatePayButton( int nPageNum );
    void clearPayButtonText();
//    void memPayRequest(EPayMethod ePayMethod, QString strCardNo, QString strPayAmt, int nInteg, QString strPayPasswd , QString strIntToAmt);

    void updateRoundWay(QString strText);//更新分的圆整方式
    QString updateCashRoundWay(QString strText);//更新现金的圆整方式
    QString updateOtherRoundWay(QString strText );//更新其他支付方式的圆整方式
    QString floatRoundWay(QString strAmt );
private slots:
    void slot_samllChange();//抹零处理

    void slot_setText( QString strText );
    void slot_deleteValue();
    void slot_clearZero();
    void slot_statement();//结算
    void slot_virtualPaysStatement(); // 虚拟支付结算
    void slot_memberStatement(); // 会员卡支付
    void slot_textChanged( QString strText );

    void slot_factor_amt();
    void slot_fifty_amt();
    void slot_hundred();
    void slot_two_hundred();

    void slot_cashSure();
    void slot_memPaySure();
    void slot_cashClose();
    void slot_PayWndClose();
    void slot_closeOddChangeDlg();
    void slot_virtualPay();
    void slot_virtualPays();

    void slot_couponPay();

    void slot_getPayStatus( int nPayMethod, QString strPayOrderNum );
    void slot_createPayInfo( EPayMethod ePayMethod, QString strBarCode, QString strPayAmt );
    void slot_memPayInfo( int nCode, QString strMsg, QString strOrderNumS, QString strAuthCode, EPayMethod ePayMethod );
    void slot_onPayStoreCardInfo(int nCode, QString sMsg, PayStoreCardInfo storeCardInfo);
    void slot_onCreatePayMemberCard(int nCode, QString sMsg, QString sBanlanceOrderNum, QString sIntegralOrderNum);
    void slot_onUpdateMemberIntegral(int nCode, QString sMsg, int nGiftIntegral, QString sOrderNum);

    void slot_payInfo( QString strOrderNumS, EStatementStatus eStatementStatus, QString sBarCode);
    void slot_payRevoke( QString strOrderNumS );//支付撤销
    void slot_RevokePay( QString strPayOrderNum, QString strPaidAmt);
    void slot_revokeAllAmt( QString strOrderNum, QString strPaidAmt );
    void slot_MemCardRevokePay(QString strPayOrderNum, QString strPaidAmt, QString strMemCardBalance, int nMemCardIntegral );

    void slot_showPayDetailsDlg();
    void slot_payInfoChanged();
    void on_cardIDStoreEdit_returnPressed();
    void on_statementStoreButton_clicked();
    void slot_confirmStoreCardPay();

    void on_factAmtCouponEdit_1_returnPressed();

private:
    void handleCouponInfo( int nCode, QString sMsg, QString strOrderNumS, QString strAuthCode );
    void handleMemPayInfo(int nCode, QString sMsg, QString sBanlanceOrderNum, QString sIntegralOrderNum);
    void handleStoreCardInfo(int nCode, QString sMsg, QString strOrderNumS, QString strAuthCode);
    void closeWnd(); // 关闭结算对话框

private:
    Ui::StatementDlg *ui;

    StatementCtr *m_pStatementCtr;
    PaymentDetailDlg *m_pPayDetailsDlg;

    StatementInfo m_stStatementInfo;
    int m_nClickedNum;//抹零按钮的点击次数
    float m_fSmallChange;//抹零金额
    bool m_bFirst;//首次点击
    bool m_bModify;//商品更改

    QList< StatementMethodButton *> m_listPayButton;
    QList<PayWayInfoSet> m_listPayInfo;
    QList<VirtualPayInfo> m_virtualPayList;
    PayWayInfoSet m_stCurPayInfo;
    EPaymentState m_eCurPayState;
    EPaymentType m_eCurPayType;

    int m_nOnePageCount;//一页的按钮个数
    int m_nCurPageNum;
    int m_nTotalPageNum;

    MemRegisterInfo_s m_stMemInfo;
    bool m_bOnline;
    bool m_bDiscardZero;//抹零
    PayStoreCardInfo m_storeCardInfo;

    AlipayRechargeDlg* m_pAlipayRechargeDlg;
};

#endif // STATEMENTDLG_H
