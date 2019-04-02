#include "RankChartsLeftListView.h"
#include <QPainter>

enum RankChartsLeftInfoType
{
    e_rankChartsInfo
};

RankChartsLeftDelegate::RankChartsLeftDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void RankChartsLeftDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_rankChartsInfo);
    if (v_itemInfo.canConvert<RankChartsInfo>())
    {
        RankChartsInfo rankChartsInfo = v_itemInfo.value<RankChartsInfo>();
        paintContent(painter, option, rankChartsInfo);
    }

    painter->restore();
}

void RankChartsLeftDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const RankChartsInfo &rankChartsInfo) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    QFont font;
    const int nFontSize = 12;
    font.setPixelSize(nFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#333333");
    painter->setPen(pen);

    // 序号
    int nPositionWidth = 50;
    QRect positionRect(xPos, yPos, nPositionWidth, nHeight);
    painter->drawText(positionRect, Qt::AlignCenter, QString::number(rankChartsInfo.nPosition));

    // 商品
    // 商品 -- 商品名称
    const int nFirstColWidth = 121;
    int nFirstXPos = xPos + nPositionWidth;
    int nTowRowSpace = 8;
    int nFirstFirstRowYPos = yPos + (nHeight - 2*nFontSize - nTowRowSpace) / 2;
    QRect firstFirstRowRect(nFirstXPos, nFirstFirstRowYPos, nFirstColWidth, nFontSize);
    painter->drawText(firstFirstRowRect, Qt::AlignLeft | Qt::AlignVCenter, rankChartsInfo.sGoodsName);
    // 商品 -- 商品编号
    int nFirstSecondRowYPos = nFirstFirstRowYPos + nFontSize + nTowRowSpace;
    QRect firstSecondRowRect(nFirstXPos, nFirstSecondRowYPos, nFirstColWidth, nFontSize);
    pen.setColor("#999999");
    painter->setPen(pen);
    painter->drawText(firstSecondRowRect, Qt::AlignLeft | Qt::AlignVCenter, rankChartsInfo.sGoodsCode);

    pen.setColor("#666666");
    painter->setPen(pen);
    // 销售额
    const int nSecondWidth = 58;
    int nSecondColXPos = nFirstXPos + nFirstColWidth;
    QRect secondRect(nSecondColXPos, yPos, nSecondWidth, nHeight);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(rankChartsInfo.fSaleMoney, 'f', 2));

    // 单价
    const int nThirdWidth = 47;
    int nThirdXPos = nSecondColXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(rankChartsInfo.fGoodsPrice, 'f', 2));

    // 销售量
    const int nFourthWidth = 58;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(rankChartsInfo.fSaleNumber, 'f', 2));

    // 客流
    const int nFifthWidth = 46;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifthRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(rankChartsInfo.nPeopleNumber));

    //
    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

RankChartsLeftListView::RankChartsLeftListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(47)
{
    init();
}

void RankChartsLeftListView::appendItem(const RankChartsInfo &rankChartsInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(rankChartsInfo.nGoodsId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(rankChartsInfo.nGoodsId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(rankChartsInfo.nGoodsId);
    }

    QVariant variant;
    variant.setValue(rankChartsInfo);
    pItem->setData(variant, e_rankChartsInfo);
}

void RankChartsLeftListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void RankChartsLeftListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new RankChartsLeftDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
