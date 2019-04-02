#include "StatementCtr.h"
#include "SatementAgent.h"
#include "SaleHeadAgent.h"
#include "SaleDetailsAgent.h"
#include "PayDetailsAgent.h"
#include "OnlineStateAgent.h"
#include "CategoryInfoAgent.h"
#include "KPosLog.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include "KPosIni.h"

StatementCtr::StatementCtr(QObject *parent)
    : QObject(parent)
    , m_pReceiptJson( NULL )
{
    m_pReceiptJson = new ReceiptJson;
    initConnect();
}

StatementCtr::~StatementCtr()
{

}

bool StatementCtr::getStatementInfo( StatementInfo &stStatementInfo )
{
    bool bSuc = SatementAgent::Instance()->getStatementInfo( stStatementInfo );
    return bSuc;
}

void StatementCtr::insertPayDetailData( const PaymentDetailInfo &stPaymentDetail )
{
    SatementAgent::Instance()->insertPayDetailData( stPaymentDetail );
}

void StatementCtr::createPayInfoRequest( QString strOrderNum, EPayMethod ePayMethod, QString strBarCode, QString strPayAmt )
{
    // 销售订单
    SaleHead stSaleHead;
    SaleHeadAgent::Instance()->findSaleHead( strOrderNum, stSaleHead );

    // 使用json组QString
    QString strSale = m_pReceiptJson->createPaySaleHeadJson( stSaleHead );
    QString sSaleDetailsJson = "";
    if (ePayMethod == PayStoreCard)
    {
        // 销售明细
        QList<SaleDetails> listSaleDetails;
        SaleDetailsAgent::Instance()->findSaleDetails( strOrderNum, listSaleDetails );
        sSaleDetailsJson = m_pReceiptJson->createSaleDetailsArrayJsonToString(listSaleDetails);
    }
    //qDebug()<<"StatementCtr::createPayInfoRequest"<<strSale;
    //KPosLog::instance()->writeDebugLog( strSale );

    SatementAgent::Instance()->createPayInfoRequest( ePayMethod, strBarCode, strPayAmt, strSale, sSaleDetailsJson);
}

//void StatementCtr::memPayRequest( QString strOrderNum, EPayMethod ePayMethod, QString strCardNo, QString strPayAmt, int nInteg, QString strPayPasswd, QString strIntToAmt )
//{
//    //1. 销售订单
//    SaleHead stSaleHead;
//    SaleHeadAgent::Instance()->findSaleHead( strOrderNum, stSaleHead );
//    //2. 销售明细
////    QList<SaleDetails> listSaleDetails;
////    SaleDetailsAgent::Instance()->findSaleDetails( strOrderNum, listSaleDetails );


//    //3. 使用json组QString
//    QString strSale = m_pReceiptJson->createPaySaleHeadJson( stSaleHead );//m_pReceiptJson->createSaleArrayJson( stSaleHead, listSaleDetails );
//    //qDebug()<<"StatementCtr::createPayInfoRequest"<<strSale;
//    //KPosLog::instance()->writeDebugLog( strSale );

//    SatementAgent::Instance()->memPayRequest( ePayMethod, strCardNo, strPayAmt, strSale, nInteg, strPayPasswd, strIntToAmt );
//}

void StatementCtr::getPayStatusRequest( int nPayMethod, QString strPayOrderNum )
{
    SatementAgent::Instance()->getPayStatusRequest( nPayMethod, strPayOrderNum );
}

void StatementCtr::payRevokeRequest( EPayMethod ePayMethod, QString strPayOrderNum )
{
    SatementAgent::Instance()->payRevokeRequest( ePayMethod, strPayOrderNum );
}

void StatementCtr::createPayMemberCardRequest(QString strOrderNum, QString strCardNo, QString strPayAmt, int nInteg, QString strPayPasswd, QString strIntToAmt)
{
    SaleHead stSaleHead;
    SaleHeadAgent::Instance()->findSaleHead(strOrderNum, stSaleHead);
    QString strSale = m_pReceiptJson->createPaySaleHeadJson( stSaleHead );

    SatementAgent::Instance()->createPayMemberCardRequest(strCardNo, strPayAmt, strSale, nInteg, strPayPasswd, strIntToAmt );
}

