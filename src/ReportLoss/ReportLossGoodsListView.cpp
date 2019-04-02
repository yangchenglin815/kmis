#include "ReportLossGoodsListView.h"
#include "../data/constData.h"
#include <QPainter>
#include <QMouseEvent>

enum ReportLossGoodsItemType
{
    e_reportLossGoodsInfo = Qt::UserRole + 1,
};

ReportLossGoodsDelegate::ReportLossGoodsDelegate(QObject *parent)
 : QStyledItemDelegate(parent)
{

}

void ReportLossGoodsDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();

    QVariant vItemInfo = index.data(e_reportLossGoodsInfo);
    if(vItemInfo.canConvert<GoodsInfo>())
    {
        GoodsInfo goodsInfo = vItemInfo.value<GoodsInfo>();
        if((option.state & QStyle::State_MouseOver) && (goodsInfo.nId > 0))
        {
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/goods_btn_press.png").scaled(option.rect.size()));
        }
        else
        {
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/goods_btn_normal.png").scaled(option.rect.size()));
        }

        if (goodsInfo.nId > 0)
        {
            paintContent(painter, option, goodsInfo);
        }
    }

    painter->restore();
}

void ReportLossGoodsDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, GoodsInfo &goodsInfo) const
{
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();
    int nXPos = option.rect.x();
    int nYPos = option.rect.y();

    int nFontSize = 12 * g_widthRate;
    QFont font;
    font.setPixelSize(nFontSize);
    font.setFamily("微软雅黑");
    font.setBold(true);
    painter->setFont(font);
    QPen pen;
    pen.setColor("#333333");
    painter->setPen(pen);

    const int nLeftSpace = 4;
    const int nTopSpace = 4;
    const int nContentRowSpace = 4;

    int nStartXPos = nXPos + nLeftSpace;
    int nStartYPos = nYPos + nTopSpace;

    QString strName = "";
    if( goodsInfo.sShortName.isEmpty() ) {
        strName = goodsInfo.sName;
    } else {
        strName = goodsInfo.sShortName;
    }

    QString sFirstRowContent = painter->fontMetrics().elidedText( strName, Qt::ElideLeft, nWidth - 2*nLeftSpace);
    sFirstRowContent = strName.left(sFirstRowContent.length());
    QRect firstRowRect(nStartXPos, nStartYPos, nWidth, nFontSize);
    painter->drawText(firstRowRect, Qt::AlignLeft | Qt::AlignVCenter, sFirstRowContent);

    int nRemainLen = strName.length()-sFirstRowContent.length();
    if (nRemainLen > 0)
    {
        nStartYPos += (nFontSize + nContentRowSpace);
        QString sRightContent = strName.right(nRemainLen);
        QString sSecondRowContent = painter->fontMetrics().elidedText(sRightContent, Qt::ElideLeft, nWidth-2*nLeftSpace);
        sSecondRowContent = sRightContent.left(sSecondRowContent.length());
        QRect secondRowRect(nStartXPos, nStartYPos, nWidth, nFontSize);
        painter->drawText(secondRowRect, Qt::AlignLeft | Qt::AlignVCenter, sSecondRowContent);
        nRemainLen = sRightContent.length() - sSecondRowContent.length();
        if (nRemainLen > 0)
        {
            nStartYPos += (nFontSize + nContentRowSpace);
            sRightContent = sRightContent.right(nRemainLen);
            QRect thirdRowRect(nStartXPos, nStartYPos, nWidth, nFontSize);
            painter->drawText(thirdRowRect, Qt::AlignLeft | Qt::AlignVCenter, sRightContent);
        }
    }

    // 绘制商品价格
    const int nPriceFontSize = 12 * g_widthRate;
    font.setPixelSize(nPriceFontSize);
    font.setBold(false);
    painter->setFont(font);
    QString sPriceText = QString("￥%1/%2").arg(QString::number(goodsInfo.fPrice, 'f', 2)).arg(goodsInfo.sSaleUnit);
    int nBottomSpace = 4;
    int nPriceYPos = nYPos + nHeight - nBottomSpace - nPriceFontSize;
    QRect goodsPriceRect(nXPos, nPriceYPos, nWidth - nLeftSpace, nPriceFontSize);
    painter->drawText(goodsPriceRect, Qt::AlignRight | Qt::AlignVCenter, sPriceText);
}

ReportLossGoodsListView::ReportLossGoodsListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(70)
    , m_nItemWidth(82)
{
   init();
}

void ReportLossGoodsListView::appendItem(const GoodsInfo &goodsInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(goodsInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(goodsInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(m_nItemWidth, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(goodsInfo.nId);
    }
    QVariant variant;
    variant.setValue(goodsInfo);
    pItem->setData(variant, e_reportLossGoodsInfo);
}

void ReportLossGoodsListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void ReportLossGoodsListView::setWidth(int width)
{
    m_nItemWidth = width;
}

void ReportLossGoodsListView::setHeight(int height)
{
    m_nItemHeight = height;
}

void ReportLossGoodsListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());
    GoodsInfo goodsInfo;
    QVariant v_itemInfo = index.data(e_reportLossGoodsInfo);
    if (v_itemInfo.canConvert<GoodsInfo>())//可以转换
    {
        goodsInfo = v_itemInfo.value<GoodsInfo>();
        if (goodsInfo.nId > 0)
        {
            emit sigClickItem(goodsInfo);
        }
    }
}

void ReportLossGoodsListView::init()
{
    setViewMode(IconMode);
    setMovement(Static);
    setSpacing(0);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new ReportLossGoodsDelegate(this));//设置图元代理forColumn
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode(SingleSelection);//单选
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
