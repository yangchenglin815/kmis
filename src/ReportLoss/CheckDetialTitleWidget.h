#ifndef CHECKDETIALTITLEWIDGET_H
#define CHECKDETIALTITLEWIDGET_H
#include <QWidget>

class CheckDetialTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CheckDetialTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void sigSortFoutthCol(bool bArrowDown);
    void sigSortFifthCol(bool bArrowDown);

private:
    int m_nFourthColArrowStartXPos;
    int m_nFifthColArrowStartXPos;
    bool m_bFourthArrowDown;
    bool m_bFifthArrowDown;
};
#endif // CHECKDETIALTITLEWIDGET_H
