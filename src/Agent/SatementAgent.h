#ifndef SATEMENTAGENT_H
#define SATEMENTAGENT_H

#include <QObject>
#include "structData.h"
#include "enumData.h"
#include "ReceiptJson.h"

class SatementAgent : public QObject
{
    Q_OBJECT
public:
    static SatementAgent *Instance();
    static void Release();

    void setStatementInfo( StatementInfo &stStatementInfo );
    bool getStatementInfo( StatementInfo &stStatementInfo );
    void insertPayDetailData( const PaymentDetailInfo &stPaymentDetail );
    void insertPayDetailData(const PayDetail_s& payDetail_s);
    // 结算支付
    void createPayInfoRequest(EPayMethod ePayMethod, QString strBarCode, QString strPayAmt, QString strSale, QString sSaleDetailsJson);
//    void memPayRequest(EPayMethod ePayMethod, QString strCardNo, QString strPayAmt, QString strSale, int nInteg, QString strPayPasswd , QString strIntToAmt);
    void getPayStatusRequest( int nPayMethod, QString strPayOrderNum );
    void payRevokeRequest( EPayMethod ePayMethod, QString strPayOrderNum );
    void createPayMemberCardRequest(QString strCardNo, QString strPayAmt, QString strSale, int nInteg, QString strPayPasswd, QString strIntToAmt); // 会员卡支付
    void updateMemberIntegralRequest(float fMoney, QString sCardNum, QString sOrderNum, QString sRefundOrderNum = ""); // 更新会员积分

    void updateSaleHeadStatementInfo(QString strOrderNum, QString strDisAmt, QString strProfitLoss, QString strFactorAmt, QString strOddChange);
    void updateSaleHeadOutAmt( QString strOrderNum, QString strSimple );
    void updateSaleHeadFactorAmt( QString strOrderNum, QString strFactorAmt );
    void updateSmallChangeAmt( QString strOrderNum, QString strSmallChangeAmt );
    void updateSaleHeadOddChange(QString strOrderNum, QString strOddChange);
    void updateSaleHeadMemInfo( QString strOrderNum, MemRegisterInfo_s stMemRegInfo );
    void updateComplete( const QString &strOrderNum, const ESaleHeadStatus &eSaleHeadStatus, const QDateTime &dtComplete );
    int getUploadReceiptNum();//获取需要上传的小票数量
    void uploadAllReceipt();//上传所有未被上传的小票
    void uploadReceipt( QString strSale );
    void refundRequest(EPayMethod ePayMethod, QString strPayOrderNum , bool bVirtual);
    void updateRefundStatus( QString strPayOrderNum );
    void getPayCodeRequest(QString sCardNum); // 获取储值卡信息
    void getIntegralPayMoney(float& fMoney, QString sOrderNum); // 获取本地积分抵现
    void getPayIntegral(int& nIntegral, QString sOrderNum); // 获取本地积分
    void getFactorAmt(float& fMoney, QString sOrderNum);
    void updateIntegral(int nGiftIntegral, QString sOrderNum); // 更新主表会员积分

    //所有当前门店的用户信息
  //  void getAllUserInfo(QList<SalemanInfo> &listSalemanInfo);
public slots:
    void slot_onGetCreatePayStatus( int nCode, QString strMsg, QString strOrderNumS, QString strAuthCode , EPayMethod ePayMethod);
    void slot_onGetPayStatus( int nCode, QString strMsg, QString strOrderNumS, int nTradeState );
    void slot_noUploadReceiptSuc( int nCode, QString strMsg, QList<QString> strListOrderNum );
    void slot_onRevokePay( int nCode, QString strMsg, QString strOrderNum , int nRevoked );
    void slot_onMemCardRevokePay( int nCode, QString strMsg, QString strOrderNum, int nRevoked, QString strMemCardBalance, int nMemCardIntegral );

signals:
    void sigOnCreatePayStatus( int nCode, QString strMsg, QString strOrderNumS, QString strAuthCode, EPayMethod ePayMethod );
    void sigGetPayStatus( int nCode, QString strMsg, QString strOrderNumS, int nTradeState );
    void sigOnCreatePayMemberCard(int nCode, QString sMsg, QString sBanlanceOrderNum, QString sIntegralOrderNum);
    void sigRevokePay( int nCode, QString strMsg, QString strOrderNum, int nRevoked );
    void sigOnMemCardRevokePay( int nCode, QString strMsg, QString strOrderNum, int nRevoked, QString strMemCardBalance, int nMemCardIntegral );
    void sig_uploadReceiptSuc(bool bSuccess);
    void sigOnPayStoreCardInfo(int nCode, QString sMsg, PayStoreCardInfo storeCardInfo); // 获取储值卡信息
    void sigOnUpdateMemberIntegral(int nCode, QString sMsg, int nGiftIntegral, QString sOrderNum); // 结算后更新会员积分

private:
    explicit SatementAgent();
    void initConnect();

    void updateUploadReceiptNum( int nNoUploadReceiptNum );//更新小票上传的次数
private:
    static SatementAgent *m_pSatementAgent;

    StatementInfo m_stStatementInfo;
    int m_nUploadReceiptNum;//上传小票的次数
    ReceiptJson *m_pReceiptJson;
    bool m_bUploading;
};

#endif // SATEMENTAGENT_H
