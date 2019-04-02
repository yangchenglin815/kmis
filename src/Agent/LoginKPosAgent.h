#ifndef LOGINKPOSAGENT_H
#define LOGINKPOSAGENT_H

#include <QObject>
#include "../data/httpstructdata.h"

class LoginKPosAgent : public QObject
{
    Q_OBJECT
public:
    static LoginKPosAgent* instance();
    void loginKPosRequest(QString sUserCode, QString sPassword);
    void updateToken();
    void getAllUserInfoRequest();
    LoginKPosInfo getLoginKPosInfo();
    bool isInitFinish();
    void setInitFinishFlag(bool bFinish);
    bool getAllSalemanInfo( QList<SalemanInfo> &listSalemanInfo );
//    void addLoginoutRecord(QString sLoginTime);
    void logoutRequest(QString sSubmitMoney);
    void getLogoutReceiptData();

private slots:
    void slot_onLoginKPos(int nCode, QString sMsg, LoginKPosInfo loginKPosInfo);
    void slot_localLoginKPos(int nCode, QString sMsg, LoginKPosInfo loginKPosInfo);
    void slot_onGetAllUserInfo( int nCode, QString sMsg, QList<SalemanInfo> listSalemanInfo );
    void slot_onLogoutKPos(int nCode, QString sMsg);
    void slot_OnUpdateToken(QString sToken);

private:
    explicit LoginKPosAgent();
    void initConnect();
    void insertUserInfo(SalemanInfo stSalemanInfo);
    void updateUserInfo( SalemanInfo stSalemanInfo );
    void deleteUserInfo(SalemanInfo stSalemanInfo);
    void countPaymethodMoney(QMap<QString, QString>& payMethodMap, const QList<QString>& orderNumList); // 统计各种支付方式收的钱

signals:
    void sigOnLoginKPos(int nCode, QString sMsg, bool isAllowLocalLogin = false);
    void sigOnLogoutKPos(int nCode, QString sMsg); // 登出

private:
    static LoginKPosAgent* m_pInstance;
    LoginKPosInfo m_loginKPosInfo;
    bool m_bInitFinish;

    QList<SalemanInfo> m_listSalemanInfo;//所有员工信息的列表
};

#endif // LOGINKPOSAGENT_H
