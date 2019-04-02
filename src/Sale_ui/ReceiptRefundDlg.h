#ifndef RECEIPTREFUNDDLG_H
#define RECEIPTREFUNDDLG_H

#include <QDialog>
#include "../data/structData.h"

namespace Ui {
class ReceiptRefundDlg;
}

class ReceiptRefundDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiptRefundDlg(QWidget *parent = 0);
    ~ReceiptRefundDlg();
    void test();

private slots:
    void on_cashRefundButton_clicked();
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();

private:
    Ui::ReceiptRefundDlg *ui;
    QList<RefundWithReceiptInfo> m_refundInfoList;
    int m_nOnePageCount;
    int m_nCurPage;
    int m_nTotalPage;
};

#endif // RECEIPTREFUNDDLG_H
