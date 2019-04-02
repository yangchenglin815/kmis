#include "KPosAddDllUAN.h"
#include <QMessageBox>
#include "TipsDlg.h"

// 打印机
typedef int (* PrintBitmapFile)(char *, int);//位图文件打印—用于打印条码或 Logo 等，
typedef int(* BeginPrint)(int); //开始打印

// 称重机
typedef int (* ReadBaseInfo)(char *);//读取量程信息----在访问称重相关接口函数之前，必须至少调用一次此函数，并将取得的相关量程信息如实的显示到应用程序界面上。
typedef int (* SendPreTare)(char *buf); // 预设皮重
typedef int (* SetTareBykey)(char *buf); // 自动去皮
typedef int (* SendZero)(); // 清零
typedef int (* ReadStandard)(char *buf); // 称重

#define HS_OK 240

static const QString c_sKPosAdDllPath = "pos_ad_UAN.dll";


void KPosAddDllUAN::printBitmapFile(QString sBitmapPath)
{
    callPrintBitmapFile_stdcall(sBitmapPath);
    callBeginPrint_stdcall(7);
}

void KPosAddDllUAN::cutPage()
{
    callBeginPrint_stdcall(8);
}

void KPosAddDllUAN::readBalanceInfo(EBalanceInfo &banaceInfo)
{
    QLibrary lib(c_sKPosAdDllPath);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_UAN.dll加载失败"));
        return;
    }
    ReadBaseInfo readBaseInfo = (ReadBaseInfo)lib.resolve("read_baseinfo_stdcall");
    readBaseInfo((char*)&banaceInfo);
}

bool KPosAddDllUAN::readBalanceStandard(EBalanceStandard_Ex &balanceStandard_Ex)
{
    QLibrary lib(c_sKPosAdDllPath);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_UAN.dll加载失败"));
        return false;
    }
    ReadStandard readStandard = (ReadBaseInfo)lib.resolve("read_standard_stdcall");

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
        return true;
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
            balanceStandard_Ex.sWeight = "-99.999";
            balanceStandard_Ex.bLessWeight = true;
            return true;
        }
        else if (a == -2)
        {
            balanceStandard_Ex.bOverWeight = true;
            return true;
        }
        else
        {
            return false;
        }
    }
}

void KPosAddDllUAN::autoRemovePeel()
{
    QLibrary lib(c_sKPosAdDllPath);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_dll.dll加载失败"));
        return;
    }

    char buf1[10] = "0.000";
    SendPreTare sendPreTare = (ReadBaseInfo)lib.resolve("send_pre_tare_stdcall");
    sendPreTare(buf1);
    SetTareBykey setTareBykey = (ReadBaseInfo)lib.resolve("set_tare_bykey_stdcall");
    char buf2[10] = "0.000";
    setTareBykey(buf2);
    SendZero sendZero = (SendZero)lib.resolve("send_zero_stdcall");
    sendZero();
}

//打开钱箱
int KPosAddDllUAN::openCashBox()
{
    QLibrary lib(c_sKPosAdDllPath);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_dll.dll加载失败"));
        return -1;
    }

    //打开钱箱
    typedef int (* openCashDrawerEx)(void);
    openCashDrawerEx openCashDrawer = (openCashDrawerEx)lib.resolve("OpenCashDrawerEx");//获取该方法的地址
    int n = openCashDrawer();//240为成功，255为失败
    //TipsDlg::instance()->releaseCtrl( "openCashDrawerEx" + QString::number( n ) );
    return n;
}

bool KPosAddDllUAN::testDll(QString &sHintText)
{
    QLibrary lib(c_sKPosAdDllPath);
    if (!lib.load())
    {
        sHintText.append(QStringLiteral("有安库加载失败;\n"));
        return false;
    }
    else
    {
        sHintText.append(QStringLiteral("有安库加载成功;\n"));
    }

    //返回数传版本
    EBalanceInfo banaceInfo;
    readBalanceInfo(banaceInfo);

    return (banaceInfo.systemVersion == "UAN1.0.0.1");
}

int KPosAddDllUAN::callPrintBitmapFile_stdcall(QString sBitmapPath)
{
    QLibrary lib(c_sKPosAdDllPath);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_dll.dll加载失败"));
        return -1;
    }
    PrintBitmapFile printBitmapFile = (PrintBitmapFile)lib.resolve("PrintBitmapFile_stdcall");
    return printBitmapFile(const_cast<char*>(sBitmapPath.toStdString().c_str()), 0);
}

int KPosAddDllUAN::callBeginPrint_stdcall(int type)
{
    QLibrary lib(c_sKPosAdDllPath);
    if (!lib.load())
    {
        TipsDlg::instance()->releaseCtrl( QStringLiteral("动态库pos_ad_dll.dll加载失败"));
        return -1;
    }

    BeginPrint beginPrint = (BeginPrint)lib.resolve("BeginPrint_stdcall");//
    return beginPrint(type);
}
