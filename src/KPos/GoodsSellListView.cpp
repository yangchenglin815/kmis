#include "GoodsSellListView.h"
#include <QDebug>
#include "../data/constData.h"

enum GoodsSellItemROLE
{
    e_GoodsSellItemInfo = Qt::UserRole + 1,
    e_GoodsSellListTitle
};

static const int c_nGoodsSellItemHeight = 54;
static const int c_nSequenceColWidth = 33;
static const int c_nSequenceGoodsNameSpace = 9;
static const int c_nGoodsNameColWidth = 112;

static const int c_nGoodsNameTextSize = 13;
static const int c_nGoodsUnit = 10;
static const int c_nNumberSize = 14;

int gnPixSize = 12;

static int nPromotionStartXPos = -1;
static int nPromotionEndXPos = -1;

GoodsSellDelegate::GoodsSellDelegate()
{

}

void GoodsSellDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_GoodsSellItemInfo);
    if (v_itemInfo.canConvert<GoodsDetailInfo>())
    {
        bool bSelected = false;
        GoodsDetailInfo goodsInfo = v_itemInfo.value<GoodsDetailInfo>();

        if ( goodsInfo.bSelectStatus )//用来判断option.state中是否有选中状态
        {
            bSelected = true;
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/rect.png"));            
        }
        else
        {
            bSelected = false;
        }
        paintGoodsInfo(painter, option, goodsInfo, bSelected);
    }

    painter->restore();
}

void GoodsSellDelegate::paintGoodsInfo(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo &rInfo, bool bSelected) const
{
    paintSequenceCol(painter, option, rInfo, bSelected);
    paintGoodsNameCol(painter, option, rInfo, bSelected);
    paintGoodsPriceCol(painter, option, rInfo, bSelected);
    paintLine(painter, option);
}

void GoodsSellDelegate::paintSequenceCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo &rInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    if (bSelected && rInfo.bPromotion)
    {
        QPixmap promotionPixmap(":/saleImage/cuBig.png");
        promotionPixmap = promotionPixmap.scaled(c_nSequenceColWidth, c_nGoodsSellItemHeight  * g_heightRate);
        QRect promotionRect(xPos, yPos, c_nSequenceColWidth, c_nGoodsSellItemHeight  * g_heightRate);
        painter->drawPixmap(promotionRect, promotionPixmap);
        nPromotionStartXPos = xPos;
        nPromotionEndXPos = xPos + c_nSequenceColWidth;
    }
    else
    {
        QFont font;
        font.setPixelSize( gnPixSize * g_heightRate);
        painter->setFont(font);
        QPen pen;
        pen.setColor(bSelected ? "#ffffff" : "#333333");
        painter->setPen(pen);
        QString text = QString::number(rInfo.nPos);
        QRect textRec(xPos, yPos, c_nSequenceColWidth, c_nGoodsSellItemHeight * g_heightRate);
        painter->drawText(textRec, Qt::AlignHCenter | Qt::AlignVCenter, text);
    }
}

void GoodsSellDelegate::paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo &rInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int startXPos = xPos + 38 * g_heightRate;
    int startYPos = yPos + 12 * g_heightRate;
    QFont font;
    font.setPixelSize( gnPixSize * g_heightRate);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected ? "#ffffff" : "#333333");
    painter->setPen(pen);
    QString strName = rInfo.strGoodsShortName;
    if (strName.isEmpty())
    {
        strName = rInfo.sGoodsName;
    }
    int goodsNameWidth = painter->fontMetrics().width( strName );
    int goodsHeight = 14 * g_heightRate;
    QRect goodsNameRect(startXPos, startYPos, goodsNameWidth, goodsHeight);
    painter->drawText(goodsNameRect, Qt::AlignCenter, strName );
    pen.setColor(bSelected ? "#ffffff" : "#999999");
    painter->setPen(pen);
    QString sShowUnit = QString("( %1 )").arg(rInfo.sUnit);
    int goodsUnitWidth = painter->fontMetrics().width(sShowUnit);
    startXPos += goodsNameWidth + 2 * g_heightRate;
    startYPos += 0;
    QRect goodsUnitRect(startXPos, startYPos, goodsUnitWidth, goodsHeight);
    painter->drawText(goodsUnitRect, Qt::AlignCenter, sShowUnit);
    startXPos += goodsUnitWidth + 4 * g_heightRate;
    startYPos += 0;

    QPixmap promotionPixmap((bSelected || !rInfo.bPromotion) ? "" : ":/saleImage/cu.png");
    QRect promotionRect(startXPos, startYPos, 13 * g_heightRate, 14 * g_heightRate);
    painter->drawPixmap(promotionRect, promotionPixmap);
    startXPos += (((bSelected || !rInfo.bPromotion) ? 0 : (13 + 2)));


    QPixmap discountPixmap((!rInfo.bDisCount)? "" : ":/saleImage/discount.png");
    QRect discountRect(startXPos, startYPos, 13 * g_heightRate, 14 * g_heightRate);
    painter->drawPixmap(discountRect, discountPixmap);
}

