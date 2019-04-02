#include "SummaryChartsLeftListView.h"
#include <QPainter>

enum SummaryChartsLeftInfoType
{
    e_summaryCharts,
};

SummaryChartsLeftDelegate::SummaryChartsLeftDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void SummaryChartsLeftDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_summaryCharts);
    if (v_itemInfo.canConvert<SummaryChartsInfo>())
    {
        SummaryChartsInfo summaryChartsInfo = v_itemInfo.value<SummaryChartsInfo>();
        paintContent(painter, option, summaryChartsInfo);
    }

    painter->restore();
}

void SummaryChartsLeftDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const SummaryChartsInfo &summaryChartsInfo) const
{
    const int xPos = option.rect.x();
    const int yPos = option.rect.y();
    const int nWidth = option.rect.width();
    const int nHeight = option.rect.height();

    QFont font;
    const int nFontSize = 12;
    font.setPixelSize(nFontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor("#333333");
    painter->setPen(pen);

    // 时段
    const int nLeftSpace = 20;
    const int nFirstColWidth = 117;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect(nFirstXPos, yPos, nFirstColWidth, nHeight);
    painter->drawText(firstRect, Qt::AlignLeft | Qt::AlignVCenter, summaryChartsInfo.sTimePeriod);

    // 销售额
    const int nSecondWidth = 112;
    int nSecondColXPos = nFirstXPos + nFirstColWidth;
    QRect secondRect(nSecondColXPos, yPos, nSecondWidth, nHeight);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(summaryChartsInfo.fSaleMoney, 'f', 2));

    // 客流量
    const int nThirdWidth = 75;
    int nThirdXPos = nSecondColXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(summaryChartsInfo.nPeopleNumber));

    // 客单价
    const int nFourthWidth = 59;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourthRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(summaryChartsInfo.fPeoplePrice, 'f', 2));

    //
    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

SummaryChartsLeftListView::SummaryChartsLeftListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(30)
{
    init();
}

void SummaryChartsLeftListView::appendItem(const SummaryChartsInfo &summaryChartsInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(summaryChartsInfo.sTimePeriod))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(summaryChartsInfo.sTimePeriod, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(summaryChartsInfo.sTimePeriod);
    }

    QVariant variant;
    variant.setValue(summaryChartsInfo);
    pItem->setData(variant, e_summaryCharts);
}

void SummaryChartsLeftListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void SummaryChartsLeftListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new SummaryChartsLeftDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}


