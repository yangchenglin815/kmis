#include "MTComAPIMananger.h"
#include "MTComAPIDll.h"
#include "../util/KPosServerIni.h"

MTComAPIMananger* MTComAPIMananger::m_pInstance = NULL;

MTComAPIMananger::MTComAPIMananger(QWidget *parent)
    : QWidget(parent)
    , m_sWeight("00.0000")
    , m_nCheckTimeLen( 500 )
    , m_bUseMTCom(false)
{
    m_bUseMTCom = KPosServerIni::isUseMTComAPIDll();
    initConnect();
}

MTComAPIMananger *MTComAPIMananger::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new MTComAPIMananger;
    }
    return m_pInstance;
}

void MTComAPIMananger::openMTCom()
{
    if (m_bUseMTCom)
    {
        MTComAPIDll::openMTCom();
    }
}

void MTComAPIMananger::release()
{
    if (m_bUseMTCom)
    {
        MTComAPIDll::closeMTCom();
    }

    if (m_pInstance != NULL)
    {
        m_pInstance->deleteLater();
        m_pInstance = NULL;
    }
}

void MTComAPIMananger::stopCheckWeight()
{
    m_timer.stop();
}

void MTComAPIMananger::startCheckWeight()
{
    if (m_bUseMTCom)
    {
        if (MTComAPIDll::isOpen())
        {
            m_timer.start();
        }
    }
}

void MTComAPIMananger::setCheckTimeLen(int nTimeLen)
{
    m_nCheckTimeLen = nTimeLen;
}

void MTComAPIMananger::slot_timeOut()
{
    m_timer.stop();
    EBalanceStandard_Ex balanceStandard_Ex;
    MTComAPIDll::readWeight(balanceStandard_Ex);
    m_sWeight = balanceStandard_Ex.sWeight;
    m_stableTimer.start();
}

void MTComAPIMananger::slot_stableTimeout()
{
    EBalanceStandard_Ex balanceStandard_Ex;
    MTComAPIDll::readWeight(balanceStandard_Ex);
    bool bStable = ((m_sWeight == balanceStandard_Ex.sWeight) && balanceStandard_Ex.bStable);
    m_sWeight = balanceStandard_Ex.sWeight;

//    if( balanceStandard_Ex.sWeight.toFloat() < 0 ) {
//        balanceStandard_Ex.bLessWeight = true;
//    } else {
//        balanceStandard_Ex.bLessWeight = false;
//    }

    emit sig_stableInfo(balanceStandard_Ex, bStable);

    if (bStable)
    {
        m_stableTimer.stop();
        m_timer.start(m_nCheckTimeLen);
    }
    else
    {
        m_stableTimer.stop();
        m_stableTimer.start(200);
    }
}

void MTComAPIMananger::initConnect()
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(slot_timeOut()));
    connect(&m_stableTimer, SIGNAL(timeout()), this, SLOT(slot_stableTimeout()));
}

