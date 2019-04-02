#ifndef PROGRESSWIDGET_H
#define PROGRESSWIDGET_H

#include <QWidget>

class ProgressWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProgressWidget(QWidget *parent = 0);
    void setProgressValue(int progressValue);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_nProgressValue; // 百分比进度值
};

#endif // PROGRESSWIDGET_H
