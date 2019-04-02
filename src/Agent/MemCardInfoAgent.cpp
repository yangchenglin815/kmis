#include "MemCardInfoAgent.h"
#include "HttpClient.h"
#include "HttpSignal.h"
#include "ReceiptPictureMaker.h"
#include "receiptdata.h"
#include "KPosIni.h"
#include "PosDBFactory.h"
#include "OnlineStateAgent.h"
#include "constData.h"

MemCardInfoAgent *MemCardInfoAgent::m_pMemCardInfoAgent = NULL;

MemCardInfoAgent *MemCardInfoAgent::instance()
{
    if( !m_pMemCardInfoAgent ) {
        m_pMemCardInfoAgent = new MemCardInfoAgent();
    }

    return m_pMemCardInfoAgent;
}

void MemCardInfoAgent::memTypeListRequest()
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->getMemTypeListRequest();
    }
    else
    {
        QList<MemTypeInfo_s> listMemType;
        slot_memTypeList(e_connectServerError, c_sNetError, listMemType);
    }
}

//获取会员等级请求
void MemCardInfoAgent::memGradeListRequest()
{
    QMap<int,MemTypeInfo_s>::iterator it = m_mapMemTypeInfo.begin();
//    for( ; it != m_mapMemTypeInfo.end(); ++it ) {
        HttpClient::instance()->getMemGradeListRequest( it.key() );
//    }
}

void MemCardInfoAgent::getOPeratorListRequest()
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->getOPeratorListRequest();
    }
    else
    {
       QList<OperatorInfo_s> operatorInfoList;
       emit sigOnOperatorList(e_connectServerError, c_sNetError, operatorInfoList);
    }
}

void MemCardInfoAgent::memQueryRequest( QString strMemCardId )
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->memQueryRequest( strMemCardId );
    }
    else
    {
        MemRegisterInfo_s memRegisterInfo;
        emit sigOnMemInfoQuery(e_connectServerError, c_sNetError, memRegisterInfo);
    }
}

void MemCardInfoAgent::memQueryForRefundRequest(QString strMemCardId)
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->memQueryForRefundRequest(strMemCardId);
    }
    else
    {
        MemRegisterInfo_s memRegisterInfo;
        emit sigOnMemInfoQueryForRefund(e_connectServerError, c_sNetError, memRegisterInfo);
    }
}

void MemCardInfoAgent::memRechargeRequest( QString strMemCardId, QString strRechargeAmt \
                                           , int nPayMethod, int nOperatorId, QString strPayCode, bool bVirtual )
{
    if (OnlineStateAgent::instance()->isOnline())
    {
       HttpClient::instance()->memRechargeRequest( strMemCardId, strRechargeAmt, nPayMethod, nOperatorId, strPayCode, bVirtual );
    }
    else
    {
        emit sigOnMemRecharge(e_connectServerError, c_sNetError, "", "", "", -1, "" );
    }
}

void MemCardInfoAgent::memRechargeStatusRequest( int nPayMethod, QString strRechargeOrderNum )
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->createPayQueryRequest(nPayMethod, strRechargeOrderNum);
    }
    else
    {
        emit sigOnGetPayStatus(e_connectServerError, c_sNetError, strRechargeOrderNum, eTradeWaiting);
    }
}

void MemCardInfoAgent::memRegisterRequest( MemRegisterInfo_s stMemRegister )
{
    if (OnlineStateAgent::instance()->isOnline())
    {
       HttpClient::instance()->memRegisterRequest( stMemRegister );
    }
    else
    {
        emit sigOnMemRegister( e_connectServerError, c_sNetError, "", 1, stMemRegister);
    }
}

void MemCardInfoAgent::memPwdModifyRequest( QString strCardId, QString strOldPwd, QString strNewPwd )
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->memModifyPwdRequest( strCardId, strOldPwd, strNewPwd );
    }
    else
    {
        emit sigOnMemPwdModify( e_connectServerError, c_sNetError, "", 1 );
    }
}

