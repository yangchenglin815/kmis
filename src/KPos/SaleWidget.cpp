#include "SaleWidget.h"
#include "ui_SaleWidget.h"
#include "DlgCommon.h"
#include "SatementAgent.h"
#include "structData.h"
#include "KPosLog.h"
#include "CommonFun.h"
#include "WarningDlg.h"
#include "SingleDiscountDlg.h"
#include "SaleDiscountDlg.h"
#include "KPosServerIni.h"
#include "constData.h"
#include "KPosSetAgent.h"
#include "BalanceManage.h"
#include "../util/KPosIni.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QMessageBox>
#include "SalemanInfoDlg.h"
#include "LoginKPosAgent.h"
#include "MTScaleAPIDll.h"
#include "TipsDlg.h"
#include "CategoryInfoAgent.h"


#include "HttpClient.h"

const int gnCategoryOnePageCount = 6;
const int gnGoodsOnePageCount = 30;
const QString strMemCard = "会员账号：";
const QString strFrontOddChange = "上笔找零：";
const QString strMemName = "会员姓名：";
const QString gstrDisAmt = "优惠金额：";
const QString strLastShoppingTime = "上次购物时间：";
const QString strCurTime = "时间：";

const QString c_sRefundRemove = QStringLiteral("删除");
const QString c_sRefundClear = QStringLiteral("清空");
const QString c_sRefundGoods = QStringLiteral("退货");
const QString c_sRefundAllGoods = QStringLiteral("整单退货");
const QString c_sRefundModifyGoods = QStringLiteral("修改数量");

//标题栏
const int gnTitleWidth = 800;
const int gnTitleHeight = 51;
//销售信息
const int gnSellListWidth = 288;
const int gnSellListHeight = 529;

const int gnHor3Width = 11;
//选择商品信息
const int gnBtnWidgetWidth = 406;
const int gnBtnWidgetHeight = gnSellListHeight;
const int gnCategoryHeight = 111;
const int gnGoodsHeight = 360;
const int gnFunBtnHeight = 53;
//翻页
const int gnPageWidgetWidth = 55;
const int gnPageWidgetHeight = gnSellListHeight;

//const int gnPageBtnWidth = ;
//const int gnPageBtnHeight = ;
//const int gnStatementHeight = ;

//Space
int gnSpaceLeft = 20;
int gnSpaceTop = 10;
int gnSpaceRight = 20;
int gnSpaceBottom = 10;

SaleWidget::SaleWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SaleWidget)
    , m_pSaleCtrl( NULL )
    , m_pPendingDlg( NULL )
    , m_pStatementDlg( NULL )
    , m_pMemberDlg( NULL )
    , m_pRefundGoodsReasonDlg(NULL)
    , m_pNoReceiptRefundDlg(NULL)
    , m_pReceiptRefundDlg(NULL)
    , m_nCategoryColumn(5)
    , m_nGoodsOnePageCount(25)
    , m_pOtherOperator( NULL )
    , m_pSingleDisDlg( NULL )
    , m_pSaleDisDlg( NULL )
    , m_bCategoryGoodsChanged( false )
    , m_pSalemanDlg( NULL )
    , m_nSellState(e_normalSell)
    , m_nTimerId( -1 )
    , m_nTimerCount( 0 )
    , m_pQuickAddDlg(NULL)
{
    ui->setupUi(this);
    init();
    slot_keySetChanged();//销售界面设置初始化
    setWindowTitle( "销售" );
    startCurTimer();
}

SaleWidget::~SaleWidget()
{
    stopCurTimer();
    delete ui;
}

void SaleWidget::setRation( float fRatioWidth, float fRatioHeight )
{
    float fMinWidth = 1280/800.00;
    if( fRatioWidth - fMinWidth < 0.000001 ) {
        //必须商品窗口放在分类窗口前，因为分类窗口重置后，需要重新默认选中第一个分类按钮
        ui->goodsWidget->setColumn(25, e_goodsSale);
        //        ui->categoryWidget->setColumn(5);
        ui->operateWidget->setColumn( 5 );

        ui->titleLabel->setPixSize( 12 );
    } else {
        ui->goodsWidget->setColumn(30, e_goodsSale);
        //        ui->categoryWidget->setColumn(6);
        ui->operateWidget->setColumn( 6 );
    }

    int nTitleWidth = gnTitleWidth*fRatioWidth;
    int nTitleHeight = gnTitleHeight*fRatioHeight;
    int nSellListWidth = gnSellListWidth*fRatioWidth;
    int nSellListHeight = gnSellListHeight*fRatioHeight;
    int nHor3Width = gnHor3Width*fRatioWidth;

    int nBtnWidgetWidth = gnBtnWidgetWidth*fRatioWidth;
    int nBtnWidgetHeight = gnBtnWidgetHeight*fRatioHeight;

    int nCategoryHeight = gnCategoryHeight*fRatioHeight;
    int nGoodsHeight = gnGoodsHeight*fRatioHeight;
    int nFunBtnHeight = gnFunBtnHeight*fRatioHeight;


    int nPageWidgetWidth = gnPageWidgetWidth*fRatioWidth;
    int nPageWidgetHeight = gnPageWidgetHeight*fRatioHeight;

    //    int nSpaceLeft = gnSpaceLeft*fRatioWidth;
    //    int nSpaceTop = gnSpaceTop*fRatioHeight;
    //    int nSpaceRight = gnSpaceRight*fRatioWidth;
    //    int nSpaceBottom = gnSpaceBottom*fRatioHeight;

    ui->titleLabel->setFixedSize( QSize( nTitleWidth, nTitleHeight ) );
    ui->saleInfoWidget->setFixedSize( QSize( nSellListWidth, nSellListHeight ) );
    //    ui->horizontalSpacer_3->changeSize( nHor3Width, ui->horizontalSpacer_3->geometry().height() );

    //分类，商品，功能按钮
    ui->AllBtnWidget->setFixedSize( nBtnWidgetWidth, nBtnWidgetHeight );
    ui->categoryWidget->setFixedSize( nBtnWidgetWidth, nCategoryHeight );
    ui->goodsWidget->setFixedSize( nBtnWidgetWidth, nGoodsHeight );
    ui->operateWidget->setFixedSize( nBtnWidgetWidth, nFunBtnHeight );

    ui->PageWidget->setFixedSize( nPageWidgetWidth, nPageWidgetHeight );

    //    ui->horizontalSpacer->changeSize( nSpaceLeft, 10 );
    //    ui->horizontalSpacer_2->changeSize( nSpaceRight, 10 );
    //    ui->verticalSpacer_2->changeSize( 10, nSpaceTop );
    //    ui->verticalSpacer_3->changeSize( 10, nSpaceBottom);

    qDebug()<<"SaleWidget::setRation"<<nTitleWidth<<nTitleHeight<<nSellListWidth<<nSellListHeight \
           <<nHor3Width<<nBtnWidgetWidth<<nBtnWidgetHeight<<nPageWidgetWidth<<nPageWidgetHeight \
          << fRatioWidth <<fRatioHeight;
}

void SaleWidget::getCategoryInfoList(QList<CategoryInfo*> &categoryInfoList)
{
    if (m_pSaleCtrl != NULL)
    {
        m_pSaleCtrl->getCategoryInfoList(categoryInfoList);
    }
}

void SaleWidget::clearMemInfo()
{
    ui->searchWidget->clearText();
    initMemInfo();
    initShoppingInfo();
    emit sig_loginMem( false );
}

void SaleWidget::beginSale()
{
    BalanceManage::instance()->startCheckBalance();
    clearMemInfo();
    ui->searchWidget->clearText();
    QString strCategoryId = ui->categoryWidget->getCurCategory();
    m_pSaleCtrl->slot_getGoodsList( strCategoryId );
    ui->searchWidget->setSearchFocus();
}

void SaleWidget::setKPosSet( KPosSet &stKPosSet )
{
    QList<KeySetInfo> listHomeKey = stKPosSet.keySet.homeKeyList;
    updateOperatorBtn( listHomeKey );

    m_stKPosSet = stKPosSet;
    ui->goodsSellListWidget->setSingleMaxNum( m_stKPosSet.paramsSet.systemSetParams.nGoodsMaxNumber );
}

void SaleWidget::updateOperatorBtn( const QList<KeySetInfo> &listHomeKey )
{
    QList<KeySetInfo> listOperator;
    QList<KeySetInfo> listOtherOperator;

    //增加一个其他按钮
    KeySetInfo stKey;
    stKey.nKeyId = 1;
    stKey.bStartUsed = true;
    listOperator.append( stKey );

    QList<KeySetInfo>::const_iterator it = listHomeKey.cbegin();
    for( int i=0; it != listHomeKey.cend(); ++it ) {
        if( !it->bStartUsed ) continue;

        if( i < m_nCategoryColumn-1 ) {
            listOperator.append( *it );
        } else {
            listOtherOperator.append( *it );
        }
        ++i;
    }

    ui->operateWidget->updateOperateList( listOperator );
    if( m_pOtherOperator ) {
        m_pOtherOperator->updateOperateList( listOtherOperator );
    }
}

void SaleWidget::reInit()
{
    ui->titleLabel->init();
}

//void SaleWidget::resizeEvent(QResizeEvent *event)
//{
//    QDesktopWidget* desktopWidget = QApplication::desktop();
//    float fRatioWidth = desktopWidget->width()/800.00;
//    float fRatioHeight = desktopWidget->height()/600.00;

