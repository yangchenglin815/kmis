#ifndef STOCKAGENT_H
#define STOCKAGENT_H

#include <QObject>
#include "../data/stockdata.h"

class StockAgent : public QObject
{
    Q_OBJECT
public:

    static StockAgent* instance();
    void getStockOrderListRequest(QString sStartDate, QString sEndDate, QString sSearchPatter);
    void checkStockOrderRequest(int nOrderId);
    void removeStockOrderRequest(int nOrderId); // 删除改价单
    void searchStockOrderRequest(int nOrderId); // 查看改价单
    void editStockOrderRequest(int nOrderId); // 编辑改价单
    void printStockOrderRequest(int nOrderId); // 打印改价单
    void saveStockOrderRequest(int nOrderId, const QList<StockSelectGoodsInfo> &selectGoodsList);
    void getStockGoodsInfoRequest(int nGoodsId);

private:
    explicit StockAgent(QObject *parent = 0);
    void initConnect();

signals:
    void sigOnGetStockOrderList(int nCode, QString sMsg, QList<StockOrderInfo> orderInfoList);
    void sigOnCheckStockOrder(int nCode, QString sMsg);
    void sigOnRemoveStockOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnSearchStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> searchInfoList);
    void sigOnEditStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnPrintStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnSaveStockOrder(int nCode, QString sMsg);
    void sigOnGetStockGoodsInfo(int nCode, QString sMsg, GoodsStockInfo goodsStockInfo);

private:
    static StockAgent* m_pInstance;
};

#endif // STOCKAGENT_H
