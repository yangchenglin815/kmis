#include "BCSGoodsListView.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

enum ItemType
{
    e_itemInfo = Qt::UserRole + 1,
};

BCSGoodsDelegate::BCSGoodsDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void BCSGoodsDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<BCSGoodsInfo>())
    {
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
        }
        BCSGoodsInfo itemInfo = v_itemInfo.value<BCSGoodsInfo>();
        paintContent(painter, option, itemInfo, bSelected);
    }

    painter->restore();
}

void BCSGoodsDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const BCSGoodsInfo &itemInfo, bool bSelected) const
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

    const int nLeftSpace = 30;
    // 选择列
    const int checkBoxSideLenght = 16;
    int nSelectBoxXPos = xPos + nLeftSpace;
    int nSelectBoxYPos = yPos + (nHeight - checkBoxSideLenght) / 2;
    QRect selectBoxRect(nSelectBoxXPos, nSelectBoxYPos, checkBoxSideLenght, checkBoxSideLenght);
    QPixmap checkBoxPixmap;
    checkBoxPixmap.load(bSelected ? ":/orderGoodsImage/checkBoxPress.png" : ":/orderGoodsImage/checkBoxWithSide.png");
    painter->drawPixmap(selectBoxRect, checkBoxPixmap);

    // 商品名称
    // 商品名称--商品名称
    const int nFontSize2 = 12;
    const int nSecondTwoRowSpace = 6; // 商品列一二两行的间距
    const int nFirstWidth = 227;
    int nFirstXPos = nSelectBoxXPos + checkBoxSideLenght + nLeftSpace;
    int nFirstYPos = yPos + (nHeight - (nFontSize + nSecondTwoRowSpace + nFontSize2))/2;
    QRect firstRect1(nFirstXPos, nFirstYPos, nFirstWidth, nFontSize);
    painter->drawText(firstRect1, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sName);
    // 商品名称--商品编码(商品单位)
    font.setPixelSize(nFontSize2);
    painter->setFont(font);
    pen.setColor("#999999");
    painter->setPen(pen);
    nFirstYPos += nFontSize + nSecondTwoRowSpace;
    QRect firstRect2(nFirstXPos, nFirstYPos, nFirstWidth, nFontSize2);
    QString secondText = QString("%1(%2)").arg(itemInfo.sCode).arg(itemInfo.sUnit);
    painter->drawText(firstRect2, Qt::AlignLeft | Qt::AlignVCenter, secondText);
    //
    font.setPixelSize(nFontSize);
    painter->setFont(font);
    pen.setColor("#333333");
    painter->setPen(pen);

    // PLU码
    const int nSecondWidth = 144;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    QRect secondRect(nSecondXPos, yPos, nSecondWidth, nHeight);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sPlu);

    // 单价
    const int nThirdWidth = 124;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, QString("￥%1").arg(itemInfo.sPrice));

    // 会员价
    pen.setColor("#F08E58");
    painter->setPen(pen);
    const int nFourthWidth = 92;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, QString("￥%1").arg(itemInfo.sMemberPrice));

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

BCSGoodsListView::BCSGoodsListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
{
    init();
}

void BCSGoodsListView::appendItem(const BCSGoodsInfo &itemInfo)
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

    if (m_sSelectKeyIdList.contains(itemInfo.sKeyId))
    {
        this->setCurrentIndex(pItem->index());
    }
}

void BCSGoodsListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void BCSGoodsListView::appendSelectKeyIds(const QList<QString> &keyIdList)
{
    int nLen = keyIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (!m_sSelectKeyIdList.contains(keyIdList[i]))
        {
            m_sSelectKeyIdList.append(keyIdList[i]);
        }
    }
}

void BCSGoodsListView::removeSelectKeyIds(const QList<QString> &keyIdList)
{
    int nLen = keyIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        m_sSelectKeyIdList.removeOne(keyIdList[i]);
    }
}

void BCSGoodsListView::getSelectIdList(QList<QString> &keyIdList)
{
    keyIdList = m_sSelectKeyIdList;
}

void BCSGoodsListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    BCSGoodsInfo itemInfo;
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<BCSGoodsInfo>())//可以转换
    {
        itemInfo = v_itemInfo.value<BCSGoodsInfo>();
        if (m_sSelectKeyIdList.contains(itemInfo.sKeyId))
        {
            m_sSelectKeyIdList.removeOne(itemInfo.sKeyId);
        }
        else
        {
            m_sSelectKeyIdList.append(itemInfo.sKeyId);
        }
        emit sigClickItem();
    }
}

void BCSGoodsListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new BCSGoodsDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode(MultiSelection);
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



