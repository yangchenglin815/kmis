#ifndef INSTOCKAGENT_H
#define INSTOCKAGENT_H

#include <QObject>

#include <QObject>
#include "../data/stockdata.h"
#include "structData.h"

class InStockAgent : public QObject
{
    Q_OBJECT
public:

    static InStockAgent* instance();
    void getInStockOrderListRequest(QString sStartDate, QString sEndDate, QString sSearchPatter);
    void checkInStockOrderRequest(int nOrderId);
    void removeInStockOrderRequest(int nOrderId); // 删除改价单
    void searchInStockOrderRequest(int nOrderId); // 查看改价单
    void editInStockOrderRequest(int nOrderId); // 编辑改价单
    void printInStockOrderRequest(int nOrderId); // 打印改价单
    void saveInStockOrderRequest(int nOrderId, const QList<InStockSelectGoodsInfo> &selectGoodsList);
    void getStockGoodsInfoRequest(int nGoodsId);

private:
    explicit InStockAgent(QObject *parent = 0);
    void initConnect();

signals:
    void sigOnGetInStockOrderList(int nCode, QString sMsg, QList<InStockOrderInfo> orderInfoList);
    void sigOnCheckInStockOrder(int nCode, QString sMsg);
    void sigOnRemoveInStockOrder(int nCode, QString sMsg, int nOrderId);
    void sigOnSearchInStockOrder(int nCode, QString sMsg,QString sTotal, QList<InStockOrderSearchInfo> searchInfoList);
    void sigOnEditInStockOrder(int nCode, QString sMsg, QList<InStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnPrintInStockOrder(int nCode, QString sMsg, QList<InStockOrderSearchInfo> searchInfoList, int nOrderId);
    void sigOnSaveInStockOrder(int nCode, QString sMsg);

private:
    static InStockAgent* m_pInstance;
};

#endif // INSTOCKAGENT_H
