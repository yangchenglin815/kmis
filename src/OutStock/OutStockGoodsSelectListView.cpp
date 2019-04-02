#include "OutStockGoodsSelectListView.h"
#include "../data/constData.h"
#include "CommonFun.h"
#include <QPainter>
#include <QMouseEvent>

enum OutStockGoodsSelectItemType
{
    e_outstkGoodsSelectInfo = Qt::UserRole + 1,
};

OutStockGoodsSelectDelegate::OutStockGoodsSelectDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void OutStockGoodsSelectDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_outstkGoodsSelectInfo);
    if (v_itemInfo.canConvert<OutStockSelectGoodsInfo>())
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
        OutStockSelectGoodsInfo selectGoodsInfo = v_itemInfo.value<OutStockSelectGoodsInfo>();
        paintContent(painter, option, selectGoodsInfo, bSelected);
    }

    painter->restore();
}

void OutStockGoodsSelectDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const OutStockSelectGoodsInfo &rInfo, bool bSelected) const
{
    paintSeqCol(painter, option, rInfo, bSelected);
    paintGoodsNameCol(painter, option, rInfo, bSelected);
    paintOtherCol(painter, option, rInfo, bSelected);
    paintLine(painter, option);
}

void OutStockGoodsSelectDelegate::paintSeqCol(QPainter *painter, const QStyleOptionViewItem &option, const OutStockSelectGoodsInfo &rInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    const int fontSize = 14*g_heightRate;
    QFont font;
    font.setPixelSize(fontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected?"#ffffff":"#333333");
    painter->setPen(pen);
    const int c_nColWidth = 36*g_heightRate;
    QRect textRec(xPos, yPos, c_nColWidth, option.rect.height());
    painter->drawText(textRec, Qt::AlignCenter, rInfo.sSeq);
}

void OutStockGoodsSelectDelegate::paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const OutStockSelectGoodsInfo &rInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    const int nLeftSpace = 50*g_heightRate;
    const int nTopSpace = 12*g_heightRate;
    int startXPos = xPos + nLeftSpace;
    int startYPos = yPos + nTopSpace;
    const int fontSize = 14*g_heightRate;
    QFont font;
    font.setPixelSize(fontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected ? "#ffffff" : "#333333");
    painter->setPen(pen);

    QString strName = rInfo.sName;
    int goodsNameWidth = painter->fontMetrics().width(strName);
    QRect goodsNameRect(startXPos, startYPos, goodsNameWidth, fontSize);
    painter->drawText(goodsNameRect, Qt::AlignLeft | Qt::AlignVCenter, strName);
    pen.setColor(bSelected ? "#ffffff" : "#999999");
    painter->setPen(pen);
    startXPos += goodsNameWidth + 2*g_heightRate;
    QRect goodsUnitRect(startXPos, startYPos, option.rect.width(), fontSize);
    painter->drawText(goodsUnitRect, Qt::AlignLeft | Qt::AlignVCenter, QString("( %1 )").arg(rInfo.sSellUnit));
}

