#ifndef SALESMANINFOTABLE_H
#define SALESMANINFOTABLE_H

#include<QSqlDatabase>
#include "DbBaseTable.h"
#include "httpstructdata.h"

class SalesmanInfoTable : public DbBaseTable
{
    Q_OBJECT
public:
    SalesmanInfoTable(QObject* parent = NULL);
    void setDatabase(QSqlDatabase* pDatabase);
    void addSalesmanInfo(const SalemanInfo& salemanInfo);
    void updateSalesmanInfo(const SalemanInfo &salemanInfo);
    void deleteSalesmanInfo( const SalemanInfo &salemanInfo );
    void clearSalesmanInfo();
    void updateSalemanPasswd(QString user, QString newkey);
    SalemanInfo getSalemanInfo(int nID);
    SalemanInfo getUserdata(QString code);//获取收银员信息
    bool isAllowLogin(SalemanInfo& salemanInfo);

    void getAllSalesmanInfo(QList<SalemanInfo> &listSalemanInfo);

private:
    void createTable();
    void setSqlToSaleman(SalemanInfo &stSalemanInfo, const QSqlQuery &sqlQuery);
private:
    QSqlDatabase* m_pDatabase;
    QString m_sTableName; // 表名
};

#endif // SALESMANINFOTABLE_H
