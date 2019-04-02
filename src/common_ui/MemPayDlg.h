#ifndef MEMPAYDLG_H
#define MEMPAYDLG_H

#include <QDialog>
#include <QKeyEvent>
#include <QLineEdit>

namespace Ui {
class MemPayDlg;
}

class MemPayDlg : public QDialog
{
    Q_OBJECT

public:
    explicit MemPayDlg(QWidget *parent = 0, QString strPayPwd = "" );
    ~MemPayDlg();

    QString getPayPwd();
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    void initCtrl();
    void initConnect();

    void setPayPwd();
    void clearPayPwd();
private slots:
    void slot_sure();
private:
    Ui::MemPayDlg *ui;
    QString m_sMemPwd;//会员密码
    QString m_sPayPwd;//支付密码

    QList<QLineEdit*> m_listPayPwd;
};

#endif // MEMPAYDLG_H
