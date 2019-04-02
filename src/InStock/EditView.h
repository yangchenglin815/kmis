#ifndef EDITVIEW_H
#define EDITVIEW_H

#include <QWidget>
#include "constData.h"
#include "structData.h"
#include "../Bussiness/InStockCtrl.h"
#include "QuickAddDlg.h"
#include "../data/structData.h"
#include "AddInStkDlg.h"
#include "SaleCtrl.h"

namespace Ui {
class EditView;
}

class EditView : public QWidget
{
    Q_OBJECT

public:
    explicit EditView(QWidget *parent = 0);
    ~EditView();
    void setCategoryList(QList<CategoryInfo *> categoryInfoList);
    void initSelectGoodsData(const QList<InStockSelectGoodsInfo>& searchInfoList, int nOrderId);
    void initInStockCtrl(InStockCtrl* pInStockCtrl);
    void clearGoodsSelectWidgetData();
    void setOrderId(int nOrderId);

private slots:
    void slot_clickCategoryItem(CategoryInfo categoryInfo);
    void slot_clickGoodsItem(GoodsInfo goodsInfo);
//    void slot_clickGoodsSelectItem(InStockSelectGoodsInfo inStockOrderSearchInfo);
    void on_deleteButton_clicked(); // 删除
    void on_modifyButton_clicked(); // 修改
    void on_printBtn_clicked(); // 打印
    void on_saveButton_clicked(); // 保存
    void slot_onSaveInStockOrder(int nCode, QString sMsg);
    void slot_searchChanged(QString sSearchText);
    void slot_addInStockGoods(InStockSelectGoodsInfo inStockSelectGoodsInfo);

    void on_quickAddButton_clicked();

private:
    void initConnect();
    void initButtons();

signals:
    void sigSaveOrderSuccess();
    void sigPrintAll(QList<InStockSelectGoodsInfo> goodsInfoList, int nOrderId);
    void sigAddQuickGoods(); // 快速建档

private:
    Ui::EditView *ui;
    AddInStkDlg* m_pInStockDlg;
    InStockCtrl* m_pInStockCtrl;
    QuickAddDlg* addKind;
    int m_nOrderId;

};

#endif // EDITVIEW_H
