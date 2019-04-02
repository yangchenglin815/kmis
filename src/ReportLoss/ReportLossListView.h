#ifndef REPORTLOSSLISTVIEW_H
#define REPORTLOSSLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "httpstructdata.h"

class ReportLossDelegate : public QStyledItemDelegate
{
public:
    ReportLossDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const ReportLossInfo &reportLossInfo, bool bSelected) const;
};

class ReportLossListView : public QListView
{
     Q_OBJECT
public:
    explicit ReportLossListView(QWidget *parent = 0);
    void appendItem(const ReportLossInfo& reportLossInfo);
    void clearItems();
    int getSelectIdList();
    void setSelectKeyId(int nKeyId);

protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    void sigClickItem(ReportLossInfo reportLossInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    QList<ReportLossInfo> m_selectItemInfoList;
    int m_nSelectKeyId;

private:
    void init();
};

#endif // REPORTLOSSLISTVIEW_H
