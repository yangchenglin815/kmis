#ifndef STOCKWIDGET_H
#define STOCKWIDGET_H

#include <QWidget>
#include "../Bussiness/StockCtrl.h"
#include "../data/structData.h"

namespace Ui {
class StockWidget;
}

class StockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StockWidget(QWidget *parent = 0);
    ~StockWidget();

    void test();
    void setCategoryList(QList<CategoryInfo*> categoryInfoList);

private slots:
    void slot_returnClicked();
    void slot_addStockOrder();
    void slot_onSearchStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> searchInfoList);
    void slot_onEditStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> searchInfoList, int nOrderId);
    void slot_updateOrder();
//    void slot_checkStockSuccess();
    void slot_printAll(QList<StockSelectGoodsInfo> goodsInfoList, int nOrderId);
    void slot_printAdded(QList<StockSelectGoodsInfo> addedGoodsList, QList<StockSelectGoodsInfo> removedGoodsList
                         , QList<StockSelectGoodsInfo> updatedGoodsList, int nOrderId);

private:
    void init();
    void initConnect();

signals:
    void sigReturnClicked();

private:
    Ui::StockWidget *ui;
    StockCtrl* m_pStockCtrl;
};

#endif // STOCKWIDGET_H
