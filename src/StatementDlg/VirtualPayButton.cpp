#include "VirtualPayButton.h"

VirtualPayButton::VirtualPayButton(QWidget *parent)
    : QPushButton(parent)
{

    setUnSelectedSelf();
}

VirtualPayButton::~VirtualPayButton()
{

}

void VirtualPayButton::setSelectedSelf()
{
    this->setStyleSheet("QPushButton{color:#333333;font-size:12px;border-image: url(:/statementImage/virtualPay_press.jpg);}"
                        "QPushButton:pressed{border-image: url(:/statementImage/virtualPay_press.jpg);}");
}

void VirtualPayButton::setUnSelectedSelf()
{
    this->setStyleSheet("QPushButton{color:#333333;font-size:12px;border-image: url(:/statementImage/virtualPay_normal.jpg);}"
                        "QPushButton:pressed{border-image: url(:/statementImage/virtualPay_press.jpg);}");
}

void VirtualPayButton::setLeftButton()
{
//    this->setStyleSheet("QPushButton{color:#ffffff;font-size:12px;border-image: url(:/statementImage/left_normal.png);}"
//                        "QPushButton:pressed{border-image: url(:/saleImage/left_press.png);}");
}

void VirtualPayButton::setRightButton()
{
//    this->setStyleSheet("QPushButton{color:#ffffff;font-size:12px;border-image: url(:/statementImage/right_normal.png);}"
//                        "QPushButton:pressed{border-image: url(:/statementImage/right_press.png);}");
}

PayWayInfoSet VirtualPayButton::getPayInfo()
{
    return m_stPayInfo;
}

void VirtualPayButton::setPayInfo( PayWayInfoSet stPayInfo )
{
    m_stPayInfo = stPayInfo;
}
