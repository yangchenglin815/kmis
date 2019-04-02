#include "InquireListView.h"
#include <QMouseEvent>
#include <QPainter>
#include "../data/enumData.h"
#include "../data/constData.h"
#include "../util/CommonFun.h"

enum InquireItemType
{
    e_InquireInfo = Qt::UserRole + 1,
};

InquireDelegate::InquireDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void InquireDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_InquireInfo);
    if (v_itemInfo.canConvert<InStockOrderSearchInfo>())
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
        InStockOrderSearchInfo istkInfo = v_itemInfo.value<InStockOrderSearchInfo>();
        paintContent(painter, option, istkInfo, bSelected);
    }

    painter->restore();
}

void InquireDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const InStockOrderSearchInfo &istkInfo, bool bSelected) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    const int nfontSize = 14*g_widthRate;
    const int nfontSize2 = 12*g_widthRate;
    QFont font;
    font.setPixelSize(nfontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setPen(pen);

    // 序号
    const int nLeftSpace=22*g_widthRate;
    const int nFirstWidth = 60*g_widthRate;
    int nFirstXPos = xPos+nLeftSpace ;
    QRect firstRect(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect, Qt::AlignLeft | Qt::AlignVCenter, istkInfo.sSeq);

    const int nVSpace = 2*g_widthRate;
    // 商品--商品名称
    QString strName = istkInfo.sName;

    const int nSecondWidth = 220*g_widthRate;
    int nSecondXPos= xPos+nFirstWidth ;
    int nSecondYPos = yPos + (nHeight - (nfontSize + nVSpace + nfontSize2))/2 ;
    QRect secondFirstRect(nSecondXPos, nSecondYPos, nSecondWidth, nfontSize);
    painter->drawText(secondFirstRect, Qt::AlignLeft | Qt::AlignVCenter, strName );
    // 商品--商品单位
    int goodsNameWidth = painter->fontMetrics().width( strName );
    font.setPixelSize(nfontSize2);
    painter->setFont(font);
    pen.setColor(bSelected ? "#ffffff" : "#999999");
    painter->setPen(pen);
    QString sShowUnit = QString("( %1 )").arg(istkInfo.sWeighUnit);
    int goodsUnitXPos = nSecondXPos + goodsNameWidth + 2;
    int goodsUnitYPos = nSecondYPos + nfontSize - nfontSize2;
    QRect goodsUnitRect(goodsUnitXPos, goodsUnitYPos, nSecondWidth, nfontSize2);
    painter->drawText(goodsUnitRect, Qt::AlignLeft | Qt::AlignVCenter, sShowUnit);

    // 商品--商品条码
    nSecondYPos += (nfontSize + nVSpace);
    QRect secondSecondRect(nSecondXPos, nSecondYPos, nSecondWidth, nfontSize2);
    painter->drawText(secondSecondRect, Qt::AlignLeft | Qt::AlignVCenter, istkInfo.sCode);

    //
    font.setPixelSize(nfontSize);
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setFont(font);
    painter->setPen(pen);

    // 入库单价
    const int nThirdWidth = 130*g_widthRate;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, istkInfo.sPrice);

    // 数量
    const int n4Width = 100*g_widthRate;
    int n4XPos = nThirdXPos + nThirdWidth;
    QRect fourRect(n4XPos, yPos, n4Width, nHeight);
    painter->drawText(fourRect, Qt::AlignLeft | Qt::AlignVCenter, istkInfo.sCount);

    // 件数
    const int n5Width = 136*g_widthRate;
    int n5XPos = n4XPos + n4Width;
    QRect fiveRect(n5XPos, yPos, n5Width, nHeight);
    painter->drawText(fiveRect, Qt::AlignLeft | Qt::AlignVCenter, istkInfo.sBoxNum);

    // 小计金额
    const int n6Width = 130*g_widthRate;
    int n6XPos = n5XPos + n5Width;
    QRect sixRect(n6XPos, yPos, n6Width, nHeight);
    pen.setColor(bSelected?"#ffffff":"#ea8852");
    painter->setPen(pen);
    painter->drawText(sixRect, Qt::AlignLeft | Qt::AlignVCenter,istkInfo.sSubTotal);

    // 审核状态
    //    QString n7Text = QString::fromUtf8("未审核");
    //    if (istkInfo.nState == e_instkNoChecked)
    //    {
    //        pen.setColor(bSelected?"#ffffff":"#999999");
    //    }
    //    else
    //    {
    //        n7Text = QString::fromUtf8("已审核");
    //        pen.setColor(bSelected?"#ffffff":"#75ab57");
    //    }
    //    painter->setPen(pen);
    //    const int n7Width = 79;
    //    int n7XPos = n6XPos + n6Width;
    //    QRect sevenRect(n7XPos, yPos, n7Width, nHeight);
    //    painter->drawText(sevenRect, Qt::AlignLeft | Qt::AlignVCenter, n7Text);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

InquireListView::InquireListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51*g_widthRate)
    , m_nSelectKeyId(-1)
{
    init();
}

void InquireListView::appendItem(const InStockOrderSearchInfo &istkInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(istkInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(istkInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(istkInfo.nId);
    }

    QVariant variant;
    variant.setValue(istkInfo);
    pItem->setData(variant, e_InquireInfo);

    if (m_nSelectKeyId == istkInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void InquireListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

int InquireListView::getSelectKeyId()
{
    return m_nSelectKeyId;
}

void InquireListView::setSelectKeyId(int nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

void InquireListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    InStockOrderSearchInfo istkInfo;
    QVariant v_itemInfo = index.data(e_InquireInfo);
    if (v_itemInfo.canConvert<InStockOrderSearchInfo>())//可以转换
    {
        istkInfo = v_itemInfo.value<InStockOrderSearchInfo>();
        m_nSelectKeyId = istkInfo.nId;
        emit sigClickItem(istkInfo);
    }
}

void InquireListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new InquireDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



