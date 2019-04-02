#ifndef STOCKORDERCHECKWIDGET_H
#define STOCKORDERCHECKWIDGET_H

#include <QWidget>
#include "StockDlg.h"
#include "constData.h"
#include "../Bussiness/StockCtrl.h"
#include "../data/structData.h"

namespace Ui {
class StockOrderCheckWidget;
}

class StockOrderCheckWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StockOrderCheckWidget(QWidget *parent = 0);
    ~StockOrderCheckWidget();
    void setCategoryList(QList<CategoryInfo *> categoryInfoList);
    void initSelectGoodsData(const QList<StockSelectGoodsInfo>& searchInfoList, int nOrderId);
    void initStockCtrl(StockCtrl* pStockCtrl);
    void clearGoodsSelectWidgetData();
    void setOrderId(int nOrderId);

private slots:
    void slot_clickCategoryItem(CategoryInfo categoryInfo);
    void slot_clickGoodsItem(GoodsInfo goodsInfo);
    void slot_clickGoodsSelectItem(StockSelectGoodsInfo stockOrderSearchInfo);
    void on_deleteButton_clicked(); // 删除
    void on_modifyNumButton_clicked(); // 修改
    void on_printAllButton_clicked(); // 打印全部
    void on_printAddedButton_clicked(); // 打印新增
    void on_saveButton_clicked(); // 保存
    void slot_onSaveStockOrder(int nCode, QString sMsg);
    void slot_searchChanged(QString sSearchText);
    void slot_addStockGoods(StockSelectGoodsInfo stockSelectGoodsInfo);

private:
    void initConnect();
    void initButtons();

signals:
    void sigSaveOrderSuccess();
    void sigPrintAll(QList<StockSelectGoodsInfo> goodsInfoList, int nOrderId);
    void sigPrintAdded(QList<StockSelectGoodsInfo> addedGoodsList,
                       QList<StockSelectGoodsInfo> removedGoodsList, QList<StockSelectGoodsInfo> updatedGoodsList, int nOrderId);

private:
    Ui::StockOrderCheckWidget *ui;
    StockDlg* m_pStockDlg;
    StockCtrl* m_pStockCtrl;
    int m_nOrderId;
};

#endif // STOCKORDERCHECKWIDGET_H
