#ifndef SALEDETIALAGENT_H
#define SALEDETIALAGENT_H

#include <QObject>
#include "receiptdata.h"
#include "structData.h"

class SaleDetialAgent : public QObject
{
    Q_OBJECT
public:
    static SaleDetialAgent* instance();
    void getSaleDetialListRequest();
    void getSaleReceiptListRequest(QString selectId);

private:
    explicit SaleDetialAgent(QObject *parent = 0);
    void initconnect();

private:
    static SaleDetialAgent* m_pInstance;

signals:
    void sigOnGetSaleDetialOrder(int nCode, QString sMsg, QList<ReceiptInfo> infoList);
    void sigOnGetSaleReceiptOrder(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> saleDetailsList, QList<PaymentDetailInfo> paymentInfoList);
};

#endif // SALEDETIALAGENT_H