//    int nTitleWidth = ui->titleLabel->width();
//    int nTitleHeight = gnTitleHeight*fRatioHeight;
//    int nSellListWidth = gnSellListWidth*fRatioWidth;
//    int nSellListHeight = gnSellListHeight*fRatioHeight;
//    int nHor3Width = gnHor3Width*fRatioWidth;
//    int nBtnWidgetWidth = gnBtnWidgetWidth*fRatioWidth;
//    int nBtnWidgetHeight = gnBtnWidgetHeight*fRatioHeight;
//    int nPageWidgetWidth = gnPageWidgetWidth*fRatioWidth;
//    int nPageWidgetHeight = gnPageWidgetHeight*fRatioHeight;


//    ui->titleLabel->setFixedSize( QSize( nTitleWidth, nTitleHeight ) );
//    ui->widget_4->setFixedSize( QSize( nSellListWidth, nSellListHeight ) );
//    //ui->horizontalSpacer_3->setContentsMargins();
//    ui->widget_12->setFixedSize( QSize( nBtnWidgetWidth, nBtnWidgetHeight ) );
//    ui->widget_11->setFixedSize( QSize( nPageWidgetWidth, nPageWidgetHeight ) );

//    qDebug()<<"SaleWidget::resizeEvent"<<nTitleWidth<<nTitleHeight<<nSellListWidth<<nSellListHeight
//           <<nHor3Width<<nBtnWidgetWidth<<nBtnWidgetHeight<<nPageWidgetWidth<<nPageWidgetHeight
//          << fRatioWidth <<fRatioHeight;
//}


void SaleWidget::slot_backHomePage()
{
    if (m_nSellState != e_normalSell)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("返回销售界面"));
        m_nSellState = e_normalSell;
        ui->goodsRefundListWidget->clearAllGoods();
        ui->sellStackedWidget->setCurrentWidget(ui->goodsSellListWidget);
        ui->operateStackedWidget->setCurrentWidget(ui->operateWidget);
    }
    else if (ui->goodsSellListWidget->getGoodsNum() > 0)
    {
        WarningDlg *pDlg = new WarningDlg();
        pDlg->setTitle( "" );
        pDlg->setContent( "仍有商品未结算 无法返回" );
        pDlg->exec();
        return;
    }
    else
    {
        if(!m_pOtherOperator->isHidden())
        {
            m_pOtherOperator->hide();
        }
        emit sig_backHomePage();
        BalanceManage::instance()->stopCheckBalance();
    }
    clearMemInfo();
    ui->searchWidget->hideKeyboard();
}

void SaleWidget::slot_searchGoods(const QString &strGoods)
{
    if (m_pSaleCtrl == NULL)
    {
        return;
    }

    if (strGoods.isEmpty())
    {
        QString sCategoryKeyId = ui->categoryWidget->getCurCategory();
        m_pSaleCtrl->slot_getGoodsList(sCategoryKeyId);
        return;
    }

    ui->searchWidget->clearText();

    bool bSearchSuccess = searchSaleByPrice(strGoods);
    if (bSearchSuccess)return;

    bSearchSuccess = searchRefundReceipt(strGoods);
    if (bSearchSuccess)return;

    bSearchSuccess = searchBarcodeScalesGoods(strGoods);
    if (bSearchSuccess)return;

    bool bHas = m_pSaleCtrl->searchGoodsInfo(strGoods);
    if( !bHas )
    {
        QString strText = "没有找到对应的商品信息";
        QMessageBox::information( this, "提示", strText );
        QString strCategoryId = ui->categoryWidget->getCurCategory();
        m_pSaleCtrl->slot_getGoodsList( strCategoryId );

    }


    //*******************************************************************//
    //    if (m_pSaleCtrl == NULL)
    //    {
    //        return;
    //    }

    ////    m_bSearchReceiptAgain = false;
    //    if (m_nSellState != e_normalSell)
    //    {
    //        if (m_pSaleCtrl->isReceiptFormat(strGoods))
    //        {
    //            if (ui->goodsRefundListWidget->getSaleDetailsListLengh() == 0)
    //            {
    //                SaleHead saleHead;
    //                bool bSaleReceipt = m_pSaleCtrl->isSaleReceipt(strGoods, saleHead);
    //                if (bSaleReceipt)
    //                {
    //                    QList<SaleDetails> saleDetailsList;
    //                    m_pSaleCtrl->findSaleDetails(strGoods, saleDetailsList);
    //                    if (saleDetailsList.length() > 0)
    //                    {
    ////                        if (!m_pSaleCtrl->isRefundFinish(strGoods))
    ////                        {
    //                        m_nSellState = e_receiptRefund;

    //                        saleHead.strReturnOrderNum = strGoods; // 订单号赋值给退货单号
    //                        ui->goodsRefundListWidget->initData(saleHead, saleDetailsList);
    //                        QList<QString> strList;
    //                        strList<<c_sRefundClear<<c_sRefundGoods<<c_sRefundAllGoods<<c_sRefundModifyGoods;
    //                        initRefundButtonList(strList);
    //                        ui->lastChangeLabel->setText(QStringLiteral("上笔找零：￥%1").arg(saleHead.strLastCharge));
    //                        ui->couponLabel->setText(QStringLiteral("优惠金额：￥%1").arg(QString::number(saleHead.fAllDisAmt, 'f', 2)));
    //                        if (m_pSaleCtrl != NULL)
    //                        {
    //                            if (!saleHead.strMemCardId.isEmpty())
    //                            {
    //                                m_pSaleCtrl->getMemInfoForRefundRequest(saleHead.strMemCardId);
    //                            }
    //                        }
    ////                        }
    ////                        else
    ////                        {
    ////                            TipsDlg::instance()->releaseCtrl(QStringLiteral("此小票单号已经退过一次，不能再退！"));
    ////                        }
    //                    }
    //                    else
    //                    {
    //                        if (m_pSaleCtrl->isOnline())
    //                        {
    //                            m_pSaleCtrl->searchReceiptRequst(strGoods);
    ////                            TipsDlg::instance()->releaseCtrl(QStringLiteral("此小票无销售明细，开始远程搜索此小票，请稍等..."));
    //                        }
    //                        else
    //                        {
    //                            TipsDlg::instance()->releaseCtrl(QStringLiteral("没检测到网络，无法远程搜索此小票！"));
    //                        }
    //                    }
    //                }
    //                else
    //                {
    //                    if (m_pSaleCtrl->isOnline())
    //                    {
    //                        m_pSaleCtrl->searchReceiptRequst(strGoods);
    ////                        TipsDlg::instance()->releaseCtrl(QStringLiteral("本地无此小票，开始远程搜索此小票，请稍等..."));
    //                    }
    //                    else
    //                    {
    //                        TipsDlg::instance()->releaseCtrl(QStringLiteral("没检测到网络，无法远程搜索此小票！"));
    //                    }
    //                }
    //            }
    //            else
    //            {
    //                TipsDlg::instance()->releaseCtrl(QStringLiteral("请先清空列表数据，才能使用此小票单号！"));
    ////                m_bSearchReceiptAgain = true;
    //            }
    //            ui->searchWidget->clearText();
    //            QString strCategoryId = ui->categoryWidget->getCurCategory();
    //            m_pSaleCtrl->slot_getGoodsList( strCategoryId );
    //            return;
    //        }
    //    }

    //    if (strGoods.isEmpty())
    //    {
    //        QString sCategoryKeyId = ui->categoryWidget->getCurCategory();
    //        m_pSaleCtrl->slot_getGoodsList(sCategoryKeyId);
    //    }
    //    else
    //    {

    //        MTBarcodeProductData_s productData = MTScaleAPIDll::verifyBarcode(strGoods);
    //        if(productData.plu != NULL)
    //        {
    //            ui->searchWidget->clearText();
    //            QList<GoodsInfo> goodsInfoList;
    //            m_pSaleCtrl->searchGoodsInfo("0001", goodsInfoList);
    //            if (goodsInfoList.length() != 1)
    //            {
    //                return;
    //            }
    //            GoodsInfo st_goodsInfo = goodsInfoList[0];

    //            // 前台是否允许销售售价为零的商品
    //            if( !m_stKPosSet.paramsSet.shopSetParams.bSellZeroGoodsBySeller && st_goodsInfo.fPrice<= 0.00 ) return;
    //            if( !m_stKPosSet.paramsSet.shopSetParams.bSellZeroGoodsBySeller && !m_stMemRegInfo.stMemInfo.strCardNo.isEmpty()
    //                    && st_goodsInfo.fMemberPrice <= 0.00 )
    //            {
    //                return;
    //            }

    //            if( ui->goodsSellListWidget->getGoodsNum() == 0 && ! m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) {
    //                ui->goodsSellListWidget->setMemStatus( true );
    //            }

    //            ui->goodsSellListWidget->addGoodsInfo( st_goodsInfo, productData.weight);


    //            if( ui->goodsSellListWidget->getGoodsNum() == 1 ) {
    //                SaleHead stSaleHead;
    //                ui->goodsSellListWidget->getSaleHead( stSaleHead );
    //                if( stSaleHead.strOrderNum.isEmpty() ) return;
    //                if( m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) return;
    //                stSaleHead.strMemCardId = m_stMemRegInfo.stMemInfo.strCardNo;
    //                ui->goodsSellListWidget->setSaleHead( stSaleHead );

    //                m_pStatementDlg->updateSaleHeadMemInfo( stSaleHead.strOrderNum, m_stMemRegInfo );
    //            }

    //            return;
    //        }

    //        bool bHas = m_pSaleCtrl->searchGoodsInfo(strGoods);
    //        if( !bHas ) {
    //            QString strText = "没有找到对应的商品信息";
    //            QMessageBox::information( this, "提示", strText );
    //            QString strCategoryId = ui->categoryWidget->getCurCategory();
    //            m_pSaleCtrl->slot_getGoodsList( strCategoryId );
    //        }
    //        ui->searchWidget->clearText();
    //    }
}

