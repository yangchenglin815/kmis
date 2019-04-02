#include "SalemanInfoDlg.h"
#include "ui_SalemanInfoDlg.h"

SalemanInfoDlg::SalemanInfoDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SalemanInfoDlg)
    , m_nCurPage( 1 )
    , m_nTotalPage( 1 )
    , m_nOnePageCount( 6 )
{
    ui->setupUi(this);

    initCtrl();
    initConnect();
}

SalemanInfoDlg::~SalemanInfoDlg()
{
    delete ui;
}

void SalemanInfoDlg::setSalemanInfo( QList<SalemanInfo> &listSalemanInfo )
{
    m_listSalemanInfo = listSalemanInfo;
    ui->listView->setSelectedUserId( -1 );

    m_nCurPage = 1;
    int nCount = m_listSalemanInfo.size();
    m_nTotalPage = nCount/m_nOnePageCount + ((nCount%m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateSalemanList();

}

SalemanInfo SalemanInfoDlg::getCurSalemanInfo()
{
    return m_stCurSalemanInfo;
}

void SalemanInfoDlg::slot_upPage()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateSalemanList();
}

void SalemanInfoDlg::slot_downPage()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateSalemanList();
}

void SalemanInfoDlg::slot_ItemClicked( int nSalemanUserId )
{
    int nLen = m_listSalemanInfo.size();
    for( int i=0; i<nLen; ++i ) {
        if( m_listSalemanInfo[i].nUserId == nSalemanUserId ) {
            m_stCurSalemanInfo = m_listSalemanInfo[i];
            accept();//reject
            break;
        }
    }
}

void SalemanInfoDlg::initCtrl()
{
    setWindowFlags( Qt::FramelessWindowHint );
    setModal( true );
    ui->titleWidget->setTitleText( "业务员" );
    setWindowTitle( "业务员" );
}

void SalemanInfoDlg::initConnect()
{
    connect( ui->upPageBtn, SIGNAL(clicked(bool)), this, SLOT( slot_upPage() ) );
    connect( ui->downPageBtn, SIGNAL(clicked(bool)), this, SLOT( slot_downPage() ) );
    connect( ui->listView, SIGNAL(sigItemClicked(int)), this, SLOT( slot_ItemClicked(int)) );
    connect( ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(close()) );
}

//重新生成分类列表
void SalemanInfoDlg::generateSalemanList()
{
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_listSalemanInfo.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem( m_listSalemanInfo[i] );
    }

//    ui->listView->setStartPosition(nStartPos);

//    int nLen = nEndPos - nCount;
//    for (int i = 0; i < nLen; i++)
//    {
//        CategoryInfo categoryInfo;
//        categoryInfo.nId = c_nNegativeNumber - i;
//        categoryInfo.sKeyId = QString("2+%1").arg(categoryInfo.nId);
//        ui->listView->appendItem(categoryInfo);
//    }
}

void SalemanInfoDlg::checkCurPageButtonState()
{
    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        ui->upPageBtn->setEnabled(false);
    }
    else
    {
        ui->upPageBtn->setEnabled(true);
    }

    if (m_nCurPage < m_nTotalPage)
    {
        ui->downPageBtn->setEnabled(true);
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        ui->downPageBtn->setEnabled(false);
    }
}
