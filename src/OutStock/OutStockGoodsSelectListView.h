#ifndef OUTSTOCKGOODSSELECTLISTVIEW_H
#define OUTSTOCKGOODSSELECTLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/stockdata.h"

class OutStockGoodsSelectDelegate : public QStyledItemDelegate
{
public:
    OutStockGoodsSelectDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option, const OutStockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintSeqCol(QPainter *painter, const QStyleOptionViewItem &option, const OutStockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const OutStockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintOtherCol(QPainter *painter, const QStyleOptionViewItem &option, const OutStockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintLine(QPainter *painter, const QStyleOptionViewItem &option) const;
};

class OutStockGoodsSelectListView : public QListView
{
    Q_OBJECT
public:
    explicit OutStockGoodsSelectListView(QWidget *parent = 0);
    void appendItem(const OutStockSelectGoodsInfo& selectGoodsInfo);
    void clearItems();
    bool isExistItem(int nKeyId);
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);
    bool getSelectItem(OutStockSelectGoodsInfo& selectGoodsInfo);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(OutStockSelectGoodsInfo selectGoodsInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nSelectKeyId;
};

#endif // OutStockGOODSSELECTLISTVIEW_H
