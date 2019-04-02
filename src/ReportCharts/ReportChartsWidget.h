#ifndef REPORTCHARTSWIDGET_H
#define REPORTCHARTSWIDGET_H

#include <QWidget>

namespace Ui {
class ReportChartsWidget;
}

class ReportChartsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReportChartsWidget(QWidget *parent = 0);
    ~ReportChartsWidget();

private slots:
    void on_summaryChartsButton_clicked();
    void on_rankChartsButton_clicked();
    void slot_returnClicked();

private:
    void initConnect();

signals:
    void sigReturnClicked();

private:
    Ui::ReportChartsWidget *ui;
};

#endif // REPORTCHARTSWIDGET_H
