#ifndef GOODSSELECTFORCREATEWIDGET_H
#define GOODSSELECTFORCREATEWIDGET_H

#include <QWidget>
#include "../data/recievinggoodsdata.h"

namespace Ui {
class GoodsSelectForCreateWidget;
}

class GoodsSelectForCreateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsSelectForCreateWidget(QWidget *parent = 0);
    ~GoodsSelectForCreateWidget();
    void appendOneInfo(GoodsForCreateInfo* pGoodsForCreateInfo);
    void clearData();

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();
    void on_lastStepButton_clicked();
    void on_confirmButton_clicked();
    void slot_delSelectItem(int nGoodId);

private:
    void generateUI();
    void checkCurPageButtonState();
    void initConnect();
    void removeOneInfo(int nGoodsId);

signals:
    void sigLastStep();
    void sigConfirmCreateOrder();
    void sigDelSelectItem(int nGoodId);  

private:
    Ui::GoodsSelectForCreateWidget *ui;
    QList<GoodsForCreateInfo*> m_goodsForCreateInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // GOODSSELECTFORCREATEWIDGET_H
