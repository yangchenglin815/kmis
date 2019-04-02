#ifndef STOCKORDERSEARCHTITLEWIDGET_H
#define STOCKORDERSEARCHTITLEWIDGET_H

#include <QWidget>

class StockOrderSearchTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StockOrderSearchTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void sigSortSixthCol(bool bArrowDown);
    void sigSortSeventhCol(bool bArrowDown);

private:
    int m_nFontSize;
    int m_nSixthColArrowStartXPos;
    int m_nSeventhColArrowStartXPos;
    bool m_bSixthArrowDown;
    bool m_bSeventhArrowDown;
};

#endif // STOCKORDERSEARCHTITLEWIDGET_H
