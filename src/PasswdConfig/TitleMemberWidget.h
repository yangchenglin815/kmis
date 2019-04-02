#ifndef TITLEMEMBERWIDGET_H
#define TITLEMEMBERWIDGET_H

#include <QWidget>
#include <QMap>

class TitleMemberWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleMemberWidget(QWidget *parent = 0);
signals:
    void sigSelectBox(bool bSelect);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    bool m_bSelected;
};

#endif // TITLEMEMBERWIDGET_H
