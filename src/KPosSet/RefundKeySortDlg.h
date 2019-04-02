#ifndef REFUNDKEYSORTDLG_H
#define REFUNDKEYSORTDLG_H

#include <QDialog>

namespace Ui {
class RefundKeySortDlg;
}

class RefundKeySortDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RefundKeySortDlg(QWidget *parent = 0);
    ~RefundKeySortDlg();
    void reInit();

private slots:
    void on_key1Button_clicked();
    void on_key2Button_clicked();
    void on_key3Button_clicked();

private:
    void init();
    void initUI();
    void buttonClick(int nPos);

signals:
    void sigClickKeyId(int keyId, int nSetPagePos); // nSetPagePos位置从0开始
    void sigFinished(QList<int> m_sortKeyIDList);

private:
    Ui::RefundKeySortDlg *ui;
    QList<int> m_keyIDList;
    QList<int> m_sortKeyIDList;
    QList<QPushButton*> m_pushButtonList;
};

#endif // REFUNDKEYSORTDLG_H
