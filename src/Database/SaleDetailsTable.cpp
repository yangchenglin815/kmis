#include "SaleDetailsTable.h"
#include <QDebug>
#include "CommonFun.h"
#include "../util/KPosLog.h"
#include "../data/constData.h"

SaleDetailsTable::SaleDetailsTable( QObject *parent )
    : DbBaseTable( parent )
    , m_pDatabase( NULL )
    , m_sTableName( "SaleDetailsInfo" )
{

}

SaleDetailsTable::~SaleDetailsTable()
{

}

void SaleDetailsTable::setDatabase( QSqlDatabase *pDatabase )
{
    m_pDatabase = pDatabase;
    if ( m_pDatabase->isOpen() )
    {
        createTable();
    }
}

void SaleDetailsTable::insertSaleDetails( const SaleDetails &stSaleDetails )
{
    m_pReadWriteLock->lockForWrite();

    QSqlQuery query(*m_pDatabase);

    QString sInsertData = QString("replace into %1 (ID,order_num,bar_code,goods_name"
                                  ",goods_id,goods_code,price,number,sum_price,unit"
                                  ",taste_type,goods_type,goods_spec,swap_price,swap_amt"
                                  ",pop_dis_amt,pop_dis_rate,grant_dis_rate,all_dis_amt"
                                  ",tax_rate,inp_bar_code,batch_no,prom_price,create_time,status,mem_price"
                                  ",refund_price,refund_num,refund_sum_price,goods_short_name)"
                                  "values('%2','%3','%4','%5',%6,'%7',%8,%9,'%10','%11','%12','%13','%14','%15','%16'"
                                  ",'%17','%18','%19','%20','%21','%22','%23','%24','%25','%26','%27','%28','%29','%30','%31')")
            .arg(m_sTableName).arg( stSaleDetails.nSaleDetailPos ).arg( stSaleDetails.strOrderNum )
            .arg( stSaleDetails.strBarCode )
            .arg( stSaleDetails.strGoodsName ).arg( stSaleDetails.nGoodsId )
            .arg( stSaleDetails.goodsInfo.strGoodsCode ).arg( stSaleDetails.fPrice )
            .arg( stSaleDetails.goodsInfo.fNumber ).arg( stSaleDetails.strOrgSum )
            .arg( stSaleDetails.goodsInfo.sUnit ).arg( stSaleDetails.goodsInfo.nTasteType )
            .arg( stSaleDetails.goodsInfo.bStandard )
            .arg( stSaleDetails.strGoodsSpec ).arg( stSaleDetails.fSwapPrice ).arg( stSaleDetails.strSwapAmt )
            .arg( stSaleDetails.fPopDisAmt ).arg( stSaleDetails.fPopDisRate ).arg( stSaleDetails.fGrantDisRate )
            .arg( stSaleDetails.fAllDisAmt ).arg( stSaleDetails.fTaxRate )
            .arg( stSaleDetails.strInpBarCode ).arg( stSaleDetails.strBatchNo ).arg( stSaleDetails.strPromPrice )
            .arg( stSaleDetails.dtCreateTime.toString( "yyyy-MM-dd hh:mm:ss") )
            .arg( stSaleDetails.nStatus ).arg( stSaleDetails.fMemPrice ).arg( stSaleDetails.goodsInfo.fRefundPrice )
            .arg( stSaleDetails.goodsInfo.fRefundNumber ).arg( stSaleDetails.goodsInfo.sRefundSumPrice )
            .arg( stSaleDetails.goodsInfo.strGoodsShortName );

    if(!query.exec(sInsertData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::insertSaleDetails -- %1").arg(sInsertData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::insertSaleDetails -- %1").arg(sInsertData));
    }

    m_pReadWriteLock->unlock();
}

