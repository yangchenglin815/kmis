#include "OrderCategorySmallListView.h"
#include <QPainter>
#include <QMouseEvent>

enum orderCategoryType
{
    e_orderSmallCategoryInfo
};

OrderCategorySmallDelegate::OrderCategorySmallDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void OrderCategorySmallDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_orderSmallCategoryInfo);
    if (v_itemInfo.canConvert<OrderCategorySmallInfo>())
    {
        OrderCategorySmallInfo orderCategorySmallInfo = v_itemInfo.value<OrderCategorySmallInfo>();
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
            painter->drawPixmap(option.rect, QPixmap(":/orderGoodsImage/orderTab_Press.png").scaled(option.rect.size()));
        }
        else
        {
           painter->drawPixmap(option.rect, QPixmap(":/orderGoodsImage/orderTab.png").scaled(option.rect.size()));
        }

        paintContent(painter, option, orderCategorySmallInfo, bSelected);
    }

    painter->restore();
}

void OrderCategorySmallDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                                              const OrderCategorySmallInfo &orderCategorySmallInfo, bool bSelected) const
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
    if (!bSelected)
    {
        pen.setColor("#ffffff");
    }
    else
    {
        pen.setColor("#333333");
    }
    painter->setPen(pen);
    int nNameWidth = painter->fontMetrics().width(orderCategorySmallInfo.sName);
    const int nLeftSpace = 12;
    int nNameStartXPos = xPos + nLeftSpace;
    int nNameStartYPos = yPos + (nHeight - nNameFontSize) / 2;
    QRect nameRect(nNameStartXPos, nNameStartYPos, nNameWidth, nNameFontSize);
    painter->drawText(nameRect, Qt::AlignCenter, orderCategorySmallInfo.sName);


    const int nNameNumberSpace = 2; // 名字和数字之间的间隔
    const int nNumberFontSize = 12;
    font.setPixelSize(nNumberFontSize);
    painter->setFont(font);
    pen.setColor("#999999");
    painter->setPen(pen);
    int nNumberStartXPos = nNameStartXPos + nNameWidth + nNameNumberSpace;
    int nNumberStartYPos = nNameStartYPos + (nNameFontSize - nNumberFontSize);
    QRect numberRect(nNumberStartXPos, nNumberStartYPos, nWidth, nNumberFontSize);
    painter->drawText(numberRect, Qt::AlignLeft | Qt::AlignVCenter, QString("(%1)").arg(orderCategorySmallInfo.nNumber));
}

OrderCategorySmallListView::OrderCategorySmallListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(36)
    , m_nSelectedCategoryId(-1)
{
    init();
}

void OrderCategorySmallListView::appendItem(const OrderCategorySmallInfo &orderCategorySmallInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(orderCategorySmallInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(orderCategorySmallInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(orderCategorySmallInfo.nId);
    }
    QVariant variant;
    variant.setValue(orderCategorySmallInfo);
    pItem->setData(variant, e_orderSmallCategoryInfo);

    if (m_nSelectedCategoryId == orderCategorySmallInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void OrderCategorySmallListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void OrderCategorySmallListView::setDefaultSelectedCategoryId(int nCategoryId)
{
    m_nSelectedCategoryId = nCategoryId;
}

void OrderCategorySmallListView::mousePressEvent(QMouseEvent *event)
{
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    OrderCategorySmallInfo orderCategorySmallInfo;
    QVariant v_itemInfo = index.data(e_orderSmallCategoryInfo);
    if (v_itemInfo.canConvert<OrderCategorySmallInfo>())//可以转换
    {
        orderCategorySmallInfo = v_itemInfo.value<OrderCategorySmallInfo>();
        m_nSelectedCategoryId = orderCategorySmallInfo.nId;
        emit sigClickCategorySmall(m_nSelectedCategoryId);
    }

    QListView::mousePressEvent(event);
}

void OrderCategorySmallListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new OrderCategorySmallDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
