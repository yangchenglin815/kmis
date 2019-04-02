#ifndef OTITLEWIDGET_H
#define OTITLEWIDGET_H

#include <QWidget>
#include <QMap>

class OTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OTitleWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // STOCKORDERTITLEWIDGET_H
