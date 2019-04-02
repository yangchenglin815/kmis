#include "KPosAdDll2.h"

#include <QLibrary>
#include <QMessageBox>
#include "TipsDlg.h"

int KPosAdDll2::m_nPrintPort = 5;
int KPosAdDll2::m_nPrintBaud = 38400;
int KPosAdDll2::m_nWeighPort = 2;
int KPosAdDll2::m_nWeighBaud = 9600;

#define HS_OK 240

// 原名是pos_ad_dll.dll，由于库命名冲突，所以改名了，改名如下
static const QString c_sKPosAdDll2Path = "pos_ad_dllWinTec.dll";

void KPosAdDll2::printBitmapFile(QString sBitmapPath)
{
    QLibrary lib(c_sKPosAdDll2Path);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_dllWinTec.dll加载失败"));
        return;
    }

    // 打开 AD 板串口。
    typedef bool (*OpenADCom)(int port, int baud);
    OpenADCom openADCom = (OpenADCom)lib.resolve("OpenADCom");
    bool bOpenSuccess = openADCom(m_nPrintPort, m_nPrintBaud);
    if (!bOpenSuccess)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("打印机端口打开失败"));
        return;
    }

    // 打印单色位图图片
    typedef int (*PrintBitmapFile)(char* BmpFileName, int LabelAngle);
    PrintBitmapFile printBitmapFile = (PrintBitmapFile)lib.resolve("PrintBitmapFile");
    int nResult = printBitmapFile(const_cast<char*>(sBitmapPath.toStdString().c_str()), 1); // 图片打印位置：0,1,2 （居左，居中，居右）。
    if (nResult != HS_OK)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("打印失败, 错误码: %1").arg(nResult));
        return;
    }

    typedef void (*CloseADCom)();
    CloseADCom closeADCom = (CloseADCom)lib.resolve("CloseADCom");
    closeADCom();
}

void KPosAdDll2::cutPage()
{
    QLibrary lib(c_sKPosAdDll2Path);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_dllWinTec.dll加载失败"));
        return;
    }

    // 打开 AD 板串口。
    typedef bool (*OpenADCom)(int port, int baud);
    OpenADCom openADCom = (OpenADCom)lib.resolve("OpenADCom");
    bool bOpenSuccess = openADCom(m_nPrintPort, m_nPrintBaud);
    if (!bOpenSuccess)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("打印机端口打开失败"));
        return;
    }

    typedef int (*CutPaper)(int i);
    CutPaper cutPaper = (CutPaper)lib.resolve("CutPaper");
    cutPaper(0);

    typedef void (*CloseADCom)();
    CloseADCom closeADCom = (CloseADCom)lib.resolve("CloseADCom");
    closeADCom();
}

