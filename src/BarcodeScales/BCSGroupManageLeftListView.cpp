#include "BCSGroupManageLeftListView.h"
#include "../data/constData.h"
#include <QPainter>
#include <QMouseEvent>

enum ItemType
{
    e_itemInfo = Qt::UserRole + 1,
};

BCSGroupManageLeftDelegate::BCSGroupManageLeftDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void BCSGroupManageLeftDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<BCSGroupManageLeftInfo>())
    {
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
            QRect rect = option.rect;
            rect.setX(rect.x() + 1);
            rect.setWidth(rect.width() - 2);
            painter->fillRect(rect, QBrush(QColor(c_sThemeColor)));
        }
        BCSGroupManageLeftInfo itemInfo = v_itemInfo.value<BCSGroupManageLeftInfo>();
        paintContent(painter, option, itemInfo, bSelected);
    }

    painter->restore();
}

void BCSGroupManageLeftDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option,
                                              const BCSGroupManageLeftInfo &itemInfo, bool bSelected) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    const int nfontSize = 14;
    QFont font;
    font.setPixelSize(nfontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setPen(pen);

    // 序号
    const int nLeftSpace = 16;
    const int nFirstWidth = 44;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sSeq);

    // 组号
    const int nSecondWidth = 65;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    QRect secondRect(nSecondXPos, yPos, nSecondWidth, nHeight);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sGroupNum);

    // 组名
    const int nThirdWidth = 116;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sGroupName);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

BCSGroupManageLeftListView::BCSGroupManageLeftListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(44)
    , m_nSelectKeyId(-1)
{
    init();
}

void BCSGroupManageLeftListView::appendItem(const BCSGroupManageLeftInfo &itemInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(itemInfo.nGroupId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(itemInfo.nGroupId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(itemInfo.nGroupId);
    }

    QVariant variant;
    variant.setValue(itemInfo);
    pItem->setData(variant, e_itemInfo);

    if (m_nSelectKeyId == itemInfo.nGroupId)
    {
        m_selectItemInfo = itemInfo;
        this->setCurrentIndex(pItem->index());
    }
}

void BCSGroupManageLeftListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

int BCSGroupManageLeftListView::getSelectKeyId()
{
    return m_nSelectKeyId;
}

void BCSGroupManageLeftListView::setSelectKeyId(int nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

void BCSGroupManageLeftListView::getSelectItemInfo(BCSGroupManageLeftInfo &bcsInfo)
{
    if (m_nSelectKeyId < 0)
    {
        m_selectItemInfo.nGroupId = -1;
    }
    bcsInfo = m_selectItemInfo;
}

int BCSGroupManageLeftListView::getSelectSeq()
{
    if (m_nSelectKeyId < 0)
    {
        return -1;
    }
    return m_selectItemInfo.sSeq.toInt();
}

void BCSGroupManageLeftListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    BCSGroupManageLeftInfo itemInfo;
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<BCSGroupManageLeftInfo>())//可以转换
    {
        itemInfo = v_itemInfo.value<BCSGroupManageLeftInfo>();
        m_nSelectKeyId = itemInfo.nGroupId;
        m_selectItemInfo = itemInfo;
        emit sigClickItem();
    }
}

void BCSGroupManageLeftListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new BCSGroupManageLeftDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



