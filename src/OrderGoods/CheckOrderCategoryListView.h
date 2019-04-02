#ifndef CHECKORDERCATEGORYLISTVIEW_H
#define CHECKORDERCATEGORYLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "../data/ordergoodsdata.h"

class CheckOrderCategoryDelegate : public QStyledItemDelegate
{
public:
    CheckOrderCategoryDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const CheckOrderCategoryInfo &checkOrderCategoryInfo, bool bSelected) const;
};

class CheckOrderCategoryListView : public QListView
{
    Q_OBJECT
public:
    explicit CheckOrderCategoryListView(QWidget *parent = 0);
    void appendItem(const CheckOrderCategoryInfo& checkOrderCategoryInfo);
    void clearItems();
    void setDefaultSelectedIdList(QList<int> selectedIdList);
    void clearSelectedIdList();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigAddSelectCategory(int nCategoryId, bool bAdded);
    void sigSelectAllCategory(bool bSelectedAll);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemWidth;
    int m_nItemHeight;
    QList<int> m_selectedIdList;
    bool m_bSelectedAll;
};

#endif // CHECKORDERCATEGORYLISTVIEW_H
