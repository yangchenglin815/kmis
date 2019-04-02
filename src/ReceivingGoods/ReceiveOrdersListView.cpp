#include "ReceiveOrdersListView.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "../util/EnumToString.h"
#include "../data/enumData.h"

static int s_nOperateButtonStartXPos = -1;
static int s_nOperateButtonEndXPos = -1;

enum RecieveOrdersType
{
    e_receiveOrders
};

ReceiveOrdersDelegate::ReceiveOrdersDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void ReceiveOrdersDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_receiveOrders);
    if (v_itemInfo.canConvert<ReceiveOrderInfo>())
    {
        ReceiveOrderInfo receiveGoodsInfo = v_itemInfo.value<ReceiveOrderInfo>();
        paintFirstColumn(painter, option, receiveGoodsInfo);
        paintOtherColumn(painter, option, receiveGoodsInfo);
    }

    painter->restore();
}

void ReceiveOrdersDelegate::paintFirstColumn(QPainter *painter, const QStyleOptionViewItem &option,
                                            const ReceiveOrderInfo &receiveGoodsInfo) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();

    const int nFirstRowFontSize = 14;
    QFont font;
    font.setPixelSize(nFirstRowFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#333333");
    painter->setPen(pen);

    const int nLeftSpace = 20;
    const int nTopSpace = 8;
    int nFirstRowXPos = xPos + nLeftSpace;
    int nFirstRowYPos = yPos + nTopSpace;
    QRect firstRowRect(nFirstRowXPos, nFirstRowYPos, nWidth, nFirstRowFontSize);
    painter->drawText(firstRowRect, Qt::AlignLeft | Qt::AlignVCenter, receiveGoodsInfo.sProviderName);

    if (receiveGoodsInfo.nRecieveState == e_RecieveOrderDoing)
    {
        int nFistRowTextWidth = painter->fontMetrics().width(receiveGoodsInfo.sProviderName);
        const int nEditPicWidth = 11;
        const int nEditPicHeight = 13;
        int offXSpace = 4;
        int nEditPicXPos = nFirstRowXPos + nFistRowTextWidth + offXSpace;
        int nEditPicYPos = nFirstRowYPos + (nFirstRowFontSize - nEditPicHeight);
        QPixmap editPicPixmap(":/receivingGoodsImage/editing.png");
        QRect eiditPicRect(nEditPicXPos, nEditPicYPos, nEditPicWidth, nEditPicHeight);
        painter->drawPixmap(eiditPicRect, editPicPixmap);
    }

    const int nSecondFontSize = 12;
    const int nTwoRowSpace = 5;
    font.setPixelSize(nSecondFontSize);
    painter->setFont(font);
    pen.setColor("#999999");
    painter->setPen(pen);
    int nSecondRowXPos = nFirstRowXPos;
    int nSecondRowYPos = nFirstRowYPos + nFirstRowFontSize + nTwoRowSpace;
    QRect secondRowRect(nSecondRowXPos, nSecondRowYPos, nWidth, nSecondFontSize);
    painter->drawText(secondRowRect, Qt::AlignLeft | Qt::AlignVCenter, receiveGoodsInfo.sProviderCode);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

void ReceiveOrdersDelegate::paintOtherColumn(QPainter *painter, const QStyleOptionViewItem &option,
                                            const ReceiveOrderInfo &receiveGoodsInfo) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
//    int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    const int nFirstRowFontSize = 14;
    QFont font;
    font.setPixelSize(nFirstRowFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#333333");
    painter->setPen(pen);

    // 单号
    const int nLeftSpace = 158;
    int nSecondColXPos = xPos + nLeftSpace;
    int nSecondColWidth = 118;
    QRect secondColRect(nSecondColXPos, yPos, nSecondColWidth, nHeight);
    painter->drawText(secondColRect, Qt::AlignLeft | Qt::AlignVCenter, receiveGoodsInfo.sCode);
    pen.setColor("#333333");
    painter->setPen(pen);

    // 应收件数/数量
    int nThirdWidth = 91;
    int nThirdColXPos = nSecondColXPos + nSecondColWidth;
    QRect thirdColRect(nThirdColXPos, yPos, nThirdWidth, nHeight);
    QString sThirdText = "";
    if (receiveGoodsInfo.nNeedReceiveSumNum >= 0 && receiveGoodsInfo.fNeedReceiveSumValue >= 0)
    {
        sThirdText.sprintf("%d/%.2f", receiveGoodsInfo.nNeedReceiveSumNum, receiveGoodsInfo.fNeedReceiveSumValue);
    }
    else if (receiveGoodsInfo.fNeedReceiveSumValue >= 0)
    {
        sThirdText.sprintf("%.2f", receiveGoodsInfo.fNeedReceiveSumValue);
    }

    painter->drawText(thirdColRect, Qt::AlignLeft | Qt::AlignVCenter, sThirdText);

    // 实收件数/数量
    int nFourthColWidth = 93;
    int nFourthColXPos = nThirdColXPos + nThirdWidth;
    QRect fourthColRect(nFourthColXPos, yPos, nFourthColWidth, nHeight);
    QString sFourthText;
    if (receiveGoodsInfo.nRealReceiveSumNum >= 0 && receiveGoodsInfo.fRealReceiveSumValue >= 0)
    {
        sFourthText.sprintf("%d/%.2f", receiveGoodsInfo.nRealReceiveSumNum, receiveGoodsInfo.fRealReceiveSumValue);
    }
    else if (receiveGoodsInfo.fRealReceiveSumValue >= 0)
    {
        sFourthText.sprintf("%.2f", receiveGoodsInfo.fRealReceiveSumValue);
    }
    painter->drawText(fourthColRect, Qt::AlignLeft | Qt::AlignVCenter, sFourthText);

    // 金额
    int nFifthWidth = 64;
    int nFifthColXPos = nFourthColXPos + nFourthColWidth;
    QRect fifthColRect(nFifthColXPos, yPos, nFifthWidth, nHeight);
    QString sFifthText;
    sFifthText.sprintf("%.2f", receiveGoodsInfo.fSumPrice);
    painter->drawText(fifthColRect, Qt::AlignLeft | Qt::AlignVCenter, sFifthText);

    // 上传时间
    int nSixColWidth = 90;
    int nSixColXPos = nFifthColXPos + nFifthWidth;
    QRect sixColRect(nSixColXPos, yPos, nSixColWidth, nHeight);
    painter->drawText(sixColRect, Qt::AlignLeft | Qt::AlignVCenter, receiveGoodsInfo.sUploadDate);

    // 状态
    int nSevenColWidth = 70;
    int nSevenColXPos = nSixColXPos + nSixColWidth;
    QRect seventColRect(nSevenColXPos, yPos, nSevenColWidth, nHeight);
    QString sSevenText = EnumToString::recieveGoodsStateToString(receiveGoodsInfo.nRecieveState);
    setStateTextPainter(painter, pen, receiveGoodsInfo.nRecieveState);
    painter->drawText(seventColRect, Qt::AlignLeft | Qt::AlignVCenter, sSevenText);
    pen.setColor("#333333");
    painter->setPen(pen); // 恢复画笔颜色

    // 操作
    // 图片
    const int nEighthWidth = 61;
    const int nPictureHeight = 28;
    int nEightXPos = nSevenColXPos + nSevenColWidth;
    int nPictureYPos = yPos + (nHeight - nPictureHeight) / 2;
    QRect pictrueRect(nEightXPos, nPictureYPos, nEighthWidth, nPictureHeight);
    QPixmap buttonPicture(":/receivingGoodsImage/orangeRect.png");
    painter->drawPixmap(pictrueRect, buttonPicture.scaled(nEighthWidth, nPictureHeight));
    s_nOperateButtonStartXPos = nEightXPos;
    s_nOperateButtonEndXPos = nEightXPos + nEighthWidth;

    // 图片文字
    pen.setColor("#ffffff");
    painter->setPen(pen);
    int nOffY = 2;
    QRect pictureTextRect(nEightXPos, yPos - nOffY, nEighthWidth, nHeight);
    QString pictureText;
    pictureText = QStringLiteral("查看");
    painter->drawText(pictureTextRect, Qt::AlignCenter, pictureText);
}

void ReceiveOrdersDelegate::setStateTextPainter(QPainter *painter, QPen &pen, int nState) const
{
    if (nState == e_RecieveOrderFinish) // 已完成
    {
        pen.setColor("#75ab57");
    }
    else if (nState == e_RecieveOrderDoing) // 收货中
    {
        pen.setColor("#fa7a7a");
    }
    else if (nState == e_RecieveOrderNotStart) // 未收货
    {
        pen.setColor("#999999");
    }
    painter->setPen(pen);
}

ReceiveOrdersListView::ReceiveOrdersListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
{
    init();
}

void ReceiveOrdersListView::appendItem(const ReceiveOrderInfo &receiveOrderInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(receiveOrderInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(receiveOrderInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(receiveOrderInfo.nId);
    }

    QVariant variant;
    variant.setValue(receiveOrderInfo);
    pItem->setData(variant, e_receiveOrders);
}

void ReceiveOrdersListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

bool ReceiveOrdersListView::isExistReceiveOrder(int nOrderId)
{
    return m_ItemKeyIdMap.contains(nOrderId);
}

void ReceiveOrdersListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    ReceiveOrderInfo receiveGoodsInfo;
    QVariant v_itemInfo = index.data(e_receiveOrders);
    if (v_itemInfo.canConvert<ReceiveOrderInfo>())//可以转换
    {
        receiveGoodsInfo = v_itemInfo.value<ReceiveOrderInfo>();
        int nXPos = event->pos().x();
        if ((nXPos >= s_nOperateButtonStartXPos) &&
                (nXPos <= s_nOperateButtonEndXPos))
        {
            emit sigCheckReceiveOrder(receiveGoodsInfo.nId);
        }
    }
}

void ReceiveOrdersListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new ReceiveOrdersDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


