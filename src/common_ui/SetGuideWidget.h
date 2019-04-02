#ifndef SETGUIDEWIDGET_H
#define SETGUIDEWIDGET_H

#include <QWidget>

namespace Ui {
class SetGuideWidget;
}

class SetGuideWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SetGuideWidget(QWidget *parent = 0);
    ~SetGuideWidget();
    void showSetBaseGuidePage();
signals:
    void sigOnShowHomePage();
    void sigOnShowSetButtonPage();
    void sigOnShowSetGoodsPage();
    void sigOnShowSetDevicePage();
    void sigOnShowSetPaymentPage();
    void sigOnShowSetParamPage();
private slots:
    void showSetButtonGuidePage();
    void showSetGoodsGuidePage();
    void showSetDeviceGuidePage();
    void showSetPaymentGuidePage();
    void showSetParamGuidePage();
    void showHomePage();
private:
    Ui::SetGuideWidget *ui;
private:
    void initconnect();
};

#endif // SETGUIDEWIDGET_H
