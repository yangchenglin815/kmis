#include "LoginKPosCtr.h"
#include "LoginKPosAgent.h"
#include "CategoryInfoAgent.h"
#include "KPosSetAgent.h"
#include "AdjustPriceAgent.h"
#include "../data/enumData.h"
#include "../util/KPosIni.h"
#include "../util/GlobalSignal.h"
#include "../util/FilePathManage.h"
#include "../util/CommonFun.h"
#include "SatementAgent.h"
#include "HttpSignal.h"
#include "SaleHeadAgent.h"
#include "SaleDetailsAgent.h"
#include "PayDetailsAgent.h"
#include "MemCardInfoAgent.h"
#include "PosInfoAgent.h"
#include "OnlineStateAgent.h"
#include "QuickAddGoodsAgent.h"
#include "ClientCashSubmitTable.h"
#include "../Database/PosDBFactory.h"
#include <QDebug>

LoginKPosCtr::LoginKPosCtr(QObject *parent)
    : QObject(parent)
    , m_nRemoteAdNum(-1)
    , m_bLogout(false)
{
    initConnect();
}

void LoginKPosCtr::loginKPosRequest(QString sUserCode, QString sPassword)
{
    LoginKPosAgent::instance()->loginKPosRequest(sUserCode, sPassword);
}

void LoginKPosCtr::getAllUserInfoRequest()
{
    LoginKPosAgent::instance()->getAllUserInfoRequest();
}

void LoginKPosCtr::logoutRequest(QString sSubmitMoney)
{
    m_timer.stop();
    LoginKPosAgent::instance()->logoutRequest(sSubmitMoney);
}

void LoginKPosCtr::printLogoutReceipt()
{
    LoginKPosAgent::instance()->getLogoutReceiptData();
}

void LoginKPosCtr::checkUploadAllReceipt()
{
    connect(SatementAgent::Instance(), SIGNAL(sig_uploadReceiptSuc(bool)), this, SLOT(slot_finishReceiptUpload(bool)));
    if (OnlineStateAgent::instance()->isOnline())
    {
        SatementAgent::Instance()->uploadAllReceipt();
    }
    else
    {
        disconnect(SatementAgent::Instance(), SIGNAL(sig_uploadReceiptSuc(bool)), this, SLOT(slot_finishReceiptUpload(bool)));
        emit sigFinisReceipUpload(false);
    }
}

void LoginKPosCtr::slot_onLoginKPos(int nCode, QString sMsg, bool isAllowLocalLogin)
{
    m_bLogout = false;
    if(nCode == e_success || (nCode == e_connectServerError && isAllowLocalLogin))
    {
        bool bInitFinished = LoginKPosAgent::instance()->isInitFinish();
        if (!bInitFinished)
        {
            CategoryInfoAgent::instance()->getAllGoodsInfoRequest(bInitFinished);
        }
    }  

    emit sigOnLoginKPos(nCode, sMsg, isAllowLocalLogin);
}

void LoginKPosCtr::slot_uploadReceiptSuc()
{
    PosInfoAgent::instance()->pushClientCash();
    //jiaokuan
}

//void LoginKPosCtr::slot_onUploadClientCashSubmit(int nCode, QString sMsg)
//{
//    bool bInitFinished = LoginKPosAgent::instance()->isInitFinish();
//    CategoryInfoAgent::instance()->getAllGoodsInfoRequest(bInitFinished);
//}

void LoginKPosCtr::slot_onGetAllGoods(int nCode, QString sMsg)
{
    emit sigOnGetAllGoods(nCode, sMsg);

    if (nCode == e_success)
    {
        CategoryInfoAgent::instance()->getAllGoodsPriceRequest();
    }
    else
    {
        CategoryInfoAgent::instance()->getCategoryRequest();
    }
}

void LoginKPosCtr::slot_onGetChangedGoods(int nCode, QString sMsg)
{
    Q_UNUSED( sMsg )

    if (nCode == e_success)
    {
        CategoryInfoAgent::instance()->getAllGoodsPriceRequest();
    }
    else
    {
        CategoryInfoAgent::instance()->getCategoryRequest();
    }
}

