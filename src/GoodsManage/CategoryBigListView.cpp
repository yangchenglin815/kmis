#include "CategoryBigListView.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

enum CategoryType
{
    e_CategoryInfo
};

CategoryBigListView::CategoryBigListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(50)
    , m_nItemWidth(105)
    , m_nSelectedCategoryId(-1)
{
   init();
}

void CategoryBigListView::appendItem(const sCategoryBigInfo &categoryInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(categoryInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(categoryInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(m_nItemWidth, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(categoryInfo.nId);
    }
    QVariant variant;
    variant.setValue(categoryInfo);
    pItem->setData(variant, e_CategoryInfo);

    if (m_nSelectedCategoryId == categoryInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void CategoryBigListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void CategoryBigListView::setDefaultSelectedCategoryId(int nCategoryId)
{
    m_nSelectedCategoryId = nCategoryId;
}

void CategoryBigListView::mousePressEvent(QMouseEvent *event)
{
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    sCategoryBigInfo categoryInfo;
    QVariant v_itemInfo = index.data(e_CategoryInfo);
    if (v_itemInfo.canConvert<sCategoryBigInfo>())//可以转换
    {
        categoryInfo = v_itemInfo.value<sCategoryBigInfo>();
        m_nSelectedCategoryId = categoryInfo.nId;
        emit sigClickCategoryBig(m_nSelectedCategoryId);
    }

    QListView::mousePressEvent(event);
}

void CategoryBigListView::init()
{
    setViewMode(IconMode);
    setMovement(Static);
    setSpacing(0);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new CategoryBigDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


CategoryBigDelegate::CategoryBigDelegate(QWidget *parent)
: QStyledItemDelegate(parent)
{

}

void CategoryBigDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_CategoryInfo);
    if (v_itemInfo.canConvert<sCategoryBigInfo>())
    {
        sCategoryBigInfo categoryInfo = v_itemInfo.value<sCategoryBigInfo>();
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
        }

        paintContent(painter, option, categoryInfo, bSelected);
    }

    painter->restore();
}

void CategoryBigDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const sCategoryBigInfo &scategoryInfo, bool bSelected) const
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
    int nNameWidth = painter->fontMetrics().width(scategoryInfo.sName);

    const int nNumberFontSize = 12;
    font.setPixelSize(nNumberFontSize);
    painter->setFont(font);
    int nNumberWidth = painter->fontMetrics().width(QString("(%1)").arg(scategoryInfo.nNumber));

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
    painter->drawText(nameRect, Qt::AlignCenter, scategoryInfo.sName);

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
    painter->drawText(numberRect, Qt::AlignCenter, QString("(%1)").arg(scategoryInfo.nNumber));

    if (scategoryInfo.bDrawLine)
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
