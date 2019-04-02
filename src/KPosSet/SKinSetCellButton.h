#ifndef SKINSETCELLWIDGET_H
#define SKINSETCELLWIDGET_H

#include <QPushButton>

class SKinSetCellButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SKinSetCellButton(QWidget *parent = 0);
    void setSkinType(int nSkinType);
    void setSelectedState(bool bSelected);

protected:
    void paintEvent(QPaintEvent *event);

private:
    bool m_bSelected;
    int m_nSkinType;
    QString m_sSkinPath;
};

#endif // SKINSETCELLWIDGET_H
