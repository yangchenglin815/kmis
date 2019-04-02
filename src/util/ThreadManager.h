#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QThread>

class ThreadManager : public QObject
{
    Q_OBJECT
public:
    static QThread* getAgentThread();
    static QThread* getDownloadThread();

private:
    static QThread* m_pAgentThread;
    static QThread* m_pDownloadThread;
};

#endif // THREADMANAGER_H
