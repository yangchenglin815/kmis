#include "GoodsInfoTable.h"
#include "../util/KPosLog.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

GoodsInfoTable::GoodsInfoTable(QObject *parent)
    : DbBaseTable(parent)
    ,m_pDatabase(NULL)
    ,m_sTableName("GoodsInfo")
{

}

void GoodsInfoTable::setDatabase(QSqlDatabase *pDatabase)
{
    m_pDatabase = pDatabase;
    if (m_pDatabase->isOpen())
    {
        createTable();
    }
}

bool GoodsInfoTable::initAllGoods(const QList<GoodsInfo_s> &goodsInfoList, bool bDeleteTable)
{
    m_pReadWriteLock->lockForWrite();
    m_pDatabase->transaction();
    QSqlQuery query(*m_pDatabase);
    if (bDeleteTable)
    {
        QString sDeleteAllData = QString("delete from %1").arg(m_sTableName);
        query.exec(sDeleteAllData);
    }
    int len = goodsInfoList.length();
    QString sInsertData = "";
    GoodsInfo_s goodsInfo;
    for (int i = 0; i < len; i++)
    {
        goodsInfo = goodsInfoList[i];
        sInsertData = QString("replace into %1 (barCode, ID , code, name, shortName, pinYinName, wuBiName, pluCode, "
                              "pluName, pluGrade, isStandard, saleUnit, price, memberPrice)values"
                              "('%2', %3, '%4', '%5', '%6', '%7', '%8', '%9', '%10', %11, %12, '%13', %14, %15)")
                .arg(m_sTableName).arg(goodsInfo.sBarCode).arg(goodsInfo.nId).arg(goodsInfo.sCode).arg(goodsInfo.sName)
                .arg(goodsInfo.sShortName).arg(goodsInfo.sPinYinName).arg(goodsInfo.sWuBiName).arg(goodsInfo.sPluCode)
                .arg(goodsInfo.sPluName).arg(goodsInfo.nPluGrade).arg(goodsInfo.bStandard?1:0).arg(goodsInfo.sSaleUnit)
                .arg(goodsInfo.goodsPriceInfo.fPrice).arg(goodsInfo.goodsPriceInfo.fMemberPrice);
        if (!query.exec(sInsertData))
        {
            KPosLog::instance()->writeErrorLog(QString("GoodsInfoTable::initAllGoods -- %1").arg(sInsertData));
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

bool GoodsInfoTable::updateGoodsPrice(const QMap<QString, GoodsPriceInfo_s> &goodsPriceInfoMap)
{
    if (goodsPriceInfoMap.size() == 0)
    {
        return true;
    }

    m_pReadWriteLock->lockForWrite();
    m_pDatabase->transaction();
    QSqlQuery query(*m_pDatabase);
    QList<QString> keyList = goodsPriceInfoMap.keys();
    int nLen = keyList.length();
    QString sKey = "";
    QString sUpdateSql = "";
    GoodsPriceInfo_s goodsPriceInfo;
    for (int i = 0; i < nLen; i++)
    {
        sKey = keyList[i];
        goodsPriceInfo = goodsPriceInfoMap.value(sKey);
        sUpdateSql = QString("update %1 set price=%2, memberPrice=%3 where barCode='%4'")
                .arg(m_sTableName).arg(goodsPriceInfo.fPrice).arg(goodsPriceInfo.fMemberPrice)
                .arg(sKey);
        if (!query.exec(sUpdateSql))
        {
            KPosLog::instance()->writeErrorLog(QString("GoodsInfoTable::updateGoodsPrice -- %1").arg(sUpdateSql));
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

bool GoodsInfoTable::removeGoods(const QList<QString> &deleteList)
{
    if (deleteList.size() == 0)
    {
        return true;
    }

    m_pReadWriteLock->lockForWrite();
    m_pDatabase->transaction();
    QSqlQuery query(*m_pDatabase);
    int nLen = deleteList.length();
    QString sDeleteSql = "";
    for (int i = 0; i < nLen; i++)
    {
        sDeleteSql = QString("delete %1 where barCode=%2").arg(m_sTableName).arg(deleteList[i]);
        query.exec(sDeleteSql);
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

void GoodsInfoTable::getAllGoodsInfo(QMap<QString, GoodsInfo_s> &goodsInfoMap)
{
    goodsInfoMap.clear();
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString sqlTemp = QString("select * from %1 order by ID").arg(m_sTableName);
    query.exec(sqlTemp);
    m_pReadWriteLock->unlock();

    GoodsInfo_s goodsInfo;
    while (query.next())
    {
        goodsInfo.sBarCode = query.value(0).toString();//商品条码（主键）
        goodsInfo.nId = query.value(1).toInt();//商品id
        goodsInfo.sCode = query.value(2).toString();//商品编码id
        goodsInfo.sName = query.value(3).toString();//商品名称
        goodsInfo.sShortName = query.value(4).toString();//商品简称
        goodsInfo.sPinYinName = query.value(5).toString(); // 拼音助记码
        goodsInfo.sWuBiName = query.value(6).toString(); // 五笔助记码
        goodsInfo.sPluCode = query.value(7).toString(); // plu码
        goodsInfo.sPluName = query.value(8).toString(); // 商品Plu名称
        goodsInfo.nPluGrade = query.value(9).toInt(); // 商品plu等级
        goodsInfo.bStandard = query.value(10).toBool();//是否标品
        goodsInfo.sSaleUnit = query.value(11).toString();//销售单位： 元/公斤
        goodsInfo.goodsPriceInfo.fPrice = query.value(12).toFloat();//商品价格
        goodsInfo.goodsPriceInfo.fMemberPrice = query.value(13).toFloat(); // 会员价
        goodsInfoMap.insert(goodsInfo.sBarCode, goodsInfo);
    }
}

//bool GoodsInfoTable::searchGoods( QString strSearch, QList<GoodsInfo_s> &listGoodsInfo )
//{
//    //code, barcode, name,
//    Q_UNUSED( listGoodsInfo )

//    if( strSearch.isEmpty() ) return true;

//    m_pReadWriteLock->lockForRead();
//    QSqlQuery query(*m_pDatabase);
//    QString sqlTemp = QString("select * from %1 where code like '%2%' or barcode like '%3%' \
//                                or name like '%4%' ").arg(m_sTableName).arg( strSearch ) \
//                              .arg( strSearch ).arg( strSearch );
//    bool bHas = query.exec(sqlTemp);
//    m_pReadWriteLock->unlock();

//    qDebug()<<"GoodsInfoTable::searchGoods"<<sqlTemp;

//    if( !bHas ) return false;

////    GoodsInfo_s goodsInfo;
////    while (query.next())
////    {
////        goodsInfo.nId = query.value(0).toInt();
////        goodsInfo.sCode = query.value(1).toString();
////        goodsInfo.sBarCode = query.value(2).toString();
////        goodsInfo.sName = query.value(3).toString();
////        goodsInfo.sShortName = query.value(4).toString();
////        goodsInfo.nCategoryId = query.value(5).toInt();
////        goodsInfo.fPrice = query.value(6).toFloat();
////        goodsInfo.fMemberPrice = query.value(7).toFloat();
////        goodsInfo.nTasteType = query.value(8).toInt();
////        goodsInfo.bStandard = query.value(9).toBool();
////        goodsInfo.sSaleUnit = query.value(10).toString();
////        listGoodsInfo.append(goodsInfo);
////    }

//    return bHas;
//}

void GoodsInfoTable::createTable()
{
    /**
    barCode -- 商品条码
    ID -- 商品id
    code -- 商品编码
    name -- 商品名称
    shortName -- 商品简称
    pinYinName -- 拼音助记码
    wuBiName -- 五笔助记码
    pluCode -- plu码
    pluName -- 商品Plu名称
    pluGrade -- plu等级
    isStandard -- 是否标品
    saleUnit -- 销售单位： 元/公斤
    price -- 商品价格
    memberPrice -- 会员价
    */

    QString newSqlTemp = QString("Create TABLE %1(barCode nvarchar PRIMARY KEY UNIQUE NOT NULL, ID int, code nvarchar,name nvarchar, "
                                 "shortName nvarchar, pinYinName nvarchar, wuBiName nvarchar, pluCode nvarchar, pluName nvarchar, "
                                 "pluGrade int, isStandard int, saleUnit nvarchar, price real, memberPrice real)").arg(m_sTableName);

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
