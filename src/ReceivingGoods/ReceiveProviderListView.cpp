#include "ReceiveProviderListView.h"
#include <QPainter>
#include <QMouseEvent>

enum ReceiveProviderType
{
    e_receiveProvider,
};

ReceiveProviderDelegate::ReceiveProviderDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void ReceiveProviderDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_receiveProvider);
    if (v_itemInfo.canConvert<ReceiveProviderInfo>())
    {
        ReceiveProviderInfo receiveProviderInfo = v_itemInfo.value<ReceiveProviderInfo>();
        paintContent(painter, option, receiveProviderInfo);
    }

    painter->restore();
}

void ReceiveProviderDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const ReceiveProviderInfo &receiveProviderInfo) const
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

    const int nLeftSpace = 12;
    const int nTopSpace = 10;
    int nFirstRowXPos = xPos + nLeftSpace;
    int nFirstRowYPos = yPos + nTopSpace;
    QRect firstRowRect(nFirstRowXPos, nFirstRowYPos, nWidth, nFirstRowFontSize);
    painter->drawText(firstRowRect, Qt::AlignLeft | Qt::AlignVCenter, receiveProviderInfo.sName);

    const int nSecondFontSize = 12;
    const int nTwoRowSpace = 4;
    font.setPixelSize(nSecondFontSize);
    painter->setFont(font);
    pen.setColor("#999999");
    painter->setPen(pen);
    int nSecondRowXPos = nFirstRowXPos;
    int nSecondRowYPos = nFirstRowYPos + nFirstRowFontSize + nTwoRowSpace;
    QRect secondRowRect(nSecondRowXPos, nSecondRowYPos, nWidth, nSecondFontSize);
    painter->drawText(secondRowRect, Qt::AlignLeft | Qt::AlignVCenter, receiveProviderInfo.sCode);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

ReceiveProviderListView::ReceiveProviderListView(QWidget *parent)
    : QListView(parent)
    , m_nItemHeight(50)
{
    init();
}

void ReceiveProviderListView::appendItem(const ReceiveProviderInfo &receiveProviderInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(receiveProviderInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(receiveProviderInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(receiveProviderInfo.nId);
    }

    QVariant variant;
    variant.setValue(receiveProviderInfo);
    pItem->setData(variant, e_receiveProvider);
}

void ReceiveProviderListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void ReceiveProviderListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    ReceiveProviderInfo receiveProviderInfo;
    QVariant v_itemInfo = index.data(e_receiveProvider);
    if (v_itemInfo.canConvert<ReceiveProviderInfo>())//可以转换
    {
        receiveProviderInfo = v_itemInfo.value<ReceiveProviderInfo>();
        emit sigClickProvider(receiveProviderInfo.nId);
    }
}

void ReceiveProviderListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new ReceiveProviderDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
