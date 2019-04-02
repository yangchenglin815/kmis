#ifndef OEDITVIEW_H
#define OEDITVIEW_H

#include <QWidget>
#include "constData.h"
#include "structData.h"
#include "../Bussiness/OutStockCtrl.h"
#include "../data/structData.h"
#include "AddOutStkDlg.h"

namespace Ui {
class OEditView;
}

class OEditView : public QWidget
{
    Q_OBJECT

public:
    explicit OEditView(QWidget *parent = 0);
    ~OEditView();
    void setCategoryList(QList<CategoryInfo *> categoryInfoList);
    void initSelectGoodsData(const QList<OutStockSelectGoodsInfo>& searchInfoList, int nOrderId);
    void initOutStockCtrl(OutStockCtrl* pOutStockCtrl);
    void clearGoodsSelectWidgetData();
    void setOrderId(int nOrderId);

private slots:
    void slot_clickCategoryItem(CategoryInfo categoryInfo);
    void slot_clickGoodsItem(GoodsInfo goodsInfo);
    void on_deleteButton_clicked(); // 删除
    void on_modifyButton_clicked(); // 修改
    void on_printBtn_clicked(); // 打印
    void on_saveButton_clicked(); // 保存
    void slot_onSaveOutStockOrder(int nCode, QString sMsg);
    void slot_searchChanged(QString sSearchText);
    void slot_addOutStockGoods(OutStockSelectGoodsInfo outStockSelectGoodsInfo);
private:
    void initConnect();
    void initButtons();

signals:
    void sigSaveOrderSuccess();
    void sigPrintAll(QList<OutStockSelectGoodsInfo> goodsInfoList, int nOrderId);
private:
    Ui::OEditView *ui;
    AddOutStkDlg* m_pOutStockDlg;
    OutStockCtrl* m_pOutStockCtrl;
    int m_nOrderId;

};

#endif // EDITVIEW_H
