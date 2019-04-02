#include "DeliveryOrderCtrl.h"
#include "../Agent/DeliveryOrderAgent.h"

DeliveryOrderCtrl::DeliveryOrderCtrl(QObject *parent) : QObject(parent)
{
    initConnect();
}

void DeliveryOrderCtrl::getDeliveryOrderListRequest(QString sStartDate, QString sEndDate)
{
    int nLimit = 1000;
    int nOffset = 0;
    DeliveryOrderAgent::instance()->getDeliveryOrderListRequest(nLimit, nOffset, sStartDate, sEndDate);
}

void DeliveryOrderCtrl::startReceiveGoodsRequest(int nDeliveryId)
{
    DeliveryOrderAgent::instance()->startReceiveGoodsRequest(nDeliveryId);
}

void DeliveryOrderCtrl::endReceiveGoodsRequest(int nDeliveryId)
{
    DeliveryOrderAgent::instance()->endReceiveGoodsRequest(nDeliveryId);
}

void DeliveryOrderCtrl::getDeliveryDetailRequest(int nDeliveryId)
{
    DeliveryOrderAgent::instance()->getDeliveryDetailRequest(nDeliveryId);
}

void DeliveryOrderCtrl::getReceiveGoodsDetailRequest(int nDeliverGoodId)
{
    DeliveryOrderAgent::instance()->getReceiveGoodsDetailRequest(nDeliverGoodId);
}

void DeliveryOrderCtrl::saveReceiveGoodsRequest(const ReceiveGoodsDetail_s &receiveGoodsDetail, int nDeliverGoodId)
{
    DeliveryOrderAgent::instance()->saveReceiveGoodsRequest(receiveGoodsDetail, nDeliverGoodId);
}

void DeliveryOrderCtrl::initConnect()
{
    qRegisterMetaType<QList<DeliveryOrderInfo_s> >("QList<DeliveryOrderInfo_s>");
    connect(DeliveryOrderAgent::instance(), SIGNAL(sigOnGetDeliveryOrderList(int,QString,QList<DeliveryOrderInfo_s>))
            , this, SIGNAL(sigOnGetDeliveryOrderList(int,QString,QList<DeliveryOrderInfo_s>)));
    connect(DeliveryOrderAgent::instance(), SIGNAL(sigOnStartReceiveGoods(int,QString,int)), this, SIGNAL(sigOnStartReceiveGoods(int,QString,int)));
    qRegisterMetaType<QList<DeliveryOrderDetailInfo_s> >("QList<DeliveryOrderDetailInfo_s>");
    connect(DeliveryOrderAgent::instance(), SIGNAL(sigOnGetDeliveryDetail(int,QString,QList<DeliveryOrderDetailInfo_s>,int))
            , this, SIGNAL(sigOnGetDeliveryDetail(int,QString,QList<DeliveryOrderDetailInfo_s>,int)));
    qRegisterMetaType<ReceiveGoodsDetail_s>("ReceiveGoodsDetail_s");
    connect(DeliveryOrderAgent::instance(), SIGNAL(sigOnGetReceiveGoodsDetail(int,QString,ReceiveGoodsDetail_s,int))
            , this, SIGNAL(sigOnGetReceiveGoodsDetail(int,QString,ReceiveGoodsDetail_s,int)));
}

