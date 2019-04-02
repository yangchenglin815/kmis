#ifndef ORDERCATEGORYSMALLWIDGET_H
#define ORDERCATEGORYSMALLWIDGET_H

#include <QWidget>
#include "../data/ordergoodsdata.h"
#include "../data/constData.h"

namespace Ui {
class OrderCategorySmallWidget;
}

class OrderCategorySmallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderCategorySmallWidget(QWidget *parent = 0);
    ~OrderCategorySmallWidget();
    void initData(const QList<OrderCategorySmallInfo*>& orderCategorySmallInfoList, int nDefaultSelectedId = c_nNegativeNumber);

private slots:
    void on_nextPageButton_clicked();
    void slot_clickCategorySmall(int categorySmallId);

private:
    void generateUI();
    void initConnect();
    int countRootSelectNumber();

signals:
    void sigClickCategorySmall(int categorySmallId);

private:
    Ui::OrderCategorySmallWidget *ui;
    QList<OrderCategorySmallInfo*> m_orderCategorySmallInfoList;
    OrderCategorySmallInfo m_rootOrderCategorySmallInfo;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    QList<int> m_selectedCategorySmallIdList;
    int m_nCurCategorySmallId;
};

#endif // ORDERCATEGORYSMALLWIDGET_H
