#ifndef HOMEKEYSORTDLG_H
#define HOMEKEYSORTDLG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class HomeKeySortDlg;
}

class HomeKeySortDlg : public QDialog
{
    Q_OBJECT

public:
    explicit HomeKeySortDlg(QWidget *parent = 0);
    ~HomeKeySortDlg();
    void reInit();

private slots:
    void on_key1Button_clicked();
    void on_key2Button_clicked();
    void on_key3Button_clicked();
    void on_key4Button_clicked();
    void on_key5Button_clicked();
    void on_key6Button_clicked();
    void on_key7Button_clicked();
    void on_key8Button_clicked();
    void on_key9Button_clicked();
    void on_key10Button_clicked();
    void on_key11Button_clicked();
    void on_key12Button_clicked();
    void on_key13Button_clicked();

private:
    void init();
    void initUI();
    void buttonClick(int nPos);

signals:
    void sigClickKeyId(int keyId, int nSetPagePos); // nSetPagePos位置从0开始
    void sigFinished(QList<int> m_sortKeyIDList);

private:
    Ui::HomeKeySortDlg *ui;
    QList<int> m_keyIDList;
    QList<int> m_sortKeyIDList;
    QList<QPushButton*> m_pushButtonList;
};

#endif // HOMEKEYSORTDLG_H
