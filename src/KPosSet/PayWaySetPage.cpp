#include "PayWaySetPage.h"
#include "ui_PayWaySetPage.h"
#include "EnumToString.h"
#include "globaldata.h"
#include <QDebug>

PayWaySetPage::PayWaySetPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PayWaySetPage)
{
    ui->setupUi(this);
    ui->firstGrideWidget->setColumnNum(5);
    ui->firstGrideWidget->setRowNum(2);
    pingbi();
    init();

    ui->virtualButton->setOpenState(false);
    ui->virtualMemberButton->setOpenState(false);
//    ui->virtualButton->setEnabled(false);
//    ui->virtualMemberButton->setEnabled(false);
}

PayWaySetPage::~PayWaySetPage()
{
    delete ui;
}

void PayWaySetPage::somePlacePressed(const QPoint &globalPoint)
{
    QPoint localPoint = this->mapFromGlobal(globalPoint);
    if (!ui->cashComBox->geometry().contains(localPoint))
    {
        ui->cashComBox->hideListWidget();
    }
}

void PayWaySetPage::uploadData(KPosSet &kPosSet)
{
    kPosSet.payWaySet.bChanged = false;

    PayWaySet tempPayWay = m_defaultPayWay;
    tempPayWay.bChanged = false;
    int nLen = tempPayWay.payWayInfoSetList.length();
    PayWayInfoSet payWayInfoSet;
    for( int i=0; i < nLen; i++) //目前只显示5列，没有做翻页
    {
        payWayInfoSet = tempPayWay.payWayInfoSetList[i];
        if (payWayInfoSet.nPayType == e_PayCash) //现金支付
        {
            int nDropType = EnumToString::dropTypeToInt(ui->cashComBox->getContent());
            if (payWayInfoSet.nDropType != nDropType)
            {
                tempPayWay.bChanged = true;
                tempPayWay.payWayInfoSetList[i].nDropType = nDropType;
            }
        }
        else if (payWayInfoSet.nPayType == e_PayMemCard) //会员卡支付
        {
            bool bStartUse = ui->memberStartButton->isOpen();
            if (payWayInfoSet.bStartUse != bStartUse)
            {
                tempPayWay.bChanged = true;
                tempPayWay.payWayInfoSetList[i].bStartUse = bStartUse;
            }
        }
        else if (payWayInfoSet.nPayType == e_PayAlipay) //支付宝
        {
            bool bStartUse = ui->alipayStartButton->isOpen();
            bool bChargeMember = ui->alipayMemberButton->isOpen();
//            bool bVirtualPay = ui->alipayVirtualButton->isOpen();
            if ((payWayInfoSet.bStartUse != bStartUse)
                    || (payWayInfoSet.bChargeMember != bChargeMember)
                    /*|| (payWayInfoSet.bVirtualPay != bVirtualPay)*/)
            {
                tempPayWay.bChanged = true;
                tempPayWay.payWayInfoSetList[i].bStartUse = bStartUse;
                tempPayWay.payWayInfoSetList[i].bChargeMember = bChargeMember;
//                tempPayWay.payWayInfoSetList[i].bVirtualPay = bVirtualPay;
            }
        }
        else if (payWayInfoSet.nPayType == e_PayWeChat) //微信支付
        {
            bool bStartUse = ui->weChatStartButton->isOpen();
            bool bChargeMember = ui->weChatMemberButton->isOpen();
//            bool bVirtualPay = ui->weChatVirtualButton->isOpen();
            if ((payWayInfoSet.bStartUse != bStartUse)
                    || (payWayInfoSet.bChargeMember != bChargeMember)
                    /*|| (payWayInfoSet.bVirtualPay != bVirtualPay)*/)
            {
                tempPayWay.bChanged = true;
                tempPayWay.payWayInfoSetList[i].bStartUse = bStartUse;
                tempPayWay.payWayInfoSetList[i].bChargeMember = bChargeMember;
//                tempPayWay.payWayInfoSetList[i].bVirtualPay = bVirtualPay;
            }
        }
        else if (payWayInfoSet.nPayType == e_virtualPay)
        {
            bool bStartUse = ui->virtualButton->isOpen();
            bool bChargeMember = ui->virtualMemberButton->isOpen();
//            bool bVirtualPay = ui->weChatVirtualButton->isOpen();
            if ((payWayInfoSet.bStartUse != bStartUse)
                    || (payWayInfoSet.bChargeMember != bChargeMember)
                    /*|| (payWayInfoSet.bVirtualPay != bVirtualPay)*/)
            {
                tempPayWay.bChanged = true;
                tempPayWay.payWayInfoSetList[i].bStartUse = bStartUse;
                tempPayWay.payWayInfoSetList[i].bChargeMember = bChargeMember;
//                tempPayWay.payWayInfoSetList[i].bVirtualPay = bVirtualPay;
            }
        }
    }

    if (tempPayWay.bChanged)
    {
        kPosSet.payWaySet = tempPayWay;
    }
}

void PayWaySetPage::initData(const PayWaySet &payWaySet)
{
    m_defaultPayWay = payWaySet;
    int nLen = payWaySet.payWayInfoSetList.length();
    PayWayInfoSet payWayInfoSet;
    int count = 0;
    for( int i = 0; (i < nLen) && (count < 5); i++) //目前只显示5列，没有做翻页
    {
        count++;
        payWayInfoSet = m_defaultPayWay.payWayInfoSetList[i];
        if (payWayInfoSet.nPayType == e_PayCash) //现金支付
        {
            ui->cashComBox->setContent(EnumToString::dropTypeToString(payWayInfoSet.nDropType));
        }
        else if (payWayInfoSet.nPayType == e_PayMemCard) //会员卡支付
        {
            ui->memberStartButton->setOpenState(payWayInfoSet.bStartUse);
        }
        else if (payWayInfoSet.nPayType == e_PayAlipay) //支付宝
        {
            ui->alipayStartButton->setOpenState(payWayInfoSet.bStartUse);
            ui->alipayMemberButton->setOpenState(payWayInfoSet.bChargeMember);
//            ui->alipayVirtualButton->setOpenState(payWayInfoSet.bVirtualPay);
        }
        else if (payWayInfoSet.nPayType == e_PayWeChat) //微信支付
        {
            ui->weChatStartButton->setOpenState(payWayInfoSet.bStartUse);
            ui->weChatMemberButton->setOpenState(payWayInfoSet.bChargeMember);
//            ui->weChatVirtualButton->setOpenState(payWayInfoSet.bVirtualPay);
        }
        else if (payWayInfoSet.nPayType == e_virtualPay) // 虚拟支付
        {
            ui->virtualButton->setOpenState(payWayInfoSet.bStartUse);
            ui->virtualMemberButton->setOpenState(payWayInfoSet.bChargeMember);
        }
        else
        {
            count--;
            continue;
        }
    }
}

void PayWaySetPage::init()
{
    QList<QString> strList;
    strList<<QStringLiteral("舍弃")<<QStringLiteral("四舍五入")<<QStringLiteral("进位");
    ui->cashComBox->initListWidget(strList);
}

void PayWaySetPage::pingbi()
{
    ui->nextPageButton->hide();
}


