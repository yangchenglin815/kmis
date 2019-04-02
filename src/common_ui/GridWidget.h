#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H

#include <QWidget>
#include <QPaintEvent>

namespace Ui {
class GridWidget;
}

class GridWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GridWidget(QWidget *parent = 0);
    ~GridWidget();
public:
    void setColumnNum( int nColumnNum );
    void setRowNum( int nRowNum );
    void setWidgetSize( int nWidth, int nHeight );
    void setWidgetWidth( int nWidth );
    void setWidgetHeight( int nHeight );

protected:
    void paintEvent( QPaintEvent *event );

private:
    Ui::GridWidget *ui;

    int m_nColumnNum;
    int m_nRowNum;
    int m_nWidth;
    int m_nHeight;
};

#endif // GRIDWIDGET_H
