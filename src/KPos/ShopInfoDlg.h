#ifndef SHOPINFODLG_H
#define SHOPINFODLG_H

#include <QDialog>

namespace Ui {
class ShopInfoDlg;
}

class ShopInfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ShopInfoDlg(QWidget *parent = 0);
    ~ShopInfoDlg();
    void setShopInfo(QString sCorpName, QString sShopName);
    QString getCorpName();
    QString getShopName();

private slots:
    void on_confirmButton_clicked();
    void on_cancellButton_clicked();

signals:
    void sigConfirm();
    void sigCanncel();

private:
    Ui::ShopInfoDlg *ui;
    QString m_sCorpName;
    QString m_sShopName;
};

#endif // SHOPINFODLG_H
