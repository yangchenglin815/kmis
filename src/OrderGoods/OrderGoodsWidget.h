#ifndef ORDERGOODSWIDGET_H
#define ORDERGOODSWIDGET_H

#include <QWidget>
#include "../data/ordergoodsdata.h"
#include "../Bussiness/OrderGoodsCtrl.h"
#include "../common_ui/DlgCommon.h"

namespace Ui {
class OrderGoodsWidget;
}

class OrderGoodsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderGoodsWidget(QWidget *parent = 0);
    ~OrderGoodsWidget();
    void setReInitData();
    void test();

private slots:
    void slot_clickCategoryBig(int nCategoryBigId);
    void slot_clickCategorySmall(int nCategorySmallId);
    void slot_orderGoodsChanged();
    void slot_searchChanged(QString searchText);
    void slot_orderGoodsWidgetClickReturn(int nGoodsId, int nCategoryBigId, int nCategorySmallId);
    void slot_createOrderCard(QList<OrderGoodsInfo*> orderGoodsInfoList);
    void slot_returnClicked();

    void slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> orderCategoryBigList);
    void slot_onGetOrderGoods(int nCode, QString sMsg, QList<OrderGoodsInfo_s> orderGoodsInfoList, int nCategoryBigId);
    void slot_onCreateOrderCard(int nCode, QString sMsg);

private:
    void initConnect();
    OrderCategoryBigInfo* getCategoryBigInfo(int nCategoryBigId);
    void getOrderCategory();
    void clearData();
    void clearChooseGoods();

signals:
    void sigReturnClicked(bool bOrderCardChanged);

private:
    Ui::OrderGoodsWidget *ui;
    QList<OrderCategoryBigInfo*> m_orderCategoryBigInfoList;
    int m_nClickedCategoryBigId;
    QMap<int, int> m_categoryBigSmallIdMap;
    OrderGoodsCtrl* m_pOrderGoodsCtrl;
    QList<int> m_nRequestCategoryIdList;
    DlgCommon* m_pDlgCommon;
    bool m_bOrderCardChanged;
    bool m_bReInitData;
};

#endif // ORDERGOODSWIDGET_H
