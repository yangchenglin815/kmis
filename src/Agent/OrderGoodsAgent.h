#ifndef ORDERGOODSAGENT_H
#define ORDERGOODSAGENT_H

#include <QObject>
#include "../data/ordergoodsdata.h"

class OrderGoodsAgent : public QObject
{
    Q_OBJECT
public:
    static OrderGoodsAgent* instance();
    void getOrderCategoryRequest(); // 获取要货分类
    void getOrderGoodsRequest(QString searchPattern, int nLimit, int nOffset, const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId); // 获取分类下的商品请求
    void getLeafCategoryIdListRequest(int nBigCategoryId, QList<int> &leafCategoryIdList); // 获取根节点分类所包含的最后一层叶子节点的分类id
    void createOrderCardRequest(const QList<OrderGoodsInfo *> &orderGoodsInfoList); // 生成要货卡

private slots:
    void slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> categoryBigInfoList);

private:
    OrderGoodsAgent();
    void initConnect();

signals:
    void sigOnGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> categoryBigInfoList);
    void sigOnGetOrderGoods(int nCode, QString sMsg, QList<OrderGoodsInfo_s> orderGoodsInfoList, int nCategoryBigId);
    void sigOnCreateOrderCard(int nCode, QString sMsg);

private:
    static OrderGoodsAgent* m_pInstance;
    QList<OrderCategoryBigInfo_s> m_categoryBigInfoList;
};

#endif // ORDERGOODSAGENT_H
