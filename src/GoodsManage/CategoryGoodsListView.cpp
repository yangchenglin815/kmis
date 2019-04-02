#include "CategoryGoodsListView.h"

#include <QPainter>
#include <QMouseEvent>
#include <QLineEdit>
#include "constData.h"

enum CategoryGoodsType
{
    e_GoodsInfo
};

CategoryGoodsListView::CategoryGoodsListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
{
   init();
}

void CategoryGoodsListView::appendItem(const sGoodsInfo &goodsInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(goodsInfo.id))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(goodsInfo.id, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(goodsInfo.id);
    }
    QVariant variant;
    variant.setValue(goodsInfo);
    pItem->setData(variant, e_GoodsInfo);
}

void CategoryGoodsListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void CategoryGoodsListView::mousePressEvent(QMouseEvent *event)
{

}

void CategoryGoodsListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new CategoryGoodsDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


CategoryGoodsDelegate::CategoryGoodsDelegate(QWidget *parent)
 : QStyledItemDelegate(parent)
{

}

void CategoryGoodsDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_GoodsInfo);
    if (v_itemInfo.canConvert<sGoodsInfo>())
    {
        sGoodsInfo goodsInfo = v_itemInfo.value<sGoodsInfo>();
        paintFirstColumn(painter, option, goodsInfo);
        paintOtherColumn(painter, option, goodsInfo);
    }

    painter->restore();
}

void CategoryGoodsDelegate::paintFirstColumn(QPainter *painter, const QStyleOptionViewItem &option, const sGoodsInfo &goodsInfo) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();

    const int nFirstRowFontSize = 14;
    QFont font;
    font.setPixelSize(nFirstRowFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#333333");
    painter->setPen(pen);

    // 商品 -- 商品名称
    const int nLeftSpace = 26;
    const int nTopSpace = 8;
    int nFirstRowXPos = xPos + nLeftSpace;
    int nFirstRowYPos = yPos + nTopSpace;
    QRect firstRowRect(nFirstRowXPos, nFirstRowYPos, nWidth, nFirstRowFontSize);
    painter->drawText(firstRowRect, Qt::AlignLeft | Qt::AlignVCenter, goodsInfo.sName);

    // 商品--商品编号(商品单位)
    const int nSecondFontSize = 12;
    const int nTwoRowSpace = 8;
    font.setPixelSize(nSecondFontSize);
    painter->setFont(font);
    pen.setColor("#999999");
    painter->setPen(pen);
    int nSecondRowXPos = nFirstRowXPos;
    int nSecondRowYPos = nFirstRowYPos + nFirstRowFontSize + nTwoRowSpace;
    QRect secondRowRect(nSecondRowXPos, nSecondRowYPos, nWidth, nSecondFontSize);
    QString secondText = QString("%1(%2)").arg(goodsInfo.sCode).arg(goodsInfo.sUnitSpecification);
    painter->drawText(secondRowRect, Qt::AlignLeft | Qt::AlignVCenter, secondText);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

void CategoryGoodsDelegate::paintOtherColumn(QPainter *painter, const QStyleOptionViewItem &option, const sGoodsInfo &goodsInfo) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nHeight = option.rect.height();

    const int nFirstRowFontSize = 14;
    QFont font;
    font.setPixelSize(nFirstRowFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);

    // 商品条码
    QPen pen;
    pen.setColor("#333333");
    painter->setPen(pen);
    const int nLeftSpace = 175;
    int nSecondColXPos = xPos + nLeftSpace;
    int nSecondColWidth = 140;
    QRect secondColRect(nSecondColXPos, yPos, nSecondColWidth, nHeight);
    painter->drawText(secondColRect, Qt::AlignLeft | Qt::AlignVCenter, goodsInfo.sCodeId);

    // 原价
    int nThirdWidth = 74;
    int nThirdColXPos = nSecondColXPos + nSecondColWidth;
    QRect thirdColRect(nThirdColXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdColRect, Qt::AlignLeft | Qt::AlignVCenter, QString("¥%1").arg(goodsInfo.fPrice));

    // 会员价
    int nFourthColWidth = 96;
    int nFourthColXPos = nThirdColXPos + nThirdWidth;
    QRect fourthColRect(nFourthColXPos, yPos, nFourthColWidth, nHeight);
    painter->drawText(fourthColRect, Qt::AlignLeft | Qt::AlignVCenter, QString("¥%1").arg(goodsInfo.vPrice));

    // 称重类型
    int nFifthWidth = 80;
    int nFifthColXPos = nFourthColXPos + nFourthColWidth;
    QRect fifthColRect(nFifthColXPos, yPos, nFifthWidth, nHeight);
    QString category;
    if(goodsInfo.category == 1){
        category = "标品";
    }
    else if(goodsInfo.category == 2){
        category = "称重";
    }
    else if(goodsInfo.category == 3){
        category = "计数";
    }
    painter->drawText(fifthColRect, Qt::AlignLeft | Qt::AlignVCenter, category);

    // 库存
    pen.setColor(f_fontColorOrange);
    painter->setPen(pen);
    int nSixColWidth = 70;
    int nSixColXPos = nFifthColXPos + nFifthWidth;
    QRect sixColRect(nSixColXPos, yPos, nSixColWidth, nHeight);
    painter->drawText(sixColRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(goodsInfo.sStockNumber, 'f', 2));
}
