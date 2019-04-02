#ifndef STATEMENTMETHODBUTTON_H
#define STATEMENTMETHODBUTTON_H

#include <QPushButton>
#include "enumData.h"
#include "setstructdata.h"

class StatementMethodButton : public QPushButton
{
    Q_OBJECT
public:
    explicit StatementMethodButton( QWidget *parent = 0 );
    ~StatementMethodButton();
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

#endif // STATEMENTMETHODBUTTON_H
