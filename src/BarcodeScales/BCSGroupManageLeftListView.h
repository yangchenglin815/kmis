#ifndef BCSGROUPMANAGELEFTLISTVIEW_H
#define BCSGROUPMANAGELEFTLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "barcodescaledata.h"

class BCSGroupManageLeftDelegate : public QStyledItemDelegate
{
public:
    BCSGroupManageLeftDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const BCSGroupManageLeftInfo &itemInfo, bool bSelected) const;
};

class BCSGroupManageLeftListView : public QListView
{
    Q_OBJECT
public:
    explicit BCSGroupManageLeftListView(QWidget *parent = 0);
    void appendItem(const BCSGroupManageLeftInfo& itemInfo);
    void clearItems();
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);
    void getSelectItemInfo(BCSGroupManageLeftInfo& itemInfo);
    int getSelectSeq();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem();

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nSelectKeyId;
    BCSGroupManageLeftInfo m_selectItemInfo;
};

#endif // BCSGROUPMANAGELEFTLISTVIEW_H
