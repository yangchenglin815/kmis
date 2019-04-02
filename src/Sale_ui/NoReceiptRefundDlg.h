#ifndef NORECEIPTREFUNDDLG_H
#define NORECEIPTREFUNDDLG_H

#include <QDialog>

namespace Ui {
class NoReceiptRefundDlg;
}

class NoReceiptRefundDlg : public QDialog
{
    Q_OBJECT

public:
    explicit NoReceiptRefundDlg(QWidget *parent = 0);
    ~NoReceiptRefundDlg();
    void setRefundCash(float fRefundCash);
    void setRefundReasonId(int nReasonId);
    void showIntegralMoney(float fMoney);
    void hideIntegralMoney();

private slots:
    void on_confirmButton_clicked();

private:
    void initConnect();

signals:
    void sigConfirm(int nReasonId);

private:
    Ui::NoReceiptRefundDlg *ui;
    int m_nRefundReasonId;
    float m_nIntegralMoney;
};

#endif // NORECEIPTREFUNDDLG_H
