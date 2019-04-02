#ifndef INQUIRELISTVIEW_H
#define INQUIRELISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/stockdata.h"

class InquireDelegate : public QStyledItemDelegate
{
public:
    InquireDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const InStockOrderSearchInfo &stkOrderInfo, bool bSelected) const;
};

class InquireListView : public QListView
{
    Q_OBJECT
public:
    explicit InquireListView(QWidget *parent = 0);
    void appendItem(const InStockOrderSearchInfo& stkOrderInfo);
    void clearItems();
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(InStockOrderSearchInfo stkOrderInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    quint64 m_nSelectKeyId;
};

#endif // InquireListView_H
