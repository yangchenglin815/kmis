#ifndef RECEIVEPROVIDERLISTVIEW_H
#define RECEIVEPROVIDERLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "../data/recievinggoodsdata.h"

class ReceiveProviderDelegate : public QStyledItemDelegate
{
public:
    ReceiveProviderDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const ReceiveProviderInfo &receiveProviderInfo) const;
};

class ReceiveProviderListView : public QListView
{
    Q_OBJECT
public:
    explicit ReceiveProviderListView(QWidget *parent = 0);
    void appendItem(const ReceiveProviderInfo& receiveProviderInfo);
    void clearItems();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickProvider(int nProviderId);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
};

#endif // RECEIVEPROVIDERLISTVIEW_H
