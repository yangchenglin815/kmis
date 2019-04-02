#ifndef SUMMARYCHARTSLEFTTITLEWIDGET_H
#define SUMMARYCHARTSLEFTTITLEWIDGET_H

#include <QWidget>

class SummaryChartsLeftTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SummaryChartsLeftTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // SUMMARYCHARTSLEFTTITLEWIDGET_H
