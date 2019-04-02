#include "SaleDetailsAgent.h"
#include "PosDBFactory.h"
#include "HttpClient.h"
#include "../util/HttpSignal.h"
#include "../data/constData.h"
#include "../Agent/OnlineStateAgent.h"

SaleDetailsAgent *SaleDetailsAgent::m_pInstance = NULL;

SaleDetailsAgent::SaleDetailsAgent(QObject *parent) : QObject(parent)
{
    initConnect();
}

SaleDetailsAgent::~SaleDetailsAgent()
{

}

SaleDetailsAgent *SaleDetailsAgent::Instance()
{
    if( m_pInstance == NULL ) {
        m_pInstance = new SaleDetailsAgent;
    }

    return m_pInstance;
}

void SaleDetailsAgent::Release()
{
    if( m_pInstance ) {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

void SaleDetailsAgent::insertSaleDetailsTable( const SaleDetails &stSaleDetails )
{
    PosDBFactory::getPosDB()->m_pSaleDetailsTable->insertSaleDetails( stSaleDetails );
}

void SaleDetailsAgent::updateSaleDetailsTable( const SaleDetails &stSaleDetails )
{
    PosDBFactory::getPosDB()->m_pSaleDetailsTable->updateSaleDetails( stSaleDetails );
}

void SaleDetailsAgent::updateSaleDetailsNum( const QString &strOrderNum, float fNumber, QString strSumPrice, int nGoodsId )
{
    PosDBFactory::getPosDB()->m_pSaleDetailsTable->updateSaleDetails( strOrderNum, fNumber, strSumPrice, nGoodsId );
}

bool SaleDetailsAgent::deleteSaleDetailsTable( const QString &strOrderNum )
{
    PosDBFactory::getPosDB()->m_pSaleDetailsTable->deleteSaleDetails( strOrderNum );
    return true;
}

bool SaleDetailsAgent::deleteSaleDetailsTable( const int nSaleDetailsPos )
{
    PosDBFactory::getPosDB()->m_pSaleDetailsTable->deleteSaleDetails( nSaleDetailsPos );
    return true;
}

void SaleDetailsAgent::cancelSaleDetailsState(const QString &strOrderNum)
{
    PosDBFactory::getPosDB()->m_pSaleDetailsTable->cancelSaleDetails(strOrderNum);
}

void SaleDetailsAgent::cancelSaleDetailsState(const int nSaleDetailsPos)
{
    PosDBFactory::getPosDB()->m_pSaleDetailsTable->cancelSaleDetails(nSaleDetailsPos);
}

bool SaleDetailsAgent::findSaleDetails( const QString &strOrderNum, QList<SaleDetails> &listSaleDetails )
{
    bool bHas = PosDBFactory::getPosDB()->m_pSaleDetailsTable->findSaleDetails( strOrderNum, listSaleDetails );
    return bHas;
}

void SaleDetailsAgent::findAllSaleDetails(const QString &strOrderNum, QList<SaleDetails> &listSaleDetails)
{
    PosDBFactory::getPosDB()->m_pSaleDetailsTable->findAllSaleDetails(strOrderNum, listSaleDetails);
}

void SaleDetailsAgent::findRefundSaleDetails(const QString &sOrderNum, QList<SaleDetails> &saleDetailsList, const QList<QString> &refundOrderNumList)
{
    PosDBFactory::getPosDB()->m_pSaleDetailsTable->findSaleDetails(sOrderNum, saleDetailsList);
    int nLen = saleDetailsList.length();
    for (int i = 0; i < nLen; i++)
    {
        saleDetailsList[i].goodsInfo.fHaveRefundNum = PosDBFactory::getPosDB()->m_pSaleDetailsTable->getRefundNum(saleDetailsList[i].strBarCode ,refundOrderNumList);
    }
}

int SaleDetailsAgent::getLastSaleDetailsPos()
{
    int nLastSaleDetailsPos = PosDBFactory::getPosDB()->m_pSaleDetailsTable->getLastSaleDetailsPos();
    return nLastSaleDetailsPos;
}

void SaleDetailsAgent::getOughtAmt(QString sOrderNum, float &fOughtAmt)
{
    PosDBFactory::getPosDB()->m_pSaleDetailsTable->getOughtAmt(sOrderNum, fOughtAmt);
}

void SaleDetailsAgent::getRefundGoodsReasonListRequest()
{
    HttpClient::instance()->getRefundGoodsReasonList(OnlineStateAgent::instance()->isOnline());
}

void SaleDetailsAgent::searchReceiptRequst(QString sOrderNum)
{
    HttpClient::instance()->searchReceipt(sOrderNum);
}

void SaleDetailsAgent::slot_onGetRefundGoodsReasonList(int nCode, QString sMsg, QList<RefundGoodsReason> reasonList)
{
    emit sigOnGetRefundGoodsReasonList(nCode, sMsg, reasonList);
}

void SaleDetailsAgent::initConnect()
{
    qRegisterMetaType<QList<RefundGoodsReason> >("QList<RefundGoodsReason>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetRefundGoodsReasonList(int,QString,QList<RefundGoodsReason>))
            , this, SIGNAL(sigOnGetRefundGoodsReasonList(int,QString,QList<RefundGoodsReason>)));
    qRegisterMetaType<SaleHead>("SaleHead");
    qRegisterMetaType<QList<SaleDetails> >("QList<SaleDetails>");
    connect(HttpSignal::instance(), SIGNAL(sigOnSearchReceipt(int,QString,SaleHead,QList<SaleDetails>, float, int))
            , this, SIGNAL(sigOnSearchReceipt(int,QString,SaleHead,QList<SaleDetails>, float, int)));
}
