#ifndef ADDREPORTLOSSLISTVIEW_H
#define ADDREPORTLOSSLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "httpstructdata.h"

class AddReportLossDelegate : public QStyledItemDelegate
{
public:
    AddReportLossDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const AddReportLossSelectInfo& sInfo, bool bSelected) const;
};

class AddReportLossListView : public QListView
{
    Q_OBJECT
public:
    explicit AddReportLossListView(QWidget *parent = 0);
    void appendItem(const AddReportLossSelectInfo& selectLossInfo);
    void clearItems();
    bool isExistItem(int nKeyId);
    int getSelectKeyId();
    void setSelectKeyId(int nKeyId);
    bool getSelectItem(AddReportLossSelectInfo& selectLossInfo);

signals:
    void sigClickItem(AddReportLossSelectInfo selectlossInfo);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nSelectKeyId;
};

#endif // ADDREPORTLOSSLISTVIEW_H
