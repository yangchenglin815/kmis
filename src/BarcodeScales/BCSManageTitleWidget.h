#ifndef BCSMANAGETITLEWIDGET_H
#define BCSMANAGETITLEWIDGET_H

#include <QWidget>

class BCSManageTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCSManageTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // BCSMANAGETITLEWIDGET_H
