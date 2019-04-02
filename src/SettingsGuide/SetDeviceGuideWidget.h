#ifndef SETDEVICEGUIDEWIDGET_H
#define SETDEVICEGUIDEWIDGET_H

#include <QWidget>

namespace Ui {
class SetDeviceGuideWidget;
}

class SetDeviceGuideWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SetDeviceGuideWidget(QWidget *parent = 0);
    ~SetDeviceGuideWidget();
signals:
    void sigOnShowPaymentPage();
private slots:
    void on_pushButton_clicked();

private:
    Ui::SetDeviceGuideWidget *ui;
};

#endif // SETDEVICEGUIDEWIDGET_H
