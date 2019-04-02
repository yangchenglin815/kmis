#ifndef REFUNDWITHRECEIPTVIEW_H
#define REFUNDWITHRECEIPTVIEW_H

#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include <QListView>
#include "../data/structData.h"

class ReceipRefundDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ReceipRefundDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option, const RefundWithReceiptInfo& rInfo) const;
};

class RefundWithReceiptView : public QListView
{
    Q_OBJECT
public:
    RefundWithReceiptView(QWidget* parent = NULL);
    void appendItem(const RefundWithReceiptInfo& rInfo);
    void clearItems();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigButtonClicked(QString sOrderSequence);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
};

#endif // REFUNDWITHRECEIPTVIEW_H
