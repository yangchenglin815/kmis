#include "GoodsWidget.h"
#include "ui_GoodsWidget.h"
#include "GlobalSignal.h"
#include "AdjustPositionWidget.h"
#include <QDebug>

//const int gnGoodsButtonCount = 30;

GoodsWidget::GoodsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoodsWidget)
  , m_nGoodsWidgetType( e_goodsSale )
  , m_pUpPageButton( NULL )
  , m_pDownPageButton( NULL )
  , m_nCurPage( 1 )
  , m_nTotalPage( 1 )
  , m_nOnePageCount( 25 )
  , m_bShowSubGoods( false )
  , m_sBarCode( "" )
{
    ui->setupUi(this);
//    setColumn( 25 );
    initConnect();
}

GoodsWidget::~GoodsWidget()
{
    delete ui;
}

void GoodsWidget::setGoodsWidgetType(int nGoodsWidgetType)
{
    m_nGoodsWidgetType = nGoodsWidgetType;

    for( int i = 0; i < m_goodsCellButtonList.size(); ++i ) {
        m_goodsCellButtonList[i]->setGoodsWidget( nGoodsWidgetType );
    }
}

void GoodsWidget::curPageChanged()
{
//    int nLen = m_goodsCellButtonList.count();
//    for( int i = 0; i < nLen; ++i ) {
//        if( m_goodsCellButtonList[i]->getGoodsId() == m_nGoodsId && m_nGoodsId > 0 ) {
//            m_goodsCellButtonList[i]->setSelectedSelf();
//        } else {
//            m_goodsCellButtonList[i]->setUnSelectedSelf();
//        }
//    }
}

//分类翻页
void GoodsWidget::setUpDownPageButton( QPushButton *pUpPageButton, QPushButton *pDownPageButton )
{
    m_pUpPageButton = pUpPageButton;
    m_pDownPageButton = pDownPageButton;
    connect( m_pUpPageButton, SIGNAL(clicked()), this, SLOT(slot_upPage()) );
    connect( m_pDownPageButton, SIGNAL(clicked()), this, SLOT(slot_downPage()) );
}

void GoodsWidget::setColumn(int nColumn , int nGoodsWidgetType)
{
    m_goodsCellButtonList.clear();
    m_nOnePageCount = nColumn;

    m_goodsCellButtonList.append(ui->cellButton_01);
    m_goodsCellButtonList.append(ui->cellButton_02);
    m_goodsCellButtonList.append(ui->cellButton_03);
    m_goodsCellButtonList.append(ui->cellButton_04);
    m_goodsCellButtonList.append(ui->cellButton_05);

    if( nColumn == 25 ) {
        m_goodsCellButtonList.append(ui->cellButton_07);
        m_goodsCellButtonList.append(ui->cellButton_08);
        m_goodsCellButtonList.append(ui->cellButton_09);
        m_goodsCellButtonList.append(ui->cellButton_10);
        m_goodsCellButtonList.append(ui->cellButton_11);
        m_goodsCellButtonList.append(ui->cellButton_13);
        m_goodsCellButtonList.append(ui->cellButton_14);
        m_goodsCellButtonList.append(ui->cellButton_15);
        m_goodsCellButtonList.append(ui->cellButton_16);
        m_goodsCellButtonList.append(ui->cellButton_17);
        m_goodsCellButtonList.append(ui->cellButton_19);
        m_goodsCellButtonList.append(ui->cellButton_20);
        m_goodsCellButtonList.append(ui->cellButton_21);
        m_goodsCellButtonList.append(ui->cellButton_22);
        m_goodsCellButtonList.append(ui->cellButton_23);
        m_goodsCellButtonList.append(ui->cellButton_25);
        m_goodsCellButtonList.append(ui->cellButton_26);
        m_goodsCellButtonList.append(ui->cellButton_27);
        m_goodsCellButtonList.append(ui->cellButton_28);
        m_goodsCellButtonList.append(ui->cellButton_29);

        ui->cellButton_06->hide();
        ui->cellButton_12->hide();
        ui->cellButton_18->hide();
        ui->cellButton_24->hide();
        ui->cellButton_30->hide();

        QList<GoodsCellButton *>::iterator it = m_goodsCellButtonList.begin();
        for( ; it != m_goodsCellButtonList.end(); ++it ) {
            (*it)->setFontSize( 12 );
        }

    } else {
        ui->cellButton_06->show();
        ui->cellButton_12->show();
        ui->cellButton_18->show();
        ui->cellButton_24->show();
        ui->cellButton_30->show();
        m_goodsCellButtonList.append(ui->cellButton_06);
        m_goodsCellButtonList.append(ui->cellButton_07);
        m_goodsCellButtonList.append(ui->cellButton_08);
        m_goodsCellButtonList.append(ui->cellButton_09);
        m_goodsCellButtonList.append(ui->cellButton_10);
        m_goodsCellButtonList.append(ui->cellButton_11);
        m_goodsCellButtonList.append(ui->cellButton_12);
        m_goodsCellButtonList.append(ui->cellButton_13);
        m_goodsCellButtonList.append(ui->cellButton_14);
        m_goodsCellButtonList.append(ui->cellButton_15);
        m_goodsCellButtonList.append(ui->cellButton_16);
        m_goodsCellButtonList.append(ui->cellButton_17);
        m_goodsCellButtonList.append(ui->cellButton_18);
        m_goodsCellButtonList.append(ui->cellButton_19);
        m_goodsCellButtonList.append(ui->cellButton_20);
        m_goodsCellButtonList.append(ui->cellButton_21);
        m_goodsCellButtonList.append(ui->cellButton_22);
        m_goodsCellButtonList.append(ui->cellButton_23);
        m_goodsCellButtonList.append(ui->cellButton_24);
        m_goodsCellButtonList.append(ui->cellButton_25);
        m_goodsCellButtonList.append(ui->cellButton_26);
        m_goodsCellButtonList.append(ui->cellButton_27);
        m_goodsCellButtonList.append(ui->cellButton_28);
        m_goodsCellButtonList.append(ui->cellButton_29);
        m_goodsCellButtonList.append(ui->cellButton_30);
    }

    setGoodsWidgetType(nGoodsWidgetType);

    //需要重新设置
}

