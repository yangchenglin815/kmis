#include "AdjustPriceOrderSearchListView.h"
#include <QPainter>
#include <QMouseEvent>
#include "../data/constData.h"

enum AdjustPriceOrderSearchItemType
{
    e_adjustPriceOrderSearchInfo = Qt::UserRole + 1,
};

AdjustPriceOrderSearchDelegate::AdjustPriceOrderSearchDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void AdjustPriceOrderSearchDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_adjustPriceOrderSearchInfo);
    if (v_itemInfo.canConvert<AdjustPriceOrderSearchInfo>())
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
        AdjustPriceOrderSearchInfo adjustPriceOrderSearchInfo = v_itemInfo.value<AdjustPriceOrderSearchInfo>();
        paintContent(painter, option, adjustPriceOrderSearchInfo, bSelected);
    }

    painter->restore();
}

void AdjustPriceOrderSearchDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const AdjustPriceOrderSearchInfo &orderSearchInfo, bool bSelected) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    const int nfontSize = 14 * g_heightRate;
    QFont font;
    font.setPixelSize(nfontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setPen(pen);

    // 序号
    const int nLeftSpace = 20 * g_heightRate;
    const int nFirstWidth = 52 * g_heightRate;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect, Qt::AlignLeft | Qt::AlignVCenter, orderSearchInfo.sSeq);

    // 商品
    const int nSecondWidth = 232 * g_heightRate;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    const int nVSpace = 4 * g_heightRate;
    const int nBarCodefontSize = 12 * g_heightRate;
    // 商品--商品名称
    int nSecondYPos = yPos + (nHeight - (nfontSize+nVSpace+nBarCodefontSize))/2 ;
    QRect secondFirstRect(nSecondXPos, nSecondYPos, nSecondWidth, nfontSize);

    QString strName = "";
    if( orderSearchInfo.sShortName.isEmpty() ) {
        strName = orderSearchInfo.sName;
    } else {
        strName = orderSearchInfo.sShortName;
    }
    painter->drawText(secondFirstRect, Qt::AlignLeft | Qt::AlignVCenter, strName );
    // 商品--商品条码
    font.setPixelSize(nBarCodefontSize);
    pen.setColor(bSelected?"#ffffff":"#999999");
    painter->setFont(font);
    painter->setPen(pen);
    nSecondYPos += (nfontSize + nVSpace);
    QRect secondSecondRect(nSecondXPos, nSecondYPos, nSecondWidth, nBarCodefontSize);
    painter->drawText(secondSecondRect, Qt::AlignLeft | Qt::AlignVCenter, orderSearchInfo.sCode);
    font.setPixelSize(nfontSize);
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setFont(font);
    painter->setPen(pen);

    // 原售价
    const int nThirdWidth = 132 * g_heightRate;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(orderSearchInfo.fOldPrice, 'f', 2));

    // 现售价
    const int nFourthWidth = 120 * g_heightRate;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    pen.setColor(bSelected?"#ffffff":"#ea8852");
    painter->setPen(pen);
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(orderSearchInfo.fNowPrice, 'f', 2));
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setPen(pen);

    // 原会员价
    const int nFifthWidth = 132 * g_heightRate;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifthRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(orderSearchInfo.fOldMemberPrice, 'f', 2));

    // 现会员价
    const int nSixthWidth = 78 * g_heightRate;
    int nSixthXPos = nFifthXPos + nFifthWidth;
    pen.setColor(bSelected?"#ffffff":"#ea8852");
    painter->setPen(pen);
    QRect sixthRect(nSixthXPos, yPos, nSixthWidth, nHeight);
    painter->drawText(sixthRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(orderSearchInfo.fNowMemberPrice, 'f', 2));

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

AdjustPriceOrderSearchListView::AdjustPriceOrderSearchListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
    , m_nSelectKeyId(-1)
{
    init();
}

void AdjustPriceOrderSearchListView::appendItem(const AdjustPriceOrderSearchInfo &searchInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(searchInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(searchInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(searchInfo.nId);
    }

    QVariant variant;
    variant.setValue(searchInfo);
    pItem->setData(variant, e_adjustPriceOrderSearchInfo);

    if (m_nSelectKeyId == searchInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void AdjustPriceOrderSearchListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void AdjustPriceOrderSearchListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    AdjustPriceOrderSearchInfo orderSearchInfo;
    QVariant v_itemInfo = index.data(e_adjustPriceOrderSearchInfo);
    if (v_itemInfo.canConvert<AdjustPriceOrderSearchInfo>())//可以转换
    {
        orderSearchInfo = v_itemInfo.value<AdjustPriceOrderSearchInfo>();
        m_nSelectKeyId = orderSearchInfo.nId;
    }
}

void AdjustPriceOrderSearchListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new AdjustPriceOrderSearchDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


