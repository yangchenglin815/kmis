#include "CheckDetialListView.h"
#include <QPainter>
#include <QMouseEvent>
#include "../data/constData.h"

enum ItemType
{
    e_itemInfo = Qt::UserRole + 1,
};

CheckDetialDelegate::CheckDetialDelegate(QObject *parent)
  : QStyledItemDelegate(parent)
{

}

void CheckDetialDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<AddReportLossSelectInfo>())
    {
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
        }
        AddReportLossSelectInfo checkDetialInfo = v_itemInfo.value<AddReportLossSelectInfo>();
        paintContent(painter, option, checkDetialInfo, bSelected);
    }
    painter->restore();
}

void CheckDetialDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const AddReportLossSelectInfo &checkDetialInfo, bool bSelected) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    QFont font;
    font.setPixelSize(f_fontSizeMode1*g_widthRate);
    font.setFamily(f_fontStyle);
    painter->setFont(font);
    QPen pen;
    pen.setColor(QColor(f_fontColorBlack));
    painter->setPen(pen);

    const int nLeftSpace = 26*g_widthRate;

    // 序号
    const int nFirstWidth = 50*g_widthRate;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect1(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect1, Qt::AlignLeft | Qt::AlignVCenter, QString::number(checkDetialInfo.nId));

    // 商品
    const int nSecondWidth = 145*g_widthRate;
    const int nSecondTwoRowSpace = 6*g_widthRate;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    int nSecondYPos = yPos + (nHeight - (f_fontSizeMode1 + f_fontSizeMode2 + nSecondTwoRowSpace))/2;
    int nYPos = nSecondYPos;
    QRect secondRect(nSecondXPos, nSecondYPos, nSecondWidth, f_fontSizeMode1);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, checkDetialInfo.sName + QString(" (%1)").arg(checkDetialInfo.sUnit));

    // 商品编号
    font.setPixelSize(f_fontSizeMode2);
    painter->setFont(font);
    pen.setColor("#666666");
    painter->setPen(pen);
    nSecondYPos += f_fontSizeMode1 + nSecondTwoRowSpace;
    QRect thirdRect(nSecondXPos, nSecondYPos, nSecondWidth, f_fontSizeMode2);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, checkDetialInfo.sCode);

    //单位
    const int nThirdWidth = 105*g_widthRate;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect rect(nThirdXPos, nYPos, nThirdWidth, f_fontSizeMode2);
//    painter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, checkDetialInfo.sUnit);

    // 类别
    font.setPixelSize(f_fontSizeMode1);
    painter->setFont(font);
    pen.setColor(QColor(f_fontColorBlack));
    painter->setPen(pen);
    const int nFourthWidth = 185*g_widthRate;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, checkDetialInfo.sCategoryName);

    // 报损数量
    const int nFifthWidth = 155*g_widthRate;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifththRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    painter->drawText(fifththRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(checkDetialInfo.sNumber, 'f', 2));

    //报损金额
    pen.setColor(f_fontColorOrange);
    painter->setPen(pen);
    const int nSixthWidth = 150*g_widthRate;
    int nSixthXPos = nFifthXPos + nFifthWidth;
    QRect sixthRect(nSixthXPos, yPos, nSixthWidth, nHeight);
    painter->drawText(sixthRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(checkDetialInfo.sMoney, 'f', 2));

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

CheckDetialListView::CheckDetialListView(QWidget *parent)
   : QListView(parent)
   , m_pStandardItemModel(NULL)
   , m_nItemHeight(51)
   , m_nSelectKeyId(-1)
{
   init();
}

void CheckDetialListView::appendItem(const AddReportLossSelectInfo &checkDetialInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(checkDetialInfo.id))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(checkDetialInfo.id, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(checkDetialInfo.id);
    }

    QVariant variant;
    variant.setValue(checkDetialInfo);
    pItem->setData(variant, e_itemInfo);

    if (m_nSelectKeyId == checkDetialInfo.id)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void CheckDetialListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

int CheckDetialListView::getSelectIdList()
{
    return m_nSelectKeyId;
}

void CheckDetialListView::setSelectKeyId(int nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

void CheckDetialListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    AddReportLossSelectInfo checkDetialInfo;
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<AddReportLossSelectInfo>())//可以转换
    {
        checkDetialInfo = v_itemInfo.value<AddReportLossSelectInfo>();
        m_nSelectKeyId = checkDetialInfo.id;
        emit sigClickItem(checkDetialInfo);
    }
}

void CheckDetialListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new CheckDetialDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
