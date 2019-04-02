#include "WndDigitalKeyboard.h"
#include "ui_WndDigitalKeyboard.h"

WndDigitalKeyboard::WndDigitalKeyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WndDigitalKeyboard)
{
    ui->setupUi(this);
}

WndDigitalKeyboard::~WndDigitalKeyboard()
{
    delete ui;
}

void WndDigitalKeyboard::clearDotButtonText()
{
    ui->dotButton->setText("");
}

void WndDigitalKeyboard::changeToDialog()
{

}

void WndDigitalKeyboard::on_num1Button_clicked()
{
    emit sigText("1");
}

void WndDigitalKeyboard::on_num2Button_clicked()
{
    emit sigText("2");
}

void WndDigitalKeyboard::on_num3Button_clicked()
{
    emit sigText("3");
}

void WndDigitalKeyboard::on_num4Button_clicked()
{
    emit sigText("4");
}

void WndDigitalKeyboard::on_num5Button_clicked()
{
    emit sigText("5");
}

void WndDigitalKeyboard::on_num6Button_clicked()
{
    emit sigText("6");
}

void WndDigitalKeyboard::on_num7Button_clicked()
{
    emit sigText("7");
}

void WndDigitalKeyboard::on_num8Button_clicked()
{
    emit sigText("8");
}

void WndDigitalKeyboard::on_num9Button_clicked()
{
    emit sigText("9");
}

void WndDigitalKeyboard::on_dotButton_clicked()
{
    if (ui->dotButton->text().isEmpty())
    {
        return;
    }
    emit sigText(".");
}

void WndDigitalKeyboard::on_num0Button_clicked()
{
    emit sigText("0");
}

void WndDigitalKeyboard::on_num00Button_clicked()
{
    emit sigText("00");
}

void WndDigitalKeyboard::on_deleteButton_clicked()
{
    emit sigDelete();
}

void WndDigitalKeyboard::on_clearButton_clicked()
{
    emit sigClear();
}

void WndDigitalKeyboard::on_confirmButton_clicked()
{
    emit sigConfirm();
}


