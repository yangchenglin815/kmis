#include "ClientCashSubmitTable.h"
#include "../util/KPosLog.h"
#include <QSqlQuery>
#include <QDebug>

ClientCashSubmitTable::ClientCashSubmitTable(QObject *parent)
    : DbBaseTable(parent)
    , m_pDatabase(NULL)
    , m_sTableName("ClientCashSubmitInfo")//ClientCashSubmitInfo
{

}

void ClientCashSubmitTable::setDatabase(QSqlDatabase *pDatabase)
{
    m_pDatabase = pDatabase;
    if (m_pDatabase->isOpen())
    {
        createTable();
    }
}

//插入数据
QString ClientCashSubmitTable::initClentCash(const ClentCashSubmit_s &ClentCashSubmit)
{
    QString submit_code = this->getNewSubmitCode(ClentCashSubmit.user_code);

    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);


    QString sInsertData = QString("insert into %1 (submit_amount, uuid, user_code, operate_at, last_submit_at, status, login_at, logout_at, submit_code)"
                                  " values('%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10')")
            .arg(m_sTableName).arg(ClentCashSubmit.submit_amount).arg(ClentCashSubmit.uuid).arg(ClentCashSubmit.user_code).arg(ClentCashSubmit.operate_at)
            .arg(ClentCashSubmit.last_submit_at).arg(ClentCashSubmit.status).arg(ClentCashSubmit.login_at).arg(ClentCashSubmit.logout_at).arg(submit_code);
    if(!query.exec(sInsertData))
    {
        KPosLog::instance()->writeErrorLog(QString("ClientCashSubmitTable::initClentCash -- %1").arg(sInsertData));
    }

//     qDebug()<<sInsertData;
    m_pReadWriteLock->unlock();
    return submit_code;
}

//获取未提交的数据
ClentCashSubmit_s ClientCashSubmitTable::getFirstClentCash()
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString sqlTemp = QString("SELECT * FROM %1 WHERE status = 1 LIMIT 0,1 ").arg(m_sTableName);
    if(!query.exec(sqlTemp))
    {
        KPosLog::instance()->writeErrorLog(QString("ClientCashSubmitTable::getFirstClentCash -- %1").arg(sqlTemp));
    }

    bool b_first = query.first();
    ClentCashSubmit_s ClentCashSubmit;

    if(b_first)
    {
        ClentCashSubmit.submit_code = query.value(0).toString(); // 交款金额
        ClentCashSubmit.submit_amount = query.value(1).toString(); // 交款金额
        ClentCashSubmit.uuid = query.value(2).toString();
        ClentCashSubmit.user_code = query.value(3).toString();//操作人编号
        ClentCashSubmit.login_at = query.value(4).toString();//登录时间点
        ClentCashSubmit.logout_at = query.value(5).toString();//登出时间点
        ClentCashSubmit.operate_at = query.value(6).toString();//交款时间
        ClentCashSubmit.last_submit_at = query.value(7).toString(); //上次交款时间
    }


    m_pReadWriteLock->unlock();
    return ClentCashSubmit;
}


//将数据修改为已完成交款
bool ClientCashSubmitTable::updateClentCashStatus(QString submit_code)
{
     m_pReadWriteLock->lockForWrite();
     QSqlQuery query(*m_pDatabase);
     QString sqlTemp = QString("UPDATE %1 SET status = 0 WHERE submit_code = '%2'").arg(m_sTableName).arg(submit_code);
     bool bols = query.exec(sqlTemp);
     if(!bols)
     {
         KPosLog::instance()->writeErrorLog(QString("ClientCashSubmitTable::updateClentCashStatus -- %1").arg(sqlTemp));
     }
     m_pReadWriteLock->unlock();

     return bols;
}

//拉取上次交款时间
QString ClientCashSubmitTable::getLastSubmitAt(QString userCode)
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString sqlTemp = QString("SELECT operate_at FROM %1 WHERE user_code = '%2' ORDER BY submit_code DESC LIMIT 0,1").arg(m_sTableName).arg(userCode);
    if (!query.exec(sqlTemp))
    {
        KPosLog::instance()->writeErrorLog(QString("ClientCashSubmitTable::getLastSubmitAt -- %1").arg(sqlTemp));
    }

    bool b_first = query.first();
    QString operate_at;
    if(b_first)
    {
        operate_at = query.value(0).toString();
    }

    m_pReadWriteLock->unlock();
    return operate_at;
}

//创建新的交款单code
QString ClientCashSubmitTable::getNewSubmitCode(QString userCode)
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString sqlTemp = QString("SELECT submit_code FROM %1 WHERE user_code = '%2' ORDER BY submit_code DESC LIMIT 0,1").arg(m_sTableName).arg(userCode);
    if (!query.exec(sqlTemp))
    {
        KPosLog::instance()->writeErrorLog(QString("ClientCashSubmitTable::getFirstClentCash -- %1").arg(sqlTemp));
    }

    bool b_first = query.first();
    QString NewSubmitCode;

    if(b_first)
    {
        NewSubmitCode = query.value(0).toString();
        int length = NewSubmitCode.length() - 6;
        NewSubmitCode = NewSubmitCode.mid(length);
        int str = NewSubmitCode.toInt()+1;
        NewSubmitCode = QString("%1%2").arg(userCode).arg(str, 6, 10, QChar('0'));

    }
    else
    {
        NewSubmitCode = userCode + "000001";
    }
    m_pReadWriteLock->unlock();

    return NewSubmitCode;
}

//创建数据表
void ClientCashSubmitTable::createTable()
{
    /**
        uuid
        submit_amount 交款金额
        user_code 操作员code
        login_at 登录时间点
        logout_at 登出时间点
        operate_at 交款时间
        last_submit_at 上次交款时间
        status 状态 0已提交 1未提交
    */

    QString newSqlTemp = QString("Create TABLE %1(submit_code nvarchar PRIMARY KEY UNIQUE NOT NULL,submit_amount nvarchar,uuid nvarchar, user_code nvarchar, login_at nvarchar, logout_at nvarchar,"
                                 "operate_at nvarchar, last_submit_at nvarchar,status nvarchar)").arg(m_sTableName);

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

