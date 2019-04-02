#include "PayDetailsTable.h"
#include "../util/KPosLog.h"
#include <QSqlQuery>
#include <QDebug>

PayDetailsTable::PayDetailsTable( QObject *parent )
    : DbBaseTable( parent )
    , m_pDatabase( NULL )
    , m_sTableName( "PayDetailsInfo" )
{

}

PayDetailsTable::~PayDetailsTable()
{

}

void PayDetailsTable::setDatabase( QSqlDatabase *pDatabase )
{
    m_pDatabase = pDatabase;
    if (m_pDatabase->isOpen())
    {
        createTable();
    }
}

void PayDetailsTable::insertPayDetails(const PayDetail_s &payDetailList)
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);

    QString sInsertData = QString("insert into %1 (OrderNum, PayOrderNum,PayMethod,PayMoney,PayIntegral"
                            ",PayStatus,IntToAmt,AuthCode,PayType,CreatTime,CompleteTime,Comment,IntExchangeAmt,isVirtual"
                            ")values('%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15')")
            .arg(m_sTableName).arg(payDetailList.strOrderNum)
            .arg(payDetailList.strPaymentOrderNum)
            .arg(payDetailList.nPayMethod).arg(payDetailList.fPayMoney).arg(payDetailList.nPayIntegral)
            .arg(payDetailList.nStatus).arg(payDetailList.fIntToAmt).arg(payDetailList.strAuthCode)
            .arg(payDetailList.nPayType)
            .arg(payDetailList.dtCreate.toString("yyyy-MM-dd hh:mm:ss"))
            .arg(payDetailList.dtComplete.toString("yyyy-MM-dd hh:mm:ss"))
            .arg(payDetailList.strComment)
            .arg(payDetailList.strIntExchangeAmt).arg(payDetailList.bVirtual);

    if(!query.exec(sInsertData))
    {
        KPosLog::instance()->writeErrorLog(QString("PayDetailsTable::insertPayDetails -- %1").arg(sInsertData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("PayDetailsTable::insertPayDetails -- %1").arg(sInsertData));
    }

    m_pReadWriteLock->unlock();
}

void PayDetailsTable::updateData( QString strPayOrderNum, QString strPayOrderNumS, EPaymentState ePayStatus, QDateTime dtComplete )
{
    //通过strPayOrderNum获取支付单号
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);

    QString strUpdateData = QString("update %1 set PayOrderNum = '%2',PayStatus = %3,CompleteTime = '%4'  where PayOrderNum = '%5' ")
            .arg(m_sTableName).arg( strPayOrderNumS ).arg( ePayStatus)
            .arg( dtComplete.toString( "yyyy-MM-dd hh:mm:ss") ).arg( strPayOrderNum );
    if(!query.exec(strUpdateData))
    {
        KPosLog::instance()->writeErrorLog(QString("PayDetailsTable::updateData -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("PayDetailsTable::updateData -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void PayDetailsTable::updateRefundStatus( QString strPayOrderNum )
{
    //通过strPayOrderNum获取支付单号
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);

    QDateTime dt = QDateTime::currentDateTime();
    QString strUpdateData = QString("update %1 set PayType = %2,CompleteTime = '%3'  where PayOrderNum = '%4' ")
            .arg(m_sTableName).arg( e_Refund )
            .arg( dt.toString( "yyyy-MM-dd hh:mm:ss") ).arg( strPayOrderNum );
    if(!query.exec(strUpdateData))
    {
        KPosLog::instance()->writeErrorLog(QString("PayDetailsTable::updateRefundStatus -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("PayDetailsTable::updateRefundStatus -- %1").arg(strUpdateData));
    }
    m_pReadWriteLock->unlock();
}

void PayDetailsTable::findData( QString strPayOrderNums, PayDetail_s &stPayDetails )
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString strPayDetailsData = QString("select * from %1 where PayOrderNum = '%2' ")
            .arg(m_sTableName).arg( strPayOrderNums );
    if(query.exec(strPayDetailsData))
    {
        bool b_first = query.first();
        if( b_first )
        {
            setSqlToPayDetails( stPayDetails, query );
        }
        KPosLog::instance()->writeDatabaseLog(QString("PayDetailsTable::findData -- %1").arg(strPayDetailsData));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("PayDetailsTable::findData -- %1").arg(strPayDetailsData));
    }

    m_pReadWriteLock->unlock();
}

bool PayDetailsTable::findData( QString strOrderNum, QList<PayDetail_s> &listPayDetails )
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    bool bHas = false;
    QString strQueryData = QString("select * from %1 where OrderNum = '%2' and (PayStatus=1 or PayStatus=3) ")
            .arg( m_sTableName ).arg( strOrderNum ) ;
    bool bExec = query.exec( strQueryData );

    if(bExec)
    {
        while(query.next())
        {//开始就先执行一次next()函数，那么query指向结果集的第一条记录
            PayDetail_s stPayDetail;
            setSqlToPayDetails( stPayDetail, query );
            listPayDetails.push_back( stPayDetail );
        }
        bHas = true;
        KPosLog::instance()->writeDatabaseLog(QString("PayDetailsTable::findData2 -- %1").arg(strQueryData));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("PayDetailsTable::findData2 -- %1").arg(strQueryData));
    }
    m_pReadWriteLock->unlock();

    return bHas;
}