void GoodsSellDelegate::paintGoodsPriceCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo &rInfo, bool bSelected) const
{
    QFont font;
    font.setPixelSize( gnPixSize * g_heightRate);
    painter->setFont(font);

    QPen pen;
    pen.setColor(bSelected ? "#ffffff" : "#333333");
    painter->setPen(pen);
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    xPos += 0;
    yPos += 32* g_heightRate;
    // 价格
    static const int nPriceColWidth = 140 * g_heightRate;
    static const int nColHeight = 12 * g_heightRate;
    QRect numberTextRec1(xPos, yPos, nPriceColWidth, nColHeight);
    QString sPrice = "";
    sPrice.sprintf("%.2f", rInfo.fPrice);
    painter->drawText(numberTextRec1, Qt::AlignRight | Qt::AlignVCenter, sPrice);

    // 乘号
    xPos += nPriceColWidth;
    static const int nSignWidth = 28 * g_heightRate;
    QRect numberTextRec2(xPos, yPos, nSignWidth, nColHeight);
    painter->drawText(numberTextRec2, Qt::AlignCenter, QStringLiteral("x"));

    // 数量
    xPos += nSignWidth;
    static const int nGoodsNumWidth = 49 * g_heightRate;
    QRect numberTextRec3(xPos, yPos, nGoodsNumWidth, nColHeight);
    QString sNumber = "";
    sNumber.sprintf("%.3f", rInfo.fNumber);
    painter->drawText(numberTextRec3, Qt::AlignCenter | Qt::AlignVCenter, sNumber);

    // 总价
    xPos += nGoodsNumWidth;
    static const int nGoodsSumPriceWidth = 64 * g_heightRate;
    QRect numberTextRec4(xPos, yPos, nGoodsSumPriceWidth, nColHeight);
    painter->drawText(numberTextRec4, Qt::AlignRight | Qt::AlignVCenter, QString("￥%1").arg(rInfo.sSumPrice));
}

