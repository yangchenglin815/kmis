#ifndef KPOSADDDLLUAN_H
#define KPOSADDDLLUAN_H

#include <QLibrary>
#include "../data/ebalancedata.h"

class KPosAddDllUAN
{
public:
    KPosAddDllUAN();
    // 打印机
    static void printBitmapFile(QString sBitmapPath); // 打印位图
    static void cutPage(); // 打印完毕后切纸
    // 称重台
    static void readBalanceInfo(EBalanceInfo &banaceInfo); // 读取秤的信息
    static bool readBalanceStandard(EBalanceStandard_Ex &balanceStandard_Ex); // 读取秤的称量信息
    static void autoRemovePeel(); // 自动去皮
    static int openCashBox();//打开钱箱
    static bool testDll(QString& sHintText); // 测试

private:
    static int callPrintBitmapFile_stdcall(QString sBitmapPath);
    static int callBeginPrint_stdcall(int type = 0);
};

#endif // KPOSADDDLLUAN_H
