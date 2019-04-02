#ifndef RECEIPTDETIALWIDGET_H
#define RECEIPTDETIALWIDGET_H

#include <QWidget>
//#include <receiptdata.h>
#include "structData.h"

namespace Ui {
class ReceiptDetialWidget;
}

class ReceiptDetialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiptDetialWidget(QWidget *parent = 0);
    ~ReceiptDetialWidget();
    void initData(const QList<SaleDetails>& itemInfoList, const SaleHead& saleHead, const QList<PaymentDetailInfo>& paymentInfoList);
    void test();

private slots:
    void on_nextButton_clicked();

    void on_printButton_clicked();

    void on_lastButton_clicked();

private:
    Ui::ReceiptDetialWidget *ui;
    QList<SaleDetails> m_InfoList;
    QList<PaymentDetailInfo> m_paymentDetialInfo;
    SaleHead m_saleHead;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;

private:
    void generateUI();
    void checkCurPageButtonState();
    void init();
    void initconnect();
};

#endif // RECEIPTDETIALWIDGET_H
