#ifndef ODDCHANGEDLG_H
#define ODDCHANGEDLG_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class OddChangeDlg;
}

class OddChangeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit OddChangeDlg(QWidget *parent = 0);
    ~OddChangeDlg();
public:
    void setTitleText( QString strTitleText );
    void setData( float fTotalMoney, float fReceivedAmt, float fOddChange );
signals:
    void sig_wnd_close();
private:
    void initCtrl();
private:
    Ui::OddChangeDlg *ui;

    QTimer *m_pTimerCloseWnd;
};

#endif // ODDCHANGEDLG_H
