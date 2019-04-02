#include "KPosDateInput.h"

KPosCalendarWidget* KPosDateInput::m_pCalendarWidget = NULL;

KPosDateInput::KPosDateInput(QWidget *parent)
    : QLineEdit(parent)
{

}

KPosDateInput::~KPosDateInput()
{
    if (m_pCalendarWidget != NULL)
    {
        m_pCalendarWidget->deleteLater();
        m_pCalendarWidget = NULL;
    }
}

void KPosDateInput::setCalendarPosition(int nXPos, int nYPos)
{
    m_nXPos = nXPos;
    m_nYPos = nYPos;
}

void KPosDateInput::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED( event )
//    QLineEdit::mousePressEvent(event);
    if (m_pCalendarWidget == NULL)
    {
        m_pCalendarWidget = new KPosCalendarWidget;
    }
    m_pCalendarWidget->move(m_nXPos, m_nYPos);
    m_pCalendarWidget->activateWindow();
    m_pCalendarWidget->showNormal();
}

