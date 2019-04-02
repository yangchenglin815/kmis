#include "AdjustPriceCategoryListView.h"
#include "../data/constData.h"
#include <QPainter>
#include <QMouseEvent>

enum AdjustPriceCategoryItemType
{
    e_adjustPriceCategoryInfo = Qt::UserRole + 1,
};

AdjustPriceCategoryDelegate::AdjustPriceCategoryDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void AdjustPriceCategoryDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();

    QVariant vItemInfo = index.data(e_adjustPriceCategoryInfo);
    if( vItemInfo.canConvert<CategoryInfo>() )
    {
        CategoryInfo categoryInfo = vItemInfo.value<CategoryInfo>();
        if((option.state & QStyle::State_Selected) && categoryInfo.nId >0)
        {
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/goods_category_btn_press.png"));
        }
        else
        {
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/goods_category_btn_normal.png"));
        }
        paintContent(painter, option, categoryInfo);
    }

    painter->restore();
}

void AdjustPriceCategoryDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, CategoryInfo &categoryInfo) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    QFont font;
    const int nfontSize = 12*g_widthRate;
    font.setPixelSize(nfontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor( "#ffffff");
    painter->setPen(pen);

    int nlen = categoryInfo.sName.length();
    if(nlen > 4)//当大于4个字符时候
    {
        QRect textRect = QRect(xPos + 18 * g_widthRate, yPos + 12 * g_widthRate, nfontSize * 4, option.rect.height());
        painter->drawText(textRect, Qt::TextWrapAnywhere, categoryInfo.sName);
    }
    else{
        QRect textRect = QRect(xPos, yPos, option.rect.width(), option.rect.height());
        painter->drawText(textRect, Qt::AlignCenter, categoryInfo.sName);
    }
}

AdjustPriceCategoryListView::AdjustPriceCategoryListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(54)
//    , m_nItemWidth(82)
    , m_sSelectedKeyId("")
{
    init();
}

void AdjustPriceCategoryListView::appendItem(const CategoryInfo &categoryInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(categoryInfo.sKeyId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(categoryInfo.sKeyId, pItem);
        m_keyIdList.append(categoryInfo.sKeyId);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(m_nItemWidth, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(categoryInfo.sKeyId);
    }
    QVariant variant;
    variant.setValue(categoryInfo);
    pItem->setData(variant, e_adjustPriceCategoryInfo);

    if (m_sSelectedKeyId == categoryInfo.sKeyId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void AdjustPriceCategoryListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
    m_keyIdList.clear();
}

void AdjustPriceCategoryListView::clickSelectKeyId()
{
    if (m_sSelectedKeyId.isEmpty() || (!m_keyIdList.contains(m_sSelectedKeyId)))
    {
        if (m_keyIdList.count() > 0)
        {
            m_sSelectedKeyId = m_keyIdList[0];
        }
    }

    if (!m_sSelectedKeyId.isEmpty())
    {
        QStandardItem* pItem = m_ItemKeyIdMap.value(m_sSelectedKeyId);
        if (pItem == NULL)
        {
            return;
        }

        this->setCurrentIndex(pItem->index());
        QVariant v_itemInfo = pItem->data(e_adjustPriceCategoryInfo);
        if (v_itemInfo.canConvert<CategoryInfo>())//可以转换
        {
            CategoryInfo categoryInfo = v_itemInfo.value<CategoryInfo>();
            emit sigClickItem(categoryInfo);
        }
    }
}

void AdjustPriceCategoryListView::setWidth(int width)
{
    m_nItemWidth = width;
}

void AdjustPriceCategoryListView::setHeight(int height)
{
    m_nItemHeight = height;
}

void AdjustPriceCategoryListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());
    CategoryInfo categoryInfo;
    QVariant v_itemInfo = index.data(e_adjustPriceCategoryInfo);
    if (v_itemInfo.canConvert<CategoryInfo>())//可以转换
    {
        categoryInfo = v_itemInfo.value<CategoryInfo>();
        m_sSelectedKeyId = categoryInfo.sKeyId;
        emit sigClickItem(categoryInfo);
    }
}

void AdjustPriceCategoryListView::init()
{
    setViewMode(IconMode);
    setMovement(Static);
    setSpacing(0);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new AdjustPriceCategoryDelegate(this));//设置图元代理forColumn
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode( SingleSelection );//单选
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
