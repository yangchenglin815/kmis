#ifndef ADJUSTPRICEAGENT_H
#define ADJUSTPRICEAGENT_H

#include <QObject>
#include "../data/adjustpricedata.h"

class AdjustPriceAgent : public QObject
{
    Q_OBJECT
public:
    static AdjustPriceAgent* instance();
    void getAdjustPriceOrderListRequest(QString sStartDate, QString sEndDate, QString searchPatter);
    void checkAdjustPriceOrderRequest(int nOrderId);
    void removeAdjustPriceOrderRequest(int nOrderId); // 删除改价单
    void searchAdjustPriceOrder(int nOrderId); // 查看改价单
    void editAdjustPriceOrder(int nOrderId); // 编辑改价单
    void printAdjustPriceOrder(int nOrderId); // 打印改价单
    void saveAdjustPriceOrder(int nOrderId, const QList<AdjustPriceSelectGoodsInfo> &selectGoodsList);

private:
    explicit AdjustPriceAgent(QObject *parent = 0);
    void initConnect();

signals:
    void sigOnGetAdjustPriceOrderList(int nCode, QString sMsg, QList<AdjustPriceOrderInfo> orderInfoList);
    void sigOnCheckAdjustPriceOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnRemoveAdjustPriceOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnSearchAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList);
    void sigOnEditAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnPrintAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnSaveAdjustPriceOrder(int nCode, QString sMsg);
    void sigStartUpdateThread();

private:
    static AdjustPriceAgent* m_pInstance;
};

#endif // ADJUSTPRICEAGENT_H