void GoodsWidget::initGoodsInfoList(const QList<GoodsInfo> &listGoodsInfo, int nMovePosition)
{
    m_bShowSubGoods = false;
    clearText();   
    m_nCurPage = nMovePosition / m_nOnePageCount + ((nMovePosition % m_nOnePageCount == 0) ? 0 : 1);
    int nLen = listGoodsInfo.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
//    qDebug()<<"m_nCurPage:"<<m_nCurPage<<";m_nTotalPage:"<<m_nTotalPage;
    m_listGoodsInfo = listGoodsInfo;

    setCurPage(m_nCurPage, m_nTotalPage);
    generateGoodsList();
    int nSelectedPosition = nMovePosition % m_nOnePageCount;
    if (nSelectedPosition == 0)
    {
        nSelectedPosition = m_nOnePageCount;
    }
    m_goodsCellButtonList[nSelectedPosition - 1]->setSelectedSelf();
    curPageChanged();

    m_pDownPageButton->setEnabled( true );

}

void GoodsWidget::slot_addGoodsInfo( QList<GoodsInfo> listGoodsInfo )
{
    if( m_nGoodsWidgetType == e_goodsSet ) {
        initGoodsInfoList(listGoodsInfo, 1);
        return;
    }

//    if( listGoodsInfo.size() == 1 ) {
//        emit sig_addGoodsToSaleList( listGoodsInfo[0] );
//        return;
//    }

    //销售窗口
    clearText();

    m_bShowSubGoods = false;
    m_listGoodsInfo = listGoodsInfo;

    int n = 0;
    QList<GoodsInfo>::iterator it = m_listGoodsInfo.begin();
    for( ; it != m_listGoodsInfo.end(); ++it ) {
        ++n;
        if( n > m_nOnePageCount ) {
            continue;
        }

        QString strPrice = "";
        strPrice.sprintf( "￥%.2f/", it->fPrice );

        if( it->nPluGrade > 1 ) {
            m_goodsCellButtonList[n-1]->setGoodsInfo( it->sPluName, strPrice + it->sSaleUnit, it->sBarCode, it->nId, n);
        } else {
            QString strName = "";
            if( it->sShortName.isEmpty() ) {
                strName = it->sName;
            } else {
                strName = it->sShortName;
            }
            m_goodsCellButtonList[n-1]->setGoodsInfo( strName, strPrice + it->sSaleUnit, it->sBarCode, it->nId, n);
        }
        m_goodsCellButtonList[n-1]->setEnabled( it->bAllowSell );
    }

    m_pUpPageButton->setEnabled( false );
    if( n > m_nOnePageCount ) {
        m_pDownPageButton->setEnabled( true );
    } else {
        m_pDownPageButton->setEnabled( false );
    }

    m_nCurPage = 1;
    m_nTotalPage = n/m_nOnePageCount + ( (n%m_nOnePageCount)>0?1:0 );
    setCurPage( m_nCurPage, m_nTotalPage );

    update();
}

