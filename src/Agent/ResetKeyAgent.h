#ifndef RESETKEYAGENT_H
#define RESETKEYAGENT_H

#include <QObject>
#include <QMutex>

class ResetKeyAgent : public QObject
{
    Q_OBJECT
public:
    static ResetKeyAgent* instance();
    void resetKeyRequest(QString oldkey, QString newkey);//修改密码

signals:
    void sigResetPasswd(int nCode, QString sMsg);//修改密码

private:
    explicit ResetKeyAgent(QObject *parent = 0);
    void initConnect();
    static ResetKeyAgent* m_pInstance;
};

#endif // RESETKEYAGENT_H
