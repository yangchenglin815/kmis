#ifndef REFUNDWITHRECEIPTWIDGET_H
#define REFUNDWITHRECEIPTWIDGET_H

#include <QWidget>
#include <QList>
#include "../data/structData.h"

namespace Ui {
class RefundWithReceiptWidget;
}

class RefundWithReceiptWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RefundWithReceiptWidget(QWidget *parent = 0);
    ~RefundWithReceiptWidget();
    void test();

private:
    void generateRefundInfo();

private:
    Ui::RefundWithReceiptWidget *ui;
    QList<RefundWithReceiptInfo*> m_refundInfoList;
};

#endif // REFUNDWITHRECEIPTWIDGET_H
