#ifndef ADJUSTPRICEORDERWIDGET_H
#define ADJUSTPRICEORDERWIDGET_H

#include <QWidget>
#include "../data/adjustpricedata.h"
#include "../Bussiness/AdjustPriceCtrl.h"
#include "KPosCalendarWidget.h"

namespace Ui {
class AdjustPriceOrderWidget;
}

class AdjustPriceOrderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdjustPriceOrderWidget(QWidget *parent = 0);
    ~AdjustPriceOrderWidget();
//    void test();
    void initAdjustPriceCtrl(AdjustPriceCtrl* pAdjustPriceCtrl);
    void getAdjustPriceOrderListRequest();
    void initData(const QList<AdjustPriceOrderInfo>& orderInfoList);
    void printAdjustOrder(const QList<AdjustPriceSelectGoodsInfo>& goodsInfoList, int nOrderId);
    void hideCalendarWidget();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_deleteButton_clicked(); // 删除
    void on_checkButton_clicked(); // 审核
    void on_printButton_clicked(); // 打印
    void on_searchButton_clicked(); // 查看
    void on_editButton_clicked(); // 编辑
    void on_addButton_clicked(); // 新增
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void slot_clickDate(int nYear, int nMonth, int nDay);
    void slot_clickAdjustItem(AdjustPriceOrderInfo adjustPriceOrderInfo);
    void slot_onGetAdjustPriceOrderList(int nCode, QString sMsg, QList<AdjustPriceOrderInfo> orderInfoList);
    void slot_onCheckAdjustPriceOrder(int nCode, QString sMsg, int nOrderId);
    void slot_onRemoveAdjustPriceOrder(int nCode, QString sMsg, int nOrderId);
    void slot_onPrintAdjustPriceOrder(int nCode, QString sMsg, QList<AdjustPriceOrderSearchInfo> orderInfoList, int nOrderId);
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
    void sigAddAdjustOrder();
    void sigCheckAdjustSuccess();

private:
    Ui::AdjustPriceOrderWidget *ui;
    QList<AdjustPriceOrderInfo> m_orderInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    bool m_bInStartDate;
    KPosCalendarWidget* m_pKPosCalendarWidget;
    AdjustPriceCtrl* m_pAdjustPriceCtrl;
    QString m_sStartDate;
    QString m_sEndDate;
    QString m_sSearchPattern;
};

#endif // ADJUSTPRICEORDERWIDGET_H
