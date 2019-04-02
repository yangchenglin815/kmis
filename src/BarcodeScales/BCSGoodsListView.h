#ifndef BCSGOODSLISTVIEW_H
#define BCSGOODSLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "barcodescaledata.h"

class BCSGoodsDelegate : public QStyledItemDelegate
{
public:
    BCSGoodsDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const BCSGoodsInfo &itemInfo, bool bSelected) const;
};

class BCSGoodsListView : public QListView
{
    Q_OBJECT
public:
    explicit BCSGoodsListView(QWidget *parent = 0);
    void appendItem(const BCSGoodsInfo& itemInfo);
    void clearItems();
    void appendSelectKeyIds(const QList<QString>& keyIdList);
    void removeSelectKeyIds(const QList<QString>& keyIdList);
    void getSelectIdList(QList<QString>& keyIdList);
//    QString getSelectKeyId();
//    void setSelectKeyId(QString sKeyId);
//    void getSelectItemInfo(BCSGoodsInfo& itemInfo);
//    int getSelectSeq();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem();

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    QList<QString> m_sSelectKeyIdList;
    QList<BCSGoodsInfo> m_selectItemInfoList;
};

#endif // BCSGOODSLISTVIEW_H
