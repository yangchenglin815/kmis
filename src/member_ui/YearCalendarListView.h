#ifndef YEARCALENDARLISTVIEW_H
#define YEARCALENDARLISTVIEW_H

#include <QListView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QVariant>
#include <QMouseEvent>
#include "../data/structData.h"

class YearCalendarDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit YearCalendarDelegate( QWidget* parent = NULL );
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
private:
    void paintYearBtn(QPainter *painter, const QStyleOptionViewItem &option, YearInfo &stYearInfo ) const;
    void drawYearImage( QPainter *painter, QRect textRect, bool bSelected ) const;
};

class YearCalendarListView : public QListView
{
    Q_OBJECT
public:
    explicit YearCalendarListView(QWidget *parent = 0);
    ~YearCalendarListView();
    void appendItem(const YearInfo &rInfo);
    void clearItems();
private:
    void mousePressEvent( QMouseEvent *event );
signals:
    void sig_yearInfoClicked( int nCurYearId );
private:
    void init();

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_mapItemKeyId;

    bool m_bSelect;
    int m_nCurYearId;
    YearInfo m_stYearInfo;
};

#endif // YEARCALENDARLISTVIEW_H
