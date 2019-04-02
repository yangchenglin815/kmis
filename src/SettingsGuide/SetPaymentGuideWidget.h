#ifndef SETPAYMENTGUIDEWIDGET_H
#define SETPAYMENTGUIDEWIDGET_H

#include <QWidget>

namespace Ui {
class SetPaymentGuideWidget;
}

class SetPaymentGuideWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SetPaymentGuideWidget(QWidget *parent = 0);
    ~SetPaymentGuideWidget();
signals:
    void sigOnShowParamPage();
private slots:
    void on_pushButton_clicked();

private:
    Ui::SetPaymentGuideWidget *ui;
};

#endif // SETPAYMENTGUIDEWIDGET_H
