#include "PosDBFactory.h"
#include "PosDB_Sqlite.h"
#include "py_sqlite.h"

PosDB* PosDBFactory::m_pPosDB = NULL;
PosDB* PosDBFactory::m_pPyDB = NULL;

PosDB *PosDBFactory::getPosDB(int type)
{
    if (type == e_sqlite)
    {
        if (m_pPosDB == NULL)
        {
            m_pPosDB = new PosDB_Sqlite;
        }
    }
    else if (type == e_sqlServer)
    {

    }
    return m_pPosDB;
}

PosDB *PosDBFactory::getWordPosDB(int type)
{
    if (type == e_sqlite)
    {
        if (m_pPyDB == NULL)
        {
            m_pPyDB = new Py_Sqlite;
        }
    }
    else if (type == e_sqlServer)
    {

    }
    return m_pPyDB;
}

void PosDBFactory::release()
{
    if (m_pPosDB != NULL)
    {
        delete m_pPosDB;
        m_pPosDB = NULL;
    }
}
