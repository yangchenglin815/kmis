#include "OperatorButton.h"
#include "enumData.h"
#include "SaleHeadAgent.h"
#include <QPainter>
#include <QDebug>

OperatorButton::OperatorButton( QWidget *parent )
    : QPushButton( parent )
    , m_bSelect( false )
    , m_nKeyId( -1 )
    , m_nPendingNum( 0 )
{
    initCtrl();
    initConnect();
}

void OperatorButton::setKeyId( int nKeyId )
{
    m_nKeyId = nKeyId;
//    if( m_nKeyId == e_homePending ) {
//        startTimer();
//    } else {
//        stopTimer();
//    }
}

int OperatorButton::getKeyId()
{
    return m_nKeyId;
}

void OperatorButton::setPendingNum()
{
    m_nPendingNum = SaleHeadAgent::Instance()->getPendingOrder();
    update();
}

//int OperatorButton::getPendingNum()
//{
//    return m_nPendingNum;
//}

void OperatorButton::setSelectStatus( bool bSelect )
{
    m_bSelect = bSelect;
}

bool OperatorButton::isSelectStatus()
{
    return m_bSelect;
}

void OperatorButton::setSelectedSelf()
{
    this->setStyleSheet("QPushButton{color:#ffffff;font-size:12px;font-family:\"微软雅黑\";border-image: url(:/saleImage/operate_press.png);}"
                        "QPushButton:pressed{border-image: url(:/saleImage/operate_press.png);}" );
}

void OperatorButton::setUnSelectedSelf()
{
    this->setStyleSheet("QPushButton{color:#ffffff;font-size:12px;font-family:'微软雅黑';border-image: url(:/saleImage/operate_normal.png);}"
                        "QPushButton:pressed{border-image: url(:/saleImage/operate_press.png);}" );
}

void OperatorButton::paintEvent( QPaintEvent *pEvent )
{
    QPushButton::paintEvent( pEvent );

    if(m_nKeyId == e_homePending ){
        QPainter draw( this );
        draw.setBrush(QColor(242, 148, 96));
        draw.setPen(QPen(QColor(242, 148, 96), 0));
        QRectF rect(width()-19, y(), 18, 18);
        draw.drawEllipse(rect);
        draw.setPen(QPen(Qt::white, 0));
        draw.drawText(rect, Qt::AlignCenter, QString::number( m_nPendingNum ));
        draw.end();
    }
}

void OperatorButton::slot_clicked()
{
    if( m_bSelect ) {
        setSelectedSelf();
    } else {
        setUnSelectedSelf();
    }

    if( m_nKeyId == e_homeElse ) {
       setSelectedSelf();
    }

    emit sig_clicked( m_nKeyId );
}

//void OperatorButton::slot_updatePendingNum()
//{
//    int PendingNum = SaleHeadAgent::Instance()->getPendingOrder();
//    setPendingNum(PendingNum);
//}

void OperatorButton::initCtrl()
{
    setUnSelectedSelf();
    m_nKeyId = -1;
    m_bSelect = false;
    setText( "" );
    hide();
}

void OperatorButton::initConnect()
{
    connect( this, SIGNAL(clicked()), this, SLOT( slot_clicked() ) );

//    connect( &m_updateNumTimer, SIGNAL(timeout()), this, SLOT( slot_updatePendingNum() ) );
}

//void OperatorButton::startTimer()
//{
//    if( !m_updateNumTimer.isActive() ){
//        m_updateNumTimer.start(500);//500ms
//    }
//}

//void OperatorButton::stopTimer()
//{
//    m_updateNumTimer.stop();
//}
