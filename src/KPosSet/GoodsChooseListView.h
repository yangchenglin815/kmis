#ifndef GOODSCHOOSELISTVIEW_H
#define GOODSCHOOSELISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "structData.h"

class GoodsChooseDelegate : public QStyledItemDelegate
{
public:
    GoodsChooseDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const GoodsChooseInfo &goodsChooseInfo) const;
};

class GoodsChooseListView : public QListView
{
    Q_OBJECT
public:
    explicit GoodsChooseListView(QWidget *parent = 0);
    void appendItem(const GoodsChooseInfo& goodsChooseInfo);
    void clearItems();
    void clearSelectGoodsIdList();
    void setDefaultSelectedGoodsList(QList<int> selectedGoodsList);
    QList<int> getSelectedGoodsIdList();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nItemWidth;
    QList<int> m_nSelectedGoodsIdList;
};

#endif // GOODSCHOOSELISTVIEW_H
