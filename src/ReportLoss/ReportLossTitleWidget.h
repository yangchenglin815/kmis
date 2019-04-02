#ifndef REPORTLOSSTITLEWIDGET_H
#define REPORTLOSSTITLEWIDGET_H

#include <QWidget>

class ReportLossTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReportLossTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // REPORTLOSSTITLEWIDGET_H
