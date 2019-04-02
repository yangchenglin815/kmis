#ifndef POSDB_SQLITE_H
#define POSDB_SQLITE_H

#include <QSqlDatabase>
#include "PosDB.h"

class PosDB_Sqlite : public PosDB
{
public:
    PosDB_Sqlite();
    ~PosDB_Sqlite();
    bool openDatabase();
    void closeDatabase();
    bool isOpenDatabase();

private:
    void initDatabase();
    QSqlDatabase m_database;
};

#endif // POSDB_SQLITE_H
