#include "SatementAgent.h"
#include "HttpClient.h"
#include "PosDBFactory.h"
#include "httpstructdata.h"
#include "HttpSignal.h"
#include "SaleHeadAgent.h"
#include "SaleDetailsAgent.h"
#include "PayDetailsAgent.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

SatementAgent *SatementAgent::m_pSatementAgent = NULL;

const int gnSingleUploadReceiptNum = 20;//单次上传小票数

SatementAgent *SatementAgent::Instance()
{
    if( m_pSatementAgent == NULL ) {
        m_pSatementAgent = new SatementAgent();
    }

    return m_pSatementAgent;
}

void SatementAgent::Release()
{
    if( m_pSatementAgent ) {
        delete m_pSatementAgent;
        m_pSatementAgent = NULL;
    }
}

void SatementAgent::setStatementInfo( StatementInfo &stStatementInfo )
{
    stStatementInfo.fSimpleAmt += 0.003;

    m_stStatementInfo = stStatementInfo;
}

bool SatementAgent::getStatementInfo( StatementInfo &stStatementInfo )
{
    stStatementInfo = m_stStatementInfo;
    return true;
}

void SatementAgent::insertPayDetailData( const PaymentDetailInfo &stPaymentDetail )
{
    PayDetail_s stPayDetails;
    stPayDetails.strOrderNum = stPaymentDetail.sPaymentSequence;
    stPayDetails.strPaymentOrderNum = stPaymentDetail.strPaymentOrderNum;
    stPayDetails.fPayMoney = stPaymentDetail.fPaymentSum;
    stPayDetails.nPayIntegral = stPaymentDetail.nPayIntegral;
    stPayDetails.nPayMethod = stPaymentDetail.ePayMethod;
    stPayDetails.nStatus = stPaymentDetail.ePaymentState;
    stPayDetails.nPayType = stPaymentDetail.ePayType;
    stPayDetails.strIntExchangeAmt = stPaymentDetail.strIntExchangeAmt;
//    stPayDetails.strComment = "";
    stPayDetails.dtCreate = QDateTime::currentDateTime();
    stPayDetails.dtComplete = stPayDetails.dtCreate;
    stPayDetails.bVirtual = stPaymentDetail.bVirtual;
    stPayDetails.strAuthCode = stPaymentDetail.strAuthCode;
    //插入支付详情数据库表
    PosDBFactory::getPosDB()->m_pPayDetailsTable->insertPayDetails( stPayDetails );
}

void SatementAgent::insertPayDetailData(const PayDetail_s &payDetail_s)
{
    PosDBFactory::getPosDB()->m_pPayDetailsTable->insertPayDetails(payDetail_s);
}

void SatementAgent::createPayInfoRequest(EPayMethod ePayMethod, QString strBarCode, QString strPayAmt, QString strSale , QString sSaleDetailsJson)
{
    HttpClient::instance()->createPayInfoRequest( ePayMethod, strBarCode, strPayAmt, strSale, sSaleDetailsJson);
}

//void SatementAgent::memPayRequest( EPayMethod ePayMethod, QString strCardNo, QString strPayAmt
//                                   , QString strSale, int nInteg, QString strPayPasswd, QString strIntToAmt )
//{
//    HttpClient::instance()->createPayInfoRequest( ePayMethod, strCardNo, strPayAmt, strSale, "", nInteg, strPayPasswd, strIntToAmt);
//}

void SatementAgent::getPayStatusRequest( int nPayMethod, QString strPayOrderNum )
{
    HttpClient::instance()->createPayQueryRequest( nPayMethod, strPayOrderNum );
}

void SatementAgent::payRevokeRequest( EPayMethod ePayMethod, QString strPayOrderNum )
{
    HttpClient::instance()->payRevokeRequest( ePayMethod, strPayOrderNum );
}

