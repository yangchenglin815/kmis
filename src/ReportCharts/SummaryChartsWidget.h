#ifndef SUMMARYCHARTSWIDGET_H
#define SUMMARYCHARTSWIDGET_H

#include <QWidget>

namespace Ui {
class SummaryChartsWidget;
}

class SummaryChartsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SummaryChartsWidget(QWidget *parent = 0);
    ~SummaryChartsWidget();
    void test();

private:
    Ui::SummaryChartsWidget *ui;
};

#endif // SUMMARYCHARTSWIDGET_H
