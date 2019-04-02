#ifndef GOODSINFOTABLE_H
#define GOODSINFOTABLE_H

#include<QSqlDatabase>
#include "DbBaseTable.h"
#include "httpstructdata.h"

class GoodsInfoTable : public DbBaseTable
{
    Q_OBJECT
public:
    explicit GoodsInfoTable(QObject *parent = 0);
    void setDatabase(QSqlDatabase* pDatabase);
    bool initAllGoods(const QList<GoodsInfo_s>& goodsInfoList, bool bDeleteTable = true);
    bool updateGoodsPrice(const QMap<QString, GoodsPriceInfo_s>& goodsPriceInfoMap);
    bool removeGoods(const QList<QString>& deleteList);

    void getAllGoodsInfo(QMap<QString, GoodsInfo_s> &goodsInfoMap);
//    bool searchGoods( QString strSearch, QList<GoodsInfo_s> &goodsInfoList );
private:
    void createTable();

private:
    QSqlDatabase* m_pDatabase;
    QString m_sTableName; // 表名
};

#endif // GOODSINFOTABLE_H
