#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/stockdata.h"

class InStockDelegate : public QStyledItemDelegate
{
public:
    InStockDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const InStockOrderInfo &stkOrderInfo, bool bSelected) const;
};

class ListView : public QListView
{
    Q_OBJECT
public:
    explicit ListView(QWidget *parent = 0);
    void appendItem(const InStockOrderInfo& stkOrderInfo);
    void clearItems();
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(InStockOrderInfo stkOrderInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    quint64 m_nSelectKeyId;
};

#endif // ListView_H
