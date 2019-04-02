#include "LoginRecordTable.h"
#include "../util/KPosLog.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

LoginRecordTable::LoginRecordTable(QObject *parent)
    : DbBaseTable(parent)
    ,m_pDatabase(NULL)
    ,m_sTableName("LoginRecord")
{

}

void LoginRecordTable::setDatabase(QSqlDatabase *pDatabase)
{
    m_pDatabase = pDatabase;
    if (m_pDatabase->isOpen())
    {
        createTable();
    }
}

void LoginRecordTable::setCurUserId(int nUserId)
{
    m_nUserId = nUserId;
}

void LoginRecordTable::addLoginTime(QString sLoginTime)
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);

    QString sqlTemp = QString("insert into %1 (UserID, loginTime)values(%2,'%3')")
            .arg(m_sTableName).arg(m_nUserId).arg(sLoginTime);
    if(!query.exec(sqlTemp))
    {
        KPosLog::instance()->writeErrorLog(QString("LoginRecordTable::addLoginTime -- %1").arg(sqlTemp));
    }

    m_pReadWriteLock->unlock();
}

void LoginRecordTable::addLogoutTime(QString sLoginTime, QString sLogoutTime)
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString sqlTemp = QString("update %1 set logoutTime='%2' where UserID=%3 and loginTime='%4'")
            .arg(m_sTableName).arg(sLogoutTime).arg(m_nUserId).arg(sLoginTime);
    if(!query.exec(sqlTemp))
    {
        KPosLog::instance()->writeErrorLog(QString("LoginRecordTable::addLogoutTime -- %1").arg(sqlTemp));
    }
    m_pReadWriteLock->unlock();
}

void LoginRecordTable::createTable()
{
    /**
    ID -- 用户id
    loginTime -- 登入时间
    logoutTime -- 登出时间
    */
    QString newSqlTemp = QString("Create TABLE %1(UserID integer, loginTime nvarchar, logoutTime nvarchar)").arg(m_sTableName);

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

