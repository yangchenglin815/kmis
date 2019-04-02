#include "StockOrderSearchListView.h"
#include "../data/constData.h"
#include <QMouseEvent>
#include <QPainter>

enum StockOrderSearchItemType
{
    e_StockOrderSearchInfo = Qt::UserRole + 1,
};

StockOrderSearchDelegate::StockOrderSearchDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void StockOrderSearchDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_StockOrderSearchInfo);
    if (v_itemInfo.canConvert<StockOrderSearchInfo>())
    {
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
            QRect rect = option.rect;
            rect.setX(rect.x() + 1);
            rect.setWidth(rect.width() - 2);
            painter->fillRect(rect, QBrush(QColor(c_sThemeColor)));
        }
        StockOrderSearchInfo stockOrderSearchInfo = v_itemInfo.value<StockOrderSearchInfo>();
        paintContent(painter, option, stockOrderSearchInfo, bSelected);
    }

    painter->restore();
}

void StockOrderSearchDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const StockOrderSearchInfo &searchInfo, bool bSelected) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    const int nfontSize = 14*g_heightRate;
    const int nfontSize2 = 12*g_heightRate;
    QFont font;
    font.setPixelSize(nfontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setPen(pen);

    // 序号
    const int nLeftSpace = 22*g_heightRate;
    const int nFirstWidth = 42*g_heightRate;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect, Qt::AlignLeft | Qt::AlignVCenter, searchInfo.sSeq);

    // 商品
    const int nSecondWidth = 216*g_heightRate;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    const int nVSpace = 2*g_heightRate;
    // 商品--商品名称
    QString strName = "";
    if( searchInfo.sShortName.isEmpty() ) {
        strName = searchInfo.sName;
    } else {
        strName = searchInfo.sShortName;
    }

    int nSecondYPos = yPos + (nHeight - (nfontSize + nVSpace + nfontSize2))/2 ;
    QRect secondFirstRect(nSecondXPos, nSecondYPos, nSecondWidth, nfontSize);
    painter->drawText(secondFirstRect, Qt::AlignLeft | Qt::AlignVCenter, strName );

    // 商品--商品单位
    int goodsNameWidth = painter->fontMetrics().width( strName );
    font.setPixelSize(nfontSize2);
    painter->setFont(font);
    pen.setColor(bSelected ? "#ffffff" : "#999999");
    painter->setPen(pen);
    QString sShowUnit = QString("( %1 )").arg(searchInfo.sWeighUnit);
    int goodsUnitXPos = nSecondXPos + goodsNameWidth + 2;
    int goodsUnitYPos = nSecondYPos + nfontSize - nfontSize2;
    QRect goodsUnitRect(goodsUnitXPos, goodsUnitYPos, nSecondWidth, nfontSize2);
    painter->drawText(goodsUnitRect, Qt::AlignLeft | Qt::AlignVCenter, sShowUnit);

    // 商品--商品条码
    nSecondYPos += (nfontSize + nVSpace);
    QRect secondSecondRect(nSecondXPos, nSecondYPos, nSecondWidth, nfontSize2);
    painter->drawText(secondSecondRect, Qt::AlignLeft | Qt::AlignVCenter, searchInfo.sCode);

    //
    font.setPixelSize(nfontSize);
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setFont(font);
    painter->setPen(pen);

    // 类别
    const int nThirdWidth = 78*g_heightRate;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, searchInfo.sBelongCategory);

    // 账盘数量
    const int nFourthWidth = 100*g_heightRate;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(searchInfo.fShouldStockNum, 'f', 2));

    // 实盘数量
    const int nFifthWidth = 98;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifthRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(searchInfo.fRealStockNum, 'f', 2));

    // 差异数量
    const int nSixthWidth = 108*g_heightRate;
    int nSixthXPos = nFifthXPos + nFifthWidth;
    QRect sixthRect(nSixthXPos, yPos, nSixthWidth, nHeight);
    painter->drawText(sixthRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(searchInfo.fStockDifferNum, 'f', 2));


    // 进价差异金额
    pen.setColor(bSelected?"#ffffff":"#ea8852");
    painter->setPen(pen);
    const int nSeventhWidth = 106*g_heightRate;
    int nSeventhXPos = nSixthXPos + nSixthWidth;
    QRect seventhRect(nSeventhXPos, yPos, nSeventhWidth, nHeight);
    painter->drawText(seventhRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(searchInfo.fBuyDifferPrice, 'f', 2));

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

StockOrderSearchListView::StockOrderSearchListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51*g_heightRate)
{
    init();
}

void StockOrderSearchListView::appendItem(const StockOrderSearchInfo &searchInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(searchInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(searchInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(searchInfo.nId);
    }

    QVariant variant;
    variant.setValue(searchInfo);
    pItem->setData(variant, e_StockOrderSearchInfo);

    if (m_nSelectKeyId == searchInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void StockOrderSearchListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void StockOrderSearchListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    StockOrderSearchInfo orderSearchInfo;
    QVariant v_itemInfo = index.data(e_StockOrderSearchInfo);
    if (v_itemInfo.canConvert<StockOrderSearchInfo>())//可以转换
    {
        orderSearchInfo = v_itemInfo.value<StockOrderSearchInfo>();
        m_nSelectKeyId = orderSearchInfo.nId;
    }
}

void StockOrderSearchListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new StockOrderSearchDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