void SaleWidget::slot_getGoodsList( QString strCategoryId )
{
    ui->searchWidget->clearText();
    m_pSaleCtrl->slot_getGoodsList( strCategoryId );
}

void SaleWidget::slot_addGoodsToSaleList( GoodsInfo st_goodsInfo )
{
    ui->searchWidget->clearText();
    QString strCategoryId = ui->categoryWidget->getCurCategory();
    m_pSaleCtrl->slot_getGoodsList( strCategoryId );

    if (m_nSellState == e_normalSell)
    {
        // 前台是否允许销售售价为零的商品
        if( !m_stKPosSet.paramsSet.shopSetParams.bSellZeroGoodsBySeller && st_goodsInfo.fPrice<= 0.00 ) return;
        if( !m_stKPosSet.paramsSet.shopSetParams.bSellZeroGoodsBySeller && !m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() \
                && st_goodsInfo.fMemberPrice <= 0.00 ) return;

        if( ui->goodsSellListWidget->getGoodsNum() == 0 && ! m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) {
            ui->goodsSellListWidget->setMemStatus( true );
        }

        if( st_goodsInfo.bStandard ) {//标品，判断销售列表中，有没有该商品，有则数量叠加；没有则新增
            bool bHas = ui->goodsSellListWidget->isGoods( st_goodsInfo.sBarCode );
            if( bHas ) {
                ui->goodsSellListWidget->updateGoodsInfo( st_goodsInfo );
            } else {
                ui->goodsSellListWidget->addGoodsInfo( st_goodsInfo, "1" );
            }
        } else {//非标品,直接加载到销售列表中
            float fWeight = m_stBalanceStandardEx.sWeight.toFloat();
            if( fWeight <= 0.0000 ) return;//小于等于0
            if( m_stBalanceStandardEx.bOverWeight ) return;//过载

            if( m_stBalanceStandardEx.bStable && !m_stBalanceStandardEx.bInZero ) {
                ui->goodsSellListWidget->addGoodsInfo( st_goodsInfo, m_stBalanceStandardEx.sWeight );
            }
        }

        if( ui->goodsSellListWidget->getGoodsNum() == 1 ) {
            SaleHead stSaleHead;
            ui->goodsSellListWidget->getSaleHead( stSaleHead );
            if( stSaleHead.strOrderNum.isEmpty() ) return;
            if( m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) return;
            stSaleHead.strMemCardId = m_stMemRegInfo.stMemInfo.strCardNo;
            ui->goodsSellListWidget->setSaleHead( stSaleHead );

            m_pStatementDlg->updateSaleHeadMemInfo( stSaleHead.strOrderNum, m_stMemRegInfo );
        }
    }
    else if (m_nSellState == e_noReceiptRefund)
    {
        if (!st_goodsInfo.bStandard)
        {
            float fWeight = m_stBalanceStandardEx.sWeight.toFloat();
            if( fWeight <= 0.0000 ) return; //小于等于0
            if( m_stBalanceStandardEx.bOverWeight) return;//过载

            if( m_stBalanceStandardEx.bStable && !m_stBalanceStandardEx.bInZero )
            {
                ui->goodsRefundListWidget->appendData(st_goodsInfo, fWeight);
            }
        }
        else
        {
            ui->goodsRefundListWidget->appendData(st_goodsInfo, 1.0f);
        }
    }
    else if (m_nSellState == e_receiptRefund)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("有小票退货，请使用【修改数量按钮】修改退货数量"));
    }
    ui->searchWidget->setSearchFocus();
}

void SaleWidget::slot_stableInfo( EBalanceStandard_Ex balanceStandard_Ex, bool bStable )
{
    ui->titleLabel->setBalanceStable( bStable );
    ui->titleLabel->setBalanceZero( balanceStandard_Ex.bInZero );//零位
    ui->titleLabel->setBalanceOverload( balanceStandard_Ex.bOverWeight );//过载
    ui->titleLabel->setBalanceUnderload( balanceStandard_Ex.bLessWeight );//欠载

    //    QString strWeight = "";
    //    strWeight.sprintf( "%6.3f", balanceStandard_Ex.sWeight.toFloat() );
    ui->platFormLabel->setfGoodsWeight( balanceStandard_Ex.sWeight );
    //KPosLog::instance()->writeTestLog( "SaleWidget::slot_stableInfo:" + QString::number( balanceStandard_Ex.bLessWeight?1:0 ) + balanceStandard_Ex.sWeight + balanceStandard_Ex.sTareWeight );

    m_stBalanceStandardEx = balanceStandard_Ex;
}

void SaleWidget::slot_showOtherOperatorWidget()
{
    QPoint ptGlobal = ui->operateWidget->mapToGlobal(QPoint(0, 0));
    int nY = ptGlobal.y() - m_pOtherOperator->height();

    m_pOtherOperator->move( ptGlobal.x(), nY );

    m_pOtherOperator->activateWindow();
    m_pOtherOperator->show();
}

//显示会员对话框
void SaleWidget::slot_showMemDlg()
{
    //    QList<PayWayInfoSet> listMemRechargeMethod;
    //    QList<PayWayInfoSet> listPayWayInfoSet = m_stKPosSet.payWaySet.payWayInfoSetList;
    //    int nSize = listPayWayInfoSet.size();
    //    for( int i =0; i<nSize; ++i ) {
    //        if( !listPayWayInfoSet[i].bStartUse ) continue;
    //        if( !listPayWayInfoSet[i].bChargeMember ) continue;

    //        listMemRechargeMethod.append( listPayWayInfoSet[i] );
    //    }
    //    {//测试
    //        listMemRechargeMethod.append( PayAlipay );
    //        listMemRechargeMethod.append( PayStoreCard );
    //        listMemRechargeMethod.append( PayCash );
    //        listMemRechargeMethod.append( ApplePay );
    //        listMemRechargeMethod.append( PayWeChat );
    //        listMemRechargeMethod.append( JdWallet );
    //    }

    //m_pMemberDlg->setMemRechargeMethod( listMemRechargeMethod );
    if (m_pMemberDlg == NULL)
    {
        m_pMemberDlg = new MemberDlg();
        connect( m_pMemberDlg, SIGNAL(sig_memInfo(MemRegisterInfo_s)), this, SLOT( slot_updateMemInfo( MemRegisterInfo_s)) );
        connect( m_pMemberDlg, SIGNAL(sig_replaceMemCard(QString,QString)), this, SLOT( slot_replaceMemCard( QString, QString ) ) );
    }
    m_pMemberDlg->clearData();
    m_pMemberDlg->setMemRegInfo( m_stMemRegInfo );
    m_pMemberDlg->activateWindow();
    //m_pMemberDlg->exec();
    m_pMemberDlg->show();
}

void SaleWidget::slot_showPendingDlg()
{
    //int nNum = m_pSaleCtrl->getSaleHeadPendingNum();
    //int nPendingMaxLength = m_stKPosSet.paramsSet.shopSetParams.nPendingListMaxLength;

    //if( (nPendingMaxLength != 0 && nPendingMaxLength <= nNum) || ui->goodsSellListWidget->getGoodsNum() < 1 ) {
    if( ui->goodsSellListWidget->getGoodsNum() < 1 )
    {
        m_pPendingDlg->initData();
        m_pPendingDlg->show();
    } else {
        //修改当前销售的状态为挂单，并clear销售明细表
        ui->goodsSellListWidget->setMemStatus( false );
        ui->goodsSellListWidget->setSaleHeadStatus( e_headPending );
        ui->sumPriceValueLabel->setText( "￥0.00" );
        initMemInfo();
        initShoppingInfo();

        emit sig_clearGoodsToSaleList();
    }

    ui->operateWidget->updatePendingNum();
}

void SaleWidget::slot_deleteSelectGoods()
{
    if( ui->goodsSellListWidget->getSelectGoodsNum() < 1 ) {
        return;
    }

    DlgCommon *dlgCommon = new DlgCommon();
    dlgCommon->set_title( "取消" );
    dlgCommon->set_content( "是否确认删除?" );
    dlgCommon->show();

    connect( dlgCommon, SIGNAL( sig_dlg_close() ), this, SLOT( slot_closeDlg() ) );
    connect(dlgCommon, SIGNAL(sig_btn_cancel()), this, SLOT(slot_closeDlg()) );
    connect( dlgCommon, SIGNAL( sig_btn_sure()), this, SLOT( slot_Sure() ) );
}

