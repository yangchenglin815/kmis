#include "BalanceManage.h"
#include "KPosAddDll.h"
#include "KPosAdDll2.h"
#include "KPosAddDllUAN.h"
#include "KPosLog.h"
#include "../util/KPosServerIni.h"
#include "KPosIni.h"
#include "../data/constData.h"
#include "../util/KPosLog.h"
#include <QMessageBox>
#include "ScaleVgaData.h"

BalanceManage* BalanceManage::m_pInstance = NULL;

BalanceManage::BalanceManage(QObject *parent)
    : QObject(parent)
    , m_sWeight("00.0000")
    , m_nCheckTimeLen( 200 )
    , m_bAutoPeel(false)
    ,m_scaleVgaData(new ScaleVgaData())
{
    initConnect();
    m_sPosName = getPosName();
}

BalanceManage *BalanceManage::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new BalanceManage;
    }
    return m_pInstance;
}

void BalanceManage::Release()
{
    if( m_pInstance ) {
        m_pInstance->deleteLater();
        m_pInstance = NULL;
    }
}

void BalanceManage::startCheckBalance()
{

    if (!m_timer.isActive())
    {
        m_timer.start();
    }

}

void BalanceManage::stopCheckBalance()
{
    m_timer.stop();
    m_stableTimer.stop();
}

void BalanceManage::setCheckTimeLen(int nTimeLen)
{
    m_nCheckTimeLen = nTimeLen;
}

void BalanceManage::autoClearTareWeight()
{
    m_bAutoPeel = true;
    //    m_timer.stop();
    //    m_stableTimer.stop();
    //    if (m_sPosName == c_sMettLerBalance)
    //    {
    //        KPosAddDll::autoRemovePeel();
    //    }
    //    else if (m_sPosName == c_sWinTecBalance)
    //    {
    //        KPosAdDll2::autoRemovePeel();
    //    }
    //    m_timer.start(m_nCheckTimeLen);
}

void BalanceManage::openCashBox()
{
    if (m_sPosName == c_sMettLerBalance)
    {
        KPosAddDll::openCashBox();
    }
    else if (m_sPosName == c_sWinTecBalance)
    {
        KPosAdDll2::openCashBox();
    }
    else if (m_sPosName == c_sUANBalance)
    {
        KPosAddDllUAN::openCashBox();
    }
}

void BalanceManage::printBitmapFile(QString sBitmapPath)
{
    if (m_sPosName == c_sMettLerBalance)
    {
        KPosAddDll::printBitmapFile(sBitmapPath);
    }
    else if (m_sPosName == c_sWinTecBalance)
    {
        KPosAdDll2::printBitmapFile(sBitmapPath);
    }
    else if (m_sPosName == c_sUANBalance)
    {
        KPosAddDllUAN::printBitmapFile(sBitmapPath);
    }
}

void BalanceManage::cutPage()
{
    if (m_sPosName == c_sMettLerBalance)
    {
        KPosAddDll::cutPage();
    }
    else if (m_sPosName == c_sWinTecBalance)
    {
        KPosAdDll2::cutPage();
    }
    else if (m_sPosName == c_sUANBalance)
    {
        KPosAddDllUAN::cutPage();
    }
}

bool BalanceManage::testDll(QString sPosName, QString &sHintText)
{
    if (sPosName == c_sMettLerBalance)
    {
        return KPosAddDll::testDll(sHintText);
    }
    else if (sPosName == c_sUANBalance)
    {
        return KPosAddDllUAN::testDll(sHintText);
    }
    else if (sPosName == c_sWinTecBalance)
    {
        return KPosAdDll2::testDll(sHintText);
    }
    else if (sPosName == c_sOnlyPc)
    {
        return true;
    }
    else
    {
        return false;
    }
}

QString BalanceManage::AnalysisScaleWeight(QString sData)
{
    int PricingScaleType = KPosServerIni::getPricingScaleType();//获取计价秤型号id
    QString Weight;
    switch (PricingScaleType)
    {
        case 0://大华
        {
            Weight = sData.left(2) + "." + sData.mid(2,5);
            break;
        }
        case 1://凯士
        {
            Weight = sData.left(8);
            break;
        }
        case 2://寺岗
        {
            Weight = sData.mid(3, 7);
            if(Weight.left(1) == " "||Weight.left(1) == "U" ||Weight.left(1) == "T")Weight = "";
            break;
        }
        case 3://迪宝
        {
            Weight = sData.left(7);
            break;
        }
        case 4://托利多
        {
            Weight = sData.left(7);
            break;
        }
    }

    if(Weight == ".")Weight = "";
    return Weight;

}

QString BalanceManage::getPosName()
{
    QString sHintText = "onlyPc";
    QString sPosName = KPosServerIni::getCurPosEBalanceName();
    if (sPosName == c_sOnlyPc)
    {
        if(testDll(c_sUANBalance, sHintText)){
            sPosName = c_sUANBalance;
            KPosServerIni::setCurPosEBalanceName(sPosName);
        }
        else if (testDll(c_sMettLerBalance, sHintText))
        {
            sPosName = c_sMettLerBalance;
            KPosServerIni::setCurPosEBalanceName(sPosName);
        }
        else if (testDll(c_sWinTecBalance, sHintText))
        {
            sPosName = c_sWinTecBalance;
            KPosServerIni::setCurPosEBalanceName(sPosName);
        }
    }

    return sPosName;
}

