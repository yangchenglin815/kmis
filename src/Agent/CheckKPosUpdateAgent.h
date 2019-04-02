#ifndef CHECKKPOSUPDATEAGENT_H
#define CHECKKPOSUPDATEAGENT_H

#include <QObject>
#include "../data/httpstructdata.h"

class CheckKPosUpdateAgent : public QObject
{
    Q_OBJECT
public:
    static CheckKPosUpdateAgent* instance();
    void checkKPosUpdateRequest();

private slots:
    void slot_onCheckKPosUpdate(int nCode, QString sMsg, KPosUpdateInfo kPosUpdateInfo);
    void slot_localCheckKPosUpdate();

signals:
    void sigOnCheckKPosUpdate(int nCode, QString sMsg, KPosUpdateInfo kPosUpdateInfo);
    void sigLocalCheckKPosUpdate();

private:
    explicit CheckKPosUpdateAgent(QObject *parent = 0);
    void initConnect();

private:
    static CheckKPosUpdateAgent* m_pInstance;
};

#endif // CHECKKPOSUPDATEAGENT_H
