#ifndef SALEDETIALCTRL_H
#define SALEDETIALCTRL_H

#include <QObject>
#include "httpstructdata.h"
#include "receiptdata.h"
#include "SaleDetialAgent.h"
#include "structData.h"

class SaleDetialCtrl : public QObject
{
    Q_OBJECT
public:
    explicit SaleDetialCtrl(QObject *parent = 0);
    void getSaleDetialListRequest();
    void getSaleReceiptListRequest(QString selectId);

private:
    void initconnect();

signals:
    void sigOnGetSaleDetialOrder(int nCode, QString sMsg, QList<ReceiptInfo> infoList);
    void sigOnGetSaleReceiptOrder(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> saleDetailsList, QList<PaymentDetailInfo> paymentInfoList);
};

#endif // SALEDETIALCTRL_H
