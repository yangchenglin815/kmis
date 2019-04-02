#ifndef CASHIERPAYMENTDLG_H
#define CASHIERPAYMENTDLG_H

#include <QDialog>

namespace Ui {
class CashierPaymentDlg;
}

class CashierPaymentDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CashierPaymentDlg(QWidget *parent = 0);
    ~CashierPaymentDlg();

private:
    Ui::CashierPaymentDlg *ui;
};

#endif // CASHIERPAYMENTDLG_H
