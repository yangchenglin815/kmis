#ifndef PROMOTIONWIDGET_H
#define PROMOTIONWIDGET_H

#include <QWidget>
#include <QLabel>
#include "structData.h"

namespace Ui {
class PromotionWidget;
}

//促销窗口
class PromotionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PromotionWidget(QWidget *parent = 0);
    ~PromotionWidget();

    void setPromotion(QMap<int, SaleDetails> mapPromotion , bool bPromotion=false);
private:
    void initCtrl();
    void initConnect();

    void hideAllLabel();
private:
    Ui::PromotionWidget *ui;

    QList<QLabel*> m_listShopping;
    QList<QLabel*> m_listGoods;
    QList<QLabel*> m_listPromotionStatus;
};

#endif // PROMOTIONWIDGET_H
