#ifndef CHECKORDERCATEGORYDETAILLISTVIEW_H
#define CHECKORDERCATEGORYDETAILLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "../data/ordergoodsdata.h"

class CheckOrderCategoryDetailDelegate : public QStyledItemDelegate
{
public:
    CheckOrderCategoryDetailDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const CheckOrderCategoryDetailInfo &checkOrderCategoryDetailInfo, bool bSelected) const;
};

class CheckOrderCategoryDetailListView : public QListView
{
    Q_OBJECT
public:
    explicit CheckOrderCategoryDetailListView(QWidget *parent = 0);
    void appendItem(const CheckOrderCategoryDetailInfo& checkOrderCategoryDetailInfo);
    void clearItems();
    void setDefaultSelectedIdList(QList<int> selectedList);
    void clearId();
    QList<int> getSelectedIdList();
    void removeId(int nId);
    int getChooseId();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigSelectId(int nOrderCardId, bool addSelected);
    void sigClickItem(bool);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    QList<int> m_selectedIdList;
    int m_nChooseId;
    int m_nItemHeight;
};

#endif // CHECKORDERCATEGORYDETAILLISTVIEW_H
