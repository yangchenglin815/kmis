#ifndef PENDINGLISTVIEW_H
#define PENDINGLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include <QStandardItem>
#include "../data/structData.h"

class PendingListDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit PendingListDelegate();
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintOrderInfo(QPainter *painter, const QStyleOptionViewItem &option, const OrderInfo& rInfo, bool bSelected) const;

};

/**
 * @brief The PendingListView class 挂单listView
 */
class PendingListView : public QListView
{
    Q_OBJECT
public:
    explicit PendingListView(QWidget *parent = 0);
    ~PendingListView();
    void appendItem(const OrderInfo& rInfo);//加载或更新图元
    void removeItem( const QString &strOrderNum );//删除图元
    bool findItem( const QString &strOrderNum );//找到图元
    void clearItem();//清除图元
    int getItemsNum();
    int getItemHeight();
protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigUnPending(QString sOrderSequence);
    void sigDeleteOrder(QString sOrderSequence);
    void sig_selectPending( OrderInfo rInfo );

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;
};

#endif // PENDINGLISTVIEW_H
