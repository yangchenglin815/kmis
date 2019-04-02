#ifndef ORDERCATEGORYGOODSTITLEWIDGET_H
#define ORDERCATEGORYGOODSTITLEWIDGET_H

#include <QWidget>

class OrderCategoryGoodsTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OrderCategoryGoodsTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void sigSortSecondCol(bool bDown);
    void sigSortThirdCol(bool bDown);

private:
    int m_nFontSize;
    int m_nSecondColArrowStartXPos;
    int m_nThirdColArrowStartXPos;
    bool m_bScondArrowDown;
    bool m_bThirdArrowDown;
};

#endif // ORDERCATEGORYGOODSTITLEWIDGET_H
