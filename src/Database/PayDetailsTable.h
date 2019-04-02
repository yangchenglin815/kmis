#ifndef PAYDETAILSTABLE_H
#define PAYDETAILSTABLE_H

#include<QSqlDatabase>
#include "DbBaseTable.h"
#include "httpstructdata.h"
#include "structData.h"

class PayDetailsTable : public DbBaseTable
{
public:
    explicit PayDetailsTable( QObject *parent = 0 );
    ~PayDetailsTable();
public:
    void setDatabase( QSqlDatabase* pDatabase );
    void insertPayDetails(const PayDetail_s &payDetailList);
    void updateData( QString strPayOrderNum, QString strPayOrderNumS, EPaymentState ePayStatus, QDateTime dtComplete );
    void updateRefundStatus( QString strPayOrderNum );
    void findData( QString strPayOrderNums, PayDetail_s &stPayDetails );
    bool findData( QString strOrderNum, QList<PayDetail_s> &listPayDetails );
//    void getAllPayDetailsInfo( QList<PayDetail_s>& payDetailList );
    void deleteData( QString strOrderNum );
    void countSumMoney(float& fSumMoney, int nPayMethod, QList<QString> orderNumList);
    void countSumMoney(float &fSumMoney, int nPayMethod, QString sOrderNum);
    void getPayIntegral(int& nIntegral, QString sOrderNum); // 获取本地积分
//    void countOtherMoney(float& fSumMoney, QList<int> payMethodList, QList<QString> orderNumList);

private:
    void createTable();
    void setSqlToPayDetails( PayDetail_s &stPayDetails, const QSqlQuery &sqlQuery );
private:
    QSqlDatabase* m_pDatabase;
    QString m_sTableName; // 表名
};

#endif // PAYDETAILSTABLE_H
