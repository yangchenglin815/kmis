#ifndef SALEDETAILSTABLE_H
#define SALEDETAILSTABLE_H

#include<QSqlDatabase>
#include <QSqlQuery>
#include "DbBaseTable.h"
#include "structData.h"

class SaleDetailsTable : public DbBaseTable
{
    Q_OBJECT
public:
    SaleDetailsTable( QObject *parent = 0 );
    ~SaleDetailsTable();
public:
    void setDatabase( QSqlDatabase *pDatabase );

    void insertSaleDetails( const SaleDetails& stSaleDetails );
    void updateSaleDetails( const SaleDetails& stSaleDetails );
    void updateSaleDetails( const QString &strOrderNum, float fNumber, QString strSumPrice, int nGoodsId );
    void deleteSaleDetails( const QString &strOrderNum );
    void deleteSaleDetails( const int nSaleDetailsPos );
    void cancelSaleDetails(const QString &strOrderNum);
    void cancelSaleDetails(const int nSaleDetailsPos);
    bool findSaleDetails( const QString &strOrderNum, QList<SaleDetails> &listSaleDetails );
    void findAllSaleDetails(const QString &strOrderNum, QList<SaleDetails> &listSaleDetails);
    float getRefundNum(QString sBarCode, const QList<QString>& refundOrderNumList); // 获取某一订单的某一商品的已退数量
    int getLastSaleDetailsPos();
    void getOughtAmt(QString sOrderNum, float &fOughtAmt); // 获取应收金额

private:
    void createTable();
    void setSqlToSaleDetails( SaleDetails &stSaleDetails, const QSqlQuery& sqlQuery );
private:
    QSqlDatabase* m_pDatabase;
    QString m_sTableName; // 表名
};

#endif // SALEDETAILSTABLE_H
