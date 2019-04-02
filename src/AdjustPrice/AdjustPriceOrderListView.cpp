#include "AdjustPriceOrderListView.h"
#include <QPainter>
#include <QMouseEvent>
#include "../data/enumData.h"
#include "../data/constData.h"
#include "../util/CommonFun.h"

enum AdjustPriceOrderItemType
{
    e_adjustPriceOrderInfo = Qt::UserRole + 1,
};

AdjustPriceOrderDelegate::AdjustPriceOrderDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void AdjustPriceOrderDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_adjustPriceOrderInfo);
    if (v_itemInfo.canConvert<AdjustPriceOrderInfo>())
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
        AdjustPriceOrderInfo adjustPriceOrderInfo = v_itemInfo.value<AdjustPriceOrderInfo>();
        paintContent(painter, option, adjustPriceOrderInfo, bSelected);
    }

    painter->restore();
}

void AdjustPriceOrderDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const AdjustPriceOrderInfo &adjustPriceOrderInfo, bool bSelected) const
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

    // 单号
    const int nLeftSpace = 20 * g_heightRate;
    const int nFirstWidth = 234 * g_heightRate;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect, Qt::AlignLeft | Qt::AlignVCenter, adjustPriceOrderInfo.sOrderNum);

    // 制单人/审核人
    const int nSecondWidth = 128 * g_heightRate;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    QRect secondRect(nSecondXPos, yPos, nSecondWidth, nHeight);
    QString sMakerAndChecker = QString("%1/%2").arg(adjustPriceOrderInfo.sMaker).arg(adjustPriceOrderInfo.sChecker);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, sMakerAndChecker);

    // 修改时间
    const int nThirdWidth = 148 * g_heightRate;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, CommonFun::trunkDateTime(adjustPriceOrderInfo.sMakeTime));

    // 生效时间
    const int nFourthWidth = 158 * g_heightRate;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, CommonFun::trunkDateTime(adjustPriceOrderInfo.sEffectTime));

    // 状态
    QString fifthText = "";
    if (adjustPriceOrderInfo.nState == e_adjustPriceOrderNotCheck)
    {
        fifthText = QStringLiteral("未审核");
        pen.setColor(bSelected?"#ffffff":"#999999");
    }
    else
    {
        fifthText = QStringLiteral("已审核");
        pen.setColor(bSelected?"#ffffff":"#75ab57");
    }
    painter->setPen(pen);
    const int nFifthWidth = 78 * g_heightRate;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifthRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, fifthText);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

AdjustPriceOrderListView::AdjustPriceOrderListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
    , m_nSelectKeyId(-1)
{
    init();
}

void AdjustPriceOrderListView::appendItem(const AdjustPriceOrderInfo &adjustPriceOrderInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(adjustPriceOrderInfo.nOrderId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(adjustPriceOrderInfo.nOrderId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(adjustPriceOrderInfo.nOrderId);
    }

    QVariant variant;
    variant.setValue(adjustPriceOrderInfo);
    pItem->setData(variant, e_adjustPriceOrderInfo);

    if (m_nSelectKeyId == adjustPriceOrderInfo.nOrderId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void AdjustPriceOrderListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

int AdjustPriceOrderListView::getSelectKeyId()
{
    return m_nSelectKeyId;
}

void AdjustPriceOrderListView::setSelectKeyId(int nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

void AdjustPriceOrderListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    AdjustPriceOrderInfo adjustPriceOrderInfo;
    QVariant v_itemInfo = index.data(e_adjustPriceOrderInfo);
    if (v_itemInfo.canConvert<AdjustPriceOrderInfo>())//可以转换
    {
        adjustPriceOrderInfo = v_itemInfo.value<AdjustPriceOrderInfo>();
        m_nSelectKeyId = adjustPriceOrderInfo.nOrderId;
        emit sigClickItem(adjustPriceOrderInfo);
    }
}

void AdjustPriceOrderListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new AdjustPriceOrderDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



