#ifndef OUTSTOCKAGENT_H
#define OUTSTOCKAGENT_H

#include <QObject>
#include "../data/stockdata.h"

class OutStockAgent : public QObject
{
    Q_OBJECT
public:

    static OutStockAgent* instance();
    void getOutStockOrderListRequest(QString sStartDate, QString sEndDate, QString sSearchPatter);
    void checkOutStockOrderRequest(int nOrderId);
    void removeOutStockOrderRequest(int nOrderId); // 删除改价单
    void searchOutStockOrderRequest(int nOrderId); // 查看改价单
    void editOutStockOrderRequest(int nOrderId); // 编辑改价单
    void printOutStockOrderRequest(int nOrderId); // 打印改价单
    void saveOutStockOrderRequest(int nOrderId, const QList<OutStockSelectGoodsInfo> &selectGoodsList);
    void getStockGoodsInfoRequest(int nGoodsId);

private:
    explicit OutStockAgent(QObject *parent = 0);
    void initConnect();

signals:
    void sigOnGetOutStockOrderList(int nCode, QString sMsg, QList<OutStockOrderInfo> orderInfoList);
    void sigOnCheckOutStockOrder(int nCode, QString sMsg);
    void sigOnRemoveOutStockOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnSearchOutStockOrder(int nCode, QString sMsg,QString sTotal, QList<OutStockOrderSearchInfo> searchInfoList);
    void sigOnEditOutStockOrder(int nCode, QString sMsg, QList<OutStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnPrintOutStockOrder(int nCode, QString sMsg, QList<OutStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnSaveOutStockOrder(int nCode, QString sMsg);
//    void sigOnGetOutStockGoodsInfo(const  QString& sMsg, float fBuyPrice);

private:
    static OutStockAgent* m_pInstance;
};

#endif // OutStockAGENT_H
