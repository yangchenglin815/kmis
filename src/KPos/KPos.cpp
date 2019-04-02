#include "KPos.h"
#include "ui_KPos.h"
#include "../util/GlobalSignal.h"
#include "../util/ScreenInfo.h"
#include <QDebug>
#include <QDesktopWidget>
#include "HttpSignal.h"
#include "KPosSetAgent.h"
#include "KPosIni.h"

//const float gfRzWidth = 800.00;
//const float gfRzHeight = 600.00;

KPos::KPos(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KPos)
    , m_pCustomerDisplayDlg( NULL )
    , m_setGuideWidget(NULL)
{
    ui->setupUi(this);

    setWindowIcon( QIcon( ":/shareImages/kpos_logo.png" ) );
    setWindowFlags( Qt::FramelessWindowHint );
    //    this->setStyleSheet( "background-color: rgb(81, 80, 80);" );

    init();
    initConnect();
    //setCursor(Qt::BlankCursor); //隐藏鼠标
    ui->stackedWidget->setCurrentWidget(ui->HomePage);
    if(KPosIni::getSetGuide()){
        if(m_setGuideWidget == NULL){
            m_setGuideWidget = new SetGuideWidget;
            ui->HomePage->initSetGuideObj(m_setGuideWidget);
            connect(m_setGuideWidget, SIGNAL(sigOnShowHomePage()), this, SLOT(slot_showHomeWidget()));
        }
    }
}

KPos::~KPos()
{
    delete ui;
}

void KPos::setRemoteADList(QList<QString> remoteADList)
{
    if (m_pCustomerDisplayDlg != NULL)
    {
        m_pCustomerDisplayDlg->setRemoteAdList(remoteADList);
    }
}

void KPos::reInit()
{
    ui->SalePage->reInit();
}

void KPos::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED( event )


    //this->move( -800, 0 );//test代码
    //    QRect app_rect = this->geometry();
    //    multiScreen( this, app_rect );
    //this->resize( 800, 600 );

    //    if( this->width() == 800 && this->height() == 600 ) {
    //        float fRatioWidth = this->width()/gfRzWidth;
    //        float fRatioHeight = this->height()/gfRzHeight;
    //        ui->SalePage->setRation( fRatioWidth, fRatioHeight );
    //    } else if( this->width() == 1920 && this->height() == 1080 ){
    //        float fRatioWidth = this->width()/gfRzWidth;
    //        float fRatioHeight = this->height()/gfRzHeight;
    //        ui->SalePage->setRation( fRatioWidth, fRatioHeight );
    //    }


}

void KPos::init()
{
    //1. 确定屏幕数量
    QDesktopWidget *pDesktopWidget = QApplication::desktop();
//    int nPrimaryIndex = pDesktopWidget->primaryScreen();//获取主屏幕的索引值
//    QRect rctPrimary = pDesktopWidget->screenGeometry( nPrimaryIndex );//主屏幕的size
    int nNumScreens = pDesktopWidget->numScreens();
    if( nNumScreens > 1 ) {
        QRect rct1 =  pDesktopWidget->screenGeometry( 1 );
        m_pCustomerDisplayDlg = new CustomerDisplayDlg();
        int nX = rct1.x() + (rct1.width()-800)/2;
        int nY = rct1.y() + (rct1.height() -600)/2;
        m_pCustomerDisplayDlg->move( nX, nY );
//        m_pCustomerDisplayDlg->move( 0, 0 );
        m_pCustomerDisplayDlg->show();
    }
//    ScreenInfo::resetGrid(this);
    this->resize(ScreenInfo::width(), ScreenInfo::height());
}

