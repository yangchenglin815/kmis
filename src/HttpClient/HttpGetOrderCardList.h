#ifndef HTTPGETORDERCARDLIST_H
#define HTTPGETORDERCARDLIST_H

#include "IHttpReqRes.h"

class HttpGetOrderCardList : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpGetOrderCardList
     * @param sToken    // 授权标识
     * @param nShopID   // 门店ID
     * @param nLimit    // 单页返回数据限制，默认是20
     * @param nOffset   // 数据偏移，从第几条数据开始返回，默认是0
     * @param categoryIdList // 商品分类ID列表
     * @param nStatus   // 要货卡状态，默认是全部，0：全部，1：未上传；2：已上传；3：已删除
     * @param sStartDate    // 筛选起始日期，默认null为2天
     * @param sEndDate  // 筛选截止日期，默认null为2天
     */
    explicit HttpGetOrderCardList(QString sToken, int nShopID, QString sCorpID, QString sUUID,
                                  int nLimit, int nOffset, const QList<int> &categoryIdList,
                                  int nStatus, QString sStartDate, QString sEndDate,
                                  QString sSearchText);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    QString createCategoryIdListJson(const QList<int> &categoryIdList);
};

#endif // HTTPGETORDERCARDLIST_H