bool KPosAdDll2::readBalanceStandard(EBalanceStandard_Ex &balanceStandard_Ex)
{
    QLibrary lib(c_sKPosAdDll2Path);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_dllWinTec.dll加载失败"));
        return false;
    }

    // 打开 AD 板串口。
    typedef bool (*OpenADCom)(int port, int baud);
    OpenADCom openADCom = (OpenADCom)lib.resolve("OpenADCom");
    bool bOpenSuccess = openADCom(m_nWeighPort, m_nWeighBaud);
    if (!bOpenSuccess)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("称重端口打开失败"));
        return false;
    }

    typedef int (*read_standard)(char *buf);
    read_standard readStandard = (read_standard)lib.resolve("read_standard");

    EBalanceStandard balanceStandard;
    balanceStandard_Ex.bOverWeight = false;
    balanceStandard_Ex.bLessWeight = false;

    int a = readStandard((char*)&balanceStandard);
    if (a == HS_OK /*&& (balanceStandard.status & 1)*/)
    {
        balanceStandard_Ex.bStable = balanceStandard.status & 1; // 是否稳定
        balanceStandard_Ex.bInZero = balanceStandard.status & 2; // 是否在零位
        balanceStandard_Ex.bHaveTareWeight = balanceStandard.status & 4; // 是否有皮重
        char buf[10] = "";
        int i = 0;
        while (balanceStandard.net_weight[i] != 'P' && i < 10)
        {
            buf[i] = balanceStandard.net_weight[i];
            i++;
        }
        balanceStandard_Ex.sWeight = buf;
        balanceStandard_Ex.sTareWeight = balanceStandard.tare_weight;
        balanceStandard_Ex.bLessWeight = false;
        balanceStandard_Ex.bOverWeight = false;
    }
    else
    {
        balanceStandard_Ex.bStable = false; // 是否稳定
        balanceStandard_Ex.bInZero = true; // 是否在零位
        balanceStandard_Ex.bHaveTareWeight = false; // 是否有皮重
        balanceStandard_Ex.sWeight = "00.000";
        balanceStandard_Ex.sTareWeight = "00.000";

        // -1 欠载 -2 过载
        if (a == -1)
        {
            balanceStandard_Ex.sTareWeight = "-99.999";
            balanceStandard_Ex.bLessWeight = true;
        }
        else if (a == -2)
        {
            balanceStandard_Ex.bOverWeight = true;
        }
    }

    //  关闭 AD 板串口。
    typedef void (*CloseADCom)();
    CloseADCom closeADCom = (CloseADCom)lib.resolve("CloseADCom");
    closeADCom();

    return true;
}

void KPosAdDll2::autoRemovePeel()
{
    QLibrary lib(c_sKPosAdDll2Path);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_dllWinTec.dll加载失败"));
        return;
    }

    typedef bool (*OpenADCom)(int port, int baud);
    OpenADCom openADCom = (OpenADCom)lib.resolve("OpenADCom");
    bool bOpenSuccess = openADCom(m_nWeighPort, m_nWeighBaud);
    if (!bOpenSuccess)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("称重端口打开失败"));
        return;
    }

    // 设置皮重为0
    typedef int (*send_pre_tare)(char *buf);
    send_pre_tare sendPreTare = (send_pre_tare)lib.resolve("send_pre_tare");
    char preTareWeight[12] = "0";
    sendPreTare(preTareWeight);

    // 自动去皮
    typedef int (*send_tare)(char *buf);
    send_tare sendTare = (send_tare)lib.resolve("send_tare");
    char tareWeight[12] = "0.0";
    sendTare(tareWeight);

    // 秤台清零
    typedef int (*send_zero)(void);
    send_zero sendZero = (send_zero)lib.resolve("send_zero");
    sendZero();

    typedef void (*CloseADCom)();
    CloseADCom closeADCom = (CloseADCom)lib.resolve("CloseADCom");
    closeADCom();
}

void KPosAdDll2::clearTareWeight()
{
    QLibrary lib(c_sKPosAdDll2Path);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_dllWinTec.dll加载失败"));
        return;
    }

    typedef bool (*OpenADCom)(int port, int baud);
    OpenADCom openADCom = (OpenADCom)lib.resolve("OpenADCom");
    bool bOpenSuccess = openADCom(m_nWeighPort, m_nWeighBaud);
    if (!bOpenSuccess)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("称重端口打开失败"));
        return;
    }

    // 设置皮重
    typedef int (*send_pre_tare)(char *buf);
    send_pre_tare sendPreTare = (send_pre_tare)lib.resolve("send_pre_tare");
    char preTareWeight[12] = "0";
    sendPreTare(preTareWeight);

    typedef void (*CloseADCom)();
    CloseADCom closeADCom = (CloseADCom)lib.resolve("CloseADCom");
    closeADCom();
}

void KPosAdDll2::clearZero()
{
    QLibrary lib(c_sKPosAdDll2Path);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_dllWinTec.dll加载失败"));
        return;
    }

    typedef bool (*OpenADCom)(int port, int baud);
    OpenADCom openADCom = (OpenADCom)lib.resolve("OpenADCom");
    bool bOpenSuccess = openADCom(m_nWeighPort, m_nWeighBaud);
    if (!bOpenSuccess)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("称重端口打开失败"));
        return;
    }

    // 秤台清零
    typedef int (*send_zero)(void);
    send_zero sendZero = (send_zero)lib.resolve("send_zero");
    sendZero();

    typedef void (*CloseADCom)();
    CloseADCom closeADCom = (CloseADCom)lib.resolve("CloseADCom");
    closeADCom();
}

