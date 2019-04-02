#include "BCSRelateDlgListView.h"
#include "../data/constData.h"
#include "../util/EnumToString.h"
#include <QPainter>
#include <QMouseEvent>

enum ItemType
{
    e_itemInfo = Qt::UserRole + 1,
};

CSRelateDlgListView::CSRelateDlgListView(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void CSRelateDlgListView::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<BarCodeScaleInfo>())
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
        BarCodeScaleInfo itemInfo = v_itemInfo.value<BarCodeScaleInfo>();
        paintContent(painter, option, itemInfo, bSelected);
    }

    painter->restore();
}

void CSRelateDlgListView::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const BarCodeScaleInfo &itemInfo, bool bSelected) const
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
    pen.setColor("#333333");
    painter->setPen(pen);

    const int nLeftSpace = 30;
    //选择列
    const int checkBoxSideLenght = 16;
    int nSelectBoxXPos = xPos + nLeftSpace;
    int nSelectBoxYPos = yPos + (nHeight - checkBoxSideLenght) / 2;
    QRect selectBoxRect(nSelectBoxXPos, nSelectBoxYPos, checkBoxSideLenght, checkBoxSideLenght);
    QPixmap checkBoxPixmap;
    checkBoxPixmap.load(bSelected ? ":/orderGoodsImage/checkBoxPress.png" : ":/orderGoodsImage/checkBoxWithSide.png");
    painter->drawPixmap(selectBoxRect, checkBoxPixmap);

    // 序号
    const int nSecondWidth = 54;
    int nSecondXPos = nSelectBoxXPos + checkBoxSideLenght + nLeftSpace;
    QRect secondRect(nSecondXPos, yPos, nSecondWidth, nHeight);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sSeq);

    // 编号
    const int nThirdWidth = 85;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sCode);

    // 型号
    const int nFourthWidth = 143;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sModel);

    // IP
    const int nFifthWidth = 171;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifthRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, itemInfo.sIP);

    // 状态
    const int nSixthColWidth = 85;
    int nSixXPos = nFifthXPos + nFifthWidth;
    QRect SixRect(nSixXPos, yPos, nSixthColWidth, nHeight);
    setStateTextPainter(painter, pen, itemInfo.nState);
    painter->drawText(SixRect, Qt::AlignLeft | Qt::AlignVCenter, EnumToString::bcsLinkStateToString(itemInfo.nState));

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

void CSRelateDlgListView::setStateTextPainter(QPainter *painter, QPen &pen, int nState) const
{
    if (nState == e_bcsSendDownSuccess)
    {
        pen.setColor("#75AB57");
    }
    else if (nState == e_bcsSendDownFailed)
    {
        pen.setColor("#EA8852");
    }
    painter->setPen(pen);
}

BCSRelateDlgListView::BCSRelateDlgListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
{
    init();
}

void BCSRelateDlgListView::appendItem(const BarCodeScaleInfo &itemInfo)
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

void BCSRelateDlgListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void BCSRelateDlgListView::appendSelectKeyIds(const QList<QString> &keyIdList)
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

void BCSRelateDlgListView::removeSelectKeyIds(const QList<QString> &keyIdList)
{
    int nLen = keyIdList.length();
    for (int i = 0; i < nLen; i++)
    {
        m_sSelectKeyIdList.removeOne(keyIdList[i]);
    }
}

//QString BCSRelateDlgListView::getSelectKeyId()
//{
////    if (!m_ItemKeyIdMap.contains(m_sSelectKeyId))
////    {
////        m_sSelectKeyId = "";
////    }
//    return m_sSelectKeyId;
//}

//void BCSRelateDlgListView::setSelectKeyId(QString sKeyId)
//{
//    m_sSelectKeyId = sKeyId;
//}

//void BCSRelateDlgListView::getSelectItemInfo(BarCodeScaleInfo &itemInfo)
//{
////    if (!m_ItemKeyIdMap.contains(m_sSelectKeyId))
////    {
////        m_sSelectKeyId = "";
////        bcsInfo.sKeyId = "";
////        return;
////    }
//    itemInfo = m_selectItemInfo;
//}

//int BCSRelateDlgListView::getSelectSeq()
//{
//    if (m_sSelectKeyId.isEmpty())
//    {
//        return -1;
//    }
//    return m_selectItemInfo.sSeq.toInt();
//}

void BCSRelateDlgListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    BarCodeScaleInfo itemInfo;
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<BarCodeScaleInfo>())//可以转换
    {
        itemInfo = v_itemInfo.value<BarCodeScaleInfo>();
        if (m_sSelectKeyIdList.contains(itemInfo.sKeyId))
        {
            m_sSelectKeyIdList.removeOne(itemInfo.sKeyId);
        }
        else
        {
            m_sSelectKeyIdList.append(itemInfo.sKeyId);
        }
        emit sigClickItem(itemInfo);
    }
}

void BCSRelateDlgListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new CSRelateDlgListView(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode(MultiSelection);
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}

