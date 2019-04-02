#include "InStockGoodsSelectListView.h"
#include "../data/constData.h"
#include "CommonFun.h"
#include <QPainter>
#include <QMouseEvent>

enum InStockGoodsSelectItemType
{
    e_instkGoodsSelectInfo = Qt::UserRole + 1,
};

InStockGoodsSelectDelegate::InStockGoodsSelectDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void InStockGoodsSelectDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_instkGoodsSelectInfo);
    if (v_itemInfo.canConvert<InStockSelectGoodsInfo>())
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
        InStockSelectGoodsInfo selectGoodsInfo = v_itemInfo.value<InStockSelectGoodsInfo>();
        paintContent(painter, option, selectGoodsInfo, bSelected);
    }

    painter->restore();
}

void InStockGoodsSelectDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const InStockSelectGoodsInfo &rInfo, bool bSelected) const
{
    paintSeqCol(painter, option, rInfo, bSelected);
    paintGoodsNameCol(painter, option, rInfo, bSelected);
    paintOtherCol(painter, option, rInfo, bSelected);
    paintLine(painter, option);
}

void InStockGoodsSelectDelegate::paintSeqCol(QPainter *painter, const QStyleOptionViewItem &option, const InStockSelectGoodsInfo &rInfo, bool bSelected) const
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

void InStockGoodsSelectDelegate::paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const InStockSelectGoodsInfo &rInfo, bool bSelected) const
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

void InStockGoodsSelectDelegate::paintOtherCol(QPainter *painter, const QStyleOptionViewItem &option, const InStockSelectGoodsInfo &rInfo, bool bSelected) const
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
    QRect rect112(nStartXPos, nStartYPos, 20, fontSize);
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

void InStockGoodsSelectDelegate::paintLine(QPainter *painter, const QStyleOptionViewItem &option) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    QPen pen;
    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + option.rect.height(), xPos + option.rect.width(), yPos + option.rect.height());
}

InStockGoodsSelectListView::InStockGoodsSelectListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51*g_heightRate)
    , m_nSelectKeyId(-1)
{
    init();
}

void InStockGoodsSelectListView::appendItem(const InStockSelectGoodsInfo &selectGoodsInfo)
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
    pItem->setData(variant, e_instkGoodsSelectInfo);

    if (m_nSelectKeyId == selectGoodsInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void InStockGoodsSelectListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

bool InStockGoodsSelectListView::isExistItem(int nKeyId)
{
    return m_ItemKeyIdMap.contains(nKeyId);
}

int InStockGoodsSelectListView::getSelectKeyId()
{
    return m_nSelectKeyId;
}

void InStockGoodsSelectListView::setSelectKeyId(int nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

bool InStockGoodsSelectListView::getSelectItem(InStockSelectGoodsInfo &selectGoodsInfo)
{
    if ((m_nSelectKeyId > 0) && m_ItemKeyIdMap.contains(m_nSelectKeyId))
    {
        QStandardItem* pItem = m_ItemKeyIdMap.value(m_nSelectKeyId);
        QVariant v_itemInfo = pItem->data(e_instkGoodsSelectInfo);
        if (v_itemInfo.canConvert<InStockSelectGoodsInfo>())//可以转换
        {
            selectGoodsInfo = v_itemInfo.value<InStockSelectGoodsInfo>();
            return true;
        }
        return false;
    }
    return false;
}

void InStockGoodsSelectListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    InStockSelectGoodsInfo selectGoodsInfo;
    QVariant v_itemInfo = index.data(e_instkGoodsSelectInfo);
    if (v_itemInfo.canConvert<InStockSelectGoodsInfo>())//可以转换
    {
        selectGoodsInfo = v_itemInfo.value<InStockSelectGoodsInfo>();
        m_nSelectKeyId = selectGoodsInfo.nId;
        emit sigClickItem(selectGoodsInfo);
    }
}

void InStockGoodsSelectListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new InStockGoodsSelectDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



