#ifndef RECEIPTDETIALLISTVIEW_H
#define RECEIPTDETIALLISTVIEW_H

#include <QWidget>
#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "httpstructdata.h"
#include "receiptdata.h"
#include "structData.h"

class ReceiptDetialListDelegate : public QStyledItemDelegate
{
public:
    ReceiptDetialListDelegate(QObject* parent = NULL);
    void paint(QPainter *painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const SaleDetails &detialInfo) const;
};

class ReceiptDetialListView : public QListView
{
    Q_OBJECT
public:
    explicit ReceiptDetialListView(QWidget *parent = 0);
    void appendItems(const SaleDetails& receiptInfo);
    void clearItems();

protected:
    void mousePressEvent(QMouseEvent *event);
private:
    void init();

private:
    QStandardItemModel* m_pStandardItemModel;
    int m_nItemHeight;
    QString m_nSelectKetId;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;
};

#endif // RECEIPTDETIALLISTVIEW_H
