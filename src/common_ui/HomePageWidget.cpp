#include "HomePageWidget.h"
#include "ui_HomePageWidget.h"
#include "OnlineStateAgent.h"
#include "SaleHeadAgent.h"
#include "LoginKPosAgent.h"
#include "TipsDlg.h"
#include "KPosServerIni.h"


HomePageWidget::HomePageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePageWidget)
    , m_setGuideWidget(NULL)
{
    ui->setupUi(this);

    initCtrl();
    initConnect();
    ui->minimizeButton->hide();
}

HomePageWidget::~HomePageWidget()
{
    delete ui;
}

void HomePageWidget::initSetGuideObj(SetGuideWidget *setGuideWidget)
{
   if(m_setGuideWidget == NULL){
       m_setGuideWidget = setGuideWidget;
       m_setGuideWidget->show();
   }
}

void HomePageWidget::slot_OnlineState( bool bOnline )
{
//    ui->reportButton->setEnabled( bOnline );
//    ui->setButton->setEnabled( bOnline );
    //    ui->modifyPasswdButton->setEnabled( bOnline );
}

void HomePageWidget::initCtrl()
{
    initBtn();
}

void HomePageWidget::initConnect()
{
    connect( OnlineStateAgent::instance(), SIGNAL(sigOnlineState(bool)), this, SLOT( slot_OnlineState(bool) ) );
}

void HomePageWidget::initBtn()
{
    int nUserType = KPosServerIni::getKPosUserType();
    if (nUserType == e_tianMaoVersion)
    {
        ui->adjustPriceButton->setEnabled( false );
        ui->accountManageButton->setEnabled( false );
        ui->orderGoodsButton->setEnabled( false );
        ui->reportButton->setEnabled( false );
        ui->stockingButton->setEnabled( false );
        ui->setButton->setEnabled( false );
        ui->modifyPasswdButton->setEnabled( false );
        ui->inStockButton->setEnabled(false);
        ui->outStockButton->setEnabled(false);
        //    ui->barCodeScaleButton->setEnabled(false);
    }
    else if (nUserType == e_commonVersion)
    {
        //    ui->adjustPriceButton->setEnabled( false );
//            ui->accountManageButton->setEnabled( false );
        //    ui->orderGoodsButton->setEnabled( false );
            ui->reportButton->setEnabled( false );
        //    ui->stockingButton->setEnabled( false );
        //    ui->setButton->setEnabled( false );
        //    ui->modifyPasswdButton->setEnabled( false );
        //    ui->inStockButton->setEnabled(false);
        //    ui->outStockButton->setEnabled(false);
        //    ui->barCodeScaleButton->setEnabled(false);
//            ui->accountManageButton->setEnabled(false);
//            ui->saleDetialButton->setEnabled(false);
//            ui->reportLossButton->setEnabled(false);
//            ui->goodsManageButton->setEnabled(false);
    }
}

void HomePageWidget::on_orderGoodsButton_clicked()
{
    emit sig_showOrderGoodsWidget();
}

void HomePageWidget::on_saleButton_clicked()
{
    emit sig_showSaleWidget();
}

void HomePageWidget::on_reportButton_clicked()
{
    emit sig_showReportWidget();
}

void HomePageWidget::on_setButton_clicked()
{
    emit sig_showSetWidget();
    if(m_setGuideWidget != NULL){
        m_setGuideWidget->showSetBaseGuidePage();
    }
}

void HomePageWidget::on_stockingButton_clicked()
{
    emit sig_showStockingWidget();
}

void HomePageWidget::on_adjustPriceButton_clicked()
{
    emit sig_showAdjustPriceWidget();
}

void HomePageWidget::on_accountManageButton_clicked() //账号管理
{
    emit sig_showAccountManageWidget();
}

void HomePageWidget::on_barCodeScaleButton_clicked()
{
//    if (LoginKPosAgent::getLoginKPosInfo().salemanInfo.bShopHeader)
//    {

//    }
    emit sig_showbarCodeScaleWidget();
}

void HomePageWidget::on_minimizeButton_clicked()
{
    emit sig_minimizeWidget();
}

void HomePageWidget::on_closeButton_clicked()
{
    int PendingNum = SaleHeadAgent::Instance()->getPendingOrder();
    if(PendingNum > 0){
        TipsDlg::instance()->releaseCtrl( QString::fromUtf8("挂单未处理,不可退出"));
        return;
    }
    emit sig_closeWidget();
}

void HomePageWidget::on_outStockButton_clicked()
{
    emit sig_showOutStockWidget(); // 出库
}

void HomePageWidget::on_inStockButton_clicked()
{
    emit sig_showInStockWidget(); // 入库
}

void HomePageWidget::on_modifyPasswdButton_clicked() // 修改密码
{
    emit sig_showResetKeyWidget();
}

void HomePageWidget::on_saleDetialButton_clicked() // 销售明细
{
    emit sig_showSaleDetialWidget();
}

void HomePageWidget::on_reportLossButton_clicked() // 报损
{
    emit sig_showReportLossWidget();
}

void HomePageWidget::on_goodsManageButton_clicked()
{
    emit sig_showGoodsManageWidget();
}
