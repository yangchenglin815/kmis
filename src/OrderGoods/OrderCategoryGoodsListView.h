#ifndef ORDERCATEGORYGOODSLISTVIEW_H
#define ORDERCATEGORYGOODSLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "../data/ordergoodsdata.h"
#include "ChangeOrderNumberWidget.h"

class OrderCategoryGoodsDelegate : public QStyledItemDelegate
{
public:
    OrderCategoryGoodsDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintFirstColumn(QPainter *painter, const QStyleOptionViewItem &option,
                          const OrderGoodsInfo &orderGoodsInfo) const;
    void paintOtherColumn(QPainter *painter, const QStyleOptionViewItem &option,
                          const OrderGoodsInfo &orderGoodsInfo) const;
};

class OrderCategoryGoodsListView : public QListView
{
    Q_OBJECT
public:
    explicit OrderCategoryGoodsListView(QWidget *parent = 0);
    ~OrderCategoryGoodsListView();
    void appendItem(const OrderGoodsInfo& orderGoodsInfo);
    void clearItems();

protected:
    void mousePressEvent(QMouseEvent *event);

private slots:
    void slot_changeNum(int nNum);

private:
    void init();

signals:
    void sigOrderNumberAdded(int nId, int nAddedOrderNum, float fUnitValue, float fPrice);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
//    QMap<int, OrderGoodsInfo> m_orderGoodsInfoMap;
    int m_nItemHeight;
    ChangeOrderNumberWidget* m_pChangeOrderNumberWidget;
    OrderGoodsInfo m_curOrderGoodsInfo;
};

#endif // ORDERCATEGORYGOODSLISTVIEW_H
