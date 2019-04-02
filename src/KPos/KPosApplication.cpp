#include "KPosApplication.h"
#include "../data/enumData.h"
#include "DlgCommon.h"
#include <QDebug>
#include "KPosIni.h"
#include "KPosStartHintDlg.h"
#include "KPosSetAgent.h"
#include "CommonFun.h"
#include "BalanceManage.h"
#include "SaleHeadAgent.h"

KPosApplication::KPosApplication(int &argc, char **argv)
    : QApplication(argc, argv)
    , m_pPosRegisterCtr(NULL)
    , m_pLoginWidget(NULL)
    , m_pFirstLoginWidget(NULL)
    , m_pKPos(NULL)
    , m_pGlobalEventFilter(NULL)
    , m_nLockTimeLength(5*60) // 5分钟
    , m_pKPosUpdate(NULL)
    , m_nTimerId( -1 )
    , m_nTimerCount( 0 )
    , m_pClientCashSubmit(NULL)
{
    m_pPosRegisterCtr = new PosRegisterCtr;
    initConnect();
    slot_paramsSetChanged();
}

KPosApplication::~KPosApplication()
{
    if (m_pPosRegisterCtr != NULL)
    {
        m_pPosRegisterCtr->deleteLater();
        m_pPosRegisterCtr = NULL;
    }
    if (m_pLoginWidget != NULL)
    {
        m_pLoginWidget->deleteLater();
        m_pLoginWidget = NULL;
    }
    if (m_pFirstLoginWidget != NULL)
    {
        m_pFirstLoginWidget->deleteLater();
        m_pFirstLoginWidget = NULL;
    }
    if (m_pKPos != NULL)
    {
        //m_pKPos->deleteLater();//使用这个方法，调试时，无法进入KPos析构函数
        delete m_pKPos;
        m_pKPos = NULL;
    }
    if (m_pGlobalEventFilter != NULL)
    {
        m_pGlobalEventFilter->deleteLater();
        m_pGlobalEventFilter = NULL;
    }
    if (m_pKPosUpdate != NULL)
    {
        m_pKPosUpdate->deleteLater();
        m_pKPosUpdate = NULL;
    }
}

void KPosApplication::checkOnlineStateRequest()
{
    if (m_pPosRegisterCtr != NULL)
    {
        KPosStartHintDlg::instance()->set_content(QString("正在检查在线状态,请稍等..."));
        KPosStartHintDlg::instance()->show();
        m_pPosRegisterCtr->checkOnlineStateRequest();
    }
}

void KPosApplication::checkRegisterResultRequest()
{
    if (m_pPosRegisterCtr != NULL)
    {
        m_pPosRegisterCtr->checkRegisterResultRequest();
    }
}

void KPosApplication::hintAllowOnlyoneRun()
{
    DlgCommon *hintDlg = new DlgCommon;
    hintDlg->set_title(QStringLiteral("提示"));
    hintDlg->set_content(QStringLiteral("检测到已经有KPos正在运行，只允许运行一个"));
    connect(hintDlg, SIGNAL(sig_dlg_close()), hintDlg, SLOT(close()));
    connect(hintDlg, SIGNAL(sig_btn_sure()), hintDlg, SLOT(close()));
    connect(hintDlg, SIGNAL(sig_btn_cancel()), hintDlg, SLOT(close()));
    hintDlg->exec();
}

