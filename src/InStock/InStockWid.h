#ifndef INSTOCKWID_H
#define INSTOCKWID_H

#include <QWidget>
#include "../Bussiness/InStockCtrl.h"
#include "../data/structData.h"

namespace Ui {
class InStockWid;
}

class InStockWid : public QWidget
{
    Q_OBJECT

public:
    explicit InStockWid(QWidget *parent = 0);
    ~InStockWid();
    void test();
    void setCategoryList(QList<CategoryInfo*> categoryInfoList);

private slots:
    void slot_returnClicked();
    void slot_addInStockOrder();
    void slot_onSearchInStockOrder(int nCode, QString sMsg,QString sTotal, QList<InStockOrderSearchInfo> searchInfoList);
    void slot_onEditInStockOrder(int nCode, QString sMsg, QList<InStockOrderSearchInfo> searchInfoList, int nOrderId);
    void slot_updateOrder();
    void slot_printAll(QList<InStockSelectGoodsInfo> goodsInfoList, int nOrderId);

private:
    void init();
    void initConnect();

signals:
    void sigReturnClicked();//返回主界面
    void sigAddQuickGoods(); // 快速建档

private:
    Ui::InStockWid *ui;
    InStockCtrl* m_pInStockCtrl;
};

#endif // INSTOCKWID_H
