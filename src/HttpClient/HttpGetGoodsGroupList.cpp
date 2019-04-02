#include "HttpGetGoodsGroupList.h"
#include "../data/constData.h"
#include "../util/CommonFun.h"
#include "../util/KPosLog.h"
#include "../util/HttpSignal.h"
#include "barcodescaledata.h"
#include <QScriptEngine>
#include <QScriptValueIterator>

HttpGetGoodsGroupList::HttpGetGoodsGroupList(QString sCorpID, QString sToken, QString sUUID)
{
    QString userParam = QString("&hq_code=%1&access_token=%2&uuid=%3").arg(sCorpID).arg(sToken).arg(sUUID);
    QString systemParam = CommonFun::generateSystemParams(c_sHttpGetGoodsGroupListAction);
    QStringList paramList = systemParam.append(userParam).split("&");
    QString sMd5Sign = CommonFun::getHttpParamSign(paramList);
    QString allParam = systemParam.append(QString("&sign=%1").arg(sMd5Sign));
    QByteArray array;
    array.append(allParam);
    setReqParams(array);
}

void HttpGetGoodsGroupList::processResponse(QString strResult)
{
//    KPosLog::instance()->writeErrorLog(this->getTestUrl());
//    KPosLog::instance()->writeErrorLog(strResult);

    QScriptEngine engine;
    QScriptValue sc = engine.evaluate("value=" + strResult);
    int nCode = sc.property("code").toInt32();
    QString sMsg = sc.property("msg").toString();
    if (!sc.property("code").isValid())
    {
        KPosLog::instance()->writeErrorLog(QStringLiteral("HttpGetInStockOrderList 返回参数json格式错误"));
        nCode = e_connectServerError;
        sMsg = c_sServerJsonError;
    }
    if (nCode != e_success)
    {
        KPosLog::instance()->writeErrorLog(this->getTestUrl());
        KPosLog::instance()->writeErrorLog(strResult);
    }

    QList<BCSGroupManageLeftInfo> leftInfoList;
    if (sc.property("data").isArray())
    {
        BCSGroupManageLeftInfo leftInfo;
        BCSGroupManageRightInfo rightInfo;
        QScriptValueIterator it1(sc.property("data"));
        while (it1.hasNext())
        {
            it1.next();

            leftInfo.nGroupId = it1.value().property("group_id").toInt32(); // 商品组Id
//            leftInfo.sKeyId = QString::number(leftInfo.nGroupId);
            if (leftInfo.nGroupId <= 0)
            {
                continue;
            }
            leftInfo.sGroupNum= it1.value().property("group_code").toString(); // 商品组编号
            leftInfo.sGroupName = it1.value().property("group_name").toString(); // 商品组名称

            if(it1.value().property("group_content").isArray())
            {
                QScriptValueIterator it2(it1.value().property("group_content"));
                while(it2.hasNext())
                {
                    it2.next();
                    rightInfo.nGoodsId = it2.value().property("product_id").toInt32(); // 商品id
                    if (rightInfo.nGoodsId <= 0)
                    {
                        continue;
                    }
                    rightInfo.sGoodsName = it2.value().property("product_plu_name").toString(); // 商品名称
                    rightInfo.sGoodsCode = it2.value().property("code").toString(); // 商品编号
                    rightInfo.sGoodsUnit = it2.value().property("sale_unit").toString(); // 商品单位
                    rightInfo.sGoodsPlu = it2.value().property("plu_code").toString(); // 商品plu码
                    rightInfo.sGoodsPrice = it2.value().property("current_price").toString(); // 商品价格
                    rightInfo.sGoodsMemberPrice = it2.value().property("current_member_price").toString(); // 商品会员价

                    rightInfo.sKeyId = rightInfo.sGoodsPlu;
                    leftInfo.rightInfoList.append(rightInfo);
                }
            }
            leftInfoList.append(leftInfo);
        }
    }
    HttpSignal::instance()->sigOnGetGoodsGroupList(nCode, sMsg, leftInfoList);

    this->deleteLater();
}

void HttpGetGoodsGroupList::processError()
{
    QList<BCSGroupManageLeftInfo> leftInfoList;
    HttpSignal::instance()->sigOnGetGoodsGroupList(e_connectServerError, c_sNetError, leftInfoList);
    this->deleteLater();
}

