#include "SwitchButton.h"

SwitchButton::SwitchButton(QWidget *parent)
    : QPushButton(parent)
    , m_bOpen(false)
{
    initConnect();
}

void SwitchButton::setOpenState(bool bOpen)
{
    m_bOpen = bOpen;
    if (bOpen)
    {
        this->setStyleSheet("border-image: url(:/kPosSetImage/on.png)");
    }
    else
    {
        this->setStyleSheet("border-image: url(:/kPosSetImage/off.png)");
    }
}

bool SwitchButton::isOpen()
{
    return m_bOpen;
}

void SwitchButton::slot_clicked()
{
    setOpenState(!m_bOpen);
}

void SwitchButton::initConnect()
{
    connect(this, SIGNAL(clicked()), this, SLOT(slot_clicked()));
}
