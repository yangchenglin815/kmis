#ifndef PARAMSSHOPSETWIDGET_H
#define PARAMSSHOPSETWIDGET_H

#include <QWidget>

class ParamsShopSetWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ParamsShopSetWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_nRowCount;
};

#endif // PARAMSSHOPSETWIDGET_H
