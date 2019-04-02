#ifndef CATEGORYSMALLLISTVIEW_H
#define CATEGORYSMALLLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "goodsmanagedata.h"

class CategorySmallDelegate : public QStyledItemDelegate
{
public:
    CategorySmallDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const sCategorySmallInfo &categorySmallInfo, bool bSelected) const;
};

class CategorySmallListView : public QListView
{
    Q_OBJECT
public:
    explicit CategorySmallListView(QWidget *parent = 0);
    void appendItem(const sCategorySmallInfo& categorySmallInfo);
    void clearItems();
    void setDefaultSelectedCategoryId(int nCategoryId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickCategorySmall(int categorySmallId);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nSelectedCategoryId;
};

#endif // CATEGORYSMALLLISTVIEW_H