bool BalanceManage::isIntegratedScale()
{
    return KPosServerIni::getMachineType() == c_sIntegratedScale;
}

void BalanceManage::initConnect()
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(slot_timeOut()));
    connect(&m_stableTimer, SIGNAL(timeout()), this, SLOT(slot_stableTimeout()));
}

void BalanceManage::slot_timeOut()
{
    ////     模拟测试称发称重数据
    //    EBalanceStandard_Ex balanceStandard_Ex;
    //    balanceStandard_Ex.bStable = true; // 是否稳定
    //    balanceStandard_Ex.bInZero = false; // 是否在零位
    //    balanceStandard_Ex.bHaveTareWeight = false; // 是否有皮重
    //    static int i = 0;
    //    i++;
    //    i = i % 10;
    //    balanceStandard_Ex.sWeight = "1.25";//QString("1%1.111").arg(i); // 称重
    //    balanceStandard_Ex.sTareWeight = ""; // 皮重
    //    balanceStandard_Ex.bOverWeight = false; // 过载
    //    balanceStandard_Ex.bLessWeight = false; // 欠载
    //    emit sig_stableInfo(balanceStandard_Ex, true);

    m_timer.stop();
    EBalanceStandard_Ex balanceStandard_Ex;
    bool bWeighing = true;

    if (isIntegratedScale())//是一体pos机
    {
        if (m_sPosName == c_sMettLerBalance)
        {
            KPosAddDll::readBalanceStandard(balanceStandard_Ex);
        }
        else if (m_sPosName == c_sWinTecBalance)
        {
            KPosAdDll2::readBalanceStandard(balanceStandard_Ex);
        }
        else if (m_sPosName == c_sUANBalance)
        {
            KPosAddDllUAN::readBalanceStandard(balanceStandard_Ex);
        }
        else
        {
            bWeighing = false;
        }
    }
    else{//分散组装机
        int port = KPosServerIni::getPricingScalePort();//端口号
        QString portName =  QString("com%1").arg(port + 1);
        m_scaleVgaData->setPortName(portName);
        m_scaleVgaData->setBaudRate(9600);

        QString sData =  m_scaleVgaData->getScaleData();

        QString sWeight = AnalysisScaleWeight(sData);

        if(sWeight == ""){
            m_timer.start(m_nCheckTimeLen);
            return;
        }

        balanceStandard_Ex.bStable = true; // 是否稳定
        balanceStandard_Ex.bInZero = false; // 是否在零位
        balanceStandard_Ex.bHaveTareWeight = false; // 是否有皮重
        static int i = 0;
        i++;
        i = i % 10;
        balanceStandard_Ex.sWeight = sWeight; // 称重
        balanceStandard_Ex.sTareWeight = ""; // 皮重
        balanceStandard_Ex.bOverWeight = false; // 过载
        balanceStandard_Ex.bLessWeight = false; // 欠载

        KPosLog::instance()->writeErrorLog(QString("BalanceManage::slot_timeOut~~~~~~2333333333333333333333333 -- %1").arg(sWeight));

        emit sig_stableInfo(balanceStandard_Ex , true);
        m_timer.start(m_nCheckTimeLen);
        bWeighing = false;
    }


    if (bWeighing)
    {
        m_sWeight = balanceStandard_Ex.sWeight;
        m_stableTimer.start();
    }
}



void BalanceManage::slot_stableTimeout()
{
    m_stableTimer.stop();

    EBalanceStandard_Ex balanceStandard_Ex;
    if (m_sPosName == c_sMettLerBalance)
    {
        if (m_bAutoPeel)
        {
            KPosAddDll::autoRemovePeel();
            m_bAutoPeel = false;
        }
        KPosAddDll::readBalanceStandard(balanceStandard_Ex);
    }
    else if (m_sPosName == c_sWinTecBalance)
    {
        if (m_bAutoPeel)
        {
            KPosAdDll2::autoRemovePeel();
            m_bAutoPeel = false;
        }
        KPosAdDll2::readBalanceStandard(balanceStandard_Ex);
    }
    else if (m_sPosName == c_sUANBalance)
    {
        if (m_bAutoPeel)
        {
            KPosAddDllUAN::autoRemovePeel();
            m_bAutoPeel = false;
        }
        KPosAddDllUAN::readBalanceStandard(balanceStandard_Ex);
    }
    else
    {
        return;
    }

    bool bStable = ((m_sWeight == balanceStandard_Ex.sWeight) && balanceStandard_Ex.bStable);
    m_sWeight = balanceStandard_Ex.sWeight;

    if( balanceStandard_Ex.sWeight.toFloat() < 0 ) {
        balanceStandard_Ex.bLessWeight = true;
    } else {
        balanceStandard_Ex.bLessWeight = false;
    }

    emit sig_stableInfo(balanceStandard_Ex, bStable);

    if (bStable)
    {
        m_timer.start(m_nCheckTimeLen);
    }
    else
    {
        m_stableTimer.start(100);
    }
}
