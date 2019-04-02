#ifndef VIRTUALPAYBUTTON_H
#define VIRTUALPAYBUTTON_H

#include <QPushButton>
#include "enumData.h"
#include "setstructdata.h"

class VirtualPayButton : public QPushButton
{
    Q_OBJECT
public:
    explicit VirtualPayButton(QWidget *parent = 0);
    ~VirtualPayButton();
public:
    void setSelectedSelf();
    void setUnSelectedSelf();
    void setLeftButton();
    void setRightButton();

    PayWayInfoSet getPayInfo();
    void setPayInfo( PayWayInfoSet stPayInfo );
private:
    PayWayInfoSet m_stPayInfo;
};

#endif // VIRTUALPAYBUTTON_H
