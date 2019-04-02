#ifndef TITLEBARLABEL_H
#define TITLEBARLABEL_H

#include <QLabel>

namespace Ui {
class TitleBarLabel;
}

class TitleBarLabel : public QLabel
{
    Q_OBJECT

public:
    explicit TitleBarLabel(QWidget *parent = 0);
    ~TitleBarLabel();

    void setPixSize( int nPixSize );
    void setBalanceStable( bool bStable );
    void setBalanceZero( bool bZero );
    void setBalanceOverload( bool bOverWeight );
    void setBalanceUnderload( bool bUnderWeight );
    void setMemStatus( bool bMemStatus );
    void init();

private slots:
    void slot_OnlineState(bool bOnline);

signals:
    void sig_backHomePage();
private:
    void initConnect();

private:
    Ui::TitleBarLabel *ui;
};

#endif // TITLEBARLABEL_H
