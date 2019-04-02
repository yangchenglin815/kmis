#ifndef GOODSSELLLISTTITLEWIDGET_H
#define GOODSSELLLISTTITLEWIDGET_H

#include <QWidget>

class GoodsSellListTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GoodsSellListTitleWidget(QWidget *parent = 0);

    void setPixSize( int nPixSize );
protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_nPixSize;
};

#endif // GOODSSELLLISTTITLEWIDGET_H
