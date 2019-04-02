#ifndef LOGINRECORDTABLE_H
#define LOGINRECORDTABLE_H

#include "DbBaseTable.h"
#include "../data/httpstructdata.h"

class LoginRecordTable : public DbBaseTable
{
    Q_OBJECT
public:
    explicit LoginRecordTable(QObject *parent = 0);
    void setDatabase(QSqlDatabase* pDatabase);
    void setCurUserId(int nUserId);
    void addLoginTime(QString sLoginTime);
    void addLogoutTime(QString sLoginTime, QString sLogoutTime);

private:
    void createTable();

private:
    QSqlDatabase* m_pDatabase;
    QString m_sTableName; // 表名
    int m_nUserId;
};

#endif // LOGINRECORDTABLE_H
