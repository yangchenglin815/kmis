#include "PayMethodButton.h"

PayMethodButton::PayMethodButton(QWidget *parent)
    : QPushButton( parent )
    , m_ePayMethod( PayNull )
{

}

PayMethodButton::~PayMethodButton()
{

}

void PayMethodButton::setPayInfo( PayWayInfoSet stPayWayInfo )
{
    show();
    m_stPayWayInfo = stPayWayInfo;

    setPayBtnUnselected();
}

PayWayInfoSet PayMethodButton::getPayInfo()
{
    return m_stPayWayInfo;
}

void PayMethodButton::setPayBtnSelected()
{
    switch( m_stPayWayInfo.nPayType ) {
    case PayNull:
        hide();
        break;
    case PayCash:
        setCashPaySelected();
        break;
    case UnionPay:
        setUnionPaySelected();
        break;
    case PayMemCard:
        setMemCardSelected();
        break;
    case PayStoreCard:
        setPayStoreCardSelected();
        break;
    case PayAlipay:
        setAlipaySelected();
        break;
    case PayWeChat:
        setWechartPaySelected();
        break;
    case ApplePay:
        setApplePaySelected();
        break;
    case JdWallet:
        setJdWalletPaySelected();
        break;
    case Coupon:
        break;
    default:
        break;
    }
}

void PayMethodButton::setPayBtnUnselected()
{
    switch( m_stPayWayInfo.nPayType ) {
    case PayNull:
        hide();
        break;
    case PayCash:
        setCashPayUnselected();
        break;
    case UnionPay:
        setUnionPayUnselected();
        break;
    case PayMemCard:
        setMemCardUnselected();
        break;
    case PayStoreCard:
        setPayStoreCardUnselected();
        break;
    case PayAlipay:
        setAlipayUnselected();
        break;
    case PayWeChat:
        setWechartPayUnselected();
        break;
    case ApplePay:
        setApplePayUnselected();
        break;
    case JdWallet:
        setJdWalletPayUnselected();
        break;
    case Coupon:
        break;
    default:
        break;
    }
}

void PayMethodButton::setCashPaySelected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/cash_selected.png);}" );
}

void PayMethodButton::setCashPayUnselected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/cash_normal.png);}" );
}

void PayMethodButton::setUnionPaySelected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/unionPay_selected.png);}" );
}

void PayMethodButton::setUnionPayUnselected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/unionPay_noraml.png);}" );
}

void PayMethodButton::setMemCardSelected()
{

}

void PayMethodButton::setMemCardUnselected()
{

}

void PayMethodButton::setPayStoreCardSelected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/storeCard_selected.png);}" );
}

void PayMethodButton::setPayStoreCardUnselected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/storeCard_normal.png);}" );
}

void PayMethodButton::setAlipaySelected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/Alipay_selected.png);}" );
}

void PayMethodButton::setAlipayUnselected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/Alipay_normal.png);}" );
}

void PayMethodButton::setApplePaySelected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/applePay_seleted.png);}" );
}

void PayMethodButton::setApplePayUnselected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/applePay_normal.png);}" );
}

void PayMethodButton::setWechartPaySelected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/wechartPay_selected.png);}" );
}

void PayMethodButton::setWechartPayUnselected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/wechartPay_normal.png);}" );
}

void PayMethodButton::setJdWalletPaySelected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/jdWallet_selected.png);}" );
}

void PayMethodButton::setJdWalletPayUnselected()
{
    this->setStyleSheet("QPushButton{border-image: url(:/shareImages/jdWallet_normal.png);}" );
}
