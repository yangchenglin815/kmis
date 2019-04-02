#ifndef CATEGORYGOODSLISTVIEW_H
#define CATEGORYGOODSLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "goodsmanagedata.h"

class CategoryGoodsDelegate : public QStyledItemDelegate
{
public:
    CategoryGoodsDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintFirstColumn(QPainter *painter, const QStyleOptionViewItem &option,
                          const sGoodsInfo &goodsInfo) const;
    void paintOtherColumn(QPainter *painter, const QStyleOptionViewItem &option,
                          const sGoodsInfo &goodsInfo) const;
};

class CategoryGoodsListView : public QListView
{
    Q_OBJECT
public:
    explicit CategoryGoodsListView(QWidget *parent = 0);
    void appendItem(const sGoodsInfo& goodsInfo);
    void clearItems();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();
private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    sGoodsInfo m_curGoodsInfo;
};

#endif // CATEGORYGOODSLISTVIEW_H
