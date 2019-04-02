#ifndef STOCKORDERTITLEWIDGET_H
#define STOCKORDERTITLEWIDGET_H

#include <QWidget>

class StockOrderTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StockOrderTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // STOCKORDERTITLEWIDGET_H
