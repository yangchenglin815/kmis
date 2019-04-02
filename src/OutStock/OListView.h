#ifndef OLISTVIEW_H
#define OLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/stockdata.h"

class OutStockDelegate : public QStyledItemDelegate
{
public:
    OutStockDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const OutStockOrderInfo &stkOrderInfo, bool bSelected) const;
};

class OListView : public QListView
{
    Q_OBJECT
public:
    explicit OListView(QWidget *parent = 0);
    void appendItem(const OutStockOrderInfo& stkOrderInfo);
    void clearItems();
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(OutStockOrderInfo stkOrderInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    quint64 m_nSelectKeyId;
};

#endif // ListView_H
