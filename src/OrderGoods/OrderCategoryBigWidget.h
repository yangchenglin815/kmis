#ifndef ORDERCATEGORYBIGWIDGET_H
#define ORDERCATEGORYBIGWIDGET_H

#include <QWidget>
#include "../data/ordergoodsdata.h"

namespace Ui {
class OrderCategoryBigWidget;
}

class OrderCategoryBigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderCategoryBigWidget(QWidget *parent = 0);
    ~OrderCategoryBigWidget();
    void initData(const QList<OrderCategoryBigInfo*> &orderCategoryBigInfoList);
    void clickCategoryBigId(int nCategoryId);

private slots:
    void on_nextPageButton_clicked();
    void slot_clickCategoryBig(int nCategoryId);

private:
    void generateUI();
    void initConnect();

signals:
    void sigClickCategoryBig(int categoryBigId);

private:
    Ui::OrderCategoryBigWidget *ui;
    QList<OrderCategoryBigInfo*> m_orderCategoryBigInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    int m_nSelectedBigCategoryId;
};

#endif // ORDERCATEGORYBIGWIDGET_H
