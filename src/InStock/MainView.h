#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include "../data/stockdata.h"
#include "../Bussiness/InStockCtrl.h"
#include "KPosCalendarWidget.h"

namespace Ui {
class MainView;
}

class MainView : public QWidget
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();
    void initInStockCtrl(InStockCtrl* pStockCtrl);
    void getInStockOrderListRequest();
    void initData(const QList<InStockOrderInfo>& orderInfoList);
    void printAllInStockOrder(const QList<InStockSelectGoodsInfo>& goodsInfoList, int nOrderId);
//    void printAddedInStockOrder(QList<InStockSelectGoodsInfo> addedGoodsList, QList<InStockSelectGoodsInfo> removedGoodsList
//                              , QList<InStockSelectGoodsInfo> updatedGoodsList, int nOrderId);
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
    void slot_clickAdjustItem(InStockOrderInfo stockOrderInfo);
    void slot_onGetInStockOrderList(int nCode, QString sMsg, QList<InStockOrderInfo> orderInfoList);
    void slot_onCheckInStockOrder(int nCode, QString sMsg);
    void slot_onRemoveInStockOrder(int nCode, QString sMsg, int nOrderId);
    void slot_onPrintInStockOrder(int nCode, QString sMsg, QList<InStockOrderSearchInfo> orderInfoList, int nOrderId);
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
    void sigCheckInStockSuccess();
    void sigAddInStockOrder();
signals:
    void sig_InquireView();//查看页面
    void sig_EditView();
private:
    Ui::MainView *ui;
    QList<InStockOrderInfo> m_orderInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    bool m_bInStartDate;
    float m_Total;
    KPosCalendarWidget* m_pKPosCalendarWidget;
    InStockCtrl* m_pStockCtrl;
    QString m_sStartDate;
    QString m_sEndDate;
    QString m_sSearchPattern;
};

#endif // MAINVIEW_H
