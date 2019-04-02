#ifndef KPOS_H
#define KPOS_H

#include <QMainWindow>
#include "GlobalEventFilter.h"
#include "CustomerDisplayDlg.h"
#include "setstructdata.h"
#include "ClientCashSubmit.h"
#include "SetGuideWidget.h"

namespace Ui {
class KPos;
}

class KPos : public QMainWindow
{
    Q_OBJECT

public:
    explicit KPos(QWidget *parent = 0);
    ~KPos();
    void setRemoteADList(QList<QString> remoteADList);
    void reInit();

public:
    void resizeEvent(QResizeEvent *event);
signals:
    void sig_closeWnd();
    void sig_lockScreen();
private:
    void init();
    void initConnect();
    bool multiScreenShow( QWidget *p_full_widget, QRect app_rect );
private slots:
    void slot_minimizeWidget();
    void slot_closeWidget();

    void slot_showHomeWidget();
    void slot_showSaleWidget(); // 销售
    void slot_showReportWidget();
    void slot_showSetWidget();
    void slot_showInStockWidget();//入库界面显示
    void slot_showOutStockWidget();//出库界面显示
    void slot_updateSetInfo();
    void slot_downloadKposSet();
    void slot_showTrainWidget();
    void slot_modifyPwdWidget();
    void slot_showOrderGoodsWidget();
    void slot_showReceivingWidget();
    void slot_showStockingWidget(); // 盘点
    void slot_showAdjustPriceWidget(); // 改价
    void slot_showbarCodeScaleWidget(); // 条码秤管理
    void slot_showResetKeyWidget(); // 修改密码
    void slot_showAccountManageWidget(); // 账号管理
    void slot_showSaleDetialWidget(); // 销售明细
    void slot_showReportLossWidget(); // 报损
    void slot_showGoodsManageWidget(); // 商品管理

    //客显显示
    void slot_addGoodsToSaleList( SaleDetails stSaleDetailsInfo );
    void slot_delGoodsToSaleList( int nSaleDetailsPos );
    void slot_clearGoodsToSaleList();
    void slot_loginMem( bool bMember );
private:
    Ui::KPos *ui;
    CustomerDisplayDlg *m_pCustomerDisplayDlg;
    ClientCashSubmit *m_pClientCashSubmit;
    SetGuideWidget *m_setGuideWidget;
};

#endif // KPOS_H
