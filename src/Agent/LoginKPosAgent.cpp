#include "LoginKPosAgent.h"
#include "OnlineStateAgent.h"
#include "HttpClient.h"
#include "../util/HttpSignal.h"
#include "../util/ThreadManager.h"
#include "../util/KPosIni.h"
#include "../util/CommonFun.h"
#include "../util/EnumToString.h"
#include "../data/enumData.h"
#include "../data/constData.h"
#include "../Database/PosDBFactory.h"
#include "../callOuterDll/ReceiptPictureMaker.h"

LoginKPosAgent* LoginKPosAgent::m_pInstance = NULL;

LoginKPosAgent::LoginKPosAgent()
{
    m_bInitFinish = false;
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

LoginKPosAgent *LoginKPosAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new LoginKPosAgent;
    }
    return m_pInstance;
}

void LoginKPosAgent::loginKPosRequest(QString sUserCode, QString sPassword)
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->loginKPos(sUserCode, sPassword);
    }
    else
    {
        LoginKPosInfo loginKPosInfo;
        loginKPosInfo.salemanInfo.sUserCode = sUserCode;
        loginKPosInfo.salemanInfo.sPassword = sPassword;//用户编码
//        //离线状态下拉取上上次登录本地数据

        loginKPosInfo.sLastHandPurseTime = PosDBFactory::getPosDB()->m_pClientCashSubmitTable->getLastSubmitAt( sUserCode );
//        SalemanInfo salemanInfo = PosDBFactory::getPosDB()->m_pSalesmanInfoTable->getUserdata( sUserCode );
//        loginKPosInfo.salemanInfo.nUserId = salemanInfo.nUserId;//用户ID
//        loginKPosInfo.salemanInfo.sUsername = salemanInfo.sUsername ;//用户名
//        loginKPosInfo.salemanInfo.sEmail = salemanInfo.sEmail;//用户邮箱
//        loginKPosInfo.salemanInfo.sMobile = salemanInfo.sMobile;//手机
//        loginKPosInfo.salemanInfo.sRoleCode = salemanInfo.sRoleCode;//角色编码
//        loginKPosInfo.salemanInfo.sLoginTime = QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss" ); //登入时间

        slot_localLoginKPos(e_connectServerError, c_sNetError, loginKPosInfo);
    }
}

void LoginKPosAgent::updateToken()
{
    if (m_loginKPosInfo.sToken.isEmpty())
    {
        HttpClient::instance()->updateToken(m_loginKPosInfo.salemanInfo.sUserCode, m_loginKPosInfo.salemanInfo.sPassword);
    }
}

void LoginKPosAgent::getAllUserInfoRequest()
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->getAllUserInfoRequest();
    }
    else
    {
        QList<SalemanInfo> listSalemanInfo;
        slot_onGetAllUserInfo(e_connectServerError, c_sNetError, listSalemanInfo);
    }
}

LoginKPosInfo LoginKPosAgent::getLoginKPosInfo()
{
    return m_loginKPosInfo;
}

bool LoginKPosAgent::isInitFinish()
{
    return m_bInitFinish;
}

void LoginKPosAgent::setInitFinishFlag(bool bFinish)
{
    m_bInitFinish = bFinish;
}

bool LoginKPosAgent::getAllSalemanInfo( QList<SalemanInfo> &listSalemanInfo )
{
    int nLen = m_listSalemanInfo.length();
    for (int i = 0; i < nLen; i++)
    {
        if ((m_listSalemanInfo[i].sRoleCode == "004")
                || (m_listSalemanInfo[i].sRoleCode == "002"))
        {
            if ((m_listSalemanInfo[i].nUserId == m_loginKPosInfo.salemanInfo.nUserId) && (m_listSalemanInfo[i].sRoleCode == "002"))
            {
                m_loginKPosInfo.salemanInfo.bShopHeader = true;
            }
            listSalemanInfo.append(m_listSalemanInfo[i]);
        }
    }

//    listSalemanInfo = m_listSalemanInfo;
    return true;
}

//void LoginKPosAgent::addLoginoutRecord(QString sLoginTime)
//{
//    m_loginKPosInfo.salemanInfo.sLogoutTime = CommonFun::getCurDateTime();
//    PosDBFactory::getPosDB()->m_pLoginRecordTable->addLogoutTime(sLoginTime, m_loginKPosInfo.salemanInfo.sLogoutTime);
//}

void LoginKPosAgent::logoutRequest(QString sSubmitMoney)
{
    m_loginKPosInfo.salemanInfo.sSubmitMoney = sSubmitMoney;
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->LogoutKPos(false);
    }
    else
    {
        slot_onLogoutKPos(e_connectServerError, c_sNetError);
    }
}

