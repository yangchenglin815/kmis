#ifndef ADJUSTPRICEWIDGET_H
#define ADJUSTPRICEWIDGET_H

#include <QWidget>
#include "../data/structData.h"
#include "../Bussiness/AdjustPriceCtrl.h"

namespace Ui {
class AdjustPriceWidget;
}

class AdjustPriceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdjustPriceWidget(QWidget *parent = 0);
    ~AdjustPriceWidget();
    void test();
    void setCategoryList(QList<CategoryInfo*> categoryInfoList);

private slots:
    void slot_returnClicked();
    void slot_addAdjustOrder();
    void slot_onSearchAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList);
    void slot_onEditAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList, int nOrderId);
    void slot_updateOrder();
    void slot_checkAdjustSuccess();
    void slot_printAdjustOrder(QList<AdjustPriceSelectGoodsInfo> goodsInfoList, int nOrderId);

private:
    void init();
    void initConnect();

signals:
    void sigReturnClicked();

private:
    Ui::AdjustPriceWidget *ui;
    AdjustPriceCtrl* m_pAdjustPriceCtrl;
};

#endif // ADJUSTPRICEWIDGET_H
