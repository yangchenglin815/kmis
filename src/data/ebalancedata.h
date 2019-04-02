#ifndef EBALANCEDATA_H
#define EBALANCEDATA_H

#include <QString>

// 电子秤信息
struct EBalanceInfo
{
    long maxRange[3]; //最大秤量
    long minRange; //最小秤量
    long maxTare; //最大皮重
    long maxPreTare; //最大预置皮重
    long resolution[3]; //分度
    char weightUnit[4]; //重量单位
    char moneyUnit[4]; //货币单位
    char systemVersion[20]; //数传版本
};

// 电子秤dll称重结构
struct EBalanceStandard
{
    char status;//status 的 bit0(第一位)表示是否稳定; bit1(第二位)表示是否在零位; bit2(第三位)表示是否有皮重
    char net_weight[7]; //注： 如净重<=-10.000 时，小数点后取 3 位，其它时候为 4 位。 如 9.9980， -10.124
    char FixSeparator;//固定为"P"
    char tare_weight[7];
};

// 电子秤称重结构
struct EBalanceStandard_Ex
{
    bool bStable; // 是否稳定
    bool bInZero; // 是否在零位
    bool bHaveTareWeight; // 是否有皮重
    QString sWeight; // 称重
    QString sTareWeight; // 皮重
    bool bOverWeight; // 过载
    bool bLessWeight; // 欠载
};

// 收货称重秤dll结构
struct MT_Continuous_Data
{
    char gross[12]; // 毛重 = 皮重 + 净重
    char tare[12]; // 皮重
    char net[12]; // 净重
    char unit; // 重量单位
    char overload; // ‘1’: overload 过载
    char underload; // ‘1’: underload 欠载
    char motion; // ‘1’: motion  晃动
    char GorN; // ‘1’: net,’0’:gross  // 是否有皮重
    char X10; // ‘1’: X10   // 精度
    char PowerupZeroCapture; // ‘1’: PowerupZeroCapture fail(positive)  开机清零 正重量
    char NegativePowerupZeroCapture; // ‘1’:PowerupZeroCapture fail (negative) 开机清零  负重量
};


#endif // EBALANCEDATA_H
