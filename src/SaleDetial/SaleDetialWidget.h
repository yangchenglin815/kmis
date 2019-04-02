#ifndef SALEDETIALWIDGET_H
#define SALEDETIALWIDGET_H

#include <QWidget>
#include "SaleDetialCtrl.h"

namespace Ui {
class SaleDetialWidget;
}

class SaleDetialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SaleDetialWidget(QWidget *parent = 0);
    ~SaleDetialWidget();
    void initSaleDetialList();

private:
    Ui::SaleDetialWidget *ui;
    SaleDetialCtrl* m_saleDetialCtrl;

signals:
    void sigReturnClicked();

private slots:
    void slot_showDetialPage();
    void slot_ReturnClicked();
    void slot_getSaleDetialOrder(int nCode, QString sMsg, QList<ReceiptInfo> InfoList);
    void slot_getSaleReceiptOrder(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> InfoList, QList<PaymentDetailInfo> paymentList);

private:
    void init();
    void initconnect();
};

#endif // SALEDETIALWIDGET_H
