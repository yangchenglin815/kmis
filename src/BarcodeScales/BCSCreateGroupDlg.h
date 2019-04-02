#ifndef BCSCREATEGROUPDLG_H
#define BCSCREATEGROUPDLG_H

#include <QDialog>

namespace Ui {
class BCSCreateGroupDlg;
}

class BCSCreateGroupDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSCreateGroupDlg(QWidget *parent = 0);
    ~BCSCreateGroupDlg();

private:
    Ui::BCSCreateGroupDlg *ui;
};

#endif // BCSCREATEGROUPDLG_H
