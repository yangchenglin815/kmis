#ifndef RECEIPTDETIALINFOWIDGET_H
#define RECEIPTDETIALINFOWIDGET_H

#include <QWidget>
#include "structData.h"

class ReceiptDetialInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReceiptDetialInfoWidget(QWidget *parent = 0);
    void initData(const SaleHead& saleHead, const QList<PaymentDetailInfo>& paymentInfoList);

protected:
    void paintEvent(QPaintEvent* event);

private:
    SaleHead m_saleHead;
    QList<PaymentDetailInfo> m_paymentInfoList;
};

#endif // RECEIPTDETIALINFOWIDGET_H
