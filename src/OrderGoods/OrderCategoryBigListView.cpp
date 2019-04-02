#include "OrderCategoryBigListView.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

enum orderCategoryType
{
    e_orderCategoryInfo
};

OrderCategoryBigDelegate::OrderCategoryBigDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void OrderCategoryBigDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_orderCategoryInfo);
    if (v_itemInfo.canConvert<OrderCategoryBigInfo>())
    {
        OrderCategoryBigInfo orderCategoryInfo = v_itemInfo.value<OrderCategoryBigInfo>();
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
        }

        paintContent(painter, option, orderCategoryInfo, bSelected);
    }

    painter->restore();
}

void OrderCategoryBigDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                                            const OrderCategoryBigInfo &orderCategoryInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();
    const int nNameFontSize = 14;

    QFont font;
    font.setPixelSize(nNameFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    int nNameWidth = painter->fontMetrics().width(orderCategoryInfo.sName);

    const int nNumberFontSize = 12;
    font.setPixelSize(nNumberFontSize);
    painter->setFont(font);
    int nNumberWidth = painter->fontMetrics().width(QString("(%1)").arg(orderCategoryInfo.nNumber));

    font.setPixelSize(nNameFontSize);
    painter->setFont(font);
    const int nNameNumberSpace = 2; // 名字和数字之间的间隔
    int nNameStartXPos = xPos + (nWidth - (nNameWidth + nNumberWidth + nNameNumberSpace)) / 2; // 名字和数字整体居中的起始坐标
    int nNameStartYPos = yPos + (nHeight - nNameFontSize) / 2;
    QRect nameRect(nNameStartXPos, nNameStartYPos, nNameWidth, nNameFontSize);
    if (!bSelected)
    {
        pen.setColor("#ffffff");
    }
    else
    {
        pen.setColor("#f08e58");
    }
    painter->setPen(pen);
    painter->drawText(nameRect, Qt::AlignCenter, orderCategoryInfo.sName);

    font.setPixelSize(nNumberFontSize);
    painter->setFont(font);
    int nNumberStartXPos = nNameStartXPos + nNameWidth + nNameNumberSpace;
    int nNumberStartYPos = nNameStartYPos + (nNameFontSize - nNumberFontSize);
    QRect numberRect(nNumberStartXPos, nNumberStartYPos, nNumberWidth, nNumberFontSize);
    if (!bSelected)
    {
        pen.setColor("#999999");
    }
    else
    {
        pen.setColor("#f08e58");
    }
    painter->setPen(pen);
    painter->drawText(numberRect, Qt::AlignCenter, QString("(%1)").arg(orderCategoryInfo.nNumber));

    if (orderCategoryInfo.bDrawLine)
    {
        pen.setColor("#6c6c6c");
        painter->setPen(pen);
        int startXPos = xPos + nWidth - 1;
        int startYPos = (nHeight - nNameFontSize)/2;
        int endXPos = startXPos;
        int endYPos = startYPos + nNameFontSize;
        painter->drawLine(startXPos, startYPos, endXPos, endYPos);
    }
}

OrderCategoryBigListView::OrderCategoryBigListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(50)
    , m_nItemWidth(105)
    , m_nSelectedCategoryId(-1)
{
    init();
}

void OrderCategoryBigListView::appendItem(const OrderCategoryBigInfo &orderCategoryInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(orderCategoryInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(orderCategoryInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(m_nItemWidth, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(orderCategoryInfo.nId);
    }
    QVariant variant;
    variant.setValue(orderCategoryInfo);
    pItem->setData(variant, e_orderCategoryInfo);

    if (m_nSelectedCategoryId == orderCategoryInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void OrderCategoryBigListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void OrderCategoryBigListView::setDefaultSelectedCategoryId(int nCategoryId)
{
    m_nSelectedCategoryId = nCategoryId;
}

void OrderCategoryBigListView::mousePressEvent(QMouseEvent *event)
{
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    OrderCategoryBigInfo orderCategoryInfo;
    QVariant v_itemInfo = index.data(e_orderCategoryInfo);
    if (v_itemInfo.canConvert<OrderCategoryBigInfo>())//可以转换
    {
        orderCategoryInfo = v_itemInfo.value<OrderCategoryBigInfo>();
        m_nSelectedCategoryId = orderCategoryInfo.nId;
        emit sigClickCategoryBig(m_nSelectedCategoryId);
    }

    QListView::mousePressEvent(event);
}

void OrderCategoryBigListView::init()
{
    setViewMode(IconMode);
    setMovement(Static);
    setSpacing(0);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new OrderCategoryBigDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


