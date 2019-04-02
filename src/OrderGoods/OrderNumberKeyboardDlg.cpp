#include "OrderNumberKeyboardDlg.h"
#include "ui_OrderNumberKeyboardDlg.h"

OrderNumberKeyboardDlg::OrderNumberKeyboardDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderNumberKeyboardDlg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
}

OrderNumberKeyboardDlg::~OrderNumberKeyboardDlg()
{
    delete ui;
}



void OrderNumberKeyboardDlg::on_num0Button_clicked()
{
    emit sigClickNumber("0");
}

void OrderNumberKeyboardDlg::on_num1Button_clicked()
{
    emit sigClickNumber("1");
}

void OrderNumberKeyboardDlg::on_num2Button_clicked()
{
    emit sigClickNumber("2");
}

void OrderNumberKeyboardDlg::on_num3Button_clicked()
{
    emit sigClickNumber("3");
}

void OrderNumberKeyboardDlg::on_num4Button_clicked()
{
    emit sigClickNumber("4");
}

void OrderNumberKeyboardDlg::on_num5Button_clicked()
{
    emit sigClickNumber("5");
}

void OrderNumberKeyboardDlg::on_num6Button_clicked()
{
    emit sigClickNumber("6");
}

void OrderNumberKeyboardDlg::on_num7Button_clicked()
{
    emit sigClickNumber("7");
}

void OrderNumberKeyboardDlg::on_num8Button_clicked()
{
    emit sigClickNumber("8");
}

void OrderNumberKeyboardDlg::on_num9Button_clicked()
{
    emit sigClickNumber("9");
}

void OrderNumberKeyboardDlg::on_deleteButton_clicked()
{
    emit sigClickDelete();
}

void OrderNumberKeyboardDlg::on_enterButton_clicked()
{
    this->hide();
    emit sigClickEnter();
}
