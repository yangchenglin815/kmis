#ifndef CLIENTCASHSUBMITTABLE_H
#define CLIENTCASHSUBMITTABLE_H

#include<QSqlDatabase>
#include "DbBaseTable.h"
#include "httpstructdata.h"

class ClientCashSubmitTable : public DbBaseTable
{
    Q_OBJECT
public:
    explicit ClientCashSubmitTable(QObject *parent = 0);
    void setDatabase(QSqlDatabase* pDatabase);
    QString initClentCash(const ClentCashSubmit_s& ClentCashSubmit);
    ClentCashSubmit_s getFirstClentCash();
    bool updateClentCashStatus(QString submitCode);
    QString getLastSubmitAt(QString userCode);
private:
    void createTable();
    QString getNewSubmitCode(QString user_code);

private:
    QSqlDatabase* m_pDatabase;
    QString m_sTableName; // 表名
};

#endif // CLIENTCASHSUBMITTABLE_H
