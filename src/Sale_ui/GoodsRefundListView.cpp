#include "GoodsRefundListView.h"
#include "../data/constData.h"
#include <QPainter>
#include <QMouseEvent>

static int nPromotionStartXPos = -1;
static int nPromotionEndXPos = -1;

enum GoodsRefundItemType
{
    e_goodsRefundInfo = Qt::UserRole + 1,
};

GoodsRefundDelegate::GoodsRefundDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void GoodsRefundDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_goodsRefundInfo);
    if (v_itemInfo.canConvert<GoodsDetailInfo>())
    {
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)//用来判断option.state中是否有选中状态
        {
            bSelected = true;
            QRect rect = option.rect;
            rect.setX(rect.x() + 1);
            rect.setWidth(rect.width() - 2);
            painter->fillRect(rect, QBrush(QColor(c_sThemeColor)));
        }
        GoodsDetailInfo goodsInfo = v_itemInfo.value<GoodsDetailInfo>();
        paintGoodsInfo(painter, option, goodsInfo, bSelected);
    }
    painter->restore();
}

void GoodsRefundDelegate::paintGoodsInfo(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo &rInfo, bool bSelected) const
{
    paintSequenceCol(painter, option, rInfo, bSelected);
    paintGoodsNameCol(painter, option, rInfo, bSelected);
    paintGoodsPriceCol(painter, option, rInfo, bSelected);
    paintLine(painter, option);
}

void GoodsRefundDelegate::paintSequenceCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo &rInfo, bool bSelected) const
{
    static const int c_nSequenceColWidth = 33*g_widthRate;
    int nFontSize = 12*g_widthRate;

    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nHeight = option.rect.height();

    if (bSelected && rInfo.bPromotion)
    {
        QPixmap promotionPixmap(":/saleImage/cuBig.png");
        promotionPixmap = promotionPixmap.scaled(c_nSequenceColWidth, nHeight);
        QRect promotionRect(xPos, yPos, c_nSequenceColWidth, nHeight);
        painter->drawPixmap(promotionRect, promotionPixmap);
        nPromotionStartXPos = xPos;
        nPromotionEndXPos = xPos + c_nSequenceColWidth;
    }
    else
    {
        QFont font;
        font.setPixelSize(nFontSize);
        painter->setFont(font);
        QPen pen;
        pen.setColor(bSelected ? "#ffffff" : "#333333");
        painter->setPen(pen);
        QString text = QString::number(rInfo.nPos);
        QRect textRec(xPos, yPos, c_nSequenceColWidth, nHeight);
        painter->drawText(textRec, Qt::AlignHCenter | Qt::AlignVCenter, text);
    }
}

void GoodsRefundDelegate::paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo &rInfo, bool bSelected) const
{
    int nFontSize = 12*g_widthRate;

    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int startXPos = xPos + 38*g_widthRate;
    int startYPos = yPos + 4*g_widthRate;
    QFont font;
    font.setPixelSize(nFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected ? "#ffffff" : "#333333");
    painter->setPen(pen);
    QString strName = rInfo.strGoodsShortName;
    if(strName.isEmpty())
    {
        strName = rInfo.sGoodsName;
    }
    int goodsNameWidth = painter->fontMetrics().width( strName );
    int goodsHeight = 14*g_widthRate;
    QRect goodsNameRect(startXPos, startYPos, goodsNameWidth, goodsHeight);
    painter->drawText(goodsNameRect, Qt::AlignCenter, strName );
    pen.setColor(bSelected ? "#ffffff" : "#999999");
    painter->setPen(pen);
    QString sShowUnit = QString("( %1 )").arg(rInfo.sUnit);
    int goodsUnitWidth = painter->fontMetrics().width(sShowUnit);
    startXPos += goodsNameWidth + 2;
    startYPos += 0;
    QRect goodsUnitRect(startXPos, startYPos, goodsUnitWidth, goodsHeight);
    painter->drawText(goodsUnitRect, Qt::AlignCenter, sShowUnit);
    startXPos += goodsUnitWidth + 4;
    startYPos += 0;

    QPixmap promotionPixmap((bSelected || !rInfo.bPromotion) ? "" : ":/saleImage/cu.png");
    QRect promotionRect(startXPos, startYPos, 13 *g_widthRate, 14 *g_widthRate);
    painter->drawPixmap(promotionRect, promotionPixmap);
    startXPos += (((bSelected || !rInfo.bPromotion) ? 0 : (13 + 2)));


    QPixmap discountPixmap(rInfo.bDisCount? ":/saleImage/discount.png" : "");
    QRect discountRect(startXPos, startYPos, 13 *g_widthRate, 14*g_widthRate);
    painter->drawPixmap(discountRect, discountPixmap);

    QPixmap refundPixmap((-rInfo.fHaveRefundNum > 0.000001) ? ":/saleImage/refundFlag.png" : "");
    QRect refundRect(xPos + 38*g_widthRate, startYPos + 24*g_widthRate, 22*g_widthRate, 13*g_widthRate);
    painter->drawPixmap(refundRect, refundPixmap);

    QString sRefundNum = "";
    if (-rInfo.fHaveRefundNum > 0.000001)
    {
        sRefundNum = QString::number(-rInfo.fHaveRefundNum, 'f', 3);
    }
    QRect refundNumRect(xPos + 38*g_widthRate + 22*g_widthRate + 2, startYPos + 24*g_widthRate, option.rect.width(), 14*g_widthRate);
    painter->drawText(refundNumRect, Qt::AlignLeft || Qt::AlignVCenter, sRefundNum);
}

