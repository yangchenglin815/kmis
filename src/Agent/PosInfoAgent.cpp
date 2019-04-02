#include "PosInfoAgent.h"
#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "../util/ThreadManager.h"
#include "../util/KPosIni.h"
#include "../util/CommonFun.h"
#include "../data/enumData.h"
#include "../data/constData.h"
#include "../data/globaldata.h"
#include "OnlineStateAgent.h"
#include "ClientCashSubmitTable.h"
#include "../Database/PosDBFactory.h"


PosInfoAgent* PosInfoAgent::m_pInstance = NULL;

PosInfoAgent::PosInfoAgent()
{
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

PosInfoAgent *PosInfoAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new PosInfoAgent;
    }
    return m_pInstance;
}

void PosInfoAgent::getShopInfoRequest(QString sCorpID, QString sShopCode)
{
    HttpClient::instance()->getShopInfo(sCorpID, sShopCode);
}

void PosInfoAgent::registPosRequest(QString sCorpID, QString sShopCode)
{
    HttpClient::instance()->registerPos(sCorpID, sShopCode);
}

void PosInfoAgent::checkRegisterResultRequest()
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->checkRegisterResult();
    }
    else
    {
        emit sigLocalCheckRegisterResult();
    }
}

void PosInfoAgent::uploadClientCashSubmitRequest(QString sSubmitAmount)
{
    sSubmitAmount = sSubmitAmount.split("￥")[1];
    ClentCashSubmit_s m_clentCashSubmit;
    m_clentCashSubmit.uuid = CommonFun::getUUID();
    m_clentCashSubmit.operate_at = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    m_clentCashSubmit.last_submit_at = KPosIni::getLastHandPurseTime();
    m_clentCashSubmit.submit_amount = sSubmitAmount;
    m_clentCashSubmit.user_code = KPosIni::getUserCode();
    m_clentCashSubmit.login_at = KPosIni::getLoginTime();//登录时间
    m_clentCashSubmit.logout_at = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"); //登出时间

    if (OnlineStateAgent::instance()->isOnline())
    {
        m_clentCashSubmit.status = 0;
        m_clentCashSubmit.submit_code = PosDBFactory::getPosDB()->m_pClientCashSubmitTable->initClentCash(m_clentCashSubmit);
        HttpClient::instance()->uploadClientCashSubmit(m_clentCashSubmit);\
    }
    else
    {
        m_clentCashSubmit.status = 1;
        PosDBFactory::getPosDB()->m_pClientCashSubmitTable->initClentCash(m_clentCashSubmit);
        emit sigOnUploadClientCashSubmit(e_connectServerError, c_sNetError);
    }
}

void PosInfoAgent::pushClientCash()
{
    ClentCashSubmit_s clentCashSubmit;
    clentCashSubmit = PosDBFactory::getPosDB()->m_pClientCashSubmitTable->getFirstClentCash();

    if(NULL == clentCashSubmit.uuid){
        return;
    }
    HttpClient::instance()->uploadClientCashSubmitSync(clentCashSubmit);
//    qDebug()<<ClentCashSubmit.uuid;
}

//void PosInfoAgent::checkOnlineStateRequest()
//{
//    OnlineStateAgent::instance()->checkIsOnlineRequest(false);
//}

void PosInfoAgent::slot_onGetShopInfo(int nCode, QString sMsg, ShopInfo shopInfo)
{
    emit sigOnGetShopInfo(nCode, sMsg, shopInfo);
}

void PosInfoAgent::slot_onRegisterPos(int nCode, QString sMsg)
{
    emit sigOnRegisterPos(nCode, sMsg);
}

void PosInfoAgent::slot_onCheckRegisterResult(int nCode, QString sMsg, RegistResultInfo registResultInfo)
{
    if (nCode >= e_success)
    {
        if (nCode == e_success)
        {
            KPosIni::setRegistResult(registResultInfo.nRegistResult);
            KPosIni::setCorpID(registResultInfo.sCorpCode);
            if (!registResultInfo.sAppKey.isEmpty())
            {
                g_sHttpAPP_Key = registResultInfo.sAppKey;
                g_sHttpAPP_Secret = registResultInfo.sAppSecret;
                KPosIni::setAppKey(registResultInfo.sAppKey);
                KPosIni::setAppSecret(registResultInfo.sAppSecret);
            }
        }
        else if( nCode == e_posNotRegist)
        {
            KPosIni::setUserCode( "" );
            KPosIni::setUserName( "" );
            KPosIni::setPassword( "" );
            KPosIni::setCloseAppStatus( 1 );
        }
        emit sigOnCheckRegisterResult(nCode, sMsg, registResultInfo.nRegistResult);
    }
    else
    {
        slot_localCheckRegisterResult();
    }
}

void PosInfoAgent::slot_localCheckRegisterResult()
{
    int nRegistResult = KPosIni::getRegistResult();
    g_sHttpAPP_Key = KPosIni::getAppKey();
    g_sHttpAPP_Secret = KPosIni::getAppSecret();
    emit sigOnCheckRegisterResult(-1, QStringLiteral("网络异常"), nRegistResult);
}

//void PosInfoAgent::slot_onlineState(bool bOnline)
//{
//    Q_UNUSED(bOnline);
//    disconnect(OnlineStateAgent::instance(), SIGNAL(sigOnlineState(bool)), this, SLOT(slot_onlineState(bool)));
//    checkRegisterResultRequest();
//}

void PosInfoAgent::initConnect()
{
    qRegisterMetaType<ShopInfo>("ShopInfo");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetShopInfo(int, QString, ShopInfo)), this, SLOT(slot_onGetShopInfo(int, QString, ShopInfo)));
    connect(HttpSignal::instance(), SIGNAL(sigOnRegisterPos(int, QString)), this, SLOT(slot_onRegisterPos(int, QString)));
    qRegisterMetaType<RegistResultInfo>("RegistResultInfo");
    connect(HttpSignal::instance(), SIGNAL(sigOnCheckRegisterResult(int, QString, RegistResultInfo)),
            this, SLOT(slot_onCheckRegisterResult(int, QString, RegistResultInfo)));
    connect(this, SIGNAL(sigLocalCheckRegisterResult()), this, SLOT(slot_localCheckRegisterResult()));
//    connect(OnlineStateAgent::instance(), SIGNAL(sigOnlineState(bool)), this, SLOT(slot_onlineState(bool)));
    connect(HttpSignal::instance(), SIGNAL(sigOnUploadClientCashSubmit(int,QString)),
            this, SIGNAL(sigOnUploadClientCashSubmit(int,QString)));
}
