#ifndef SALEDETAILSAGENT_H
#define SALEDETAILSAGENT_H

#include <QObject>
#include "structData.h"

class SaleDetailsAgent : public QObject
{
    Q_OBJECT
public:
    explicit SaleDetailsAgent(QObject *parent = 0);
    ~SaleDetailsAgent();

    static SaleDetailsAgent *Instance();
    static void Release();

    void insertSaleDetailsTable( const SaleDetails &stSaleDetails );
    void updateSaleDetailsTable( const SaleDetails &stSaleDetails );
    void updateSaleDetailsNum( const QString &strOrderNum, float fNumber, QString strSumPrice, int nGoodsId );
    bool deleteSaleDetailsTable( const QString &strOrderNum );
    bool deleteSaleDetailsTable( const int nSaleDetailsPos );
    void cancelSaleDetailsState(const QString &strOrderNum);
    void cancelSaleDetailsState(const int nSaleDetailsPos);
    bool findSaleDetails( const QString &strOrderNum, QList<SaleDetails> &listSaleDetails );
    void findAllSaleDetails(const QString &strOrderNum, QList<SaleDetails> &listSaleDetails);
    void findRefundSaleDetails(const QString &sOrderNum, QList<SaleDetails> &saleDetailsList, const QList<QString>& refundOrderNumList);
    int getLastSaleDetailsPos();
    void getOughtAmt(QString sOrderNum, float &fOughtAmt); // 获取应收金额
    void getRefundGoodsReasonListRequest();
    void searchReceiptRequst(QString sOrderNum); // 搜索销售小票

private slots:
    void slot_onGetRefundGoodsReasonList(int nCode, QString sMsg, QList<RefundGoodsReason> reasonList);

private:
    void initConnect();

signals:
    void sigOnGetRefundGoodsReasonList(int nCode, QString sMsg, QList<RefundGoodsReason> reasonList);
    void sigOnSearchReceipt(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> saleDetailsList, float fIntegralPayMoney, int nIntegralPay);

private:
    static SaleDetailsAgent *m_pInstance;
};

#endif // SALEDETAILSAGENT_H
