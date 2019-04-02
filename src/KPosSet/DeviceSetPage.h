#ifndef DEVICESETPAGE_H
#define DEVICESETPAGE_H

#include <QWidget>

namespace Ui {
class DeviceSetPage;
}

class DeviceSetPage : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceSetPage(QWidget *parent = 0);
    ~DeviceSetPage();

private slots:
    void on_typeButton1_clicked();
    void on_typeButton2_clicked();
    void on_pricingScaleType_currentIndexChanged(int index);
    void on_pricingScalePort_currentIndexChanged(int index);

private:
    void initConnect();

private:
    Ui::DeviceSetPage *ui;
};

#endif // DEVICESETPAGE_H