void SaleWidget::slot_clearAllGoods()
{
    if( ui->goodsSellListWidget->getGoodsNum() < 1 ) {
        return;
    }

    DlgCommon *dlgCommon = new DlgCommon();
    dlgCommon->set_title( "整取" );
    dlgCommon->set_content( "是否确认删除整单数据?" );
    connect( dlgCommon, SIGNAL( sig_dlg_close() ), this, SLOT( slot_closeDlg() ) );
    connect(dlgCommon, SIGNAL(sig_btn_cancel()), this, SLOT(slot_closeDlg()));
    connect( dlgCommon, SIGNAL( sig_btn_sure()), this, SLOT( slot_Sure() ) );
    dlgCommon->show();
}

void SaleWidget::slot_discount()
{
//    SystemSetParams stSystemSetParams = m_stKPosSet.paramsSet.systemSetParams;
    ShopSetParams stShopSetParams = m_stKPosSet.paramsSet.shopSetParams;

    if( !stShopSetParams.bChangePriceBySeller ) return;
    //非会员价打折并且没有登录会员
//    if( !stSystemSetParams.bDiscountOnMember && !m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) return;

    if( ui->goodsSellListWidget->getSelectGoodsNum() != 1 ) {
        return;
    } else if( ui->goodsSellListWidget->getSelectGoodsNum() == 1 ) {
        //显示单品折扣对话框
        SaleDetails stSaleDetails;
        QList<SaleDetails> listSaleDetails;
        ui->goodsSellListWidget->getSelectGoodsInfo( listSaleDetails );
        if( listSaleDetails.size() != 1 ) return;

        if( m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) {
            m_pSingleDisDlg->setMember( false );
        } else {
            m_pSingleDisDlg->setMember( true );
        }
        stSaleDetails = listSaleDetails.first();
        m_pSingleDisDlg->setSaleDetails( stSaleDetails );
        m_pSingleDisDlg->exec();
    }/* else {//显示多品折扣对话框
        //显示单品折扣对话框
        QList<SaleDetails> listSaleDetails;
        bool bHas = ui->goodsSellListWidget->getSelectGoodsInfo( listSaleDetails );
        if( !bHas ) return;

        //如果所选择的商品中有打过折，并且不可以折上折，则return
        bool bDis = isDiscount( listSaleDetails );
        if( bDis && !stSystemSetParams.bDiscountOnDiscount ) return;

        if( m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) {
            m_pSaleDisDlg->setMember( false );
        } else {
            m_pSaleDisDlg->setMember( true );

        }
        m_pSaleDisDlg->setSaleHeadDis( false );
        m_pSaleDisDlg->setSaleDetails( listSaleDetails );
        m_pSaleDisDlg->exec();
    }*/

}

void SaleWidget::slot_saleDiscount()
{
    SystemSetParams stSystemSetParams = m_stKPosSet.paramsSet.systemSetParams;
    ShopSetParams stShopSetParams = m_stKPosSet.paramsSet.shopSetParams;

    if( !stShopSetParams.bChangePriceBySeller ) return;
//    if( !stSystemSetParams.bDiscountOnMember && !m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) return;

    if( ui->goodsSellListWidget->getGoodsNum() < 1 ) {
        return;
    }
    QList<SaleDetails> listSaleDetails;
    bool bHas = ui->goodsSellListWidget->getAllGoodsInfo( listSaleDetails );
    if( !bHas ) return;

    //如果所选择的商品中有打过折，并且不可以折上折，则return
    bool bDis = isDiscount( listSaleDetails );
    if( bDis && !stSystemSetParams.bDiscountOnDiscount ) return;

    if( m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) {
        m_pSaleDisDlg->setMember( false );
    } else {
        m_pSaleDisDlg->setMember( true );
    }
    m_pSaleDisDlg->setSaleHeadDis( true );
    m_pSaleDisDlg->setSaleDetails( listSaleDetails );
    //显示折扣对话框
    m_pSaleDisDlg->exec();
}

void SaleWidget::slot_openCashBox()
{
    //只有店长才能打开钱箱
    if( m_stKPosSet.paramsSet.shopSetParams.bOpenCashboxBySeller ) {
        //弹出登录对话框，并且是店长登录
    }

    BalanceManage::instance()->openCashBox();
}

void SaleWidget::slot_refundGoods()
{
    if (ui->goodsSellListWidget->getGoodsNum() > 0)
    {
        WarningDlg *pDlg = new WarningDlg();
        pDlg->setTitle( "" );
        pDlg->setContent( "仍有商品未结算 无法退货" );
        pDlg->exec();
        return;
    }

    clearMemInfo();
    initNoReceiptKeyPage();
    ui->sellStackedWidget->setCurrentWidget(ui->goodsRefundListWidget);
    ui->operateStackedWidget->setCurrentWidget(ui->refundKeyPage);
    ui->goodsRefundListWidget->initCtrl(m_pSaleCtrl);
}

//打印上张小票
void SaleWidget::slot_printLastReceipt()
{
    m_pSaleCtrl->printLastReceipt( m_stMemRegInfo );
}

void SaleWidget::slot_fastCreateDocument()
{
    if (m_pQuickAddDlg == NULL)
    {
        m_pQuickAddDlg = new QuickAddDlg;
        m_pQuickAddDlg->setCtrl(m_pSaleCtrl);
    }
    m_pQuickAddDlg->getCategoryNodeList();
    m_pQuickAddDlg->activateWindow();
    m_pQuickAddDlg->showNormal();
}

void SaleWidget::slot_peeling()
{
    m_pSaleCtrl->peeling();
}

void SaleWidget::slot_otherOperator( int nKeyId )
{
    switch ( nKeyId ) {
    case e_homeElse:
        //slot_showOtherOperatorWidget();//因为不显示otherBtn
        break;
    case e_homeMember:
        slot_showMemDlg();
        break;
    case e_homePending:
        slot_showPendingDlg();
        break;
    case e_homeCancel:
        slot_deleteSelectGoods();
        break;
    case e_homeTrimMoney:
        slot_clearAllGoods();
        break;
    case e_homeDiscount://折扣，多品折扣
        slot_discount();
        break;
    case e_lastReceipt://上张小票
        slot_printLastReceipt();
        break;
    case e_homeFastCreateDocument:
        slot_fastCreateDocument();
        break;
    case e_homeTrimBox:
        slot_peeling();
        break;
    case e_homeDiscountAll://整单折扣
        slot_saleDiscount();
        break;
    case e_homePurse://钱箱
        slot_openCashBox();
        break;
    case e_homeRefundGoods: // 退货
        slot_refundGoods();
        break;
    case e_homeLock://手动锁屏
        emit sig_lockScreen();
        break;
    case e_homeModifyNum:
        ui->goodsSellListWidget->slot_ModifyGoodsNum();
        ui->searchWidget->setSearchFocus();
        break;
    default:
        break;
    }

    m_pOtherOperator->hide();
}

void SaleWidget::slot_OtherOPeratorWidgetHide()
{
    ui->operateWidget->setUnSelectStatus( e_homeElse );
}

void SaleWidget::slot_closeDlg()
{
    ui->searchWidget->setSearchFocus();
    QObject *pObj = QObject::sender();
    if( pObj ) {
        delete pObj;
        pObj = NULL;
    }
}

void SaleWidget::slot_Sure()
{
    DlgCommon *pObj = (DlgCommon*)QObject::sender();
    if( pObj->get_title() == "取消" ) {
        //获取所有的选中商品信息，然后for循环删除
        QList<SaleDetails> listSaleDetails;
        ui->goodsSellListWidget->getSelectGoodsInfo( listSaleDetails );
        QList<SaleDetails>::iterator it = listSaleDetails.begin();
        for( ; it != listSaleDetails.end(); ++it ) {
            emit sig_delGoodsToSaleList( it->nSaleDetailPos );
        }

        ui->goodsSellListWidget->slot_deleteSelectGoods();
        //ui->goodsSellListWidget->getSelectGoodsInfo( listSelectGoods );
        if( ui->goodsSellListWidget->getGoodsNum() == 0 ) {
            initMemInfo();
            initShoppingInfo();
            updateCategoryGoodsShow();
        }
    } else if( pObj->get_title() == "整取" ) {
        ui->goodsSellListWidget->slot_clearAllGoods();
        emit sig_clearGoodsToSaleList();
        updateCategoryGoodsShow();

        initMemInfo();
        initShoppingInfo();
    }
    ui->searchWidget->setSearchFocus();

    if( pObj ) {
        delete pObj;
        pObj = NULL;
    }
}

void SaleWidget::slot_addSaleHead( const QString &strOrderNum )
{
    m_pPendingDlg->hide();
    ui->goodsSellListWidget->addSaleHead( strOrderNum );
    ui->operateWidget->updatePendingNum();
    ui->searchWidget->setSearchFocus();
}

void SaleWidget::slot_hidePendingDlg()
{
    m_pPendingDlg->initData();
    m_pPendingDlg->hide();
    ui->operateWidget->updatePendingNum();
    ui->searchWidget->setSearchFocus();
}

