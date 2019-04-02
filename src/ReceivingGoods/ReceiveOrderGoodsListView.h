#ifndef RECEIVEORDERGOODSLISTVIEW_H
#define RECEIVEORDERGOODSLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "../data/recievinggoodsdata.h"

class ReceiveOrderGoodsDelegate : public QStyledItemDelegate
{
public:
    ReceiveOrderGoodsDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintFirstColumn(QPainter *painter, const QStyleOptionViewItem &option,
                          const ReceiveOrderGoodsInfo& receiveOrderGoodsInfo) const;
    void paintOtherColumn(QPainter *painter, const QStyleOptionViewItem &option,
                          const ReceiveOrderGoodsInfo& receiveOrderGoodsInfo) const;
    void setStateTextPainter(QPainter *painter, QPen& pen, bool bSave) const;
};

class ReceiveOrderGoodsListView : public QListView
{
    Q_OBJECT
public:
    explicit ReceiveOrderGoodsListView(QWidget *parent = 0);
    void appendItem(const ReceiveOrderGoodsInfo& receiveOrderGoodsInfo);
    void clearItems();
    bool isExistReceiveOrderGoods(int nId);
    void setFinishFlag(bool isFinished);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigReceiveOrderGoodsDetail(int nId);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
};

#endif // RECEIVEORDERGOODSLISTVIEW_H
