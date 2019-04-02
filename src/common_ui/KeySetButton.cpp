#include "KeySetButton.h"
#include <QPainter>

KeySetButton::KeySetButton(QWidget *parent)
    : QPushButton( parent )
    , m_sText( "" )
    , m_bEnable( true )
{

}

KeySetButton::~KeySetButton()
{

}

//void KeySetButton::paintEvent( QPaintEvent *event )
//{
//    Q_UNUSED( event )

//    QPainter draw( this );

//    draw.end();
//}
