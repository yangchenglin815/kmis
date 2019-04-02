#ifndef GOODSFORCREATELISTVIEW_H
#define GOODSFORCREATELISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/recievinggoodsdata.h"

class GoodsForCreateDelegate : public QStyledItemDelegate
{
public:
    GoodsForCreateDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    void setHaveDeleteButtonFlag(bool bHave);

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const GoodsForCreateInfo &goodsForCreateInfo) const;

private:
    bool m_bHaveDeleteButton;
};

class GoodsForCreateListView : public QListView
{
    Q_OBJECT
public:
    explicit GoodsForCreateListView(QWidget *parent = 0);
    void appendItem(const GoodsForCreateInfo& goodsForCreateInfo);
    void clearItems();
    void setItemHeight(int nHeight);
    void setHaveDeleteButtonFlag(bool bHave);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickSearchItem(int nGoodsId);
    void sigDeleteItem(int nGoodsId);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    GoodsForCreateDelegate* m_pGoodsForCreateDelegate;
};

#endif // GOODSFORCREATELISTVIEW_H
