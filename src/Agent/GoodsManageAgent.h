#ifndef GOODSMANAGEAGENT_H
#define GOODSMANAGEAGENT_H

#include <QObject>
#include "goodsmanagedata.h"

class GoodsManageAgent : public QObject
{
    Q_OBJECT
public:
    static GoodsManageAgent* instance();
    void getGoodsManageListRequest(QString searchPattern, int nLimit, int nOffset, const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId);
    void getCategoryListRequest();
    void getLeafCategoryIdListRequest(int nBigCategoryId, QList<int> &leafCategoryIdList); // 获取根节点分类所包含的最后一层叶子节点的分类id
private slots:
    void slot_onGetCategory(int nCode, QString sMsg, QList<CategoryBigInfo_s> categoryBigInfoList);
private:
    GoodsManageAgent();
    void initConnect();
signals:
    void sigOnGetGoodsManageList(int nCode, QString sMsg, QList<sGoodsInfo_s> orderGoodsInfoList, int nCategoryBigId);
    void sigOnGetCategoryList(int nCode, QString sMsg, QList<CategoryBigInfo_s>);
private:
    static GoodsManageAgent* m_pInstance;
     QList<CategoryBigInfo_s> m_categoryBigInfoList;
};

#endif // GOODSMANAGEAGENT_H
