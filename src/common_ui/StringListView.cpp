#include "StringListView.h"
#include <QPainter>
#include <QMouseEvent>

enum StringListItemType
{
    e_strInfo = Qt::UserRole + 1,
};

StringListDelegate::StringListDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
    , m_nFontSize(12)
{

}

void StringListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_strInfo);
    if (v_itemInfo.canConvert<StrInfo>())
    {
        StrInfo strInfo = v_itemInfo.value<StrInfo>();
        paintContent(painter, option, strInfo);
    }

    painter->restore();
}

void StringListDelegate::setFontSize(int nFontSize)
{
    m_nFontSize = nFontSize;
}

void StringListDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const StrInfo strInfo) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();
    static const int c_nLeftMargin = 4;
    const int c_nStartX = xPos + c_nLeftMargin;
    QFont font;
    font.setPixelSize(m_nFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#666666");
    painter->setPen(pen);

    QRect textRect(c_nStartX, yPos, nWidth, nHeight);
    painter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, strInfo.sText);

    if (strInfo.bDrawLine)
    {
        pen.setColor("#ededed");
        painter->setPen(pen);
        painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
    }
}

StringListView::StringListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_pStringListDelegate(NULL)
{
    init();
}

void StringListView::setItemHeight(int nItemHeight)
{
    m_nItemHeight = nItemHeight;
}

void StringListView::appendItem(StrInfo strInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(strInfo.sText))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(strInfo.sText, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
        QVariant variant;
        variant.setValue(strInfo);
        pItem->setData(variant, e_strInfo);
        this->setFixedHeight(getItemsCount()*m_nItemHeight);
    }
}

void StringListView::setFontSize(int nFontSize)
{
    if (m_pStringListDelegate != NULL)
    {
        m_pStringListDelegate->setFontSize(nFontSize);
    }
}

int StringListView::getItemsCount()
{
    return m_ItemKeyIdMap.keys().count();
}

void StringListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    QModelIndex index = indexAt(event->pos());
    QVariant v_ItemInfo = index.data(e_strInfo);
    if (!v_ItemInfo.canConvert<StrInfo>())
    {
        return;
    }

    StrInfo strInfo = v_ItemInfo.value<StrInfo>();
    emit sigClicked(strInfo.sText);
}

void StringListView::init()
{
    m_pStringListDelegate = new StringListDelegate(this);
    setItemDelegateForColumn(0, m_pStringListDelegate);
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
