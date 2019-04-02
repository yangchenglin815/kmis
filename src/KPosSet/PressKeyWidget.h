#ifndef PRESSKEYWIDGET_H
#define PRESSKEYWIDGET_H

#include <QWidget>

class PressKeyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PressKeyWidget(QWidget *parent = 0);
    // 三种界面效果
    void addEye(); // 第一种界面效果
    void addEye_Gray(); // 第二种界面效果
    void addGray_Eye(); // 第三种界面效果
    //
    void setContent(int nKeyId);
    void setEyeState(bool bOpen);
    void setPosition(int nPos);
    int getKeyId();
    bool isEyeOpen();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    void paintGrayRectImage(QPainter& painter, const QRect& rect);
    void paintEyeImage(QPainter &painter, const QRect& rect);

private:
    int m_nFirstLayerType;
    int m_nSecondLayerType;
    QString m_sContent;
    bool m_bEyeOpen;
    int m_nPosition;
    int m_nKeyId;
};

#endif // PRESSKEYWIDGET_H