void MemCardInfoAgent::replaceMemCardRequest( QString strOldCardId , QString strNewCardId )
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->replaceMemCardRequest( strOldCardId, strNewCardId );
    }
    else
    {
        emit sigOnReplaceMemCard(e_connectServerError, c_sNetError, "", "");
    }
}

void MemCardInfoAgent::memSetStatusRequest( QString strCardId, int nStatus )
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->memSetCardStatusRequest( strCardId, nStatus );
    }
    else
    {
        emit sigOnMemStatus(e_connectServerError, c_sNetError, "", 1);
    }
}

void MemCardInfoAgent::printMemRechargeReceipt(QString strSequence, MemRegisterInfo_s stMemInfo, QString strRechargeAmt, QString strGiftAmt, QString strPayMethod )
{
    MemRechargePrintInfo stMemRechargeInfo;
    //名店信息
    stMemRechargeInfo.sHeadContent = KPosIni::getShopName();
    stMemRechargeInfo.stShopInfo.sShopCode = QString::number( KPosIni::getShopId() );
    stMemRechargeInfo.stShopInfo.sShopName = KPosIni::getShopName();
    stMemRechargeInfo.stShopInfo.sKPosCode = KPosIni::getPosCode();
    stMemRechargeInfo.stShopInfo.sSequence = strSequence;//交易流水号
    stMemRechargeInfo.stShopInfo.sDealTime = QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss" );

    //会员信息
    stMemRechargeInfo.stMemberRechargeInfo.strCardNo = stMemInfo.stMemInfo.strCardNo;
    stMemRechargeInfo.stMemberRechargeInfo.strName = stMemInfo.stMemInfo.strName;
    stMemRechargeInfo.stMemberRechargeInfo.strRechargeAmt = strRechargeAmt;
    stMemRechargeInfo.stMemberRechargeInfo.strGiftAmt = strGiftAmt;
    stMemRechargeInfo.stMemberRechargeInfo.sBalance = stMemInfo.stMemInfo.strAccountBalance;
    stMemRechargeInfo.stMemberRechargeInfo.strPayMethod = strPayMethod;

    ReceiptPictureMaker::instance()->printMemRechargeReceipt( stMemRechargeInfo );
}

void MemCardInfoAgent::insertMemRechargeTable( QString strCardNo, QString strRechargeAmt, QString strGiftAmt, int nGiftIntegral \
                                               , EPayMethod ePayMethod, int nUserId, QString strPayCode, int nStatus )
{
    MemRechargeInfo_s stMemberRechargeInfo;
    {
        stMemberRechargeInfo.strCorpID = KPosIni::getCorpID();// 企业编号
        stMemberRechargeInfo.strCardNo = strCardNo;
        stMemberRechargeInfo.strRechargeAmt = strRechargeAmt;
        stMemberRechargeInfo.ePayMethod = ePayMethod;
        stMemberRechargeInfo.strGiftAmt = strGiftAmt;
        stMemberRechargeInfo.nGiftIntegral = nGiftIntegral;
        stMemberRechargeInfo.nShopId = KPosIni::getShopId();// 门店ID
        stMemberRechargeInfo.nUserId = nUserId;//员工id
        stMemberRechargeInfo.strPayCode = strPayCode;//付款码
        stMemberRechargeInfo.nStatus = nStatus;//充值状态：0：充值失败，1：充值成功
    }

    PosDBFactory::getPosDB()->m_pMemRechargeDetailsTable->insertMemRechargeDetails( stMemberRechargeInfo );
}

void MemCardInfoAgent::deleteMemReChargeDetailsTable(int nSaveDay )
{
    PosDBFactory::getPosDB()->m_pMemRechargeDetailsTable->deleteMemRechargeDetails( nSaveDay );
}

