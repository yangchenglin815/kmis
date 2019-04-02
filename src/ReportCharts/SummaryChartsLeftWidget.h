#ifndef SUMMARYCHARTSLEFTWIDGET_H
#define SUMMARYCHARTSLEFTWIDGET_H

#include <QWidget>
#include "../data/reportchartsdata.h"

namespace Ui {
class SummaryChartsLeftWidget;
}

class SummaryChartsLeftWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SummaryChartsLeftWidget(QWidget *parent = 0);
    ~SummaryChartsLeftWidget();
    void test();

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();

private:
    void generateUI();
    void checkCurPageButtonState();

private:
    Ui::SummaryChartsLeftWidget *ui;
    QList<SummaryChartsInfo*> m_summaryChartsInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // SUMMARYCHARTSLEFTWIDGET_H
