#ifndef PAYDETAILSAGENT_H
#define PAYDETAILSAGENT_H

#include <QObject>
#include "httpstructdata.h"
#include "structData.h"
#include "enumData.h"

class PayDetailsAgent : public QObject
{
    Q_OBJECT
public:
    explicit PayDetailsAgent( QObject *parent = 0 );
    ~PayDetailsAgent();
public:
    static PayDetailsAgent *Instance();
    static void Release();

    //增删改查
    void insertData( PayDetail_s &stPayDetails );

    /**
     * @brief updateData
     * @param strPayOrderNum  支付单号
     * @param strPayOrderNumS 内部定义的支付单号
     * @param ePayStatus   支付状态
     * @param dtComplete   支付完成时间
     */
    void updateData( QString strPayOrderNum, QString strPayOrderNumS, EPaymentState ePayStatus, QDateTime dtComplete );
    void findData( QString strPayOrderNumS, PayDetail_s &stPayDetails );
    void findData( QString strOrderNum, QList<PayDetail_s> &listPayDetails );
    void deleteData();
    void deletePayDetailsTable( QString strOrderNum );
private:
    static PayDetailsAgent *m_pInstance;
};

#endif // PAYDETAILSAGENT_H
