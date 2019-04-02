#ifndef INSTOCKGOODSSELECTTITLEWIDGET_H
#define INSTOCKGOODSSELECTTITLEWIDGET_H

#include <QWidget>

class InStockGoodsSelectTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InStockGoodsSelectTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // InStockGOODSSELECTTITLEWIDGET_H
