#ifndef ONLINESTATEAGENT_H
#define ONLINESTATEAGENT_H

#include <QObject>
#include <QMutex>
#include <QReadWriteLock>
#include <QTimer>

class MyMutexReadLocker
{
public:
    MyMutexReadLocker(QReadWriteLock& readwriteLock);
    ~MyMutexReadLocker();
private:
    QReadWriteLock *m_pReadWriteLock;
};

class OnlineStateAgent : public QObject
{
    Q_OBJECT

public:
    static OnlineStateAgent* instance();
    void checkIsOnlineRequest();
    bool isOnline();
    void setOnlineState(bool isOnline);

signals:
    void sigOnlineState( bool isOnline );
    void sigUploadReceipt( bool isOnline );//在有网的情况下，上传小票

private slots:
    void slot_onlineState(bool isOnline);
    void slot_timeout();
    void slot_overTimeout();

private:
    explicit OnlineStateAgent();
    void initConnect();

private:
    static OnlineStateAgent* m_pInstance;
    bool m_bOnline;
    QReadWriteLock m_readWriteLock;
};

#endif // ONLINESTATEAGENT_H
