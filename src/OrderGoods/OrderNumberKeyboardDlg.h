#ifndef ORDERNUMBERKEYBOARDDLG_H
#define ORDERNUMBERKEYBOARDDLG_H

#include <QDialog>

namespace Ui {
class OrderNumberKeyboardDlg;
}

class OrderNumberKeyboardDlg : public QDialog
{
    Q_OBJECT

public:
    explicit OrderNumberKeyboardDlg(QWidget *parent = 0);
    ~OrderNumberKeyboardDlg();

private slots:
    void on_num0Button_clicked();
    void on_num1Button_clicked();
    void on_num2Button_clicked();
    void on_num3Button_clicked();
    void on_num4Button_clicked();
    void on_num5Button_clicked();
    void on_num6Button_clicked();
    void on_num7Button_clicked();
    void on_num8Button_clicked();
    void on_num9Button_clicked();
    void on_deleteButton_clicked();
    void on_enterButton_clicked();

signals:
    void sigClickNumber(QString nNum);
    void sigClickDelete();
    void sigClickEnter();

private:
    Ui::OrderNumberKeyboardDlg *ui;
};

#endif // ORDERNUMBERKEYBOARDDLG_H
