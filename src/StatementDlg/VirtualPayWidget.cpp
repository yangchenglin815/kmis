#include "VirtualPayWidget.h"
#include "ui_VirtualPayWidget.h"

VirtualPayWidget::VirtualPayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VirtualPayWidget)
{
    ui->setupUi(this);

    initCtrl();
    initConnect();
}

VirtualPayWidget::~VirtualPayWidget()
{
    delete ui;
}

void VirtualPayWidget::setCurPayInfo(PayWayInfoSet stPayWayInfo)
{
    m_stCurPayInfo = stPayWayInfo;

    //设置当前选中的虚拟支付方式
    int nLen = m_listVirtualPayBtn.size();
    for( int i=0; i<nLen; ++i ) {
        if( m_listVirtualPayBtn[i]->getPayInfo().nPayType == m_stCurPayInfo.nPayType ) {
            m_listVirtualPayBtn[i]->setSelectedSelf();
            break;
        }
    }
}

PayWayInfoSet VirtualPayWidget::getCurPayInfo()
{
    return m_stCurPayInfo;
}

void VirtualPayWidget::initPayInfo()
{
    emit ui->virtualPay_01->click();
}

QLineEdit *VirtualPayWidget::getVirtualAmtEdit()
{
    return ui->factAmtVirtualEdit;
}

void VirtualPayWidget::setVirtualWidgetVisible(bool bVisible)
{
    ui->virtualWidget->setVisible(bVisible);
}

void VirtualPayWidget::clickPayBtn(int nBtnType)
{
    int nLen = m_listVirtualPayBtn.size();
    for( int i = 0; i<nLen; ++i )
    {
        if (m_listVirtualPayBtn[i]->getPayInfo().nPayType == nBtnType)
        {
            emit m_listVirtualPayBtn[i]->click();
        }
    }
}

void VirtualPayWidget::initCtrl()
{
    ui->virtualPay_08->hide();
    ui->virtualPay_09->hide();

    m_listVirtualPayBtn.append( ui->virtualPay_01 );
    m_listVirtualPayBtn.append( ui->virtualPay_02 );
    m_listVirtualPayBtn.append( ui->virtualPay_03 );
    m_listVirtualPayBtn.append( ui->virtualPay_04 );
    m_listVirtualPayBtn.append( ui->virtualPay_05 );
    m_listVirtualPayBtn.append( ui->virtualPay_06 );
    m_listVirtualPayBtn.append( ui->virtualPay_07 );

    initVirtualPayMethod();
}

//初始化虚拟支付方式
void VirtualPayWidget::initVirtualPayMethod()
{
    PayWayInfoSet payWayInfo;
    // 实体卡
    payWayInfo.nPayType = e_PayEntityCard; //实体卡
    payWayInfo.bStartUse = true; // 是否启动
    payWayInfo.bChargeMember = true; // 是否用于会员充值
    payWayInfo.bVirtualPay = true; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
    m_listVirtualPay.append( payWayInfo );

    // 银联支付
    payWayInfo.nPayType = e_PayUnion; //银联支付
    payWayInfo.bStartUse = true; // 是否启动
    payWayInfo.bChargeMember = true; // 是否用于会员充值
    payWayInfo.bVirtualPay = true; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
    m_listVirtualPay.append( payWayInfo );

    // 果麦
    payWayInfo.nPayType = e_PayFengCha; //果麦
    payWayInfo.bStartUse = true; // 是否启动
    payWayInfo.bChargeMember = true; // 是否用于会员充值
    payWayInfo.bVirtualPay = true; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
    m_listVirtualPay.append( payWayInfo );

    // 支票
    payWayInfo.nPayType = e_PayCheck; //支票
    payWayInfo.bStartUse = true; // 是否启动
    payWayInfo.bChargeMember = false; // 是否用于会员充值
    payWayInfo.bVirtualPay = true; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
    m_listVirtualPay.append( payWayInfo );

    // 欠单
    payWayInfo.nPayType = e_PayBills; //欠单
    payWayInfo.bStartUse = true; // 是否启动
    payWayInfo.bChargeMember = true; // 是否用于会员充值
    payWayInfo.bVirtualPay = true; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
    m_listVirtualPay.append( payWayInfo );

    // 市民卡
    payWayInfo.nPayType = e_PayCityCard; //市民卡
    payWayInfo.bStartUse = true; // 是否启动
    payWayInfo.bChargeMember = true; // 是否用于会员充值
    payWayInfo.bVirtualPay = true; // 是否虚拟支付
    payWayInfo.nDropType = eRounding; //　分的圆整方式,4表示不处理
    m_listVirtualPay.append( payWayInfo );

    // 其他
    payWayInfo.nPayType = e_PayOther;//其他
    payWayInfo.bStartUse = true;// 是否启动
    payWayInfo.bChargeMember = false; // 是否用于会员充值
    payWayInfo.bVirtualPay = true; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated;//= 分的圆整方式,4表示不处理
    m_listVirtualPay.append( payWayInfo );
}

void VirtualPayWidget::initConnect()
{
    int nLen = m_listVirtualPayBtn.size();
    for( int i = 0; i<nLen; ++i ) {
        m_listVirtualPayBtn[i]->setPayInfo( m_listVirtualPay[i] );//初始化按钮
        connect( m_listVirtualPayBtn[i], SIGNAL(clicked(bool)), this, SLOT( slot_virtualPayBtn() ) );
    }

    connect( ui->statementVirtualButton, SIGNAL(clicked(bool)), this, SIGNAL( sig_virtualStatement() ) );
}

void VirtualPayWidget::clearAllVirtualPayBtn()
{
    int nLen = m_listVirtualPayBtn.size();
    for( int i = 0; i<nLen; ++i ) {
        m_listVirtualPayBtn[i]->setUnSelectedSelf();
    }
}

void VirtualPayWidget::slot_virtualPayBtn()
{
    VirtualPayButton *pObj = (VirtualPayButton *)QObject::sender();
    if( pObj && pObj->getPayInfo().nPayType != m_stCurPayInfo.nPayType ) {
        clearAllVirtualPayBtn();
        pObj->setSelectedSelf();
        m_stCurPayInfo = pObj->getPayInfo();
    }
}