void GoodsRefundDelegate::paintGoodsPriceCol(QPainter *painter, const QStyleOptionViewItem &option, const GoodsDetailInfo &rInfo, bool bSelected) const
{
    int nFontSize = 12*g_widthRate;

    QFont font;
    font.setPixelSize(nFontSize);
    painter->setFont(font);

    QPen pen;
    pen.setColor(bSelected ? "#ffffff" : "#333333");
    painter->setPen(pen);
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    xPos += 0;
    yPos += 24 *g_widthRate;

    float new_widthRate =(g_widthRate*0.6 + 0.4);
    static const int nPriceColWidth = 140 * new_widthRate;
    static const int nSignWidth = 28 *new_widthRate;
    static const int nGoodsNumWidth = 49 *new_widthRate;
    static const int nGoodsSumPriceWidth = 64 *new_widthRate;
    static const int nColHeight = 12 *new_widthRate;
    QString sPrice = "";
    QString sNumber = "";
    if (!rInfo.sSumPrice.isEmpty())
    {
        // 原价格
        QRect numberTextRec1(xPos, yPos, nPriceColWidth, nColHeight);
        sPrice = QString::number(rInfo.fRefundPrice, 'f', 2);
        painter->drawText(numberTextRec1, Qt::AlignRight | Qt::AlignVCenter, sPrice);
        // 原乘号
        xPos += nPriceColWidth;
        QRect numberTextRec2(xPos, yPos, nSignWidth, nColHeight);
        painter->drawText(numberTextRec2, Qt::AlignCenter, QStringLiteral("x"));
        // 原数量
        xPos += nSignWidth;
        QRect numberTextRec3(xPos, yPos, nGoodsNumWidth, nColHeight);
        QString sNumber = QString::number(rInfo.fNumber, 'f', 3);
        painter->drawText(numberTextRec3, Qt::AlignCenter | Qt::AlignVCenter, sNumber);
        // 原总价
        xPos += nGoodsNumWidth;
        QRect numberTextRec4(xPos, yPos, nGoodsSumPriceWidth, nColHeight);
        painter->drawText(numberTextRec4, Qt::AlignRight | Qt::AlignVCenter, QString("￥%1").arg(rInfo.sSumPrice));
    }

    // -------
    if (!rInfo.sRefundSumPrice.isEmpty())
    {
        pen.setColor(bSelected ? "#ffffff" : "#ea8852");
        painter->setPen(pen);
        xPos = option.rect.x();
        yPos += (2 + nFontSize);
        // 现价格
        QRect numberTextRec21(xPos, yPos, nPriceColWidth, nColHeight);
        sPrice = QString::number(rInfo.fRefundPrice, 'f', 2);
        painter->drawText(numberTextRec21, Qt::AlignRight | Qt::AlignVCenter, sPrice);

        // 现乘号
        xPos += nPriceColWidth;
        QRect numberTextRec22(xPos, yPos, nSignWidth, nColHeight);
        painter->drawText(numberTextRec22, Qt::AlignCenter, QStringLiteral("x"));

        // 现数量
        xPos += nSignWidth;
        QRect numberTextRec23(xPos, yPos, nGoodsNumWidth, nColHeight);
        sNumber = QString::number(rInfo.fRefundNumber, 'f', 3);
        painter->drawText(numberTextRec23, Qt::AlignCenter | Qt::AlignVCenter, sNumber);

        // 现总价
        xPos += nGoodsNumWidth;
        QRect numberTextRec24(xPos, yPos, nGoodsSumPriceWidth, nColHeight);
        painter->drawText(numberTextRec24, Qt::AlignRight | Qt::AlignVCenter, QString("￥%1").arg(rInfo.sRefundSumPrice));
    }
}

void GoodsRefundDelegate::paintLine(QPainter *painter, const QStyleOptionViewItem &option) const
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

GoodsRefundListView::GoodsRefundListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(54*g_widthRate)
{
    init();
}

void GoodsRefundListView::appendItem(const GoodsDetailInfo &rInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;

    if (m_ItemKeyIdMap.contains(rInfo.nSaleDetailPos) )// 更新
    {
        pItem = m_ItemKeyIdMap.value(rInfo.nSaleDetailPos);
    }
    else // 添加
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(rInfo.nSaleDetailPos, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }

    QVariant variant;
    variant.setValue(rInfo);
    pItem->setData(variant, e_goodsRefundInfo);

    if (m_selectIdList.contains(rInfo.nSaleDetailPos))
    {
        this->setCurrentIndex(pItem->index());
    }
}

void GoodsRefundListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

QList<int> GoodsRefundListView::getSelectIdList()
{
    return m_selectIdList;
}

void GoodsRefundListView::clearSelectIdList()
{
    m_selectIdList.clear();
}

void GoodsRefundListView::mousePressEvent(QMouseEvent *event)
{
    QModelIndex index = indexAt(event->pos());
    GoodsDetailInfo goodsInfo;
    QVariant v_itemInfo = index.data(e_goodsRefundInfo);
    if ( v_itemInfo.canConvert<GoodsDetailInfo>() )//可以转换
    {
        int nXPos = event->x();
        goodsInfo = v_itemInfo.value<GoodsDetailInfo>();
        if(goodsInfo.bPromotion && (nXPos >= nPromotionStartXPos) && (nXPos <= nPromotionEndXPos))
        {
//            emit sig_showPromotionDlg();
        }
        else
        {
            if (m_selectIdList.contains(goodsInfo.nSaleDetailPos))
            {
                m_selectIdList.removeAll(goodsInfo.nSaleDetailPos);
            }
            else
            {
                m_selectIdList.append(goodsInfo.nSaleDetailPos);
            }

            emit sigClickItem();
        }
    }
    QListView::mousePressEvent(event);
}

void GoodsRefundListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new GoodsRefundDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode(MultiSelection);
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



