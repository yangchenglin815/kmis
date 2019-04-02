#include "ParamsSetPage.h"
#include "ui_ParamsSetPage.h"

ParamsSetPage::ParamsSetPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ParamsSetPage)
//    , m_pKeyboardDlg(NULL)
{
    ui->setupUi(this);
    ui->updateOtherPosButton->hide();// 暂时屏蔽显示
//    ui->saleByPriceLineEdit->installEventFilter(this);
//    m_pKeyboardDlg = new WndDigitalKeyboardDlg;
//    connect(m_pKeyboardDlg, SIGNAL(sigText(QString)), this, SLOT(slot_Text(QString)));
//    connect(m_pKeyboardDlg, SIGNAL(sigDelete()), this, SLOT(slot_Delete()));
//    connect(m_pKeyboardDlg, SIGNAL(sigClear()), this, SLOT(slot_Clear()));
//    connect(m_pKeyboardDlg, SIGNAL(sigConfirm()), this, SLOT(slot_Confirm()));
}

ParamsSetPage::~ParamsSetPage()
{
    delete ui;
}

void ParamsSetPage::initData(const ParamsSet &paramsSet)
{
    m_defaultParamsSet = paramsSet;

    initSystemParams(paramsSet);

//    ui->saleByPriceButton->setOpenState(paramsSet.shopSetParams.bSaleByPrice);
//    ui->saleByPriceLineEdit->setText(paramsSet.shopSetParams.sPriceRange);
    ui->changePriceButton->setOpenState(paramsSet.shopSetParams.bChangePriceBySeller);
    ui->createGoodsButton->setOpenState(paramsSet.shopSetParams.bCreateGoodsBySeller);
    ui->openCashboxButton->setOpenState(paramsSet.shopSetParams.bOpenCashboxBySeller);
    ui->sellZeroPriceGoodsButton->setOpenState(paramsSet.shopSetParams.bSellZeroGoodsBySeller);
    ui->handinCashButton->setOpenState(paramsSet.shopSetParams.bHandinCashBySeller);
    ui->chooseSalesmanButton->setOpenState(paramsSet.shopSetParams.bChooseSeller);
    ui->nameWidget->setText(paramsSet.shopSetParams.sReceiptShopName);
    // 最大挂单数
    int nPendingListMaxLength = paramsSet.shopSetParams.nPendingListMaxLength;
    if (nPendingListMaxLength == 10)
    {
        ui->pending1RButton->setChecked(true);
    }
    else if (nPendingListMaxLength == 20)
    {
        ui->pending2RButton->setChecked(true);
    }
    else if (nPendingListMaxLength == 30)
    {
        ui->pending3RButton->setChecked(true);
    }
    else
    {
        ui->pending0RButton->setChecked(true);
        m_defaultParamsSet.shopSetParams.nPendingListMaxLength = 0;
    }

    // 锁屏等待时间
    int nLockWaitTimeLenth = paramsSet.shopSetParams.nLockWaitTimeLenth;
    if (nLockWaitTimeLenth == 1)
    {
        ui->lock1RButton->setChecked(true);
    }
    else if (nLockWaitTimeLenth == 2)
    {
        ui->lock2RButton->setChecked(true);
    }
    else if (nLockWaitTimeLenth == 5)
    {
        ui->lock3RButton->setChecked(true);
    }
    else if (nLockWaitTimeLenth == 30)
    {
        ui->lock4RButton->setChecked(true);
    }
    else
    {
        ui->lock0RButton->setChecked(true);
        m_defaultParamsSet.shopSetParams.nLockWaitTimeLenth = 0;
    }
}

void ParamsSetPage::initSystemParams(const ParamsSet &paramsSet)
{
    ui->discountBaseMemberLabel->setText(paramsSet.systemSetParams.bDiscountOnMember ? QStringLiteral("会员价") : QStringLiteral("原价"));
//    ui->discountBaseDiscountLabel->setText(paramsSet.systemSetParams.bDiscountOnDiscount ? QStringLiteral("是") : QStringLiteral("否"));
    ui->discardZeroLabel->setText(paramsSet.systemSetParams.bDiscardZero ? QStringLiteral("是") : QStringLiteral("否"));
    ui->maxGoodsSaleNumberLabel->setText(QString::number(paramsSet.systemSetParams.nGoodsMaxNumber));
    ui->maxSaveDaysLabel->setText(QString(QStringLiteral("%1天")).arg(paramsSet.systemSetParams.nDataSaveDays));
    ui->fillReasonForRefundLabel->setText(paramsSet.systemSetParams.bFillReasonForRefund ? QStringLiteral("是") : QStringLiteral("否"));
    ui->priceSaleLabel->setText(paramsSet.systemSetParams.bPriceSale ? QStringLiteral("是") : QStringLiteral("否"));
    ui->priceSaleLimitLabel->setText(QString::number(paramsSet.systemSetParams.nPriceSaleLimit));
}

