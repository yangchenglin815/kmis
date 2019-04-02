#include "KPos.h"
#include <QApplication>
#include "KPosApplication.h"
#include "../util/SingletonManager.h"
#include "CommonFun.h"
#include <QDir>
#include <QTextStream>

//#include "../OrderGoods/OrderGoodsWidget.h"
//#include "../OrderGoods/CheckOrderGoodsDlg.h" // 测试
//#include "../ReceivingGoods/CreateDeliveryOrderDlg.h"
//#include "../ReceivingGoods/GoodsSelectForCreateWidget.h"
//#include "../ReceivingGoods/GoodsSearchForCreateWidget.h"
//#include "../ReceivingGoods/ReceiveGoodsForCreateWidget.h"
//#include "../ReceivingGoods/ReceiveOrdersWidget.h"
//#include "../Stocking/StockingOrdersWidget.h"
//#include "../Stocking/StockingOrderCheckWidget.h"
//#include "../ReportCharts/ReportChartsWidget.h"
//#include "../common_ui/TitleBarWidget.h"
//#include "../common_ui/KPosCalendarWidget.h"
//#include "../Sale_ui/ReceiptRefundDlg.h"
//#include "../ReportLoss/ReportLossWid.h"
//#include "../SaleDetial/SaleDetialWidget.h"
//#include "../BarcodeScales/BCSGoodsSelectWidget.h"
//#include "goodsmanagewidget.h"
//#include "SetGuideWidget.h"
//#include "StockWidget.h"

#include "KPos.h"
#include "windows.h"
#include "DbgHelp.h"
#include "exceptiondump.h"
#include "constData.h"
#include "ScreenInfo.h"

float g_heightRate=1.00f;
float g_widthRate=1.00f;
bool isQHD=false;
int g_cashHandleType = eRounding; // 现金的分的处理方式
QString g_sHttpAPP_Key = "20160918000001";
QString g_sHttpAPP_Secret = "E44DA6E95045B7712FE40362F3CF2D16";

int main(int argc, char *argv[])
{
    SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);
    int nNUm = CommonFun::getKPosRuningNum();

    KPosApplication a(argc, argv);
    QString path = ":/qss/main.css";

    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        a.setStyleSheet(stream.readAll());
    }

    if (nNUm <= 1)
    {
        SingletonManager singletonManager;
        Q_UNUSED(singletonManager)
        a.checkOnlineStateRequest();
        return a.exec();
    }
    else
    {
        a.hintAllowOnlyoneRun();
        return nNUm;
    }
    /* 设置向导 */
//    KPosApplication a(argc, argv);
//    SetGuideWidget w;
//    w.show();
//    return a.exec();
    /* 盘点 */
//    KPosApplication a(argc, argv);
//    StockWidget w;
//    w.show();
//    return a.exec();
    /* 商品管理 */
//        KPosApplication a(argc, argv);
//        GoodsManageWidget w;
//        w.show();
//        return a.exec();
    /* 销售明细测试 */
//    KPosApplication a(argc, argv);
//    SaleDetialWidget w;
//    w.show();
//    return a.exec();
    /* 报损测试 */
//    KPosApplication a(argc, argv);
//    ReportLossWid w;
//    w.show();
//    return a.exec();
//    // 退款
    //    KPosApplication a(argc, argv);
    //    BCSGoodsSelectWidget dlg;
    //    dlg.show();
    //    return a.exec();

    //     测试
    //    KPosApplication a(argc, argv);
    //    SingletonManager singletonManager;
    //    Q_UNUSED(singletonManager)
    //    KPos kPos;
    //    kPos.show();
    //    return a.exec();

    // 测试
    //    KPosApplication a(argc, argv);
    ////    OrderGoodsDlg dlg;
    ////    dlg.exec();
    //    OrderGoodsWidget orderGoodsWidget;
    //    orderGoodsWidget.show();
    //    return a.exec();

    // 测试
    //    KPosApplication a(argc, argv);
    //    CheckOrderDlg checkOrderDlg;
    //    checkOrderDlg.exec();
    //    return a.exec();

    //    // 测试
    //    KPosApplication a(argc, argv);
    //    CheckOrderGoodsDlg checkOrderGoodsDlg;
    //    checkOrderGoodsDlg.setCheckType(false);
    //    checkOrderGoodsDlg.exec();
    //    return a.exec();

    // 测试
    //    QApplication a(argc, argv);
    ////    ReceiveGoodsDlg receiveGoodsDlg;
    ////    receiveGoodsDlg.show();
    //    ReceiveOrdersWidget receiveOrdersWidget;
    //    receiveOrdersWidget.show();
    //    return a.exec();

    // 测试
    //    KPosApplication a(argc, argv);
    //    CreateDeliveryOrderDlg createDeliveryOrderDlg;
    //    createDeliveryOrderDlg.show();
    //    return a.exec();

    // 测试
    //    KPosApplication a(argc, argv);
    //    GoodsSelectForCreateWidget goodsSelectForCreateWidget;
    //    goodsSelectForCreateWidget.show();
    //    return a.exec();

    // 测试
    //    KPosApplication a(argc, argv);
    //    GoodsSearchForCreateWidget goodsSearchForCreateWidget;
    //    goodsSearchForCreateWidget.show();
    //    return a.exec();

    // 测试
    //    KPosApplication a(argc, argv);
    //    ReceiveGoodsForCreateWidget receiveGoodsForCreateWidget;
    //    receiveGoodsForCreateWidget.show();
    //    return a.exec();

    //    // 测试
    //    KPosApplication a(argc, argv);
    //    StockingOrdersWidget stockingOrdersWidget;
    //    stockingOrdersWidget.show();
    //    return a.exec();

    // 测试
    //    KPosApplication a(argc, argv);
    //    StockingOrderCheckWidget stockingOrderCheckWidget;
    //    stockingOrderCheckWidget.show();
    //    return a.exec();

    // 测试
    //    KPosApplication a(argc, argv);
    //    ReportChartsWidget reportChartsWidget;
    //    reportChartsWidget.show();
    //    return a.exec();

    // 测试
    //    KPosApplication a(argc, argv);
    //    TitleBarWidget titleBarWidget;
    //    titleBarWidget.show();
    //    return a.exec();

    //    // 测试
    //    KPosApplication a(argc, argv);
    //    KPosCalendarWidget kPosCalendarWidget;
    //    kPosCalendarWidget.show();
    //    return a.exec();
}
