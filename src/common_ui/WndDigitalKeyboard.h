#ifndef WNDDIGITALKEYBOARD_H
#define WNDDIGITALKEYBOARD_H

#include <QWidget>

namespace Ui {
class WndDigitalKeyboard;
}
/**
 * @brief The WndDigitalKeyboard class  数字键盘窗口
 */
class WndDigitalKeyboard : public QWidget
{
    Q_OBJECT

public:
    explicit WndDigitalKeyboard(QWidget *parent = 0);
    ~WndDigitalKeyboard();
    void clearDotButtonText();
    void changeToDialog(); // 变成dialog

private slots:
    void on_num1Button_clicked();
    void on_num2Button_clicked();
    void on_num3Button_clicked();
    void on_num4Button_clicked();
    void on_num5Button_clicked();
    void on_num6Button_clicked();
    void on_num7Button_clicked();
    void on_num8Button_clicked();
    void on_num9Button_clicked();
    void on_dotButton_clicked();
    void on_num0Button_clicked();
    void on_num00Button_clicked();
    void on_deleteButton_clicked();
    void on_clearButton_clicked();
    void on_confirmButton_clicked();

signals:
    void sigText(QString sNum);
    void sigDelete();
    void sigClear();
    void sigConfirm();

private:
    Ui::WndDigitalKeyboard *ui;
};

#endif // WNDDIGITALKEYBOARD_H
