#ifndef UPARROWBUTTON_H
#define UPARROWBUTTON_H

#include <QPushButton>

class KPosArrowButton : public QWidget
{
    Q_OBJECT
public:
    explicit KPosArrowButton(QWidget *parent = 0);
    void setArrowText(QString sArrowText);
    void setArrowDisable();
    void setArrowEnable();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void initArrowPath(QString sArrowNormalPath, QString sArrowPressedPath = "", QString sArrowDisablePath = "");

private:
    void setArrowPath(QString sArrowPath);

signals:
    void sigClick();

private:
    int m_nArrowWidth;
    int m_nArrowHeight;
    QString m_sArrowPath;
    QString m_sArrowNormalPath; // 正常
    QString m_sArrowPressedPath; // 点击
    QString m_sArrowDisablePath; // 不可用
    QString m_sArrowText;
    bool m_bEnAble;
};

class KPosUpArrowButton : public KPosArrowButton
{
public:
    KPosUpArrowButton(QWidget *parent = 0);
};

class KPosDownArrowButton: public KPosArrowButton
{
public:
    KPosDownArrowButton(QWidget *parent = 0);
};

#endif // UPARROWBUTTON_H
