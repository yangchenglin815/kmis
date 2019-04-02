#ifndef SALEHEADTABLE_H
#define SALEHEADTABLE_H

#include<QSqlDatabase>
#include "DbBaseTable.h"
#include "structData.h"
#include "enumData.h"
#include <QSqlQuery>

class SaleHeadTable : public DbBaseTable
{
    Q_OBJECT
public:
    explicit SaleHeadTable( QObject *parent = 0 );
    ~SaleHeadTable();
public: 
    void setDatabase( QSqlDatabase *pDatabase );

    void replaceSaleHead( const SaleHead &stSaleHead );
    void updateStatus( const QString &strOrderNum, const ESaleHeadStatus &eSaleHeadStatus );
    void updateStatus( const QString &strOrderNum, const ESaleHeadStatus &eSaleHeadStatus , const QDateTime &dtFactorTime );
    void updateCompleteTime( const QString &strOrderNum, const QDateTime &dtCompleteTime );
    void updateUploadTime( const QString &strOrderNum, const QDateTime &dtUpload );
    void updateUploadStatus( QString strOrderNum, EUploadReceiptStatus eUploadStatus );

    void updateStatementInfo(QString strOrderNum, QString strDisAmt, QString strProfitLoss, QString strFactorAmt, QString strOddChange);
    void updateOutAmt(QString strOrderNum, QString strSimple );
    void updateFactorAMt( QString strOrderNum, QString strFactorAmt );
    void updateSmallChangeAmt( QString strOrderNum, QString strSmallChange );//更新抹零金额
    void updateOddChange( QString strOrderNum, QString strOddChange);
    void updateMemInfo( QString strOrderNum, MemRegisterInfo_s stMemRegInfo );
    void deleteSaleHead( const QString &strOrderNum );
    void findSaleHead(int nDayBefore, QList<QString> &listOrderNum );//查找天数之前的数据
    bool findSaleHead(const QString &strOrderNum, SaleHead &stSaleHead);
//    bool findRefundSaleHead(QString sRefundOrderNum, SaleHead &saleHead);
    void getFinishRefundOrderNumList(QString sOrderNum, QList<QString>& refundOrderNumList); // 获取已完成退货单号列表
    void findAllUnUploadSale( QList<SaleHead> &listSaleHead );
    void findStatusToSaleHead( const ESaleHeadStatus &eSaleHeadStatus , QMap<int, SaleHead> &mapSaleHead );
    void clearSaleHead();
    int getLastSaleHeadId();
    int getPendingOrder();//获取所有挂单数量
    //获取最后一个结算成功的销售OrderNum
    QString findStatusToLastSaleOrderNum( const ESaleHeadStatus &eSaleHeadStatus );

    void countSaleMoney(int& nCount, float& fSaleMoney, QString sStartTime, QString sEndTime); // 统计销售金额
    void countSaleRefundMoney(int& nCount, float& fSaleMoney, QString sStartTime, QString sEndTime); // 统计退款金额
    void getOrderNumList(QList<QString>& orderNumList, QString sStartTime, QString sEndTime);
    void getFactorAmt(float& fMoney, QString sOrderNum);
    void updateIntegral(int nGiftIntegral, QString sOrderNum);

private:
    void createTable();
    void setSqlToSaleHead( SaleHead &stSaleHead, const QSqlQuery& sqlQuery );
    void countSumMoney(int& nCount, float& fSaleMoney, QString sStartTime, QString sEndTime, bool bRefund);
//    bool checkColumnExist( QString strColumnName );
//    bool addNewColumn( QString strColumnName );
private:
    QSqlDatabase* m_pDatabase;
    QString m_sTableName; // 表名
};

#endif // SALEHEADTABLE_H
