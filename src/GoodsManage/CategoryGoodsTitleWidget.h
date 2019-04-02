#ifndef CATEGORYGOODSTITLEWIDGET_H
#define CATEGORYGOODSTITLEWIDGET_H

#include <QWidget>

class CategoryGoodsTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CategoryGoodsTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // CATEGORYGOODSTITLEWIDGET_H
