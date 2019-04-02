#ifndef ORDERCATEGORYBIGLISTVIEW_H
#define ORDERCATEGORYBIGLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "../data/ordergoodsdata.h"

class OrderCategoryBigDelegate : public QStyledItemDelegate
{
public:
    OrderCategoryBigDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const OrderCategoryBigInfo &orderCategoryInfo, bool bSelected) const;
};


class OrderCategoryBigListView : public QListView
{
    Q_OBJECT
public:
    explicit OrderCategoryBigListView(QWidget *parent = 0);
    void appendItem(const OrderCategoryBigInfo& orderCategoryInfo);
    void clearItems();
    void setDefaultSelectedCategoryId(int nCategoryId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickCategoryBig(int nCategoryId);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nItemWidth;
    int m_nSelectedCategoryId;
};

#endif // ORDERCATEGORYBIGLISTVIEW_H
