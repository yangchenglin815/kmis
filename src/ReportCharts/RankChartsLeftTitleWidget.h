#ifndef RANKCHARTSLEFTTITLEWIDGET_H
#define RANKCHARTSLEFTTITLEWIDGET_H

#include <QWidget>

class RankChartsLeftTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RankChartsLeftTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // RANKCHARTSLEFTTITLEWIDGET_H