void SaleWidget::slot_showStatementDlg()
{
    ui->searchWidget->clearText();
    QString strCategoryId = ui->categoryWidget->getCurCategory();
    m_pSaleCtrl->slot_getGoodsList( strCategoryId );

    if (m_nSellState == e_normalSell)
    {
        if( ui->goodsSellListWidget->getGoodsNum() < 1 ) return;
        if( m_stKPosSet.paramsSet.shopSetParams.bChooseSeller ) {
            //显示业务员的对话框
        }

        //从数据库获取当前门店的所有用户信息
        SalemanInfo stSalemanInfo;
        QList<SalemanInfo> listSalemanInfo;
        LoginKPosAgent::instance()->getAllSalemanInfo( listSalemanInfo );
        if( listSalemanInfo.size() != 0 ) {
            m_pSalemanDlg->setSalemanInfo( listSalemanInfo );

            if( m_pSalemanDlg->exec() != QDialog::Accepted ) return;

            stSalemanInfo = m_pSalemanDlg->getCurSalemanInfo();
            //并加载如数据库
            SaleHead stSaleHead;
            ui->goodsSellListWidget->getSaleHead( stSaleHead );
            stSaleHead.nShoppingId = stSalemanInfo.nUserId;
            stSaleHead.strShoppingName = stSalemanInfo.sUsername;
            ui->goodsSellListWidget->setSaleHead( stSaleHead );
        }

        SaleHead stSaleHead;
        bool bHas = ui->goodsSellListWidget->getSaleHead( stSaleHead );
        if( !bHas ) {
            qDebug()<<"SaleWidget::slot_showStatementDlg  "<<"has not SaleHead";
            return;
        }

        StatementInfo stStatementInfo;
        stStatementInfo.strOrderNum = stSaleHead.strOrderNum;
        stStatementInfo.fDiscount = stSaleHead.fGrantDisRate;
        stStatementInfo.fDisAmt = stSaleHead.fAllDisAmt;
        stStatementInfo.fSimpleAmt = stSaleHead.fOughtAmt;
        stStatementInfo.fCouponDisAmt = stSaleHead.fCouponDisAmt;

        //1.通过订单号，获取该订单号的支付详情个数和支付成功个数
        m_pStatementDlg->setStatementInfo( stStatementInfo );
        m_pStatementDlg->setMemInfo( m_stMemRegInfo );
        m_pStatementDlg->setDiscardZero( m_stKPosSet.paramsSet.systemSetParams.bDiscardZero );
        m_pStatementDlg->show();
    }
    else
    {
        if (-ui->goodsRefundListWidget->getRefundCash() < 0.00001f)
        {
            TipsDlg::instance()->releaseCtrl(QStringLiteral("没有退任何商品，结算无效"));
            return;
        }

        if (m_pSaleCtrl != NULL)
        {
            m_pSaleCtrl->getRefundGoodsReasonListRequest();
        }
    }
}

void SaleWidget::slot_updateGoodsSumPrice(QString strSumPrice, QString strDisAmt)
{
    ui->sumPriceValueLabel->setText( "￥" + strSumPrice );
    ui->couponLabel->setText( gstrDisAmt + "￥" + strDisAmt );
    ui->searchWidget->setSearchFocus();
}

void SaleWidget::slot_updateSaleHead( StatementInfo stStatementInfo )
{
    //需要添加 优惠券优惠字段，才能使用
    SaleHead stSaleHead;
    ui->goodsSellListWidget->getSaleHead( stSaleHead );
    stSaleHead.fCouponDisAmt = stStatementInfo.fCouponDisAmt;
    stSaleHead.fOughtAmt = stStatementInfo.fSimpleAmt;
    ui->goodsSellListWidget->setSaleHead( stSaleHead );
    ui->goodsSellListWidget->updateGoodsList();
}

void SaleWidget::slot_updateMemInfo( MemRegisterInfo_s stMemRegInfo )
{
    m_stMemRegInfo = stMemRegInfo;
    ui->titleLabel->setMemStatus( true );

    ui->memberNumLabel->setText( "会员账号:" + m_stMemRegInfo.stMemInfo.strCardNo );
    ui->memberNameLabel->setText( "会员姓名:" + m_stMemRegInfo.stMemInfo.strName );
    //    QString dtShopping = m_stMemRegInfo.stMemInfo.dtShopping.toString( "MM.dd hh:mm" );
    ui->lastDateLabel->setText( "上次购物时间:" + m_stMemRegInfo.stMemInfo.dtShopping.toString( "MM.dd hh:mm" ) );

    //更新销售列表,而以后的商品加载都需要用会员价
    ui->goodsSellListWidget->setMemStatus( true );
    ui->goodsSellListWidget->updateGoodsList();
    emit sig_loginMem( true );
    //把会员信息更新到销售主表中
    SaleHead stSaleHead;
    ui->goodsSellListWidget->getSaleHead( stSaleHead );
    if( stSaleHead.strOrderNum.isEmpty() ) return;
    stSaleHead.strMemCardId = m_stMemRegInfo.stMemInfo.strCardNo;
    ui->goodsSellListWidget->setSaleHead( stSaleHead );
    ui->searchWidget->setSearchFocus();
    //m_pStatementDlg->updateSaleHeadMemInfo( stSaleHead.strOrderNum, m_stMemRegInfo );
}

void SaleWidget::slot_replaceMemCard( QString strOldCardId, QString strNewCardId )
{
    if( m_stMemRegInfo.stMemInfo.strCardNo != strOldCardId ) return;

    m_stMemRegInfo.stMemInfo.nCardStatus = 1;
    m_stMemRegInfo.stMemInfo.strCardNo = strNewCardId;
    ui->memberNumLabel->setText( "会员账号:" + m_stMemRegInfo.stMemInfo.strCardNo );
}

void SaleWidget::slot_categoryGoodsChanged()
{
    if (m_pSaleCtrl == NULL)
    {
        return;
    }

    m_bCategoryGoodsChanged = true;
    if( ui->goodsSellListWidget->getGoodsNum() > 0 ) return;

    updateCategoryGoodsShow();
    emit sigCategoryGoodsChanged();
}

void SaleWidget::slot_keySetChanged()
{
    m_bKeySetChanged = true;

    KPosSetAgent::instance()->getKPosSetInfo( m_stKPosSet );
    setKPosSet( m_stKPosSet );
    m_bKeySetChanged = false;
}

void SaleWidget::slot_onGetRefundGoodsReasonList(int nCode, QString sMsg, QList<RefundGoodsReason> reasonList)
{
    if (reasonList.length() > 0)
    {
        if (m_pRefundGoodsReasonDlg == NULL)
        {
            m_pRefundGoodsReasonDlg = new RefundGoodsReasonDlg(this);
            connect(m_pRefundGoodsReasonDlg, SIGNAL(sigClickReason(int)), this, SLOT(slot_clickRefundReason(int)));
        }
        int nMoveXPos = (this->width() - m_pRefundGoodsReasonDlg->width())/2;
        int nMoveYPos = (this->height() - m_pRefundGoodsReasonDlg->height())/2;
        m_pRefundGoodsReasonDlg->move(nMoveXPos, nMoveYPos);
        m_pRefundGoodsReasonDlg->setReasonList(reasonList);
        m_pRefundGoodsReasonDlg->exec();
    }
    else
    {
        slot_clickRefundReason(-1);
    }
}

void SaleWidget::slot_onSearchReceipt(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> saleDetailsList, float fIntegralPayMoney, int nIntegralPay)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("小票搜索失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else if (saleDetailsList.length() > 0)
    {
        m_nSellState = e_receiptRefund;
        ui->goodsRefundListWidget->initData(saleHead, saleDetailsList, fIntegralPayMoney, nIntegralPay);
        QList<QString> strList;
        strList<<c_sRefundClear<<c_sRefundGoods<<c_sRefundAllGoods<<c_sRefundModifyGoods;
        initRefundButtonList(strList);
        ui->lastChangeLabel->setText(QStringLiteral("上笔找零：￥%1").arg(saleHead.strLastCharge));
        ui->couponLabel->setText(QStringLiteral("优惠金额：￥%1").arg(QString::number(saleHead.fAllDisAmt, 'f', 2)));
        if (m_pSaleCtrl != NULL)
        {
            if (!saleHead.strMemCardId.isEmpty())
            {
                m_pSaleCtrl->getMemInfoForRefundRequest(saleHead.strMemCardId);
            }
        }
    }
    else
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("小票搜索失败，没搜到订单详情"));
    }
    ui->searchWidget->clearText();
}

void SaleWidget::slot_onMemInfoQueryForRefund(int nCode, QString sMsg, MemRegisterInfo_s memRegisterInfo)
{
    if(nCode != e_success)
    {
        //TipsDlg::instance()->releaseCtrl(QStringLiteral("会员信息查询失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        m_stMemRegInfo = memRegisterInfo;
        ui->memberNumLabel->setText("会员账号:" + m_stMemRegInfo.stMemInfo.strCardNo);
        ui->memberNameLabel->setText("会员姓名:" + m_stMemRegInfo.stMemInfo.strName);
        ui->lastDateLabel->setText("上次购物时间:" + m_stMemRegInfo.stMemInfo.dtShopping.toString("MM.dd hh:mm"));
    }
}

