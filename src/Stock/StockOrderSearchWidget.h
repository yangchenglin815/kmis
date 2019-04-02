#ifndef STOCKORDERSEARCHWIDGET_H
#define STOCKORDERSEARCHWIDGET_H

#include <QWidget>
#include "../data/stockdata.h"

namespace Ui {
class StockOrderSearchWidget;
}

class StockOrderSearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StockOrderSearchWidget(QWidget *parent = 0);
    ~StockOrderSearchWidget();
//    void test();
    void initData(const QList<StockOrderSearchInfo>& orderInfoList);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void slot_searchChanged(QString searchText);
    void slot_sortSixthCol(bool m_bSixthArrowDown);
    void slot_sortSeventhCol(bool m_bSeventhArrowDown);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    void initSearchData(const QList<StockOrderSearchInfo>& orderInfoList);

signals:
    void sigSortSixthCol(bool m_bSixthArrowDown);
    void sigSortSeventhCol(bool m_bSeventhArrowDown);

private:
    Ui::StockOrderSearchWidget *ui;
    QList<StockOrderSearchInfo> m_orderInfoList;
    QList<StockOrderSearchInfo> m_backUpOrderInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // STOCKORDERSEARCHWIDGET_H
