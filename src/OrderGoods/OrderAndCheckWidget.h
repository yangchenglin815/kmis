#ifndef ORDERANDCHECKWIDGET_H
#define ORDERANDCHECKWIDGET_H

#include <QWidget>

namespace Ui {
class OrderAndCheckWidget;
}

class OrderAndCheckWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderAndCheckWidget(QWidget *parent = 0);
    ~OrderAndCheckWidget();
    void test();

private slots:
    void slot_showOrderGoodsPage();
    void slot_backCheckOrderPage(bool bOrderCardChanged);

private:
    void initConnect();

signals:
    void sig_backHomePage();

private:
    Ui::OrderAndCheckWidget *ui;
};

#endif // ORDERANDCHECKWIDGET_H
