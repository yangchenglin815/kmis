#ifndef CHECKORDERWIDGET_H
#define CHECKORDERWIDGET_H

#include <QWidget>
#include "CheckOrderGoodsDlg.h"
#include "../data/ordergoodsdata.h"
#include "../Bussiness/OrderGoodsCheckCtrl.h"

namespace Ui {
class CheckOrderWidget;
}

class CheckOrderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CheckOrderWidget(QWidget *parent = 0);
    ~CheckOrderWidget();
    void getOrderCategory();
    void test();
    void clearData();
    QString createTestOrderId(int i);

private slots:
    void slot_searchOrderCard(int nOrderCardId); // 查看要货卡
    void slot_editOrderCard(QList<int> orderCardIdList); // 编辑要货卡
//    void slot_checkManyOrderCategoryDetailInfo(QList<int> orderCardIdList); // 批量审核
    void slot_uploadOrderCard(QList<int> orderCardIdList); // 上传要货卡
    void slot_removeOrderCard(QList<int> orderCardIdList); // 删除要货卡
    void slot_selectAllCategory(bool bSelectAll);
    void slot_addSelectCategory(int nCategoryId, bool bAdded);
    void slot_searchDate(QString sStartDate, QString sEndDate, QString sSearchText);

    void slot_onGetOrderCategory(int nCode, QString sMsg, QList<OrderCategoryBigInfo_s> categoryInfoList);
    void slot_onGetOrderCardList(int nCode, QString sMsg, QList<OrderCardInfo_s> orderCardlInfoList);
    void slot_onGetOrderCardListDetail(int nCode, QString sMsg, QList<OrderCardDetailInfo_s> orderCardDetailInfoList, bool bUploadFinish, QList<int> orderCardIdList);
    void slot_onUploadOrderCard(int nCode, QString sMsg,QList<int> orderCardIdList);
    void slot_onRemoveOrderCard(int nCode, QString sMsg);

private:
    void initConnect();

signals:
    void sigReturnClicked();
    void sigAddCheckOrder();

private:
    Ui::CheckOrderWidget *ui;
    CheckOrderGoodsDlg* m_pCheckOrderGoodsDlg;
    QList<CheckOrderCategoryInfo*> m_categoryInfoList;
    OrderGoodsCheckCtrl* m_pOrderGoodsCheckCtrl;
    bool m_bNeedRequestOrderCategory;
    bool m_bNeedRequestOrderCard;
    QList<int> m_selectedCategoryIdList;
    QString m_sStartSearchDate;
    QString m_sEndSearchDate;
    QString m_sSearchPattern;
};

#endif // CHECKORDERWIDGET_H
