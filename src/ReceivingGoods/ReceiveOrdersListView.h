#ifndef RECEIVEORDERSLISTVIEW_H
#define RECEIVEORDERSLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/recievinggoodsdata.h"

class ReceiveOrdersDelegate : public QStyledItemDelegate
{
public:
    ReceiveOrdersDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintFirstColumn(QPainter *painter, const QStyleOptionViewItem &option,
                          const ReceiveOrderInfo &receiveGoodsInfo) const;
    void paintOtherColumn(QPainter *painter, const QStyleOptionViewItem &option,
                          const ReceiveOrderInfo &receiveGoodsInfo) const;
    void setStateTextPainter(QPainter *painter, QPen& pen, int nState) const;
};

class ReceiveOrdersListView : public QListView
{
    Q_OBJECT
public:
    explicit ReceiveOrdersListView(QWidget *parent = 0);
    void appendItem(const ReceiveOrderInfo& receiveOrderInfo);
    void clearItems();
    bool isExistReceiveOrder(int nOrderId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigCheckReceiveOrder(int nOrderId);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
};

#endif // RECEIVEORDERSLISTVIEW_H
