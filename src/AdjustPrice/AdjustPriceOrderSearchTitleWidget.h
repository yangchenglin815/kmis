#ifndef ADJUSTPRICEORDERSEARCHTITLEWIDGET_H
#define ADJUSTPRICEORDERSEARCHTITLEWIDGET_H

#include <QWidget>

class AdjustPriceOrderSearchTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AdjustPriceOrderSearchTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // ADJUSTPRICEORDERSEARCHTITLEWIDGET_H
