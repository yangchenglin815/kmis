#include "CommonFun.h"
#include <QDateTime>
#include <QByteArray>
#include <QCryptographicHash>
#include <QNetworkInterface>
#include <QSettings>
#include <QProcess>
#include "../data/constData.h"
#include "../data/enumData.h"
#include "KPosLog.h"
#include <QDebug>
#include <QRegExp>
#include "windows.h"
#include "globaldata.h"

QString CommonFun::getCurDateTime()
{
    return QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
}

QString CommonFun::getFormatDate(int nYear, int nMonth, int nDay, QString sFormat)
{
    QString sMonth;
    if (nMonth < 10)
    {
        sMonth =  QString("0%1").arg(nMonth);
    }
    else
    {
        sMonth =  QString("%1").arg(nMonth);
    }

    QString sDay;
    if (nDay < 10)
    {
        sDay = QString("0%1").arg(nDay);
    }
    else
    {
        sDay = QString("%1").arg(nDay);
    }


    return QString("%1%2%3%4%5").arg(nYear).arg(sFormat).arg(sMonth).arg(sFormat).arg(sDay);
}

void CommonFun::adjustDateTime(QString sDateTime)
{
    if (sDateTime.isEmpty())
    {
        return;
    }
    QDateTime dateTime = QDateTime::fromString(sDateTime, "yyyy-MM-dd HH:mm:ss");
    if (!dateTime.isValid())
    {
        return;
    }
    QDateTime curDateTime = QDateTime::currentDateTime();
    int nDifferTime = dateTime.secsTo(curDateTime);
    if (nDifferTime > 60 || -nDifferTime > 60) // 如果日期不相等，矫正机器时间
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("本地时间：%1,服务器时间：%2")
                                           .arg(curDateTime.toString("yyyy-MM-dd HH:mm:ss")).arg(sDateTime));
        SYSTEMTIME   st;
        GetLocalTime(&st);
        st.wYear=dateTime.date().year();
        st.wMonth=dateTime.date().month();
        st.wDay=dateTime.date().day();
        st.wHour = dateTime.time().hour() - 8;
        st.wMinute = dateTime.time().minute();
        st.wSecond = dateTime.time().second();
        SetSystemTime(&st);    //Win32 API 设置系统时间
    }
}

QString CommonFun::trunkDateTime(QString sDateTime)
{
    QDateTime dateTime = QDateTime::fromString(sDateTime, "yyyy-MM-dd HH:mm:ss");
    return dateTime.toString("MM-dd HH:mm");
}

QString CommonFun::getHttpParamSign(QStringList paramList)
{
    paramList.sort();
    int nLen = paramList.length();
    QString sParams;
    for (int i = 0; i < nLen; i++)
    {
        sParams.append(paramList[i].replace("=",""));
    }

    QString appSecretParam = QString("app_secret").append(g_sHttpAPP_Secret);

    QString sMd5 = getStringMd5(appSecretParam.append(sParams));
//    KPosLog::instance()->writeErrorLog(appSecretParam);
    return sMd5.toUpper();
}

//系统参数
QString CommonFun::generateSystemParams(QString sAction)
{
    return QString("app_key=%1&action=%2&timestamp=%3&version=%4").arg(g_sHttpAPP_Key)
            .arg(sAction).arg(CommonFun::getCurDateTime()).arg(c_sHttpServerVersion);
}

QString CommonFun::getRealInStr(QString text)
{
    QRegExp rx("(\\d+)|(\\d*\\.\\d+)");//整数与浮点数匹配
    int pos = 0;
      while ((pos = rx.indexIn(text, pos)) != -1) {
          text.remove(pos,rx.matchedLength());
          pos += rx.matchedLength();
      }
      return text;
}

QString CommonFun::getUUID()
{
    return getStringMd5(getPosMacAddress());
}

QString CommonFun::getAppName()
{
    return c_sAppName;
}

QString CommonFun::getAppVersion()
{
    QSettings settings("./readme.ini", QSettings::IniFormat);
    return settings.value("Readme/AppVersion", "255.255.255.255").toString();
}

QString CommonFun::getOsVersion()
{
    return QString::number(QSysInfo::WindowsVersion);
}

//bool CommonFun::isWindow64()
//{
//    static bool bHasGet = false;
//    bool bIsWin64 = false;
//    if (!bHasGet)
//    {
//#ifdef Q_OS_WIN
//        OSVERSIONINFOEX osvi;
//        SYSTEM_INFO si;
//        ZeroMemory(&si, sizeof(SYSTEM_INFO));
//        ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
//        osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

//        GetVersionEx((OSVERSIONINFO*)&osvi);
//        typedef void (WINAPI *PGNSI)(LPSYSTEM_INFO);
//        PGNSI pGNSI;
//        pGNSI = (PGNSI) GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetNativeSystemInfo");
//        if(NULL != pGNSI)
//        {
//            pGNSI(&si);
//        }
//        else
//        {
//            GetSystemInfo(&si);
//        }