void OutStockGoodsSelectDelegate::paintOtherCol(QPainter *painter, const QStyleOptionViewItem &option, const OutStockSelectGoodsInfo &rInfo, bool bSelected) const
{
    const int fontSize = 12*g_heightRate;
    QFont font;
    font.setPixelSize(fontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected ? "#ffffff" : "#ea8852");
    painter->setPen(pen);

    int xPos = option.rect.x();
    int yPos = option.rect.y();
    const int nLeftSpace = 132*g_heightRate;
    const int nTopSpace = 32*g_heightRate;
    int nStartXPos = xPos + nLeftSpace;
    int nStartYPos = yPos + nTopSpace;

    const int nFirstColWidth = 54*g_heightRate;
    const int nSecondColWidth = 54*g_heightRate;
    const int nThirdColWidth = 76*g_heightRate;
    //单价
    QRect rec11(nStartXPos, nStartYPos, nFirstColWidth, fontSize);
    if(false==rInfo.isEdited)
        painter->drawText(rec11, Qt::AlignLeft | Qt::AlignVCenter, rInfo.sPrice);
    else
        painter->drawText(rec11, Qt::AlignLeft | Qt::AlignVCenter, CommonFun::floatToString(rInfo.fBatchPrice));
    //乘号
    nStartXPos += 40*g_heightRate;
    QRect rect112(nStartXPos, nStartYPos, 20*g_heightRate*g_heightRate, fontSize);
    painter->drawText(rect112, Qt::AlignLeft | Qt::AlignVCenter, "x");

    //申请入库数量
    nStartXPos += 14*g_heightRate;
    QRect rect12(nStartXPos, nStartYPos, nSecondColWidth, fontSize);
    if(false==rInfo.isEdited)
        painter->drawText(rect12, Qt::AlignLeft | Qt::AlignVCenter, rInfo.sCount);
    else
        painter->drawText(rect12, Qt::AlignLeft | Qt::AlignVCenter, CommonFun::floatToString(rInfo.fShouldCount));
    //小计金额
    nStartXPos += nSecondColWidth;
    QRect rect13(nStartXPos, nStartYPos, nThirdColWidth, fontSize);

    QString strFcout=CommonFun::floatToString(rInfo.fShouldTotal);
    if(false==rInfo.isEdited)
        painter->drawText(rect13, Qt::AlignLeft | Qt::AlignVCenter,rInfo.sSubTotal);
    else
        painter->drawText(rect13, Qt::AlignLeft | Qt::AlignVCenter, strFcout);
}

void OutStockGoodsSelectDelegate::paintLine(QPainter *painter, const QStyleOptionViewItem &option) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    QPen pen;
    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + option.rect.height(), xPos + option.rect.width(), yPos + option.rect.height());
}

OutStockGoodsSelectListView::OutStockGoodsSelectListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51*g_heightRate)
    , m_nSelectKeyId(-1)
{
    init();
}

void OutStockGoodsSelectListView::appendItem(const OutStockSelectGoodsInfo &selectGoodsInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(selectGoodsInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(selectGoodsInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(selectGoodsInfo.nId);
    }

    QVariant variant;
    variant.setValue(selectGoodsInfo);
    pItem->setData(variant, e_outstkGoodsSelectInfo);

    if (m_nSelectKeyId == selectGoodsInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void OutStockGoodsSelectListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

bool OutStockGoodsSelectListView::isExistItem(int nKeyId)
{
    return m_ItemKeyIdMap.contains(nKeyId);
}

int OutStockGoodsSelectListView::getSelectKeyId()
{
    return m_nSelectKeyId;
}

void OutStockGoodsSelectListView::setSelectKeyId(int nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

bool OutStockGoodsSelectListView::getSelectItem(OutStockSelectGoodsInfo &selectGoodsInfo)
{
    if ((m_nSelectKeyId > 0) && m_ItemKeyIdMap.contains(m_nSelectKeyId))
    {
        QStandardItem* pItem = m_ItemKeyIdMap.value(m_nSelectKeyId);
        QVariant v_itemInfo = pItem->data(e_outstkGoodsSelectInfo);
        if (v_itemInfo.canConvert<OutStockSelectGoodsInfo>())//可以转换
        {
            selectGoodsInfo = v_itemInfo.value<OutStockSelectGoodsInfo>();
            return true;
        }
        return false;
    }
    return false;
}

void OutStockGoodsSelectListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    OutStockSelectGoodsInfo selectGoodsInfo;
    QVariant v_itemInfo = index.data(e_outstkGoodsSelectInfo);
    if (v_itemInfo.canConvert<OutStockSelectGoodsInfo>())//可以转换
    {
        selectGoodsInfo = v_itemInfo.value<OutStockSelectGoodsInfo>();
        m_nSelectKeyId = selectGoodsInfo.nId;
        emit sigClickItem(selectGoodsInfo);
    }
}

void OutStockGoodsSelectListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new OutStockGoodsSelectDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