//退款
void GoodsSellDelegate::paintRefundGoodsPriceCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo &rInfo, bool bSelected) const
{
    QFont font;
    font.setPixelSize( gnPixSize );
    painter->setFont(font);

    QPen pen;
    if (bSelected)
    {
        pen.setColor("#ffffff");
    }
    else
    {
        QPen pen;
        pen.setColor("#333333");
    }
    painter->setPen(pen);
    static const int nStartPos = 200;
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    xPos += nStartPos;
    int nTopMargin = 10;
    int nFirstStartYPos = yPos + nTopMargin;
    int nTextHeight = 12;
    // 第一行
    // 价格
    static const int nPriceColWidth = 48;
    QRect numberTextRec11(xPos, nFirstStartYPos, nPriceColWidth, nTextHeight);
    QString sPrice = "";
    sPrice.sprintf("%.2f", rInfo.fPrice);
    painter->drawText(numberTextRec11, Qt::AlignRight | Qt::AlignVCenter, sPrice);
    // 乘号
    xPos += nPriceColWidth;
    static const int nSignWidth = 25;
    QRect numberTextRec12(xPos, nFirstStartYPos, nSignWidth, nTextHeight);
    painter->drawText(numberTextRec12, Qt::AlignHCenter | Qt::AlignVCenter, QStringLiteral("x"));
    // 数量
    xPos += nSignWidth;
    static const int nGoodsNumWidth = 58;
    QRect numberTextRec13(xPos, nFirstStartYPos, nGoodsNumWidth, nTextHeight);
    QString sNumber = "";
    sNumber.sprintf("%.3f", rInfo.fNumber);
    painter->drawText(numberTextRec13, Qt::AlignLeft | Qt::AlignVCenter, sNumber);
    // 总价
    xPos += nGoodsNumWidth;
    static const int nGoodsSumPriceWidth = 60;
    QRect numberTextRec14(xPos, nFirstStartYPos, nGoodsSumPriceWidth, nTextHeight);
    painter->drawText(numberTextRec14, Qt::AlignLeft | Qt::AlignVCenter, rInfo.sSumPrice);

    // 第二行
    QPen pen2;
    pen2.setColor("#fa7a7a");
    painter->setPen(pen2);

    // 价格
    xPos = option.rect.x();
    yPos = option.rect.y();
    xPos += nStartPos;
    static const int nTwoTextSpace = 10;
    int nSecondStartYPos = yPos + nTopMargin + nTextHeight + nTwoTextSpace;
    QRect numberTextRec21(xPos, nSecondStartYPos, nPriceColWidth, nTextHeight);
    painter->drawText(numberTextRec21, Qt::AlignRight | Qt::AlignVCenter, QString("").sprintf("%.2f", rInfo.fPrice));

    // 乘号
    xPos += nPriceColWidth;
    QRect numberTextRec22(xPos, nSecondStartYPos, nSignWidth, nTextHeight);
    painter->drawText(numberTextRec22, Qt::AlignHCenter | Qt::AlignVCenter, QStringLiteral("x"));

    // 数量
    xPos += nSignWidth;
    QRect numberTextRec23(xPos, nSecondStartYPos, nGoodsNumWidth, nTextHeight);
    painter->drawText(numberTextRec23, Qt::AlignHCenter | Qt::AlignVCenter, QString("").sprintf("%.3f", rInfo.fNumber));

    // 总价
    xPos += nGoodsNumWidth;
    QRect numberTextRec24(xPos, nSecondStartYPos, nGoodsSumPriceWidth, nTextHeight);
    painter->drawText(numberTextRec24, Qt::AlignLeft | Qt::AlignVCenter, rInfo.sSumPrice);
}

void GoodsSellDelegate::paintLine(QPainter *painter, const QStyleOptionViewItem &option) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();
    QPen pen;
    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

GoodsSellListView::GoodsSellListView(QWidget *parent)
    : QListView(parent)
    , m_bSelect( true )
{
    init();
}

GoodsSellListView::~GoodsSellListView()
{

}

void GoodsSellListView::appendItem(const GoodsDetailInfo &rInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;

    if (m_mapItemKeyId.contains(rInfo.nSaleDetailPos) )// 更新
    {
        pItem = m_mapItemKeyId.value(rInfo.nSaleDetailPos);
    }
    else // 添加
    {
        pItem = new QStandardItem;
        m_mapItemKeyId.insert(rInfo.nSaleDetailPos, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, c_nGoodsSellItemHeight * g_heightRate));
    }

    QVariant variant;
    variant.setValue(rInfo);
    pItem->setData(variant, e_GoodsSellItemInfo);
}

void GoodsSellListView::deleteSelectGoods( const int nSaleDetailPos )
{
    if( !m_mapItemKeyId.contains(nSaleDetailPos) ) return;

    QStandardItem *pItem = m_mapItemKeyId.value( nSaleDetailPos );
    int nRow = pItem->row();
    if( pItem == NULL || nRow < 0 ) return;

    m_pStandardItemModel->removeRow( nRow );
    m_mapItemKeyId.remove( nSaleDetailPos );
}

void GoodsSellListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_mapItemKeyId.clear();
}

