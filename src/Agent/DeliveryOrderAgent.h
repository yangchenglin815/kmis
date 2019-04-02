#ifndef DELIVERYORDERAGENT_H
#define DELIVERYORDERAGENT_H

#include <QObject>
#include "../data/recievinggoodsdata.h"

class DeliveryOrderAgent : public QObject
{
    Q_OBJECT
public:
    static DeliveryOrderAgent* instance();
    void getDeliveryOrderListRequest(int nLimit, int nOffset, QString sStartDate, QString sEndDate); // 获取送货单列表
    void startReceiveGoodsRequest(int nDeliveryId); // 开始收货
    void endReceiveGoodsRequest(int nDeliveryId); // 停止收货
    void getDeliveryDetailRequest(int nDeliveryId); // 获取送货单明细
    void getReceiveGoodsDetailRequest(int nDeliverGoodId); // 获取收货物品明细
    void saveReceiveGoodsRequest(const ReceiveGoodsDetail_s& receiveGoodsDetail, int nDeliverGoodId); // 保存收货

private:
    explicit DeliveryOrderAgent(QObject *parent = 0);
    void initConnect();

signals:
    void sigOnGetDeliveryOrderList(int nCode, QString sMsg, QList<DeliveryOrderInfo_s> deliveryOrderInfoList);
    void sigOnStartReceiveGoods(int nCode, QString sMsg, int nDeliveryId);
    void sigOnGetDeliveryDetail(int nCode, QString sMsg, QList<DeliveryOrderDetailInfo_s> deliveryOrderDetailInfoList, int nDeliveryId);
    void sigOnGetReceiveGoodsDetail(int nCode, QString sMsg, ReceiveGoodsDetail_s receiveGoodsDetail, int nDeliveryGoodId);

private:
    static DeliveryOrderAgent* m_pInstance;
};

#endif // DELIVERYORDERAGENT_H
