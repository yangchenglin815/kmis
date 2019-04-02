#ifndef ADJUSTPRICEORDERLISTVIEW_H
#define ADJUSTPRICEORDERLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "../data/adjustpricedata.h"

class AdjustPriceOrderDelegate : public QStyledItemDelegate
{
public:
    AdjustPriceOrderDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const AdjustPriceOrderInfo &adjustPriceOrderInfo, bool bSelected) const;
};

class AdjustPriceOrderListView : public QListView
{
    Q_OBJECT
public:
    explicit AdjustPriceOrderListView(QWidget *parent = 0);
    void appendItem(const AdjustPriceOrderInfo& adjustPriceOrderInfo);
    void clearItems();
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(AdjustPriceOrderInfo adjustPriceOrderInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nSelectKeyId;
};

#endif // ADJUSTPRICEORDERLISTVIEW_H
