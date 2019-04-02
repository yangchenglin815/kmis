#include "SalesmanInfoTable.h"
#include "../util/KPosLog.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

SalesmanInfoTable::SalesmanInfoTable(QObject *parent)
    :DbBaseTable(parent)
    ,m_pDatabase(NULL)
    ,m_sTableName("SalesmanInfo")
{

}

void SalesmanInfoTable::setDatabase(QSqlDatabase *pDatabase)
{
    m_pDatabase = pDatabase;
    if (m_pDatabase->isOpen())
    {
        createTable();
    }
}

void SalesmanInfoTable::updateSalemanPasswd(QString user, QString newkey){
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString sql = QString("update %1 set password = '%2' where code = '%3'").arg(m_sTableName).arg(newkey).arg(user);
    if(!query.exec(sql)){
        KPosLog::instance()->writeErrorLog(QString("SalesmanInfoTable::updateSalemanPasswd -- %1").arg(sql));
    }
    else
    {
         KPosLog::instance()->writeDatabaseLog(QString("SalesmanInfoTable::updateSalemanPasswd -- %1").arg(sql));
    }
     m_pReadWriteLock->unlock();
}

void SalesmanInfoTable::addSalesmanInfo(const SalemanInfo &salemanInfo)
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    int nLen = salemanInfo.privilegeList.length();
    QString sPrivileges;
    for (int i = 0; i < nLen - 1; i++)
    {
        sPrivileges.append(QString("%1,").arg(salemanInfo.privilegeList[i]));
    }
    if (nLen - 1 >= 0)
    {
        sPrivileges.append(salemanInfo.privilegeList[nLen - 1]);
    }

    QString sqlTemp = QString("replace into %1 (ID, password, code, name, privilege, sex, email, mobile, headPic,role_code)"
                              "values(%2,'%3', '%4', '%5', '%6', '%7', '%8', '%9','%10','%11')")
            .arg(m_sTableName).arg(salemanInfo.nUserId).arg(salemanInfo.sPassword).arg(salemanInfo.sUserCode)
            .arg(salemanInfo.sUsername).arg(sPrivileges).arg(salemanInfo.nSex)
            .arg(salemanInfo.sEmail).arg(salemanInfo.sMobile).arg(salemanInfo.sUserPic)
            .arg( salemanInfo.sRoleCode );
    if(!query.exec(sqlTemp))
    {
        KPosLog::instance()->writeErrorLog(QString("SalesmanInfoTable::addSalesmanInfo -- %1").arg(sqlTemp));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SalesmanInfoTable::addSalesmanInfo -- %1").arg(sqlTemp));
    }

    m_pReadWriteLock->unlock();
}

void SalesmanInfoTable::updateSalesmanInfo(const SalemanInfo &salemanInfo)
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    int nLen = salemanInfo.privilegeList.length();
    QString sPrivileges;
    for (int i = 0; i < nLen - 1; i++)
    {
        sPrivileges.append(QString("%1,").arg(salemanInfo.privilegeList[i]));
    }
    if (nLen - 1 >= 0)
    {
        sPrivileges.append(salemanInfo.privilegeList[nLen - 1]);
    }

    QString sqlTemp = QString("update %1 set ID =%2, code='%3', name='%4', privilege='%5', sex=%6, email='%7', mobile='%8', headPic='%9',role_code='%10' where ID = %11")
            .arg(m_sTableName).arg(salemanInfo.nUserId).arg(salemanInfo.sUserCode)
            .arg(salemanInfo.sUsername).arg(sPrivileges).arg(salemanInfo.nSex)
            .arg(salemanInfo.sEmail).arg(salemanInfo.sMobile).arg(salemanInfo.sUserPic)
            .arg( salemanInfo.sRoleCode ).arg(salemanInfo.nUserId);
    if( !query.exec(sqlTemp) )
    {
        KPosLog::instance()->writeErrorLog(QString("SalesmanInfoTable::updateSalesmanInfo -- %1").arg(sqlTemp));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SalesmanInfoTable::updateSalesmanInfo -- %1").arg(sqlTemp));
    }

    m_pReadWriteLock->unlock();
}

