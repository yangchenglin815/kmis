#ifndef PAYMETHODBUTTON_H
#define PAYMETHODBUTTON_H

#include <QPushButton>
#include "enumData.h"
#include "setstructdata.h"

class PayMethodButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PayMethodButton( QWidget *parent );
    ~PayMethodButton();

    void setPayInfo( PayWayInfoSet stPayWayInfo );
    PayWayInfoSet getPayInfo();
    void setPayBtnSelected();
    void setPayBtnUnselected();
private:
    void setCashPaySelected();
    void setCashPayUnselected();
    void setUnionPaySelected();
    void setUnionPayUnselected();
    void setMemCardSelected();
    void setMemCardUnselected();
    void setPayStoreCardSelected();
    void setPayStoreCardUnselected();
    void setAlipaySelected();
    void setAlipayUnselected();
    void setApplePaySelected();
    void setApplePayUnselected();
    void setWechartPaySelected();
    void setWechartPayUnselected();
    void setJdWalletPaySelected();
    void setJdWalletPayUnselected();
private:
    EPayMethod m_ePayMethod;
    PayWayInfoSet m_stPayWayInfo;
};

#endif // PAYMETHODBUTTON_H
