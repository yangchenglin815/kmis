#ifndef ADJUSTPRICEORDERCHECKWIDGET_H
#define ADJUSTPRICEORDERCHECKWIDGET_H

#include <QWidget>
#include "../data/adjustpricedata.h"
#include "../data/structData.h"
#include "../Bussiness/AdjustPriceCtrl.h"
#include "AdjustPriceDlg.h"

namespace Ui {
class AdjustPriceOrderCheckWidget;
}

class AdjustPriceOrderCheckWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdjustPriceOrderCheckWidget(QWidget *parent = 0);
    ~AdjustPriceOrderCheckWidget();
    void setCategoryList(QList<CategoryInfo *> categoryInfoList);
    void initSelectGoodsData(const QList<AdjustPriceSelectGoodsInfo> &goodsInfoList, int nOrderId);
    void initAdjustPriceCtrl(AdjustPriceCtrl* pAdjustPriceCtrl);
    void clearGoodsSelectWidgetData();
    void setOrderId(int nOrderId);

private slots:
    void slot_clickCategoryItem(CategoryInfo categoryInfo);
    void slot_clickGoodsItem(GoodsInfo goodsInfo);
    void slot_clickGoodsSelectItem(AdjustPriceSelectGoodsInfo adjustPriceSelectGoodsInfo);
    void on_deleteButton_clicked(); // 删除
    void on_modifyPriceButton_clicked(); // 修改价格
    void on_printButton_clicked(); // 打印
    void on_saveButton_clicked(); // 保存
    void slot_modifyGoodsPrice(AdjustPriceSelectGoodsInfo goodsInfo);
    void slot_onSaveAdjustPriceOrder(int nCode, QString sMsg);
    void slot_searchChanged(QString sSearchText);

private:
    void initConnect();
    void initButtons();

signals:
    void sigSaveOrderSuccess();
    void sigPrintAdjustOrder(QList<AdjustPriceSelectGoodsInfo> selectGoodsInfoList, int nOrderId);

private:
    Ui::AdjustPriceOrderCheckWidget *ui;
    AdjustPriceDlg* m_pAdjustPriceDlg;
    AdjustPriceCtrl* m_pAdjustPriceCtrl;
    int m_nOrderId; 
};

#endif // ADJUSTPRICEORDERCHECKWIDGET_H
