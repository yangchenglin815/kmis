#ifndef OINQUIRETITLEWIDGET_H
#define OINQUIRETITLEWIDGET_H

#include <QWidget>
#include <QMap>

class OInquireTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OInquireTitleWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // STOCKORDERTITLEWIDGET_H