void KPos::initConnect()
{
    connect( ui->HomePage, SIGNAL( sig_minimizeWidget() ), this, SLOT( slot_minimizeWidget() ) );
    connect( ui->HomePage, SIGNAL( sig_closeWidget() ), this, SLOT( slot_closeWidget() ) );
    connect( ui->HomePage, SIGNAL( sig_showSaleWidget() ), this, SLOT( slot_showSaleWidget() ) ); // 销售
    connect( ui->HomePage, SIGNAL( sig_showReportWidget() ), this, SLOT( slot_showReportWidget() ) );
    connect( ui->HomePage, SIGNAL( sig_showSetWidget() ), this, SLOT( slot_showSetWidget() ) ); // 设置
    connect( ui->HomePage, SIGNAL( sig_showInStockWidget() ), this, SLOT( slot_showInStockWidget() ) ); // 设置
    connect( ui->HomePage, SIGNAL( sig_showOutStockWidget() ), this, SLOT( slot_showOutStockWidget() ) ); // 设置
    connect( KPosSetAgent::instance(), SIGNAL(sigDownloadKPosSetFinished()), this, SLOT( slot_downloadKposSet()));
    //    connect( ui->HomePage, SIGNAL( sig_showTrainWidget() ), this, SLOT( slot_showTrainWidget() ) );
    //    connect( ui->HomePage, SIGNAL( sig_showModifyPwdWidget() ), this, SLOT( slot_modifyPwdWidget() ) );
    connect(ui->HomePage, SIGNAL(sig_showOrderGoodsWidget()), this, SLOT(slot_showOrderGoodsWidget())); // 要货
    //    connect(ui->HomePage, SIGNAL(sig_showReceivingWidget()), this, SLOT(slot_showReceivingWidget())); // 收货
    connect(ui->HomePage, SIGNAL(sig_showStockingWidget()), this, SLOT(slot_showStockingWidget())); // 盘点
    connect(ui->HomePage, SIGNAL(sig_showAdjustPriceWidget()), this, SLOT(slot_showAdjustPriceWidget())); // 改价
    connect(ui->HomePage, SIGNAL(sig_showbarCodeScaleWidget()), this, SLOT(slot_showbarCodeScaleWidget())); // 条码秤管理
    connect(ui->HomePage, SIGNAL(sig_showResetKeyWidget()), this, SLOT(slot_showResetKeyWidget()));  // 修改密码
    connect(ui->HomePage, SIGNAL(sig_showAccountManageWidget()), this, SLOT(slot_showAccountManageWidget())); // 账号管理
    connect(ui->HomePage, SIGNAL(sig_showSaleDetialWidget()), this, SLOT(slot_showSaleDetialWidget())); // 销售明细
    connect(ui->HomePage, SIGNAL(sig_showReportLossWidget()), this, SLOT(slot_showReportLossWidget())); // 报损
    connect(ui->HomePage, SIGNAL(sig_showGoodsManageWidget()), this, SLOT(slot_showGoodsManageWidget())); // 商品管理

    // 销售
    connect(ui->SalePage, SIGNAL(sig_backHomePage()), this, SLOT( slot_showHomeWidget()));
    connect(ui->SalePage, SIGNAL(sig_addGoodsToSaleList(SaleDetails)), this, SLOT(slot_addGoodsToSaleList(SaleDetails)));
    connect(ui->SalePage, SIGNAL(sig_delGoodsToSaleList(int)), this, SLOT(slot_delGoodsToSaleList(int)) );
    connect(ui->SalePage, SIGNAL(sig_clearGoodsToSaleList()), this, SLOT(slot_clearGoodsToSaleList()));
    connect( ui->SalePage, SIGNAL(sig_loginMem(bool)), this, SLOT( slot_loginMem( bool ) ) );
    connect(ui->SalePage, SIGNAL(sig_lockScreen()), this, SIGNAL(sig_lockScreen()));
    connect(ui->SalePage, SIGNAL(sigCategoryGoodsChanged()), this, SLOT(slot_updateSetInfo()));

    connect(ui->SetPage, SIGNAL(sig_backHomePage()), this, SLOT(slot_showHomeWidget())); // 设置
    connect(ui->orderAndCheckPage, SIGNAL(sig_backHomePage()), this, SLOT(slot_showHomeWidget()));
    connect(ui->inStockPage, SIGNAL(sigReturnClicked()), this, SLOT(slot_showHomeWidget()));  // 入库
    connect(ui->inStockPage, SIGNAL(sigAddQuickGoods()), ui->SalePage, SLOT(slot_fastCreateDocument())); // 快速建档
    connect(ui->goodsManagePage, SIGNAL(sigFastCreateDocument()), ui->SalePage, SLOT(slot_fastCreateDocument()));

    connect(ui->outStockPage, SIGNAL(sigReturnClicked()), this, SLOT(slot_showHomeWidget()));
    //    connect(ui->receiveOrdersPage, SIGNAL(sigReturnClicked()), this, SLOT(slot_showHomeWidget())); // 收货
    connect(ui->stockPage, SIGNAL(sigReturnClicked()), this, SLOT(slot_showHomeWidget())); // 盘点
    connect(ui->reportChartsPage, SIGNAL(sigReturnClicked()), this, SLOT(slot_showHomeWidget())); // 报表
    connect(ui->adjustPricePage, SIGNAL(sigReturnClicked()), this, SLOT(slot_showHomeWidget())); // 改价
    connect(ui->barCodeScalePage, SIGNAL(sigReturnClicked()), this, SLOT(slot_showHomeWidget())); // 条码秤管理
    connect(ui->resetKeyPage, SIGNAL(sig_backHomePage()), this, SLOT(slot_showHomeWidget())); // 修改密码
    connect(ui->accountManagePage, SIGNAL(sig_backHomePage()), this, SLOT(slot_showHomeWidget())); // 账号管理
    connect(ui->saleDetialPage, SIGNAL(sigReturnClicked()), this, SLOT(slot_showHomeWidget())); // 销售明细
    connect(ui->reportLossPage, SIGNAL(sigReturnClicked()), this, SLOT(slot_showHomeWidget())); // 报损
    connect(ui->goodsManagePage, SIGNAL(sigReturnClicked()), this, SLOT(slot_showHomeWidget())); // 商品管理

    connect( KPosSetAgent::instance(), SIGNAL(sigKeySetChanged()), ui->SalePage, SLOT( slot_keySetChanged() ) );  
}

