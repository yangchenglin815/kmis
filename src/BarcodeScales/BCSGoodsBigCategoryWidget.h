#ifndef BCSGOODSBIGCATEGORYWIDGET_H
#define BCSGOODSBIGCATEGORYWIDGET_H

#include <QWidget>
#include "ordergoodsdata.h"

namespace Ui {
class BCSGoodsBigCategoryWidget;
}

class BCSGoodsBigCategoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCSGoodsBigCategoryWidget(QWidget *parent = 0);
    ~BCSGoodsBigCategoryWidget();
    void initData(const QList<OrderCategoryBigInfo*> &categoryBigInfoList);

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void slot_clickCategoryBig(int nCategoryId);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();

signals:
    void sigClickCategoryBig(int categoryBigId);

private:
    Ui::BCSGoodsBigCategoryWidget *ui;
    QList<OrderCategoryBigInfo*> m_infoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    int m_nSelectedBigCategoryId;
};

#endif // BCSGOODSBIGCATEGORYWIDGET_H
