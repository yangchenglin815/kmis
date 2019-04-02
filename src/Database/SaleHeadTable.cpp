#include "SaleHeadTable.h"
#include "KPosLog.h"
#include "../util/KPosLog.h"
#include <QDebug>

SaleHeadTable::SaleHeadTable(QObject *parent)
    : DbBaseTable( parent )
    , m_pDatabase( NULL )
    , m_sTableName( "SaleHeadInfo" )
{

}

SaleHeadTable::~SaleHeadTable()
{

}

void SaleHeadTable::setDatabase( QSqlDatabase *pDatabase )
{
    m_pDatabase = pDatabase;
    if (m_pDatabase->isOpen())
    {
        createTable();
    }
}

void SaleHeadTable::replaceSaleHead( const SaleHead &stSaleHead )
{
    if( stSaleHead.nSerialNum < 0 ) return;
    m_pReadWriteLock->lockForWrite();

    QSqlQuery query(*m_pDatabase);
    //replace sqlite自动检测需要insert还是update
    QString sInsertData = QString("replace into %1 (ID,serial_num,pos_id,order_num"
                            ",sale_total_num,ought_amt,factor_amt,odd_change"
                            ",mem_card_id,mem_integer,dis_reason,grant_dis,all_dis_amt"
                            ",profit_loss,status,ntype,shop_id,upload_status"
                            ",create_time,factor_time,cost_time,complete_time,receipt_upload"
                            ",cashier_no,cashier_name,tran_status,sale_type,return_order_num"
                            ",return_reason, sale_mode, log, shopping_id, shopping_name, small_change, coupon_disAmt)"
                            "values('%2', '%3', '%4', '%5' "
                            ",'%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17','%18'"
                            ",'%19','%20','%21','%22','%23','%24','%25','%26','%27','%28','%29','%30'"
                            ",'%31','%32','%33','%34', '%35', '%36')")
            .arg(m_sTableName).arg(stSaleHead.nSaleHeadId).arg(stSaleHead.nSerialNum)
            .arg(stSaleHead.strPosId).arg(stSaleHead.strOrderNum)
            .arg(stSaleHead.nSaleTotalNum).arg(stSaleHead.fOughtAmt).arg(stSaleHead.fFactorAmt)
            .arg(stSaleHead.fOddChange).arg(stSaleHead.strMemCardId)
            .arg(stSaleHead.nMemInteger).arg(stSaleHead.strDisReason).arg(stSaleHead.fGrantDisRate)
            .arg(stSaleHead.fAllDisAmt).arg(stSaleHead.fProfitLoss).arg(stSaleHead.nStatus)
            .arg(stSaleHead.nType).arg(stSaleHead.nShopId).arg(stSaleHead.eUploadStatus)
            .arg(stSaleHead.dtCreateTime.toString("yyyy-MM-dd hh:mm:ss"))
            .arg(stSaleHead.dtFactorTime.toString("yyyy-MM-dd hh:mm:ss"))
            .arg(stSaleHead.nCostTime)
            .arg(stSaleHead.dtCompleteTime.toString("yyyy-MM-dd hh:mm:ss"))
            .arg(stSaleHead.dtReceiptUpload.toString("yyyy-MM-dd hh:mm:ss"))
            .arg(stSaleHead.nCashierId).arg(stSaleHead.strCashierName)
            .arg(stSaleHead.nTranStatus).arg(stSaleHead.nSaleType).arg(stSaleHead.strReturnOrderNum)
            .arg(stSaleHead.strReturnReason).arg(stSaleHead.nSaleMode).arg(stSaleHead.strLog)
            .arg( stSaleHead.nShoppingId ).arg( stSaleHead.strShoppingName ).arg(stSaleHead.sSmallChangeAmt)
            .arg(stSaleHead.fCouponDisAmt);
    if(!query.exec(sInsertData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::replaceSaleHead -- %1").arg(sInsertData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::replaceSaleHead -- %1").arg(sInsertData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateStatus( const QString &strOrderNum
                                               , const ESaleHeadStatus &eSaleHeadStatus )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set status = %2 where order_num = '%3'")
            .arg(m_sTableName).arg( eSaleHeadStatus ).arg( strOrderNum );
    if( !query.exec( strUpdateData ) )
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateStatus -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::updateStatus -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateStatus( const QString &strOrderNum, const ESaleHeadStatus &eSaleHeadStatus, const QDateTime &dtFactorTime )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set status = %2, factor_time = '%3' where order_num = '%4'")
            .arg(m_sTableName).arg( eSaleHeadStatus ).arg( dtFactorTime.toString( "yyyy-MM-dd hh:mm:ss") ).arg( strOrderNum );
    if( !query.exec( strUpdateData ) )
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateStatus2 -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::updateStatus2 -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateCompleteTime( const QString &strOrderNum, const QDateTime &dtCompleteTime )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set complete_time = '%2' where order_num = '%3' ")
            .arg(m_sTableName).arg( dtCompleteTime.toString( "yyyy-MM-dd hh:mm:ss") ).arg( strOrderNum );
    if( !query.exec( strUpdateData ) )
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateCompleteTime -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::updateCompleteTime -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateUploadTime( const QString &strOrderNum, const QDateTime &dtUpload )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set receipt_upload = '%2' where order_num = '%3' ")
            .arg(m_sTableName).arg( dtUpload.toString( "yyyy-MM-dd hh:mm:ss") ).arg( strOrderNum );
    if( !query.exec( strUpdateData ) )
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateUploadTime -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::updateUploadTime -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateUploadStatus( QString strOrderNum, EUploadReceiptStatus eUploadStatus )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set upload_status = %2 where order_num = '%3' ")
            .arg(m_sTableName).arg( eUploadStatus ).arg( strOrderNum );
    if(!query.exec(strUpdateData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateUploadStatus -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::updateUploadStatus -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateStatementInfo( QString strOrderNum, QString strDisAmt, QString strProfitLoss, QString strFactorAmt, QString strOddChange )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set factor_amt = '%2', all_dis_amt='%3',profit_loss='%4',odd_change='%5' where order_num = '%6' ")
            .arg(m_sTableName).arg( strFactorAmt ).arg( strDisAmt ).arg( strProfitLoss ).arg(strOddChange).arg(strOrderNum);
    if( !query.exec(strUpdateData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateStatementInfo -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::updateStatementInfo -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateOutAmt( QString strOrderNum, QString strSimple )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set ought_amt = %2 where order_num = '%3' ")
            .arg(m_sTableName).arg( strSimple.toFloat() ).arg( strOrderNum );
    if(!query.exec(strUpdateData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateOutAmt -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::updateOutAmt -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateFactorAMt( QString strOrderNum, QString strFactorAmt )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set factor_amt = %2 where order_num = '%3' ")
            .arg(m_sTableName).arg( strFactorAmt ).arg( strOrderNum );
    if( !query.exec(strUpdateData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateFactorAMt -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::updateFactorAMt -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateSmallChangeAmt( QString strOrderNum, QString strSmallChange )
{
//    SaleHead stSaleHead;
//    findSaleHead(strOrderNum, stSaleHead);

//    stSaleHead.sSmallChangeAmt = strSmallChange;
//    stSaleHead.fFactorAmt = stSaleHead.fFactorAmt - stSaleHead.fOddChange; // 根据新规则，先在数据库层面修改，以后从源头修改
//    stSaleHead.fOughtAmt = stSaleHead.fFactorAmt + stSaleHead.sSmallChangeAmt.toFloat()
//             + stSaleHead.fCouponDisAmt - stSaleHead.fProfitLoss; // 根据新定义的规则，先在数据库层面修改，以后从源头修改

//    qDebug()<<"1111111111" << stSaleHead.sSmallChangeAmt;
//    qDebug()<<"22222222222" << stSaleHead.fFactorAmt;
//    qDebug()<<"333333333333" << stSaleHead.fOughtAmt;

//    replaceSaleHead(stSaleHead);


//    bool bResult = checkColumnExist( "small_change" );
//    if( !bResult ) {
//        bool bNew = addNewColumn( "small_change" );
//        if( !bNew ) {
//            KPosLog::instance()->writeErrorLog( "SaleHeadTable::updateSmallChangeAmt 新增抹零字段失败！");
//            return;
//        }
//    }

    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set small_change = %2 where order_num = '%3' ")
            .arg(m_sTableName).arg( strSmallChange.toFloat() ).arg( strOrderNum );
    if(!query.exec(strUpdateData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateSmallChangeAmt -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::updateSmallChangeAmt -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateOddChange( QString strOrderNum, QString strOddChange )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set odd_change = %2 where order_num = '%3' ")
            .arg(m_sTableName).arg( strOddChange.toFloat() ).arg( strOrderNum );
    if(!query.exec(strUpdateData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateOddChange -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::updateOddChange -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateMemInfo( QString strOrderNum, MemRegisterInfo_s stMemRegInfo )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strUpdateData = QString("update %1 set mem_card_id = '%2' where order_num = '%3' ")
            .arg(m_sTableName).arg( stMemRegInfo.stMemInfo.strCardNo ).arg( strOrderNum );
    if( !query.exec( strUpdateData ) )
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateMemInfo -- %1").arg(strUpdateData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::updateMemInfo -- %1").arg(strUpdateData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::deleteSaleHead( const QString &strOrderNum )
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strDeleteData = QString("delete from %1 where order_num = '%2'")
            .arg(m_sTableName).arg( strOrderNum );
    if(!query.exec(strDeleteData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::deleteSaleHead -- %1").arg(strDeleteData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::deleteSaleHead -- %1").arg(strDeleteData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::findSaleHead( int nDayBefore, QList<QString> &listOrderNum )
{
    qint64 nDayBeforeTime = nDayBefore*86400;
    qint64 nCurTime = QDateTime::currentDateTime().toTime_t();
    qint64 nBefore = nCurTime - nDayBeforeTime;

    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    //必须是上传小票完成的才可以删除
    QString strFindDay = QString("select order_num from %1 where ( strftime('%s',complete_time)>0 and strftime('%s',complete_time)-'%2'<0 and upload_status=1)")
            .arg(m_sTableName).arg( nBefore );

    bool bHas = query.exec( strFindDay );
    if( bHas )
    {
        while( query.next() )
        {//开始就先执行一次next()函数，那么query指向结果集的第一条记录
            QString strOrderNum = query.value( 0 ).toString();
            listOrderNum.push_back( strOrderNum );
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::findSaleHead -- %1").arg(strFindDay));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::findSaleHead -- %1").arg(strFindDay));
    }
    m_pReadWriteLock->unlock();
}

bool SaleHeadTable::findSaleHead( const QString &strOrderNum, SaleHead &stSaleHead )
{
    m_pReadWriteLock->lockForRead();
    bool bFind = false;
    QSqlQuery query(*m_pDatabase);
    QString strSaleData = QString("select * from %1 where order_num = '%2' ")
            .arg(m_sTableName).arg( strOrderNum );
    if( query.exec( strSaleData ) ) {
        bool b_first = query.first();
        if( b_first ) {
            setSqlToSaleHead( stSaleHead, query );
            bFind = true;
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::findSaleHead2 -- %1").arg(strSaleData));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::findSaleHead2 -- %1").arg(strSaleData));
    }

    m_pReadWriteLock->unlock();
    return bFind;
}

//bool SaleHeadTable::findRefundSaleHead(QString sRefundOrderNum, SaleHead &saleHead)
//{
//    m_pReadWriteLock->lockForRead();
//    bool bFind = false;
//    QSqlQuery query(*m_pDatabase);
//    QString strSaleData = QString("select * from %1 where return_order_num = '%2'")
//            .arg(m_sTableName).arg(sRefundOrderNum);
//    if(query.exec(strSaleData))
//    {
//        if(query.next())
//        {
//            setSqlToSaleHead(saleHead, query);
//            bFind = true;
//        }
//    }
//    m_pReadWriteLock->unlock();
//    return bFind;
//}

void SaleHeadTable::getFinishRefundOrderNumList(QString sOrderNum, QList<QString> &refundOrderNumList)
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString sSql = QString("select order_num from %1 where return_order_num = '%2' and status = 1;")
            .arg(m_sTableName).arg(sOrderNum);
    if(query.exec(sSql))
    {
        while(query.next())
        {
            refundOrderNumList.append(query.value(0).toString());
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::getFinishRefundOrderNumList -- %1").arg(sSql));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::getFinishRefundOrderNumList -- %1").arg(sSql));
    }
    m_pReadWriteLock->unlock();
}

void SaleHeadTable::findAllUnUploadSale( QList<SaleHead> &listSaleHead )
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString strStatusData = QString("select * from %1 where upload_status = 0 and (status=1 or status =-1) ")
            .arg(m_sTableName);

    bool bHas = query.exec( strStatusData );
    if( bHas )
    {
        while( query.next() )
        {//开始就先执行一次next()函数，那么query指向结果集的第一条记录
            SaleHead stSaleHead;
            setSqlToSaleHead( stSaleHead, query );

            listSaleHead.push_back( stSaleHead );
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::findAllUnUploadSale -- %1").arg(strStatusData));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::findAllUnUploadSale -- %1").arg(strStatusData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::findStatusToSaleHead( const ESaleHeadStatus &eSaleHeadStatus, QMap< int, SaleHead> &mapSaleHead )
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString strStatusData = QString("select * from %1 where status = %2")
            .arg(m_sTableName).arg( eSaleHeadStatus );
    if( query.exec( strStatusData ) )
    {
        while( query.next() ) {//开始就先执行一次next()函数，那么query指向结果集的第一条记录
            SaleHead stSaleHead;
            setSqlToSaleHead( stSaleHead, query );

            int nPendTime = stSaleHead.dtFactorTime.toTime_t();
            mapSaleHead.insert( nPendTime, stSaleHead );
        }

        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::findStatusToSaleHead -- %1").arg(strStatusData));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::findStatusToSaleHead -- %1").arg(strStatusData));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::clearSaleHead()
{

}

int SaleHeadTable::getLastSaleHeadId()
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString strQueryData = QString( "select max(ID) from %1 " ).arg( m_sTableName );

    int nLastId = 0;
    if( query.exec( strQueryData ) ) {
        bool b_first = query.first();
        if( b_first )
        {
            nLastId = query.value( 0 ).toInt();
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::getLastSaleHeadId -- %1").arg(strQueryData));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::getLastSaleHeadId -- %1").arg(strQueryData));
    }

    m_pReadWriteLock->unlock();

    return nLastId;
}

//获取挂单数量
int SaleHeadTable::getPendingOrder()
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString strQueryNum = QString( "select count(*) from %1 where status = 3" ).arg( m_sTableName );
    int strNum = 0;
    if( query.exec( strQueryNum ) )
    {
        bool b_first = query.first();
        if( b_first ) {
            strNum = query.value( 0 ).toInt();
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::getPendingOrder -- %1").arg(strQueryNum));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::getPendingOrder -- %1").arg(strQueryNum));
    }

    m_pReadWriteLock->unlock();

    return strNum;
}


QString SaleHeadTable::findStatusToLastSaleOrderNum(const ESaleHeadStatus &eSaleHeadStatus)
{
    QString strOrderNum = "";

    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString strLastStatementSucData = QString("select max(ID),order_num  from %1 where status=%2")
            .arg(m_sTableName).arg( eSaleHeadStatus );

    if (!query.exec(strLastStatementSucData))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::findStatusToLastSaleOrderNum -- %1").arg(strLastStatementSucData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::findStatusToLastSaleOrderNum -- %1").arg(strLastStatementSucData));
    }

    bool b_first = query.first();
    if( b_first )
    {
        strOrderNum = query.value( 1 ).toString();
    }
    else
    {
       KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::findStatusToLastSaleOrderNum222 -- %1").arg(b_first));
    }

    m_pReadWriteLock->unlock();

    return strOrderNum;
}

void SaleHeadTable::countSaleMoney(int &nCount, float &fSaleMoney, QString sStartTime, QString sEndTime)
{
    countSumMoney(nCount, fSaleMoney, sStartTime, sEndTime, false);
}

void SaleHeadTable::countSaleRefundMoney(int &nCount, float &fSaleMoney, QString sStartTime, QString sEndTime)
{
    countSumMoney(nCount, fSaleMoney, sStartTime, sEndTime, true);
}

void SaleHeadTable::getOrderNumList(QList<QString> &orderNumList, QString sStartTime, QString sEndTime)
{
    if (sStartTime.isEmpty() || sEndTime.isEmpty())
    {
        return;
    }

    m_pReadWriteLock->lockForRead();
    QString sSql = QString("select order_num from SaleHeadInfo where"
                           " complete_time >= '%1' and complete_time <= '%2'"
                           " and status = 1;").arg(sStartTime).arg(sEndTime);
    QSqlQuery query(*m_pDatabase);
    if (query.exec(sSql))
    {
        while (query.next())
        {
           QString sOrderNum = query.value(0).toString();
           orderNumList.append(sOrderNum);
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::getOrderNumList -- %1").arg(sSql));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::getOrderNumList -- %1").arg(sSql));
    }
    m_pReadWriteLock->unlock();
}

void SaleHeadTable::getFactorAmt(float &fMoney, QString sOrderNum)
{
    m_pReadWriteLock->lockForRead();
    QString sSql = QString("select factor_amt from SaleHeadInfo where order_num = '%1'").arg(sOrderNum);
    QSqlQuery query(*m_pDatabase);
    if (query.exec(sSql))
    {
        if (query.next())
        {
           fMoney = query.value(0).toFloat();
        }
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::getFactorAmt -- %1").arg(sSql));
    }

    m_pReadWriteLock->unlock();
}

void SaleHeadTable::updateIntegral(int nGiftIntegral, QString sOrderNum)
{
    m_pReadWriteLock->lockForWrite();

    QString sSql = QString("update SaleHeadInfo set mem_integer = %1 where order_num = '%2'").arg(nGiftIntegral).arg(sOrderNum);
    QSqlQuery query(*m_pDatabase);
    if (!query.exec(sSql))
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::updateMemberIntegral -- %1").arg(sSql));
    }
    m_pReadWriteLock->unlock();
}

void SaleHeadTable::createTable()
{
    /**
     * @field ID  销售id
     * @field serial_num 流水号（5位）
     * @field pos_id  款机号
     * @field order_num  单号（pos号+日期YYMMDD+流水号）
     * @field sale_total_num  商品总数
     * @field ought_amt  应付金额
     * @field factor_amt 实付金额
     * @field odd_change 找零
     * @field mem_card_id 会员卡号
     * @field mem_integer 会员积分
     * @field dis_reason 折扣原因
     * @field grant_dis  临时折扣率
     * @field all_dis_amt 所有优惠金额 2016.12.15
     * @field profit_loss 收银损益((实际支付的钱- 找零-应付金额，由现金四舍五入引起)
     * @field status 交易状态: -1.取消，0.正在进行，1.完成
     * @field ntype  购物类型:网购、现购、团购
     * @field shop_id 门店编号
     * @field upload_status  上传总部状态
     * @field create_time  创建时间
     * @field factor_time  实际交易时间
     * @field cost_time    交易花费时间
     * @field complete_time  交易完成时间
     * @field receipt_upload 小票上传时间
     * @field cashier_no    收款员编号
     * @field cashier_name  收款员姓名
     *
     * @field tran_status   交易状态:-1.取消，0.正在进行，1.完成
     * @field sale_type     销售类型：0.销售小票，1.退货小票，2.会员充值，3.储值卡充值，4.退充值，5.取消小票
     * @field return_order_num  退货订单号
     * @field return_reason 退货原因
     * @field sale_mode     销售方式：：1.KeyPos，2.待定
     * @field log           日志
     * @field shopping_id   导购员ID
     * @field shopping_name 导购员名字
     */
    QString newSqlTemp = QString("Create TABLE %1(ID integer PRIMARY KEY UNIQUE NOT NULL \
                                , serial_num integer, pos_id varchar, order_num varchar \
                                , sale_total_num integer, ought_amt float \
                                , factor_amt float, odd_change float, mem_card_id varchar \
                                , mem_integer integer, dis_reason varchar \
                                , grant_dis float, all_dis_amt float, profit_loss float \
                                , status integer, ntype integer, shop_id integer, upload_status integer \
                                , create_time DATETIME, factor_time DATETIME, cost_time integer \
                                , complete_time DATETIME, receipt_upload DATETIME \
                                , cashier_no varchar, cashier_name varchar, tran_status integer \
                                , sale_type integer, return_order_num varchar, return_reason varchar \
                                , sale_mode integer, log varchar, shopping_id integer, shopping_name varchar "
                                ", 'small_change' float,  coupon_disAmt float)")
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

void SaleHeadTable::setSqlToSaleHead( SaleHead &stSaleHead, const QSqlQuery& sqlQuery )
{
    stSaleHead.nSaleHeadId = sqlQuery.value( 0 ).toInt();
    stSaleHead.nSerialNum = sqlQuery.value( 1 ).toInt();
    stSaleHead.strPosId = sqlQuery.value( 2 ).toString();
    stSaleHead.strOrderNum = sqlQuery.value( 3 ).toString();
    stSaleHead.nSaleTotalNum = sqlQuery.value( 4 ).toInt();
    stSaleHead.fOughtAmt = sqlQuery.value( 5 ).toFloat();
    stSaleHead.fFactorAmt = sqlQuery.value( 6 ).toFloat();
    stSaleHead.fOddChange = sqlQuery.value( 7 ).toFloat();
    stSaleHead.strMemCardId = sqlQuery.value( 8 ).toString();
    stSaleHead.nMemInteger = sqlQuery.value( 9 ).toInt();
    stSaleHead.strDisReason = sqlQuery.value( 10 ).toString();
    stSaleHead.fGrantDisRate = sqlQuery.value( 11 ).toFloat();
    stSaleHead.fAllDisAmt = sqlQuery.value( 12 ).toFloat();
    stSaleHead.fProfitLoss = sqlQuery.value( 13 ).toFloat();
    stSaleHead.nStatus = sqlQuery.value( 14 ).toInt();
    stSaleHead.nType = sqlQuery.value( 15 ).toInt();
    stSaleHead.nShopId = sqlQuery.value( 16 ).toInt();
    int nUploadStatus = sqlQuery.value( 17 ).toInt();
    stSaleHead.eUploadStatus = static_cast<EUploadReceiptStatus>( nUploadStatus );
    stSaleHead.dtCreateTime = sqlQuery.value( 18 ).toDateTime();
    stSaleHead.dtFactorTime = sqlQuery.value( 19 ).toDateTime();
    stSaleHead.nCostTime = sqlQuery.value( 20 ).toInt();
    stSaleHead.dtCompleteTime = sqlQuery.value( 21 ).toDateTime();
    stSaleHead.dtReceiptUpload = sqlQuery.value( 22 ).toDateTime();
    stSaleHead.nCashierId = sqlQuery.value( 23 ).toInt();
    stSaleHead.strCashierName = sqlQuery.value( 24 ).toString();
    stSaleHead.nTranStatus = sqlQuery.value( 25 ).toInt();
    stSaleHead.nSaleType = sqlQuery.value( 26 ).toInt();
    stSaleHead.strReturnOrderNum = sqlQuery.value( 27 ).toString();
    stSaleHead.strReturnReason = sqlQuery.value( 28 ).toString();;
    stSaleHead.nSaleMode = sqlQuery.value( 29 ).toInt();
    stSaleHead.strLog = sqlQuery.value( 30 ).toString();
    stSaleHead.nShoppingId = sqlQuery.value( 31 ).toInt();
    stSaleHead.strShoppingName = sqlQuery.value( 32 ).toString();
    stSaleHead.sSmallChangeAmt = sqlQuery.value( 33 ).toString();
    stSaleHead.fCouponDisAmt = sqlQuery.value( 34 ).toFloat();
}

void SaleHeadTable::countSumMoney(int &nCount, float &fSaleMoney, QString sStartTime, QString sEndTime, bool bRefund)
{
    m_pReadWriteLock->lockForRead();

    QString sSql = QString("select count(*), sum(factor_amt) from SaleHeadInfo"  // ought_amt
                           " where complete_time >= '%1' and"
                           " complete_time <= '%2' and sale_type = %3"
                           " and status = 1;").arg(sStartTime).arg(sEndTime).arg(bRefund?1:0);
    QSqlQuery query(*m_pDatabase);
    if (query.exec(sSql))
    {
        if (query.next())
        {
           nCount = query.value(0).toInt();
           fSaleMoney = query.value(1).toFloat();
        }
        else
        {
            // 日志
        }
        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::countSumMoney -- %1").arg(sSql));
    }
    else
    {
        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::countSumMoney -- %1").arg(sSql));
    }

    m_pReadWriteLock->unlock();
}

/**
 * 检查某表列是否存在
 * @param strColumnName 列名
 * @return
 */
//bool SaleHeadTable::checkColumnExist( QString strColumnName )
//{
//    bool bResult = false ;
//    m_pReadWriteLock->lockForRead();
//    QString sSql = QString("select %1 from %2").arg( strColumnName ).arg( m_sTableName );
//    QSqlQuery query(*m_pDatabase);
//    bResult = query.exec(sSql);
//    if (!bResult)
//    {
//        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::checkColumnExist -- %1").arg(sSql));
//    }
//    else
//    {
//        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::checkColumnExist -- %1").arg(sSql));
//    }
//    m_pReadWriteLock->unlock();
//    return bResult;
//}

//bool SaleHeadTable::addNewColumn( QString strColumnName )
//{
//    bool bResult = false ;
//    m_pReadWriteLock->lockForWrite();
//    QString sSql = QString("ALTER TABLE %1 ADD '%2' float").arg( m_sTableName ).arg( strColumnName );
//    QSqlQuery query(*m_pDatabase);
//    bResult = query.exec(sSql);
//    if (!bResult)
//    {
//        KPosLog::instance()->writeErrorLog(QString("SaleHeadTable::addNewColumn -- %1").arg(sSql));
//    }
//    else
//    {
//        KPosLog::instance()->writeDatabaseLog(QString("SaleHeadTable::addNewColumn -- %1").arg(sSql));
//    }

//    m_pReadWriteLock->unlock();
//    return bResult;
//}
