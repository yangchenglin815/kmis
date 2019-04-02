#ifndef POSREGISTERCTR_H
#define POSREGISTERCTR_H

#include <QObject>
#include <QTimer>
#include "../data/httpstructdata.h"

class PosRegisterCtr : public QObject
{
    Q_OBJECT
public:
    PosRegisterCtr(QObject* parent = NULL);
    void checkRegisterResultRequest();
    void getShopInfoRequest(QString sCorpID, QString sShopCode);
    void registerPosRequest(QString sCorpID, QString sShopCode);
    void checkKPosUpdateRequest();
    void checkOnlineStateRequest();
    void uploadClientCashSubmitRequest(QString sSubmitAmount);
    int getListSaleSize();

private slots:
    void slot_timeout();
    void slot_onGetShopInfo(int nCode, QString sMsg, ShopInfo shopInfo);
    void slot_onRegisterPos(int nCode, QString sMsg);
    void slot_onCheckRegisterResult(int nCode, QString sMsg, int nRegisterResult);
    void slot_onCheckKPosUpdate(int nCode, QString sMsg, KPosUpdateInfo kPosUpdateInfo);
    void slot_onlineState(bool bOnline);

private:
    void initConnect();

signals:
    void sigOnCheckRegisterResult(int nCode, QString sMsg, int nRegisterResult);
    void sigOnGetShopInfo(int nCode, QString sMsg, ShopInfo shopInfo);
    void sigOnRegisterPos(int nCode, QString sMsg);
    void sigOnCheckKPosUpdate(int nCode, QString sMsg, KPosUpdateInfo kPosUpdateInfo);
    void sigOnUploadClientCashSubmit(int nCode, QString sMsg);// 交款

private:
    QTimer m_timer;
};

#endif // POSREGISTERCTR_H
