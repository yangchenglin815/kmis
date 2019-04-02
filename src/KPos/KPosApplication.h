#ifndef KPOSAPPLICATION_H
#define KPOSAPPLICATION_H

#include <QApplication>
#include <QTimer>
#include "../Bussiness/PosRegisterCtr.h"
#include "LoginWidget.h"
#include "FirstLoginWidget.h"
#include "KPos.h"
#include "../util/GlobalEventFilter.h"
#include "KPosUpdate.h"
#include "DlgCommon.h"

class KPosApplication : public QApplication
{
    Q_OBJECT
public:
    KPosApplication(int &argc, char **argv);
    ~KPosApplication();
    void checkOnlineStateRequest();
    void checkRegisterResultRequest();
    void hintAllowOnlyoneRun();
private slots:
    void slot_onCheckRegisterResult(int nCode, QString sMsg, int nRegisterResult);
    void slot_onCheckKPosUpdate(int nCode, QString sMsg, KPosUpdateInfo kPosUpdateInfo);
    void slot_checkRegisterResultRequestAgain();
    void slot_loginSuccess();
    void slot_mouseChanged();
    void slot_lockScreen();
    void slot_handLockScreen();
    void slot_updateFailed();
    void slot_updateSuccess();
    void slot_closeWnd();
    void slot_logout();
    void slot_quitApp();
    void slot_paramsSetChanged();//参数设置修改
    void slot_remoteADChanged(QList<QString> remoteADList);
    void slot_widgetLogout();
    void slot_confirmLogout();

private:
    void initConnect();
    void checkKPosUpdateRequest();
    void beginLogin();

    void start_lockScreen();
    void stop_lockScreen();
private:
    PosRegisterCtr* m_pPosRegisterCtr;
    LoginWidget* m_pLoginWidget;
    FirstLoginWidget* m_pFirstLoginWidget;
    KPos* m_pKPos;
    QTimer m_checkRegistTimer;
    GlobalEventFilter* m_pGlobalEventFilter;
    QTimer m_lockScreenTimer;
    int m_nLockTimeLength;
    KPosUpdate* m_pKPosUpdate;

    int m_nTimerId;
    int m_nTimerCount;//按秒计数
    ClientCashSubmit* m_pClientCashSubmit;
};

#endif // KPOSAPPLICATION_H