void GoodsWidget::slot_upPage()
{
    if (m_nCurPage > 1)
    {
        m_nCurPage--;
        setCurPage( m_nCurPage, m_nTotalPage );
    }
    if (m_nCurPage == 1 && m_pUpPageButton != NULL)
    {
        m_pUpPageButton->setEnabled(false);
    }
    if (m_pDownPageButton != NULL)
    {
        m_pDownPageButton->setEnabled(true);
    }

    generateGoodsList();
    curPageChanged();
}

void GoodsWidget::slot_downPage()
{
    int nLen = m_listGoodsInfo.length();
    if (m_nCurPage*m_nOnePageCount < nLen)
    {
        m_nCurPage++;
        setCurPage( m_nCurPage, m_nTotalPage );
    } else {
        m_pDownPageButton->setEnabled(false);
    }

    if (m_nCurPage >= m_nTotalPage && m_pDownPageButton != NULL)
    {
        m_pDownPageButton->setEnabled(false);
    }
    if (m_pUpPageButton != NULL)
    {
        m_pUpPageButton->setEnabled(true);
    }

    generateGoodsList();
    curPageChanged();
}

void GoodsWidget::init()
{
    m_goodsCellButtonList.append(ui->cellButton_01);
    m_goodsCellButtonList.append(ui->cellButton_02);
    m_goodsCellButtonList.append(ui->cellButton_03);
    m_goodsCellButtonList.append(ui->cellButton_04);
    m_goodsCellButtonList.append(ui->cellButton_05);
    m_goodsCellButtonList.append(ui->cellButton_06);
    m_goodsCellButtonList.append(ui->cellButton_07);
    m_goodsCellButtonList.append(ui->cellButton_08);
    m_goodsCellButtonList.append(ui->cellButton_09);
    m_goodsCellButtonList.append(ui->cellButton_10);
    m_goodsCellButtonList.append(ui->cellButton_11);
    m_goodsCellButtonList.append(ui->cellButton_12);
    m_goodsCellButtonList.append(ui->cellButton_13);
    m_goodsCellButtonList.append(ui->cellButton_14);
    m_goodsCellButtonList.append(ui->cellButton_15);
    m_goodsCellButtonList.append(ui->cellButton_16);
    m_goodsCellButtonList.append(ui->cellButton_17);
    m_goodsCellButtonList.append(ui->cellButton_18);
    m_goodsCellButtonList.append(ui->cellButton_19);
    m_goodsCellButtonList.append(ui->cellButton_20);
    m_goodsCellButtonList.append(ui->cellButton_21);
    m_goodsCellButtonList.append(ui->cellButton_22);
    m_goodsCellButtonList.append(ui->cellButton_23);
    m_goodsCellButtonList.append(ui->cellButton_24);
    m_goodsCellButtonList.append(ui->cellButton_25);
    m_goodsCellButtonList.append(ui->cellButton_26);
    m_goodsCellButtonList.append(ui->cellButton_27);
    m_goodsCellButtonList.append(ui->cellButton_28);
    m_goodsCellButtonList.append(ui->cellButton_29);
    m_goodsCellButtonList.append(ui->cellButton_30);

}

void GoodsWidget::initConnect()
{
    connect(GlobalSignal::instance(), SIGNAL(sigGoodsCellButtonClicked(QString,GoodsWidgetType))
            , this, SLOT(slot_goodsButtonClicked( QString, GoodsWidgetType)));
    connect(GlobalSignal::instance(), SIGNAL(sigGoodsCellMovePosition(int)), this, SLOT(slot_goodsCellMovePosition(int)));
}

