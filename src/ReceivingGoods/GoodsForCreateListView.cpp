#include "GoodsForCreateListView.h"
#include <QPainter>
#include <QMouseEvent>

enum GoodsForCreateType
{
    e_goodsForCreate,
};

static int s_nDelButtonStartXPos = -1;
static int s_nDelButtonEndXPos = -1;

GoodsForCreateDelegate::GoodsForCreateDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
    , m_bHaveDeleteButton(false)
{

}

void GoodsForCreateDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_goodsForCreate);
    if (v_itemInfo.canConvert<GoodsForCreateInfo>())
    {
        GoodsForCreateInfo goodsForCreateInfo = v_itemInfo.value<GoodsForCreateInfo>();
        paintContent(painter, option, goodsForCreateInfo);
    }

    painter->restore();
}

void GoodsForCreateDelegate::setHaveDeleteButtonFlag(bool bHave)
{
    m_bHaveDeleteButton = bHave;
}

void GoodsForCreateDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const GoodsForCreateInfo &goodsForCreateInfo) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();

    const int nFirstRowFontSize = 14;
    const int nSecondFontSize = 12;
    const int nTwoRowSpace = 5;

    QFont font;
    font.setPixelSize(nFirstRowFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#333333");
    painter->setPen(pen);

    const int nLeftSpace = 12;
    const int nTopSpace = (nHeight - (nFirstRowFontSize + nSecondFontSize + nTwoRowSpace)) / 2;
    int nFirstRowXPos = xPos + nLeftSpace;
    int nFirstRowYPos = yPos + nTopSpace;
    QRect firstRowRect(nFirstRowXPos, nFirstRowYPos, nWidth, nFirstRowFontSize);
    painter->drawText(firstRowRect, Qt::AlignLeft | Qt::AlignVCenter, goodsForCreateInfo.sGoodName);

    font.setPixelSize(nSecondFontSize);
    painter->setFont(font);
    pen.setColor("#999999");
    painter->setPen(pen);
    int nSecondRowXPos = nFirstRowXPos;
    int nSecondRowYPos = nFirstRowYPos + nFirstRowFontSize + nTwoRowSpace;
    QRect secondRowRect(nSecondRowXPos, nSecondRowYPos, nWidth, nSecondFontSize);
    QString sSecondText = QString("%1(%2/%3)").arg(goodsForCreateInfo.sGoodsCode)
            .arg(goodsForCreateInfo.sUnitSpecification).arg(goodsForCreateInfo.sSpecification);
    painter->drawText(secondRowRect, Qt::AlignLeft | Qt::AlignVCenter, sSecondText);

    if (m_bHaveDeleteButton)
    {
        // 删除
        const int nEighthWidth = 44;
        const int nPictureHeight = 32;
        const int nRightSpace = 12;
        int nEightXPos = nWidth - nEighthWidth - nRightSpace;
        int nPictureYPos = yPos + (nHeight - nPictureHeight) / 2;
        QRect pictrueRect(nEightXPos, nPictureYPos, nEighthWidth, nPictureHeight);
        QPixmap buttonPicture(":/receivingGoodsImage/redRect.png");
        painter->drawPixmap(pictrueRect, buttonPicture.scaled(nEighthWidth, nPictureHeight));
        s_nDelButtonStartXPos = nEightXPos;
        s_nDelButtonEndXPos = nEightXPos + nEighthWidth;

        // 图片文字
        pen.setColor("#ffffff");
        painter->setPen(pen);
        int nOffY = 2;
        QRect pictureTextRect(nEightXPos, yPos - nOffY, nEighthWidth, nHeight);
        QString pictureText = QStringLiteral("删除");
        painter->drawText(pictureTextRect, Qt::AlignCenter, pictureText);
    }

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

GoodsForCreateListView::GoodsForCreateListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(50)
    , m_pGoodsForCreateDelegate(NULL)
{
    init();
}

void GoodsForCreateListView::appendItem(const GoodsForCreateInfo &goodsForCreateInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(goodsForCreateInfo.nGoodsId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(goodsForCreateInfo.nGoodsId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(goodsForCreateInfo.nGoodsId);
    }

    QVariant variant;
    variant.setValue(goodsForCreateInfo);
    pItem->setData(variant, e_goodsForCreate);
}

void GoodsForCreateListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void GoodsForCreateListView::setItemHeight(int nHeight)
{
    Q_UNUSED( nHeight )
    m_nItemHeight = 50;
}

void GoodsForCreateListView::setHaveDeleteButtonFlag(bool bHave)
{
    if (m_pGoodsForCreateDelegate != NULL)
    {
        m_pGoodsForCreateDelegate->setHaveDeleteButtonFlag(bHave);
    }
}

void GoodsForCreateListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    GoodsForCreateInfo goodsForCreateInfo;
    QVariant v_itemInfo = index.data(e_goodsForCreate);
    if (v_itemInfo.canConvert<GoodsForCreateInfo>())//可以转换
    {
        goodsForCreateInfo = v_itemInfo.value<GoodsForCreateInfo>();
        int nPosX = event->pos().x();
        if ((nPosX >= s_nDelButtonStartXPos) && (nPosX <= s_nDelButtonEndXPos))
        {
            emit sigDeleteItem(goodsForCreateInfo.nGoodsId);
        }
        else
        {
            emit sigClickSearchItem(goodsForCreateInfo.nGoodsId);
        }
    }
}

void GoodsForCreateListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pGoodsForCreateDelegate = new GoodsForCreateDelegate(this);
    setItemDelegateForColumn(0, m_pGoodsForCreateDelegate);
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


