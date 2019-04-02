#ifndef RECEIVEGOODSFORCREATEWIDGET_H
#define RECEIVEGOODSFORCREATEWIDGET_H

#include <QWidget>
#include "../data/recievinggoodsdata.h"

namespace Ui {
class ReceiveGoodsForCreateWidget;
}

class ReceiveGoodsForCreateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveGoodsForCreateWidget(QWidget *parent = 0);
    ~ReceiveGoodsForCreateWidget();
    void initData(const QList<GoodsForCreateInfo*>& goodsForCreateInfoList);

private slots:
    void slot_searchChanged(QString searchText);
    void slot_clickSearchItem(int nGoodsId);
    void slot_delSelectItem(int nGoodsId);
    void slot_confirmCreateOrder();

private:
    void initConnect();

signals:
    void sigLastStep();
    void sigConfirmCreateOrder(QList<GoodsForCreateInfo*> m_goodsSelectedList);

private:
    Ui::ReceiveGoodsForCreateWidget *ui;
    QList<GoodsForCreateInfo*> m_goodsForSearchList; // 用于查找的
    QList<GoodsForCreateInfo*> m_goodsSelectedList; // 选择的
};

#endif // RECEIVEGOODSFORCREATEWIDGET_H
