#include "StatementMethodButton.h"

StatementMethodButton::StatementMethodButton(QWidget *parent)
    : QPushButton( parent )
{
    setUnSelectedSelf();
}

StatementMethodButton::~StatementMethodButton()
{

}

void StatementMethodButton::setSelectedSelf()
{
    this->setStyleSheet("QPushButton{color:#333333;font-size:12px;border-image: url(:/statementImage/tab_press.png);}"
                        "QPushButton:pressed{border-image: url(:/saleImage/tab_press.png);}");
}

void StatementMethodButton::setUnSelectedSelf()
{
    this->setStyleSheet("QPushButton{color:#ffffff;font-size:12px;border-image: url(:/statementImage/tab.png);}"
                        "QPushButton:pressed{border-image: url(:/statementImage/tab_press.png);}");
}

void StatementMethodButton::setLeftButton()
{
    this->setStyleSheet("QPushButton{color:#ffffff;font-size:12px;border-image: url(:/statementImage/left_normal.png);}"
                        "QPushButton:pressed{border-image: url(:/saleImage/left_press.png);}");
}

void StatementMethodButton::setRightButton()
{
    this->setStyleSheet("QPushButton{color:#ffffff;font-size:12px;border-image: url(:/statementImage/right_normal.png);}"
                        "QPushButton:pressed{border-image: url(:/statementImage/right_press.png);}");
}

PayWayInfoSet StatementMethodButton::getPayInfo()
{
    return m_stPayInfo;
}

void StatementMethodButton::setPayInfo( PayWayInfoSet stPayInfo )
{
    m_stPayInfo = stPayInfo;
}
