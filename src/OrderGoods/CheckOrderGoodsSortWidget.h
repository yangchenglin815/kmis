#ifndef CHECKORDERGOODSSORTWIDGET_H
#define CHECKORDERGOODSSORTWIDGET_H

#include <QWidget>
#include "../data/enumData.h"

class CheckOrderGoodsSortWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CheckOrderGoodsSortWidget(QWidget *parent = 0);
    void setSortType(CheckOrderGoodsSortType eCheckOrderGoodsSortType);
    void setSelectedState();
    void canncleSelectedState();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    QString getShowText();

private slots:
    void slot_clickCheckOrderGoodsSortWidget(int nType);

signals:
    void sigClickText();
    void sigDownSort(bool bDownSort);

private:
    CheckOrderGoodsSortType m_eCheckOrderGoodsSortType;
    QString m_eShowText;
    bool m_bDownSort;
    bool m_bSelected;
    int m_nSortArrowStartXPos;
    int m_nSortArrowEndXPos;
};

#endif // CHECKORDERGOODSSORTWIDGET_H
