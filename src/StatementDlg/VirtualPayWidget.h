#ifndef VIRTUALPAYWIDGET_H
#define VIRTUALPAYWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include "setstructdata.h"
#include "VirtualPayButton.h"

namespace Ui {
class VirtualPayWidget;
}

class VirtualPayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VirtualPayWidget(QWidget *parent = 0);
    ~VirtualPayWidget();
public:
    void setCurPayInfo( PayWayInfoSet stPayWayInfo );
    PayWayInfoSet getCurPayInfo();

    void initPayInfo();
    QLineEdit *getVirtualAmtEdit();
    void setVirtualWidgetVisible(bool bVisible);
    void clickPayBtn(int nBtnType);

signals:
    void sig_virtualStatement();
private:
    void initCtrl();
    void initVirtualPayMethod();
    void initConnect();

    void clearAllVirtualPayBtn();
private slots:
    void slot_virtualPayBtn();
private:
    Ui::VirtualPayWidget *ui;
    QList<VirtualPayButton*> m_listVirtualPayBtn;
    QList<PayWayInfoSet> m_listVirtualPay;
    PayWayInfoSet m_stCurPayInfo;
};

#endif // VIRTUALPAYWIDGET_H
