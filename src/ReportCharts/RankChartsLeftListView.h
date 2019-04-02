#ifndef RANKCHARTSLEFTLISTVIEW_H
#define RANKCHARTSLEFTLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/reportchartsdata.h"

class RankChartsLeftDelegate : public QStyledItemDelegate
{
public:
    RankChartsLeftDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const RankChartsInfo &rankChartsInfo) const;
};

class RankChartsLeftListView : public QListView
{
    Q_OBJECT
public:
    explicit RankChartsLeftListView(QWidget *parent = 0);
    void appendItem(const RankChartsInfo& rankChartsInfo);
    void clearItems();

private:
    void init();

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
};

#endif // RANKCHARTSLEFTLISTVIEW_H
