#ifndef GOODSREFUNDLISTVIEW_H
#define GOODSREFUNDLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/structData.h"

class GoodsRefundDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit GoodsRefundDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
private:
    void paintGoodsInfo(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo& rInfo, bool bSelected) const;
    void paintSequenceCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo& rInfo, bool bSelected) const;
    void paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo& rInfo, bool bSelected) const;
    void paintGoodsPriceCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo& rInfo, bool bSelected) const;
    void paintLine(QPainter *painter, const QStyleOptionViewItem &option) const;
};

class GoodsRefundListView : public QListView
{
    Q_OBJECT
public:
    explicit GoodsRefundListView(QWidget *parent = 0);
    void appendItem(const GoodsDetailInfo& rInfo);
    void clearItems();
    QList<int> getSelectIdList();
    void clearSelectIdList();

private:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem();

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    QList<int> m_selectIdList;
    int m_nItemHeight;
};

#endif // GOODSREFUNDLISTVIEW_H