void StatementCtr::updateMemberIntegralRequest(float fMoney, QString sCardNum, QString sOrderNum)
{
    SatementAgent::Instance()->updateMemberIntegralRequest(fMoney, sCardNum, sOrderNum);
}

void StatementCtr::updateSaleHeadStatementInfo( QString strOrderNum, QString strDisAmt, QString strProfitLoss, QString strFactorAmt, QString strOddChange )
{
    SatementAgent::Instance()->updateSaleHeadStatementInfo( strOrderNum, strDisAmt, strProfitLoss, strFactorAmt, strOddChange );
}

void StatementCtr::updateSaleHeadOutAmt( QString strOrderNum, QString strSimple )
{
    SatementAgent::Instance()->updateSaleHeadOutAmt( strOrderNum, strSimple );
}

void StatementCtr::updateSaleHeadFactorAmt( QString strOrderNum, QString strFactorAmt )
{
    SatementAgent::Instance()->updateSaleHeadFactorAmt( strOrderNum, strFactorAmt );
}

void StatementCtr::updateSmallChangeAmt(QString strOrderNum, QString strSmallChangeAmt)
{
    SatementAgent::Instance()->updateSmallChangeAmt( strOrderNum, strSmallChangeAmt );
}

void StatementCtr::updateSaleHeadOddChange(QString strOrderNum, QString strOddChange)
{
    SatementAgent::Instance()->updateSaleHeadOddChange( strOrderNum, strOddChange);
}

void StatementCtr::updateSaleHeadComplete( QString strOrderNum, ESaleHeadStatus eSaleHeadStatus, QDateTime dtComplete )
{
    SatementAgent::Instance()->updateComplete( strOrderNum, eSaleHeadStatus, dtComplete );
}

void StatementCtr::findSaleHead(const QString &strOrderNum, SaleHead &stSaleHead)
{
    SaleHeadAgent::Instance()->findSaleHead(strOrderNum, stSaleHead);
}

void StatementCtr::updateSaleHead(const SaleHead &stSaleHead)
{
    SaleHeadAgent::Instance()->insertSaleHeadTable(stSaleHead);
}

void StatementCtr::getOughtAmt(QString sOrderNum, float &fOughtAmt)
{
    SaleDetailsAgent::Instance()->getOughtAmt(sOrderNum, fOughtAmt);
}

void StatementCtr::getFactorAmt(float &fMoney, QString sOrderNum)
{
    SatementAgent::Instance()->getFactorAmt(fMoney, sOrderNum);
}

void StatementCtr::getIntegralPay(float &fMoney, QString sOrderNum)
{
    SatementAgent::Instance()->getIntegralPayMoney(fMoney, sOrderNum);
}

void StatementCtr::updateIntegral(int nGiftIntegral, QString sOrderNum)
{
    SatementAgent::Instance()->updateIntegral(nGiftIntegral, sOrderNum);
}

//打印小票
void StatementCtr::printReceipt( QString strOrderNum, MemRegisterInfo_s stMemRegInfo )
{
    if( strOrderNum.isEmpty() ) return;
    //1. 销售订单
    SaleHead stSaleHead;
    SaleHeadAgent::Instance()->findSaleHead( strOrderNum, stSaleHead );
    //2. 销售明细
    QList<SaleDetails> listSaleDetails;
    SaleDetailsAgent::Instance()->findSaleDetails( strOrderNum, listSaleDetails );
    int nTotalNum = listSaleDetails.size();
    stSaleHead.nSaleTotalNum = nTotalNum;
    //3. 支付明细
    QList<PayDetail_s> listPayDetails;
    PayDetailsAgent::Instance()->findData( strOrderNum, listPayDetails );

    SaleHeadAgent::Instance()->printReceipt( strOrderNum, stSaleHead, listSaleDetails, listPayDetails, stMemRegInfo);

    //从数据库加载小票信息，然后发送给后台
//    if( OnlineStateAgent::instance()->isOnline() ) {
//        //4. 使用json组QString
//        QString strSale = m_pReceiptJson->createSaleArrayJson( stSaleHead, listSaleDetails, listPayDetails );

//        SatementAgent::Instance()->uploadReceipt( strSale );
//    }
}

