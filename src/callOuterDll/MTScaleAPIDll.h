#ifndef MTSCALEAPIDLL_H
#define MTSCALEAPIDLL_H

#include <QWidget>
#include "MTScaleAPI.h"
#include "barcodescaledata.h"

//条型码读取的商品信息
struct MTBarcodeProductData_s
{
    QString plu;//商品PLU码
    QString weight;//商品重量或数量
};

////电子秤信息
//struct MTDeviceData_s
//{
//    QString DeviceID;//序号
//    QString ScaleNo;//秤号
//    QString IP;//ip地址

//};

////下发的商品数据
//struct MTIssuedProductData_s
//{
//    QString PLU;//plu码
//    QString AlternativeItemID;//货号
//    QString ItemName;//商品名称
//    QString UnitOfMeasureCode;//商品计价方式
//    QString ItemPrice;//商品价格

//};

class MTScaleAPIDll : public QWidget
{
    Q_OBJECT
public:
    static void IssuedMTScale(QString sTaskID);
    static void createScaleXML(QString sTaskID ,BarCodeScaleInfo sendInfo, QList<BCSGroupManageRightInfo> groupList);
    static MTBarcodeProductData_s verifyBarcode(QString sBarcode);
    static bool ceadResultXML();
private:

};



#endif // MTSCALEAPIDLL_H