void GoodsSellListView::mousePressEvent( QMouseEvent *event )
{
    if( !m_bSelect ) return;

    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    GoodsDetailInfo goodsInfo;
    QVariant v_itemInfo = index.data(e_GoodsSellItemInfo);
    if ( v_itemInfo.canConvert<GoodsDetailInfo>() )//可以转换
    {
        goodsInfo = v_itemInfo.value<GoodsDetailInfo>();
    } else {
        return;
    }

    if( goodsInfo.bPromotion && nPromotionStartXPos !=-1&& event->x() >= nPromotionStartXPos && event->x() <= nPromotionEndXPos ) {
        emit sig_showPromotionDlg();
    } else {
        emit sig_selectGoods( goodsInfo );
    }

//    qDebug()<<"GoodsSellListView::mousePressEvent"<<nPromotionStartXPos<<nPromotionEndXPos;

    QListView::mousePressEvent( event );
}

void GoodsSellListView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if( !m_bSelect ) return;

    GoodsSellListView::mousePressEvent( event );
    QListView::mouseDoubleClickEvent(event);

    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    GoodsDetailInfo goodsInfo;
    QVariant v_itemInfo = index.data(e_GoodsSellItemInfo);
    if ( v_itemInfo.canConvert<GoodsDetailInfo>() )//可以转换
    {
        goodsInfo = v_itemInfo.value<GoodsDetailInfo>();
    } else {
        return;
    }

    if( goodsInfo.bPromotion && nPromotionStartXPos !=-1&& event->x() >= nPromotionStartXPos && event->x() <= nPromotionEndXPos ) {
        emit sig_showPromotionDlg();
    } else {
        emit sig_doubleClickItem(goodsInfo);
    }
}

int GoodsSellListView::getRows()
{
    return m_pStandardItemModel->rowCount();
}

void GoodsSellListView::setSelectStatus( bool bSelect )
{
    m_bSelect = bSelect;
}

bool GoodsSellListView::isGoods( const GoodsDetailInfo &st_goodsInfo )
{
    QMap<int, QStandardItem*>::iterator it = m_mapItemKeyId.begin();
    for( ; it != m_mapItemKeyId.end(); ++it ) {
        GoodsDetailInfo goodsInfo = it.value()->data( e_GoodsSellItemInfo ).value<GoodsDetailInfo>();
        if( goodsInfo.nSaleDetailPos == st_goodsInfo.nSaleDetailPos ) {
            return true;
        }
    }

    return false;
}

bool GoodsSellListView::findItem( int nRow, GoodsDetailInfo &rInfo )
{
    if( m_pStandardItemModel->item( nRow ) ) {
        QVariant variant = m_pStandardItemModel->item( nRow )->data( e_GoodsSellItemInfo );
        if ( variant.canConvert<GoodsDetailInfo>() )//variant能够转换成GoodsInfo
        {
            rInfo = variant.value<GoodsDetailInfo>();
            return true;
        }
    }

    return false;
}

bool GoodsSellListView::isNoSelectGoods( GoodsDetailInfo &rInfo )
{
    int nRow = m_pStandardItemModel->rowCount();
    for( int i = 0; i < nRow; ++i ) {
        if( !m_pStandardItemModel->item( i ) ) continue;

        QVariant variant = m_pStandardItemModel->item( i )->data( e_GoodsSellItemInfo );
        if ( !variant.canConvert<GoodsDetailInfo>() ) continue;//variant能够转换成GoodsInfo

        rInfo = variant.value<GoodsDetailInfo>();
        if( !rInfo.bSelectStatus ) {
            return true;
        }
    }

    return false;
}

void GoodsSellListView::cancelAllSelectGoods()
{
    int nRow = m_pStandardItemModel->rowCount();
    for( int i = 0; i < nRow; ++i ) {
        if( !m_pStandardItemModel->item( i ) ) continue;

        QVariant variant = m_pStandardItemModel->item( i )->data( e_GoodsSellItemInfo );
        if ( !variant.canConvert<GoodsDetailInfo>() ) continue;//variant能够转换成GoodsInfo

        GoodsDetailInfo rInfo = variant.value<GoodsDetailInfo>();
        if( rInfo.bSelectStatus ) {
            rInfo.bSelectStatus = false;
            appendItem( rInfo );
        }
    }
}

void GoodsSellListView::setPixSize( int nPixSize )
{
    gnPixSize = nPixSize;
}

void GoodsSellListView::init()
{
    setItemDelegateForColumn(0, new GoodsSellDelegate);
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode(MultiSelection);
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