//多屏显示
bool KPos::multiScreenShow( QWidget *p_full_widget, QRect app_rect )
{
    QDesktopWidget *pDesktopWidget = QApplication::desktop();
    QWidget *pWidget = pDesktopWidget->screen( pDesktopWidget->screenCount() - 1 );
    int n_total_width = 0;
    if( pWidget->x() < 0 ){  //若在左边只考虑2个屏
        n_total_width = pWidget->x();
        for( int n_screen_num = pDesktopWidget->screenCount() - 1; n_screen_num > -1; n_screen_num-- ){
            pWidget = pDesktopWidget->screen( n_screen_num );
            if( ( app_rect.x() < ( n_total_width + pWidget->rect().width()/2 ) ) &&
                    ( app_rect.x() >  n_total_width - pWidget->width() ) ){
                p_full_widget->move( n_total_width, pWidget->y() );
                p_full_widget->setGeometry( n_total_width, pWidget->y(), pWidget->width(), pWidget->height() );
                break;
            } else {
                pWidget = pDesktopWidget->screen( 0 );
                p_full_widget->move( 0, pWidget->y() );
                p_full_widget->setGeometry( 0, pWidget->y(), pWidget->width(), pWidget->height() );
            }
        }
    } else {    //多屏在右边
        for( int n_screen_num = 0; n_screen_num < pDesktopWidget->screenCount(); n_screen_num++ ){
            pWidget = pDesktopWidget->screen( n_screen_num );
            if( ( app_rect.x() < ( n_total_width + pWidget->rect().width()/2 ) ) &&
                    ( app_rect.x() > ( n_total_width - pWidget->width() ) ) ){
                p_full_widget->move( n_total_width, pWidget->y() );
                p_full_widget->setGeometry( n_total_width, pWidget->y(), pWidget->width(), pWidget->height() );
                break;
            } else if( ( app_rect.x() > ( n_total_width + pWidget->rect().width()/2 ) ) &&
                       ( app_rect.x() < ( n_total_width + pWidget->rect().width() ) ) ){
                if( n_screen_num + 1 < pDesktopWidget->screenCount() ){
                    QWidget *p_widget1 = pDesktopWidget->screen( n_screen_num + 1 );
                    p_full_widget->move( n_total_width + pWidget->rect().width(), p_widget1->y() );
                    p_full_widget->setGeometry( n_total_width + pWidget->rect().width(), p_widget1->y(), p_widget1->width(), p_widget1->height() );
                }else{
                    p_full_widget->move( n_total_width, pWidget->y() );
                    p_full_widget->setGeometry( n_total_width, pWidget->y(), pWidget->width(), pWidget->height() );
                }
                break;
            }else{
                n_total_width += pWidget->rect().width();
            }
        }
    }

    return false;
}

