#ifndef RECEIPTDETIALINFOLISTVIEW_H
#define RECEIPTDETIALINFOLISTVIEW_H

#include <QWidget>
#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "httpstructdata.h"
#include "receiptdata.h"
#include "structData.h"

class ReceiptDetialInfoDelegate : public QStyledItemDelegate
{
public:
    ReceiptDetialInfoDelegate(QObject* parent = NULL);
    void paint(QPainter *painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const SaleHead &detialInfo, bool bSelected) const;
};


class ReceiptDetialInfoListView : public QListView
{
    Q_OBJECT
public:
    explicit ReceiptDetialInfoListView(QWidget *parent = 0);
    void appendItems(const SaleHead& receiptInfo);
    void clearItems();

private:
    void init();

private:
    QStandardItemModel* m_pStandardItemModel;
    int m_nItemHeight;
    QString m_nSelectKetId;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;
}
#endif // RECEIPTDETIALINFOLISTVIEW_H