void SaleWidget::slot_clickRefundReason(int nReasonId)
{
    if ((m_nSellState == e_noReceiptRefund) ||
            KPosServerIni::isOnlyCashRefund())
    {
        if (m_pNoReceiptRefundDlg == NULL)
        {
            m_pNoReceiptRefundDlg = new NoReceiptRefundDlg(this);
            connect(m_pNoReceiptRefundDlg, SIGNAL(sigConfirm(int)), this, SLOT(slot_confirmNoReceiptRefund(int)));
        }
        int nMoveXPos = (this->width() - m_pNoReceiptRefundDlg->width())/2;
        int nMoveYPos = (this->height() - m_pNoReceiptRefundDlg->height())/2;

        if (ui->goodsRefundListWidget->isMemberRefund())
        {
            m_pNoReceiptRefundDlg->showIntegralMoney(ui->goodsRefundListWidget->getIntegralPayMoney());
        }
        else
        {
            m_pNoReceiptRefundDlg->hideIntegralMoney();
        }
        m_pNoReceiptRefundDlg->setRefundCash(ui->goodsRefundListWidget->getRefundCash());
        m_pNoReceiptRefundDlg->setRefundReasonId(nReasonId);

        m_pNoReceiptRefundDlg->move(nMoveXPos, nMoveYPos);
        m_pNoReceiptRefundDlg->exec();
    }
    else if (m_nSellState == e_receiptRefund)
    {
        if (m_pReceiptRefundDlg == NULL)
        {
            m_pReceiptRefundDlg = new ReceiptRefundDlg(this);
        }
        int nMoveXPos = (this->width() - m_pReceiptRefundDlg->width())/2;
        int nMoveYPos = (this->height() - m_pReceiptRefundDlg->height())/2;
        m_pReceiptRefundDlg->move(nMoveXPos, nMoveYPos);
        m_pReceiptRefundDlg->exec();

        refundButtonClick(c_sRefundClear);
        m_nSellState = e_normalSell;
        ui->sellStackedWidget->setCurrentWidget(ui->goodsSellListWidget);
        ui->operateStackedWidget->setCurrentWidget(ui->operateWidget);
    }
}

void SaleWidget::slot_confirmNoReceiptRefund(int nReasonId)
{
    ui->goodsRefundListWidget->confirmRefund(nReasonId, m_stMemRegInfo);
    m_nSellState = e_normalSell;
    ui->sellStackedWidget->setCurrentWidget(ui->goodsSellListWidget);
    ui->operateStackedWidget->setCurrentWidget(ui->operateWidget);
    clearMemInfo();
}

void SaleWidget::init()
{
    m_pSaleCtrl = new SaleCtrl( this );
    m_pPendingDlg = new PendingDlg();
    m_pStatementDlg = new StatementDlg();
    //    m_pMemberDlg = new MemberDlg();
    m_pOtherOperator = new OtherOperateWidget();
    m_pOtherOperator->activateWindow();
    m_pOtherOperator->show();
    m_pOtherOperator->hide();
    m_pSalemanDlg = new SalemanInfoDlg();
    ui->lastChangeLabel->setText( strFrontOddChange + "￥0.0" );
    initShoppingInfo();
    initDiscountWidget();
    initConnect();
    initGoodsWidget();
    initCategoryWidget();
    ui->goodsSellListWidget->initData();
    //    m_pSaleCtrl->slot_addCategoryData();//test代码
    ui->sellStackedWidget->setCurrentWidget(ui->goodsSellListWidget);
    ui->operateStackedWidget->setCurrentWidget(ui->operateWidget);
    m_refundButtonList.clear();
    m_refundButtonList.append(ui->refund1Button);
    m_refundButtonList.append(ui->refund2Button);
    m_refundButtonList.append(ui->refund3Button);
    m_refundButtonList.append(ui->refund4Button);
    m_refundButtonList.append(ui->refund5Button);
    //    int nRefundLen = m_refundButtonList.length();
    //    for (int i = 0; i < nRefundLen; i++)
    //    {
    //        m_refundButtonList[i]->setText("");
    //        m_refundButtonList[i]->setEnabled(false);
    //    }

    //ui->searchWidget->setSearchFocus();
}

void SaleWidget::initCategoryWidget()
{
    ui->categoryWidget->setUpDownPageButton(ui->categoryFrontButton, ui->categoryNextButton);
    QList<CategoryInfo*> categoryInfoList;
    m_pSaleCtrl->getCategoryInfoList(categoryInfoList);
    ui->categoryWidget->initData(categoryInfoList);
    //    ui->categoryWidget->setCategoryWidgetType( e_categorySet );
    //    ui->categoryWidget->setColumn(m_nCategoryColumn);
}

void SaleWidget::initGoodsWidget()
{
    ui->goodsWidget->setColumn(m_nGoodsOnePageCount, e_goodsSale);
    ui->goodsWidget->setUpDownPageButton( ui->goodsFrontButton, ui->goodsNextButton );
}

void SaleWidget::initShoppingInfo()
{
    MemRegisterInfo_s stMemReg;
    m_stMemRegInfo = stMemReg;

    ui->memberNumLabel->setText( strMemCard );
    ui->memberNameLabel->setText( strMemName );
    ui->lastDateLabel->setText( strLastShoppingTime );
    ui->couponLabel->setText( gstrDisAmt + "￥0.00" );
    QDateTime dt = QDateTime::currentDateTime();
    ui->curDateLabel->setText( strCurTime + dt.toString("hh:mm:ss" ) );
    ui->sumPriceValueLabel->setText( "￥0.00" );
}

//商品价格修改后弹窗
void SaleWidget::slot_onChangeGoodsPrice()
{
    //    m_bGoodsChangedDlg = true;

    //    QList<int> listSelectGoods;
    //    ui->goodsSellListWidget->getSelectGoodsInfo( listSelectGoods );

    //    if(listSelectGoods.length() == 0)
    //    {

    //        WarningDlg *pDlg = new WarningDlg();
    //        pDlg->setTitle( "提示" );
    //        pDlg->setContent( "商品有更新" );
    //        pDlg->exec();
    //        m_bGoodsChangedDlg = false;
    //    }
}

void SaleWidget::initConnect()
{
    connect( ui->titleLabel, SIGNAL( sig_backHomePage() ), this, SLOT( slot_backHomePage() ) );
    connect( ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchGoods(QString)));

    connect( m_pSaleCtrl, SIGNAL(sig_allCategoryInfo(QList<CategoryInfo*>)), ui->categoryWidget, SLOT( slot_addCategoryInfo( QList<CategoryInfo*> ) ) );
    connect( m_pSaleCtrl, SIGNAL( sig_goodsInfo( QList<GoodsInfo> ) ), ui->goodsWidget, SLOT( slot_addGoodsInfo( QList<GoodsInfo> ) ) );
    qRegisterMetaType<GoodsInfo>("GoodsInfo");
    connect( m_pSaleCtrl, SIGNAL(sig_searchGoodsInfo(GoodsInfo)), this, SLOT( slot_addGoodsToSaleList(GoodsInfo) ) );
    connect( m_pSaleCtrl, SIGNAL(sig_stableInfo(EBalanceStandard_Ex,bool)), this, SLOT( slot_stableInfo(EBalanceStandard_Ex, bool) ) );
    connect(m_pSaleCtrl, SIGNAL(sigCategoryGoodsChanged()), this, SLOT(slot_categoryGoodsChanged()));
    qRegisterMetaType<QList<RefundGoodsReason> >("QList<RefundGoodsReason>");
    connect(m_pSaleCtrl, SIGNAL(sigOnGetRefundGoodsReasonList(int,QString,QList<RefundGoodsReason>))
            , this, SLOT(slot_onGetRefundGoodsReasonList(int,QString,QList<RefundGoodsReason>)));
    qRegisterMetaType<SaleHead>("SaleHead");
    qRegisterMetaType<QList<SaleDetails> >("QList<SaleDetails>");
    connect(m_pSaleCtrl, SIGNAL(sigOnSearchReceipt(int,QString,SaleHead,QList<SaleDetails>, float, int))
            , this, SLOT(slot_onSearchReceipt(int,QString,SaleHead,QList<SaleDetails>, float, int)));
    qRegisterMetaType<MemRegisterInfo_s>("MemRegisterInfo_s");
    connect(m_pSaleCtrl, SIGNAL(sigOnMemInfoQueryForRefund(int,QString,MemRegisterInfo_s))
            , this, SLOT(slot_onMemInfoQueryForRefund(int,QString,MemRegisterInfo_s)));

    connect( ui->categoryWidget, SIGNAL( sig_getGoodsList(QString)), this, SLOT( slot_getGoodsList(QString) ) );

    connect( ui->goodsWidget, SIGNAL( sig_addGoodsToSaleList( GoodsInfo )), this, SLOT( slot_addGoodsToSaleList( GoodsInfo ) ) );

    //操作按钮
    connect( ui->operateWidget, SIGNAL(sig_showOtherButton()), this, SLOT( slot_showOtherOperatorWidget() ) );
    connect( ui->operateWidget, SIGNAL( sig_clicked(int) ), this, SLOT( slot_otherOperator(int) ) );
    //    connect( ui->operateWidget, SIGNAL( sig_showMemDlg() ), this, SLOT( slot_showMemDlg() )  );
    //    connect( ui->operateWidget, SIGNAL( sig_showPendingDlg() ), this, SLOT( slot_showPendingDlg() )  );
    //    connect( ui->operateWidget, SIGNAL( sig_deleteSelectGoods() ), this, SLOT( slot_deleteSelectGoods() ) );
    //    connect( ui->operateWidget, SIGNAL( sig_modifyNum() ), ui->goodsSellListWidget, SLOT( slot_ModifyGoodsNum() ) );
    //    connect( ui->operateWidget, SIGNAL( sig_peeling() ), this, SLOT( slot_peeling() ) );

    connect( m_pOtherOperator, SIGNAL(sig_clicked(int)), this, SLOT( slot_otherOperator(int) ) );
    connect( m_pOtherOperator, SIGNAL(sig_wndHide()), this, SLOT( slot_OtherOPeratorWidgetHide() ) );

    connect( m_pPendingDlg, SIGNAL(sig_addSaleHead( const QString& )), this, SLOT( slot_addSaleHead( const QString& ) ) );
    connect( m_pPendingDlg, SIGNAL(sig_hideDlg()), this, SLOT( slot_hidePendingDlg() ) );
    connect( m_pStatementDlg, SIGNAL( sig_wndClose()), this, SLOT( slot_closeStatementWnd() ) );
    connect( m_pStatementDlg, SIGNAL(sig_oddChange(QString)), this, SLOT( slot_oddChange(QString) ) );
    qRegisterMetaType<StatementInfo>("StatementInfo");
    connect( m_pStatementDlg, SIGNAL(sig_updateSaleHead(StatementInfo)), this, SLOT( slot_updateSaleHead(StatementInfo) ) );
    //    connect( m_pMemberDlg, SIGNAL(sig_memInfo(MemRegisterInfo_s)), this, SLOT( slot_updateMemInfo( MemRegisterInfo_s)) );
    //    connect( m_pMemberDlg, SIGNAL(sig_replaceMemCard(QString,QString)), this, SLOT( slot_replaceMemCard( QString, QString ) ) );

    connect( ui->statementButton, SIGNAL(clicked()), this, SLOT( slot_showStatementDlg() ) );
    connect( ui->goodsSellListWidget, SIGNAL(sig_updateGoodsSumPrice(QString,QString)), this, SLOT(slot_updateGoodsSumPrice(QString,QString) ) );
    connect( ui->goodsSellListWidget, SIGNAL( sig_addGoodsToSaleList(SaleDetails)), this, SIGNAL( sig_addGoodsToSaleList( SaleDetails) ) );

    //折扣
    connect( m_pSingleDisDlg, SIGNAL(sig_commit(SaleDetails)), ui->goodsSellListWidget, SLOT( slot_updateGoodsInfo(SaleDetails)) );
    connect( m_pSaleDisDlg, SIGNAL(sig_commit(QList<SaleDetails>,bool)), ui->goodsSellListWidget, SLOT( slot_updateGoodsInfo(QList<SaleDetails>,bool )) );

    connect(ui->goodsRefundListWidget, SIGNAL(sigClickItem()), this, SLOT(slot_clickRefundItem()));
    connect(ui->goodsRefundListWidget, SIGNAL(sigUpdateSumPrice(QString,QString)), this, SLOT(slot_updateGoodsSumPrice(QString, QString)));

    connect( &m_curTimer, SIGNAL(timeout()), this, SLOT(slot_updateCurTimer()));

    connect(CategoryInfoAgent::instance(), SIGNAL(sigOnChangeGoodsPrice()), this, SLOT(slot_onChangeGoodsPrice()));

}

