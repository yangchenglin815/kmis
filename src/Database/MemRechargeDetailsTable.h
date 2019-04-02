#ifndef MEMRECHARGEDETAILSTABLE_H
#define MEMRECHARGEDETAILSTABLE_H

#include<QSqlDatabase>
#include "DbBaseTable.h"
#include "httpstructdata.h"
#include "structData.h"

class MemRechargeDetailsTable : public DbBaseTable
{
public:
    explicit MemRechargeDetailsTable(QObject *parent = 0);
    ~MemRechargeDetailsTable();
public:
    void setDatabase( QSqlDatabase* pDatabase );
    void insertMemRechargeDetails( MemRechargeInfo_s &stMemRechargeInfo );
    void deleteMemRechargeDetails(int nSaveDay );
private:
    void createTable();
//    void setSqlToMemRecharge( MemRechargeInfo_s &stMemRechargeInfo, const QSqlQuery &sqlQuery );
private:
    QSqlDatabase* m_pDatabase;
    QString m_sTableName; // 表名
};

#endif // MEMRECHARGEDETAILSTABLE_H