//打开钱箱
void KPosAdDll2::openCashBox()
{
    QLibrary lib( c_sKPosAdDll2Path );
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_dllWinTec.dll加载失败"));
        return;
    }

    // 打开 AD 板串口。
    typedef bool (*OpenADCom)(int port, int baud);
    OpenADCom openADCom = (OpenADCom)lib.resolve("OpenADCom");
    bool bOpenSuccess = openADCom(m_nPrintPort, m_nPrintBaud);
    if (!bOpenSuccess)
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("打印机端口打开失败"));
        return;
    }

    //打开钱箱
    typedef int (* openCashDrawerEx)(void);
    openCashDrawerEx openCashDrawer = (openCashDrawerEx)lib.resolve("OpenCashDrawerEx");//获取该方法的地址
    /*int n =*/ openCashDrawer();//240为成功，255为失败
    //TipsDlg::instance()->releaseCtrl( "openCashDrawerEx" + QString::number( n ) );

    //关闭串口
    typedef void (*CloseADCom)();
    CloseADCom closeADCom = (CloseADCom)lib.resolve("CloseADCom");
    closeADCom();
}

bool KPosAdDll2::testDll(QString &sHintText)
{
    QLibrary lib(c_sKPosAdDll2Path);
    if (!lib.load())
    {
        sHintText.append(QStringLiteral("中科英泰库加载失败;\n"));
        return false;
    }
    else
    {
        sHintText.append(QStringLiteral("中科英泰库加载成功;\n"));
    }

    // 打开 AD 板串口。
    typedef bool (*OpenADCom)(int port, int baud);
    OpenADCom openADCom = (OpenADCom)lib.resolve("OpenADCom");
    bool bOpenSuccess = openADCom(m_nPrintPort, m_nPrintBaud);
    if (!bOpenSuccess)
    {
        sHintText.append(QStringLiteral("端口打开失败;\n"));
        return false;
    }
    else
    {
        sHintText.append(QStringLiteral("端口打开成功;\n"));
    }

    // 打印单色位图图片
//    typedef int (*PrintBitmapFile)(char* BmpFileName, int LabelAngle);
//    PrintBitmapFile printBitmapFile = (PrintBitmapFile)lib.resolve("PrintBitmapFile");
//    int nResult = printBitmapFile(const_cast<char*>("testPic.bmp"), 1); // 图片打印位置：0,1,2 （居左，居中，居右）。
//    sHintText.append((nResult == HS_OK) ?  QStringLiteral("打印机打开成功;\n") : QStringLiteral("打印机打开失败;\n"));


    // 开钱箱
    typedef int (* openCashDrawerEx)(void);
    openCashDrawerEx openCashDrawer = (openCashDrawerEx)lib.resolve("OpenCashDrawerEx");//获取该方法的地址
    int nResult = openCashDrawer();//240为成功，255为失败
    sHintText.append((nResult == HS_OK) ?  QStringLiteral("钱箱打开成功;\n") : QStringLiteral("钱箱打开失败;\n"));

    // 称重
//    typedef int (*read_standard)(char *buf);
//    read_standard readStandard = (read_standard)lib.resolve("read_standard");
//    EBalanceStandard balanceStandard;
//    nResult = readStandard((char*)&balanceStandard);
//    sHintText.append((nResult == HS_OK) ?  QStringLiteral("称重设备打开成功;\n") : QStringLiteral("称重设备打开失败;\n"));

    //关闭串口
    typedef void (*CloseADCom)();
    CloseADCom closeADCom = (CloseADCom)lib.resolve("CloseADCom");
    closeADCom();

    return (nResult == HS_OK);
}

