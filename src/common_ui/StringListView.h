#ifndef STRINGLISTVIEW_H
#define STRINGLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "../data/commonuidata.h"

class StringListDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit StringListDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    void setFontSize(int nFontSize);

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option, const StrInfo strInfo) const;

private:
    int m_nFontSize;
};

class StringListView : public QListView
{
    Q_OBJECT
public:
    explicit StringListView(QWidget *parent = 0);
    void setItemHeight(int nItemHeight);
    void appendItem(StrInfo strInfo);
    void setFontSize(int nFontSize);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();
    int getItemsCount();

signals:
    void sigClicked(QString sContent);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<QString, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    StringListDelegate* m_pStringListDelegate;
};

#endif // STRINGLISTVIEW_H
