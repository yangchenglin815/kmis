#ifndef BARCODESCALEWIDGET_H
#define BARCODESCALEWIDGET_H

/* 条码秤界面整体结构
BCSManageWidget     条码秤管理
BCSManageTitleWidget
BCSManageListView

BCSGroupManageWidget 商品组管理

BCSGroupManageLeftWidget
BCSGroupManageLeftTitleWidget
BCSGroupManageLeftListView

BCSGroupManageRightWidget
BCSGroupManageRightTitleWiget
BCSGroupManageRightListView

BCSAddDlg 条码秤新增对话框
BCSRelateDlg 条码秤关联对话框

BCSSendDownDlg 条码秤下发对话框
BCSSendDownTitleWidget
BCSSendDownListView

BCSCreateGroupDlg  创建商品组对话框

BCSGoodsSelectWidget 条码秤组商品
BCSGoodsBigCategoryWidget
BCSGoodsBigCategoryListView 商品大类
BCSGoodsSmallCategoryWidget
BCSGoodsSmallCategoryListView 商品中类
BCSGoodsWidget
BCSGoodsTitleWidget
BCSGoodsListView
*/

#include <QWidget>
#include <QPushButton>
#include "BCSSendDownDlg.h"
#include "../Bussiness/BarCodeScalesCtrl.h"

namespace Ui {
class BarCodeScaleWidget;
}

class BarCodeScaleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BarCodeScaleWidget(QWidget *parent = 0);
    ~BarCodeScaleWidget();
    void test();

private slots:
    void slot_returnHomePage();
    void slot_returnBcsPage();
    void slot_editBcsGroup(int nGroupId);
//    void slot_addBcsGroup();

private:
    void initConnect();

signals:
    void sigReturnClicked();

private:
    Ui::BarCodeScaleWidget *ui;
    BarCodeScalesCtrl* m_pCtrl;
};

#endif // BARCODESCALEWIDGET_H
