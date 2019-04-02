#ifndef KPOSCALENDARWIDGET_H
#define KPOSCALENDARWIDGET_H

#include <QWidget>

namespace Ui {
class KPosCalendarWidget;
}

class KPosCalendarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KPosCalendarWidget(QWidget *parent = 0);
    ~KPosCalendarWidget();

private slots:
    void on_yearLeftButton_clicked();
    void on_yearRightButton_clicked();
    void on_monthLeftButton_clicked();
    void on_monthRightButton_clicked();

private:
    void init();
    void generateUI();
    void initConnect();

signals:
    void sigClickDate(int nYear, int nMonth, int nDay);

private:
    Ui::KPosCalendarWidget *ui;
    int m_nYear;
    int m_nMonth;
    int m_nDay;
};

#endif // KPOSCALENDARWIDGET_H
