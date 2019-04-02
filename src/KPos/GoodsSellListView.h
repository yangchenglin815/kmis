#ifndef GOODSSELLLISTVIEW_H
#define GOODSSELLLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QVariant>
#include <QMouseEvent>
#include "../data/structData.h"

class GoodsSellDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit GoodsSellDelegate();
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
private:
    void paintGoodsInfo(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo& rInfo, bool bSelected) const;
    void paintSequenceCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo& rInfo, bool bSelected) const;
    void paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo& rInfo, bool bSelected) const;
    void paintGoodsPriceCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo& rInfo, bool bSelected) const;
    void paintRefundGoodsPriceCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo& rInfo, bool bSelected) const;
    void paintLine(QPainter *painter, const QStyleOptionViewItem &option) const;
};

class GoodsSellListView : public QListView
{
    Q_OBJECT
public:
    explicit GoodsSellListView(QWidget *parent = 0);
    ~GoodsSellListView();
    void appendItem(const GoodsDetailInfo& rInfo);
    void deleteSelectGoods( const int nSaleDetailPos );
    void clearItems();

    int getRows();
    void setSelectStatus( bool bSelect );
    bool isGoods( const GoodsDetailInfo& st_goodsInfo );
    bool findItem( int nRow, GoodsDetailInfo &rInfo );
    bool isNoSelectGoods( GoodsDetailInfo &rInfo );
    void cancelAllSelectGoods();
    void setPixSize( int nPixSize );

private:
    void mousePressEvent( QMouseEvent *event );
    void mouseDoubleClickEvent(QMouseEvent * event);

signals:
    void sig_selectGoods( GoodsDetailInfo st_goodsInfo );
    void sig_doubleClickItem( GoodsDetailInfo st_goodsInfo );
    void sig_showPromotionDlg();
private:
    void init();

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_mapItemKeyId;

    bool m_bSelect;
};

#endif // GOODSSELLLISTVIEW_H
