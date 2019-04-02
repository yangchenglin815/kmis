#ifndef CHECKORDERCATEGORYDETAILTITLEWIDGET_H
#define CHECKORDERCATEGORYDETAILTITLEWIDGET_H

#include <QWidget>

class CheckOrderCategoryDetailTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CheckOrderCategoryDetailTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CHECKORDERCATEGORYDETAILTITLEWIDGET_H