void SalesmanInfoTable::deleteSalesmanInfo(const SalemanInfo &salemanInfo)
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString sqlDelete = QString("delete from %1 where ID=%2")
            .arg(m_sTableName).arg(salemanInfo.nUserId);
    if( !query.exec(sqlDelete) )
    {
        KPosLog::instance()->writeErrorLog(QString("SalesmanInfoTable::deleteSalesmanInfo -- %1").arg(sqlDelete));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SalesmanInfoTable::deleteSalesmanInfo -- %1").arg(sqlDelete));
    }

    m_pReadWriteLock->unlock();
}

void SalesmanInfoTable::clearSalesmanInfo()
{
    m_pReadWriteLock->lockForWrite();
    QSqlQuery query(*m_pDatabase);
    QString strDelData = QString("delete from %1")
            .arg(m_sTableName);
    if(!query.exec(strDelData))
    {
         KPosLog::instance()->writeErrorLog(QString("SalesmanInfoTable::clearSalesmanInfo -- %1").arg(strDelData));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SalesmanInfoTable::clearSalesmanInfo -- %1").arg(strDelData));
    }

    m_pReadWriteLock->unlock();
}

SalemanInfo SalesmanInfoTable::getSalemanInfo(int nID)
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString sqlTemp = QString("select password, code, name, privilege, sex, email, mobile, headPic,role_code from %1 where ID = %2").arg(m_sTableName).arg(nID);
    if (!query.exec(sqlTemp))
    {
         KPosLog::instance()->writeErrorLog(QString("SalesmanInfoTable::getSalemanInfo -- %1").arg(sqlTemp));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SalesmanInfoTable::getSalemanInfo -- %1").arg(sqlTemp));
    }

    SalemanInfo salemanInfo;
    if (query.next()){
        salemanInfo.nUserId = nID;
        salemanInfo.sPassword = query.value(0).toString();
        salemanInfo.sUserCode = query.value(1).toString();
        salemanInfo.sUsername = query.value(2).toString();
        salemanInfo.privilegeList = query.value(3).toString().split(",");
        salemanInfo.nSex = query.value(4).toInt();
        salemanInfo.sEmail = query.value(5).toString();
        salemanInfo.sMobile = query.value(6).toString();
        salemanInfo.sUserPic = query.value(7).toString();
        salemanInfo.sRoleCode = query.value(8).toString();
    }
    else
    {
        salemanInfo.nUserId = -1;
    }
    m_pReadWriteLock->unlock();

    return salemanInfo;
}

SalemanInfo SalesmanInfoTable::getUserdata(QString code)
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString sqlTemp = QString("select ID, password,  name, privilege, sex, email, mobile, headPic,role_code from %1 where code = '%2'").arg(m_sTableName).arg(code);
    if (!query.exec(sqlTemp))
    {
         KPosLog::instance()->writeErrorLog(QString("SalesmanInfoTable::getUserdata -- %1").arg(sqlTemp));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SalesmanInfoTable::getUserdata -- %1").arg(sqlTemp));
    }

    SalemanInfo salemanInfo;
    if (query.next())
    {
        salemanInfo.nUserId = query.value(0).toInt();
        salemanInfo.sUserCode = code;
        salemanInfo.sUsername = query.value(2).toString();
        salemanInfo.privilegeList = query.value(3).toString().split(",");
        salemanInfo.nSex = query.value(4).toInt();
        salemanInfo.sEmail = query.value(5).toString();
        salemanInfo.sMobile = query.value(6).toString();
        salemanInfo.sUserPic = query.value(7).toString();
        salemanInfo.sRoleCode = query.value(8).toString();
    }
    else
    {
        salemanInfo.nUserId = -1;
    }
    m_pReadWriteLock->unlock();
    return salemanInfo;
}