void GoodsWidget::clearText()
{
    int nLen = m_goodsCellButtonList.length();
    for (int i = 0; i < nLen; i++)
    {
        m_goodsCellButtonList[i]->setGoodsInfo("", "", "", -1, -1);
    }
}

//重新生成商品列表
void GoodsWidget::generateGoodsList()
{
    clearText();
    int nStartPos = m_nOnePageCount * (m_nCurPage - 1);
    int nEndPos = m_nOnePageCount * m_nCurPage;
    int nLen = m_listGoodsInfo.length();
    for (int i = nStartPos; i < nEndPos && i < nLen; i++)
    {
        QString strPrice = "";
        strPrice.sprintf( "￥%.2f/", m_listGoodsInfo[i].fPrice );
        QString strName = "";
        if( m_listGoodsInfo[i].sShortName.isEmpty() ) {
            strName = m_listGoodsInfo[i].sName;
        } else {
            strName = m_listGoodsInfo[i].sShortName;
        }

        m_goodsCellButtonList[i-nStartPos]->setGoodsInfo(
                    strName, strPrice + m_listGoodsInfo[i].sSaleUnit
                    , m_listGoodsInfo[i].sBarCode, m_listGoodsInfo[i].nId, i + 1);

        m_goodsCellButtonList[i-nStartPos]->setEnabled( m_listGoodsInfo[i].bAllowSell );
    }
    update();
}

//值越小，口味级别越高
int GoodsWidget::getMaxTasteType( QString strGoodsCode )
{
    int nMaxTasteType = -1;
    QList<GoodsInfo>::iterator it = m_listGoodsInfo.begin();
    for( ; it != m_listGoodsInfo.end(); ++it ) {
        if( it->sCode == strGoodsCode ) {
            if( nMaxTasteType < 0 ) {
                nMaxTasteType = it->nTasteType;
                continue;
            }

            if( nMaxTasteType > it->nTasteType ) {
                nMaxTasteType = it->nTasteType;
            }
        }
    }

    return nMaxTasteType;
}

void GoodsWidget::updateGoodsInfo( QList<GoodsInfo> listGoodsInfo )
{
    clearText();

    int n = 0;
    QList<GoodsInfo>::iterator it = listGoodsInfo.begin();
    for( ; it != listGoodsInfo.end(); ++it ) {
        ++n;
        if( n > m_nOnePageCount ) {
            continue;
        }

        QString strPrice = "";
        strPrice.sprintf( "￥%.2f/", it->fPrice );
        m_goodsCellButtonList[n-1]->setGoodsInfo( it->sName, strPrice + it->sSaleUnit, it->sBarCode, it->nId, n);
        m_goodsCellButtonList[n-1]->setEnabled( it->bAllowSell );
    }

    m_pUpPageButton->setEnabled( false );
    if( listGoodsInfo.size() > m_nOnePageCount ) {
        m_pDownPageButton->setEnabled( true );
    } else {
        m_pDownPageButton->setEnabled( false );
    }

    m_nCurPage = 1;
    m_nTotalPage = n/m_nOnePageCount + ( (n%m_nOnePageCount)>0?1:0 );
    setCurPage( m_nCurPage, m_nTotalPage );

    update();
}

void GoodsWidget::updatePluGoodsInfo( QList<GoodsInfo> listPluGoodsInfo )
{
    clearText();

    int n = 0;
    QList<GoodsInfo>::iterator it = listPluGoodsInfo.begin();
    for( ; it != listPluGoodsInfo.end(); ++it ) {
        ++n;
        if( n > m_nOnePageCount ) {
            continue;
        }

        QString strPrice = "";
        strPrice.sprintf( "￥%.2f/", it->fPrice );
        m_goodsCellButtonList[n-1]->setGoodsInfo( it->sPluName, strPrice + it->sSaleUnit, it->sBarCode, it->nId, n);
        m_goodsCellButtonList[n-1]->setEnabled( it->bAllowSell );
    }

    m_pUpPageButton->setEnabled( false );
    if( listPluGoodsInfo.size() > m_nOnePageCount ) {
        m_pDownPageButton->setEnabled( true );
    } else {
        m_pDownPageButton->setEnabled( false );
    }

    m_nCurPage = 1;
    m_nTotalPage = n/m_nOnePageCount + ( (n%m_nOnePageCount)>0?1:0 );
    setCurPage( m_nCurPage, m_nTotalPage );

    update();
}

