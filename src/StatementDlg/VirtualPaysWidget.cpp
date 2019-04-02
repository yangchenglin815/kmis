#include "VirtualPaysWidget.h"
#include "ui_VirtualPaysWidget.h"
#include <QDebug>
#include <QMessageBox>

static QString sNormalQss = "QPushButton{color:#333333;font-size:12px;border-image: url(:/statementImage/virtualPay_normal.jpg);}";
static QString sPressQss = "QPushButton{color:#333333;font-size:12px;border-image: url(:/statementImage/virtualPay_press.jpg);}";

VirtualPaysWidget::VirtualPaysWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VirtualPaysWidget)
    , m_pressedButton(NULL)
{
    ui->setupUi(this);
    init();
}

VirtualPaysWidget::~VirtualPaysWidget()
{
    delete ui;
}

void VirtualPaysWidget::setFactorAmt(QString sText)
{
    ui->factAmtVirtualEdit->setText(sText);
}

QString VirtualPaysWidget::getFactorAmt()
{
    return ui->factAmtVirtualEdit->text();
}

void VirtualPaysWidget::initPayButtons(const QList<VirtualPayInfo> &payList)
{
    m_virtualPayMap.clear();
    int nLen = payList.length();
    PayWayInfoSet payWayInfoSet;
    for (int i = 0; (i < nLen) && (i < 9); i++) // 目前没有做翻页，虚拟支付最多9个
    {
        m_buttons[i]->setEnabled(true);
        m_buttons[i]->setText(payList[i].sName);
        payWayInfoSet.nPayType = payList[i].sCode.toInt(); // 支付类型
        payWayInfoSet.bStartUse = true; // 是否启动
        payWayInfoSet.bChargeMember = false; // 是否用于会员充值
        payWayInfoSet.bVirtualPay = true; // 是否虚拟支付
        payWayInfoSet.nDropType = eDropNull; //　分的圆整方式,4表示不处理
        payWayInfoSet.sPayName = payList[i].sName;

        m_virtualPayMap.insert(m_buttons[i], payWayInfoSet);
    }

    for (int i = nLen; i < 9; i++)
    {
        m_buttons[i]->setEnabled(false);
        m_buttons[i]->setText("");
    }
}

QString VirtualPaysWidget::getCurPayName()
{
    if (m_pressedButton != NULL)
    {
        return m_virtualPayMap.value(m_pressedButton).sPayName;
    }
    else
    {
        return QStringLiteral("虚拟支付");
    }
}

PayWayInfoSet VirtualPaysWidget::getCurPayWayInfo()
{
    return m_virtualPayMap.value(m_pressedButton);
}

void VirtualPaysWidget::slot_buttonClick()
{
    QPushButton* pButton = dynamic_cast<QPushButton*>(QObject::sender());
    if (pButton != m_pressedButton)
    {
        if (m_pressedButton != NULL)
        {
           m_pressedButton->setStyleSheet(sNormalQss);
        }
    }
    m_pressedButton = pButton;
    if (m_pressedButton != NULL)
    {
       m_pressedButton->setStyleSheet(sPressQss);
    }
}

void VirtualPaysWidget::on_confirmButton_clicked()
{
    if (m_pressedButton == NULL)
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("请选择虚拟支付类型。"));
        return;
    }

    emit sigConfirm();
}

void VirtualPaysWidget::init()
{
    m_buttons.append(ui->virtualPay_01);
    m_buttons.append(ui->virtualPay_02);
    m_buttons.append(ui->virtualPay_03);
    m_buttons.append(ui->virtualPay_04);
    m_buttons.append(ui->virtualPay_05);
    m_buttons.append(ui->virtualPay_06);
    m_buttons.append(ui->virtualPay_07);
    m_buttons.append(ui->virtualPay_08);
    m_buttons.append(ui->virtualPay_09);

    int nLen = m_buttons.length();
    for (int i = 0; i < nLen; i++)
    {
        m_buttons[i]->setStyleSheet(sNormalQss);
        connect(m_buttons[i], SIGNAL(clicked()), this, SLOT(slot_buttonClick()));
    }
    if (nLen >= 1)
    {
        m_buttons[0]->setStyleSheet(sPressQss);
        m_pressedButton = m_buttons[0];
    }
}
