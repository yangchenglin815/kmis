#ifndef STOCKORDERSEARCHLISTVIEW_H
#define STOCKORDERSEARCHLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/stockdata.h"

class StockOrderSearchDelegate : public QStyledItemDelegate
{
public:
    StockOrderSearchDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const StockOrderSearchInfo &searchInfo, bool bSelected) const;
};

class StockOrderSearchListView : public QListView
{
    Q_OBJECT
public:
    explicit StockOrderSearchListView(QWidget *parent = 0);
    void appendItem(const StockOrderSearchInfo& searchInfo);
    void clearItems();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nSelectKeyId;
};

#endif // STOCKORDERSEARCHLISTVIEW_H
