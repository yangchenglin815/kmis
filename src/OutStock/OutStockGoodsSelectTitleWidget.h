#ifndef OUTSTOCKGOODSSELECTTITLEWIDGET_H
#define OUTSTOCKGOODSSELECTTITLEWIDGET_H

#include <QWidget>

class OutStockGoodsSelectTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OutStockGoodsSelectTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // OutStockGOODSSELECTTITLEWIDGET_H
