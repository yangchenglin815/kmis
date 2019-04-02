#ifndef PY_SQLITE_H
#define PY_SQLITE_H

#include <QSqlDatabase>
#include "PosDB.h"


class Py_Sqlite : public PosDB
{
public:
    Py_Sqlite();
    ~Py_Sqlite();
    bool openDatabase();
    void closeDatabase();
    bool isOpenDatabase();

private:
    void initDatabase();
    QSqlDatabase m_pyDatabase; //文字字库
};

#endif // PY_SQLITE_H
