#ifndef CHECKORDERGOODSLISTVIEW_H
#define CHECKORDERGOODSLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "ChangeOrderNumberWidget.h"
#include "../data/ordergoodsdata.h"

class CheckOrderGoodsDelegate : public QStyledItemDelegate
{
public:
    CheckOrderGoodsDelegate(QWidget* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintFirstColumn(QPainter *painter, const QStyleOptionViewItem &option,
                          const CheckOrderGoodsInfo &checkOrderGoodsInfo) const;
    void paintOtherColumn(QPainter *painter, const QStyleOptionViewItem &option,
                          const CheckOrderGoodsInfo &checkOrderGoodsInfo) const;
};

class CheckOrderGoodsListView : public QListView
{
    Q_OBJECT
public:
    explicit CheckOrderGoodsListView(QWidget *parent = 0);
    ~CheckOrderGoodsListView();
    void appendItem(const CheckOrderGoodsInfo& checkOrderGoodsInfo);
    void clearItems();
    void setUploadFinishedFlag(bool bFinished);

protected:
    void mousePressEvent(QMouseEvent *event);

private slots:
    void slot_changeNum(int nNum);

private:
    void init();

signals:
    void sigOrderNumberAdded(int nId, int nAddedOrderNum, float fUnitValue, float fPrice);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
//    QMap<int, CheckOrderGoodsInfo> m_checkOrderGoodsInfoMap;
    int m_nItemHeight;
    ChangeOrderNumberWidget* m_pChangeOrderNumberWidget;
    CheckOrderGoodsInfo m_curCheckOrderGoodsInfo;
};

#endif // CHECKORDERGOODSLISTVIEW_H
