#ifndef ADJUSTPRICECATEGORYLISTVIEW_H
#define ADJUSTPRICECATEGORYLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/structData.h"

class AdjustPriceCategoryDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    AdjustPriceCategoryDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option, CategoryInfo &categoryInfo) const;
};

class AdjustPriceCategoryListView : public QListView
{
    Q_OBJECT
public:
    explicit AdjustPriceCategoryListView(QWidget *parent = 0);
    void appendItem(const CategoryInfo& categoryInfo);
    void clearItems();
    void clickSelectKeyId();
    void setWidth(int width);
    void setHeight(int height);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(CategoryInfo categoryInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;//key：分类id
    QList<QString> m_keyIdList;
    int m_nItemHeight;
    int m_nItemWidth;
    QString m_sSelectedKeyId; // 选中的分类主键
};

#endif // ADJUSTPRICECATEGORYLISTVIEW_H
