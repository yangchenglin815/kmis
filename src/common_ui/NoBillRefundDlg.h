#ifndef NOBILLREFUNDDLG_H
#define NOBILLREFUNDDLG_H

#include <QDialog>

namespace Ui {
class NoBillRefundDlg;
}

class NoBillRefundDlg : public QDialog
{
    Q_OBJECT

public:
    explicit NoBillRefundDlg(QWidget *parent = 0);
    ~NoBillRefundDlg();

private:
    Ui::NoBillRefundDlg *ui;
};

#endif // NOBILLREFUNDDLG_H
