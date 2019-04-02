#include "ReceiveOrderGoodsListView.h"
#include <QPainter>
#include <QMouseEvent>
#include "../util/EnumToString.h"
#include "../data/enumData.h"

enum ReceiveOrderGoodsType
{
    e_receiveOrderGoods,
};

static int s_nOperateButtonStartXPos = -1;
static int s_nOperateButtonEndXPos = -1;
static bool s_bFinishedReceiveOrder = false;

ReceiveOrderGoodsDelegate::ReceiveOrderGoodsDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void ReceiveOrderGoodsDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_receiveOrderGoods);
    if (v_itemInfo.canConvert<ReceiveOrderGoodsInfo>())
    {
        ReceiveOrderGoodsInfo receiveOrderGoodsInfo = v_itemInfo.value<ReceiveOrderGoodsInfo>();
        paintFirstColumn(painter, option, receiveOrderGoodsInfo);
        paintOtherColumn(painter, option, receiveOrderGoodsInfo);
    }

    painter->restore();
}

void ReceiveOrderGoodsDelegate::paintFirstColumn(QPainter *painter, const QStyleOptionViewItem &option
                                                 , const ReceiveOrderGoodsInfo &receiveOrderGoodsInfo) const
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

    // 商品--商品名称
    const int nLeftSpace = 20;
    const int nTopSpace = 8;
    int nFirstRowXPos = xPos + nLeftSpace;
    int nFirstRowYPos = yPos + nTopSpace;
    QRect firstRowRect(nFirstRowXPos, nFirstRowYPos, nWidth, nFirstRowFontSize);
    painter->drawText(firstRowRect, Qt::AlignLeft | Qt::AlignVCenter, receiveOrderGoodsInfo.sGoodName);
    // 商品--商品编码(商品单位)
    const int nSecondFontSize = 12;
    const int nTwoRowSpace = 5;
    font.setPixelSize(nSecondFontSize);
    painter->setFont(font);
    pen.setColor("#999999");
    painter->setPen(pen);
    int nSecondRowXPos = nFirstRowXPos;
    int nSecondRowYPos = nFirstRowYPos + nFirstRowFontSize + nTwoRowSpace;
    QRect secondRowRect(nSecondRowXPos, nSecondRowYPos, nWidth, nSecondFontSize);
    QString sSecondText = QString("%1(%2)").arg(receiveOrderGoodsInfo.sGoodsCode).arg(receiveOrderGoodsInfo.sUnitSpecification);
    painter->drawText(secondRowRect, Qt::AlignLeft | Qt::AlignVCenter, sSecondText);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