void LoginKPosCtr::slot_onGetAllGoodsPrice(int nCode, QString sMsg)
{
    emit sigOnGetAllGoodsPrice(nCode, sMsg);

    CategoryInfoAgent::instance()->getCategoryRequest();
}

void LoginKPosCtr::slot_onGetCategory(int nCode, QString sMsg)
{
    emit sigOnGetCategory(nCode, sMsg);
    bool bInitFinished = LoginKPosAgent::instance()->isInitFinish();
    QString sLastTime = "";
    if (bInitFinished)
    {
        sLastTime = KPosIni::getKPosSetLastUpdateTime();
    }
    KPosSetAgent::instance()->downloadKPosSetRequest(sLastTime);
}

void LoginKPosCtr::slot_onLogoutKPos(int nCode, QString sMsg)
{
    m_bLogout = true;
    LoginKPosAgent::instance()->setInitFinishFlag(false);
    emit sigOnLogoutKPos(nCode, sMsg);
}

void LoginKPosCtr::slot_downloadKPosSetFinished()
{
    bool bInitFinished = LoginKPosAgent::instance()->isInitFinish();
    if (!bInitFinished)
    {
        if (m_bLogout)
        {
            return;
        }
        LoginKPosAgent::instance()->setInitFinishFlag(true);
        emit sigDownloadKPosSetFinished();
        slot_paramsSetChanged();
    }
    m_timer.start(3*60*1000); // 3分钟检测一次
}

void LoginKPosCtr::slot_timeout()
{
//    KPosSetAgent::instance()->uploadKPosSetRequest(false);
//    bool bInitFinished = LoginKPosAgent::instance()->isInitFinish();
//    CategoryInfoAgent::instance()->getAllGoodsInfoRequest(bInitFinished);
    qDebug()<<"ding shi jian ce le 9999999";
    m_timer.stop();

    SatementAgent::Instance()->uploadAllReceipt();
}

void LoginKPosCtr::slot_sendGetAllGoodsRequest(bool bSuccess)
{
    CategoryInfoAgent::instance()->getAllGoodsInfoRequest(true);
}

void LoginKPosCtr::slot_paramsSetChanged()
{
    KPosSet stKPosSet;
    KPosSetAgent::instance()->getKPosSetInfo( stKPosSet );

    QList<QString> listOrderNum;
    SaleHeadAgent::Instance()->findSaleHead( stKPosSet.paramsSet.systemSetParams.nDataSaveDays, listOrderNum );

    int nSize = listOrderNum.size();
    for( int i=0; i<nSize; ++i )
    {
        QString strOrderNum = listOrderNum[i];
        if( strOrderNum.isEmpty() ) continue;

        SaleHeadAgent::Instance()->deleteSaleHeadTable( strOrderNum );
        SaleDetailsAgent::Instance()->deleteSaleDetailsTable( strOrderNum );
        PayDetailsAgent::Instance()->deletePayDetailsTable( strOrderNum );
    }
    //删除充值小票信息
    MemCardInfoAgent::instance()->deleteMemReChargeDetailsTable( stKPosSet.paramsSet.systemSetParams.nDataSaveDays );
}

void LoginKPosCtr::slot_screenSetChanged(ScreenSet screenSet)
{

//    m_pHttpDownloadInterface = new HttpDownloadInterface;



//    int nLen1 = screenSet.remoteADList.length();
    int nId;
    QString sPath = "";
    QString sDir = "";
//    for (int i = 0; i < nLen1; i++)
//    {
//        sPath = screenSet.remoteADList[i].sPath;
//        sDir = FilePathManage::instance()->getRemoteADPath();
//        HttpDownloadInterface* httpDownloadInterface = new HttpDownloadInterface;
//        GlobalSignal::instance()->sigAddHttpDownTask(sPath, sDir, httpDownloadInterface);
//    }

    int nLen2 = screenSet.remoteADList.length();
    m_nRemoteAdNum = nLen2;
    for (int i = 0; i < nLen2; i++)
    {
        nId = screenSet.remoteADList[i].nId;
        sPath = screenSet.remoteADList[i].sPath;
        sDir = FilePathManage::instance()->getLocalADPath();
        HttpDownloadInterface* httpDownloadInterface = new HttpDownloadInterface;
        httpDownloadInterface->setTaskId(nId);
        connect(httpDownloadInterface, SIGNAL(sigDownFinished(bool,QString,int)), this, SLOT(slot_downFinished(bool,QString,int)));
        m_httpDownloadInterfaceMap.insert(nId, httpDownloadInterface);
        GlobalSignal::instance()->sigAddHttpDownTask(sPath, sDir, httpDownloadInterface);
    }
}