void KPos::slot_minimizeWidget()
{
    showMinimized();
}

void KPos::slot_closeWidget()
{
    //    m_pClientCashSubmit = new ClientCashSubmit;
    //    connect(m_pClientCashSubmit, SIGNAL(sigClose()), this, SIGNAL(sig_closeWnd()));
    //    m_pClientCashSubmit->exec();

    //    if( ui->SetPage->getKPosSet().paramsSet.shopSetParams.bHandinCashBySeller  ) {
    ////        弹出交款对话框

    //        m_pClientCashSubmit = new ClientCashSubmit;
    //        connect(m_pClientCashSubmit, SIGNAL(sigClose()), this, SIGNAL(sig_closeWnd()));
    //        m_pClientCashSubmit->exec();
    //    } else {
    emit sig_closeWnd();
    //    }
}

void KPos::slot_showHomeWidget()
{
    ui->stackedWidget->setCurrentWidget(ui->HomePage);
    KPosIni::setSetGuide(false);
    if( m_pCustomerDisplayDlg ) {
        m_pCustomerDisplayDlg->setCurrentIndex(0);
    }
}

void KPos::slot_showSaleWidget()
{
    ui->stackedWidget->setCurrentWidget(ui->SalePage);
    ui->SalePage->beginSale();

    KPosSet stKPosSet;
    KPosSetAgent::instance()->getKPosSetInfo( stKPosSet );
    ui->SalePage->setKPosSet( stKPosSet );
}

void KPos::slot_showResetKeyWidget(){
    ui->stackedWidget->setCurrentWidget(ui->resetKeyPage);
}

void KPos::slot_showAccountManageWidget()
{
    QList<CategoryInfo*> categoryInfoList;
    ui->SalePage->getCategoryInfoList(categoryInfoList);
    ui->accountManagePage->initEmployeeList();
    ui->stackedWidget->setCurrentWidget(ui->accountManagePage);
}

void KPos::slot_showSaleDetialWidget()
{
    ui->saleDetialPage->initSaleDetialList();
    ui->stackedWidget->setCurrentWidget(ui->saleDetialPage);
}

void KPos::slot_showReportLossWidget() // 报损
{
    QList<CategoryInfo*> categoryInfoList;
    ui->SalePage->getCategoryInfoList(categoryInfoList);
    ui->reportLossPage->setCategoryList(categoryInfoList);
    ui->reportLossPage->initReportLossCtrl();
    ui->stackedWidget->setCurrentWidget(ui->reportLossPage);
}

void KPos::slot_showGoodsManageWidget()
{
   ui->goodsManagePage->clearData();
   ui->goodsManagePage->initGoodsManageCtrl();
   ui->stackedWidget->setCurrentWidget(ui->goodsManagePage);
}

void KPos::slot_showReportWidget()
{
    ui->stackedWidget->setCurrentWidget(ui->reportChartsPage);
}

