#include "MTComAPIDll.h"
#include <QMessageBox>
#include <QLibrary>
#include "TipsDlg.h"
HANDLE MTComAPIDll::m_handle;

void MTComAPIDll::openMTCom()
{
    QLibrary lib("MTComAPI.dll");
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库MTComAPI.dll加载失败"));
        return;
    }

    // 打开串口→读取重量 -发送命令→关闭串口
//    HANDLE __stdcall OpenComPort(int nPort, int nBaud,int nData,int nParity,int nStop)
//    输入参数：nPort 需要打开的串口号，整型，取值 1~n
//     nBaud 波特率，整型，取值 1200~115200
//     nData 数据位，整型，取值 8/7
//     nParity 校验位，整型，取值 0/1/2 对应 None,Odd,Even
//     nStop 停止位，整型，取值 0/1/2 对应 1, 1.5, 2
//    输出参数：无
//    返回值：成功，返回串口句柄；失败，返回 INVALID_HANDLE_VALUE
    typedef HANDLE (*OpenComPort)(int nPort, int nBaud, int nData, int nParity, int nStop);
    OpenComPort openComPort = (OpenComPort)lib.resolve("OpenComPort");
    m_handle = openComPort(5, 9600, 8, 0, 0);
}

void MTComAPIDll::closeMTCom()
{
    QLibrary lib("MTComAPI.dll");
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库MTComAPI.dll加载失败"));
        return;
    }
    //    形式：int __stdcall CloseComPort(HANDLE ComPortHandle)
    //    输入参数：ComPortHandle 串口句柄
    //    输出参数：无
    //    返回值：0 成功；非 0，失败（通常是串口句柄无效）
    typedef int (*CloseComPort)(HANDLE ComPortHandle);
    CloseComPort closeComPort = (CloseComPort)lib.resolve("CloseComPort");
    closeComPort(m_handle);
}

void MTComAPIDll::readWeight(EBalanceStandard_Ex &balanceStandard_Ex)
{
    QLibrary lib("MTComAPI.dll");
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库MTComAPI.dll加载失败"));
        return;
    }
//    int __stdcall ReadParseComMTConOut(HANDLE Comfd, MT_Continuous_Data *continuousData)
//            输入参数：Comfd 串口句柄
//            输出参数：continuousData MT_Continuous_Data 结构形式的毛、皮、净重量 值、单位及状态。
    typedef int (*ReadParseComMTConOut)(HANDLE Comfd, MT_Continuous_Data *continuousData);
    ReadParseComMTConOut readParseComMTConOut = (ReadParseComMTConOut)lib.resolve("ReadParseComMTConOut");

    MT_Continuous_Data readData;
    memset(&readData,0,sizeof(MT_Continuous_Data));
    int a = readParseComMTConOut(m_handle, &readData);
    if (a == 0)
    {
        balanceStandard_Ex.bStable = (readData.motion == '0');//balanceStandard.status & 1; // 是否稳定
        balanceStandard_Ex.bInZero = (readData.PowerupZeroCapture == '0') && (readData.NegativePowerupZeroCapture == '0');
        balanceStandard_Ex.bHaveTareWeight = (readData.GorN == '1');//= balanceStandard.status & 4; // 是否有皮重
        balanceStandard_Ex.sWeight = readData.net;
        balanceStandard_Ex.sTareWeight = readData.tare;
        balanceStandard_Ex.bLessWeight = (readData.underload == '1');
        balanceStandard_Ex.bOverWeight = (readData.overload == '1');
    }
    else
    {
        balanceStandard_Ex.bStable = false; // 是否稳定
        balanceStandard_Ex.bInZero = true; // 是否在零位
        balanceStandard_Ex.bHaveTareWeight = false; // 是否有皮重
        balanceStandard_Ex.sWeight = "00.0000";
        balanceStandard_Ex.sTareWeight = "00.0000";
        balanceStandard_Ex.bLessWeight = false;
        balanceStandard_Ex.bOverWeight = false;
    }
}

bool MTComAPIDll::isOpen()
{
    return ((int)m_handle > 0);
}

