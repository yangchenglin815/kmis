#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "../Bussiness/ResetKeyCtrl.h"

namespace Ui {
class ResetKeyWgt;
}

class ResetKeyWgt : public QWidget
{
    Q_OBJECT

public:
    explicit ResetKeyWgt(QWidget *parent = 0);
    ~ResetKeyWgt();
    void clearData();

protected:
//    void resizeEvent( QResizeEvent *event );
    void showEvent(QShowEvent *);

signals:
    void sig_backHomePage();

private slots:
    void on_backButton_clicked();
    void slot_setText(QString str);
    void slot_delete();
    void slot_clear();
    void slot_confirm();
    void slot_confirm_clicked();
    void slot_resetPasswd(int nCode, QString sMsg);

private:
    Ui::ResetKeyWgt *ui;
    ResetKeyCtrl* m_pCtrl;
    void initConnect();
    int getCentorPosX();
    void setLoginInfoWidgetPos();
    void setKeyBoardPos();
};

#endif // WIDGET_H
