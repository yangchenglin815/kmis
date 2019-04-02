#ifndef PERSONALWALLETDLG_H
#define PERSONALWALLETDLG_H

#include <QDialog>

/**
 *个人钱包对话框
 */

namespace Ui {
class PersonalWalletDlg;
}

class PersonalWalletDlg : public QDialog
{
    Q_OBJECT

public:
    explicit PersonalWalletDlg(QWidget *parent = 0);
    ~PersonalWalletDlg();

private:
    Ui::PersonalWalletDlg *ui;
};

#endif // PERSONALWALLETDLG_H
