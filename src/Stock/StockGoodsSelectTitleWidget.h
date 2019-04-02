#ifndef STOCKGOODSSELECTTITLEWIDGET_H
#define STOCKGOODSSELECTTITLEWIDGET_H

#include <QWidget>

class StockGoodsSelectTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StockGoodsSelectTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // STOCKGOODSSELECTTITLEWIDGET_H
