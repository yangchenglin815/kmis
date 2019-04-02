#ifndef OUTSTOCKWID_H
#define OUTSTOCKWID_H

#include <QWidget>
#include "../Bussiness/OutStockCtrl.h"
#include "../data/structData.h"

namespace Ui {
class OutStockWid;
}

class OutStockWid : public QWidget
{
    Q_OBJECT

public:
    explicit OutStockWid(QWidget *parent = 0);
    ~OutStockWid();
    void test();
    void setCategoryList(QList<CategoryInfo*> categoryInfoList);

private slots:
    void slot_returnClicked();
    void slot_addOutStockOrder();
    void slot_onSearchOutStockOrder(int nCode, QString sMsg,QString sTotal, QList<OutStockOrderSearchInfo> searchInfoList);
    void slot_onEditOutStockOrder(int nCode, QString sMsg, QList<OutStockOrderSearchInfo> searchInfoList, int nOrderId);
    void slot_updateOrder();
    void slot_printAll(QList<OutStockSelectGoodsInfo> goodsInfoList, int nOrderId);

private:
    void init();
    void initConnect();

signals:
    void sigReturnClicked();//返回主界面
private:
    Ui::OutStockWid *ui;
    OutStockCtrl* m_pOutStockCtrl;
};

#endif // OutStockWID_H
