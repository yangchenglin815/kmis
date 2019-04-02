#ifndef KPOSCALENDARLISTVIEW_H
#define KPOSCALENDARLISTVIEW_H

#include <QListView>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include "commonuidata.h"

class KPosCalendarDelegate : public QStyledItemDelegate
{
public:
    KPosCalendarDelegate(QObject* parent = NULL);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

private:
    void paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                      const CalendarInfo& calendarInfo, bool bSelected) const;

};

class KPosCalendarListView : public QListView
{
    Q_OBJECT
public:
    explicit KPosCalendarListView(QWidget *parent = 0);
    void setYearAndMonth(int nYear, int nMonth);
    void appendItem(const CalendarInfo& calendarInfo);
    void clearItems();
    void setDefualtDate(int nYear, int nMonth, int nDay);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void init();
    QString generateKey(int nYear, int nMonth, int nDay);

signals:
    void sigClickDate(int nYear, int nMonth, int nDay);

private:
    QStandardItemModel* m_pStandardItemModel;
    QMap<int, QStandardItem*> m_ItemKeyIdMap;
    int m_nItemHeight;
    int m_nItemWidth;
    int m_nYear;
    int m_nMonth;
    QString m_sSelectedKeyId;
};

#endif // KPOSCALENDARLISTVIEW_H
