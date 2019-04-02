#include "SaleDetialAgent.h"

#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"
#include "../util/ThreadManager.h"

SaleDetialAgent* SaleDetialAgent::m_pInstance = NULL;

SaleDetialAgent *SaleDetialAgent::instance()
{
   if(m_pInstance == NULL){
       m_pInstance = new SaleDetialAgent;
   }
   return m_pInstance;
}

void SaleDetialAgent::getSaleDetialListRequest()
{
    HttpClient::instance()->getSaleDetialListRequest();
}

void SaleDetialAgent::getSaleReceiptListRequest(QString selectId)
{
    HttpClient::instance()->getSaleReceiptListRequest(selectId);
}

SaleDetialAgent::SaleDetialAgent(QObject *parent) : QObject(parent)
{
    initconnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

void SaleDetialAgent::initconnect()
{
    qRegisterMetaType<QList<ReceiptInfo>>("QList<ReceiptInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetSaleDetialOrderList(int,QString,QList<ReceiptInfo>))
            , this, SIGNAL(sigOnGetSaleDetialOrder(int,QString,QList<ReceiptInfo>)));
    qRegisterMetaType<QList<SaleDetails>>("QList<SaleDetails>");
    qRegisterMetaType<QList<PaymentDetailInfo>>("QList<PaymentDetailInfo>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetSaleReceiptOrderList(int,QString,SaleHead,QList<SaleDetails>,QList<PaymentDetailInfo>))
            , this, SIGNAL(sigOnGetSaleReceiptOrder(int,QString,SaleHead,QList<SaleDetails>,QList<PaymentDetailInfo>)));
}

