#include "Label.h"

Label::Label(QWidget *parent)
    : QLabel( parent )
    , m_bImage( false )
    , m_sNormalImage( "" )
    , m_sPressImage( "" )
{
    setStyleSheet( "background-image: url(:/shareImages/key_normal.png);");
}

Label::~Label()
{

}

void Label::mousePressEvent( QMouseEvent *event )
{
    Q_UNUSED( event )

    if( m_bImage ) {
        QString strStyle = QString( "background-image: url(%1);" ).arg( m_sPressImage );
        setStyleSheet( strStyle );
    } else {
        setStyleSheet( "background-image: url(:/shareImages/key_press.png);");
    }
    emit sig_clicked();
}

void Label::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED( event )

    if( m_bImage ) {
        QString strStyle = QString( "background-image: url(%1);" ).arg( m_sNormalImage );
        setStyleSheet( strStyle );
    } else {
        setStyleSheet( "background-image: url(:/shareImages/key_normal.png);");
    }
}

void Label::setBackGroundImage( QString strNormalImage, QString strPressImage )
{
    m_bImage = true;
    m_sNormalImage = strNormalImage;
    m_sPressImage = strPressImage;
}


