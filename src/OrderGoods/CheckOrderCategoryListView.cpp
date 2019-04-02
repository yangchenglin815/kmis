#include "CheckOrderCategoryListView.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "../data/constData.h"

enum CheckOrderCategoryType
{
    e_checkOrderCategoryInfo,
};

CheckOrderCategoryDelegate::CheckOrderCategoryDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void CheckOrderCategoryDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_checkOrderCategoryInfo);
    if (v_itemInfo.canConvert<CheckOrderCategoryInfo>())
    {
        CheckOrderCategoryInfo checkOrderCategoryInfo = v_itemInfo.value<CheckOrderCategoryInfo>();
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
        }

        paintContent(painter, option, checkOrderCategoryInfo, bSelected);
    }

    painter->restore();
}

void CheckOrderCategoryDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                                              const CheckOrderCategoryInfo &checkOrderCategoryInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();

    const int checkBoxSideLenght = 16;
    int nCheckBoxXPos = xPos;
    int nCheckBoxYPos = yPos + (nHeight - checkBoxSideLenght) / 2;
    QRect checkBoxRect(nCheckBoxXPos, nCheckBoxYPos, checkBoxSideLenght, checkBoxSideLenght);
    QPixmap checkBoxPixmap;
    if (bSelected)
    {
        checkBoxPixmap.load(":/orderGoodsImage/checkBoxPress.png");
    }
    else
    {
        checkBoxPixmap.load(":/orderGoodsImage/checkBox.png");
    }
    painter->drawPixmap(checkBoxRect, checkBoxPixmap);

    const int nNameFontSize = 14;
    QFont font;
    font.setPixelSize(nNameFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#ffffff");
    painter->setPen(pen);
    const int nOffx = 4;
    int nTextXPos = nCheckBoxXPos + checkBoxSideLenght + nOffx;
    int nTextYPos = yPos;
    QRect textRect(nTextXPos, nTextYPos, nWidth, nHeight);
    painter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, checkOrderCategoryInfo.sName);
}

CheckOrderCategoryListView::CheckOrderCategoryListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemWidth(88)
    , m_nItemHeight(42)
    , m_bSelectedAll(false)
{
    init();
}

void CheckOrderCategoryListView::appendItem(const CheckOrderCategoryInfo &checkOrderCategoryInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(checkOrderCategoryInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(checkOrderCategoryInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(m_nItemWidth, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(checkOrderCategoryInfo.nId);
    }
    QVariant variant;
    variant.setValue(checkOrderCategoryInfo);
    pItem->setData(variant, e_checkOrderCategoryInfo);

    if (m_selectedIdList.contains(checkOrderCategoryInfo.nId))
    {
        this->setCurrentIndex(pItem->index());
    }
}

void CheckOrderCategoryListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
    update();
}

void CheckOrderCategoryListView::setDefaultSelectedIdList(QList<int> selectedIdList)
{
    m_selectedIdList = selectedIdList;
}

void CheckOrderCategoryListView::clearSelectedIdList()
{
    m_selectedIdList.clear();
}

void CheckOrderCategoryListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    CheckOrderCategoryInfo checkOrderCategoryInfo;
    QVariant v_itemInfo = index.data(e_checkOrderCategoryInfo);
    if (v_itemInfo.canConvert<CheckOrderCategoryInfo>())//可以转换
    {
        checkOrderCategoryInfo = v_itemInfo.value<CheckOrderCategoryInfo>();
        if (checkOrderCategoryInfo.nId < 0) // 根节点(全部)
        {
            m_bSelectedAll = !m_bSelectedAll;
            if (m_bSelectedAll)
            {
                emit sigSelectAllCategory(m_bSelectedAll);
            }
            else
            {
                emit sigSelectAllCategory(m_bSelectedAll);
            }
        }
        else
        {
            if (m_bSelectedAll)
            {
                m_bSelectedAll = false;
                m_selectedIdList.removeAll(c_nNegativeNumber);
            }

            if (m_selectedIdList.contains(checkOrderCategoryInfo.nId))
            {
                m_selectedIdList.removeAll(checkOrderCategoryInfo.nId);
                emit sigAddSelectCategory(checkOrderCategoryInfo.nId, false);
            }
            else
            {
                m_selectedIdList.append(checkOrderCategoryInfo.nId);
                emit sigAddSelectCategory(checkOrderCategoryInfo.nId, true);
            }
        }
    }
}

void CheckOrderCategoryListView::init()
{
    setViewMode(IconMode);
    setMovement(Static);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new CheckOrderCategoryDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode(MultiSelection);
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


