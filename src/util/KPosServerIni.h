#ifndef KPOSSERVERINI_H
#define KPOSSERVERINI_H

#include <QString>

class KPosServerIni
{
public:
    static QString getServerIp();
    static void setServerIp(QString strServerIp);
    static QString getCurPosEBalanceName(); // 获取电子秤名称
    static void setCurPosEBalanceName(QString name); // 设置电子秤名称
    static bool isUseMTComAPIDll(); // 是否要用MTCom称重机
    void setUseMTComAPIDllFlag(bool bHave); // 是否要用MTCom称重机
    static QString getReceiveRankChartsUrl();
    static QString getReceiveSummaryChartsUrl();
    static bool isOnlyCashRefund();
    static int getReceiptHeight(); // 小票高度
    static int getReceiptZoomWidth(); // 获取小票的打印缩放宽度
    static int getReceiptRealWidth(); // 获取小票的实际高度
    static int getSequenceMod();//获取流水号模式
    static void setSequenceMod(int nModId);//设置流水号模式
    static int getKPosUserType(); // KPos用户类型
    static void setMachineType(int type);//设置主机类型
    static int getMachineType();//获取主机类型
    static void setPricingScaleType(int type);//设置计价秤型号
    static int getPricingScaleType();//获取计价秤型号
    static void setPricingScalePort(int type);//设置计价秤端口号
    static int getPricingScalePort();//获取计价端口号
};

#endif // KPOSSERVERINI_H
