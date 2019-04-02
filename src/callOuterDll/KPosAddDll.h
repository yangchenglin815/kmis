#ifndef KPOSADDDLL_H
#define KPOSADDDLL_H

#include <QLibrary>
#include "../data/ebalancedata.h"

class KPosAddDll
{
public:
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
    /**
     * @brief callPrintBitmapFile_stdcall
     * @param sBitmapPath
     */
    static int callPrintBitmapFile_stdcall(QString sBitmapPath);

    /**
     * @brief callBeginPrint_stdcall
     * @param type
     *  0： iSmartP/iSmartS/UC-HTT-M/Fresh 调用 PrintOnce.exe 打印收据
        10： Fresh 调用 PrintOnce.exe 打印收据,打印后自动切纸
        1： iSmartP/iSmartS/UC-HTT-M 调用 InvoicePrintOnce.exe 打印圈式发票（内容根据头部空白行
        （点）数、最多打印数据行（点）数两个参数自动分页）
        2： iSmartP/iSmartS/UC-HTT-M 调用 LabelPrintOnce.exe 打印标签， Print.tmp 为点阵数据
        3： UC-HTT-V 调用 LPTPrintOnce.exe 打印收据
        4：走纸
        5：打印测试标签
        6：取打印机程序版本信息
        7：以收据模式打印位图（ Evo、 E+ 位图在调用此命令前需先调用 PrintBitmapFile 格式化图片文
        件)
        注： 对于 FreshwayT，此命令不起任何作用。
        8：切纸 （仅 Fresh 支持，其它型号调用不起任何作用）
        9： Fresh 打印 MT 指定格式的点阵数据文件 c:\iSmartSystem\print.tmp
        80,81,82,83,90,91,92,93：测纸
        测标签: 80、 90
        测收据： 81、 91
        测无基纸的连续标签： 82、 92
        测黑标的发票： 83、 93
        80--83 正常测纸
        90--93 在测纸前会重启 USB 打印机
     * @return
     */
    static int callBeginPrint_stdcall(int type = 0);
};

#endif // KPOSADDDLL_H
