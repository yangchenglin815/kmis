#ifndef CLIENTCASHSUBMIT_H
#define CLIENTCASHSUBMIT_H

#include <QDialog>
#include <QLineEdit>
#include "../Bussiness/PosRegisterCtr.h"

namespace Ui {
class ClientCashSubmit;
}

class ClientCashSubmit : public QDialog
{
    Q_OBJECT

public:
    explicit ClientCashSubmit(QWidget *parent = 0);
    ~ClientCashSubmit();
    void init_connect();
    void setCtrl(PosRegisterCtr* pPosRegisterCtr);
    QString getSumMoney();
    void clearData();

protected:
    void keyPressEvent(QKeyEvent *event);

signals:
    void sig_closeWnd();

public slots:
    void slot_dlg_close();
    void slot_push_from();
    void slot_setText(QString strText);
    void slot_deleteValue();
    void slot_clearZero();
    void slot_Confirm();
private slots:
    void push_and_close();
    void mian_close();
    void client_wnd_close();

    void on_bills_100_textChanged(const QString &arg1);
    void on_bills_50_textChanged(const QString &arg1);
    void on_bills_20_textChanged(const QString &arg1);
    void on_bills_10_textChanged(const QString &arg1);
    void on_bills_5_textChanged(const QString &arg1);
    void on_bills_1_textChanged(const QString &arg1);
    void on_bills_0_5_textChanged(const QString &arg1);
    void on_bills_0_1_textChanged(const QString &arg1);
    void slot_onUploadClientCashSubmit(int nCode, QString sMsg);
private:
    void firstClick();
    bool getCurFocusWnd(QLineEdit *&pEditWnd);
    void calculateTotalAmount();

signals:
    void sigClose();

private:
    Ui::ClientCashSubmit *ui;
    bool m_bFirst;
    PosRegisterCtr* m_pPosRegisterCtr;
    QString m_sSubmitAmount;
};

#endif // CLIENTCASHSUBMIT_H