void ReceiveOrderGoodsDelegate::paintOtherColumn(QPainter *painter, const QStyleOptionViewItem &option,
                                                 const ReceiveOrderGoodsInfo &receiveOrderGoodsInfo) const
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

    // 应收件数/数量
    int nLeftSpace = 248;
    if (s_bFinishedReceiveOrder)
    {
        nLeftSpace = 313;
    }
    int nSecondColXPos = xPos + nLeftSpace;
    int nSecondColWidth = 117;
    if (s_bFinishedReceiveOrder)
    {
        nSecondColWidth = 137;
    }
    QRect secondColRect(nSecondColXPos, yPos, nSecondColWidth, nHeight);
    QString sSecondText = "";
    if ((receiveOrderGoodsInfo.nNeedReceiveSumNum >= 0) && (receiveOrderGoodsInfo.fNeedReceiveSumValue >= 0))
    {
        sSecondText.sprintf("%d/%.2f", receiveOrderGoodsInfo.nNeedReceiveSumNum, receiveOrderGoodsInfo.fNeedReceiveSumValue);
    }
    else if (receiveOrderGoodsInfo.fNeedReceiveSumValue >= 0)
    {
        sSecondText.sprintf("%.2f", receiveOrderGoodsInfo.fNeedReceiveSumValue);
    }
    painter->drawText(secondColRect, Qt::AlignLeft | Qt::AlignVCenter, sSecondText);
    painter->setPen(pen);

    // 实收件数/数量
    int nThirdWidth = 110;
    if (s_bFinishedReceiveOrder)
    {
        nThirdWidth = 115;
    }
    int nThirdColXPos = nSecondColXPos + nSecondColWidth;
    QRect thirdColRect(nThirdColXPos, yPos, nThirdWidth, nHeight);
    QString sThirdText = "";
    if ((receiveOrderGoodsInfo.nRealReceiveSumNum >= 0) && (receiveOrderGoodsInfo.fRealReceiveSumValue >= 0))
    {
        sThirdText.sprintf("%d/%.2f", receiveOrderGoodsInfo.nRealReceiveSumNum, receiveOrderGoodsInfo.fRealReceiveSumValue);
    }
    else if (receiveOrderGoodsInfo.fRealReceiveSumValue >= 0)
    {
        sThirdText.sprintf("%.2f", receiveOrderGoodsInfo.fRealReceiveSumValue);
    }
    painter->drawText(thirdColRect, Qt::AlignLeft | Qt::AlignVCenter, sThirdText);

    // 收货金额
    int nFourthColWidth = 100;
    if (s_bFinishedReceiveOrder)
    {
        nFourthColWidth = 106;
    }
    int nFourthColXPos = nThirdColXPos + nThirdWidth;
    QRect fourthColRect(nFourthColXPos, yPos, nFourthColWidth, nHeight);
    QString sFourthText;
    sFourthText.sprintf("%.2f", receiveOrderGoodsInfo.fSumPrice);
    painter->drawText(fourthColRect, Qt::AlignLeft | Qt::AlignVCenter, sFourthText);

    // 状态
    int nFifthWidth = 102;
    if (s_bFinishedReceiveOrder)
    {
        nFifthWidth = 70;
    }
    int nFifthColXPos = nFourthColXPos + nFourthColWidth;
    QRect fifthColRect(nFifthColXPos, yPos, nFifthWidth, nHeight);
    QString sFifthText;
    if (receiveOrderGoodsInfo.bGoodsRecieveFinish)
    {
        sFifthText = QStringLiteral("已完成");
    }
    else
    {
        sFifthText = QStringLiteral("未收货");
    }
    setStateTextPainter(painter, pen, receiveOrderGoodsInfo.bGoodsRecieveFinish);
    painter->drawText(fifthColRect, Qt::AlignLeft | Qt::AlignVCenter, sFifthText);
    pen.setColor("#333333");
    painter->setPen(pen); // 恢复画笔颜色

    if (!s_bFinishedReceiveOrder)
    {
        // 操作
        // 图片
        const int nSixthWidth = 61;
        const int nPictureHeight = 28;
        int nSixthXPos = nFifthColXPos + nFifthWidth;
        int nPictureYPos = yPos + (nHeight - nPictureHeight) / 2;
        QRect pictrueRect(nSixthXPos, nPictureYPos, nSixthWidth, nPictureHeight);
        QPixmap buttonPicture;
        if (receiveOrderGoodsInfo.bGoodsRecieveFinish)
        {
            buttonPicture.load(":/receivingGoodsImage/blueRect.png");
        }
        else
        {
            buttonPicture.load(":/receivingGoodsImage/orangeRect.png");
        }
        painter->drawPixmap(pictrueRect, buttonPicture.scaled(nSixthWidth, nPictureHeight));
        s_nOperateButtonStartXPos = nSixthXPos;
        s_nOperateButtonEndXPos = nSixthXPos + nSixthWidth;

        // 图片文字
        pen.setColor("#ffffff");
        painter->setPen(pen);
        int nOffY = 2;
        QRect pictureTextRect(nSixthXPos, yPos - nOffY, nSixthWidth, nHeight);
        QString pictureText;
        if (receiveOrderGoodsInfo.bGoodsRecieveFinish)
        {
            pictureText = QStringLiteral("修改");
        }
        else
        {
            pictureText = QStringLiteral("收货");
        }

        painter->drawText(pictureTextRect, Qt::AlignCenter, pictureText);
    }
    else
    {
        s_nOperateButtonStartXPos = -1;
        s_nOperateButtonEndXPos = -1;
    }
}

void ReceiveOrderGoodsDelegate::setStateTextPainter(QPainter *painter, QPen &pen, bool bSave) const
{
    if (bSave) // 已完成
    {
        pen.setColor("#75ab57");
    }
    else // 未收货
    {
        pen.setColor("#999999");
    }
    painter->setPen(pen);
}

ReceiveOrderGoodsListView::ReceiveOrderGoodsListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
{
    init();
}

void ReceiveOrderGoodsListView::appendItem(const ReceiveOrderGoodsInfo &receiveOrderGoodsInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(receiveOrderGoodsInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(receiveOrderGoodsInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(receiveOrderGoodsInfo.nId);
    }

    QVariant variant;
    variant.setValue(receiveOrderGoodsInfo);
    pItem->setData(variant, e_receiveOrderGoods);
}

void ReceiveOrderGoodsListView::clearItems()
{
    if (m_pStandardItemModel != NULL)
    {
        m_pStandardItemModel->clear();
    }
    m_ItemKeyIdMap.clear();
}

bool ReceiveOrderGoodsListView::isExistReceiveOrderGoods(int nId)
{
    return m_ItemKeyIdMap.contains(nId);
}

void ReceiveOrderGoodsListView::setFinishFlag(bool isFinished)
{
    s_bFinishedReceiveOrder = isFinished;
}

void ReceiveOrderGoodsListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    ReceiveOrderGoodsInfo receiveOrderGoodsInfo;
    QVariant v_itemInfo = index.data(e_receiveOrderGoods);
    if (v_itemInfo.canConvert<ReceiveOrderGoodsInfo>())//可以转换
    {
        receiveOrderGoodsInfo = v_itemInfo.value<ReceiveOrderGoodsInfo>();
        int nXPos = event->pos().x();
        if ((nXPos >= s_nOperateButtonStartXPos) &&
                (nXPos <= s_nOperateButtonEndXPos))
        {
            emit sigReceiveOrderGoodsDetail(receiveOrderGoodsInfo.nId);
        }
    }
}

void ReceiveOrderGoodsListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new ReceiveOrderGoodsDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


