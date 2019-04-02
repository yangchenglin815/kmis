#ifndef ADJUSTPRICEORDERTITLEWIDGET_H
#define ADJUSTPRICEORDERTITLEWIDGET_H

#include <QWidget>

class AdjustPriceOrderTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AdjustPriceOrderTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // ADJUSTPRICEORDERTITLEWIDGET_H
