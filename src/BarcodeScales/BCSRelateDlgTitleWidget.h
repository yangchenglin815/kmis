#ifndef BCSRELATEDLGTITLEWIDGET_H
#define BCSRELATEDLGTITLEWIDGET_H

#include <QWidget>

class BCSRelateDlgTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCSRelateDlgTitleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void sigSelectBox(bool bSelect);

private:
    bool m_bSelected;
};

#endif // BCSRELATEDLGTITLEWIDGET_H
