#include "ReportLossListView.h"
#include <QPainter>
#include <QMouseEvent>
#include "../data/constData.h"
#include "CommonFun.h"

enum ItemType
{
    e_itemInfo = Qt::UserRole + 1,
};

ReportLossDelegate::ReportLossDelegate(QObject *parent)
  : QStyledItemDelegate(parent)
{

}

void ReportLossDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<ReportLossInfo>())
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
        ReportLossInfo reportLossInfo = v_itemInfo.value<ReportLossInfo>();
        paintContent(painter, option, reportLossInfo, bSelected);
    }
    painter->restore();
}

void ReportLossDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const ReportLossInfo &reportLossInfo, bool bSelected) const
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
    pen.setColor(bSelected?QColor(f_fontColorWhite):QColor(f_fontColorBlack));
    painter->setPen(pen);

    const int nLeftSpace = 26*g_widthRate;

    // 单号
    const int nFirstWidth = 165*g_widthRate;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect1(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect1, Qt::AlignLeft | Qt::AlignVCenter, reportLossInfo.InfoID);

    // 制单人
    const int nSecondWidth = 110*g_widthRate;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    QRect secondRect(nSecondXPos, yPos, nSecondWidth, nHeight);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, reportLossInfo.createName);

    // 制单时间
    const int nThirdWidth = 133*g_widthRate;
    int nThirdXPos = nSecondXPos + nSecondWidth;
    QRect thirdRect(nThirdXPos, yPos, nThirdWidth, nHeight);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, CommonFun::trunkDateTime(reportLossInfo.createTime));

    // 审核人
    const int nFourthWidth = 105*g_widthRate;
    int nFourthXPos = nThirdXPos + nThirdWidth;
    QRect fourththRect(nFourthXPos, yPos, nFourthWidth, nHeight);
    painter->drawText(fourththRect, Qt::AlignLeft | Qt::AlignVCenter, reportLossInfo.checkName);

    // 审核时间
    const int nFifthWidth = 150*g_widthRate;
    int nFifthXPos = nFourthXPos + nFourthWidth;
    QRect fifthRect(nFifthXPos, yPos, nFifthWidth, nHeight);
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, CommonFun::trunkDateTime(reportLossInfo.checkTime));

    // 状态
    QString status;
    if(!reportLossInfo.status){
        pen.setColor(bSelected?QColor(f_fontColorWhite):QColor(f_fontColorGray));
        status = QStringLiteral("未审核");
    }
    else{
        pen.setColor(bSelected?QColor(f_fontColorWhite):QColor(f_fontColorGreen));
        status = QStringLiteral("已审核");
    }
    painter->setPen(pen);
    const int nSixthWidth = 92;
    int nSixthXPos = nFifthXPos + nFifthWidth;
    QRect sixththRect(nSixthXPos, yPos, nSixthWidth, nHeight);
    painter->drawText(sixththRect, Qt::AlignLeft | Qt::AlignVCenter, status);

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

ReportLossListView::ReportLossListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(51)
    , m_nSelectKeyId(-1)
{
    init();
}

void ReportLossListView::appendItem(const ReportLossInfo &reportLossInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(reportLossInfo.id))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(reportLossInfo.id, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(reportLossInfo.id);
    }

    QVariant variant;
    variant.setValue(reportLossInfo);
    pItem->setData(variant, e_itemInfo);

    if (m_nSelectKeyId == reportLossInfo.id)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void ReportLossListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

int ReportLossListView::getSelectIdList()
{
    return m_nSelectKeyId;
}

void ReportLossListView::setSelectKeyId(int nKeyId)
{
     m_nSelectKeyId = nKeyId;
}

void ReportLossListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    ReportLossInfo reportLossInfo;
    QVariant v_itemInfo = index.data(e_itemInfo);
    if (v_itemInfo.canConvert<ReportLossInfo>())//可以转换
    {
        reportLossInfo = v_itemInfo.value<ReportLossInfo>();
        m_nSelectKeyId = reportLossInfo.id;
        emit sigClickItem(reportLossInfo);
    }
}

void ReportLossListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new ReportLossDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