bool GoodsWidget::getGoodsAllTasteType( QString strGoodsCode, QList<GoodsInfo> &listGoodsTasteType )
{
    QList<GoodsInfo>::iterator it = m_listGoodsInfo.begin();
    for( ; it != m_listGoodsInfo.end(); ++it ) {
        if( it->sCode == strGoodsCode ) {
            listGoodsTasteType.append( *it );
        }
    }

    if( listGoodsTasteType.size() == 0 ) {
        return false;
    }

    return true;
}

void GoodsWidget::setCurPage( int nCurPage, int nTotalPage )
{
    if( !m_pDownPageButton ) return;
    if( !m_pUpPageButton ) return;

    if( nTotalPage <= 1 ) {
        nTotalPage = 1;
        m_pUpPageButton->setEnabled( false );
        m_pDownPageButton->setEnabled( false );
    }

    QString strNum = QString( "%1/%2页" ).arg( nCurPage ).arg( nTotalPage );
    m_pDownPageButton->setText( strNum );
}

void GoodsWidget::slot_goodsButtonClicked( QString strBarCode, GoodsWidgetType e_goodsWidget )
{
    m_sBarCode = strBarCode;
    if( m_nGoodsWidgetType != e_goodsWidget
            || m_nGoodsWidgetType == e_goodsSet)
    {

        return;
    }

    GoodsInfo st_goodsInfo;
    QList<GoodsInfo>::iterator it = m_listGoodsInfo.begin();
    for( ; it != m_listGoodsInfo.end(); ++it ) {
        if( it->sBarCode == strBarCode ) {
            st_goodsInfo = *it;
            break;
        }

        bool bHas = false;
        QList<GoodsInfo>::iterator itSub = it->goodsInfoList.begin();
        for( ; itSub != it->goodsInfoList.end(); ++itSub ) {
            if( itSub->sBarCode == strBarCode ) {
                st_goodsInfo = *itSub;
                bHas = true;
                break;
            }
        }
        if( bHas ) break;
    }

    if( /*st_goodsInfo.strCode.isEmpty() || */st_goodsInfo.nId < 0 ) {
        slot_addGoodsInfo( m_listGoodsInfo );
        return;
    }

    int nNum = st_goodsInfo.goodsInfoList.size();
    if( nNum == 0 || nNum == 1 ) {//表示没有子商品
        //1.如果商品没有口味，则判断商品类型
        emit sig_addGoodsToSaleList( st_goodsInfo );
        slot_addGoodsInfo( m_listGoodsInfo );
    } else {
        if( !m_bShowSubGoods ) {//如果没有显示为子商品，则显示子商品
            QList<GoodsInfo> listPluGoodsInfo = st_goodsInfo.goodsInfoList;

//            if( listGoodsPlu.size() <= 1 ) {
//                slot_addGoodsInfo( m_listGoodsInfo );

//                emit sig_addGoodsToSaleList( st_goodsInfo );
//            } else {
                updatePluGoodsInfo( listPluGoodsInfo );
                m_bShowSubGoods = true;
            //}
        } else {//如果显示子商品，则重新加载当前选中分类下的母商品信息，并更新销售列表信息
            slot_addGoodsInfo( m_listGoodsInfo );

            emit sig_addGoodsToSaleList( st_goodsInfo );
        }
    }
}

void GoodsWidget::slot_goodsCellMovePosition(int nPosition)
{
    AdjustPositionWidget *pInstance = AdjustPositionWidget::instance();
    int nAdjustWidgetWidth = pInstance->width();
    const int nArrowHeight = 9;
    QPoint globalPoint = this->mapToGlobal(QPoint(0, 0));
    int nXPos = globalPoint.x() - (nAdjustWidgetWidth - this->width())/2;
    int nYPos = globalPoint.y() - nArrowHeight;
    pInstance->setPosition(nPosition);
    pInstance->setOwnerType(e_goodsSet);
    pInstance->move(nXPos, nYPos);
    pInstance->activateWindow();
    pInstance->showNormal();
}