void KPos::slot_showSetWidget()
{
    slot_updateSetInfo();
    ui->SetPage->init(); // 更新配置中商品配置以外的配置
    ui->stackedWidget->setCurrentWidget(ui->SetPage);
    ui->SetPage->initSetGuideObj(m_setGuideWidget);
}
void KPos::slot_showInStockWidget()
{
    QList<CategoryInfo*> categoryInfoList;
    ui->SalePage->getCategoryInfoList(categoryInfoList);
    ui->inStockPage->setCategoryList(categoryInfoList);
    ui->inStockPage->test();
    ui->stackedWidget->setCurrentWidget(ui->inStockPage);
}

void KPos::slot_showOutStockWidget()
{
    QList<CategoryInfo*> categoryInfoList;
    ui->SalePage->getCategoryInfoList(categoryInfoList);
    ui->outStockPage->setCategoryList(categoryInfoList);
    ui->outStockPage->test();
    ui->stackedWidget->setCurrentWidget(ui->outStockPage);
}

void KPos::slot_updateSetInfo()
{
    QList<CategoryInfo*> categoryInfoList;
    ui->SalePage->getCategoryInfoList(categoryInfoList);
    ui->SetPage->setCategoryInfoList(categoryInfoList); // 更新销售页面中分类信息
    ui->adjustPricePage->setCategoryList(categoryInfoList); // 更新改价页面中分类信息
    ui->reportLossPage->setCategoryList(categoryInfoList); // 更新报损页面中分类信息
}

void KPos::slot_downloadKposSet()
{
    ui->SetPage->init(); // 更新配置中商品配置以外的配置
}

void KPos::slot_showTrainWidget()
{
    //    ui->stackedWidget->setCurrentWidget(ui->TrainPage);
}

void KPos::slot_modifyPwdWidget()
{
    //    ui->stackedWidget->setCurrentWidget(ui->ModifyPwdPage);
}

void KPos::slot_showOrderGoodsWidget()
{
    ui->stackedWidget->setCurrentWidget(ui->orderAndCheckPage);
    ui->orderAndCheckPage->test();
}

void KPos::slot_showReceivingWidget()
{
    ui->stackedWidget->setCurrentWidget(ui->receiveOrdersPage);
    ui->receiveOrdersPage->test();
}

void KPos::slot_showStockingWidget()
{
    QList<CategoryInfo*> categoryInfoList;
    ui->SalePage->getCategoryInfoList(categoryInfoList);
    ui->stockPage->setCategoryList(categoryInfoList);
    ui->stockPage->test();
    ui->stackedWidget->setCurrentWidget(ui->stockPage);
}

void KPos::slot_showAdjustPriceWidget()
{
    QList<CategoryInfo*> categoryInfoList;
    ui->SalePage->getCategoryInfoList(categoryInfoList);
    ui->adjustPricePage->setCategoryList(categoryInfoList);
    ui->adjustPricePage->test();
    ui->stackedWidget->setCurrentWidget(ui->adjustPricePage);
}

void KPos::slot_showbarCodeScaleWidget()
{
    ui->barCodeScalePage->test();
    ui->stackedWidget->setCurrentWidget(ui->barCodeScalePage);
}

void KPos::slot_addGoodsToSaleList( SaleDetails stSaleDetailsInfo )
{
    if( !m_pCustomerDisplayDlg ) return;

    m_pCustomerDisplayDlg->addGoodsToSaleList( stSaleDetailsInfo );
}

void KPos::slot_delGoodsToSaleList( int nSaleDetailsPos )
{
    if( !m_pCustomerDisplayDlg ) return;

    m_pCustomerDisplayDlg->delGoodsToSaleList( nSaleDetailsPos );
}

void KPos::slot_clearGoodsToSaleList()
{
    if( !m_pCustomerDisplayDlg ) return;

    m_pCustomerDisplayDlg->clearGoodsToSaleList();
}

void KPos::slot_loginMem( bool bMember )
{
    if( !m_pCustomerDisplayDlg ) return;

    m_pCustomerDisplayDlg->loginMember( bMember );
}
