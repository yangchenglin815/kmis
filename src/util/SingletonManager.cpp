#include "SingletonManager.h"
#include "HttpSignal.h"
#include "GlobalSignal.h"
#include "FilePathManage.h"
#include "../HttpClient/HttpClient.h"
#include "../Agent/PosInfoAgent.h"
#include "../Agent/LoginKPosAgent.h"
#include "../Agent/CategoryInfoAgent.h"
#include "../Agent/OnlineStateAgent.h"
#include "../Agent/CheckKPosUpdateAgent.h"
#include "../Agent/KPosSetAgent.h"
#include "../Agent/MemCardInfoAgent.h"
#include "../Agent/OrderGoodsAgent.h"
#include "../Agent/OrderGoodsCheckAgent.h"
#include "../Agent/PayDetailsAgent.h"
#include "../Agent/SaleDetailsAgent.h"
#include "../Agent/SaleHeadAgent.h"
#include "../Agent/SatementAgent.h"
#include "../Agent/AdjustPriceAgent.h"
#include "../Database/PosDBFactory.h"
#include "HttpDownloadMgr.h"
#include "SatementAgent.h"
#include "KPosStartHintDlg.h"
#include "../util/KPosXMl.h"
#include "../callOuterDll/KPosAddDll.h"
#include "BalanceManage.h"
#include "../KPosSet/AdjustPositionWidget.h"
#include "MemCardInfoAgent.h"
#include "../callOuterDll/MTComAPIMananger.h"
#include "ScreenInfo.h"
#include "constData.h"

SingletonManager::SingletonManager()
{
    CategoryInfoAgent::instance();
    CheckKPosUpdateAgent::instance();
    KPosSetAgent::instance();
    LoginKPosAgent::instance();
    MemCardInfoAgent::instance();
    OnlineStateAgent::instance();
    OrderGoodsAgent::instance();
    OrderGoodsCheckAgent::instance();
    PayDetailsAgent::Instance();
    PosInfoAgent::instance();
    SaleDetailsAgent::Instance();
    SaleHeadAgent::Instance();
    SatementAgent::Instance();
    AdjustPriceAgent::instance();

    HttpSignal::instance();
    GlobalSignal::instance();
    FilePathManage::instance();
    HttpClient::instance();
    PosDBFactory::getPosDB();

    HttpDownloadMgr::instance();
    SatementAgent::Instance();
    KPosStartHintDlg::instance();
    KPosXMl::instance();
    BalanceManage::instance();
//    BalanceManage::instance()->startCheckBalance();
    AdjustPositionWidget::instance();
    MemCardInfoAgent::instance();
    ScreenInfo::initScreenInfo();
    g_heightRate=ScreenInfo::heightRate();
    g_widthRate=ScreenInfo::widthRate();
//    MTComAPIMananger::instance()->openMTCom();
}

SingletonManager::~SingletonManager()
{
    HttpSignal::instance()->deleteLater();
    GlobalSignal::instance()->deleteLater();
    FilePathManage::instance()->release();
    HttpClient::instance()->deleteLater();
    PosInfoAgent::instance()->deleteLater();
    LoginKPosAgent::instance()->deleteLater();
    CategoryInfoAgent::instance()->deleteLater();
    OnlineStateAgent::instance()->deleteLater();
    PosDBFactory::release();
    SaleHeadAgent::Release();
    SaleDetailsAgent::Release();
    HttpDownloadMgr::instance()->deleteLater();
    SatementAgent::Release();
//    KPosStartHintDlg::instance()->deleteLater();
    KPosXMl::instance()->release();
    BalanceManage::Release();
    AdjustPositionWidget::instance()->deleteLater();
    MTComAPIMananger::instance()->release();
}
