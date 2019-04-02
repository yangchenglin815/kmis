#include "CategoryTable.h"
#include "../util/KPosLog.h"
#include <QSqlQuery>
#include <QDebug>

CategoryTable::CategoryTable(QObject *parent)
    : DbBaseTable(parent)
    , m_pDatabase(NULL)
    , m_sTableName("CategoryInfo")
{

}

void CategoryTable::setDatabase(QSqlDatabase *pDatabase)
{
    m_pDatabase = pDatabase;
    if (m_pDatabase->isOpen())
    {
        createTable();
    }
}

bool CategoryTable::initCategory(const QList<CategoryInfo_s> &categoryInfoList)
{
    if (categoryInfoList.size() == 0)
    {
        return true;
    }

    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    m_pDatabase->transaction();
    QString sDeleteAllData = QString("delete from %1").arg(m_sTableName);
    query.exec(sDeleteAllData);
    int len = categoryInfoList.length();
    QString sInsertData = "";
    CategoryInfo_s categoryInfo;
    for (int i = 0; i < len; i++)
    {
        categoryInfo = categoryInfoList[i];
        QString goodsIdList = "";
        int goodsListLengh = categoryInfo.goodsIdList.length();
        for (int j = 0; j < goodsListLengh-1; j++)
        {
            goodsIdList.append(QString::number(categoryInfo.goodsIdList[j])).append(",");
        }
        if (goodsListLengh - 1 >= 0)
        {
            goodsIdList.append(QString::number(categoryInfo.goodsIdList[goodsListLengh - 1]));
        }

        sInsertData = QString("insert into %1 (KeyID, ID, name, isCustom, position, goodsIDList)"
                              "values('%2', %3, '%4', %5, %6, '%7')")
                .arg(m_sTableName).arg(categoryInfo.sKeyId).arg(categoryInfo.nId).arg(categoryInfo.sName)
                .arg(categoryInfo.bCustom?1:0).arg(i).arg(goodsIdList);
        if (!query.exec(sInsertData))
        {
            KPosLog::instance()->writeErrorLog(QString("CategoryTable::initCategory -- %1").arg(sInsertData));
        }
    }
    bool bSuccess = true;
    if (!m_pDatabase->commit())
    {
        m_pDatabase->rollback();
        bSuccess = false;
    }
    m_pReadWriteLock->unlock();
    return bSuccess;
}

void CategoryTable::getAllCategoryInfo(QList<CategoryInfo_s> &categoryInfoList)
{
    categoryInfoList.clear();
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString sqlTemp = QString("select KeyID, ID, name, isCustom, goodsIDList from %1 order by position").arg(m_sTableName);
    if (!query.exec(sqlTemp))
    {
        KPosLog::instance()->writeErrorLog(QString("CategoryTable::getAllCategoryInfo -- %1").arg(sqlTemp));
    }

    CategoryInfo_s categoryInfo;
    QString sGoodsIdList = "";
    QList<QString> goodsIdList;
    while (query.next())
    {
        categoryInfo.sKeyId = query.value(0).toString(); // nId和bCustom的组合
        categoryInfo.nId = query.value(1).toInt(); // 分类id
        categoryInfo.sName = query.value(2).toString(); // 分类名称
        categoryInfo.bCustom = query.value(3).toBool(); // 是否是自定义分类
        sGoodsIdList = query.value(4).toString();
        categoryInfo.goodsIdList.clear();
        if (!sGoodsIdList.isEmpty())
        {
            goodsIdList = sGoodsIdList.split(",");
            int nLen = goodsIdList.length();
            for (int i = 0; i < nLen; i++)
            {
                categoryInfo.goodsIdList.append(goodsIdList[i].toInt());// 商品ID列表
            }
        }
        categoryInfoList.append(categoryInfo);
    }
    m_pReadWriteLock->unlock();
}

void CategoryTable::createTable()
{
    /**
    KeyID -- ID和isCustom的组合
    ID -- 分类id
    code -- 分类编码
    name -- 分类名称
    isCustom -- 是否是自定义分类
    position -- 位置排序
    goodsIDList -- 商品ID列表
    */

    QString newSqlTemp = QString("CREATE TABLE %1(KeyID nvarchar PRIMARY KEY UNIQUE NOT NULL, ID int, name nvarchar, "
                                 "isCustom int, position int, goodsIDList nvarchar)").arg(m_sTableName);
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
