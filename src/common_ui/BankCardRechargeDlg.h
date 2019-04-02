#ifndef BANKCARDRECHARGEDLG_H
#define BANKCARDRECHARGEDLG_H

#include <QDialog>

/**
 *银行卡充值对话框
 */

namespace Ui {
class BankCardRechargeDlg;
}

class BankCardRechargeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BankCardRechargeDlg(QWidget *parent = 0);
    ~BankCardRechargeDlg();
private:
    Ui::BankCardRechargeDlg *ui;
};

#endif // BANKCARDRECHARGEDLG_H
