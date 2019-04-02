#ifndef RECEIPTJSON_H
#define RECEIPTJSON_H

#include <QObject>
#include "structData.h"
#include "httpstructdata.h"

class ReceiptJson
{
public:
    explicit ReceiptJson();
    ~ReceiptJson();
public:
    QString createPaySaleHeadJson( const SaleHead &stSaleHead  );
    QJsonObject createSaleHeadObjectJson( const SaleHead &stSaleHead );
    QJsonArray createSaleHeadArrayJson( const QList<SaleHead> &listSaleHead );
    QJsonObject createSaleDetailsObjectJson( const SaleDetails &saleDetails, bool bRefund );
    QJsonArray createSaleDetailsArrayJson( const QList<SaleDetails> &listSaleDetails, bool bRefund);
    QString createSaleDetailsArrayJsonToString(const QList<SaleDetails> &listSaleDetails);
    QJsonObject createPayDetailsObjectJson( const PayDetail_s &stPayDetails );
    QJsonArray createPayDetailsArrayJson(const QList<PayDetail_s> &listPayDetails );
    QString createSaleArrayJson( const SaleHead &stSaleHead , const QList<SaleDetails> listSaleDetails );
    QString createSaleArrayJson( const SaleHead &stSaleHead , const QList<SaleDetails> listSaleDetails, const QList<PayDetail_s> &listPayDetails );
    QString createReceiptArrayJson( QList<SaleHead> listSaleHead );
};

#endif // RECEIPTJSON_H
