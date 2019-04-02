#ifndef ADJUSTPRICEORDERSEARCHLISTVIEW_H
#define ADJUSTPRICEORDERSEARCHLISTVIEW_H

#include <QStyledItemDelegate>
#include <QListView>
#include <QStandardItemModel>
#include "adjustpricedata.h"

class AdjustPriceOrderSearchDelegate : public QStyledItemDelegate
{
public:
    AdjustPriceOrderSearchDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const AdjustPriceOrderSearchInfo &orderSearchInfo, bool bSelected) const;
};

class AdjustPriceOrderSearchListView : public QListView
{
    Q_OBJECT
public:
    explicit AdjustPriceOrderSearchListView(QWidget *parent = 0);
    void appendItem(const AdjustPriceOrderSearchInfo& searchInfo);
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

#endif // ADJUSTPRICEORDERSEARCHLISTVIEW_H