void SaleWidget::initDiscountWidget()
{
    m_pSingleDisDlg = new SingleDiscountDlg();
    m_pSingleDisDlg->hide();
    m_pSaleDisDlg = new SaleDiscountDlg;
    m_pSaleDisDlg->hide();
}

void SaleWidget::initMemInfo()
{
    MemRegisterInfo_s stMemReg;
    m_stMemRegInfo = stMemReg;
    ui->titleLabel->setMemStatus( false );
    ui->goodsSellListWidget->setMemStatus( false );
}

void SaleWidget::updateCategoryGoodsShow()
{
    if(m_bGoodsChangedDlg)
    {
        slot_onChangeGoodsPrice();
    }

    if( !m_bCategoryGoodsChanged ) return;

    QList<CategoryInfo*> categoryInfoList;
    m_pSaleCtrl->updateCategoryAndGoodsInfo();
    m_pSaleCtrl->getCategoryInfoList(categoryInfoList);
    ui->categoryWidget->initData(categoryInfoList);
    m_bCategoryGoodsChanged = false;
}

bool SaleWidget::isDiscount( const QList<SaleDetails>& listSaleDetails )
{
    float fDis = 0.00;
    bool bDis = false;
    int nSize = listSaleDetails.size();
    fDis = listSaleDetails[0].fGrantDisRate;
    for( int i=0; i < nSize; ++i ) {
        if( fDis != listSaleDetails[i].fGrantDisRate ) {
            bDis = true;
            break;
        }
    }

    return bDis;
}

void SaleWidget::refundButtonClick(QString sText)
{
    if (sText == c_sRefundGoods)
    {
        ui->goodsRefundListWidget->refundGoods();
    }
    else if (sText == c_sRefundAllGoods)
    {
        ui->goodsRefundListWidget->refundAllGoods();
    }
    else if (sText == c_sRefundModifyGoods)
    {
        ui->goodsRefundListWidget->modifyRefundGoodsNum();
    }
    else if (sText == c_sRefundRemove)
    {
        int remainLen = ui->goodsRefundListWidget->removeSelectGoods();
        if (remainLen == 0)
        {
            initNoReceiptKeyPage();
        }
        slot_clickRefundItem();
    }
    else if (sText == c_sRefundClear)
    {
        ui->goodsRefundListWidget->clearAllGoods();
        //        if (m_bSearchReceiptAgain)
        //        {
        //            slot_searchGoods(ui->searchWidget->getText());
        //        }
        //        else
        //        {
        initNoReceiptKeyPage();
        clearMemInfo();
        slot_clickRefundItem();
        //        }
    }
}

void SaleWidget::initRefundButtonList(QList<QString> strList)
{
    int nStrLen = strList.length();
    int nRefundLen = m_refundButtonList.length();
    int j = 0;
    for (int i = 0; i < nRefundLen; i++)
    {
        if (i >= (nRefundLen - nStrLen))
        {
            m_refundButtonList[i]->setText(strList[j++]);
        }
        else
        {
            m_refundButtonList[i]->setText("");
        }
        if ((m_refundButtonList[i]->text() == c_sRefundClear)
                || (m_refundButtonList[i]->text() == c_sRefundAllGoods))
        {
            m_refundButtonList[i]->setEnabled(true);
        }
        else
        {
            m_refundButtonList[i]->setEnabled(false);
        }
    }
}

void SaleWidget::initNoReceiptKeyPage()
{
    m_nSellState = e_noReceiptRefund;
    QList<QString> strList;
    strList<<c_sRefundRemove<<c_sRefundClear<<c_sRefundModifyGoods;
    initRefundButtonList(strList);
}

bool SaleWidget::searchSaleByPrice(QString sSearchText)
{
    float fMaxPrice = m_stKPosSet.paramsSet.systemSetParams.nPriceSaleLimit;
    if (!m_stKPosSet.paramsSet.systemSetParams.bPriceSale || (fMaxPrice < 0.0001f))
    {
        return false;
    }
    if(sSearchText[0] == '0')
    {
        return false;
    }

    bool bOk = false;
    float fPrice = sSearchText.toFloat(&bOk);
    if (bOk && (fPrice < fMaxPrice))
    {
        GoodsInfo goodsInfo;
        //        int nId;//商品id
        goodsInfo.sCode = "9999999";//商品编码
        goodsInfo.sBarCode = "9999999";//商品条码
        goodsInfo.sName = QStringLiteral("无码商品");//商品名称
        goodsInfo.sShortName = QStringLiteral("无码商品");//商品简称
        //        goodsInfo.sPinYinName; // 拼音助记码
        //        goodsInfo.sWuBiName; // 五笔助记码
        //        goodsInfo.sPluCode; // plu码
        //        goodsInfo.sPluName; // 商品Plu名称
        //        goodsInfo.sSpeUnit;//要货单位，如50个/卷
        //        goodsInfo.sCategoryName;//大类名称
        //        goodsInfo.nPluGrade; // 商品plu等级
        //        goodsInfo.nCategoryId;//商品分类id,（20161224 需要修改为strCategoryId)
        goodsInfo.fPrice = fPrice;//商品价格
        goodsInfo.fMemberPrice = fPrice; // 会员价
        //        goodsInfo.nTasteType;//商品口味分级
        goodsInfo.bStandard = true;//商品类型(标品，非标品）
        //        goodsInfo.sSaleUnit;//销售单位： 元/公斤
        //        goodsInfo. bPromotion; // 是否促销


        if(m_nSellState == e_normalSell){
            if( ui->goodsSellListWidget->getGoodsNum() == 0 && ! m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) {
                ui->goodsSellListWidget->setMemStatus( true );
            }

            ui->goodsSellListWidget->addGoodsInfo( goodsInfo, "1");

            if( ui->goodsSellListWidget->getGoodsNum() == 1 ) {
                SaleHead stSaleHead;
                ui->goodsSellListWidget->getSaleHead( stSaleHead );
                if( stSaleHead.strOrderNum.isEmpty() ) return true;
                if( m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) return true;
                stSaleHead.strMemCardId = m_stMemRegInfo.stMemInfo.strCardNo;
                ui->goodsSellListWidget->setSaleHead( stSaleHead );

                m_pStatementDlg->updateSaleHeadMemInfo( stSaleHead.strOrderNum, m_stMemRegInfo );
            }
        }
        else{
            slot_addGoodsToSaleList(goodsInfo);
            //            ui->goodsRefundListWidget->addGoodsInfo( goodsInfo, "1");
        }

        return true;
    }
    return false;
}

