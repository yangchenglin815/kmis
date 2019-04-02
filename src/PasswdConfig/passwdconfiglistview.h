#ifndef PASSWDCONFIGLISTVIEW_H
#define PASSWDCONFIGLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "httpstructdata.h"

class PasswdConfigDelegate : public QStyledItemDelegate
{
public:
    PasswdConfigDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const AccountInfo &accountInfo, bool bSelected) const;
};

class PasswdConfigListView : public QListView
{
    Q_OBJECT
public:
    explicit PasswdConfigListView(QWidget *parent = 0);
    void appendItem(const AccountInfo& accountInfo);
    void clearItems();
    void appendSelectKeyIds(const QList<int> &keyIdList);
    void removeSelectKeyIds(const QList<int>& keyIdList);
    void getSelectIdList(QList<int>& keyIdList);
    void clearSecectIdList();
  /*  QString getSelectKeyId();
    void setSelectKeyId(QString sKeyId);
    void getSelectItemInfo(BCSGoodsInfo& itemInfo);
    int getSelectSeq();*/

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();

signals:
    void sigClickItem();

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    QList<int> m_sSelectKeyIdList;
    QList<AccountInfo> m_selectItemInfoList;
};

#endif // PASSWDCONFIGLISTVIEW_H
