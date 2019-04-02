#ifndef BCSADDGOODSGROUPDLG_H
#define BCSADDGOODSGROUPDLG_H

#include <QDialog>

namespace Ui {
class BCSAddGoodsGroupDlg;
}

class BCSAddGoodsGroupDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BCSAddGoodsGroupDlg(QWidget *parent = 0);
    ~BCSAddGoodsGroupDlg();

private slots:
    void on_confirmButton_clicked(); // 确定

private:
    void initConnect();

signals:
    void sigAddGoodsGroup(QString sName);

private:
    Ui::BCSAddGoodsGroupDlg *ui;
};

#endif // BCSADDGOODSGROUPDLG_H
