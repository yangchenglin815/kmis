#ifndef SALEHEADAGENT_H
#define SALEHEADAGENT_H

#include <QObject>
#include "structData.h"
#include "enumData.h"

class SaleHeadAgent : public QObject
{
    Q_OBJECT
public:
    explicit SaleHeadAgent(QObject *parent = 0);
    ~SaleHeadAgent();

    static SaleHeadAgent *Instance();
    static void Release();

    void insertSaleHeadTable( const SaleHead &stSaleHead );
    void updateStatus( const QString &strOrderNum, const ESaleHeadStatus &eSaleHeadStatus );
    void updateStatus( const QString &strOrderNum, const ESaleHeadStatus &eSaleHeadStatus
                                    , const QDateTime &dtFactorTime );
    void updateCompleteTime( const QString &strOrderNum, const QDateTime &dtCompleteTime );
    void deleteSaleHeadTable( const QString &strOrderNum );
    void findSaleHead( int nDayBefore, QList<QString> &listOrderNum );
    bool findSaleHead( const QString &strOrderNum, SaleHead &stSaleHead );
//    bool findRefundSaleHead(QString sRefundOrderNum, SaleHead &saleHead);
    void getFinishRefundOrderNumList(QString sOrderNum, QList<QString>& refundOrderNumList); // 获取已完成退货单号列表
    void findAllUnUploadSale( QList<SaleHead> &listSaleHead );
    void findStatusToSaleHead( const ESaleHeadStatus &eSaleHeadStatus, QMap<int, SaleHead> &mapSaleHead );
    void clearSaleHeadTable();
    int getLastSaleHeadId();
    int getPendingOrder();
    QString findStatusToLastSaleOrderNum( ESaleHeadStatus eSaleHeadStatus );
    void printReceipt(QString strOrderNum, const SaleHead &stSaleHead, const QList<SaleDetails> &listSaleDetails
                      , const QList<PayDetail_s> &listPayDetails , const MemRegisterInfo_s &stMemRegInfo);
    void printRefundReceipt(QString strOrderNum, const SaleHead &stSaleHead, const QList<SaleDetails> &listSaleDetails
                            , const QList<PayDetail_s> &listPayDetails , const MemRegisterInfo_s &stMemRegInfo);
signals:

public slots:
private:
    static SaleHeadAgent *m_pInstance;
    QString sLastOrderNumber;
};

#endif // SALEHEADAGENT_H
