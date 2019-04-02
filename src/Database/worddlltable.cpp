#include "WordDlltable.h"
#include "../util/KPosLog.h"
#include <QSqlQuery>
#include <QVariant>

WordDllTable::WordDllTable(QObject *parent)
    : DbBaseTable(parent)
    , m_PyDatabase(NULL)
    , m_sTableName("pinyin")
{

}

QString WordDllTable::getWordInfo(QString pinyin)
{
    QSqlQuery query(*m_PyDatabase);
    QString wordList;
    QString sqlTemp = QString("select word from %1 where pinyin = '%2'").arg("pinyin").arg(pinyin);
    if (!query.exec(sqlTemp))
    {
        KPosLog::instance()->writeErrorLog(QString("wordDllTable::getWordInfo -- %1").arg(sqlTemp));
    }
    while(query.next()){
         wordList = query.value(0).toString();
    }
    return wordList;
}

void WordDllTable::setDatabase(QSqlDatabase *pDatabase)
{
    m_PyDatabase = pDatabase;
}