void SaleDetailsTable::updateSaleDetails( const SaleDetails &stSaleDetails )
{
    m_pReadWriteLock->lockForWrite();

    QSqlQuery query(*m_pDatabase);

    QString sInsertData = QString("replace into %1 (ID, order_num "
                            ", bar_code, goods_name, goods_id, goods_code"
                            ", price, number, sum_price, unit"
                            ", taste_type, goods_type, goods_spec, swap_price, swap_amt"
                            ", pop_dis_amt, pop_dis_rate, grant_dis_rate, all_dis_amt"
                            ", tax_rate, inp_bar_code, batch_no, prom_price, create_time, status,mem_price"
                            ", refund_price, refund_num, refund_sum_price, goods_short_name )"
                            "values('%2', '%3'"
                            ", '%4', '%5', %6, '%7', %8, %9, '%10', '%11', '%12', '%13', '%14', '%15', '%16', '%17'"
                            ", '%18', '%19', '%20', '%21', '%22', '%23', '%24', '%25', '%26','%27', '%28', '%29', '%30', '%31' )")
            .arg(m_sTableName).arg( stSaleDetails.nSaleDetailPos ).arg( stSaleDetails.strOrderNum )
            .arg( stSaleDetails.strBarCode )
            .arg( stSaleDetails.strGoodsName ).arg( stSaleDetails.nGoodsId )
            .arg( stSaleDetails.goodsInfo.strGoodsCode ).arg( stSaleDetails.fPrice )
            .arg( stSaleDetails.goodsInfo.fNumber ).arg( stSaleDetails.strOrgSum )
            .arg( stSaleDetails.goodsInfo.sUnit ).arg( stSaleDetails.goodsInfo.nTasteType )
            .arg( stSaleDetails.goodsInfo.bStandard )
            .arg( stSaleDetails.strGoodsSpec ).arg( stSaleDetails.fSwapPrice ).arg( stSaleDetails.strSwapAmt )
            .arg( stSaleDetails.fPopDisAmt ).arg( stSaleDetails.fPopDisRate ).arg( stSaleDetails.fGrantDisRate )
            .arg( stSaleDetails.fAllDisAmt ).arg( stSaleDetails.fTaxRate )
            .arg( stSaleDetails.strInpBarCode ).arg( stSaleDetails.strBatchNo )
            .arg( stSaleDetails.strPromPrice )
            .arg( stSaleDetails.dtCreateTime.toString( "yyyy-MM-dd hh:mm:ss") )
            .arg( stSaleDetails.nStatus )
            .arg( stSaleDetails.fMemPrice )
            .arg( stSaleDetails.goodsInfo.fRefundPrice )
            .arg( stSaleDetails.goodsInfo.fRefundNumber )
            .arg( stSaleDetails.goodsInfo.sRefundSumPrice )
            .arg( stSaleDetails.goodsInfo.strGoodsShortName );

    if(!query.exec(sInsertData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::updateSaleDetails -- %1").arg(sInsertData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::updateSaleDetails -- %1").arg(sInsertData));
    }

    m_pReadWriteLock->unlock();
}

void SaleDetailsTable::updateSaleDetails( const QString &strOrderNum, float fNumber, QString strSumPrice, int nGoodsId )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set number = %2, sum_price = '%3'  where order_num = '%4' and goods_id = %5")
            .arg(m_sTableName).arg( fNumber ).arg( strSumPrice ).arg( strOrderNum ).arg( nGoodsId );
    if(!query.exec( strUpdateData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::updateSaleDetails2 -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::updateSaleDetails2 -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleDetailsTable::deleteSaleDetails( const QString &strOrderNum )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strDeleteData = QString("delete from %1 where order_num = '%2' ").arg(m_sTableName).arg( strOrderNum );

    if(!query.exec(strDeleteData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::deleteSaleDetails -- %1").arg(strDeleteData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::deleteSaleDetails -- %1").arg(strDeleteData));
    }

    m_pReadWriteLock->unlock();
}

void SaleDetailsTable::deleteSaleDetails( const int nSaleDetailsPos )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strDeleteData = QString("delete from %1 where ID = %2 ").arg(m_sTableName).arg( nSaleDetailsPos );

    if(!query.exec(strDeleteData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::deleteSaleDetails2 -- %1").arg(strDeleteData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::deleteSaleDetails2 -- %1").arg(strDeleteData));
    }

    m_pReadWriteLock->unlock();
}

void SaleDetailsTable::cancelSaleDetails(const QString &strOrderNum)
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString sSql = QString("update %1 set status = %2 where order_num = '%3'").arg(m_sTableName).arg(c_nCancelSaleGoods).arg( strOrderNum );

    if(!query.exec(sSql))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::cancelSaleDetails -- %1").arg(sSql));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::cancelSaleDetails -- %1").arg(sSql));
    }

    m_pReadWriteLock->unlock();
}

void SaleDetailsTable::cancelSaleDetails(const int nSaleDetailsPos)
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString sSql = QString("update %1 set status = %2 where ID = %3 ").arg(m_sTableName).arg(c_nCancelSaleGoods).arg(nSaleDetailsPos);

    if(!query.exec(sSql))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::cancelSaleDetails2 -- %1").arg(sSql));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::cancelSaleDetails2 -- %1").arg(sSql));
    }

    m_pReadWriteLock->unlock();
}

