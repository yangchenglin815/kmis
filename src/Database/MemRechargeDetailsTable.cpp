#include "MemRechargeDetailsTable.h"
#include "../util/KPosLog.h"
#include <QSqlQuery>
#include <QDebug>

MemRechargeDetailsTable::MemRechargeDetailsTable(QObject *parent)
    : DbBaseTable(parent)
    , m_pDatabase(NULL)
    , m_sTableName( "MemRecharge" )
{

}

MemRechargeDetailsTable::~MemRechargeDetailsTable()
{
}

void MemRechargeDetailsTable::setDatabase( QSqlDatabase *pDatabase )
{
    m_pDatabase = pDatabase;
    if (m_pDatabase->isOpen())
    {
        createTable();
    }
}

void MemRechargeDetailsTable::insertMemRechargeDetails( MemRechargeInfo_s &stMemRechargeInfo )
{
    QDateTime dtCur = QDateTime::currentDateTime();

    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);

    QString sInsertData = QString("insert into %1 (pay_code"
                            ", corpID, card_no, recharge_amt, pay_method"
                            ", gift_amt, gift_integral, shopID, user_id"
                            ", status,complete_time )"
                            "values('%2', '%3'"
                            ", '%4', '%5', %6, '%7', %8, %9, %10, %11,'%12' )")
            .arg(m_sTableName).arg( stMemRechargeInfo.strPayCode )
            .arg( stMemRechargeInfo.strCorpID ).arg( stMemRechargeInfo.strCardNo )
            .arg( stMemRechargeInfo.strRechargeAmt ).arg( stMemRechargeInfo.ePayMethod )
            .arg( stMemRechargeInfo.strGiftAmt ).arg( stMemRechargeInfo.nGiftIntegral )
            .arg( stMemRechargeInfo.nShopId ).arg( stMemRechargeInfo.nUserId ).arg( stMemRechargeInfo.nStatus  )
            .arg( dtCur.toString( "yyyy-MM-dd hh:mm:ss" ) );

    if(!query.exec(sInsertData))
    {
        KPosLog::instance()->writeErrorLog(QString("MemRechargeDetailsTable::insertMemRechargeDetails -- %1").arg(sInsertData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("MemRechargeDetailsTable::insertMemRechargeDetails -- %1").arg(sInsertData));
    }

    m_pReadWriteLock->unlock();
}

void MemRechargeDetailsTable::deleteMemRechargeDetails( int nSaveDay )
{
    qint64 nSaveDayTime = nSaveDay*86400;
    qint64 nCurTime = QDateTime::currentDateTime().toTime_t();
    qint64 nBefore = nCurTime - nSaveDayTime;

    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strDeleteData = QString("delete from %1 where (strftime('%s',complete_time)>0 and strftime('%s',complete_time)-'%2'<0 )")
            .arg(m_sTableName).arg( nBefore );
    if(!query.exec(strDeleteData))
    {
        KPosLog::instance()->writeErrorLog(QString("MemRechargeDetailsTable::deleteMemRechargeDetails -- %1").arg(strDeleteData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("MemRechargeDetailsTable::deleteMemRechargeDetails -- %1").arg(strDeleteData));
    }

    m_pReadWriteLock->unlock();
}

void MemRechargeDetailsTable::createTable()
{
    QString newSqlTemp = QString("CREATE TABLE %1(pay_code varchar, corpID varchar, card_no varchar, "
                                 "recharge_amt varchar, pay_method int, gift_amt varchar, gift_integral int, "
                                 "shopID int, user_id int, status int, complete_time datetime)").arg(m_sTableName);
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

//void MemRechargeDetailsTable::setSqlToMemRecharge( MemRechargeInfo_s &stMemRechargeInfo, const QSqlQuery &sqlQuery )
//{
//    Q_UNUSED( stMemRechargeInfo )
//    Q_UNUSED( sqlQuery )
////    stPayDetails.strOrderNum = sqlQuery.value( 0 ).toString();
////    stPayDetails.strPaymentOrderNum = sqlQuery.value( 1 ).toString();
////    stPayDetails.nPayMethod = sqlQuery.value( 2 ).toInt();
////    stPayDetails.fPayMoney = sqlQuery.value( 3 ).toFloat();
////    stPayDetails.nStatus = sqlQuery.value( 4 ).toInt();
////    stPayDetails.nPayType = sqlQuery.value( 5 ).toInt();
////    stPayDetails.dtCreate = sqlQuery.value( 6 ).toDateTime();
////    stPayDetails.dtComplete = sqlQuery.value( 7 ).toDateTime();
////    stPayDetails.strComment = sqlQuery.value( 8 ).toString();
//}
