#ifndef BCSMANAGELISTVIEW_H
#define BCSMANAGELISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "barcodescaledata.h"

class BCSManageDelegate : public QStyledItemDelegate
{
public:
    BCSManageDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const BarCodeScaleInfo &itemInfo, bool bSelected) const;
    void setStateTextPainter(QPainter *painter, QPen& pen, int nState) const;
};

class BCSManageListView : public QListView
{
    Q_OBJECT
public:
    explicit BCSManageListView(QWidget *parent = 0);
    void appendItem(const BarCodeScaleInfo& itemInfo);
    void clearItems();
    QString getSelectKeyId();
    void setSelectKeyId(QString sKeyId);
    void getSelectItemInfo(BarCodeScaleInfo& itemInfo);
    int getSelectSeq();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(BarCodeScaleInfo itemInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    QString m_sSelectKeyId;
    BarCodeScaleInfo m_selectItemInfo;
};

#endif // BCSMANAGELISTVIEW_H
