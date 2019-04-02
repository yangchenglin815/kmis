#include "OtherOperateWidget.h"
#include "ui_OtherOperateWidget.h"
#include "EnumToString.h"
#include "enumData.h"
#include <QDebug>

OtherOperateWidget::OtherOperateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OtherOperateWidget)
{
    ui->setupUi(this);

    setWindowFlags( Qt::FramelessWindowHint | Qt::Tool );
    setAttribute(Qt::WA_TranslucentBackground,true);//背景透明

    initCtrl();
    initConnect();

    test();
}

OtherOperateWidget::~OtherOperateWidget()
{
    delete ui;
}

void OtherOperateWidget::updateOperateList( QList<KeySetInfo> &listHomeKey )
{
    clearBtnInfo();
    setOPerateList( listHomeKey );
}

void OtherOperateWidget::setOPerateList( QList<KeySetInfo> listHomeKey )
{
    QList<KeySetInfo>::iterator it = listHomeKey.begin(); // 首页按键列表
    QList<OperatorButton*>::iterator itBtn = m_listOtherKeyBtn.begin();

    for( ; it != listHomeKey.end(); ++it ) {
        if( !it->bStartUsed ) continue;
        if( itBtn == m_listOtherKeyBtn.end() ) break;

        QString strName = EnumToString::keySetTypeToString( it->nKeyId );
        (*itBtn)->setText( strName );
        (*itBtn)->setKeyId( it->nKeyId );
        (*itBtn)->show();

        ++itBtn;
    }
}

bool OtherOperateWidget::getOperateList()
{
    return true;
}

bool OtherOperateWidget::event(QEvent *e)
{
    if( e->type() == QEvent::WindowDeactivate ) {//window was deactivated
        emit sig_wndHide();
    }

    //qDebug()<<"OtherOperateWidget::event"<<e->type();
    return QWidget::event( e );
}

void OtherOperateWidget::initCtrl()
{
    m_listOtherKeyBtn.append( ui->otherOperator_01 );
    m_listOtherKeyBtn.append( ui->otherOperator_02 );
    m_listOtherKeyBtn.append( ui->otherOperator_03 );
    m_listOtherKeyBtn.append( ui->otherOperator_04 );
    m_listOtherKeyBtn.append( ui->otherOperator_05 );
    m_listOtherKeyBtn.append( ui->otherOperator_06 );
    m_listOtherKeyBtn.append( ui->otherOperator_07 );
    m_listOtherKeyBtn.append( ui->otherOperator_08 );
    m_listOtherKeyBtn.append( ui->otherOperator_09 );
}

void OtherOperateWidget::initConnect()
{
    QList<OperatorButton*>::iterator itBtn = m_listOtherKeyBtn.begin();
    for( ; itBtn != m_listOtherKeyBtn.end(); ++itBtn ) {
        if( *itBtn ) {
            connect( *itBtn, SIGNAL(sig_clicked(int)), this, SIGNAL(sig_clicked(int)) );
        }
    }
}

void OtherOperateWidget::test()
{
    QList<KeySetInfo> listHomeKey;

    KeySetInfo stKeySetInfo;
    stKeySetInfo.nKeyId = e_homeTrimMoney;
    stKeySetInfo.bStartUsed = true;
    listHomeKey.append( stKeySetInfo );

    stKeySetInfo.nKeyId = e_lastReceipt;
    listHomeKey.append( stKeySetInfo );

    stKeySetInfo.nKeyId = e_homeFastCreateDocument;
    listHomeKey.append( stKeySetInfo );

    stKeySetInfo.nKeyId = e_homeDiscount;
    listHomeKey.append( stKeySetInfo );

    stKeySetInfo.nKeyId = e_homeDiscountAll;
    listHomeKey.append( stKeySetInfo );

    stKeySetInfo.nKeyId = e_homePurse;
    listHomeKey.append( stKeySetInfo );

    stKeySetInfo.nKeyId = e_homeRefundGoods;
    listHomeKey.append( stKeySetInfo );

    stKeySetInfo.nKeyId = e_homeTrimBox;
    listHomeKey.append( stKeySetInfo );

    stKeySetInfo.nKeyId = e_homeLock;
    listHomeKey.append( stKeySetInfo );

    setOPerateList( listHomeKey );
}

void OtherOperateWidget::clearBtnInfo()
{
    QList<OperatorButton*>::iterator it = m_listOtherKeyBtn.begin();
    for( ; it != m_listOtherKeyBtn.end(); ++it ) {
        (*it)->initCtrl();
    }
}
