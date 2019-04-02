#ifndef CATEGORYTABLE_H
#define CATEGORYTABLE_H

#include <QSqlDatabase>
#include "DbBaseTable.h"
#include "httpstructdata.h"

class CategoryTable : public DbBaseTable
{
    Q_OBJECT
public:
    explicit CategoryTable(QObject *parent = 0);
    void setDatabase(QSqlDatabase* pDatabase);
    bool initCategory(const QList<CategoryInfo_s>& categoryInfoList);
    void getAllCategoryInfo(QList<CategoryInfo_s>& categoryInfoList);

private:
    void createTable();

private:
    QSqlDatabase* m_pDatabase;
    QString m_sTableName; // 表名
};

#endif // CATEGORYTABLE_H
