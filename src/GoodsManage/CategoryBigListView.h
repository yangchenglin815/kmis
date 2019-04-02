#ifndef CATEGORYBIGLISTVIEW_H
#define CATEGORYBIGLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "goodsmanagedata.h"

class CategoryBigDelegate : public QStyledItemDelegate
{
public:
    CategoryBigDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const sCategoryBigInfo &scategoryInfo, bool bSelected) const;
};

class CategoryBigListView : public QListView
{
    Q_OBJECT
public:
    explicit CategoryBigListView(QWidget *parent = 0);
    void appendItem(const sCategoryBigInfo& categoryInfo);
    void clearItems();
    void setDefaultSelectedCategoryId(int nCategoryId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickCategoryBig(int nCategoryId);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nItemWidth;
    int m_nSelectedCategoryId;
};

#endif // CATEGORYBIGLISTVIEW_H
