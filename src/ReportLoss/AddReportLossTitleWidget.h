#ifndef ADDREPORTLOSSTITLEWIDGET_H
#define ADDREPORTLOSSTITLEWIDGET_H

#include <QWidget>

class AddReportLossTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AddReportLossTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // ADDREPORTLOSSTITLEWIDGET_H
