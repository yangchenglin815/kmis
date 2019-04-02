#ifndef RECEIPTLISTVIEW_H
#define RECEIPTLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "httpstructdata.h"
#include "receiptdata.h"

class ReceiptListDelegate : public QStyledItemDelegate
{
public:
    ReceiptListDelegate(QObject* parent = NULL);
    void paint(QPainter *painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const ReceiptInfo &receiptInfo, bool bSelected) const;
};

class ReceiptListView : public QListView
{
    Q_OBJECT
public:
    explicit ReceiptListView(QWidget *parent = 0);
    void appendItems(const ReceiptInfo& receiptInfo);
    void clearItems();
    QString getSelectIdList();
    void setSelectKeyId(QString nKeyId);

protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    void sigClickItem(ReceiptInfo receiptInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    QList<ReceiptInfo> m_selectItemInfoList;
    QString m_nSelectKeyId;

private:
    void init();
};

#endif // RECEIPTLISTVIEW_H
