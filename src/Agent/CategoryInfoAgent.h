#ifndef CATEGORYINFOAGENT_H
#define CATEGORYINFOAGENT_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QReadWriteLock>
#include "../data/httpstructdata.h"

class CategoryInfoAgent : public QObject
{
    Q_OBJECT
public:
    static CategoryInfoAgent* instance();
    void getAllGoodsInfoRequest(bool bFinish = false);
    void getAllGoodsPriceRequest();
    void getCategoryRequest();
    void getCategoryList(QList<CategoryInfo_s> &categoryInfoList);

    void getGoodsList(QMap<int, GoodsInfo_s> &goodsInfoFirstMap, QMap<int, QList<GoodsInfo_s> >& goodsInfoSecondMap);
    void getGoodsList(QMap<int, GoodsInfo_s> &goodsInfoFirstMap);
//    void getWeighGoodsList(int nCategoryId, QMap<int, GoodsInfo_s> goodsInfoMap); // 获取称重品商品列表
    void getAllWeighGoodsList(QMap<int, QList<GoodsInfo_s> > &goodsInfoMap); // 获取所有称重品商品列表
    void getAllWeighGoodsList(QMap<QString, GoodsInfo_s>& goodsInfoMap);
    bool searchGoods(QString searchText, QList<GoodsInfo_s>& listGoodsInfo);
    void reInitFinish();

private slots:
    void slot_onGetAllGoods(int nCode, QString sMsg, QMap<QString, GoodsInfo_s> goodsInfoMap, QString sLastTime);
    void slot_onGetChangedGoods(int nCode, QString sMsg, QMap<QString,GoodsInfo_s> createGoodsMap
                                ,QMap<QString,GoodsInfo_s> updateGoodsMap, QList<QString> deleteGoodsList, QString sLastTime);
    void slot_localGetAllGoods();
    void slot_onGetAllGoodsPrice(int nCode, QString sMsg, QMap<QString, GoodsPriceInfo_s> goodsPriceInfoMap, QString sUpdateTime);
    void slot_onGetCategory(int nCode, QString sMsg, QList<CategoryInfo_s> categoryInfoList, QString sUpdateTime);
    void slot_localGetCategory();

private:
    explicit CategoryInfoAgent();
    void initConnect();
    void setGoodsInfoPrice(QMap<QString, GoodsInfo_s>& goodsInfoMap, const QMap<QString, GoodsPriceInfo_s>& goodsPriceInfoMap);

    void setGoodsInfoMap(const QMap<QString, GoodsInfo_s>& goodsInfoMap);
    void getGoodsInfoMap(QMap<QString, GoodsInfo_s>& goodsInfoMap);

signals:  
    void sigOnGetAllGoods(int nCode, QString sMsg);
    void sigGetLocalAllGoods();
    void sigOnGetChangedGoods(int nCode, QString sMsg);  
    void sigOnGetAllGoodsPrice(int nCode, QString sMsg);
    void sigOnChangeGoodsPrice();
    void sigOnGetCategory(int nCode, QString sMsg);
    void sigGetLocalCategory();
    void sigCategoryGoodsChanged();

private:
    static CategoryInfoAgent* m_pInstance;
    QList<CategoryInfo_s> m_categoryInfoList; // 所有分类信息列表， int 位置
    QMap<QString, GoodsInfo_s> m_goodsInfoMap; // int 商品ID
    QReadWriteLock m_goodsInfoMapLock;
    bool m_bInitFinish;
    bool m_bCategoryGoodsChanged; // 分类和商品信息是否有变化
};

#endif // CATEGORYINFOAGENT_H
