#ifndef RECEIPTDETIALTITLEWIDGET_H
#define RECEIPTDETIALTITLEWIDGET_H

#include <QWidget>

class ReceiptDetialTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReceiptDetialTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent* event);

};

#endif // RECEIPTDETIALTITLEWIDGET_H
