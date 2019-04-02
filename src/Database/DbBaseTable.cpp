#include "DbBaseTable.h"
#include <QSqlQuery>
#include <QVariant>

QReadWriteLock *DbBaseTable::m_pReadWriteLock = NULL;

DbBaseTable::DbBaseTable(QObject *parent)
    : QObject(parent)
{
    initLock();
}

bool DbBaseTable::createIndex(QString tableName, QString indexColName, QSqlDatabase* database)
{
    m_pReadWriteLock->lockForRead();
    QString indexSql_1;
    indexSql_1.append(QString("CREATE INDEX %1_index1 on %1(%2)").arg(tableName).arg(indexColName));
    QSqlQuery query(*database);
    bool bFlag = query.exec(indexSql_1);
    m_pReadWriteLock->unlock();
    return bFlag;
}

QString DbBaseTable::getTableSql(QString tableName, QSqlDatabase *database)
{
    m_pReadWriteLock->lockForRead();
    QString sql = QString("select sql from sqlite_master where name='%1'").arg(tableName);
    QSqlQuery query(*database);
    query.exec(sql);
    QString str = "";
    if (query.next())
    {
        str = query.value(0).toString();
    }
    m_pReadWriteLock->unlock();
    return str;
}

bool DbBaseTable::dropTable(QString tableName, QSqlDatabase *database)
{
    m_pReadWriteLock->lockForWrite();
    QString sql = QString("DROP TABLE IF EXISTS %1").arg(tableName);
    QSqlQuery query(*database);
    bool bFlag = query.exec(sql);
    m_pReadWriteLock->unlock();
    return bFlag;
}

void DbBaseTable::initLock()
{
    mutex.lock();
    if (m_pReadWriteLock == NULL)
    {
        m_pReadWriteLock = new QReadWriteLock;
    }
    mutex.unlock();
}
