#include "PlatformLabel.h"
#include <QPainter>
#include <QPixmap>

int gnImageWidth = 11;
int gnPointWidth = 5;

PlatformLabel::PlatformLabel(QWidget *parent)
    : QLabel( parent )
    , m_sGoodsWeight( "00.000" )
{

}

PlatformLabel::~PlatformLabel()
{

}

void PlatformLabel::setfGoodsWeight( QString strGoodsWeight )
{
//    m_sGoodsWeight = strGoodsWeight;

    //strGoodsWeight = "-02.3451";
    m_sGoodsWeight.sprintf( "%06.3f", strGoodsWeight.toFloat() );
    update();
}

void PlatformLabel::paintEvent( QPaintEvent *event )
{
    Q_UNUSED( event )

    QPainter draw( this );

    int nHeight = height();

    //对负号的处理
    QStringList strListMinus = m_sGoodsWeight.split( "-" );
    int nX = width();
    QStringList strListGoodsWeight;
    if( strListMinus.size() == 1 ) {
        strListGoodsWeight = strListMinus[0].split( "." );
    } else if( strListMinus.size() == 2 ) {
        strListGoodsWeight = strListMinus[1].split( "." );
    }

    draw.drawImage( QRect( nX-gnImageWidth, 0, gnImageWidth, height() ), QImage( getUnitImage() ) );
    nX = nX-gnImageWidth;

    if( strListGoodsWeight.size() == 2 ) {
        QString strFloat = strListGoodsWeight[1];
        int j = strFloat.size()-1;
        for( ; j >= 0; --j ) {
            int nData = strFloat[j].digitValue();
            QString strDataImage = getDataImage( nData );
            draw.drawImage( QRect( nX -(strFloat.size()-j)*gnImageWidth, 0, gnImageWidth, height() ), QImage( strDataImage ) );
        }

        nX = nX -strFloat.size()*gnImageWidth;
        draw.drawImage( QRect( nX -gnPointWidth, 0, gnPointWidth, height() ), QImage( getPointImage() ) );
        nX = nX - gnPointWidth;
    }

    //对小数点的处理
    QString strInt = strListGoodsWeight[0];
    int i = strInt.size() -1;
    for( ; i >= 0; --i ) {
        int nData = strInt[i].digitValue();
        QString strDataImage = getDataImage( nData );
        draw.drawImage( QRect( nX - (strInt.size()-i)*gnImageWidth, 0, gnImageWidth, nHeight ), QImage( strDataImage ) );
    }
    nX = nX - strInt.size()*gnImageWidth;

    if( strInt.size()<2 ) {
        QString strDataImage = getDataImage( 0 );
        draw.drawImage( QRect( nX - gnImageWidth, 0, gnImageWidth, nHeight ), QImage( strDataImage ) );
        nX =  nX - gnImageWidth;
    }


    if( strListMinus.size() == 2 ) {
        draw.drawImage( QRect( nX -gnImageWidth, 0, gnImageWidth, nHeight ), QImage( getMinusImage() ) );
    }

    draw.end();
}

//获取负号图片
QString PlatformLabel::getMinusImage()
{
    QString strDataImage = ":/shareImages/-.png";

    return strDataImage;
}

QString PlatformLabel::getDataImage( int nData )
{
    if( nData < 0 || nData > 9 ) {
        nData = 0;
    }
    QString strDataImage = QString(":/shareImages/%1.png").arg( nData );

    return strDataImage;
}

QString PlatformLabel::getPointImage()
{
    QString strPointImage = ":/shareImages/point.png";

    return strPointImage;
}

//单位图片
QString PlatformLabel::getUnitImage()
{
    QString strUnitImage = ":/shareImages/kg.png";

    return strUnitImage;
}