//        if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
//        {
//            bIsWin64 = true;
//        }
////        else if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
////        {
////            bIsWin64 = false;
////        }
//#endif
//    }
//    bHasGet = true;
//    return bIsWin64;
//}

QString CommonFun::getBranchName()
{
    return "";
}

int CommonFun::getKPosRuningNum()
{
    QString sProcessName = c_sAppName + ".exe";
    return getProcessNum(sProcessName);
}

bool CommonFun::killKPos()
{
    QString sProcessName = c_sAppName + ".exe";
    return killProcess(sProcessName);
}

QString CommonFun::floatToString( float fValue )
{
    return handleMoney(fValue, 2, eRounding);
//    QStringList strList = str.split(".");
//    if (strList.size() <= 1 )
//    {
//        return str;
//    }

//    QString sStr1 = strList[0];
//    QString sStr2 = strList[1].left(2);
//    return sStr1.append(".").append(sStr2);

//    QString strValue = "";
//    strValue.sprintf( "%.2f", fValue );
//    return strValue;
}

//小数位为2位的处理
float CommonFun::StringToFloat( QString strValue )
{
//    float fValue = strValue.toFloat() + 0.000000001;
//    return fValue;
    return strValue.toFloat();
}

QString CommonFun::floatToString3(float fValue)
{
    return handleMoney(fValue, 3, eRounding);
//    QStringList strList = str.split(".");
//    if (strList.size() <= 1 )
//    {
//        return str;
//    }

//    QString sStr1 = strList[0];
//    QString sStr2 = strList[1].left(3);
//    return sStr1.append(".").append(sStr2);
}

QString CommonFun::handleCash(float fCash, int nType)
{
    return handleMoney(fCash, 1, nType);
//    if (nType == eRounding)
//    {
//        return QString::number(fCash + 0.000001f, 'f', 1);
//    }
//    else if (nType == eAbandon)
//    {
//        return QString::number(fCash - 0.040009f, 'f', 1);
//    }
//    else if (nType == eCarry)
//    {
//        return QString::number(fCash + 0.040009f, 'f', 1);
//    }
//    else
//    {
//        return QString::number(fCash + 0.000001f, 'f', 1);
//    }
}

QString CommonFun::handleCash(float fCash)
{
    return handleCash(fCash, g_cashHandleType);
}

QString CommonFun::handleMoneyCoin(float fMoney, int nType)
{
    return handleMoney(fMoney, 2, nType);
//    if (nType == eRounding)
//    {
//        return QString::number(fMoney + 0.000001f, 'f', 2);
//    }
//    else if (nType == eAbandon)
//    {
//        return QString::number(fMoney - 0.004009f, 'f', 2);
//    }
//    else if (nType == eCarry)
//    {
//        return QString::number(fMoney + 0.004009f, 'f', 2);
//    }
//    else
//    {
//        return QString::number(fMoney + 0.000001f, 'f', 2);
//    }
}

QString CommonFun::handleMoneyCoin(float fMoney)
{
    return handleMoneyCoin(fMoney, g_cashHandleType);
}

QString CommonFun::handleMoney(float fMoney, int nPos, int nType)
{
//    QString str = QString::number(fMoney);
//    QStringList strList = str.split(".");
//    if (strList.size() <= 1 )
//    {
//        return str;
//    }

//    QString sStr1 = strList[0];
//    QString sStr2 = strList[1];
//    QString sSaveStr = str.left(sStr1.length() + 1 + nPos);
//    if (nType == eRounding)
//    {
//        if (sStr2.length() >= nPos+1)
//        {
//            int nRoundStr = sStr2.mid(nPos, 1).toInt();
//            if (nRoundStr >= 5)
//            {
//                float fBase = ((fMoney>0)?1:-1);
//                if (nPos == 1)
//                {
//                   fBase *= 0.1f;
//                }
//                else if (nPos == 2)
//                {
//                    fBase *= 0.01f;
//                }
//                else if (nPos == 3)
//                {
//                    fBase *= 0.001f;
//                }
//                sSaveStr = QString::number(sSaveStr.toFloat() + fBase);
//            }
//        }
//    }
//    else if (nType == eAbandon)
//    {
//        //
//    }
//    else if (nType == eCarry)
//    {
//        if (sStr2.length() >= nPos + 1)
//        {
//            float fBase = ((fMoney>0)?1:-1);
//            if (nPos == 1)
//            {
//               fBase *= 0.1f;
//            }
//            else if (nPos == 2)
//            {
//                fBase *= 0.01f;
//            }
//            else if (nPos == 3)
//            {
//                fBase *= 0.001f;
//            }
//            sSaveStr = QString::number(sSaveStr.toFloat() + fBase);
//        }
//    }

//    return sSaveStr;

    int nBase = 1;
    for (int i = 0; i < nPos; i++)
    {
        nBase *= 10;
    }

    float f = 4.45f;
    if (nType == eRounding)
    {
        f = (int)(fMoney*nBase+0.501*((fMoney>0)?1:-1))*1.0/nBase;
    }
    else if (nType == eAbandon)
    {
        f = (int)(fMoney*nBase+0.001*((fMoney>0)?1:-1))*1.0/nBase;
    }
    else if (nType == eCarry)
    {
        f = (int)(fMoney*nBase+0.901*((fMoney>0)?1:-1))*1.0/nBase;
    }

    return QString::number(f);
}

