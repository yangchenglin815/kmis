#ifndef FUNCDLG_H
#define FUNCDLG_H

#include <QDialog>

namespace Ui {
class FuncDlg;
}

class FuncDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FuncDlg(QWidget *parent = 0);
    ~FuncDlg();

private:
    Ui::FuncDlg *ui;
};

#endif // FUNCDLG_H
