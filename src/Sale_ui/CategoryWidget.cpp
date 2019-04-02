#include "CategoryWidget.h"
#include "ui_CategoryWidget.h"
#include "GlobalSignal.h"
#include "../data/constData.h"
#include <QDebug>

CategoryWidget::CategoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CategoryWidget)
    , m_eCategoryWidgetType( e_categoryNull )
    , m_nCurPage(1)
    , m_nTotalPage( 1 )
    , m_nOnePageCount(36)
    , m_pUpPageButton(NULL)
    , m_pDownPageButton(NULL)
{
    ui->setupUi(this);

    setAttribute( Qt::WA_TranslucentBackground, true );//背景透明

    initCtrl();
    initConnect();
}

CategoryWidget::~CategoryWidget()
{
    delete ui;
}

void CategoryWidget::initCategoryInfoList( QList<CategoryInfo*> categoryInfoList, int nMovePosition )
{
    Q_UNUSED( categoryInfoList )
    Q_UNUSED( nMovePosition )
//    if( categoryInfoList.size() == 0 ) return;

//    m_listCategoryInfo.clear();
//    m_pDownPageButton->setEnabled( true );

//    m_listCategoryInfo = categoryInfoList;
//    m_nCurPage = nMovePosition / m_nOnePageCount + (nMovePosition %  m_nOnePageCount == 0? 0 : 1);
//    int nLen = m_listCategoryInfo.length();
//    m_nTotalPage = nLen / m_nOnePageCount + (nLen % m_nOnePageCount == 0? 0 : 1);
//    setCurPage(m_nCurPage, m_nTotalPage);
//    generateCategoryList();
//    int nSelectedPosition = nMovePosition % (2 * m_nOnePageCount);
//    if (nSelectedPosition == 0)
//    {
//        nSelectedPosition = 2*m_nOnePageCount;
//    }
//    QString strCurCategoryKeyId = ui->categoryListView->findCategoryKeyId( nSelectedPosition );
//    ui->categoryListView->setCurCategoryKeyId( strCurCategoryKeyId );
//    emit sig_getGoodsList( strCurCategoryKeyId );
}

void CategoryWidget::setUpDownPageButton( QPushButton *pUpPageButton, QPushButton *pDownPageButton )
{
    m_pUpPageButton = pUpPageButton;
    m_pDownPageButton = pDownPageButton;

    connect(m_pUpPageButton, SIGNAL(clicked()), this, SLOT(slot_upPage()));
    connect(m_pDownPageButton, SIGNAL(clicked()), this, SLOT(slot_downPage()));
}