void LoginKPosAgent::getLogoutReceiptData()
{
    LogoutPrintData printData;
    printData.sShopName = KPosIni::getReceiptShopName(); // 门店名称
    printData.sShopCode = KPosIni::getShopCode(); // 门店号
    printData.sKPosCode = KPosIni::getPosCode(); // 款机号
    printData.sSaleman = m_loginKPosInfo.salemanInfo.sUsername; // 销售员
    printData.sLoginTime = m_loginKPosInfo.salemanInfo.sLoginTime; // 登入时间
    printData.sLogoutTime = m_loginKPosInfo.salemanInfo.sLogoutTime; // 登出时间
    printData.nSaleNum = 0; // 销售笔数
    printData.sSaleMoney = "0"; // 销售金额
    printData.nSaleRefundNum = 0; // 退款笔数
    printData.sSaleRefundMoney = "0"; // 退款金额
    printData.sSubmitSum = m_loginKPosInfo.salemanInfo.sSubmitMoney; // 交款金额
    printData.sPrintTime = CommonFun::getCurDateTime(); // 打印时间

    float fMoney = 0.0f;
    PosDBFactory::getPosDB()->m_pSaleHeadTable->countSaleMoney(printData.nSaleNum, fMoney, printData.sLoginTime, printData.sLogoutTime);
    printData.sSaleMoney = QString::number(fMoney, 'f', 2);
    fMoney = 0.0f;
    PosDBFactory::getPosDB()->m_pSaleHeadTable->countSaleRefundMoney(printData.nSaleRefundNum, fMoney, printData.sLoginTime, printData.sLogoutTime);
    printData.sSaleRefundMoney = QString::number(fMoney, 'f', 2);

    QList<QString> orderNumList;
    PosDBFactory::getPosDB()->m_pSaleHeadTable->getOrderNumList(orderNumList, printData.sLoginTime, printData.sLogoutTime);
    countPaymethodMoney(printData.payMethodMap ,orderNumList);

    ReceiptPictureMaker::instance()->printLogoutReceipt(printData);
}

void LoginKPosAgent::slot_onLoginKPos(int nCode, QString sMsg, LoginKPosInfo loginKPosInfo)
{
    if (nCode >= 0)
    {
        m_loginKPosInfo.sToken = loginKPosInfo.sToken;
        HttpClient::instance()->setToken(m_loginKPosInfo.sToken);
        if (nCode == e_success && !m_bInitFinish)
        {
            m_loginKPosInfo = loginKPosInfo;
            KPosIni::setCorpName(m_loginKPosInfo.sCorpName);
            KPosIni::setShopId(m_loginKPosInfo.nShopID);
            KPosIni::setShopName(m_loginKPosInfo.sShopName);
            KPosIni::setShopCode(m_loginKPosInfo.sShopCode);
            KPosIni::setPosCode(m_loginKPosInfo.sPosCode);
            KPosIni::setPurseRemain(m_loginKPosInfo.fPurseRemain);
            KPosIni::setLastHandPurseTime(m_loginKPosInfo.sLastHandPurseTime);
            KPosIni::setUserName(m_loginKPosInfo.salemanInfo.sUsername);
            m_loginKPosInfo.salemanInfo.sLoginTime = CommonFun::getCurDateTime();
            KPosIni::setLoginId(m_loginKPosInfo.nLoginId);
            KPosIni::setLoginTime(m_loginKPosInfo.salemanInfo.sLoginTime);
            PosDBFactory::getPosDB()->m_pSalesmanInfoTable->addSalesmanInfo(m_loginKPosInfo.salemanInfo);
            PosDBFactory::getPosDB()->m_pLoginRecordTable->setCurUserId(m_loginKPosInfo.salemanInfo.nUserId);
            PosDBFactory::getPosDB()->m_pLoginRecordTable->addLoginTime(m_loginKPosInfo.salemanInfo.sLoginTime);
        }
        emit sigOnLoginKPos(nCode, sMsg, false);
    }
    else
    {
        slot_localLoginKPos(nCode, sMsg, loginKPosInfo);
    }
}

void LoginKPosAgent::slot_localLoginKPos(int nCode, QString sMsg, LoginKPosInfo loginKPosInfo)
{
    bool bAllowLogin = PosDBFactory::getPosDB()->m_pSalesmanInfoTable->isAllowLogin(loginKPosInfo.salemanInfo);
    if (!bAllowLogin)
    {
        sMsg = QStringLiteral("离线状态，新用户不可登录！");
    }

    if (!m_bInitFinish)
    {
        m_loginKPosInfo = loginKPosInfo;
        m_loginKPosInfo.salemanInfo.sLoginTime = CommonFun::getCurDateTime();
        KPosIni::setLoginTime(m_loginKPosInfo.salemanInfo.sLoginTime);
        KPosIni::setLastHandPurseTime(m_loginKPosInfo.sLastHandPurseTime);
        KPosIni::setUserName(m_loginKPosInfo.salemanInfo.sUsername);
        KPosIni::setUserCode(m_loginKPosInfo.salemanInfo.sUserCode);
        PosDBFactory::getPosDB()->m_pLoginRecordTable->setCurUserId(m_loginKPosInfo.salemanInfo.nUserId);
        PosDBFactory::getPosDB()->m_pLoginRecordTable->addLoginTime(m_loginKPosInfo.salemanInfo.sLoginTime);
    }

    emit sigOnLoginKPos(nCode, sMsg, bAllowLogin);
}

