#ifndef KPOSDATEINPUT_H
#define KPOSDATEINPUT_H

#include <QLineEdit>
#include "KPosCalendarWidget.h"

class KPosDateInput : public QLineEdit
{
    Q_OBJECT
public:
    explicit KPosDateInput(QWidget *parent = 0);
    ~KPosDateInput();
    void setCalendarPosition(int nXPos, int nYPos);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    static KPosCalendarWidget* m_pCalendarWidget;
    int m_nXPos;
    int m_nYPos;
};

#endif // KPOSDATEINPUT_H