bool SalesmanInfoTable::isAllowLogin(SalemanInfo &salemanInfo)
{
    bool bAllow = false;
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString sqlTemp = QString("select ID, password, code, name, privilege, sex, email, mobile, headPic,role_code from %1 where code = '%2' and password = '%3' ")
            .arg(m_sTableName).arg(salemanInfo.sUserCode).arg(salemanInfo.sPassword);
    if (!query.exec(sqlTemp))
    {
        KPosLog::instance()->writeErrorLog(QString("SalesmanInfoTable::isAllowLogin -- %1").arg(sqlTemp));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SalesmanInfoTable::isAllowLogin -- %1").arg(sqlTemp));
    }

    if (query.next())
    {
        salemanInfo.nUserId = query.value(0).toInt();
        salemanInfo.sPassword = query.value(1).toString();
        salemanInfo.sUserCode = query.value(2).toString();
        salemanInfo.sUsername = query.value(3).toString();
        salemanInfo.privilegeList = query.value(4).toString().split(",");
        salemanInfo.nSex = query.value(5).toInt();
        salemanInfo.sEmail = query.value(6).toString();
        salemanInfo.sMobile = query.value(7).toString();
        salemanInfo.sUserPic = query.value(8).toString();
        salemanInfo.sRoleCode = query.value(9).toString();

        bAllow = true;
    }
    m_pReadWriteLock->unlock();
    return bAllow;
}

void SalesmanInfoTable::getAllSalesmanInfo( QList<SalemanInfo> &listSalemanInfo )
{
    m_pReadWriteLock->lockForRead();
    QSqlQuery query(*m_pDatabase);
    QString SqlTemp = QString("select * from %1").arg(m_sTableName);
    if (!query.exec(SqlTemp))
    {
        KPosLog::instance()->writeErrorLog(QString("SalesmanInfoTable::getAllSalesmanInfo -- %1").arg(SqlTemp));
    }
    else
    {
        KPosLog::instance()->writeDatabaseLog(QString("SalesmanInfoTable::getAllSalesmanInfo -- %1").arg(SqlTemp));
    }

    while (query.next()){
        SalemanInfo stSalemanInfo;
        setSqlToSaleman( stSalemanInfo, query );
        listSalemanInfo.append( stSalemanInfo );
    }
    m_pReadWriteLock->unlock();
}

void SalesmanInfoTable::createTable()
{
    /**
    ID -- 用户id
    name -- 用户名称
    email -- 用户邮箱
    mobile -- 用户手机号
    sex -- 用户性别
    headPic -- 用户头像
    privilege -- 用户权限列表
    */
    QString newSqlTemp = QString("Create TABLE %1(ID integer PRIMARY KEY UNIQUE NOT NULL, password nvarchar,"
                              "code nvarchar, name nvarchar, privilege nvarchar, sex char, email nvarchar, "
                              "mobile nvarchar, headPic nvarchar,role_code nvarchar)").arg(m_sTableName);

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

void SalesmanInfoTable::setSqlToSaleman( SalemanInfo &stSalemanInfo, const QSqlQuery& sqlQuery )
{
    stSalemanInfo.nUserId = sqlQuery.value( 0 ).toInt();
    stSalemanInfo.sPassword = sqlQuery.value(1).toString();
    stSalemanInfo.sUserCode = sqlQuery.value(2).toString();
    stSalemanInfo.sUsername = sqlQuery.value(3).toString();
    stSalemanInfo.privilegeList = sqlQuery.value(4).toString().split(",");
    stSalemanInfo.nSex = sqlQuery.value(5).toInt();
    stSalemanInfo.sEmail = sqlQuery.value(6).toString();
    stSalemanInfo.sMobile = sqlQuery.value(7).toString();
    stSalemanInfo.sUserPic = sqlQuery.value(8).toString();
    stSalemanInfo.sRoleCode = sqlQuery.value(9).toString();
}


