#ifndef STOCKORDERWIDGET_H
#define STOCKORDERWIDGET_H

#include <QWidget>
#include "../data/stockdata.h"
#include "../Bussiness/StockCtrl.h"
#include "KPosCalendarWidget.h"
#include "DlgCommon.h"
#include <QPointer>

namespace Ui {
class StockOrderWidget;
}

class StockOrderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StockOrderWidget(QWidget *parent = 0);
    ~StockOrderWidget();
//    void test();
    void initStockCtrl(StockCtrl* pStockCtrl);
    void getStockOrderListRequest();
    void initData(const QList<StockOrderInfo>& orderInfoList);
    void printAllStockOrder(const QList<StockSelectGoodsInfo>& goodsInfoList, int nOrderId);
    void printAddedStockOrder(QList<StockSelectGoodsInfo> addedGoodsList, QList<StockSelectGoodsInfo> removedGoodsList
                              , QList<StockSelectGoodsInfo> updatedGoodsList, int nOrderId);
    void hideCalendarWidget();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_deleteButton_clicked(); // 删除
    void on_checkButton_clicked(); // 审核
    void on_printButton_clicked(); // 打印
    void on_searchButton_clicked(); // 查找
    void on_editButton_clicked(); // 编辑
    void on_addButton_clicked(); // 添加
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();

    void slot_clickDate(int nYear, int nMonth, int nDay);
    void slot_clickAdjustItem(StockOrderInfo stockOrderInfo);
    void slot_onGetStockOrderList(int nCode, QString sMsg, QList<StockOrderInfo> orderInfoList);
    void slot_onCheckStockOrder(int nCode, QString sMsg);
    void slot_onRemoveStockOrder(int nCode, QString sMsg, int nOrderId);
    void slot_onPrintStockOrder(int nCode, QString sMsg, QList<StockOrderSearchInfo> orderInfoList, int nOrderId);
    void slot_searchChanged(QString searchText);

private:
    void updateData();
    void generateUI();
    void checkCurPageButtonState();
    void inputStartDate();
    void inputEndDate();
    void initConnect();
    void setButtonsState(int nState);
    void initButtons();

signals:
    void sigCheckStockSuccess();
    void sigAddStockOrder();

private:
    Ui::StockOrderWidget *ui;
    QList<StockOrderInfo> m_orderInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    bool m_bInStartDate;
    KPosCalendarWidget* m_pKPosCalendarWidget;
    QPointer<DlgCommon> tipsDlg;
    StockCtrl* m_pStockCtrl;
    QString m_sStartDate;
    QString m_sEndDate;
    QString m_sSearchPattern;
};

#endif // STOCKORDERWIDGET_H
