#ifndef STATEMENTCTR_H
#define STATEMENTCTR_H

#include <QObject>
#include "structData.h"
#include "enumData.h"
#include "ReceiptJson.h"

class StatementCtr : public QObject
{
    Q_OBJECT
public:
    explicit StatementCtr(QObject *parent = 0);
    ~StatementCtr();
public:
    bool getStatementInfo( StatementInfo &stStatementInfo );
    void insertPayDetailData( const PaymentDetailInfo &stPaymentDetail );
    // 结算支付
    void createPayInfoRequest(QString strOrderNum, EPayMethod ePayMethod, QString strBarCode, QString strPayAmt);
//    void memPayRequest(QString strOrderNum, EPayMethod ePayMethod, QString strCardNo, QString strPayAmt, int nInteg, QString strPayPasswd , QString strIntToAmt);
    void getPayStatusRequest( int nPayMethod, QString strPayOrderNum );
    void payRevokeRequest( EPayMethod ePayMethod, QString strPayOrderNum );
    void createPayMemberCardRequest(QString strOrderNum, QString strCardNo, QString strPayAmt, int nInteg, QString strPayPasswd, QString strIntToAmt); // 会员卡支付
    void updateMemberIntegralRequest(float fMoney, QString sCardNum, QString sOrderNum); // 更新会员积分

    void updateSaleHeadStatementInfo(QString strOrderNum, QString strDisAmt, QString strProfitLoss, QString strFactorAmt, QString strOddChange);
    void updateSaleHeadOutAmt( QString strOrderNum, QString strSimple );
    void updateSaleHeadFactorAmt( QString strOrderNum, QString strFactorAmt );
    void updateSmallChangeAmt( QString strOrderNum, QString strSmallChangeAmt );//更新抹零金额
    void updateSaleHeadOddChange( QString strOrderNum, QString strOddChange );//更新找零
    void updateSaleHeadComplete( QString strOrderNum, ESaleHeadStatus eSaleHeadStatus , QDateTime dtComplete);
    void findSaleHead(const QString &strOrderNum, SaleHead &stSaleHead);
    void updateSaleHead(const SaleHead &stSaleHead);
    void getOughtAmt(QString sOrderNum, float &fOughtAmt); // 获取应收金额
    void getFactorAmt(float& fMoney, QString sOrderNum);
    void getIntegralPay(float& fMoney, QString sOrderNum);
    void updateIntegral(int nGiftIntegral, QString sOrderNum); // 更新主表会员积分

    void printReceipt(QString strOrderNum , MemRegisterInfo_s stMemRegInfo);//小票
    void getPayDetailsList( QString strOrderNum, QList<PayDetail_s> &listPayDetails );
    void refundRequest(EPayMethod ePayMethod, QString strPayOrderNum , bool bVirtual);
    void getPayCodeRequest(QString sCardNum); // 获取储值卡信息

signals:
    void sigOnCreatePayStatus( int nCode, QString strMsg \
                               , QString strOrderNumS, QString strAuthCode, EPayMethod ePayMethod );
    void sig_GetPayStatus( int nCode, QString strMsg, QString strOrderNumS, int nTradeState );
    void sig_RevokePay( int nCode, QString strMsg, QString strOrderNum, int nRevoked );
    void sig_MemCardRevokePay( int nCode, QString strMsg, QString strOrderNum, int nRevoked, QString strMemCardBalance, int nMemCardIntegral );
    void sigOnPayStoreCardInfo(int nCode, QString sMsg, PayStoreCardInfo storeCardInfo); // 获取储值卡信息
    void sigOnCreatePayMemberCard(int nCode, QString sMsg, QString sBanlanceOrderNum, QString sIntegralOrderNum); // 会员卡支付
    void sigOnUpdateMemberIntegral(int nCode, QString sMsg, int nGiftIntegral, QString sOrderNum); // 结算后更新会员积分

public slots:
    void slot_GetCreatePayInfo(int nCode, QString strMsg \
                                , QString strOrderNumS, QString strAuthCode, EPayMethod ePayMethod );
    void slot_GetPayStatus( int nCode, QString strMsg, QString strOrderNumS, int nTradeState );
    void slot_RevokePay( int nCode, QString strMsg, QString strOrderNum , int nRevoked );
    void slot_MemCardRevokePay( int nCode, QString strMsg, QString strOrderNum, int nRevoked, QString strMemCardBalance, int nMemCardIntegral );
private:
    void initConnect();
private:
    ReceiptJson *m_pReceiptJson;
};

#endif // STATEMENTCTR_H
