#ifndef OPERATORBUTTON_H
#define OPERATORBUTTON_H

#include <QPushButton>
#include <QTimer>

class OperatorButton : public QPushButton
{
    Q_OBJECT
public:
    explicit OperatorButton( QWidget *parent = 0 );

    void initCtrl();
    void setKeyId( int nKeyId );
    int getKeyId();
    void setPendingNum();
//    int getPendingNum();
    void setSelectStatus( bool bSelect );
    bool isSelectStatus();
    void setSelectedSelf();
    void setUnSelectedSelf();
protected:
    void paintEvent( QPaintEvent *pEvent );
signals:
    void sig_clicked( int nKeyId );
private slots:
    void slot_clicked();
//    void slot_updatePendingNum();
private:
    void initConnect();

//    void startTimer();
//    void stopTimer();
private:
    bool m_bSelect;
    int m_nKeyId;
    int m_nPendingNum;

//    QTimer m_updateNumTimer;
};

#endif // OPERATORBUTTON_H
