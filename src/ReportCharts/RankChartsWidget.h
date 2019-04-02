#ifndef RANKCHARTSWIDGET_H
#define RANKCHARTSWIDGET_H

#include <QWidget>

namespace Ui {
class RankChartsWidget;
}

class RankChartsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RankChartsWidget(QWidget *parent = 0);
    ~RankChartsWidget();
    void test();

private:
    Ui::RankChartsWidget *ui;
};

#endif // RANKCHARTSWIDGET_H
