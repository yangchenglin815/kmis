#include "PosDB_Sqlite.h"
#include "SalesmanInfoTable.h"
#include "../Data/constData.h"
#include "../util/FilePathManage.h"
#include <QDebug>


PosDB_Sqlite::PosDB_Sqlite()
{
    m_pSalesmanInfoTable = new SalesmanInfoTable;
    m_pCategoryTable = new CategoryTable;
    m_pClientCashSubmitTable = new ClientCashSubmitTable;
    m_pGoodsInfoTable = new GoodsInfoTable;
    m_pSaleHeadTable = new SaleHeadTable;
    m_pSaleDetailsTable = new SaleDetailsTable;
    m_pPayDetailsTable = new PayDetailsTable;
    m_pMemRechargeDetailsTable = new MemRechargeDetailsTable;
    m_pLoginRecordTable = new LoginRecordTable;
    initDatabase();
}

PosDB_Sqlite::~PosDB_Sqlite()
{
    if (m_pSalesmanInfoTable != NULL)
    {
        m_pSalesmanInfoTable->deleteLater();
    }

    if (m_wordDllTabel != NULL)
    {
        m_wordDllTabel->deleteLater();
    }

    if( m_pCategoryTable != NULL ) {
        m_pCategoryTable->deleteLater();
    }

    if( m_pClientCashSubmitTable != NULL ) {
        m_pClientCashSubmitTable->deleteLater();
    }

    if( m_pGoodsInfoTable != NULL ) {
        m_pGoodsInfoTable->deleteLater();
    }

    if( m_pSaleHeadTable != NULL ) {
        m_pSaleHeadTable->deleteLater();
    }

    if( m_pSaleDetailsTable != NULL ) {
        m_pSaleDetailsTable->deleteLater();
    }

    if( m_pPayDetailsTable != NULL ) {
        m_pPayDetailsTable->deleteLater();
    }

    if( m_pMemRechargeDetailsTable != NULL ) {
        m_pMemRechargeDetailsTable->deleteLater();
    }

    closeDatabase();
}

bool PosDB_Sqlite::openDatabase()
{
    if (isOpenDatabase())
    {
        return m_database.isOpen();
    }
    else
    {
        return m_database.open();
    }
}

void PosDB_Sqlite::closeDatabase()
{
    m_database.close();
}

bool PosDB_Sqlite::isOpenDatabase()
{
    return m_database.isOpen();
}

void PosDB_Sqlite::initDatabase()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE", c_sPosDB_SqliteConnectionName);
    closeDatabase();
    QString sDatabasePath = FilePathManage::instance()->getDatabaseDirPath() + c_sPosDB_SqliteName;
    m_database.setDatabaseName(sDatabasePath);
    openDatabase();
    m_pSalesmanInfoTable->setDatabase(&m_database);
    m_pCategoryTable->setDatabase(&m_database);
    m_pClientCashSubmitTable->setDatabase(&m_database);
    m_pGoodsInfoTable->setDatabase(&m_database);
    m_pSaleHeadTable->setDatabase( &m_database );
    m_pSaleDetailsTable->setDatabase( &m_database );
    m_pPayDetailsTable->setDatabase( &m_database );
    m_pMemRechargeDetailsTable->setDatabase( &m_database );
    m_pLoginRecordTable->setDatabase(&m_database);

}
