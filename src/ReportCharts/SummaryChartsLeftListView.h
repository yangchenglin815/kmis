#ifndef SUMMARYCHARTSLEFTLISTVIEW_H
#define SUMMARYCHARTSLEFTLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/reportchartsdata.h"

class SummaryChartsLeftDelegate : public QStyledItemDelegate
{
public:
    SummaryChartsLeftDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const SummaryChartsInfo &summaryChartsInfo) const;
};

class SummaryChartsLeftListView : public QListView
{
    Q_OBJECT
public:
    explicit SummaryChartsLeftListView(QWidget *parent = 0);
    void appendItem(const SummaryChartsInfo& summaryChartsInfo);
    void clearItems();

private:
    void init();

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
};

#endif // SUMMARYCHARTSLEFTLISTVIEW_H
