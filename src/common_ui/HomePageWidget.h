#ifndef HOMEPAGEWIDGET_H
#define HOMEPAGEWIDGET_H

#include <QWidget>
#include "SetGuideWidget.h"

namespace Ui {
class HomePageWidget;
}

class HomePageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomePageWidget(QWidget *parent = 0);
    ~HomePageWidget();
    void initSetGuideObj(SetGuideWidget* setGuideWidget);

public slots:
    void slot_OnlineState( bool bOnline );

private slots:
    void on_saleButton_clicked(); // 销售
    void on_orderGoodsButton_clicked(); // 要货
    void on_reportButton_clicked(); // 报表
    void on_setButton_clicked(); // 设置
    void on_stockingButton_clicked(); // 盘点
    void on_adjustPriceButton_clicked(); // 改价
    void on_accountManageButton_clicked(); // 账号管理
    void on_barCodeScaleButton_clicked(); // 条码秤管理
    void on_minimizeButton_clicked(); // 最小化
    void on_closeButton_clicked(); // 关闭

    void on_outStockButton_clicked();

    void on_inStockButton_clicked();

    void on_modifyPasswdButton_clicked();

    void on_saleDetialButton_clicked();

    void on_reportLossButton_clicked();

    void on_goodsManageButton_clicked();

private:
    void initCtrl();
    void initConnect();

    void initBtn();
signals:
    void sig_showSaleWidget(); // 销售
    void sig_showOrderGoodsWidget(); // 要货
//    void sig_showOrderGoodsCheckWidget(); // 要货卡审核
//    void sig_showReceivingWidget(); // 收货
    void sig_showReportWidget(); // 报表
    void sig_showSetWidget(); // 设置
    void sig_showStockingWidget(); // 盘点
    void sig_showInStockWidget(); // 入库
    void sig_showOutStockWidget(); // 出库
    void sig_showAdjustPriceWidget(); // 改价
    void sig_showbarCodeScaleWidget(); // 条码秤管理
//    void sig_showTrainWidget(); // 训练
//    void sig_showModifyPwdWidget(); // 修改密码
    void sig_minimizeWidget(); // 最小化
    void sig_closeWidget(); // 关闭
    void sig_showResetKeyWidget(); // 修改密码
    void sig_showAccountManageWidget(); // 账户管理
    void sig_showSaleDetialWidget();  // 销售明细
    void sig_showReportLossWidget(); // 报损
    void sig_showGoodsManageWidget(); // 商品管理

private:
    Ui::HomePageWidget *ui;
    SetGuideWidget* m_setGuideWidget;
};

#endif // HOMEPAGEWIDGET_H
