#ifndef ZINTDLL_H
#define ZINTDLL_H
#define DLL_EXPORT

#include <QString>

class ZIntDll
{
public:
    static void createReceiptBarCode(QString sBarCode = "123456789"); // 生成条形码
    static void createReceiptQRCode(QString sQRCode = "https://hao.360.cn/"); // 生成二维码
};

#endif // ZINTDLL_H