void KPosApplication::slot_onCheckRegisterResult(int nCode, QString sMsg, int nRegisterResult)
{
    Q_UNUSED(sMsg)
    if (nCode == e_success || nCode < 0)
    {
        if (nRegisterResult == e_checked) // 审核通过
        {
            checkKPosUpdateRequest();
        }
        else if (nRegisterResult == e_checking)
        {
            if (m_pFirstLoginWidget == NULL)
            {
                m_pFirstLoginWidget = new FirstLoginWidget;
                m_pFirstLoginWidget->setPosRegisterCtr(m_pPosRegisterCtr);
                connect( m_pFirstLoginWidget, SIGNAL(sig_close_login_widget()), this,  SLOT( slot_quitApp() ) );
            }
            m_pFirstLoginWidget->showRegistPage(false);
            m_pFirstLoginWidget->show();
            if (!m_checkRegistTimer.isActive())
            {
                m_checkRegistTimer.start(1000*60); // 60秒
            }
        }
        else
        {
            if (m_pFirstLoginWidget == NULL)
            {
                m_pFirstLoginWidget = new FirstLoginWidget;
                m_pFirstLoginWidget->setPosRegisterCtr(m_pPosRegisterCtr);
                connect( m_pFirstLoginWidget, SIGNAL(sig_close_login_widget()), this,  SLOT( slot_quitApp() ) );
            }
            m_pFirstLoginWidget->showRegistPage(true);
            m_pFirstLoginWidget->setEditEnabled( true );
            m_pFirstLoginWidget->setHintText(QStringLiteral("出错了， %1").arg(sMsg));
            m_pFirstLoginWidget->show();
        }
    }
    else if (nCode == e_posNotRegist)
    {
        if (m_pFirstLoginWidget == NULL)
        {
            m_pFirstLoginWidget = new FirstLoginWidget;
            m_pFirstLoginWidget->setPosRegisterCtr(m_pPosRegisterCtr);
            connect( m_pFirstLoginWidget, SIGNAL(sig_close_login_widget()), this,  SLOT( slot_quitApp() ) );
        }
        m_pFirstLoginWidget->showRegistPage(true);
        static int i = 0;
        if (i != 0)
        {
            m_pFirstLoginWidget->setHintText(QString(QStringLiteral("设备未注册，%1，请重新申请。")).arg(i));
        }
        m_pFirstLoginWidget->setEditEnabled( true );
        m_pFirstLoginWidget->show();
        i++;
    }
    else
    {
        if (m_pFirstLoginWidget == NULL)
        {
            m_pFirstLoginWidget = new FirstLoginWidget;
            m_pFirstLoginWidget->setPosRegisterCtr(m_pPosRegisterCtr);
            connect( m_pFirstLoginWidget, SIGNAL(sig_close_login_widget()), this,  SLOT( slot_quitApp() ) );
        }
        m_pFirstLoginWidget->showRegistPage(true);
        m_pFirstLoginWidget->setEditEnabled( true );
        m_pFirstLoginWidget->setHintText(QString(QStringLiteral("未知状况, msg:%1")).arg(sMsg));
        m_pFirstLoginWidget->show();
    }

    if (nCode < 0 && m_pFirstLoginWidget != NULL)
    {
        m_pFirstLoginWidget->showRegistPage(true);
        m_pFirstLoginWidget->setEditEnabled( true );
        m_pFirstLoginWidget->setHintText(QStringLiteral("现在是离线状态，无法远程审核！"));
        m_pFirstLoginWidget->show();
    }

    if (m_pFirstLoginWidget != NULL)
    {
        KPosStartHintDlg::instance()->hide();
    }
}

void KPosApplication::slot_onCheckKPosUpdate(int nCode, QString sMsg, KPosUpdateInfo kPosUpdateInfo)
{
    KPosStartHintDlg::instance()->set_content(QStringLiteral("检测完毕"));
    if (nCode == e_connectServerError)
    {
        KPosStartHintDlg::instance()->set_content(QStringLiteral("网络异常，可能会进行离线操作！"));
        KPosStartHintDlg::instance()->show();
    }
    else
    {
        KPosStartHintDlg::instance()->hide();
    }

    Q_UNUSED(sMsg)
    if (nCode == e_success
            && kPosUpdateInfo.nUpdateType != e_noUpdate
            && !kPosUpdateInfo.sAddress.isEmpty())
    {
        int nSize = m_pPosRegisterCtr->getListSaleSize();
        if(nSize != 0)
        {
            beginLogin();
            m_pLoginWidget->sethintLabel("有新版本，小票未上传,无法更新");
            return;
        }

        if (kPosUpdateInfo.nUpdateType == e_install)
        {
            if (m_pKPosUpdate == NULL)
            {
                m_pKPosUpdate = new KPosUpdate;
                connect(m_pKPosUpdate, SIGNAL(sigDownloadError()), this, SLOT(slot_updateFailed()));
                connect(m_pKPosUpdate, SIGNAL(sigInstallStartSuccess()), this, SLOT(slot_updateSuccess()));
            }
            m_pKPosUpdate->installUpdate(kPosUpdateInfo.sAddress);
            return;
        }
        else if (kPosUpdateInfo.nUpdateType == e_increment)
        {
            // return;
        }
    }

    beginLogin();
}

void KPosApplication::slot_checkRegisterResultRequestAgain()
{
    m_checkRegistTimer.stop();
    checkRegisterResultRequest();
}

