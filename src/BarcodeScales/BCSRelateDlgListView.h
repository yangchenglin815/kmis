#ifndef BCSRELATEDLGLISTVIEW_H
#define BCSRELATEDLGLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "barcodescaledata.h"

class CSRelateDlgListView : public QStyledItemDelegate
{
public:
    CSRelateDlgListView(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const BarCodeScaleInfo &itemInfo, bool bSelected) const;
    void setStateTextPainter(QPainter *painter, QPen& pen, int nState) const;
};

class BCSRelateDlgListView : public QListView
{
    Q_OBJECT
public:
    explicit BCSRelateDlgListView(QWidget *parent = 0);
    void appendItem(const BarCodeScaleInfo& itemInfo);
    void clearItems();
    void appendSelectKeyIds(const QList<QString>& keyIdList);
    void removeSelectKeyIds(const QList<QString>& keyIdList);
//    QString getSelectKeyId();
//    void setSelectKeyId(QString sKeyId);
//    void getSelectItemInfo(BarCodeScaleInfo& itemInfo);
//    int getSelectSeq();

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
    QList<QString> m_sSelectKeyIdList;
};

#endif // BCSRELATEDLGLISTVIEW_H
