#ifndef CHECKORDERGOODSTITLEWIDGET_H
#define CHECKORDERGOODSTITLEWIDGET_H

#include <QWidget>

class CheckOrderGoodsTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CheckOrderGoodsTitleWidget(QWidget *parent = 0);
    void setCheckTitle(bool bFlag);

protected:
    void paintEvent(QPaintEvent *event);

private:
    bool m_bUploadFinished; // 是否审核标题
};

#endif // CHECKORDERGOODSTITLEWIDGET_H
