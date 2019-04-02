#include "SaleDetialCtrl.h"

SaleDetialCtrl::SaleDetialCtrl(QObject *parent) : QObject(parent)
{
   initconnect();
}

void SaleDetialCtrl::getSaleDetialListRequest()
{
    SaleDetialAgent::instance()->getSaleDetialListRequest();
}

void SaleDetialCtrl::getSaleReceiptListRequest(QString selectId)
{
    SaleDetialAgent::instance()->getSaleReceiptListRequest(selectId);
}

void SaleDetialCtrl::initconnect()
{
   qRegisterMetaType<QList<ReceiptInfo>>("QList<ReceiptInfo>");
   connect(SaleDetialAgent::instance(), SIGNAL(sigOnGetSaleDetialOrder(int,QString,QList<ReceiptInfo>))
           , this, SIGNAL(sigOnGetSaleDetialOrder(int,QString,QList<ReceiptInfo>)));
   qRegisterMetaType<QList<SaleDetails>>("QList<SaleDetails>");
   qRegisterMetaType<QList<PaymentDetailInfo>>("QList<PaymentDetailInfo>");
   connect(SaleDetialAgent::instance(), SIGNAL(sigOnGetSaleReceiptOrder(int,QString,SaleHead,QList<SaleDetails>,QList<PaymentDetailInfo>))
           , this, SIGNAL(sigOnGetSaleReceiptOrder(int,QString,SaleHead,QList<SaleDetails>,QList<PaymentDetailInfo>)));
}
