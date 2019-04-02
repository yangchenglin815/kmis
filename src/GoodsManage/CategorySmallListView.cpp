#include "CategorySmallListView.h"
#include <QPainter>
#include <QMouseEvent>

enum CategoryType
{
    e_SmallCategoryInfo
};

CategorySmallDelegate::CategorySmallDelegate(QWidget *parent)
: QStyledItemDelegate(parent)
{

}

void CategorySmallDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_SmallCategoryInfo);
    if (v_itemInfo.canConvert<sCategorySmallInfo>())
    {
        sCategorySmallInfo categorySmallInfo = v_itemInfo.value<sCategorySmallInfo>();
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

        paintContent(painter, option, categorySmallInfo, bSelected);
    }

    painter->restore();
}

void CategorySmallDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const sCategorySmallInfo &categorySmallInfo, bool bSelected) const
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
    int nNameWidth = painter->fontMetrics().width(categorySmallInfo.sName);
    const int nLeftSpace = 12;
    int nNameStartXPos = xPos + nLeftSpace;
    int nNameStartYPos = yPos + (nHeight - nNameFontSize) / 2;
    QRect nameRect(nNameStartXPos, nNameStartYPos, nNameWidth, nNameFontSize);
    painter->drawText(nameRect, Qt::AlignCenter, categorySmallInfo.sName);


    const int nNameNumberSpace = 2; // 名字和数字之间的间隔
    const int nNumberFontSize = 12;
    font.setPixelSize(nNumberFontSize);
    painter->setFont(font);
    pen.setColor("#999999");
    painter->setPen(pen);
    int nNumberStartXPos = nNameStartXPos + nNameWidth + nNameNumberSpace;
    int nNumberStartYPos = nNameStartYPos + (nNameFontSize - nNumberFontSize);
    QRect numberRect(nNumberStartXPos, nNumberStartYPos, nWidth, nNumberFontSize);
    painter->drawText(numberRect, Qt::AlignLeft | Qt::AlignVCenter, QString("(%1)").arg(categorySmallInfo.nNumber));
}

CategorySmallListView::CategorySmallListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(36)
    , m_nSelectedCategoryId(-1)
{
   init();
}

void CategorySmallListView::appendItem(const sCategorySmallInfo &categorySmallInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(categorySmallInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(categorySmallInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(categorySmallInfo.nId);
    }
    QVariant variant;
    variant.setValue(categorySmallInfo);
    pItem->setData(variant, e_SmallCategoryInfo);

    if (m_nSelectedCategoryId == categorySmallInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void CategorySmallListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void CategorySmallListView::setDefaultSelectedCategoryId(int nCategoryId)
{
     m_nSelectedCategoryId = nCategoryId;
}

void CategorySmallListView::mousePressEvent(QMouseEvent *event)
{
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    sCategorySmallInfo categorySmallInfo;
    QVariant v_itemInfo = index.data(e_SmallCategoryInfo);
    if (v_itemInfo.canConvert<sCategorySmallInfo>())//可以转换
    {
        categorySmallInfo = v_itemInfo.value<sCategorySmallInfo>();
        m_nSelectedCategoryId = categorySmallInfo.nId;
        emit sigClickCategorySmall(m_nSelectedCategoryId);
    }

    QListView::mousePressEvent(event);
}

void CategorySmallListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new CategorySmallDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