void SatementAgent::createPayMemberCardRequest(QString strCardNo, QString strPayAmt, QString strSale, int nInteg, QString strPayPasswd, QString strIntToAmt)
{
    HttpClient::instance()->createPayMemberCard(strCardNo, strPayAmt, strSale, nInteg, strPayPasswd, strIntToAmt);
}

void SatementAgent::updateMemberIntegralRequest(float fMoney, QString sCardNum, QString sOrderNum, QString sRefundOrderNum)
{
    HttpClient::instance()->updateMemberIntegral(fMoney, sCardNum, sOrderNum, sRefundOrderNum);
}

void SatementAgent::updateSaleHeadStatementInfo( QString strOrderNum, QString strDisAmt, QString strProfitLoss, QString strFactorAmt, QString strOddChange )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateStatementInfo( strOrderNum, strDisAmt, strProfitLoss, strFactorAmt, strOddChange );
}

void SatementAgent::updateSaleHeadOutAmt( QString strOrderNum, QString strSimple )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateOutAmt( strOrderNum, strSimple );
}

void SatementAgent::updateSaleHeadFactorAmt( QString strOrderNum, QString strFactorAmt )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateFactorAMt( strOrderNum, strFactorAmt );
}

void SatementAgent::updateSmallChangeAmt( QString strOrderNum, QString strSmallChangeAmt )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateSmallChangeAmt( strOrderNum, strSmallChangeAmt );
}

void SatementAgent::updateSaleHeadOddChange(QString strOrderNum, QString strOddChange)
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateOddChange( strOrderNum, strOddChange);
}

void SatementAgent::updateSaleHeadMemInfo( QString strOrderNum, MemRegisterInfo_s stMemRegInfo )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateMemInfo( strOrderNum, stMemRegInfo );
}

void SatementAgent::updateComplete( const QString &strOrderNum, const ESaleHeadStatus &eSaleHeadStatus, const QDateTime &dtComplete )
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateStatus( strOrderNum, eSaleHeadStatus );
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateCompleteTime( strOrderNum, dtComplete );
}

int SatementAgent::getUploadReceiptNum()
{
    //从数据库获取数据
    QList<SaleHead> listSaleHead;
    SaleHeadAgent::Instance()->findAllUnUploadSale( listSaleHead );
    return listSaleHead.size();
}

//每次发送50
void SatementAgent::uploadAllReceipt()
{
    if (m_bUploading)
    {
        return;
    }

    m_bUploading = true;
    //1. 销售订单
    QList<SaleHead> listSaleHead;
    SaleHeadAgent::Instance()->findAllUnUploadSale( listSaleHead );

    QJsonArray jsonArray;
    QString strListSale = "";
    int nSize = listSaleHead.size();
    if(nSize == 0) {
        emit sig_uploadReceiptSuc(true);
        m_bUploading = false;
        return;
    }

    updateUploadReceiptNum( nSize );
    QList<SaleHead>::iterator it = listSaleHead.begin();

    for( int i=1 ; it != listSaleHead.end(); ++it, ++i ) {
        //2. 销售明细
        QList<SaleDetails> listSaleDetails;
        SaleDetailsAgent::Instance()->findAllSaleDetails( it->strOrderNum, listSaleDetails );
        //3. 支付明细
        QList<PayDetail_s> listPayDetails;
        PayDetailsAgent::Instance()->findData( it->strOrderNum, listPayDetails );
        //4. 使用json组QString
        QJsonObject dataJson;
//        dataJson = m_pReceiptJson->createSaleHeadObjectJson( *it );
//        dataJson.insert( "SaleDetails", m_pReceiptJson->createSaleDetailsArrayJson( listSaleDetails, (it->nSaleType == 1)) );
//        dataJson.insert( "PayDetails", m_pReceiptJson->createPayDetailsArrayJson( listPayDetails ));
        dataJson.insert("sale_head", m_pReceiptJson->createSaleHeadObjectJson( *it ));
        dataJson.insert( "sale_details", m_pReceiptJson->createSaleDetailsArrayJson( listSaleDetails, (it->nSaleType == 1)) );
        dataJson.insert( "pay_details", m_pReceiptJson->createPayDetailsArrayJson( listPayDetails ));
        jsonArray.append( dataJson );

        if((i%gnSingleUploadReceiptNum==0) || (i>=nSize))
        {
            QJsonDocument document;
            document.setArray( jsonArray );
            QByteArray byte_array = document.toJson(QJsonDocument::Compact);
            strListSale = QString(byte_array);

            //从数据库加载小票信息，然后发送给后台
            uploadReceipt( strListSale );
            QJsonArray tempJsonArray;
            jsonArray = tempJsonArray;
        }
    }
}