bool SaleDetailsTable::findSaleDetails( const QString &strOrderNum, QList< SaleDetails> &listSaleDetails )
{
    m_pReadWriteLock->lockForRead();
    bool bHas = false;
    QSqlQuery query(*m_pDatabase);
    QString strQueryData = QString("select * from %1 where order_num = '%2' and status = %3").arg(m_sTableName).arg(strOrderNum).arg(c_nFinishSaleGoods);
    if(query.exec(strQueryData))
    {
        while( query.next() ) {//开始就先执行一次next()函数，那么query指向结果集的第一条记录
            SaleDetails stSaleDetails;
            setSqlToSaleDetails( stSaleDetails, query );
            listSaleDetails.push_back( stSaleDetails );
        }
        bHas = true;
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::findSaleDetails -- %1").arg(strQueryData));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::findSaleDetails -- %1").arg(strQueryData));
    }

    m_pReadWriteLock->unlock();
    return bHas;
}

void SaleDetailsTable::findAllSaleDetails(const QString &strOrderNum, QList<SaleDetails> &listSaleDetails)
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString strQueryData = QString("select * from %1 where order_num = '%2'").arg(m_sTableName).arg(strOrderNum);
    if(query.exec(strQueryData))
    {
        while( query.next() ) {//开始就先执行一次next()函数，那么query指向结果集的第一条记录
            SaleDetails stSaleDetails;
            setSqlToSaleDetails( stSaleDetails, query );
            listSaleDetails.push_back( stSaleDetails );
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::findAllSaleDetails -- %1").arg(strQueryData));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::findAllSaleDetails -- %1").arg(strQueryData));
    }

    m_pReadWriteLock->unlock();
}

float SaleDetailsTable::getRefundNum(QString sBarCode, const QList<QString> &refundOrderNumList)
{
    float fSum = 0.0f;
    int nLen = refundOrderNumList.length();
    if (nLen == 0)
    {
        return fSum;
    }

    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString sql = QString("select sum(refund_num) from %1 where bar_code='%2'and (")
            .arg(m_sTableName).arg(sBarCode);
    for (int i = 0; i < nLen - 1; i++)
    {
        sql.append(QString(" order_num='%1' or").arg(refundOrderNumList[i]));
    }
    sql.append(QString(" order_num='%1')").arg(refundOrderNumList[nLen-1]));


    if(query.exec(sql))
    {
        if (query.next())
        {
            fSum = query.value(0).toFloat();
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::getRefundNum -- %1").arg(sql));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::getRefundNum -- %1").arg(sql));
    }

    m_pReadWriteLock->unlock();

    return fSum;
}

int SaleDetailsTable::getLastSaleDetailsPos()
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString strQueryData = QString("select max(ID) from %1").arg(m_sTableName);

    int nLastId = -1;
    if(query.exec(strQueryData))
    {
        bool b_first = query.first();
        if(b_first)
        {
            nLastId = query.value(0).toInt();
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::getLastSaleDetailsPos -- %1").arg(strQueryData));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::getLastSaleDetailsPos -- %1").arg(strQueryData));
    }

    m_pReadWriteLock->unlock();
    return nLastId;
}

void SaleDetailsTable::getOughtAmt(QString sOrderNum, float &fOughtAmt)
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString strQueryData = QString("select sum(swap_amt) from %1 where order_num = '%2' and status = %3")
            .arg(m_sTableName).arg(sOrderNum).arg(c_nFinishSaleGoods);
    if(query.exec(strQueryData))
    {
        if(query.next())
        {
            fOughtAmt = query.value(0).toFloat();
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleDetailsTable::getLastSaleDetailsPos -- %1").arg(strQueryData));
    }
    else
    {
        fOughtAmt = 0.0f;
        KPosLog::instance()->writeErrorLog(QString("SaleDetailsTable::getLastSaleDetailsPos -- %1").arg(strQueryData));
    }

    m_pReadWriteLock->unlock();
}

