#ifndef QUICKADDGOODSAGENT_H
#define QUICKADDGOODSAGENT_H

#include <QObject>
#include "structData.h"

class QuickAddGoodsAgent : public QObject
{
    Q_OBJECT
public:
    static QuickAddGoodsAgent* instance();
    void getQuickGoodsInfoRequest(QString sBigCategoryCode); // 获取快速建档商品信息
    void createQuickGoodsRequest(const ProductInfo& info); // 创建快速建档商品

private:
    explicit QuickAddGoodsAgent(QObject *parent = 0);
    void initConnect();

signals:
    void sigOnGetQuickGoodsInfo(int nCode, QString sMsg, QString sPlu, QString sGoodsCode, QString sUnits, QString sBigCategoryCode); // 获取快速建档商品信息
    void sigOnCreateQuickGoods(int nCode, QString sMsg); // 创建快速建档商品
    void sigStartUpdateThread(); // 立即启动3分钟线程

private:
    static QuickAddGoodsAgent* m_pInstance;
};

#endif // QUICKADDGOODSAGENT_H
