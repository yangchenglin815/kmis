#ifndef VIRTUALPAYSWIDGET_H
#define VIRTUALPAYSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "setstructdata.h"

namespace Ui {
class VirtualPaysWidget;
}

class VirtualPaysWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VirtualPaysWidget(QWidget *parent = 0);
    ~VirtualPaysWidget();
    void setFactorAmt(QString sText);
    QString getFactorAmt();
    void initPayButtons(const QList<VirtualPayInfo> &payList);
    QString getCurPayName();
    PayWayInfoSet getCurPayWayInfo();

private slots:
    void slot_buttonClick();
    void on_confirmButton_clicked();

private:
    void init();

signals:
    void sigConfirm();

private:
    Ui::VirtualPaysWidget *ui;
    QMap<QPushButton*, PayWayInfoSet> m_virtualPayMap;
    QList<QPushButton*> m_buttons;
    QPushButton* m_pressedButton;
};

#endif // VIRTUALPAYSWIDGET_H
