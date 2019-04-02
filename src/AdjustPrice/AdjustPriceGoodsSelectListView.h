#ifndef ADJUSTPRICEGOODSSELECTLISTVIEW_H
#define ADJUSTPRICEGOODSSELECTLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "adjustpricedata.h"

class AdjustPriceGoodsSelectDelegate : public QStyledItemDelegate
{
public:
    AdjustPriceGoodsSelectDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option, const AdjustPriceSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintSeqCol(QPainter *painter, const QStyleOptionViewItem &option, const AdjustPriceSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const AdjustPriceSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintOtherCol(QPainter *painter, const QStyleOptionViewItem &option, const AdjustPriceSelectGoodsInfo& rInfo, bool bSelected) const;
    void paintLine(QPainter *painter, const QStyleOptionViewItem &option) const;
};

class AdjustPriceGoodsSelectListView : public QListView
{
    Q_OBJECT
public:
    explicit AdjustPriceGoodsSelectListView(QWidget *parent = 0);
    void appendItem(const AdjustPriceSelectGoodsInfo& selectGoodsInfo);
    void clearItems();
    bool isExistItem(int nKeyId);
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);
    bool getSelectItem(AdjustPriceSelectGoodsInfo& selectGoodsInfo);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem(AdjustPriceSelectGoodsInfo selectGoodsInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nSelectKeyId;
};

#endif // ADJUSTPRICEGOODSSELECTLISTVIEW_H
