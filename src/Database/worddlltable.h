#ifndef WORDDLLTABLE_H
#define WORDDLLTABLE_H

#include <QSqlDatabase>

#include "DbBaseTable.h"


class WordDllTable : public DbBaseTable
{
    Q_OBJECT
public:
    explicit WordDllTable(QObject *parent = 0);
    QString getWordInfo(QString pinyin);
    void setDatabase(QSqlDatabase* pDatabase);

private:
    QSqlDatabase* m_PyDatabase;
    QString m_sTableName; // 表名
};

#endif // WORDDLLTABLE_H
