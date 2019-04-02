#ifndef BCSSENDDOWNTITLEWIDGET_H
#define BCSSENDDOWNTITLEWIDGET_H

#include <QWidget>

class BCSSendDownTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCSSendDownTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // BCSSENDDOWNTITLEWIDGET_H
