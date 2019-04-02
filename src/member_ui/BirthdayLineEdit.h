#ifndef BIRTHDAYLINEEDIT_H
#define BIRTHDAYLINEEDIT_H

#include <QLineEdit>
#include <QEvent>
#include "BirthdayCalendarDlg.h"

class BirthdayLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit BirthdayLineEdit(QWidget *parent = 0);
    ~BirthdayLineEdit();

    bool isCalendarHidden();
    void setCalendarHidden( bool bHidden );
protected:
    bool eventFilter(QObject *watched, QEvent *event);
private:
    void initCtrl();
    void initConnect();
private:
    BirthdayCalendarDlg *m_pBirthdayCalendarDlg;
};

#endif // BIRTHDAYLINEEDIT_H
