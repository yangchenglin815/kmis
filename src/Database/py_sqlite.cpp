#include "py_sqlite.h"
#include "../Data/constData.h"
#include "../util/FilePathManage.h"
#include "PosDB.h"
#include <QDir>
#include <QDebug>

Py_Sqlite::Py_Sqlite()
{
    m_wordDllTabel = new WordDllTable;
    initDatabase();
}

Py_Sqlite::~Py_Sqlite()
{
    closeDatabase();
}

bool Py_Sqlite::openDatabase()
{
    if (isOpenDatabase())
    {
        return m_pyDatabase.isOpen();
    }
    else
    {
        return m_pyDatabase.open();
    }
}

void Py_Sqlite::closeDatabase()
{
    m_pyDatabase.close();
}

bool Py_Sqlite::isOpenDatabase()
{
    return m_pyDatabase.isOpen();
}

void Py_Sqlite::initDatabase()
{
    m_pyDatabase = QSqlDatabase::addDatabase("QSQLITE", c_py_SqliteConnectionName);
    closeDatabase();
    QString sDatabasePath = FilePathManage::instance()->getAppPath() + c_py_SqliteName;
    m_pyDatabase.setDatabaseName(sDatabasePath);
    openDatabase();
    m_wordDllTabel->setDatabase(&m_pyDatabase);
}