void SatementAgent::uploadReceipt( QString strSale )
{
    HttpClient::instance()->uploadReceipt( strSale );
}

void SatementAgent::refundRequest( EPayMethod ePayMethod, QString strPayOrderNum, bool bVirtual )
{
    if( ePayMethod == PayCash || ( ePayMethod != PayCash && bVirtual ) ) {
        emit sigRevokePay( 0, "", strPayOrderNum, 1 );
    } else {
        HttpClient::instance()->payRevokeRequest( ePayMethod, strPayOrderNum );
    }
}

void SatementAgent::updateRefundStatus( QString strPayOrderNum )
{
    PosDBFactory::getPosDB()->m_pPayDetailsTable->updateRefundStatus( strPayOrderNum );
}

//void SatementAgent::getAllUserInfo( QList<SalemanInfo> &listSalemanInfo )
//{
//    PosDBFactory::getPosDB()->m_pSalesmanInfoTable->getAllSalesmanInfo( listSalemanInfo );
//}

void SatementAgent::getPayCodeRequest(QString sCardNum)
{
    HttpClient::instance()->getPayCode(sCardNum);
}

void SatementAgent::getIntegralPayMoney(float &fMoney, QString sOrderNum)
{
    PosDBFactory::getPosDB()->m_pPayDetailsTable->countSumMoney(fMoney, e_IntegralToCansh, sOrderNum);
}

void SatementAgent::getPayIntegral(int &nIntegral, QString sOrderNum)
{
    PosDBFactory::getPosDB()->m_pPayDetailsTable->getPayIntegral(nIntegral, sOrderNum);
}

void SatementAgent::getFactorAmt(float &fMoney, QString sOrderNum)
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->getFactorAmt(fMoney, sOrderNum);
}

void SatementAgent::updateIntegral(int nGiftIntegral, QString sOrderNum)
{
    PosDBFactory::getPosDB()->m_pSaleHeadTable->updateIntegral(nGiftIntegral, sOrderNum);
}

void SatementAgent::slot_onGetCreatePayStatus(int nCode, QString strMsg, QString strOrderNumS, QString strAuthCode, EPayMethod ePayMethod )
{
    //    if ( nCode == e_success ) {
    //        PosDBFactory::getPosDB()->m_pCategoryTable->initCategory(categoryInfoList);
    //    } else {
    //        slot_localGetCategory(categoryInfoList);

    //    }
    //    initCategoryData(categoryInfoList);
        if( nCode == e_success ) {
    //        PosDBFactory::getPosDB()->m_pPayDetailsTable->find();
    //        PosDBFactory::getPosDB()->m_pPayDetailsTable->insertPayDetails( );
        }

        emit sigOnCreatePayStatus( nCode, strMsg, strOrderNumS, strAuthCode, ePayMethod );
}


void SatementAgent::slot_onGetPayStatus( int nCode, QString strMsg, QString strOrderNumS, int nTradeState )
{
    if( nCode == e_success ) {
        //PosDBFactory::getPosDB()->m_pPayDetailsTable->find();
        //PosDBFactory::getPosDB()->m_pPayDetailsTable->update( );
    }

    emit sigGetPayStatus( nCode, strMsg, strOrderNumS, nTradeState );
}

