#include "DeliveryOrderAgent.h"
#include "../HttpClient/HttpClient.h"
#include "../util/HttpSignal.h"

DeliveryOrderAgent* DeliveryOrderAgent::m_pInstance = NULL;

DeliveryOrderAgent::DeliveryOrderAgent(QObject *parent) : QObject(parent)
{
    initConnect();
}

DeliveryOrderAgent *DeliveryOrderAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new DeliveryOrderAgent;
    }
    return m_pInstance;
}

void DeliveryOrderAgent::getDeliveryOrderListRequest(int nLimit, int nOffset, QString sStartDate, QString sEndDate)
{
    HttpClient::instance()->getDeliveryOrderList(nLimit, nOffset, sStartDate, sEndDate);
}

void DeliveryOrderAgent::startReceiveGoodsRequest(int nDeliveryId)
{
    HttpClient::instance()->startReceiveGoods(nDeliveryId);
}

void DeliveryOrderAgent::endReceiveGoodsRequest(int nDeliveryId)
{
    HttpClient::instance()->endReceiveGoods(nDeliveryId);
}

void DeliveryOrderAgent::getDeliveryDetailRequest(int nDeliveryId)
{
    HttpClient::instance()->getDeliveryDetail(nDeliveryId);
}

void DeliveryOrderAgent::getReceiveGoodsDetailRequest(int nDeliverGoodId)
{
    HttpClient::instance()->getReceiveGoodsDetail(nDeliverGoodId);
}

void DeliveryOrderAgent::saveReceiveGoodsRequest(const ReceiveGoodsDetail_s &receiveGoodsDetail, int nDeliverGoodId)
{
    HttpClient::instance()->saveReceiveGoods(receiveGoodsDetail, nDeliverGoodId);
}

void DeliveryOrderAgent::initConnect()
{
    qRegisterMetaType<QList<DeliveryOrderInfo_s> >("QList<DeliveryOrderInfo_s>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetDeliveryOrderList(int,QString,QList<DeliveryOrderInfo_s>))
            , this, SIGNAL(sigOnGetDeliveryOrderList(int,QString,QList<DeliveryOrderInfo_s>)));
    connect(HttpSignal::instance(), SIGNAL(sigOnStartReceiveGoods(int,QString,int)), this, SIGNAL(sigOnStartReceiveGoods(int,QString,int)));
    qRegisterMetaType<QList<DeliveryOrderDetailInfo_s> >("QList<DeliveryOrderDetailInfo_s>");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetDeliveryDetail(int,QString,QList<DeliveryOrderDetailInfo_s>,int))
            , this, SIGNAL(sigOnGetDeliveryDetail(int,QString,QList<DeliveryOrderDetailInfo_s>,int)));
    qRegisterMetaType<ReceiveGoodsDetail_s>("ReceiveGoodsDetail_s");
    connect(HttpSignal::instance(), SIGNAL(sigOnGetReceiveGoodsDetail(int,QString,ReceiveGoodsDetail_s,int))
            , this, SIGNAL(sigOnGetReceiveGoodsDetail(int,QString,ReceiveGoodsDetail_s,int)));
}

