#ifndef LOGINKPOSCTR_H
#define LOGINKPOSCTR_H

#include <QObject>
#include <QTimer>
#include <QMutex>
#include "../data/httpstructdata.h"
#include "../data/setstructdata.h"
#include "../util/HttpDownloadInterface.h"

class LoginKPosCtr : public QObject
{
    Q_OBJECT
public:
    explicit LoginKPosCtr(QObject *parent = 0);
    void loginKPosRequest(QString sUserCode, QString sPassword);
    void getAllUserInfoRequest();
    void logoutRequest(QString sSubmitMoney);
    void printLogoutReceipt();
    void checkUploadAllReceipt();

private slots:
    void slot_onLoginKPos(int nCode, QString sMsg, bool isAllowLocalLogin);
    void slot_uploadReceiptSuc();
//    void slot_onUploadClientCashSubmit(int nCode, QString sMsg);
    void slot_onGetAllGoods(int nCode, QString sMsg);
    void slot_onGetChangedGoods(int nCode, QString sMsg);
    void slot_onGetAllGoodsPrice(int nCode, QString sMsg);
    void slot_onGetCategory(int nCode, QString sMsg);
    void slot_onLogoutKPos(int nCode, QString sMsg);
    void slot_downloadKPosSetFinished();
    void slot_timeout();
    void slot_sendGetAllGoodsRequest(bool bSuccess);
    void slot_paramsSetChanged();
    void slot_screenSetChanged(ScreenSet screenSet);
    void slot_downFinished(bool bSuccess, QString sPath, int nTaskId);\
    void slot_finishReceiptUpload(bool bSuccess);

signals:
    void sigOnLoginKPos(int nCode, QString sMsg, bool isAllowLocalLogin);
    void sigOnGetCategory(int nCode, QString sMsg);
    void sigOnGetAllGoods(int nCode, QString sMsg);
    void sigOnGetAllGoodsPrice(int nCode, QString sMsg);
    void sigDownloadKPosSetFinished();
    void sigRemoteADChanged(QList<QString> remoteADList);
    void sigOnLogoutKPos(int nCode, QString sMsg); // 登出
    void sigFinisReceipUpload(bool bSuccess);

private:
    void initConnect();

private:
    QTimer m_timer; // 定时检测商品，配置，小票等数据更新
    QMap<int, HttpDownloadInterface*> m_httpDownloadInterfaceMap;
    int m_nRemoteAdNum;
    QList<QString> m_remoteAdPathList;
    bool m_bLogout;
};

#endif // LOGINKPOSCTR_H
