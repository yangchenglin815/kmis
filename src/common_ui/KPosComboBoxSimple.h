#ifndef KPOSCOMBOBOXSIMPLE_H
#define KPOSCOMBOBOXSIMPLE_H

#include <QWidget>

class KPosComboBoxSimple : public QWidget
{
    Q_OBJECT
public:
    explicit KPosComboBoxSimple(QWidget *parent = 0);
    void setContent(QString content);
    void setFontSize(int nFontSize);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void sigClicked();

private:
    QString m_sContent;
    QString m_sOutLineColor;
    bool m_bHasOutline;
    int m_nFontSize;
};

#endif // KPOSCOMBOBOXSIMPLE_H