//#include "../HttpClient/HttpClient.h" // 测试
void KPosApplication::slot_loginSuccess()
{
    if (m_pKPos == NULL)
    {
        m_pKPos = new KPos;
        KPosIni::setCloseAppStatus( 0 );
        connect(m_pKPos, SIGNAL( sig_closeWnd() ), this, SLOT( slot_closeWnd() ));
        connect( m_pKPos, SIGNAL(sig_lockScreen()), this, SLOT( slot_handLockScreen() ) );
    }
    m_pKPos->reInit();
    m_pKPos->show();

    if (m_pGlobalEventFilter == NULL)
    {
        m_pGlobalEventFilter = new GlobalEventFilter;
        connect(m_pGlobalEventFilter, SIGNAL(sigMouseChanged()), this, SLOT(slot_mouseChanged()));
        this->installEventFilter(m_pGlobalEventFilter);
    }
    start_lockScreen();

    if (m_pLoginWidget != NULL)
    {
        m_pLoginWidget->hide();
    }

//    KPosSet kposSet; // 测试
//    HttpClient::instance()->uploadKPosSet(kposSet, false);// 测试
//    HttpClient::instance()->downloadKPosSet();// 测试
//    HttpClient::instance()->addCustomCategory(QStringLiteral("自定义分类2"));// 测试
//    HttpClient::instance()->updateCustomCategory(3, "自定义分类3修改");// 测试
//    HttpClient::instance()->deleteCustomCategory(3);// 测试

//    HttpClient::instance()->uploadScreenAD("D://qtTest//testFile//res//test.doc");
}

void KPosApplication::slot_mouseChanged()
{
    m_nTimerCount = 0;
//    m_lockScreenTimer.stop();
//    m_lockScreenTimer.start(m_nLockTimeLength);
//    qDebug()<<QStringLiteral("slot_mouseChanged");
}

void KPosApplication::slot_lockScreen()
{
    if( m_nTimerCount < m_nLockTimeLength ) {
        ++m_nTimerCount;
        return;
    }

//    qDebug()<<QStringLiteral("该锁屏了");
    stop_lockScreen();
    if (m_pLoginWidget != NULL)
    {
        m_pLoginWidget->showLockPage();
        m_pLoginWidget->show();
//        if (m_pKPos != NULL)
//        {
//            m_pKPos->hide();
//        }
    }
}

//手动锁屏
void KPosApplication::slot_handLockScreen()
{
    stop_lockScreen();
    if (m_pLoginWidget != NULL)
    {
        m_pLoginWidget->showLockPage();
        m_pLoginWidget->show();
        if (m_pKPos != NULL)
        {
            m_pKPos->hide();
        }
    }
}

void KPosApplication::slot_updateFailed()
{
    beginLogin();
}

void KPosApplication::slot_updateSuccess()
{
    this->quit();
}

void KPosApplication::slot_closeWnd()
{
    if (m_pLoginWidget != NULL)
    {
        m_pLoginWidget->checkUploadAllReceipt();
    }

//    BalanceManage::instance()->openCashBox();
//    if (m_pClientCashSubmit == NULL)
//    {
//        m_pClientCashSubmit = new ClientCashSubmit;
//        m_pClientCashSubmit->setCtrl(m_pPosRegisterCtr);
//        connect(m_pClientCashSubmit, SIGNAL(sigClose()), this, SLOT(slot_logout()));
//    }

//    m_pClientCashSubmit->clearData();

//    m_pClientCashSubmit->exec();
}

void KPosApplication::slot_logout()
{
    stop_lockScreen();
    QString sSubmitMoney = "";
    if (m_pClientCashSubmit != NULL)
    {
        sSubmitMoney = m_pClientCashSubmit->getSumMoney();
        m_pClientCashSubmit->hide();
        m_pClientCashSubmit->clearData();
    }

    if (m_pLoginWidget != NULL)
    {
        m_pLoginWidget->logout(sSubmitMoney);
        m_pLoginWidget->clearData();
    }
}

void KPosApplication::slot_quitApp()
{
    KPosIni::setCloseAppStatus( 1 );
    quit();
}