QString CommonFun::httpNullToString( QString strHttpInfo )
{
    if( strHttpInfo == "null" ) {
        strHttpInfo = "";
    }

    return strHttpInfo;
}

int CommonFun::getWeekDay(int nYear, int nMonth, int nDay)
{
    // 年份
    int nYearFlag = 0;
    int nDisYear = nYear - 2000;
    if (nDisYear >= 0)
    {
        nYearFlag = (nDisYear/4 + nDisYear) % 7;
    }
    else
    {
        nYearFlag = (nDisYear/4 + nDisYear) % 7 + 1;
    }

    // 月份
    int nMothFlag = 0;
    bool bLeapYear = isLeapYear(nYear);
    switch (nMonth) {
    case 5:
        nMothFlag = 0;
        break;
    case 8:
        nMothFlag = 1;
        break;
    case 2:
        nMothFlag = 2 - (bLeapYear?1:0);
        break;
    case 3:
    case 11:
        nMothFlag = 2;
        break;
    case 6:
        nMothFlag = 3;
        break;
    case 9:
    case 12:
        nMothFlag = 4;
        break;
    case 4:
    case 7:
        nMothFlag = 5;
        break;
    case 1:
        nMothFlag = 6 - (bLeapYear?1:0);
        break;
    case 10:
        nMothFlag = 6;
        break;
    }

    return (nYearFlag + nMothFlag + nDay)%7;
}

bool CommonFun::isLeapYear(int nYear)
{
    if(((nYear%4==0) && (nYear%100!=0))
            ||(nYear%400==0))
    {
        return true;
    }
    return false;
}

int CommonFun::getMonthDay(int nYear, int nMonth)
{
    switch (nMonth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    }

    if (isLeapYear(nYear))
    {
        return 29;
    }
    return 28;
}

QString CommonFun::getStringMd5(QString str)
{
    QByteArray bb = QCryptographicHash::hash(str.toUtf8(), QCryptographicHash::Md5);
    return bb.toHex();
}

//获取pos的mac地址
QString CommonFun::getPosMacAddress()
{
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    for (int i = 0; i < list.length(); i++)
    {
        if (list[i].humanReadableName().contains(QStringLiteral("本地连接")))
        {
            return list[i].hardwareAddress();
        }
    }
    return "";
}

int CommonFun::getProcessNum(QString sProcessName)
{
    QStringList strList;
    strList.append("-NH");
    strList.append("-FI");
    strList.append(QString("imagename eq %1").arg(sProcessName));
    QProcess process;
    process.start("tasklist", strList);
    process.waitForFinished();
    QString msg = process.readAllStandardOutput();
    QList<QString> list = msg.split("\r\n");
    int nNum = 0;
    int nLen = list.length();
    for (int i = 0; i < nLen; i++)
    {
        if (list[i].contains(QString("%1").arg(sProcessName)))
        {
            nNum++;
        }
    }
    return nNum;
}

bool CommonFun::killProcess(QString sProcessName)
{
    QStringList strList;
    strList.append("-f");
    strList.append("-t");
    strList.append("-im");
    strList.append(QString("%1").arg(sProcessName));
    QProcess process;
    process.start("taskkill", strList);
    process.waitForFinished();
    int nExitCode = process.exitCode();
    if (nExitCode == QProcess::NormalExit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//判断秤网络是否连通
bool CommonFun::pingScale(QString ip)
{
    QProcess pingProcess;
    QString exec = "ping";
    QStringList params;
    params << "-n" << "1" << "-w" << "1000" <<ip;
    pingProcess.start(exec, params, QIODevice::ReadOnly);
    pingProcess.waitForFinished(-1);
    QByteArray p_stdout = pingProcess.readAllStandardOutput();

    QString qstr=QString::fromLocal8Bit(p_stdout);
    qDebug()<<qstr;
    if(qstr.contains("往返行程的估计时间",Qt::CaseSensitive))
    {
        return true;
    }
    else if(qstr.contains("Approximate round trip times in",Qt::CaseSensitive))
    {
        return true;
    }
    else if(qstr.contains("无法访问目标主机",Qt::CaseSensitive))
    {
        return false;
    }
    else if(qstr.contains("请求超时",Qt::CaseSensitive))
    {
        return false;
    }
    else
    {
        return false;
    }
}

