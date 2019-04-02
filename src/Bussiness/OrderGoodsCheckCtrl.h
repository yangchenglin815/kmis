#ifndef ORDERGOODSCHECKCTRL_H
#define ORDERGOODSCHECKCTRL_H

#include <QObject>
#include "../data/ordergoodsdata.h"

class OrderGoodsCheckCtrl : public QObject
{
    Q_OBJECT
public:
    explicit OrderGoodsCheckCtrl(QObject *parent = 0);
    void getOrderCategoryRequest();
    void getOrderCardListRequest(const QList<int> &categoryIdList, QString sStartDate, QString sEndDate, QString sSearchText); // 获取要货卡列表
    void getOrderCardListDetailRequest(const QList<int>& orderCardIdList, bool bUploadFinish); // 获取要货卡明细
    void updateOrderCardListDetailRequest(const QMap<int, int> &changedNumMap, const QList<int> &orderCardIdList); // 更新要货卡
    void uploadOrderCardRequest(const QList<int>& orderCardIdList); // 上传要货卡
    void removeOrderCardRequest(const QList<int> orderIdList); // 删除要货卡

signals:
    void sigOnGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s>);
    void sigOnGetOrderCardList(int nCode, QString sMsg, QList<OrderCardInfo_s> orderCardList);
    void sigOnGetOrderCardListDetail(int nCode, QString sMsg, QList<OrderCardDetailInfo_s> orderCardDetailInfoList, bool, QList<int> orderCardIdList);
    void sigOnUpdateOrderCardListDetail(int nCode, QString sMsg);
    void sigOnUploadOrderCard(int nCode, QString sMsg,QList<int>);
    void sigOnRemoveOrderCard(int nCode, QString sMsg);

private:
    void initConnect();
};

#endif // ORDERGOODSCHECKCTRL_H
