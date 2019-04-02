#ifndef CHECKDETIALLISTVIEW_H
#define CHECKDETIALLISTVIEW_H
#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "httpstructdata.h"
class CheckDetialDelegate : public QStyledItemDelegate
{
public:
    CheckDetialDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const AddReportLossSelectInfo &checkDetialInfo, bool bSelected) const;
};

class CheckDetialListView : public QListView
{
    Q_OBJECT
public:
    explicit CheckDetialListView(QWidget *parent = 0);
    void appendItem(const AddReportLossSelectInfo &checkDetialInfo);
    void clearItems();
    int getSelectIdList();
    void setSelectKeyId(int nKeyId);

protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    void sigClickItem(CheckDetialInfo checkDetialInfo);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    QList<CheckDetialInfo> m_selectItemInfoList;
    int m_nSelectKeyId;

private:
    void init();
};

#endif // CHECKDETIALLISTVIEW_H
