#ifndef SETGOODSGUIDEWIDGET_H
#define SETGOODSGUIDEWIDGET_H

#include <QWidget>

namespace Ui {
class SetGoodsGuideWidget;
}

class SetGoodsGuideWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SetGoodsGuideWidget(QWidget *parent = 0);
    ~SetGoodsGuideWidget();
signals:
    void sigOnShowSetDevicePage();
private slots:
    void on_pushButton_clicked();

private:
    Ui::SetGoodsGuideWidget *ui;
};

#endif // SETGOODSGUIDEWIDGET_H