void StatementCtr::getPayDetailsList( QString strOrderNum, QList<PayDetail_s> &listPayDetails )
{
    PayDetailsAgent::Instance()->findData( strOrderNum, listPayDetails );
}

void StatementCtr::refundRequest( EPayMethod ePayMethod, QString strPayOrderNum, bool bVirtual )
{
    SatementAgent::Instance()->refundRequest( ePayMethod, strPayOrderNum, bVirtual );
}

void StatementCtr::getPayCodeRequest(QString sCardNum)
{
    SatementAgent::Instance()->getPayCodeRequest(sCardNum);
}

void StatementCtr::slot_GetCreatePayInfo( int nCode, QString strMsg \
                                          , QString strOrderNumS, QString strAuthCode, EPayMethod ePayMethod)
{
    emit sigOnCreatePayStatus( nCode, strMsg, strOrderNumS, strAuthCode, ePayMethod );
}

void StatementCtr::slot_GetPayStatus( int nCode, QString strMsg, QString strOrderNumS, int nTradeState)
{
    emit sig_GetPayStatus( nCode, strMsg, strOrderNumS, nTradeState );
}

void StatementCtr::slot_RevokePay( int nCode, QString strMsg, QString strOrderNum, int nRevoked )
{
    emit sig_RevokePay( nCode, strMsg, strOrderNum, nRevoked );
    if( nRevoked == 1 ) {
        SatementAgent::Instance()->updateRefundStatus( strOrderNum );
    }
}

void StatementCtr::slot_MemCardRevokePay( int nCode, QString strMsg, QString strOrderNum, int nRevoked, QString strMemCardBalance, int nMemCardIntegral )
{
    emit sig_MemCardRevokePay( nCode, strMsg, strOrderNum, nRevoked, strMemCardBalance, nMemCardIntegral );
    if( nRevoked == 1 ) {
        SatementAgent::Instance()->updateRefundStatus( strOrderNum );
    }
}

void StatementCtr::initConnect()
{
    connect(SatementAgent::Instance(), SIGNAL(sigOnCreatePayStatus(int,QString,QString,QString, EPayMethod)), this, SLOT(slot_GetCreatePayInfo( int,QString,QString,QString,EPayMethod ) ) );
    connect(SatementAgent::Instance(), SIGNAL(sigGetPayStatus(int,QString,QString,int)), this, SLOT(slot_GetPayStatus(int, QString, QString, int)));
    connect(SatementAgent::Instance(), SIGNAL(sigRevokePay(int,QString,QString,int)), this, SLOT(slot_RevokePay(int, QString, QString,int)));
    connect(SatementAgent::Instance(), SIGNAL(sigOnMemCardRevokePay(int,QString,QString,int,QString,int)), this, SLOT(slot_MemCardRevokePay(int,QString,QString,int,QString,int) ) );
    qRegisterMetaType<PayStoreCardInfo>("PayStoreCardInfo");
    connect(SatementAgent::Instance(), SIGNAL(sigOnPayStoreCardInfo(int,QString,PayStoreCardInfo))
            , this, SIGNAL(sigOnPayStoreCardInfo(int,QString,PayStoreCardInfo)));
    connect(SatementAgent::Instance(), SIGNAL(sigOnCreatePayMemberCard(int,QString,QString,QString)), this, SIGNAL(sigOnCreatePayMemberCard(int,QString,QString,QString)));
    connect(SatementAgent::Instance(), SIGNAL(sigOnUpdateMemberIntegral(int,QString,int,QString)), this, SIGNAL(sigOnUpdateMemberIntegral(int,QString,int,QString)));
}
