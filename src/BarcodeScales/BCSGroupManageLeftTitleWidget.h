#ifndef BCSGROUPMANAGELEFTTITLEWIDGET_H
#define BCSGROUPMANAGELEFTTITLEWIDGET_H

#include <QWidget>

class BCSGroupManageLeftTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCSGroupManageLeftTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // BCSGROUPMANAGELEFTTITLEWIDGET_H
