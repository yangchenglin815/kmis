#ifndef PAYMENTDETAILTITLE_H
#define PAYMENTDETAILTITLE_H

#include <QWidget>

class PaymentDetailTitle : public QWidget
{
    Q_OBJECT
public:
    explicit PaymentDetailTitle(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // PAYMENTDETAILTITLE_H