void CategoryWidget::initData(QList<CategoryInfo *> categoryInfoList)
{
    m_listCategoryInfo = categoryInfoList;

    m_nCurPage = 1;
    int nCount = m_listCategoryInfo.size();
    m_nTotalPage = nCount/m_nOnePageCount + ((nCount%m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();

    if (ui->categoryListView->isSelectedEmptyKeyId())
    {
        if (nCount > 0)
        {
            QString sKeyId = categoryInfoList[0]->sKeyId;
            ui->categoryListView->setSelectedKeyId(sKeyId);
            emit sig_getGoodsList(sKeyId);
        }
    }
    else
    {
        QString sKeyId = ui->categoryListView->getSelectedKeyId();
        bool isExistSelectKeyId = false;
        for (int i = 0; i < nCount; i++)
        {
            if(m_listCategoryInfo[i]->sKeyId == sKeyId)
            {
                isExistSelectKeyId = true;
                break;
            }
        }
        if (isExistSelectKeyId)
        {
            emit sig_getGoodsList(sKeyId);
        }
        else
        {
            if (nCount > 0)
            {
                sKeyId = categoryInfoList[0]->sKeyId;
                ui->categoryListView->setSelectedKeyId(sKeyId);
                emit sig_getGoodsList(sKeyId);
            }
        }
    }

    generateCategoryList();
}

QString CategoryWidget::getCurCategory()
{
    return ui->categoryListView->getSelectedKeyId();
}

void CategoryWidget::slot_addCategoryInfo( const QList<CategoryInfo*> &categoryInfoList )
{
    this->initCategoryInfoList( categoryInfoList, 1);
}

void CategoryWidget::slot_deleteCategory(QString strCategoryKeyId)
{
    int nId = -1;
    QList<CategoryInfo*>::iterator it = m_listCategoryInfo.begin();
    for( ; it != m_listCategoryInfo.end(); ++it ) {
        if( (*it)->sKeyId == strCategoryKeyId ) {
            nId = (*it)->nId;
            break;
        }
    }

    if( nId < 0 ) return;

    emit sigDeleteCategory( nId );
}

void CategoryWidget::resizeEvent(QResizeEvent *)
{
    int width = this->width();
    int height = this->height();


    int widthNum = width/80;

    if(widthNum > 6)
    {
        widthNum = 6;
    }

    m_nOnePageCount = widthNum * 2;
    int nCount = m_listCategoryInfo.size();
    m_nTotalPage = nCount/m_nOnePageCount + ((nCount%m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }

    int newItemWidth = width/widthNum;
    ui->categoryListView->setWidth(newItemWidth);

    int newItemHeight= height/2;
    ui->categoryListView->setHeight(newItemHeight);

    checkCurPageButtonState();
    generateCategoryList();
}

void CategoryWidget::slot_upPage()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateCategoryList();
}

void CategoryWidget::slot_downPage()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateCategoryList();
}

void CategoryWidget::initCtrl()
{

}

void CategoryWidget::initConnect()
{
    connect(ui->categoryListView, SIGNAL(sigItemClicked(QString)), this, SIGNAL(sig_getGoodsList(QString)));
    connect(ui->categoryListView, SIGNAL(sigItemDbClicked(QString)), this, SIGNAL(sigItemDbClicked(QString)));
    connect(ui->categoryListView, SIGNAL(sigDeleteCategory(QString)), this, SLOT(slot_deleteCategory(QString)));
}

void CategoryWidget::clearText()
{
    ui->categoryListView->clearItems();
}

void CategoryWidget::setCurPage( int nCurPage, int nTotalPage )
{
    if( !m_pDownPageButton ) return;
    if( !m_pUpPageButton ) return;

    if( nTotalPage <= 1 )
    {
        nTotalPage = 1;
        m_pUpPageButton->setEnabled( false );
        m_pDownPageButton->setEnabled( false );
    }
    else
    {
        nTotalPage--;
    }

    QString strNum = QString( "%1/%2页" ).arg( nCurPage ).arg( nTotalPage );
    m_pDownPageButton->setText( strNum );
}

//重新生成分类列表
void CategoryWidget::generateCategoryList()
{
    if (m_pDownPageButton == NULL)
    {
        return;
    }
    m_pDownPageButton->setText(QString("%1/%2页").arg(m_nCurPage).arg(m_nTotalPage));
    ui->categoryListView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_listCategoryInfo.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->categoryListView->appendItem(*(m_listCategoryInfo[i]));
    }

    ui->categoryListView->setStartPosition(nStartPos);

    int nLen = nEndPos - nCount;
    for (int i = 0; i < nLen; i++)
    {
        CategoryInfo categoryInfo;
        categoryInfo.nId = c_nNegativeNumber - i;
        categoryInfo.sKeyId = QString("2+%1").arg(categoryInfo.nId);
        ui->categoryListView->appendItem(categoryInfo);
    }
}

void CategoryWidget::checkCurPageButtonState()
{
    if ((m_pUpPageButton == NULL) || (m_pDownPageButton == NULL))
    {
        return;
    }

    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        m_pUpPageButton->setEnabled(false);
    }
    else
    {
        m_pUpPageButton->setEnabled(true);
    }

    if (m_nCurPage < m_nTotalPage)
    {
        m_pDownPageButton->setEnabled(true);
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        m_pDownPageButton->setEnabled(false);
    }
}

void CategoryWidget::setCategoryWidgetType( CategoryWidgetType eCategoryWidgetType )
{
    m_eCategoryWidgetType = eCategoryWidgetType;
    if (eCategoryWidgetType == e_categorySet)
    {
        ui->categoryListView->setSetPageFlag(true);
    }
}
