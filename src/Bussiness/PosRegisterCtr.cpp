#include "PosRegisterCtr.h"
#include "../Agent/PosInfoAgent.h"
#include "../Agent/CheckKPosUpdateAgent.h"
#include "../Agent/OnlineStateAgent.h"
#include "../data/enumData.h"
#include <QDebug>
#include "SaleHeadAgent.h"

PosRegisterCtr::PosRegisterCtr(QObject *parent)
    : QObject(parent)
{
    initConnect();
}

void PosRegisterCtr::checkRegisterResultRequest()
{
    PosInfoAgent::instance()->checkRegisterResultRequest();
}

void PosRegisterCtr::getShopInfoRequest(QString sCorpID, QString sShopCode)
{
    PosInfoAgent::instance()->getShopInfoRequest(sCorpID, sShopCode);
}

void PosRegisterCtr::registerPosRequest(QString sCorpID, QString sShopCode)
{
    PosInfoAgent::instance()->registPosRequest(sCorpID, sShopCode);
}

void PosRegisterCtr::checkKPosUpdateRequest()
{
    CheckKPosUpdateAgent::instance()->checkKPosUpdateRequest();
}

void PosRegisterCtr::checkOnlineStateRequest()
{
    m_timer.start();
}

void PosRegisterCtr::uploadClientCashSubmitRequest(QString sSubmitAmount)
{
    PosInfoAgent::instance()->uploadClientCashSubmitRequest(sSubmitAmount);
}

//获取未上传小票数量
int PosRegisterCtr::getListSaleSize()
{
    QList<SaleHead> listSaleHead;
    SaleHeadAgent::Instance()->findAllUnUploadSale( listSaleHead );
    int nSize = listSaleHead.size();
    return nSize;
}

void PosRegisterCtr::slot_timeout()
{
    m_timer.stop();
    OnlineStateAgent::instance()->checkIsOnlineRequest();
}

void PosRegisterCtr::slot_onGetShopInfo(int nCode, QString sMsg, ShopInfo shopInfo)
{
    emit sigOnGetShopInfo(nCode, sMsg, shopInfo);
}

void PosRegisterCtr::slot_onRegisterPos(int nCode, QString sMsg)
{
    emit sigOnRegisterPos(nCode, sMsg);
}

void PosRegisterCtr::slot_onCheckRegisterResult(int nCode, QString sMsg, int nRegisterResult)
{
    emit sigOnCheckRegisterResult(nCode, sMsg, nRegisterResult);
}

void PosRegisterCtr::slot_onCheckKPosUpdate(int nCode, QString sMsg, KPosUpdateInfo kPosUpdateInfo)
{
    emit sigOnCheckKPosUpdate(nCode, sMsg, kPosUpdateInfo);
}

void PosRegisterCtr::slot_onlineState(bool bOnline)
{
    Q_UNUSED( bOnline )

    static bool bFirstCheck = true;
    if (bFirstCheck)
    {
        bFirstCheck = false;
        checkRegisterResultRequest();
    }

    if (!m_timer.isActive())
    {
        m_timer.start(10*1000);
    }
}

void PosRegisterCtr::initConnect()
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(slot_timeout()));
    connect(PosInfoAgent::instance(), SIGNAL(sigOnGetShopInfo(int, QString, ShopInfo)), this, SLOT(slot_onGetShopInfo(int, QString, ShopInfo)));
    connect(PosInfoAgent::instance(), SIGNAL(sigOnRegisterPos(int, QString)), this, SLOT(slot_onRegisterPos(int, QString)));
    connect(PosInfoAgent::instance(), SIGNAL(sigOnCheckRegisterResult(int, QString, int)), this, SLOT(slot_onCheckRegisterResult(int, QString, int)));
    connect(PosInfoAgent::instance(), SIGNAL(sigOnUploadClientCashSubmit(int,QString)),
            this, SIGNAL(sigOnUploadClientCashSubmit(int,QString)));
    qRegisterMetaType<KPosUpdateInfo>("KPosUpdateInfo");
    connect(CheckKPosUpdateAgent::instance(), SIGNAL(sigOnCheckKPosUpdate(int,QString,KPosUpdateInfo)), this, SLOT(slot_onCheckKPosUpdate(int,QString,KPosUpdateInfo)));
    connect(OnlineStateAgent::instance(), SIGNAL(sigOnlineState(bool)), this, SLOT(slot_onlineState(bool)));
}

