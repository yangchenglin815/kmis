#ifndef BIRTHDAYCALENDARDLG_H
#define BIRTHDAYCALENDARDLG_H

#include <QWidget>

namespace Ui {
class BirthdayCalendarDlg;
}

class BirthdayCalendarDlg : public QWidget
{
    Q_OBJECT

public:
    explicit BirthdayCalendarDlg(QWidget *parent = 0);
    ~BirthdayCalendarDlg();

private:
    Ui::BirthdayCalendarDlg *ui;
};

#endif // BIRTHDAYCALENDARDLG_H
