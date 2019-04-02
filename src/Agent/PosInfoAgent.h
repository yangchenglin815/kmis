#ifndef POSINFOAGENT_H
#define POSINFOAGENT_H

#include <QObject>
#include "../data/httpstructdata.h"

class PosInfoAgent : public QObject
{
    Q_OBJECT
public:
    static PosInfoAgent* instance();
    void getShopInfoRequest(QString sCorpID, QString sShopCode);
    void registPosRequest(QString sCorpID, QString sShopCode);
    void checkRegisterResultRequest();
    void uploadClientCashSubmitRequest(QString sSubmitAmount);
    void pushClientCash();
//    void checkOnlineStateRequest();

private slots:
    void slot_onGetShopInfo(int nCode, QString sMsg, ShopInfo shopInfo);
    void slot_onRegisterPos(int nCode, QString sMsg);
    void slot_onCheckRegisterResult(int nCode, QString sMsg, RegistResultInfo registResultInfo);
    void slot_localCheckRegisterResult();
//    void slot_onlineState(bool bOnline);

private:
    PosInfoAgent();
    void initConnect();

signals:
    void sigOnGetShopInfo(int nCode, QString sMsg, ShopInfo shopInfo);
    void sigOnRegisterPos(int nCode, QString sMsg);
    void sigOnCheckRegisterResult(int nCode, QString sMsg, int sRegisterResult); // 检测注册状态
    void sigLocalCheckRegisterResult();
    void sigOnUploadClientCashSubmit(int nCode, QString sMsg);// 交款

private:
    static PosInfoAgent* m_pInstance;
};

#endif // POSINFOAGENT_H