bool SaleWidget::searchRefundReceipt(QString sSearchText)
{
    //    m_bSearchReceiptAgain = false;
    if (m_nSellState != e_normalSell)
    {
        if (m_pSaleCtrl->isReceiptFormat(sSearchText))
        {
            if (ui->goodsRefundListWidget->getSaleDetailsListLengh() == 0)
            {
                SaleHead saleHead;
                bool bSaleReceipt = m_pSaleCtrl->isSaleReceipt(sSearchText, saleHead);
                if (bSaleReceipt)
                {
                    QList<SaleDetails> saleDetailsList;
                    m_pSaleCtrl->findSaleDetails(sSearchText, saleDetailsList);
                    if (saleDetailsList.length() > 0)
                    {
                        //                        if (!m_pSaleCtrl->isRefundFinish(strGoods))
                        //                        {
                        m_nSellState = e_receiptRefund;

                        saleHead.strReturnOrderNum = sSearchText; // 订单号赋值给退货单号
                        ui->goodsRefundListWidget->initData(saleHead, saleDetailsList, 0.0f, 0);
                        QList<QString> strList;
                        strList<<c_sRefundClear<<c_sRefundGoods<<c_sRefundAllGoods<<c_sRefundModifyGoods;
                        initRefundButtonList(strList);
                        ui->lastChangeLabel->setText(QStringLiteral("上笔找零：￥%1").arg(saleHead.strLastCharge));
                        ui->couponLabel->setText(QStringLiteral("优惠金额：￥%1").arg(QString::number(saleHead.fAllDisAmt, 'f', 2)));
                        if (m_pSaleCtrl != NULL)
                        {
                            if (!saleHead.strMemCardId.isEmpty())
                            {
                                m_pSaleCtrl->getMemInfoForRefundRequest(saleHead.strMemCardId);
                            }
                        }
                        //                        }
                        //                        else
                        //                        {
                        //                            TipsDlg::instance()->releaseCtrl(QStringLiteral("此小票单号已经退过一次，不能再退！"));
                        //                        }
                    }
                    else
                    {
                        if (m_pSaleCtrl->isOnline())
                        {
                            m_pSaleCtrl->searchReceiptRequst(sSearchText);
                            //                            TipsDlg::instance()->releaseCtrl(QStringLiteral("此小票无销售明细，开始远程搜索此小票，请稍等..."));
                        }
                        else
                        {
                            TipsDlg::instance()->releaseCtrl(QStringLiteral("没检测到网络，无法远程搜索此小票！"));
                        }
                    }
                }
                else
                {
                    if (m_pSaleCtrl->isOnline())
                    {
                        m_pSaleCtrl->searchReceiptRequst(sSearchText);
                        //                        TipsDlg::instance()->releaseCtrl(QStringLiteral("本地无此小票，开始远程搜索此小票，请稍等..."));
                    }
                    else
                    {
                        TipsDlg::instance()->releaseCtrl(QStringLiteral("没检测到网络，无法远程搜索此小票！"));
                    }
                }
            }
            else
            {
                TipsDlg::instance()->releaseCtrl(QStringLiteral("请先清空列表数据，才能使用此小票单号！"));
                //                m_bSearchReceiptAgain = true;
            }
            //            ui->searchWidget->clearText();
            //            QString strCategoryId = ui->categoryWidget->getCurCategory();
            //            m_pSaleCtrl->slot_getGoodsList( strCategoryId );
            return true;
        }
    }
    return false;
}

bool SaleWidget::searchBarcodeScalesGoods(QString strGoods)
{
    MTBarcodeProductData_s productData = MTScaleAPIDll::verifyBarcode(strGoods);
    if(productData.plu != NULL)
    {
        if(productData.plu.endsWith("1"))
        {
            productData.plu = productData.plu.left(4);
        }
        ui->searchWidget->clearText();
        QList<GoodsInfo> goodsInfoList;
        m_pSaleCtrl->searchGoodsInfo(productData.plu, goodsInfoList);
        if (goodsInfoList.length() != 1)
        {
            return false;
        }
        GoodsInfo st_goodsInfo = goodsInfoList[0];

        // 前台是否允许销售售价为零的商品
        if( !m_stKPosSet.paramsSet.shopSetParams.bSellZeroGoodsBySeller && st_goodsInfo.fPrice<= 0.00 )
        {
            return false;
        }

        if( !m_stKPosSet.paramsSet.shopSetParams.bSellZeroGoodsBySeller && !m_stMemRegInfo.stMemInfo.strCardNo.isEmpty()
                && st_goodsInfo.fMemberPrice <= 0.00 )
        {
            return false;
        }

        if( ui->goodsSellListWidget->getGoodsNum() == 0 && ! m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) {
            ui->goodsSellListWidget->setMemStatus( true );
        }

        ui->goodsSellListWidget->addGoodsInfo( st_goodsInfo, productData.weight);


        if( ui->goodsSellListWidget->getGoodsNum() == 1 ) {
            SaleHead stSaleHead;
            ui->goodsSellListWidget->getSaleHead( stSaleHead );
            if( stSaleHead.strOrderNum.isEmpty() ) return true;
            if( m_stMemRegInfo.stMemInfo.strCardNo.isEmpty() ) return true;
            stSaleHead.strMemCardId = m_stMemRegInfo.stMemInfo.strCardNo;
            ui->goodsSellListWidget->setSaleHead( stSaleHead );

            m_pStatementDlg->updateSaleHeadMemInfo( stSaleHead.strOrderNum, m_stMemRegInfo );
        }

        return true;
    }
    return false;
}

void SaleWidget::slot_closeStatementWnd()
{
    //关闭结算窗口，销售主界面清空;
    ui->goodsSellListWidget->clearGoodsInfo();
    initShoppingInfo();
    updateCategoryGoodsShow();
    m_pStatementDlg->hide();
    ui->searchWidget->setSearchFocus();
    emit sig_clearGoodsToSaleList();
}

void SaleWidget::slot_oddChange( QString strOddChange )
{
    QString strText = "";
    if( strOddChange.isEmpty() ) {
        strText = strFrontOddChange + "￥0.0";
        ui->lastChangeLabel->setText( strText );
    } else {
        strText = strFrontOddChange + "￥" + strOddChange;
        ui->lastChangeLabel->setText( strText );
    }
    initMemInfo();
    initShoppingInfo();
    ui->searchWidget->setSearchFocus();
}

void SaleWidget::slot_clickRefundItem()
{
    int nSelectIdListLen = ui->goodsRefundListWidget->getSelectIdList().count();
    int nRefunButtonLen = m_refundButtonList.length();
    for (int i = 0; i < nRefunButtonLen; i++)
    {
        if (m_refundButtonList[i]->text() == c_sRefundGoods)
        {
            m_refundButtonList[i]->setEnabled(nSelectIdListLen >= 1);
        }
        else if (m_refundButtonList[i]->text() == c_sRefundModifyGoods)
        {
            m_refundButtonList[i]->setEnabled(nSelectIdListLen == 1);
        }
        else if (m_refundButtonList[i]->text() == c_sRefundRemove)
        {
            m_refundButtonList[i]->setEnabled(nSelectIdListLen >= 1);
        }
    }
}

void SaleWidget::on_refund1Button_clicked()
{
    refundButtonClick(ui->refund1Button->text());
}

void SaleWidget::on_refund2Button_clicked()
{
    refundButtonClick(ui->refund2Button->text());
}

void SaleWidget::on_refund3Button_clicked()
{
    refundButtonClick(ui->refund3Button->text());
}

void SaleWidget::on_refund4Button_clicked()
{
    refundButtonClick(ui->refund4Button->text());
}

void SaleWidget::on_refund5Button_clicked()
{
    refundButtonClick(ui->refund5Button->text());
}

void SaleWidget::slot_updateCurTimer()
{
    ++m_nTimerCount;
    if( m_nTimerCount >= 2 ) {
        QDateTime dt = QDateTime::currentDateTime();
        ui->curDateLabel->setText( strCurTime + dt.toString( "hh:mm:ss" ) );
        m_nTimerCount = 0;
        //        qDebug()<<"SaleWidget::slot_updateCurTimer"<<dt.toString( "MM.dd hh:mm" );
    }
}

void SaleWidget::showEvent(QShowEvent *)
{
    //    int nAdjustWidgetWidth = ui->searchWidget->width();
    QPoint globalPoint = ui->searchWidget->mapToGlobal(QPoint(0, 0));
    const int nOffx = 22;
    int nXPos = globalPoint.x() - nOffx;
    int nYPos = globalPoint.y() + ui->searchWidget->height();
    ui->searchWidget->setKeyboardPos(nXPos, nYPos);
}

void SaleWidget::startCurTimer()
{
    if( m_nTimerId < 0 ){
        m_curTimer.start(500);//500ms
        m_nTimerId = m_curTimer.timerId();
    }
}

void SaleWidget::stopCurTimer()
{
    if( m_nTimerId > 0 ){
        m_curTimer.stop();
        m_nTimerId = -1;
        m_nTimerCount = 0;
    }
}
