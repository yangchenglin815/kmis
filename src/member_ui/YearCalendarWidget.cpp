#include "YearCalendarWidget.h"
#include "ui_YearCalendarWidget.h"

YearCalendarWidget::YearCalendarWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::YearCalendarWidget)
    , m_nCurPage( 1 )
    , m_nTotalPage( 1 )
    , m_nOnePageCount( 20 )
{
    ui->setupUi(this);

    initCtrl();
}

YearCalendarWidget::~YearCalendarWidget()
{
    delete ui;
}

void YearCalendarWidget::slot_upPage()
{
    if (m_nCurPage > 1)
    {
        m_nCurPage--;
        setCurPage( m_nCurPage, m_nTotalPage );
    }
    if ( m_nCurPage == 1 )
    {
        ui->upBtn->setEnabled(false);
    }

    ui->downBtn->setEnabled(true);

    generateYearList();
}

void YearCalendarWidget::slot_downPage()
{
    int nLen = m_mapYearInfo.size();
    if (m_nCurPage*m_nOnePageCount + m_nOnePageCount < nLen)
    {
        m_nCurPage++;
        setCurPage( m_nCurPage, m_nTotalPage );
    } else {
        ui->downBtn->setEnabled(false);
    }

    if (m_nCurPage >= (m_nTotalPage - 1) && ui->downBtn != NULL)
    {
        ui->downBtn->setEnabled(false);
    }

    ui->upBtn->setEnabled(true);

    generateYearList();
}

void YearCalendarWidget::initCtrl()
{
    initYear();
}

void YearCalendarWidget::initYear()
{
    const int nYearId = 1900;

    int j = 1;
    for( int i = nYearId; i<=2099; ++i ) {
        YearInfo stYearInfo;
        stYearInfo.nId = j;
        stYearInfo.nYearId = nYearId;
        m_mapYearInfo.insert( j, stYearInfo );
        ++j;
    }

    generateYearList();
}

void YearCalendarWidget::initConnect()
{
    connect( ui->upBtn, SIGNAL(clicked()), this, SLOT( slot_upPage() ) );
    connect( ui->downBtn, SIGNAL(clicked()), this, SLOT( slot_downPage() ) );
}

void YearCalendarWidget::clearYearInfo()
{
    m_mapYearInfo.clear();
}

void YearCalendarWidget::clearItems()
{
    ui->yearListView->clearItems();
}

void YearCalendarWidget::setCurPage( int nCurPage, int nTotalPage )
{
    if( nTotalPage <= 1 )
    {
        nTotalPage = 1;
        ui->upBtn->setEnabled( false );
        ui->downBtn->setEnabled( false );
    }
    else
    {
        nTotalPage--;
    }

//    QString strNum = QString( "%1/%2页" ).arg( nCurPage ).arg( nTotalPage );
//    ui->downBtn->setText( strNum );
}

//重新生成分类列表
void YearCalendarWidget::generateYearList()
{
    clearItems();
    int nStartPos = m_nOnePageCount * (m_nCurPage - 1);
    int nEndPos = m_nOnePageCount + m_nOnePageCount * m_nCurPage;
    int nLen = m_mapYearInfo.size();
    for (int i = nStartPos; i < nEndPos && i < nLen; i++)
    {
        ui->yearListView->appendItem( m_mapYearInfo[i] );
    }
}
