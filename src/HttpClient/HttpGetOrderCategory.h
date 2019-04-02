#ifndef HTTPGETORDERCATEGORY_H
#define HTTPGETORDERCATEGORY_H

#include "IHttpReqRes.h"
#include <QScriptValue>

class HttpGetOrderCategory : public IHttpReqRes
{
    Q_OBJECT
public:
    /**
     * @brief HttpGetOrderCategory
     * @param sToken 授权标识
     * @param nLevel 几层分类
     */
    explicit HttpGetOrderCategory(QString sToken, QString sCorpID, int nLevel, int nType, QString sUUID);

protected:
    void processResponse(QString strResult);
    void processError();

private:
    void addSmallCategoryIdList(QScriptValue &listScriptValue, QList<int> &list); // 将二级以下分类的底层id，添加到所属的二级分类中

private:
    int m_nType;
};

#endif // HTTPGETORDERCATEGORY_H