void ParamsSetPage::uploadData(KPosSet &kPosSet)
{
    kPosSet.paramsSet.bChanged = false;

    int nChanged = 0;
    ShopSetParams tempShopSetParams = m_defaultParamsSet.shopSetParams;
    // 收银员是否有打折改价权限
    tempShopSetParams.bChangePriceBySeller = ui->changePriceButton->isOpen();
    nChanged += (tempShopSetParams.bChangePriceBySeller != m_defaultParamsSet.shopSetParams.bChangePriceBySeller);

    // 收银员是否有快速建档权限
    tempShopSetParams.bCreateGoodsBySeller = ui->createGoodsButton->isOpen();
    nChanged += (tempShopSetParams.bCreateGoodsBySeller != m_defaultParamsSet.shopSetParams.bCreateGoodsBySeller);

    // 收银员是否有开钱箱权限
    tempShopSetParams.bOpenCashboxBySeller = ui->openCashboxButton->isOpen();
    nChanged += (tempShopSetParams.bOpenCashboxBySeller != m_defaultParamsSet.shopSetParams.bOpenCashboxBySeller);

    // 前台是否允许销售售价为零的商品
    tempShopSetParams.bSellZeroGoodsBySeller = ui->sellZeroPriceGoodsButton->isOpen();
    nChanged += (tempShopSetParams.bSellZeroGoodsBySeller != m_defaultParamsSet.shopSetParams.bSellZeroGoodsBySeller);

    // 收银员是否交款
    tempShopSetParams.bHandinCashBySeller = ui->handinCashButton->isOpen();
    nChanged += (tempShopSetParams.bHandinCashBySeller != m_defaultParamsSet.shopSetParams.bHandinCashBySeller);

    // 结算是否选择业务员
    tempShopSetParams.bChooseSeller = ui->chooseSalesmanButton->isOpen();
    nChanged += (tempShopSetParams.bChooseSeller != m_defaultParamsSet.shopSetParams.bChooseSeller);

    // 最大挂单数
    int nPendingListMaxLength = 0;
    if (ui->pending1RButton->isChecked())
    {
        nPendingListMaxLength = 10;
    }
    else if (ui->pending2RButton->isChecked())
    {
        nPendingListMaxLength = 20;
    }
    else if (ui->pending3RButton->isChecked())
    {
        nPendingListMaxLength = 30;
    }
    tempShopSetParams.nPendingListMaxLength = nPendingListMaxLength;
    nChanged += (tempShopSetParams.nPendingListMaxLength != m_defaultParamsSet.shopSetParams.nPendingListMaxLength);

    // 锁屏等待时间
    int nLockWaitTimeLenth = 0;
    if (ui->lock1RButton->isChecked())
    {
        nLockWaitTimeLenth = 1;
    }
    else if (ui->lock2RButton->isChecked())
    {
        nLockWaitTimeLenth = 2;
    }
    else if (ui->lock3RButton->isChecked())
    {
        nLockWaitTimeLenth = 5;
    }
    else if (ui->lock4RButton->isChecked())
    {
        nLockWaitTimeLenth = 30;
    }
    tempShopSetParams.nLockWaitTimeLenth = nLockWaitTimeLenth;
    nChanged += (tempShopSetParams.nLockWaitTimeLenth != m_defaultParamsSet.shopSetParams.nLockWaitTimeLenth);

    tempShopSetParams.sReceiptShopName = ui->nameWidget->getText().trimmed();
    nChanged += (tempShopSetParams.sReceiptShopName != m_defaultParamsSet.shopSetParams.sReceiptShopName);

//    tempShopSetParams.bSaleByPrice = ui->saleByPriceButton->isOpen(); // 是否输入价格销售
//    nChanged += (tempShopSetParams.bSaleByPrice != m_defaultParamsSet.shopSetParams.bSaleByPrice);
//    tempShopSetParams.sPriceRange = ui->saleByPriceLineEdit->text().trimmed(); // 价格范围
//    nChanged += (tempShopSetParams.sPriceRange != m_defaultParamsSet.shopSetParams.sPriceRange);

    if (nChanged > 0)
    {
        kPosSet.paramsSet.shopSetParams = tempShopSetParams;
        kPosSet.paramsSet.bChanged = true;
    }
}

//bool ParamsSetPage::eventFilter(QObject *watched, QEvent *event)
//{
//    if (watched==ui->saleByPriceLineEdit)         //首先判断控件
//    {
//        if(event->type()==QEvent::MouseButtonPress )
//        {
//            if (m_pKeyboardDlg->isVisible())
//            {
//                m_pKeyboardDlg->hide();
//            }
//            else
//            {
//                QPoint globalPoint =  ui->saleByPriceLineEdit->mapToGlobal(QPoint(0, 0));
//                m_pKeyboardDlg->move(globalPoint.x() - m_pKeyboardDlg->width(), globalPoint.y() - m_pKeyboardDlg->height()/2);
//                m_pKeyboardDlg->activateWindow();
//                m_pKeyboardDlg->showNormal();
//            }
//        }
//    }

//    return QWidget::eventFilter(watched, event);
//}

//void ParamsSetPage::slot_Text(QString sNum)
//{
//    if (sNum == ".")
//    {
//        return;
//    }
//    QString sText = ui->saleByPriceLineEdit->text();
//    ui->saleByPriceLineEdit->setText(sText.append(sNum));
//}

//void ParamsSetPage::slot_Delete()
//{
//    QString sText = ui->saleByPriceLineEdit->text();
//    sText.remove(sText.length() - 1, 1);
//    ui->saleByPriceLineEdit->setText(sText);
//}

//void ParamsSetPage::slot_Clear()
//{
//    ui->saleByPriceLineEdit->clear();
//}

//void ParamsSetPage::slot_Confirm()
//{
//    if (m_pKeyboardDlg != NULL)
//    {
//        m_pKeyboardDlg->hide();
//    }
//}
