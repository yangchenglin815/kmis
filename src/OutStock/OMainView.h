#ifndef OMAINVIEW_H
#define OMAINVIEW_H

#include <QWidget>
#include "../data/stockdata.h"
#include "../Bussiness/OutStockCtrl.h"
#include "KPosCalendarWidget.h"

namespace Ui {
class OMainView;
}

class OMainView : public QWidget
{
    Q_OBJECT

public:
    explicit OMainView(QWidget *parent = 0);
    ~OMainView();
    void initOutStockCtrl(OutStockCtrl* pStockCtrl);
    void getOutStockOrderListRequest();
    void initData(const QList<OutStockOrderInfo>& orderInfoList);
    void printAllOutStockOrder(const QList<OutStockSelectGoodsInfo>& goodsInfoList, int nOrderId);
//    void printAddedOutStockOrder(QList<OutStockSelectGoodsInfo> addedGoodsList, QList<OutStockSelectGoodsInfo> removedGoodsList
//                              , QList<OutStockSelectGoodsInfo> updatedGoodsList, int nOrderId);
    void hideCalendarWidget();
protected:
    bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void on_deleteButton_clicked();

    void on_checkButton_clicked();

    void on_printButton_clicked();

    void on_searchButton_clicked();//查看

    void on_editButton_clicked();

    void on_addButton_clicked();

    void on_nextPageButton_clicked();

    void on_lastPageButton_clicked();

    void slot_clickDate(int nYear, int nMonth, int nDay);
    void slot_clickAdjustItem(OutStockOrderInfo stockOrderInfo);
    void slot_onGetOutStockOrderList(int nCode, QString sMsg, QList<OutStockOrderInfo> orderInfoList);
    void slot_onCheckOutStockOrder(int nCode, QString sMsg);
    void slot_onRemoveOutStockOrder(int nCode, QString sMsg, int nOrderId);
    void slot_onPrintOutStockOrder(int nCode, QString sMsg, QList<OutStockOrderSearchInfo> orderInfoList, int nOrderId);
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
    void sigCheckOutStockSuccess();
    void sigAddOutStockOrder();
signals:
    void sig_InquireView();//查看页面
    void sig_EditView();
private:
    Ui::OMainView *ui;
    QList<OutStockOrderInfo> m_orderInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    bool m_bInStartDate;
    float m_Total;
    KPosCalendarWidget* m_pKPosCalendarWidget;
    OutStockCtrl* m_pStockCtrl;
    QString m_sStartDate;
    QString m_sEndDate;
    QString m_sSearchPattern;
};

#endif // MAINVIEW_H