void LoginKPosAgent::slot_onGetAllUserInfo( int nCode, QString sMsg, QList<SalemanInfo> listSalemanInfo )
{
    Q_UNUSED( sMsg )
    if( nCode != e_success ) {
        PosDBFactory::getPosDB()->m_pSalesmanInfoTable->getAllSalesmanInfo( listSalemanInfo );
        m_listSalemanInfo = listSalemanInfo;
        return;
    }

    QList<SalemanInfo> listSaleInfo;
    PosDBFactory::getPosDB()->m_pSalesmanInfoTable->getAllSalesmanInfo( listSaleInfo );
    int nLen = listSaleInfo.size();
    int nLenS = listSalemanInfo.size();
    for( int i=0; i<nLen; ++i ) {
        int nUserId = listSaleInfo[i].nUserId;
        bool bHas = false;
        for( int j=0; j<nLenS; ++j ) {
            if( nUserId == listSalemanInfo[j].nUserId ) {
                bHas = true;
                break;
            }
        }

        if( !bHas ) {
            deleteUserInfo( listSaleInfo[i] );//删除
        }
    }

    for( int j=0; j<nLenS; ++j ) {
        int nUserId = listSalemanInfo[j].nUserId;
        bool bHas = false;
        for( int i=0; i<nLen; ++i ) {
            if( nUserId == listSaleInfo[i].nUserId ) {
                updateUserInfo( listSalemanInfo[j] );//更新
                bHas = true;
                break;
            }
        }
        if( !bHas ) {
            insertUserInfo( listSalemanInfo[j] );//插入
        }
    }

    m_listSalemanInfo = listSalemanInfo;
}

void LoginKPosAgent::slot_onLogoutKPos(int nCode, QString sMsg)
{
    m_loginKPosInfo.salemanInfo.sLogoutTime = CommonFun::getCurDateTime();
    PosDBFactory::getPosDB()->m_pLoginRecordTable->addLogoutTime(m_loginKPosInfo.salemanInfo.sLoginTime, m_loginKPosInfo.salemanInfo.sLogoutTime);
    emit sigOnLogoutKPos(nCode, sMsg);
}

void LoginKPosAgent::slot_OnUpdateToken(QString sToken)
{
    m_loginKPosInfo.sToken = sToken;
    HttpClient::instance()->setToken(sToken);
}

void LoginKPosAgent::initConnect()
{
    qRegisterMetaType<LoginKPosInfo>("LoginKPosInfo");
    qRegisterMetaType<QList<SalemanInfo> >("QList<SalemanInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnLoginKPos(int, QString, LoginKPosInfo)), this, SLOT(slot_onLoginKPos(int, QString, LoginKPosInfo)));
    connect(HttpSignal::instance(), SIGNAL(sigOnGetAllUserInfo(int,QString,QList<SalemanInfo>)), this, SLOT(slot_onGetAllUserInfo(int,QString,QList<SalemanInfo>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnLogoutKPos(int,QString)), this, SLOT(slot_onLogoutKPos(int,QString)));
    connect(HttpSignal::instance(), SIGNAL(sigOnUpdateToken(QString)), this, SLOT(slot_OnUpdateToken(QString)));
}

void LoginKPosAgent::insertUserInfo( SalemanInfo stSalemanInfo )
{
    PosDBFactory::getPosDB()->m_pSalesmanInfoTable->addSalesmanInfo( stSalemanInfo );
}

void LoginKPosAgent::updateUserInfo( SalemanInfo stSalemanInfo )
{
    PosDBFactory::getPosDB()->m_pSalesmanInfoTable->updateSalesmanInfo( stSalemanInfo );
}

void LoginKPosAgent::deleteUserInfo( SalemanInfo stSalemanInfo )
{
    PosDBFactory::getPosDB()->m_pSalesmanInfoTable->deleteSalesmanInfo( stSalemanInfo );
}

void LoginKPosAgent::countPaymethodMoney(QMap<QString, QString> &payMethodMap, const QList<QString> &orderNumList)
{
    QList<int> payMethodList;
    payMethodList<<PayCash<<UnionPay<<PayMemCard<<PayStoreCard<<PayAlipay<<PayWeChat<<ApplePay<<JdWallet<<Coupon
                <<IntegralToCansh<<PayEntityCard<<PayCityCard<<PayFengCha<<PayCheck<<PayBills<<PayOther;
    int nLen = payMethodList.length();
    float fMoney = 0.0f;
    for (int i = 0; i < nLen; i++)
    {
        PosDBFactory::getPosDB()->m_pPayDetailsTable->countSumMoney(fMoney, payMethodList[i], orderNumList);
        if ((fMoney > 0.000001) || (payMethodList[i] == PayCash))
        {
            payMethodMap.insert(EnumToString::payMethodToString(payMethodList[i]), QString::number(fMoney, 'f', 2));
        }
    }
}
