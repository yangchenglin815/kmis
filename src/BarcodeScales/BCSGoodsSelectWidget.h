#ifndef BCSGOODSSELECTWIDGET_H
#define BCSGOODSSELECTWIDGET_H

#include <QWidget>
#include "ordergoodsdata.h"
#include "httpstructdata.h"
#include "../Bussiness/BarCodeScalesCtrl.h"

namespace Ui {
class BCSGoodsSelectWidget;
}

class BCSGoodsSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCSGoodsSelectWidget(QWidget *parent = 0);
    ~BCSGoodsSelectWidget();
//    void test();
    void setCtrl(BarCodeScalesCtrl* pCtrl);
    void setGroupId(int nGroupId);
    void init();

private slots:
    void slot_clickCategoryBig(int nCategoryBigId);
    void slot_clickCategorySmall(int nCategorySmallId);
    void slot_updateSelectCount(QList<QString> keyIdList);
    void slot_saveGroupGoods(QList<QString> keyIdList);
//    void slot_orderGoodsChanged();
//    void slot_searchChanged(QString searchText);
//    void slot_orderGoodsWidgetClickReturn(int nGoodsId, int nCategoryBigId, int nCategorySmallId);
//    void slot_createOrderCard(QList<OrderGoodsInfo*> orderGoodsInfoList);
//    void slot_returnClicked();

    void slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> orderCategoryBigList);
//    void slot_onCreateOrderCard(int nCode, QString sMsg);

private:
    void initConnect();
    OrderCategoryBigInfo* getCategoryBigInfo(int nCategoryBigId);
    OrderCategorySmallInfo* getCategorySmallInfo(OrderCategoryBigInfo* pOrderCategoryBigInfo, int nCategorySmallId);
    void clearData();

signals:
    void sigReturnClicked();

private:
    Ui::BCSGoodsSelectWidget *ui;
    QList<OrderCategoryBigInfo*> m_orderCategoryBigInfoList;
    BarCodeScalesCtrl* m_pCtrl;
    int m_nClickedCategoryBigId;
    QMap<int, int> m_categoryBigSmallIdMap;
    QList<int> m_nRequestCategoryIdList;
    QMap<int, QList<BCSGoodsInfo> > m_goodInfoMap;
    int m_nGroupId;
};

#endif // BCSGOODSSELECTWIDGET_H
