#ifndef GOODSMANAGEWIDGET_H
#define GOODSMANAGEWIDGET_H

#include <QWidget>
#include "goodsmanagedata.h"
#include "../Bussiness/GoodsManageCtrl.h"

namespace Ui {
class GoodsManageWidget;
}

class GoodsManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsManageWidget(QWidget *parent = 0);
    ~GoodsManageWidget();
    void initGoodsManageCtrl();
    void clearData();
private slots:
    void slot_searchChanged(QString searchText);
    void slot_clickCategorySmall(int nCategorySmallId);
    void slot_getCategoryList(int nCode, QString sMsg, QList<CategoryBigInfo_s> categoryBigInfoList);
    void slot_clickCategoryBig(int nCategoryBigId);
    void slot_onGetOrderGoods(int nCode, QString sMsg, QList<sGoodsInfo_s> orderGoodsInfoList, int nCategoryBigId);
signals:
    void sigReturnClicked();
    void sigFastCreateDocument();
private:
    Ui::GoodsManageWidget *ui;
    QList<sCategoryBigInfo*> m_CategoryBigInfoList;
    GoodsManageCtrl* m_goodsManageCtrl;
    int m_nClickedCategoryBigId;
    QMap<int, int> m_categoryBigSmallIdMap;
    QList<int> m_nRequestCategoryIdList;
private:
    sCategoryBigInfo *getCategoryBigInfo(int nCategoryBigId);
    void initconnect();
};

#endif // GOODSMANAGEWIDGET_H
