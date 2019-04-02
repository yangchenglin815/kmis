#include "OListView.h"
#include <QMouseEvent>
#include <QPainter>
#include "../data/enumData.h"
#include "../data/constData.h"
#include "../util/CommonFun.h"

enum OutStockItemType
{
    e_OutStockInfo = Qt::UserRole + 1,
};

OutStockDelegate::OutStockDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void OutStockDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_OutStockInfo);
    if (v_itemInfo.canConvert<OutStockOrderInfo>())
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
        OutStockOrderInfo istkInfo = v_itemInfo.value<OutStockOrderInfo>();
        paintContent(painter, option, istkInfo, bSelected);
    }

    painter->restore();
}

void OutStockDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const OutStockOrderInfo &istkInfo, bool bSelected) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    const int nfontSize = 14*g_widthRate;
    QFont font;
    font.setPixelSize(nfontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setPen(pen);

    // 数据编号
    const int nLeftSpace=22*g_widthRate;
    const int nFirstWidth = 140*g_widthRate;
    int nFirstXPos = xPos+nLeftSpace ;
    QRect firstRect(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect, Qt::AlignLeft | Qt::AlignVCenter, istkInfo.sOrderNum);

    // 制单人
    const int nSecondWidth = 90*g_widthRate;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    QRect secondRect(nSecondXPos, yPos, nSecondWidth, nHeight);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, istkInfo.sMaker);

    // 制单时间
    const int nThirdWidth = 150*g_widthRate;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, CommonFun::trunkDateTime(istkInfo.sMakeTime));

    // 审核人
    const int n4Width = 90*g_widthRate;
    int n4XPos = nThirdXPos + nThirdWidth;
    QRect fourRect(n4XPos, yPos, n4Width, nHeight);
    painter->drawText(fourRect, Qt::AlignLeft | Qt::AlignVCenter, istkInfo.sChecker);

    // 审核时间
    const int n5Width = 150*g_widthRate;
    int n5XPos = n4XPos + n4Width;
    QRect fiveRect(n5XPos, yPos, n5Width, nHeight);
    painter->drawText(fiveRect, Qt::AlignLeft | Qt::AlignVCenter,  CommonFun::trunkDateTime(istkInfo.sCheckTime));

    // 审核状态
    QString n6Text = QString::fromUtf8("未审核");
    if (istkInfo.nState == e_instkNoChecked)
    {
        pen.setColor(bSelected?"#ffffff":"#999999");
    }
    else
    {
        n6Text = QString::fromUtf8("已审核");
        pen.setColor(bSelected?"#ffffff":"#75ab57");
    }
    painter->setPen(pen);
    const int n6Width = 79*g_widthRate;
    int n6XPos = n5XPos + n5Width;
    QRect sixRect(n6XPos, yPos, n6Width, nHeight);
    painter->drawText(sixRect, Qt::AlignLeft | Qt::AlignVCenter, n6Text);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

OListView::OListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51*g_heightRate)
    , m_nSelectKeyId(-1)
{
    init();
}

void OListView::appendItem(const OutStockOrderInfo &istkInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(istkInfo.nOrderId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(istkInfo.nOrderId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(istkInfo.nOrderId);
    }

    QVariant variant;
    variant.setValue(istkInfo);
    pItem->setData(variant, e_OutStockInfo);

    if (m_nSelectKeyId == istkInfo.nOrderId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void OListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

int OListView::getSelectKeyId()
{
    return m_nSelectKeyId;
}

void OListView::setSelectKeyId(int nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

void OListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    OutStockOrderInfo istkInfo;
    QVariant v_itemInfo = index.data(e_OutStockInfo);
    if (v_itemInfo.canConvert<OutStockOrderInfo>())//可以转换
    {
        istkInfo = v_itemInfo.value<OutStockOrderInfo>();
        m_nSelectKeyId = istkInfo.nOrderId;
        emit sigClickItem(istkInfo);
    }
}

void OListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new OutStockDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



