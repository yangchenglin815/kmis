#ifndef DBBASETABLE_H
#define DBBASETABLE_H

#include <QObject>
#include <QReadWriteLock>
#include <QMutex>
#include <QSqlDatabase>

class DbBaseTable : public QObject
{
    Q_OBJECT
public:
    explicit DbBaseTable(QObject *parent = 0);
    bool createIndex(QString tableName, QString indexColName, QSqlDatabase* database);
    QString getTableSql(QString tableName, QSqlDatabase* database);
    bool dropTable(QString tableName, QSqlDatabase* database);

private:
    void initLock();

protected:
    static QReadWriteLock *m_pReadWriteLock; // 锁定QSqlDatabase

private:
    QMutex mutex;
};

#endif // DBBASETABLE_H
