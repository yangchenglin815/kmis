#ifndef HTTPGETORDERGOODS_H
#define HTTPGETORDERGOODS_H

#include "IHttpReqRes.h"

class HttpGetOrderGoods : public IHttpReqRes
{
    Q_OBJECT

public:
    /**
     * @brief HttpGetOrderGoods
     * @param sToken	授权标识
     * @param nShopID	门店ID
     * @param searchPattern 为空，则根据分类筛选；如果字段不为空，则进行搜索，对名字模糊搜索，对条码和PLU进行精确搜索
     * @param nLimit 单页返回数据限制，默认是20
     * @param nOffset 数据偏移，从第几条数据开始返回，默认是0
     * @param categoryIdList 商品分类ID列表
     * @param sSortBy 按照今日已定(req_num)或者订销差率(dx_rate)排序
     * @param sSort 正序(asc)或逆序(desc)排列
     */
    explicit HttpGetOrderGoods(QString sToken, int nShopID, QString sCorpID, QString searchPattern, int nLimit, int nOffset
                               , const QList<int> &categoryIdList, QString sSortBy, QString sSort, int nCategoryBigId, QString sUUID);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createCategoryIdListJson(const QList<int> &categoryIdList);

private:
    int m_nCategoryBigId;
};

#endif // HTTPGETORDERGOODS_H
