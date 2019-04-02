#include "GridWidget.h"
#include "ui_GridWidget.h"
#include <QPainter>

GridWidget::GridWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GridWidget)
  , m_nColumnNum( 0 )
  , m_nRowNum( 0 )
  , m_nWidth( 0 )
  , m_nHeight( 0 )
{
    ui->setupUi(this);
}

GridWidget::~GridWidget()
{
    delete ui;
}

void GridWidget::setColumnNum( int nColumnNum )
{
    m_nColumnNum = nColumnNum;
    update();
}

void GridWidget::setRowNum( int nRowNum )
{
    m_nRowNum = nRowNum;
    update();
}

void GridWidget::setWidgetSize( int nWidth, int nHeight )
{
    m_nWidth = nWidth;
    m_nHeight = nHeight;

    resize( m_nWidth, m_nHeight );
}

void GridWidget::setWidgetWidth( int nWidth )
{
    m_nWidth = nWidth;
    resize( m_nWidth, height() );
}

void GridWidget::setWidgetHeight( int nHeight )
{
    m_nHeight = nHeight;
    resize( width(), m_nHeight );
}

void GridWidget::paintEvent( QPaintEvent *event )
{
    Q_UNUSED( event )

    if( m_nColumnNum <=0 || m_nRowNum <= 0 ) {
        return;
    }

    QPainter draw( this );
    int nSingleWidth = width()/m_nColumnNum;
    int nSingleHeight = height()/m_nRowNum;

    draw.setPen( QColor( 217, 217, 217 ) );

    for( int i = 1; i< m_nRowNum; ++i ) {
        draw.drawLine( QPoint( 0, nSingleHeight*i), QPoint( width(), nSingleHeight*i) );
    }

    for( int j = 1; j < m_nColumnNum; ++j ) {
        draw.drawLine( QPoint( nSingleWidth*j, 0 ), QPoint( nSingleWidth*j, height() ) );
    }

    draw.drawRect( QRect( 0, 0, width()-1, height()-1 ) );
    draw.end();
}
