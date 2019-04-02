#ifndef INSTOCKGOODSSELECTLISTVIEW_H
#define INSTOCKGOODSSELECTLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/stockdata.h"

class InStockGoodsSelectDelegate : public QStyledItemDelegate
{
public:
    InStockGoodsSelectDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option, const InStockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintSeqCol(QPainter *painter, const QStyleOptionViewItem &option, const InStockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const InStockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintOtherCol(QPainter *painter, const QStyleOptionViewItem &option, const InStockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintLine(QPainter *painter, const QStyleOptionViewItem &option) const;
};

class InStockGoodsSelectListView : public QListView
{
    Q_OBJECT
public:
    explicit InStockGoodsSelectListView(QWidget *parent = 0);
    void appendItem(const InStockSelectGoodsInfo& selectGoodsInfo);
    void clearItems();
    bool isExistItem(int nKeyId);
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);
    bool getSelectItem(InStockSelectGoodsInfo& selectGoodsInfo);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(InStockSelectGoodsInfo selectGoodsInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nSelectKeyId;
};

#endif // InStockGOODSSELECTLISTVIEW_H
