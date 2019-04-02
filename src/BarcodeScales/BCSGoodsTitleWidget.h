#ifndef BCSGOODSTITLEWIDGET_H
#define BCSGOODSTITLEWIDGET_H

#include <QWidget>

class BCSGoodsTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCSGoodsTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void sigSelectBox(bool bSelect);

private:
    bool m_bSelected;
};

#endif // BCSGOODSTITLEWIDGET_H
