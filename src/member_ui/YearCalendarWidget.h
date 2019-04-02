#ifndef YEARCALENDARWIDGET_H
#define YEARCALENDARWIDGET_H

#include <QWidget>
#include "structData.h"

namespace Ui {
class YearCalendarWidget;
}

class YearCalendarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit YearCalendarWidget(QWidget *parent = 0);
    ~YearCalendarWidget();
private slots:
    void slot_upPage();
    void slot_downPage();
private:
    void initCtrl();
    void initYear();
    void initConnect();

    void clearYearInfo();
    void clearItems();
    void setCurPage( int nCurPage, int nTotalPage );
    void generateYearList();
private:
    Ui::YearCalendarWidget *ui;

    QMap<int, YearInfo> m_mapYearInfo;
    int m_nCurPage;
    int m_nTotalPage;
    int m_nOnePageCount;
};

#endif // YEARCALENDARWIDGET_H
