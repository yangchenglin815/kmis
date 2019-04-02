#include "CustomerPlatformLabel.h"
#include <QFontDatabase>
#include <QPainter>

CustomerPlatformLabel::CustomerPlatformLabel( QWidget *parent )
    : QLabel( parent )
{
    QString strFontPath = ":/font/UnidreamLED.ttf";
    int nIndex = QFontDatabase::addApplicationFont( strFontPath );
    if ( nIndex != -1 )
    {
        QStringList strList( QFontDatabase::applicationFontFamilies( nIndex ) );
        if (strList.count() > 0)
        {
            QFont fontThis( strList.at(0) );
            fontThis.setPixelSize( 38 );
            setFont( fontThis );
        }
    }
}

CustomerPlatformLabel::~CustomerPlatformLabel()
{

}


void CustomerPlatformLabel::setText( QString strText )
{
    m_sText = strText;
    update();
}

void CustomerPlatformLabel::paintEvent( QPaintEvent *event )
{
    Q_UNUSED( event )

    QPainter draw( this );

    int nLen = draw.fontMetrics().width( m_sText );
    draw.drawText( QRect(0,0, nLen, height()), m_sText );
    draw.drawImage( QRect( nLen, 0, 20, height() ), QImage( ":/customer/kg.png" ) );

    draw.end();
}