void SaleDetailsTable::createTable()
{
    /**
     * @field ID 数据库中序号
     * @field order_num 订单号
     * @field bar_code  标品就用商品条码，非标品使用PLU码
     * @field goods_name 商品名称
     * @field goods_id 商品id
     * @field goods_code 商品编码
     * @field price 原单价
     * @field number 销售数量
     * @field sum_price 原销售金额
     * @field unit 商品单位
     * @field taste_type 口味
     * @field goods_type  商品类型：标品，非标品
     * @field goods_spec  商品规格
     * @field swap_price  实际成交单价
     * @field swap_amt    实际成交金额
     * @field pop_dis_amt 促销折扣
     * @field pop_dis_rate 促销折扣率
     * @field grant_dis_rate   临时折扣率
     * @field all_dis_amt 所有优惠金额
     * @field tax_rate    税率
     * @field inp_bar_code 扫描条码：临时称重品条码
     * @field batch_no    促销活动号（SJ使用中）
     * @field prom_price  促销改价单号
     * @field create_time 创建时间
     * @field status      正在进行，取消，完成
     * @field mem_price   会员价
     * @field refund_price 退款单价
     * @field refund_num   退款数量
     * @field refund_sum_price 退款总价
     * @field goods_short_name 商品简称
     */

    QString newSqlTemp = QString("Create TABLE %1(ID integer PRIMARY KEY UNIQUE NOT NULL"
                                ", order_num varchar"
                                ", bar_code varchar, goods_name varchar, goods_id integer"
                                ", goods_code varchar, price float"
                                ", number float, sum_price varchar, unit varchar"
                                ", taste_type integer, goods_type bool"
                                ", goods_spec varchar, swap_price float"
                                ", swap_amt float, pop_dis_amt float, pop_dis_rate float"
                                ", grant_dis_rate float, all_dis_amt float"
                                ", tax_rate float, inp_bar_code varchar, batch_no varchar"
                                ", prom_price varchar, create_time DateTime, status integer"
                                ", mem_price float, refund_price float, refund_num float"
                                ", refund_sum_price varchar, goods_short_name varchar )")
            .arg(m_sTableName);

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

void SaleDetailsTable::setSqlToSaleDetails( SaleDetails &stSaleDetails, const QSqlQuery& sqlQuery )
{
    stSaleDetails.nSaleDetailPos = sqlQuery.value( 0 ).toInt();
    stSaleDetails.strOrderNum = sqlQuery.value( 1 ).toString();
    stSaleDetails.strBarCode = sqlQuery.value( 2 ).toString();
    stSaleDetails.strGoodsName = sqlQuery.value( 3 ).toString();
    stSaleDetails.nGoodsId = sqlQuery.value( 4 ).toInt();

    stSaleDetails.goodsInfo.nSaleDetailPos = stSaleDetails.nSaleDetailPos;
    stSaleDetails.goodsInfo.nGoodsId = stSaleDetails.nGoodsId;
    stSaleDetails.goodsInfo.strGoodsCode = sqlQuery.value( 5 ).toString();
    stSaleDetails.goodsInfo.sGoodsName = stSaleDetails.strGoodsName;
    stSaleDetails.fPrice = sqlQuery.value( 6 ).toFloat();
    stSaleDetails.goodsInfo.fNumber = sqlQuery.value( 7 ).toFloat();
    stSaleDetails.goodsInfo.sSumPrice = sqlQuery.value( 8 ).toString();
    stSaleDetails.goodsInfo.sUnit = sqlQuery.value( 9 ).toString();
    stSaleDetails.goodsInfo.nTasteType = sqlQuery.value( 10 ).toInt();
    stSaleDetails.goodsInfo.bStandard = sqlQuery.value( 11 ).toBool();
    stSaleDetails.goodsInfo.bSelectStatus = false;

    stSaleDetails.strGoodsSpec = sqlQuery.value( 12 ).toString();
    stSaleDetails.fSwapPrice = sqlQuery.value( 13 ).toFloat();
    stSaleDetails.goodsInfo.fPrice = stSaleDetails.fSwapPrice;
    float fSwapAmt = sqlQuery.value( 14 ).toFloat();
    stSaleDetails.strSwapAmt = CommonFun::floatToString( fSwapAmt );
    stSaleDetails.goodsInfo.sSumPrice = stSaleDetails.strSwapAmt;
    stSaleDetails.fPopDisAmt = sqlQuery.value( 15 ).toFloat();
    stSaleDetails.fPopDisRate = sqlQuery.value( 16 ).toFloat();
    stSaleDetails.fGrantDisRate = sqlQuery.value( 17 ).toFloat();

    stSaleDetails.fAllDisAmt = sqlQuery.value( 18 ).toFloat();
    stSaleDetails.fTaxRate = sqlQuery.value( 19 ).toFloat();
    stSaleDetails.strInpBarCode = sqlQuery.value( 20 ).toString();
    stSaleDetails.strBatchNo = sqlQuery.value( 21 ).toString();
    stSaleDetails.strPromPrice = sqlQuery.value( 22 ).toString();
    stSaleDetails.dtCreateTime = sqlQuery.value( 23 ).toDateTime();
    stSaleDetails.nStatus = sqlQuery.value( 24 ).toInt();
    stSaleDetails.fMemPrice = sqlQuery.value( 25 ).toFloat();
    stSaleDetails.goodsInfo.fRefundPrice = sqlQuery.value( 26 ).toFloat();
    stSaleDetails.goodsInfo.fRefundNumber = sqlQuery.value( 27 ).toFloat();
    stSaleDetails.goodsInfo.sRefundSumPrice = sqlQuery.value( 28 ).toString();
    stSaleDetails.goodsInfo.strGoodsShortName = sqlQuery.value( 29 ).toString();
}
