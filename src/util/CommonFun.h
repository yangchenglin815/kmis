#ifndef COMMONFUN_H
#define COMMONFUN_H

#include <QString>
#include <QStringList>

class CommonFun
{
public:
    static QString getCurDateTime();
    static QString getFormatDate(int nYear, int nMonth, int nDay, QString sFormat = "-"); // 获取格式化日期
    static void adjustDateTime(QString sDateTime);
    static QString trunkDateTime(QString sDateTime);
    static QString getHttpParamSign(QStringList paramList);
    static QString generateSystemParams(QString sAction);
    static QString getRealInStr(QString text);//获取字段中的数字部分
    static QString getUUID();
    static QString getAppName();
    static QString getAppVersion();
    static QString getOsVersion();
//    static bool isWindow64();
    static QString getBranchName();
    static int getKPosRuningNum();
    static bool killKPos();
    //2位小数点处理
    static QString floatToString( float fValue );
    static float StringToFloat( QString strValue );
    static QString floatToString3(float fValue);
    static QString handleCash(float fCash, int nType); // 现金的处理方式,保留到角
    static QString handleCash(float fCash); // 现金的处理方式，保留到角
    static QString handleMoneyCoin(float fMoney, int nType); // 保留金钱到分位
    static QString handleMoneyCoin(float fMoney); // 保留金钱到分位
    static QString handleMoney(float fMoney, int nPos, int nType); // nPos保留位数
    static QString httpNullToString( QString strHttpInfo ); 
    static int getWeekDay(int nYear, int nMonth, int nDay); // 获取指定的某一天是周几(适用于 1900 - 2099年)
    static bool isLeapYear(int nYear);
    static int getMonthDay(int nYear, int nMonth);

    static QString getStringMd5(QString str);
    static bool pingScale(QString ip);
private:
    static QString getPosMacAddress();
    static int getProcessNum(QString sProcessName);
    static bool killProcess(QString sProcessName);
};

#endif // COMMONFUN_H
