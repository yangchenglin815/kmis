#include "AdjustPriceGoodsSelectListView.h"
#include "../data/constData.h"
#include <QPainter>
#include <QMouseEvent>

enum AdjustPriceGoodsSelectItemType
{
    e_adjustPriceGoodsSelectInfo = Qt::UserRole + 1,
};

AdjustPriceGoodsSelectDelegate::AdjustPriceGoodsSelectDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void AdjustPriceGoodsSelectDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_adjustPriceGoodsSelectInfo);
    if (v_itemInfo.canConvert<AdjustPriceSelectGoodsInfo>())
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
        AdjustPriceSelectGoodsInfo selectGoodsInfo = v_itemInfo.value<AdjustPriceSelectGoodsInfo>();
        paintContent(painter, option, selectGoodsInfo, bSelected);
    }

    painter->restore();
}

void AdjustPriceGoodsSelectDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const AdjustPriceSelectGoodsInfo &rInfo, bool bSelected) const
{
    paintSeqCol(painter, option, rInfo, bSelected);
    paintGoodsNameCol(painter, option, rInfo, bSelected);
    paintOtherCol(painter, option, rInfo, bSelected);
    paintLine(painter, option);
}

void AdjustPriceGoodsSelectDelegate::paintSeqCol(QPainter *painter, const QStyleOptionViewItem &option, const AdjustPriceSelectGoodsInfo &rInfo, bool bSelected) const
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
    const int c_nColWidth = 36 * g_heightRate;
    QRect textRec(xPos, yPos, c_nColWidth, option.rect.height());
    painter->drawText(textRec, Qt::AlignCenter, rInfo.sSeq);
}

void AdjustPriceGoodsSelectDelegate::paintGoodsNameCol(QPainter *painter, const QStyleOptionViewItem &option, const AdjustPriceSelectGoodsInfo &rInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    const int nLeftSpace = 36*g_heightRate;
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

    QString strName = "";
    if( rInfo.sShortName.isEmpty() ) {
        strName = rInfo.sName;
    } else {
        strName = rInfo.sShortName;
    }

    int goodsNameWidth = painter->fontMetrics().width( strName );
    QRect goodsNameRect(startXPos, startYPos, goodsNameWidth, fontSize);
    painter->drawText(goodsNameRect, Qt::AlignLeft | Qt::AlignVCenter, strName );
    pen.setColor(bSelected ? "#ffffff" : "#999999");
    painter->setPen(pen);
    startXPos += goodsNameWidth + 2*g_heightRate;
    QRect goodsUnitRect(startXPos, startYPos, option.rect.width(), fontSize);
    painter->drawText(goodsUnitRect, Qt::AlignLeft | Qt::AlignVCenter, QString("( %1 )").arg(rInfo.sWeighUnit));
}

void AdjustPriceGoodsSelectDelegate::paintOtherCol(QPainter *painter, const QStyleOptionViewItem &option, const AdjustPriceSelectGoodsInfo &rInfo, bool bSelected) const
{
    const int fontSize = 12*g_heightRate;
    QFont font;
    font.setPixelSize(fontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor(bSelected ? "#ffffff" : "#333333");
    painter->setPen(pen);

    int xPos = option.rect.x();
    int yPos = option.rect.y();
    const int nLeftSpace = 134*g_heightRate;
    const int nTopSpace = 32*g_heightRate;
    int nStartXPos = xPos + nLeftSpace;
    int nStartYPos = yPos + nTopSpace;

    const int nFirstColWidth = 80*g_heightRate;
    const int nSecondColWidth = 80*g_heightRate;
    // 单价
    QRect rec11(nStartXPos, nStartYPos, nFirstColWidth, fontSize);
    painter->drawText(rec11, Qt::AlignLeft | Qt::AlignVCenter, QString("￥%1").arg(QString::number(rInfo.fOldPrice, 'f', 2)));

    // 会员价
    nStartXPos += nFirstColWidth;
    QRect rect12(nStartXPos, nStartYPos, nSecondColWidth, fontSize);
    painter->drawText(rect12, Qt::AlignLeft | Qt::AlignVCenter, QString("￥%1").arg(QString::number(rInfo.fOldMemberPrice, 'f', 2)));

    pen.setColor(bSelected ? "#ffffff" : "#ea8852");
    painter->setPen(pen);

    const int nVSpace = 8;
    nStartXPos = xPos + nLeftSpace;
    nStartYPos += (fontSize + nVSpace);

    // 新单价
    QRect rect21(nStartXPos, nStartYPos, nFirstColWidth, fontSize);
    painter->drawText(rect21, Qt::AlignLeft | Qt::AlignVCenter, QString("￥%1").arg(QString::number(rInfo.fNowPrice, 'f', 2)));

    // 新会员价
    nStartXPos += nFirstColWidth;
    static const int nGoodsSumPriceWidth = 64;
    QRect rect22(nStartXPos, nStartYPos, nGoodsSumPriceWidth, fontSize);
    painter->drawText(rect22, Qt::AlignLeft | Qt::AlignVCenter, QString("￥%1").arg(QString::number(rInfo.fNowMemberPrice, 'f', 2)));
}

void AdjustPriceGoodsSelectDelegate::paintLine(QPainter *painter, const QStyleOptionViewItem &option) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    QPen pen;
    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + option.rect.height(), xPos + option.rect.width(), yPos + option.rect.height());
}

AdjustPriceGoodsSelectListView::AdjustPriceGoodsSelectListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(68 * g_heightRate)
    , m_nSelectKeyId(-1)
{
    init();
}

void AdjustPriceGoodsSelectListView::appendItem(const AdjustPriceSelectGoodsInfo &selectGoodsInfo)
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
    pItem->setData(variant, e_adjustPriceGoodsSelectInfo);

    if (m_nSelectKeyId == selectGoodsInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void AdjustPriceGoodsSelectListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

bool AdjustPriceGoodsSelectListView::isExistItem(int nKeyId)
{
    return m_ItemKeyIdMap.contains(nKeyId);
}

int AdjustPriceGoodsSelectListView::getSelectKeyId()
{
    return m_nSelectKeyId;
}

void AdjustPriceGoodsSelectListView::setSelectKeyId(int nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

bool AdjustPriceGoodsSelectListView::getSelectItem(AdjustPriceSelectGoodsInfo &selectGoodsInfo)
{
    if ((m_nSelectKeyId > 0) && m_ItemKeyIdMap.contains(m_nSelectKeyId))
    {
        QStandardItem* pItem = m_ItemKeyIdMap.value(m_nSelectKeyId);
        QVariant v_itemInfo = pItem->data(e_adjustPriceGoodsSelectInfo);
        if (v_itemInfo.canConvert<AdjustPriceSelectGoodsInfo>())//可以转换
        {
            selectGoodsInfo = v_itemInfo.value<AdjustPriceSelectGoodsInfo>();
            return true;
        }
        return false;
    }
    return false;
}

void AdjustPriceGoodsSelectListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    AdjustPriceSelectGoodsInfo selectGoodsInfo;
    QVariant v_itemInfo = index.data(e_adjustPriceGoodsSelectInfo);
    if (v_itemInfo.canConvert<AdjustPriceSelectGoodsInfo>())//可以转换
    {
        selectGoodsInfo = v_itemInfo.value<AdjustPriceSelectGoodsInfo>();
        m_nSelectKeyId = selectGoodsInfo.nId;
        emit sigClickItem(selectGoodsInfo);
    }
}

void AdjustPriceGoodsSelectListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new AdjustPriceGoodsSelectDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}



