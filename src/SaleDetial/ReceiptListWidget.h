#ifndef RECEIPTLISTWIDGET_H
#define RECEIPTLISTWIDGET_H

#include <QWidget>
#include "../data/receiptdata.h"
#include "KPosCalendarWidget.h"
#include "SaleDetialCtrl.h"

namespace Ui {
class ReceiptListWidget;
}

class ReceiptListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiptListWidget(QWidget *parent = 0);
    ~ReceiptListWidget();
    void initData(const QList<ReceiptInfo>& itemInfoList);
    void hideCalendarWidget();
    void initContent();
    void initSaleDetialCtrl(SaleDetialCtrl* ctrl);

protected:
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void slot_ClickItem(ReceiptInfo receiptInfo);
    void slot_getSaleReceiptOrder(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> infoList, QList<PaymentDetailInfo> paymentInfoList);
    void slot_clickDate(int nYear, int nMonth, int nDay);
    void slot_searchChanged(QString keyStr);
    void on_lastPageButton_clicked();

    void on_nextPageButton_clicked();

    void on_checkButton_clicked();

signals:
    void sigShowDetialPage();
    void sigGetSaleReceiptOrder(int nCode, QString sMsg, SaleHead saleHead, QList<SaleDetails> infoList, QList<PaymentDetailInfo> paymentInfoList);

private:
    Ui::ReceiptListWidget *ui;
    QList<ReceiptInfo> m_InfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
    bool m_bInStartDate;
    QString m_sStartDate;
    QString m_sEndDate;
    KPosCalendarWidget* m_pKPosCalendarWidget;
    SaleDetialCtrl* m_saleDetialCtrl;

private:
    void initconnect();
    void initButton();
    void test();
    void generateUI();
    void checkCurPageButtonState();
    void inputStartDate();
    void inputEndDate();
    void updateUI(int count);
};

#endif // RECEIPTLISTWIDGET_H
