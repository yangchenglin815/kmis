#ifndef GOODSMANAGECTRL_H
#define GOODSMANAGECTRL_H

#include <QObject>
#include "GoodsManageAgent.h"
#include "goodsmanagedata.h"

class GoodsManageCtrl : public QObject
{
    Q_OBJECT
public:
    explicit GoodsManageCtrl(QObject *parent = 0);
    void getGoodsManageListRequest(int nCategoryBigId, QString searchPattern);
    void getCategoryRequest();
private slots:
private:
    void initConnect();
signals:
    void sigOnGetGoodsManageList(int nCode, QString sMsg, QList<sGoodsInfo_s>, int nCategoryBigId);
    void sigOnGetCategoryList(int nCode, QString sMsg, QList<CategoryBigInfo_s>);
};

#endif // GOODSMANAGECTRL_H
