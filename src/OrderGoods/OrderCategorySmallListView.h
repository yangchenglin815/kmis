#ifndef ORDERCATEGORYSMALLLISTVIEW_H
#define ORDERCATEGORYSMALLLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "../data/ordergoodsdata.h"

class OrderCategorySmallDelegate : public QStyledItemDelegate
{
public:
    OrderCategorySmallDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const OrderCategorySmallInfo &orderCategorySmallInfo, bool bSelected) const;
};

class OrderCategorySmallListView : public QListView
{
    Q_OBJECT
public:
    explicit OrderCategorySmallListView(QWidget *parent = 0);
    void appendItem(const OrderCategorySmallInfo& orderCategorySmallInfo);
    void clearItems();
    void setDefaultSelectedCategoryId(int nCategoryId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickCategorySmall(int categorySmallId);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nSelectedCategoryId;
};

#endif // ORDERCATEGORYSMALLLISTVIEW_H