void KPosApplication::slot_paramsSetChanged()
{
    KPosSet stKPosSet;
    KPosSetAgent::instance()->getKPosSetInfo( stKPosSet );
    int nLockWaitTimeLenth = stKPosSet.paramsSet.shopSetParams.nLockWaitTimeLenth;
    if( nLockWaitTimeLenth == 0 ) {
        m_nLockTimeLength = nLockWaitTimeLenth;
        //那么关闭定时器
        stop_lockScreen();
    } else if( nLockWaitTimeLenth > 0 ){
        //重新开启计数
        m_nTimerCount = 0;
        m_nLockTimeLength = nLockWaitTimeLenth*60;//秒，用秒定时，时间更精确
        start_lockScreen();
    }
}

void KPosApplication::slot_remoteADChanged(QList<QString> remoteADList)
{
    if (m_pKPos != NULL)
    {
        m_pKPos->setRemoteADList(remoteADList);
    }
}

void KPosApplication::slot_widgetLogout()
{
    if (m_pLoginWidget != NULL)
    {
        if (m_pKPos != NULL)
        {
            m_pKPos->hide();
        }
        m_pLoginWidget->showLoginPage();
        m_pLoginWidget->activateWindow();
        m_pLoginWidget->showNormal();
    }
}

void KPosApplication::slot_confirmLogout()
{
    BalanceManage::instance()->openCashBox();
    if (m_pClientCashSubmit == NULL)
    {
        m_pClientCashSubmit = new ClientCashSubmit;
        m_pClientCashSubmit->setCtrl(m_pPosRegisterCtr);
        connect(m_pClientCashSubmit, SIGNAL(sigClose()), this, SLOT(slot_logout()));
    }

    m_pClientCashSubmit->clearData();
    m_pClientCashSubmit->exec();
}

void KPosApplication::initConnect()
{
    connect(m_pPosRegisterCtr, SIGNAL(sigOnCheckRegisterResult(int, QString, int)), this, SLOT(slot_onCheckRegisterResult(int, QString, int)));
    qRegisterMetaType<KPosUpdateInfo>("KPosUpdateInfo");
    connect(m_pPosRegisterCtr, SIGNAL(sigOnCheckKPosUpdate(int, QString, KPosUpdateInfo)),
            this, SLOT(slot_onCheckKPosUpdate(int, QString, KPosUpdateInfo)));
    connect(&m_checkRegistTimer, SIGNAL(timeout()), this, SLOT(slot_checkRegisterResultRequestAgain()));
    connect(&m_lockScreenTimer, SIGNAL(timeout()), this, SLOT(slot_lockScreen()));
    connect( KPosSetAgent::instance(), SIGNAL(sigParamsSetChanged()), this, SLOT( slot_paramsSetChanged() ) );
}

void KPosApplication::checkKPosUpdateRequest()
{
    if (m_pPosRegisterCtr != NULL)
    {
        KPosStartHintDlg::instance()->set_content("正在检测版本，请稍等...");
        m_pPosRegisterCtr->checkKPosUpdateRequest();
    }
}

void KPosApplication::beginLogin()
{
    if (m_pFirstLoginWidget != NULL)
    {
        m_pFirstLoginWidget->deleteLater();
        m_pFirstLoginWidget = NULL;
    }

    if (m_pLoginWidget == NULL)
    {
        m_pLoginWidget = new LoginWidget();
        connect(m_pLoginWidget, SIGNAL(sigLoginSuccess()), this, SLOT(slot_loginSuccess()));
        connect( m_pLoginWidget, SIGNAL(sig_close_login_widget()), this,  SLOT( slot_quitApp() ) );
        connect(m_pLoginWidget, SIGNAL(sigRemoteADChanged(QList<QString>)), this, SLOT(slot_remoteADChanged(QList<QString>)));
        connect(m_pLoginWidget, SIGNAL(sigLogout()), this, SLOT(slot_widgetLogout()));
        connect(m_pLoginWidget, SIGNAL(sigConfirmLogout()), this, SLOT(slot_confirmLogout()));
    }

    m_pLoginWidget->initUserName();
    m_pLoginWidget->show();
    m_checkRegistTimer.stop();
}


void KPosApplication::start_lockScreen()
{
    if( m_nTimerId < 0 && m_nLockTimeLength != 0 ){
        m_lockScreenTimer.start(1000);//1秒
        m_nTimerId = m_lockScreenTimer.timerId();
    }
}

void KPosApplication::stop_lockScreen()
{
    if( m_nTimerId > 0 ){
        m_lockScreenTimer.stop();
        m_nTimerId = -1;
        m_nTimerCount = 0;
    }
}

