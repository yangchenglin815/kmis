#ifndef ORDERCATEGORYGOODSWIDGET_H
#define ORDERCATEGORYGOODSWIDGET_H

#include <QWidget>
#include "../data/ordergoodsdata.h"

namespace Ui {
class OrderCategoryGoodsWidget;
}

class OrderCategoryGoodsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderCategoryGoodsWidget(QWidget *parent = 0);
    ~OrderCategoryGoodsWidget();
    void initData(const QList<OrderGoodsInfo*>& orderGoodsInfoList);
    void setConfirmButtonText(bool bReturnButton);
    void findGoodsPage(int nGoodsId);
    void clearChooseGoods();

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void on_confirmButton_clicked();
    void slot_orderNumberAdded(int nId, int bAddedOrderNum, float fUnitValue, float fPrice);
    void slot_sortSecondCol(bool bDownSort);
    void slot_sortThirdCol(bool bDownSort);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    OrderGoodsInfo* getFirstSearchOrderGoods();

signals:
    void sigOrderGoodsChanged();
    void sigClickReturn(int nGoodsId, int nCategoryBigId, int nCategorySmallId);
    void sigCreateOrderCard(QList<OrderGoodsInfo*> chooseGoodsInfoList); // 生成要货卡

private:
    Ui::OrderCategoryGoodsWidget *ui;
    QList<OrderGoodsInfo*> m_orderGoodsInfoList;
    QMap<int, OrderGoodsInfo*> m_chooseGoodsInfoMap; // 选择的要货商品列表
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    int m_nOrderGoodsSumNumber;
    float m_fOrderGoodsSumPrice;
};

#endif // ORDERCATEGORYGOODSWIDGET_H
