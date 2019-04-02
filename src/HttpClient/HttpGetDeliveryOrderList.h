#ifndef HTTPGETDELIVERYORDERLIST_H
#define HTTPGETDELIVERYORDERLIST_H

#include "IHttpReqRes.h"

class HttpGetDeliveryOrderList : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpGetDeliveryOrderList
     * @param sToken      授权标识
     * @param nShopID     组织ID
     * @param nProviderId   供应商ID
     * @param sOrderCode    送货单或者采购单编号
     * @param sOrderType    单据类型
     * @param nOrderStatus  送货单状态，默认是全部，0：未完成（包括未收货和收货中），1：已完成，2：全部
     * @param sStartDate 筛选起始日期，默认null为当天
     * @param sEndDate   筛选截止日期，默认null为当天
     * @param nLimit     指定返回记录的数量，默认20
     * @param nOffset    指定返回记录的开始位置，默认0
     */

    explicit HttpGetDeliveryOrderList(QString sToken, int nShopID, int nLimit, int nOffset, int nProviderId, QString sOrderCode
                                      , QString sOrderType, int nOrderStatus, QString sStartDate, QString sEndDate);

protected:
    void processResponse(QString strResult);
    void processError();
};

#endif // HTTPGETDELIVERYORDERLIST_H
