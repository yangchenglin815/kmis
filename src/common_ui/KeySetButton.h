#ifndef KEYSETBUTTON_H
#define KEYSETBUTTON_H
#include <QPushButton>

class KeySetButton : public QPushButton
{
    Q_OBJECT
public:
    explicit KeySetButton( QWidget *parent = 0 );
    ~KeySetButton();
public:
    //void paintEvent( QPaintEvent *event );
private:
    QString m_sText;
    bool m_bEnable;
};

#endif // KEYSETBUTTON_H
