#ifndef ADJUSTPRICEGOODSSELECTTITLEWIDGET_H
#define ADJUSTPRICEGOODSSELECTTITLEWIDGET_H

#include <QWidget>

class AdjustPriceGoodsSelectTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AdjustPriceGoodsSelectTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // ADJUSTPRICEGOODSSELECTTITLEWIDGET_H
