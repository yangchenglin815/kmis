#include "KPosServerIni.h"
#include <QSettings>
#include "../data/constData.h"

QString sKPosServerPath = "KPosServer.ini";

QString KPosServerIni::getServerIp()
{
    QSettings settings( sKPosServerPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    QString sHttpHostIP = settings.value("ServerInfo/serverIp"/*, "http://121.43.63.111:8000/"*/).toString();
    if (sHttpHostIP.isEmpty())
    {
        return c_sHttpHostIP;
    }
    else
    {
        return sHttpHostIP;
    }
}

void KPosServerIni::setServerIp( QString strServerIp )
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue("ServerInfo/serverIp", strServerIp );
}

QString KPosServerIni::getCurPosEBalanceName()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    return settings.value("CurEBalanceInfo/name", c_sOnlyPc).toString();  //"METTLER" WINTEC
}

void KPosServerIni::setCurPosEBalanceName(QString name)
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    settings.setValue("CurEBalanceInfo/name", name);
}

bool KPosServerIni::isUseMTComAPIDll()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    QString str = settings.value("MTComAPIDll/isUse", "0").toString();  //"METTLER" WINTEC
    if (str == "0")
    {
        return false;
    }
    else
    {
        return true;
    }
}

void KPosServerIni::setUseMTComAPIDllFlag(bool bHave)
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    settings.setValue("MTComAPIDll/isUse", bHave?1:0);
}

QString KPosServerIni::getReceiveRankChartsUrl()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    return settings.value("ReportCharts/rankCharts", "").toString();
}

QString KPosServerIni::getReceiveSummaryChartsUrl()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    return settings.value("ReportCharts/summaryCharts", "").toString();
}

bool KPosServerIni::isOnlyCashRefund()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    return settings.value("Refund/onlyCash", true).toBool();
}

int KPosServerIni::getReceiptHeight()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    int nHeight = settings.value("Receipt/height", 2000).toInt();
    if (nHeight < 1000)
    {
        nHeight = 2000;
    }
    return nHeight;
}

int KPosServerIni::getReceiptZoomWidth()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    int nZoomWidth = settings.value("Receipt/zoomWidth", 450).toInt();
    if (nZoomWidth < 100)
    {
        nZoomWidth = 450;
    }
    return nZoomWidth;
}

int KPosServerIni::getReceiptRealWidth()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    int nRealWidth = settings.value("Receipt/realWidth", 174).toInt();
    if (nRealWidth < 100)
    {
        nRealWidth = 174;
    }
    return nRealWidth;
}

int KPosServerIni::getSequenceMod()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    return settings.value("Sequence/sequenceMod", "0").toInt();
}

void KPosServerIni::setSequenceMod(int nModId)
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    settings.setValue("Sequence/sequenceMod", nModId);
}

int KPosServerIni::getKPosUserType()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    return settings.value("KPosUser/type", 0).toInt();
}

void KPosServerIni::setMachineType(int type)
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    settings.setValue("DeviceData/machineType", type);
}

int KPosServerIni::getMachineType()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    return settings.value("DeviceData/machineType", "").toInt();
}

void KPosServerIni::setPricingScaleType(int type)
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    settings.setValue("DeviceData/PricingScaleType", type);
}

int KPosServerIni::getPricingScaleType()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    return settings.value("DeviceData/PricingScaleType", "").toInt();
}

void KPosServerIni::setPricingScalePort(int type)
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    settings.setValue("DeviceData/PricingScalePort", type);
}

int KPosServerIni::getPricingScalePort()
{
    QSettings settings(sKPosServerPath, QSettings::IniFormat);
    return settings.value("DeviceData/PricingScalePort", "").toInt();
}
