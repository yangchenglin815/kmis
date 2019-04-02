#ifndef NUMBERLINEEDIT_H
#define NUMBERLINEEDIT_H

#include <QLineEdit>

class NumberLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit NumberLineEdit(QWidget *parent = 0);
    void setNumberText(QString numText); // 设置完整数字串
    void appendNumberText(QString numText); // 追加一个数字
    void setReservePoint(int nReservPoint); // 设置小数点保留位数

private:
    int m_nReservePoint;
};

#endif // NUMBERLINEEDIT_H
