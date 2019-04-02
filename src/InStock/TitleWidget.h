#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include <QMap>

class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // STOCKORDERTITLEWIDGET_H
