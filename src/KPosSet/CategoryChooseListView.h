#ifndef CATEGORYCHOOSELISTVIEW_H
#define CATEGORYCHOOSELISTVIEW_H

#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include <QListView>
#include "structData.h"

class CategoryChooseDelegate : public QStyledItemDelegate
{
public:
    CategoryChooseDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const CategoryChooseInfo& categoryChooseInfo, bool bSelected) const;
    void paintRootContent(QPainter *painter, const QStyleOptionViewItem &option,
                          const CategoryChooseInfo& categoryChooseInfo, bool bSelected) const;
};

class CategoryChooseListView : public QListView
{
    Q_OBJECT
public:
    CategoryChooseListView(QWidget *parent = 0);
    void appendItem(const CategoryChooseInfo& categoryChooseInfo);
    void clearItems();
    void setDefultSelectedCategoryKeyId(QString sCategoryKeyId);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigChooseCategory(CategoryChooseInfo categoryChooseInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nItemWidth;
    int m_nRootItemHeight;
    int m_nRootItemWidth;
    QString m_sSelectedCategoryKeyId;
};

#endif // CATEGORYCHOOSELISTVIEW_H
