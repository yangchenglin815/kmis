#include "OperateWidget.h"
#include "ui_OperateWidget.h"
#include "enumData.h"
#include "EnumToString.h"

OperateWidget::OperateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OperateWidget)
  , m_nColumn( 5 )
{
    ui->setupUi(this);

    setColumn( m_nColumn );
    initCtrl();
    initConnect();
    test();
}

OperateWidget::~OperateWidget()
{
    delete ui;
}

void OperateWidget::setColumn( int nColumn )
{
    m_nColumn = nColumn;

//    initCtrl();

//    test();
}

void OperateWidget::setUnSelectStatus( HomeKeyType eHomeKeyType )
{
    switch( eHomeKeyType ) {
    case e_homeElse:
    {
        QList<OperatorButton*>::iterator itBtn = m_listOperatorBtn.begin();
        for( ; itBtn != m_listOperatorBtn.end(); ++itBtn ) {
            if( (*itBtn)->getKeyId() == e_homeElse ) {
                (*itBtn)->setUnSelectedSelf();
                break;
            }
        }
    }
        break;
    case e_homeMember:
        break;
    case e_homePending:
        break;
    case e_homeCancel:
        break;
    case e_homeTrimMoney:
        break;
    case e_homeDiscount:
        break;
    case e_lastReceipt:
        break;
    case e_homeFastCreateDocument:
        break;
    case e_homeTrimBox:
        break;
    case e_homeDiscountAll:
        break;
    case e_homePurse:
        break;
    case e_homeRefundGoods:
        break;
    case e_homeLock://手动锁屏
        break;
    case e_homeModifyNum:
        break;
    default:
        break;
    }
}

void OperateWidget::updateOperateList( QList<KeySetInfo> &listKeyInfo )
{
    clearBtnInfo();
    setKeyInfo( listKeyInfo );
}

void OperateWidget::updatePendingNum()
{
    QList<OperatorButton*>::iterator itBtn = m_listOperatorBtn.begin();
    for( ; itBtn != m_listOperatorBtn.end(); ++itBtn )
    {
        if( (*itBtn)->getKeyId() == e_homePending )
        {
            (*itBtn)->setPendingNum();
            break;
        }
    }
}

void OperateWidget::setKeyInfo( QList<KeySetInfo> listKeyInfo )
{
    QList<KeySetInfo>::iterator it = listKeyInfo.begin();
    QList<OperatorButton*>::iterator itBtn = m_listOperatorBtn.begin();
    for( ; it != listKeyInfo.end(); ++it ) {
        if( !it->bStartUsed ) continue;
        if( itBtn == m_listOperatorBtn.end() ) return;

        QString strName = EnumToString::keySetTypeToString( it->nKeyId );
        (*itBtn)->setText( strName );
        (*itBtn)->setKeyId( it->nKeyId );
        (*itBtn)->show();
        ++itBtn;
    }
}

void OperateWidget::slot_clicked( int nKeyId )
{
    if( nKeyId == e_homeElse ) {
        emit sig_showOtherButton();
    } else {
        emit sig_clicked( nKeyId );
    }


//    switch( nKeyId ) {
//    case e_homeElse:
//        emit sig_showOtherButton();
//        break;
//    case e_homeMember:
//        emit sig_showMemDlg();
//        break;
//    case e_homePending:
//        emit sig_showPendingDlg();
//        break;
//    case e_homeCancel:
//        emit sig_deleteSelectGoods();
//        break;
//    case e_homeTrimMoney:
//        break;
//    case e_homeDiscount:
//        break;
//    case e_lastReceipt:
//        break;
//    case e_homeFastCreateDocument:
//        break;
//    case e_homeTrimBox:
//        emit sig_peeling();
//        break;
//    case e_homeDiscountAll:
//        break;
//    case e_homePurse:
//        break;
//    case e_homeRefundGoods:
//        break;
//    case e_homeLock://手动锁屏
//        break;
//    case e_homeModifyNum:
//        emit sig_modifyNum();
//        break;
//    default:
//        break;
//    }
}

void OperateWidget::initCtrl()
{
    m_listOperatorBtn.append( ui->operator_01 );
    m_listOperatorBtn.append( ui->operator_02 );
    m_listOperatorBtn.append( ui->operator_03 );
    m_listOperatorBtn.append( ui->operator_04 );
    m_listOperatorBtn.append( ui->operator_05 );

    if( m_nColumn == 6 ) {
        m_listOperatorBtn.append( ui->operator_06 );
        ui->operator_06->show();
    } else {
        ui->operator_06->hide();
    }

    clearBtnInfo();
}

void OperateWidget::initConnect()
{
    QList<OperatorButton*>::iterator it = m_listOperatorBtn.begin();
    for( ; it != m_listOperatorBtn.end(); ++it ) {
        connect( *it, SIGNAL(sig_clicked(int)), this, SLOT( slot_clicked( int ) ) );
    }
}

void OperateWidget::clearBtnInfo()
{
    QList<OperatorButton*>::iterator it = m_listOperatorBtn.begin();
    for( ; it != m_listOperatorBtn.end(); ++it ) {
        (*it)->initCtrl();
    }
    update();
}

void OperateWidget::test()
{
    QList<KeySetInfo> listKeyInfo;
    KeySetInfo stKeyInfo;
    stKeyInfo.bStartUsed = true;
    stKeyInfo.nKeyId = e_homeElse;
    listKeyInfo.append( stKeyInfo );

    stKeyInfo.nKeyId = e_homeMember;
    listKeyInfo.append( stKeyInfo );

    stKeyInfo.nKeyId = e_homePending;
    listKeyInfo.append( stKeyInfo );

    stKeyInfo.nKeyId = e_homeCancel;
    listKeyInfo.append( stKeyInfo );

    stKeyInfo.nKeyId = e_homeModifyNum;
    listKeyInfo.append( stKeyInfo );

    setKeyInfo( listKeyInfo );
}
