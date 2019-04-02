#ifndef BCSGROUPMANAGERIGHTLISTVIEW_H
#define BCSGROUPMANAGERIGHTLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "barcodescaledata.h"

class BCSGroupManageRightDelegate : public QStyledItemDelegate
{
public:
    BCSGroupManageRightDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const BCSGroupManageRightInfo &itemInfo, bool bSelected) const;
};

class BCSGroupManageRightListView : public QListView
{
    Q_OBJECT
public:
    explicit BCSGroupManageRightListView(QWidget *parent = 0);
    void appendItem(const BCSGroupManageRightInfo& itemInfo);
    void clearItems();
    QString getSelectKeyId();
    void setSelectKeyId(QString sKeyId);
    void getSelectItemInfo(BCSGroupManageRightInfo& itemInfo);
    int getSelectSeq();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(BCSGroupManageRightInfo itemInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    QString m_sSelectKeyId;
    BCSGroupManageRightInfo m_selectItemInfo;
};

#endif // BCSGROUPMANAGERIGHTLISTVIEW_H
