#include "BCSGroupManageRightListView.h"
#include "../data/constData.h"
#include <QPainter>
#include <QMouseEvent>

enum ItemType
{
    e_itemInfo = Qt::UserRole + 1,
};

BCSGroupManageRightDelegate::BCSGroupManageRightDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void BCSGroupManageRightDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<BCSGroupManageRightInfo>())
    {
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
//            QRect rect = option.rect;
//            rect.setX(rect.x() + 1);
//            rect.setWidth(rect.width() - 2);
//            painter->fillRect(rect, QBrush(QColor(c_sThemeColor)));
        }
        BCSGroupManageRightInfo itemInfo = v_itemInfo.value<BCSGroupManageRightInfo>();
        paintContent(painter, option, itemInfo, bSelected);
    }

    painter->restore();
}

void BCSGroupManageRightDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const BCSGroupManageRightInfo &itemInfo, bool bSelected) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    const int nFontSize = 14;
    QFont font;
    font.setPixelSize(nFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#333333");
    painter->setPen(pen);

    // 序号
    const int nLeftSpace = 24;
    const int nFirstWidth = 64;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sSeq);

    // 商品名称
    // 商品名称--商品名称
    const int nFontSize2 = 12;
    const int nSecondTwoRowSpace = 6; // 商品列一二两行的间距
    const int nSecondWidth = 200;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    int nSecondYPos = yPos + (nHeight - (nFontSize + nSecondTwoRowSpace + nFontSize2))/2;
    QRect secondRect1(nSecondXPos, nSecondYPos, nSecondWidth, nFontSize);
    painter->drawText(secondRect1, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sGoodsName);
    // 商品名称--商品编码(商品单位)
    font.setPixelSize(nFontSize2);
    painter->setFont(font);
    pen.setColor("#999999");
    painter->setPen(pen);
    nSecondYPos += nFontSize + nSecondTwoRowSpace;
    QRect secondRect2(nSecondXPos, nSecondYPos, nSecondWidth, nFontSize2);
    QString secondText = QString("%1(%2)").arg(itemInfo.sGoodsCode).arg(itemInfo.sGoodsUnit);
    painter->drawText(secondRect2, Qt::AlignLeft | Qt::AlignVCenter, secondText);
    //
    font.setPixelSize(nFontSize);
    painter->setFont(font);
    pen.setColor("#333333");
    painter->setPen(pen);

    // PLU码
    const int nThirdWidth = 106;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sGoodsPlu);

    // 原价/会员价
    const int nFourthWidth = 130;
    int nFourthPriceXPos = nThirdXPos + nThirdWidth;
    QRect fourthPriceRect(nFourthPriceXPos, yPos, nFourthWidth, nHeight);
    QString sGoodsPrice = QString("￥%1/￥%2").arg(itemInfo.sGoodsPrice).arg(itemInfo.sGoodsMemberPrice);
    painter->drawText(fourthPriceRect, Qt::AlignLeft | Qt::AlignVCenter, sGoodsPrice);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

BCSGroupManageRightListView::BCSGroupManageRightListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(44)
    , m_sSelectKeyId("")
{
    init();
}

void BCSGroupManageRightListView::appendItem(const BCSGroupManageRightInfo &itemInfo)
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

void BCSGroupManageRightListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

QString BCSGroupManageRightListView::getSelectKeyId()
{
    return m_sSelectKeyId;
}

void BCSGroupManageRightListView::setSelectKeyId(QString sKeyId)
{
    m_sSelectKeyId = sKeyId;
}

void BCSGroupManageRightListView::getSelectItemInfo(BCSGroupManageRightInfo &itemInfo)
{
    itemInfo = m_selectItemInfo;
}

int BCSGroupManageRightListView::getSelectSeq()
{
    if (m_sSelectKeyId.isEmpty())
    {
        return -1;
    }
    return m_selectItemInfo.sSeq.toInt();
}

void BCSGroupManageRightListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    BCSGroupManageRightInfo itemInfo;
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<BCSGroupManageRightInfo>())//可以转换
    {
        itemInfo = v_itemInfo.value<BCSGroupManageRightInfo>();
        m_sSelectKeyId = itemInfo.sKeyId;
        m_selectItemInfo = itemInfo;
        emit sigClickItem(itemInfo);
    }
}

void BCSGroupManageRightListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new BCSGroupManageRightDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



