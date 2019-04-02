#ifndef TITLEBARWIDGET_H
#define TITLEBARWIDGET_H

#include <QWidget>

namespace Ui {
class TitleBarWidget;
}

class TitleBarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBarWidget(QWidget *parent = 0);
    ~TitleBarWidget();
public:
    void setTitleText( QString strTitleText );
    void setTitleWidth( int nTitleWidth );
    void setCloseButtonFocus( bool bFocus );
    void setCloseButtonEnabled( bool bEnabled );
    void hideTitleText();
signals:
    void sig_close_wnd();
private:
    void initCtrl();
    void initConnect();
private:
    Ui::TitleBarWidget *ui;
};

#endif // TITLEBARWIDGET_H
