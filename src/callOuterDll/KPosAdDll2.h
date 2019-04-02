#ifndef KPOSADDLL2_H
#define KPOSADDLL2_H

#include <QString>
#include "../data/ebalancedata.h"

class KPosAdDll2
{
public:
    static void printBitmapFile(QString sBitmapPath); // 打印位图
    static void cutPage(); // 打印完毕后切纸
    static bool readBalanceStandard(EBalanceStandard_Ex &balanceStandard_Ex); // 读取称的称量信息
    static void autoRemovePeel(); // 自动去皮（设置当前秤台上的重物重量为皮重）
    static void clearTareWeight(); // 清空皮重(将皮重设置为0)
    static void clearZero(); // 秤台显示清零
    static void openCashBox();//打开钱箱
    static bool testDll(QString& sHintText); // 测试

private:
    // 313 , 363 ,373现在用的统一的一套dll, 373的端口在程序中是写死了，
    // 如果使用313和363，注意使用文档中要求的端口和波特率对下列变量赋值
    static int m_nPrintPort;
    static int m_nPrintBaud;
    static int m_nWeighPort;
    static int m_nWeighBaud;
};

#endif // KPOSADDLL2_H
