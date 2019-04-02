#ifndef ADJUSTPRICEGOODSLISTVIEW_H
#define ADJUSTPRICEGOODSLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include <QPushButton>
#include "../data/structData.h"

class AdjustPriceGoodsDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    AdjustPriceGoodsDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option, GoodsInfo &goodsInfo) const;
};

class AdjustPriceGoodsListView : public QListView
{
    Q_OBJECT
public:
    explicit AdjustPriceGoodsListView(QWidget *parent = 0);
    void appendItem(const GoodsInfo& goodsInfo);
    void clearItems();
    void setWidth(int width);
    void setHeight(int height);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(GoodsInfo goodsInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nItemWidth;
};

#endif // ADJUSTPRICEGOODSLISTVIEW_H
