#ifndef ADJUSTPRICEORDERSEARCHWIDGET_H
#define ADJUSTPRICEORDERSEARCHWIDGET_H

#include <QWidget>
#include "../data/adjustpricedata.h"

namespace Ui {
class AdjustPriceOrderSearchWidget;
}

class AdjustPriceOrderSearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdjustPriceOrderSearchWidget(QWidget *parent = 0);
    ~AdjustPriceOrderSearchWidget();
//    void test();
    void initData(const QList<AdjustPriceOrderSearchInfo>& orderInfoList);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void slot_searchChanged(QString searchText);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    void initSearchData(const QList<AdjustPriceOrderSearchInfo>& orderInfoList);

private:
    Ui::AdjustPriceOrderSearchWidget *ui;
    QList<AdjustPriceOrderSearchInfo> m_orderInfoList;
    QList<AdjustPriceOrderSearchInfo> m_backUpOrderInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // ADJUSTPRICEORDERSEARCHWIDGET_H
