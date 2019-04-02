#ifndef STOCKGOODSSELECTLISTVIEW_H
#define STOCKGOODSSELECTLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "../data/stockdata.h"

class StockGoodsSelectDelegate : public QStyledItemDelegate
{
public:
    StockGoodsSelectDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option, const StockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintSeqCol(QPainter *painter, const QStyleOptionViewItem &option, const StockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const StockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintOtherCol(QPainter *painter, const QStyleOptionViewItem &option, const StockSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintLine(QPainter *painter, const QStyleOptionViewItem &option) const;
};

class StockGoodsSelectListView : public QListView
{
    Q_OBJECT
public:
    explicit StockGoodsSelectListView(QWidget *parent = 0);
    void appendItem(const StockSelectGoodsInfo& selectGoodsInfo);
    void clearItems();
    bool isExistItem(int nKeyId);
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);
    bool getSelectItem(StockSelectGoodsInfo& selectGoodsInfo);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(StockSelectGoodsInfo selectGoodsInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nSelectKeyId;
};

#endif // STOCKGOODSSELECTLISTVIEW_H