//void PayDetailsTable::getAllPayDetailsInfo(QList<PayDetail_s> &payDetailList )
//{
//    Q_UNUSED( payDetailList )

//    m_pReadWriteLock->lockForRead();
////    QSqlQuery query(*m_pDatabase);
////    QString sqlTemp = QString("select OrderNum, PayOrderNum, PayMethod
////                                , PayMoney, PayStatus, PayType, CreatTime
////                                , CompleteTime, Comment from %1" ).arg(m_sTableName);
////    query.exec(sqlTemp);

//    m_pReadWriteLock->unlock();
//}

void PayDetailsTable::deleteData( QString strOrderNum )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strDeleteData = QString("delete from %1 where OrderNum = '%2' ")
            .arg(m_sTableName).arg( strOrderNum );
    if(!query.exec(strDeleteData))
    {
        KPosLog::instance()->writeErrorLog(QString("PayDetailsTable::deleteData -- %1").arg(strDeleteData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("PayDetailsTable::deleteData -- %1").arg(strDeleteData));
    }

    m_pReadWriteLock->unlock();
}

void PayDetailsTable::countSumMoney(float &fSumMoney, int nPayMethod, QList<QString> orderNumList)
{
    int nLen = orderNumList.length();
    if (nLen <= 0)
    {
        return;
    }

    m_pReadWriteLock->lockForRead();

    QString sSql = QString("select sum(PayMoney) from PayDetailsInfo where PayMethod='%1' and (").arg(nPayMethod); //PayStatus=1 and 1 and (OrderNum='0000217010700412' or OrderNum='0000217010700414'););
    for (int i = 0; i < nLen - 1; i++)
    {
        sSql.append(QString("OrderNum='%1' or ").arg(orderNumList[i]));
    }
    sSql.append(QString("OrderNum='%1')").arg(orderNumList[nLen-1]));

//    qDebug()<<sSql;
    QSqlQuery query(*m_pDatabase);
    if (query.exec(sSql))
    {
        if (query.next())
        {
           fSumMoney = query.value(0).toFloat();
        }
        else
        {
            // 日志
        }
        KPosLog::instance()->writeDatabaseLog(QString("PayDetailsTable::countSumMoney -- %1").arg(sSql));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("PayDetailsTable::countSumMoney -- %1").arg(sSql));
    }
    m_pReadWriteLock->unlock();
}

void PayDetailsTable::countSumMoney(float &fSumMoney, int nPayMethod, QString sOrderNum)
{
    QList<QString> orderNumList;
    orderNumList.append(sOrderNum);
    countSumMoney(fSumMoney, nPayMethod, orderNumList);
}

void PayDetailsTable::getPayIntegral(int &nIntegral, QString sOrderNum)
{
//    select sum(PayIntegral) from PayDetailsInfo where OrderNum = '0000317032800027' and PayMethod = 10;
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString sSql = QString("select sum(PayIntegral) from %1 where OrderNum = '%2' and PayMethod = %3")
            .arg( m_sTableName ).arg(sOrderNum).arg(e_IntegralToCansh);

    if (query.exec(sSql))
    {
        if (query.next())
        {
            nIntegral = query.value(0).toInt();
        }
        else
        {
            KPosLog::instance()->writeErrorLog(QString("PayDetailsTable::getIntegral1 -- %1").arg(sSql));
        }
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("PayDetailsTable::getIntegral2-- %1").arg(sSql));
    }
    m_pReadWriteLock->unlock();
}

