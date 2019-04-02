#include "BCSManageListView.h"
#include "EnumToString.h"
#include "../data/constData.h"
#include <QPainter>
#include <QMouseEvent>

enum ItemType
{
    e_itemInfo = Qt::UserRole + 1,
};

BCSManageDelegate::BCSManageDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void BCSManageDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<BarCodeScaleInfo>())
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
        BarCodeScaleInfo itemInfo = v_itemInfo.value<BarCodeScaleInfo>();
        paintContent(painter, option, itemInfo, bSelected);
    }

    painter->restore();
}

void BCSManageDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const BarCodeScaleInfo &itemInfo, bool bSelected) const
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
    const int nLeftSpace = 20;
    const int nFirstWidth = 44;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sSeq);

    // 编号
    const int nSecondWidth = 65;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    QRect secondRect(nSecondXPos, yPos, nSecondWidth, nHeight);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sCode);

    // 型号
    const int nThirdWidth = 133;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sModel);

    // IP
    const int nFourthWidth = 170;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sIP);

    // 关联商品组
    const int nFifthWidth = 129;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifthRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sGoodsGroupName);

    // 上次下发时间
    const int nSixthWidth = 142;
    int nSixthXPos = nFifthXPos + nFifthWidth;
    QRect sixthRect(nSixthXPos, yPos, nSixthWidth, nHeight);
    painter->drawText(sixthRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sSendDownTime);

    // 状态
    const int nSeventhWidth = 69;
    int nSeventhXPos = nSixthXPos + nSixthWidth;
    QRect seventhRect(nSeventhXPos, yPos, nSeventhWidth, nHeight);
    setStateTextPainter(painter, pen, itemInfo.nState);
    painter->drawText(seventhRect, Qt::AlignLeft | Qt::AlignVCenter, EnumToString::bcsLinkStateToString(itemInfo.nState));

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

void BCSManageDelegate::setStateTextPainter(QPainter *painter, QPen &pen, int nState) const
{
    if (nState == e_bcsLink)
    {
        pen.setColor("#75AB57");
    }
    else if (nState == e_bcsOffLink)
    {
        pen.setColor("#EA8852");
    }
    else if (nState == e_bcsForbidLink)
    {
        pen.setColor("#A3A3A3");
    }
    painter->setPen(pen);
}

BCSManageListView::BCSManageListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
    , m_sSelectKeyId("")
{
    init();
}

void BCSManageListView::appendItem(const BarCodeScaleInfo &itemInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(itemInfo.sKeyId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(itemInfo.sKeyId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(itemInfo.sKeyId);
    }

    QVariant variant;
    variant.setValue(itemInfo);
    pItem->setData(variant, e_itemInfo);

    if (m_sSelectKeyId == itemInfo.sKeyId)
    {
        m_selectItemInfo = itemInfo;
        this->setCurrentIndex(pItem->index());
    }
}

void BCSManageListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

QString BCSManageListView::getSelectKeyId()
{
//    if (!m_ItemKeyIdMap.contains(m_sSelectKeyId))
//    {
//        m_sSelectKeyId = "";
//    }
    return m_sSelectKeyId;
}

void BCSManageListView::setSelectKeyId(QString sKeyId)
{
    m_sSelectKeyId = sKeyId;
}

void BCSManageListView::getSelectItemInfo(BarCodeScaleInfo &itemInfo)
{
//    if (!m_ItemKeyIdMap.contains(m_sSelectKeyId))
//    {
//        m_sSelectKeyId = "";
//        bcsInfo.sKeyId = "";
//        return;
//    }
    itemInfo = m_selectItemInfo;
}

int BCSManageListView::getSelectSeq()
{
    if (m_sSelectKeyId.isEmpty())
    {
        return -1;
    }
    return m_selectItemInfo.sSeq.toInt();
}

void BCSManageListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    BarCodeScaleInfo itemInfo;
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<BarCodeScaleInfo>())//可以转换
    {
        itemInfo = v_itemInfo.value<BarCodeScaleInfo>();
        m_sSelectKeyId = itemInfo.sKeyId;
        m_selectItemInfo = itemInfo;
        emit sigClickItem(itemInfo);
    }
}

void BCSManageListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new BCSManageDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