void MemCardInfoAgent::slot_memTypeList( int nCode, QString sMsg, QList<MemTypeInfo_s> listMemType )
{
    if( nCode != 0 ) {
        //获取会员类型列表失败
        Q_UNUSED( sMsg )
        return;
    }

    QList<MemTypeInfo_s>::iterator it = listMemType.begin();
    //for( ; it != listMemType.end(); ++it ) {
        m_mapMemTypeInfo.insert( it->nId, *it );

    //}

    memGradeListRequest();
}

void MemCardInfoAgent::slot_memGradeList( int nCode, QString sMsg, QList<MemGradeInfo_s> listMemGrade )
{
    if( nCode != 0 ) {
        //获取会员等级列表失败
        return;
    }

    QList<MemGradeInfo_s>::iterator it = listMemGrade.begin();
    for( ; it != listMemGrade.end(); ++it ) {
        QMap<int,MemTypeInfo_s>::iterator itType = m_mapMemTypeInfo.find( it->nTypeId );
        if( itType == m_mapMemTypeInfo.end() ) continue;

        itType->listMemGrade.append( *it );
    }

    emit sigOnMemTypeList( nCode, sMsg, listMemGrade );
}

MemCardInfoAgent::MemCardInfoAgent()
{
    initConnect();
}

void MemCardInfoAgent::initConnect()
{
    connect( HttpSignal::instance(), SIGNAL(sigOnMemInfoQuery(int,QString,MemRegisterInfo_s))
             , this, SIGNAL(sigOnMemInfoQuery(int,QString,MemRegisterInfo_s)) );
    connect( HttpSignal::instance(), SIGNAL(sigOnMemRecharge(int,QString,QString,QString,QString,int,QString))
             , this, SIGNAL(sigOnMemRecharge(int,QString,QString,QString,QString,int,QString)) );
    connect( HttpSignal::instance(), SIGNAL(sigOnMemRegister(int,QString,QString,int,MemRegisterInfo_s))
             , this, SIGNAL(sigOnMemRegister(int,QString,QString,int,MemRegisterInfo_s)) );
    connect( HttpSignal::instance(), SIGNAL(sigOnMemPwdModify(int,QString,QString,int))
             , this, SIGNAL(sigOnMemPwdModify(int,QString,QString,int)) );
    connect( HttpSignal::instance(), SIGNAL(sigOnReplaceMemCard(int,QString,QString,QString))
             , this, SIGNAL(sigOnReplaceMemCard(int,QString,QString,QString)));
    connect( HttpSignal::instance(), SIGNAL(sigOnMemStatus(int,QString,QString,int))
             , this, SIGNAL(sigOnMemStatus(int,QString,QString,int)) );
    connect( HttpSignal::instance(), SIGNAL(sigOnMemTypeList(int,QString,QList<MemTypeInfo_s>))
             , this, SLOT( slot_memTypeList(int,QString,QList<MemTypeInfo_s>) ) );
    connect( HttpSignal::instance(), SIGNAL(sigOnMemGradeList(int,QString,QList<MemGradeInfo_s>))
             , this, SLOT( slot_memGradeList(int,QString,QList<MemGradeInfo_s> ) ) );
    connect( HttpSignal::instance(), SIGNAL(sigOnOperatorList(int,QString,QList<OperatorInfo_s>))
             , this, SIGNAL( sigOnOperatorList( int,QString,QList<OperatorInfo_s> ) ) );
    connect( HttpSignal::instance(), SIGNAL(sigOnGetPayStatus(int,QString,QString,int))
             , this, SIGNAL( sigOnGetPayStatus(int,QString,QString,int) ) );
    qRegisterMetaType<MemRegisterInfo_s>("MemRegisterInfo_s");
    connect(HttpSignal::instance(), SIGNAL(sigOnMemInfoQueryForRefund(int,QString,MemRegisterInfo_s))
            , this, SIGNAL(sigOnMemInfoQueryForRefund(int,QString,MemRegisterInfo_s)));
}
