#ifndef RECEIVEORDERSTITLEWIDGET_H
#define RECEIVEORDERSTITLEWIDGET_H

#include <QWidget>

class ReceiveOrdersTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReceiveOrdersTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // RECEIVEORDERSTITLEWIDGET_H
