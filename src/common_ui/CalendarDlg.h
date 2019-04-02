#ifndef CALENDARDLG_H
#define CALENDARDLG_H

#include <QDialog>

/**
 *日历对话框
 */

namespace Ui {
class CalendarDlg;
}

class CalendarDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarDlg(QWidget *parent = 0);
    ~CalendarDlg();

private:
    Ui::CalendarDlg *ui;
};

#endif // CALENDARDLG_H
