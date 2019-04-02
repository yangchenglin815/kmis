#include "CategoryChooseListView.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

enum CategoryChooseType
{
    e_CategoryChooseInfo
};

CategoryChooseDelegate::CategoryChooseDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void CategoryChooseDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_CategoryChooseInfo); 
    if (v_itemInfo.canConvert<CategoryChooseInfo>())
    {
        CategoryChooseInfo categoryChooseInfo = v_itemInfo.value<CategoryChooseInfo>();
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/rect.png"));
            bSelected = true;
        }

        if (categoryChooseInfo.bRoot)
        {
            if (!bSelected)
            {
                painter->fillRect(option.rect, QBrush(QColor("#fafafa")));
            }
            paintRootContent(painter, option, categoryChooseInfo, bSelected);
        }
        else
        {
            paintContent(painter, option, categoryChooseInfo, bSelected);
        }
    }

    painter->restore();
}

void CategoryChooseDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                                          const CategoryChooseInfo &categoryChooseInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();
    static const int c_nLeftMargin = 12;
    const int c_nStartX = xPos + c_nLeftMargin;
    QFont font;
    font.setPixelSize(14);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    if (bSelected)
    {
        pen.setColor("#ffffff");
    }
    else
    {
       pen.setColor("#333333");
    }
    painter->setPen(pen);

    QString showText = QString("%1 %2").arg(categoryChooseInfo.position).arg(categoryChooseInfo.name);
    QRect textRect(c_nStartX, yPos, nWidth, nHeight);
    painter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, showText);

    int nShowTextWidth = painter->fontMetrics().width(showText);

    font.setPixelSize(10);
    if (bSelected)
    {
        pen.setColor("#a2a2a2");
    }
    else
    {
        pen.setColor("#f69f6a");
    }
    painter->setFont(font);
    painter->setPen(pen);

    int nOffX = 3;
    int nNumXPos = c_nStartX + nShowTextWidth + nOffX;
    int nOffY = 1;
    QRect numRect(nNumXPos, yPos + nOffY, nWidth, nHeight);
    painter->drawText(numRect, Qt::AlignLeft | Qt::AlignVCenter, QString("(%1)").arg(categoryChooseInfo.num));

    QPen linePen;
    linePen.setColor("#ededed");
    painter->setPen(linePen);
    painter->drawLine(xPos, yPos+nHeight-1, xPos+nWidth, yPos+nHeight-1);
    if (categoryChooseInfo.position%2 == 0)
    {
        painter->drawLine(xPos+nWidth-1 , yPos, xPos+nWidth-1, yPos+nHeight);
    }
}

void CategoryChooseDelegate::paintRootContent(QPainter *painter, const QStyleOptionViewItem &option, const CategoryChooseInfo &categoryChooseInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();
    QFont font;
    font.setPixelSize(14);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    if (bSelected)
    {
        pen.setColor("#ffffff");
    }
    else
    {
       pen.setColor("#333333");
    }
    painter->setPen(pen);

    QString showText = QString("%1").arg(categoryChooseInfo.name);
    QRect textRect(xPos, yPos, nWidth, nHeight);
    painter->drawText(textRect, Qt::AlignHCenter | Qt::AlignVCenter, showText);

    int nShowTextWidth = painter->fontMetrics().width(showText);

    font.setPixelSize(10);
    pen.setColor("#f69f6a");
    painter->setFont(font);
    painter->setPen(pen);

    int nOffX = 3;
    int nNumXPos = xPos + (nShowTextWidth + nWidth)/2 + nOffX;
    QRect numRect(nNumXPos, yPos, nWidth, nHeight);
    painter->drawText(numRect, Qt::AlignLeft | Qt::AlignVCenter, QString("(%1)").arg(categoryChooseInfo.num));

//    QPen linePen;
//    linePen.setColor("#ededed");
//    painter->setPen(linePen);
//    painter->drawLine(xPos, yPos+nHeight-1, xPos+nWidth, yPos+nHeight-1);
}

CategoryChooseListView::CategoryChooseListView(QWidget *parent)
    : QListView(parent)
    , m_nItemHeight(40)
    , m_nItemWidth(99)
    , m_nRootItemHeight(44)
    , m_nRootItemWidth(200)
    , m_sSelectedCategoryKeyId(-1)
{
    init();
}

void CategoryChooseListView::appendItem(const CategoryChooseInfo &categoryChooseInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(categoryChooseInfo.skeyId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(categoryChooseInfo.skeyId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        if (!categoryChooseInfo.bRoot)
        {
            pItem->setSizeHint(QSize(m_nItemWidth, m_nItemHeight));
        }
        else
        {
            pItem->setSizeHint(QSize(m_nRootItemWidth, m_nRootItemHeight));
        }
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(categoryChooseInfo.skeyId);
    }
    QVariant variant;
    variant.setValue(categoryChooseInfo);
    pItem->setData(variant, e_CategoryChooseInfo);
    if (categoryChooseInfo.skeyId == m_sSelectedCategoryKeyId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void CategoryChooseListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void CategoryChooseListView::setDefultSelectedCategoryKeyId(QString sCategoryKeyId)
{
    m_sSelectedCategoryKeyId = sCategoryKeyId;
}

void CategoryChooseListView::mousePressEvent(QMouseEvent *event)
{
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    CategoryChooseInfo categoryChooseInfo;
    QVariant v_itemInfo = index.data(e_CategoryChooseInfo);
    if (v_itemInfo.canConvert<CategoryChooseInfo>())//可以转换
    {
        categoryChooseInfo = v_itemInfo.value<CategoryChooseInfo>();
        m_sSelectedCategoryKeyId = categoryChooseInfo.skeyId;
        emit sigChooseCategory(categoryChooseInfo);
    }

    QListView::mousePressEvent(event);
}

void CategoryChooseListView::init()
{
    setViewMode(IconMode);
    setMovement(Static);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new CategoryChooseDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


