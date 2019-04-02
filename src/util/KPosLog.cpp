#include "KPosLog.h"
#include <QDir>
#include <QDateTime>
#include <QTextStream>
#include <QIODevice>

KPosLog* KPosLog::m_pInstance = NULL;

KPosLog::KPosLog()
{
    m_sCurDate = QDateTime::currentDateTime().toString("yyyyMMdd");
    m_pErrorMutex = new QMutex;
    m_pDebugMutex = new QMutex;
    m_pTestMutex = new QMutex;
    m_pDatabaseMutex = new QMutex;
}

KPosLog::~KPosLog()
{
    if (m_pErrorMutex != NULL)
    {
        delete m_pErrorMutex;
        m_pErrorMutex = NULL;
    }
    if (m_pDebugMutex != NULL)
    {
        delete m_pDebugMutex;
        m_pDebugMutex = NULL;
    }
    if (m_pTestMutex != NULL)
    {
        delete m_pTestMutex;
        m_pTestMutex = NULL;
    }
}

KPosLog *KPosLog::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new KPosLog;
    }

    return m_pInstance;
}

void KPosLog::writeDebugLog(QString sDebugLog)
{
    m_pDebugMutex->lock();
    writeMessage(sDebugLog, m_sCurDate + "_debug.txt");
    m_pDebugMutex->unlock();
}

void KPosLog::writeErrorLog(QString sErrorLog)
{
    m_pErrorMutex->lock();
    writeMessage(sErrorLog, m_sCurDate + "_error.txt");
    m_pErrorMutex->unlock();
}

void KPosLog::writeTestLog(QString sTestLog)
{
//    m_pTestMutex->lock();
//    writeMessage(sTestLog, m_sCurDate + "_test.txt");
//    m_pTestMutex->unlock();
}

void KPosLog::writeDatabaseLog(QString sLog)
{
//    m_pDatabaseMutex->lock();
//    writeMessage(sLog, m_sCurDate + "_database.txt");
//    m_pDatabaseMutex->unlock();
}

void KPosLog::writeMessage(QString sContent, QString sFileName)
{
    QString logPath = "./log";
    //查看是否包含该目录
    QDir logDir;
    if (!logDir.exists(logPath))
    {
        logDir.mkpath(logPath);
    }
    //拼字符串
    QFile file(logPath + "//" + sFileName);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString message = QString("%1 %2").arg(current_date_time).arg(sContent);

    //打开文件写入
    if (file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream text_stream(&file);
        text_stream << message << "\r\n\r\n";
        file.flush();
    }
    file.close();

//    if (file.size() > 100*1024*1024)
//    {
//        file.remove();
//    }
}