//void PayDetailsTable::countOtherMoney(float &fSumMoney, QList<int> payMethodList, QList<QString> orderNumList)
//{
//    int nLen = orderNumList.length();
//    if (nLen <= 0)
//    {
//        return;
//    }

//    m_pReadWriteLock->lockForRead();

//    QString sSql = QString("select sum(PayMoney) from PayDetailsInfo where PayStatus=1 and ");
//    int nPayMethodLen = payMethodList.length();
//    for (int i = 0; i < nPayMethodLen - 1; i++)
//    {
//        sSql.append(QString("PayMethod != %1 and ").arg(payMethodList[i]));
//    }
//    if (nPayMethodLen - 1 >= 0)
//    {
//        sSql.append(QString("PayMethod != %1 and (").arg(payMethodList[nPayMethodLen - 1]));
//    }

//    for (int i = 0; i < nLen - 1; i++)
//    {
//        sSql.append(QString("OrderNum='%1' or ").arg(orderNumList[i]));
//    }
//    sSql.append(QString("OrderNum='%1')").arg(orderNumList[nLen-1]));

//    QSqlQuery query(*m_pDatabase);
//    if (query.exec(sSql))
//    {
//        if (query.next())
//        {
//           fSumMoney = query.value(0).toFloat();
//        }
//        else
//        {
//            // 日志
//        }
//    }
//    else
//    {
//        // 日志
//    }
//    m_pReadWriteLock->unlock();
//}

void PayDetailsTable::createTable()
{   /**
     * @field OrderNum 订单号
     * @field PayOrderNum 支付内部单号
     * @field PayMethod 支付方式
     * @field PayMoney  支付金额
     * @field PayIntegral 支付积分
     * @field PayStatus 支付状态
     * @field IntToAmt  积分抵现
     * @field AuthCode 支付授权码
     * @field PayType 支付类型
     * @field CreatTime 创建时间
     * @field CompleteTime 完成时间
     * @field Comment 备注
     * @field IntExchangeAmt 1积分抵价
     * @fiedl isVirtual  虚拟支付
     */
    QString newSqlTemp = QString("Create TABLE %1( OrderNum varchar, PayOrderNum varchar, "
                              "PayMethod integer, PayMoney float, PayIntegral integer, PayStatus integer, "
                              "IntToAmt float, AuthCode varchar, PayType integer, CreatTime DateTime, CompleteTime DateTime, "
                              "Comment varchar, IntExchangeAmt varchar, isVirtual bool)").arg(m_sTableName);
    QString oldTableSql= this->getTableSql(m_sTableName, m_pDatabase);
    if (newSqlTemp.compare(oldTableSql, Qt::CaseInsensitive) != 0)
    {
        this->dropTable(m_sTableName, m_pDatabase);
        m_pReadWriteLock->lockForWrite();
        QSqlQuery query(*m_pDatabase);
        query.exec(newSqlTemp);
        m_pReadWriteLock->unlock();
    }
}

void PayDetailsTable::setSqlToPayDetails( PayDetail_s &stPayDetails, const QSqlQuery& sqlQuery )
{
    stPayDetails.strOrderNum = sqlQuery.value( 0 ).toString();
    stPayDetails.strPaymentOrderNum = sqlQuery.value( 1 ).toString();
    stPayDetails.nPayMethod = sqlQuery.value( 2 ).toInt();
    stPayDetails.fPayMoney = sqlQuery.value( 3 ).toFloat();
    stPayDetails.nPayIntegral = sqlQuery.value( 4 ).toInt();
    stPayDetails.nStatus = sqlQuery.value( 5 ).toInt();
    stPayDetails.fIntToAmt = sqlQuery.value( 6 ).toFloat();
    stPayDetails.strAuthCode = sqlQuery.value( 7 ).toString();
    stPayDetails.nPayType = sqlQuery.value( 8 ).toInt();
    stPayDetails.dtCreate = sqlQuery.value( 9 ).toDateTime();
    stPayDetails.dtComplete = sqlQuery.value( 10 ).toDateTime();
    stPayDetails.strComment = sqlQuery.value( 11 ).toString();
    stPayDetails.strIntExchangeAmt = sqlQuery.value( 12 ).toString();
    stPayDetails.bVirtual = sqlQuery.value( 13 ).toBool();
}
