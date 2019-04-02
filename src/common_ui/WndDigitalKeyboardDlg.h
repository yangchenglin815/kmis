#ifndef WNDDIGITALKEYBOARDDLG_H
#define WNDDIGITALKEYBOARDDLG_H

#include <QDialog>

namespace Ui {
class WndDigitalKeyboardDlg;
}

class WndDigitalKeyboardDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WndDigitalKeyboardDlg(QWidget *parent = 0);
    ~WndDigitalKeyboardDlg();

private:
    void initConnect();

signals:
    void sigText(QString sNum);
    void sigDelete();
    void sigClear();
    void sigConfirm();

private:
    Ui::WndDigitalKeyboardDlg *ui;
};

#endif // WNDDIGITALKEYBOARDDLG_H
