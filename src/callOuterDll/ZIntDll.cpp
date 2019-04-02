#include "ZIntDll.h"
#include "zint.h"
#include "../data/constData.h"
#include "../util/FilePathManage.h"
#include <QDebug>

void ZIntDll::createReceiptBarCode(QString sBarCode)
{
    struct zint_symbol * my_symbol = ZBarcode_Create();
    my_symbol->symbology=BARCODE_CODE128;
    QString sPicturePath = FilePathManage::instance()->getReceiptPath() + c_sReceiptBarCodeName;
    const char* picturePath = sPicturePath.toStdString().c_str();
    strcpy(my_symbol->outfile, picturePath);
    ZBarcode_Encode(my_symbol, (unsigned char*)(sBarCode.toStdString().c_str()),0);
    ZBarcode_Print(my_symbol,0); //
    ZBarcode_Delete(my_symbol);
}

void ZIntDll::createReceiptQRCode(QString sQRCode)
{
    struct zint_symbol * my_symbol = ZBarcode_Create();
    my_symbol->symbology = BARCODE_QRCODE;
    QString sPicturePath = FilePathManage::instance()->getReceiptPath() + c_sReceiptQRCodeName;
    const char* picturePath = sPicturePath.toStdString().c_str();
    strcpy(my_symbol->outfile, picturePath);
    ZBarcode_Encode(my_symbol,(unsigned char*)(sQRCode.toStdString().c_str()), 0);
    ZBarcode_Print(my_symbol,0); //
    ZBarcode_Delete(my_symbol);
}
