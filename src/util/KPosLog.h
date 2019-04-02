#ifndef KPOSLOG_H
#define KPOSLOG_H

#include <QMutex>
#include <QString>

class KPosLog
{
public:
    ~KPosLog();
    static KPosLog* instance();
    void writeDebugLog(QString sDebugLog);
    void writeErrorLog(QString sErrorLog);
    void writeTestLog(QString sTestLog);
    void writeDatabaseLog(QString sLog);

private:
    KPosLog();
    void writeMessage(QString sContent, QString sFileName);

private:
    static KPosLog* m_pInstance;
    QMutex* m_pDebugMutex;
    QMutex* m_pErrorMutex;
    QMutex* m_pTestMutex;
    QMutex* m_pDatabaseMutex;
    QString m_sCurDate;
};

#endif // KPOSLOG_H
