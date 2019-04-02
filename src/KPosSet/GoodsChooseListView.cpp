#include "GoodsChooseListView.h"
#include <QPainter>
#include <QMouseEvent>

enum GoodsChooseType
{
    e_GoodsChooseInfo
};

GoodsChooseDelegate::GoodsChooseDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void GoodsChooseDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_GoodsChooseInfo);
    if (v_itemInfo.canConvert<GoodsChooseInfo>())
    {
        GoodsChooseInfo goodsChooseInfo = v_itemInfo.value<GoodsChooseInfo>();
        if (option.state & QStyle::State_Selected)
        {
            if (goodsChooseInfo.bRootGoods)
            {
                painter->drawPixmap(option.rect, QPixmap(":/kPosSetImage/goodsChoose/preDeleteGoods.png").scaled(option.rect.size()));
            }
            else
            {
                painter->drawPixmap(option.rect, QPixmap(":/kPosSetImage/goodsChoose/preSelecteGoods.png").scaled(option.rect.size()));
            }
        }
        else
        {
            painter->drawPixmap(option.rect, QPixmap(":/kPosSetImage/goodsChoose/normalGoods.png").scaled(option.rect.size()));
        }

        paintContent(painter, option, goodsChooseInfo);
    }

    painter->restore();
}

void GoodsChooseDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                                       const GoodsChooseInfo &goodsChooseInfo) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    const int nLeftSpace = 6;
    const int nTopSpace = 5;

    const int nFontSize = 12;

    QFont font;
    font.setPixelSize(nFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#ffffff");
    painter->setPen(pen);

    int c_nStartX = xPos + nLeftSpace;
    int c_nStartY = yPos + nTopSpace;
    const int nTextHeight = nFontSize;
    const int nTextRowLengh = 73;

    QString goodsName = goodsChooseInfo.name;
    QString showContentFirstRow = painter->fontMetrics().elidedText(goodsName, Qt::ElideRight, nTextRowLengh);
    showContentFirstRow = goodsChooseInfo.name.left(showContentFirstRow.length());
    QRect firstRowTextRect(c_nStartX, c_nStartY, nWidth, nTextHeight);
    painter->drawText(firstRowTextRect, Qt::AlignLeft | Qt::AlignVCenter, showContentFirstRow);
    const int nOffY = 2;
    c_nStartY += nTextHeight + nOffY;

    goodsName = goodsName.right(goodsName.length() - showContentFirstRow.length());
    QString showContentSecondRow =  painter->fontMetrics().elidedText(goodsName, Qt::ElideRight, nTextRowLengh);
    QRect secondRowTextRect(c_nStartX, c_nStartY, nWidth, nTextHeight);
    painter->drawText(secondRowTextRect, Qt::AlignLeft | Qt::AlignVCenter, showContentSecondRow);
    c_nStartY += nTextHeight;

    const int nOffY2 = 5;
    c_nStartY += nOffY2;
    QString priceText = QString("￥%1/%2").arg(goodsChooseInfo.price).arg(goodsChooseInfo.unit);
    QRect priceRect(c_nStartX, c_nStartY, nWidth, nTextHeight);
    painter->drawText(priceRect, Qt::AlignLeft | Qt::AlignVCenter, priceText);
}

GoodsChooseListView::GoodsChooseListView(QWidget *parent)
    : QListView(parent)
    , m_nItemHeight(53)
    , m_nItemWidth(85)
{
    init();
}

void GoodsChooseListView::appendItem(const GoodsChooseInfo &goodsChooseInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(goodsChooseInfo.id))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(goodsChooseInfo.id, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(m_nItemWidth, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(goodsChooseInfo.id);
    }
    QVariant variant;
    variant.setValue(goodsChooseInfo);
    pItem->setData(variant, e_GoodsChooseInfo);

    if (m_nSelectedGoodsIdList.contains(goodsChooseInfo.id))
    {
        this->setCurrentIndex(pItem->index());
    }
}

void GoodsChooseListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void GoodsChooseListView::clearSelectGoodsIdList()
{
    m_nSelectedGoodsIdList.clear();
}

void GoodsChooseListView::setDefaultSelectedGoodsList(QList<int> selectedGoodsList)
{
    m_nSelectedGoodsIdList = selectedGoodsList;
}

QList<int> GoodsChooseListView::getSelectedGoodsIdList()
{
    return m_nSelectedGoodsIdList;
}

void GoodsChooseListView::mousePressEvent(QMouseEvent *event)
{
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    GoodsChooseInfo goodsChooseInfo;
    QVariant v_itemInfo = index.data(e_GoodsChooseInfo);
    if (v_itemInfo.canConvert<GoodsChooseInfo>())//可以转换
    {
        goodsChooseInfo = v_itemInfo.value<GoodsChooseInfo>();
        if (m_nSelectedGoodsIdList.contains(goodsChooseInfo.id))
        {
            m_nSelectedGoodsIdList.removeAll(goodsChooseInfo.id);
        }
        else
        {
            m_nSelectedGoodsIdList.append(goodsChooseInfo.id);
        }
    }

    QListView::mousePressEvent(event);
}

void GoodsChooseListView::init()
{
    setViewMode(IconMode);
    setMovement(Static);
    setSpacing(3);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new GoodsChooseDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode(MultiSelection);
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