void LoginKPosCtr::slot_downFinished(bool bSuccess, QString sPath, int nTaskId)
{
    m_nRemoteAdNum--;
    HttpDownloadInterface* pHttpDownloadInterface = m_httpDownloadInterfaceMap.value(nTaskId);
    if (pHttpDownloadInterface != NULL)
    {
        pHttpDownloadInterface->deleteLater();
        m_httpDownloadInterfaceMap.remove(nTaskId);
    }

    if (bSuccess)
    {
        m_remoteAdPathList.append(sPath);
    }

    if (m_nRemoteAdNum == 0)
    {
        KPosIni::setRemoteADPathList(m_remoteAdPathList);
        emit sigRemoteADChanged(m_remoteAdPathList);
    }
}

void LoginKPosCtr::slot_finishReceiptUpload(bool bSuccess)
{
    disconnect(SatementAgent::Instance(), SIGNAL(sig_uploadReceiptSuc(bool)), this, SLOT(slot_finishReceiptUpload(bool)));
    emit sigFinisReceipUpload(bSuccess);
}

void LoginKPosCtr::initConnect()
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(slot_timeout()));
    connect(LoginKPosAgent::instance(), SIGNAL(sigOnLoginKPos(int, QString, bool)), this, SLOT(slot_onLoginKPos(int, QString, bool)));
    connect(LoginKPosAgent::instance(), SIGNAL(sigOnLogoutKPos(int,QString)), this, SLOT(slot_onLogoutKPos(int,QString)));
    connect(CategoryInfoAgent::instance(), SIGNAL(sigOnGetAllGoods(int, QString)), this, SLOT(slot_onGetAllGoods(int, QString)));
    connect(CategoryInfoAgent::instance(), SIGNAL(sigOnGetChangedGoods(int,QString))
            , this, SLOT(slot_onGetChangedGoods(int,QString)));
    connect(CategoryInfoAgent::instance(), SIGNAL(sigOnGetAllGoodsPrice(int,QString)), this, SLOT(slot_onGetAllGoodsPrice(int,QString)));
    connect(CategoryInfoAgent::instance(), SIGNAL(sigOnGetCategory(int, QString)), this, SLOT(slot_onGetCategory(int, QString)));
    connect(KPosSetAgent::instance(), SIGNAL(sigDownloadKPosSetFinished()), this, SLOT(slot_downloadKPosSetFinished()));
    connect(KPosSetAgent::instance(), SIGNAL(sigStartUpdateThread()), this, SLOT(slot_timeout()));
    qRegisterMetaType<ScreenSet>("ScreenSet");
    connect(KPosSetAgent::instance(), SIGNAL(sigScreenSetChanged(ScreenSet)), this, SLOT(slot_screenSetChanged(ScreenSet)));
    connect(SatementAgent::Instance(), SIGNAL(sig_uploadReceiptSuc(bool)), this, SLOT(slot_sendGetAllGoodsRequest(bool))); // slot_sendGetAllGoodsRequest()
//    connect(PosInfoAgent::instance(), SIGNAL(sigOnUploadClientCashSubmit(int,QString)), this, SLOT(slot_onUploadClientCashSubmit(int,QString)));
    connect(AdjustPriceAgent::instance(), SIGNAL(sigStartUpdateThread()), this, SLOT(slot_timeout()));
    connect(QuickAddGoodsAgent::instance(), SIGNAL(sigStartUpdateThread()), this, SLOT(slot_timeout()));

    connect( KPosSetAgent::instance(), SIGNAL(sigParamsSetChanged()), this, SLOT( slot_paramsSetChanged() ) );
}
