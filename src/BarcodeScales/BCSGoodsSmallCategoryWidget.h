#ifndef BCSGOODSSMALLCATEGORYWIDGET_H
#define BCSGOODSSMALLCATEGORYWIDGET_H

#include <QWidget>
#include "ordergoodsdata.h"
#include "constData.h"

namespace Ui {
class BCSGoodsSmallCategoryWidget;
}

class BCSGoodsSmallCategoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCSGoodsSmallCategoryWidget(QWidget *parent = 0);
    ~BCSGoodsSmallCategoryWidget();
    void initData(const QList<OrderCategorySmallInfo*>& orderCategorySmallInfoList, int nDefaultSelectedId);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void slot_clickCategorySmall(int categorySmallId);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    int countRootSelectNumber();

signals:
    void sigClickCategorySmall(int categorySmallId);

private:
    Ui::BCSGoodsSmallCategoryWidget *ui;
    QList<OrderCategorySmallInfo*> m_orderCategorySmallInfoList;
    OrderCategorySmallInfo m_rootOrderCategorySmallInfo;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    QList<int> m_infoIdList;
    int m_nCurCategorySmallId;
};

#endif // BCSGOODSSMALLCATEGORYWIDGET_H
