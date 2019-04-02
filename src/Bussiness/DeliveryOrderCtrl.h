#ifndef DELIVERYORDERCTRL_H
#define DELIVERYORDERCTRL_H

#include <QObject>
#include "../data/recievinggoodsdata.h"

class DeliveryOrderCtrl : public QObject
{
    Q_OBJECT
public:
    explicit DeliveryOrderCtrl(QObject *parent = 0);
    void getDeliveryOrderListRequest(QString sStartDate, QString sEndDate); // 获取送货单列表
    void startReceiveGoodsRequest(int nDeliveryId); // 开始收货
    void endReceiveGoodsRequest(int nDeliveryId); // 停止收货
    void getDeliveryDetailRequest(int nDeliveryId); // 获取送货单明细
    void getReceiveGoodsDetailRequest(int nDeliverGoodId); // 获取收货物品明细
    void saveReceiveGoodsRequest(const ReceiveGoodsDetail_s& receiveGoodsDetail, int nDeliverGoodId); // 保存收货

private:
    void initConnect();

signals:
    void sigOnGetDeliveryOrderList(int nCode, QString sMsg, QList<DeliveryOrderInfo_s> deliveryOrderInfoList);
    void sigOnStartReceiveGoods(int nCode,QString sMsg, int nDeliveryId);
    void sigOnGetDeliveryDetail(int nCode, QString sMsg, QList<DeliveryOrderDetailInfo_s> deliveryOrderDetailInfoList, int nDeliveryId);
    void sigOnGetReceiveGoodsDetail(int nCode, QString sMsg, ReceiveGoodsDetail_s receiveGoodsDetail, int nDeliveryGoodId);
};

#endif // DELIVERYORDERCTRL_H
