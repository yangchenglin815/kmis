#ifndef ORDERGOODSCHECKAGENT_H
#define ORDERGOODSCHECKAGENT_H

#include <QObject>
#include "../data/ordergoodsdata.h"

class OrderGoodsCheckAgent : public QObject
{
    Q_OBJECT
public:
    static OrderGoodsCheckAgent* instance();
    void getOrderCategoryRequest(); // 获取要货分类
    void getOrderCardListRequest(int nLimit, int nOffset, const QList<int> &categoryIdList, QString sStartDate, QString sEndDate, QString sSearchText); // 获取要货卡列表
    void getOrderCardListDetailRequest(const QList<int>& orderCardIdList, bool bUploadFinish); // 获取要货卡明细
    void updateOrderCardListDetailRequest(const QMap<int, int>& changedNumMap, const QList<int>& orderCardIdList); // 更新要货卡
    void uploadOrderCardRequest(const QList<int>& orderCardIdList); // 上传要货卡
    void removeOrderCardRequest(const QList<int> orderIdList); // 删除要货卡

private slots:
    void slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> categoryBigInfoList);

private:
    explicit OrderGoodsCheckAgent();
    void initConnect();

signals:
    void sigOnGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> categoryBigInfoList);
    void sigOnGetOrderCardList(int nCode, QString sMsg, QList<OrderCardInfo_s> orderCardList);
    void sigOnGetOrderCardListDetail(int nCode, QString sMsg, QList<OrderCardDetailInfo_s> orderCardDetailInfoList, bool bUploadFinish, QList<int> orderCardIdList);
    void sigOnUpdateOrderCardListDetail(int nCode, QString sMsg);
    void sigOnUploadOrderCard(int nCode, QString sMsg,QList<int>);
    void sigOnRemoveOrderCard(int nCode, QString sMsg);

private:
    static OrderGoodsCheckAgent* m_pInstance;
};

#endif // ORDERGOODSCHECKAGENT_H
