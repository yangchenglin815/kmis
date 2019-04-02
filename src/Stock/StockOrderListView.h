#ifndef STOCKORDERLISTVIEW_H
#define STOCKORDERLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/stockdata.h"

class StockOrderDelegate : public QStyledItemDelegate
{
public:
    StockOrderDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const StockOrderInfo &stockOrderInfo, bool bSelected) const;
};

class StockOrderListView : public QListView
{
    Q_OBJECT
public:
    explicit StockOrderListView(QWidget *parent = 0);
    void appendItem(const StockOrderInfo& stockOrderInfo);
    void clearItems();
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(StockOrderInfo stockOrderInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nSelectKeyId;
};

#endif // STOCKORDERLISTVIEW_H
