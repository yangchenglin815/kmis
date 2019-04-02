#ifndef RANKCHARTSLEFTWIDGET_H
#define RANKCHARTSLEFTWIDGET_H

#include <QWidget>
#include "../data/reportchartsdata.h"

namespace Ui {
class RankChartsLeftWidget;
}

class RankChartsLeftWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RankChartsLeftWidget(QWidget *parent = 0);
    ~RankChartsLeftWidget();
    void test();

private slots:
    void on_lastPageButton_clicked();
    void on_nextPageButton_clicked();

private:
    void generateUI();
    void checkCurPageButtonState();

private:
    Ui::RankChartsLeftWidget *ui;
    QList<RankChartsInfo*> m_rankChartsInfoList;
    int m_nOnePageCount;
    int m_nTotalPage;
    int m_nCurPage;
};

#endif // RANKCHARTSLEFTWIDGET_H
