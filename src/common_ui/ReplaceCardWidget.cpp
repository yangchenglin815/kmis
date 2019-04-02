#include "ReplaceCardWidget.h"
#include "ui_ReplaceCardWidget.h"
#include "EnumToString.h"

ReplaceCardWidget::ReplaceCardWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReplaceCardWidget)
{
    ui->setupUi(this);

    initConnect();
}

ReplaceCardWidget::~ReplaceCardWidget()
{
    delete ui;
}

void ReplaceCardWidget::initData()
{
    ui->cardIdEdit->setText( "" );
    ui->warningLabel->setText( "" );
    ui->nameValueQueryLabel->setText( "" );
    ui->sexValueQueryLabel->setText( "" );
    ui->phoneValueQueryLabel->setText( "" );
    ui->payPwdValueLabel->setText( "" );
    ui->birthdayValueLabel->setText( "" );
    ui->documentTypeValueLabel->setText( "" );
    ui->documentIdValueLabel->setText( "" );
    ui->addressValueLabel->setText( "" );
    ui->memTypeValueLabel->setText( "" );
    ui->memGradeValueLabel->setText( "" );
    ui->balanceValueLabel->setText( "" );
    ui->integValueLabel->setText( "" );
}

void ReplaceCardWidget::setMemRegInfo( const MemRegisterInfo_s &stMemRegInfo )
{
    m_stMemRegInfo = stMemRegInfo;

    ui->cardIdEdit->setText( "" );
    ui->nameValueQueryLabel->setText( m_stMemRegInfo.stMemInfo.strName );
    ui->sexValueQueryLabel->setText( EnumToString::sexToString( m_stMemRegInfo.stMemInfo.nSex ) );

    if( m_stMemRegInfo.stMemInfo.strMobile.isEmpty() ) {
        ui->phoneValueQueryLabel->setText( m_stMemRegInfo.stMemInfo.strMobile );
    } else {
        ui->phoneValueQueryLabel->setText( m_stMemRegInfo.stMemInfo.strMobile.left(3) \
                                           + "****" + m_stMemRegInfo.stMemInfo.strMobile.right(4) );

    }
    if( m_stMemRegInfo.strPayPwd.isEmpty() ) {
        ui->payPwdValueLabel->setText( "" );
    } else {
        ui->payPwdValueLabel->setText( "******" );
    }

    ui->birthdayValueLabel->setText( m_stMemRegInfo.stMemInfo.dtBirthday.toString("yyyy.MM.dd") );
    ui->documentTypeValueLabel->setText( EnumToString::documentTypeToString( m_stMemRegInfo.eDocumentType ) );
    ui->documentIdValueLabel->setText( m_stMemRegInfo.strDocumentNum );
    ui->addressValueLabel->setText( m_stMemRegInfo.strAddress );

    QMap<int, MemTypeInfo_s>::iterator it = m_mapMemTypeInfo.find( m_stMemRegInfo.stMemInfo.nMemTypeId );
    if( it != m_mapMemTypeInfo.end() ) {
        ui->memTypeValueLabel->setText( it->strTypeName );
        QList<MemGradeInfo_s>::iterator itGrade = it->listMemGrade.begin();
        for( ; itGrade != it->listMemGrade.end(); ++itGrade ) {
            if( itGrade->nId == m_stMemRegInfo.stMemInfo.nMemLevelId ) {
                ui->memGradeValueLabel->setText( itGrade->strLevelName );
                break;
            }
        }
    }

    ui->balanceValueLabel->setText( "￥" + m_stMemRegInfo.stMemInfo.strAccountBalance );
    ui->integValueLabel->setText( QString::number( m_stMemRegInfo.stMemInfo.nIntegral ) );
}

void ReplaceCardWidget::setMemTypeInfo( QMap<int, MemTypeInfo_s> mapMemTypeInfo )
{
    m_mapMemTypeInfo.clear();
    initData();

    m_mapMemTypeInfo = mapMemTypeInfo;
}

QLineEdit *ReplaceCardWidget::getCardIdEdit()
{
    return ui->cardIdEdit;
}

QString ReplaceCardWidget::getCardId()
{
    return ui->cardIdEdit->text();
}

void ReplaceCardWidget::slot_replaceMemCard( int nCode, QString strMsg, QString strOldCardId, QString strNewCardId )
{
    if( nCode != 0 ) {
        ui->warningLabel->setText( strMsg );
        return;
    }

    ui->warningLabel->setText( strMsg );
    if( m_stMemRegInfo.stMemInfo.strCardNo != strOldCardId ) return;

    ui->cardIdEdit->setText( "" );
    m_stMemRegInfo.stMemInfo.nCardStatus = 1;
    m_stMemRegInfo.stMemInfo.strCardNo = strNewCardId;
    emit sig_replaceMemCard( strOldCardId, strNewCardId );
}

void ReplaceCardWidget::initConnect()
{
    connect( ui->commitReplaceButton, SIGNAL(clicked()), this, SIGNAL(sig_replaceQuest() ) );
}
