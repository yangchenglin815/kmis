#ifndef OINQUIRELISTVIEW_H
#define OINQUIRELISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/stockdata.h"

class OInquireDelegate : public QStyledItemDelegate
{
public:
    OInquireDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const OutStockOrderSearchInfo &stkOrderInfo, bool bSelected) const;
};

class OInquireListView : public QListView
{
    Q_OBJECT
public:
    explicit OInquireListView(QWidget *parent = 0);
    void appendItem(const OutStockOrderSearchInfo& stkOrderInfo);
    void clearItems();
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(OutStockOrderSearchInfo stkOrderInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    quint64 m_nSelectKeyId;
};

#endif // OInquireListView_H