void SatementAgent::slot_noUploadReceiptSuc( int nCode, QString strMsg, QList<QString> strListOrderNum )
{
    Q_UNUSED( strMsg )

    static int nUploadNum = 0;
    ++nUploadNum;

    if( nCode == e_success ) {
        QList<QString>::iterator it = strListOrderNum.begin();
        for( ; it != strListOrderNum.end(); ++it ) {
            PosDBFactory::getPosDB()->m_pSaleHeadTable->updateUploadStatus( *it, eUploaded );
            QDateTime dt = QDateTime::currentDateTime();
            PosDBFactory::getPosDB()->m_pSaleHeadTable->updateUploadTime( *it, dt );
        }
    }

    if( m_nUploadReceiptNum == nUploadNum ) {
        QList<SaleHead> listSaleHead;
        SaleHeadAgent::Instance()->findAllUnUploadSale(listSaleHead);
        int nSize = listSaleHead.size();
        emit sig_uploadReceiptSuc(nSize == 0);

        m_bUploading = false;
        nUploadNum = 0;
    }
}

void SatementAgent::slot_onRevokePay( int nCode, QString strMsg, QString strOrderNum, int nRevoked )
{
    emit sigRevokePay( nCode, strMsg, strOrderNum, nRevoked );
}

void SatementAgent::slot_onMemCardRevokePay(int nCode, QString strMsg, QString strOrderNum, int nRevoked, QString strMemCardBalance, int nMemCardIntegral)
{
    emit sigOnMemCardRevokePay( nCode, strMsg, strOrderNum, nRevoked, strMemCardBalance, nMemCardIntegral );
}

SatementAgent::SatementAgent()
    : m_nUploadReceiptNum( 0 )
    , m_pReceiptJson( NULL )
    , m_bUploading(false)
{
    m_pReceiptJson = new ReceiptJson;
    initConnect();
}

void SatementAgent::initConnect()
{
    // 结算支付
    connect( HttpSignal::instance(), SIGNAL( sigOnCreatePayStatus(int,QString,QString,QString,EPayMethod))
             , this, SLOT( slot_onGetCreatePayStatus( int,QString,QString,QString,EPayMethod ) ) );
    connect( HttpSignal::instance(), SIGNAL(sigOnGetPayStatus(int,QString,QString,int))
             , this, SLOT( slot_onGetPayStatus(int,QString,QString,int) ) );
    connect(HttpSignal::instance(), SIGNAL(sigOnCreatePayMemberCard(int,QString,QString,QString))
            , this, SIGNAL(sigOnCreatePayMemberCard(int,QString,QString,QString)));

    connect( HttpSignal::instance(), SIGNAL(sigOnUploadReceiptSuc(int,QString,QList<QString>))
             , this, SLOT( slot_noUploadReceiptSuc( int,QString,QList<QString> ) ) );
    connect( HttpSignal::instance(), SIGNAL( sigOnRevokePay(int,QString,QString,int))
             , this, SLOT( slot_onRevokePay( int, QString, QString,int ) ) );
    connect( HttpSignal::instance(), SIGNAL( sigOnMemCardRevokePay(int,QString,QString,int,QString,int))
             , this, SLOT( slot_onMemCardRevokePay( int, QString, QString,int,QString,int ) ) );
    qRegisterMetaType<PayStoreCardInfo>("PayStoreCardInfo");
    connect(HttpSignal::instance(), SIGNAL(sigOnPayStoreCardInfo(int,QString,PayStoreCardInfo))
            , this, SIGNAL(sigOnPayStoreCardInfo(int,QString,PayStoreCardInfo)));
    connect(HttpSignal::instance(), SIGNAL(sigOnUpdateMemberIntegral(int,QString,int,QString)), this, SIGNAL(sigOnUpdateMemberIntegral(int,QString,int,QString)));
}

void SatementAgent::updateUploadReceiptNum( int nNoUploadReceiptNum )
{
    m_nUploadReceiptNum = nNoUploadReceiptNum/gnSingleUploadReceiptNum + nNoUploadReceiptNum%gnSingleUploadReceiptNum >0?1:0;
}
