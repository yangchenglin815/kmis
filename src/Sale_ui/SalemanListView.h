#ifndef SALEMANLISTVIEW_H
#define SALEMANLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QPushButton>
#include "httpstructdata.h"

class SalemanDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit SalemanDelegate(QWidget* parent = NULL);
    ~SalemanDelegate();
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
protected:
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option, SalemanInfo &stSalemanInfo) const;
    void init();

signals:
    void sigItemClicked( int nSalemanUserId );
private:
    QPushButton* m_pButton;
    int m_nPicLen;
};

class SalemanListView : public QListView
{
    Q_OBJECT
public:
    explicit SalemanListView(QWidget *parent = 0);
    ~SalemanListView();
    void appendItem(const SalemanInfo &stSalemanInfo);
    void clearItems();
    void setSelectedUserId( int nSalemanUserId );
    int getSelectedUserId();
    void setStartPosition(int nStartPosition);

protected:
    void mousePressEvent(QMouseEvent *event);

private slots:
    void slot_itemClicked( int nSalemanUserId );
private:
    void init();
    void initConnect();

signals:
    void sigItemClicked( int nSalemanUserId );
private:
    QStandardItemModel* m_pStandardItemModel;
    SalemanDelegate* m_pSalemanDelegate;
    QMap<int, QStandardItem*> m_ItemUserIdMap;//key：分类id
    int m_nItemHeight;
    int m_nItemWidth;
    int m_nSelectedUserId; // 选中的业务员Id
    int m_nSelectedPos; // 选中的位置
};

#endif // SALEMANLISTVIEW_H
