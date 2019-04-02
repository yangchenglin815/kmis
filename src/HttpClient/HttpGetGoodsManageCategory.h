#ifndef HTTPGETGOODSMANAGECATEGORY_H
#define HTTPGETGOODSMANAGECATEGORY_H

#include "IHttpReqRes.h"
#include <QScriptValue>

class HttpGetGoodsManageCategory : public IHttpReqRes
{
public:
    explicit HttpGetGoodsManageCategory(QString sToken, QString sCorpID, int nLevel, QString sUUID);
protected:
    void processResponse(QString strResult);
    void processError();
private:
    void addSmallCategoryIdList(QScriptValue &listScriptValue, QList<int> &list); // 将二级以下分类的底层id，添加到所属的二级分类中
};

#endif // HTTPGETGOODSMANAGECATEGORY_H
