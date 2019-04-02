#ifndef PAYMENTDETAILWIDGET_H
#define PAYMENTDETAILWIDGET_H

#include <QWidget>
#include <QList>
#include "../data/structData.h"

namespace Ui {
class PaymentDetailWidget;
}

/**
 * @brief The PaymentDetailWidget class 支付详情窗口
 */
class PaymentDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentDetailWidget(QWidget *parent = 0);
    ~PaymentDetailWidget();

    void updatePayDetails( PaymentDetailInfo &stPayDetails );//更新支付详情
    void insertPayDetailsList( QList<PaymentDetailInfo *> &listPayDetails );//插入支付详情
    void refundPayOrderNum( QString strPayOrderNum );//撤销支付订单
    PaymentDetailInfo *getPayOrderInfo( QString strPayOrderNum );
signals:
    void sigButtonPress( EPayMethod ePayMethod,QString strPayOrderNum, float fPayMoney, bool bVirtual );
    void sigButtonRelease( EPayMethod ePayMethod,QString strPayOrderNum );
private slots:
    //翻页
    void on_upPageButton_clicked();
    void on_downPageButton_clicked();
private:
    void generatePaymentDetail();//支付详情列表显示
    void initCtrl();
    void initConnect();
private:
    Ui::PaymentDetailWidget *ui;
    QList<PaymentDetailInfo *> m_paymentDetailInfoList;
    int m_nOnePageCount; // 一页的数据条数
    int m_nCurPage;
    int m_nTotalPage;
};

#endif // PAYMENTDETAILWIDGET_H
