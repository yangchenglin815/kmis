#ifndef DBFACTORY_H
#define DBFACTORY_H

#include "PosDB.h"
#include "../data/enumData.h"

class PosDBFactory
{
public:
    static PosDB *getPosDB(int type = e_sqlite);
    static PosDB *getWordPosDB(int type = e_sqlite);
    static void release();

private:
    static PosDB* m_pPosDB;
    static PosDB* m_pPyDB;
};

#endif // DBFACTORY_H
