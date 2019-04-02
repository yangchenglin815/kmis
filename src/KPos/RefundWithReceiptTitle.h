#ifndef REFUNDWITHRECEIPTTITLE_H
#define REFUNDWITHRECEIPTTITLE_H

#include <QWidget>

class RefundWithReceiptTitle : public QWidget
{
    Q_OBJECT
public:
    explicit RefundWithReceiptTitle(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // REFUNDWITHRECEIPTTITLE_H
