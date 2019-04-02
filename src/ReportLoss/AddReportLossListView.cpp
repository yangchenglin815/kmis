#include "AddReportLossListView.h"
#include <QPainter>
#include <QMouseEvent>
#include "../data/constData.h"
#include "httpstructdata.h"

enum AddReportLossSelectItemType
{
    e_addReportLossSelectInfo = Qt::UserRole + 1,
};

AddReportLossDelegate::AddReportLossDelegate(QObject *parent)
  : QStyledItemDelegate(parent)
{

}

void AddReportLossDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_addReportLossSelectInfo);
    if (v_itemInfo.canConvert<AddReportLossSelectInfo>())
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
        AddReportLossSelectInfo selectInfo = v_itemInfo.value<AddReportLossSelectInfo>();
        paintContent(painter, option, selectInfo, bSelected);
    }

    painter->restore();
}

void AddReportLossDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const AddReportLossSelectInfo &sInfo, bool bSelected) const
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

    const int nLeftSpace = 8*g_widthRate;
    // 序号
    const int nFirstWidth = 40*g_widthRate;
    int nFirstXPos = xPos + nLeftSpace;
    QRect firstRect1(nFirstXPos, yPos, nFirstWidth, nHeight);
    painter->drawText(firstRect1, Qt::AlignLeft | Qt::AlignVCenter, QString::number(sInfo.nId));

    // 商品名称
    font.setPixelSize(f_fontSizeMode2);
    painter->setFont(font);
    pen.setColor(bSelected?QColor(f_fontColorWhite):"#666666");
    painter->setPen(pen);
    const int nSecondWidth = 170*g_widthRate;
    const int nSecondTwoRowSpace = 6*g_widthRate;
    int nSecondXPos = nFirstXPos + nFirstWidth;
    int nSecondYPos = yPos + (nHeight - (f_fontSizeMode1 + f_fontSizeMode2 + nSecondTwoRowSpace))/2;
    int nYPos = nSecondYPos;
    QRect secondRect(nSecondXPos, nSecondYPos, nSecondWidth, f_fontSizeMode2);
    painter->drawText(secondRect, Qt::AlignLeft | Qt::AlignVCenter, sInfo.sName + QString("(%1)").arg(sInfo.sUnit));

    // 报损数量
    pen.setColor(QColor(f_fontColorOrange));
    painter->setPen(pen);
    const int nThirdXPos = nSecondXPos + nSecondWidth/2 - 10*g_widthRate;
    const int nThirdYPos =  nSecondYPos + f_fontSizeMode1 + nSecondTwoRowSpace;
    QRect thirdRect(nThirdXPos, nThirdYPos, nSecondWidth, f_fontSizeMode2);
    painter->drawText(thirdRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(sInfo.sNumber, 'f', 2));

    // 单位
    pen.setColor(QColor(f_fontColorGray));
    painter->setPen(pen);
    const int nFourthXPos = nSecondXPos + nSecondWidth;
    const int nFourthWidth = 40*g_widthRate;
    QRect fourthRect(nFourthXPos, nYPos, nFourthWidth, f_fontSizeMode2);
//    painter->drawText(fourthRect, Qt::AlignLeft | Qt::AlignVCenter, sInfo.sUnit);

    // 报损金额
    pen.setColor(QColor(f_fontColorOrange));
    painter->setPen(pen);
    const int nFifthXPos = nSecondXPos + nSecondWidth;
    const int nFifthWidth = 50*g_widthRate;
    QRect fifthRect(nFifthXPos, nThirdYPos, nFifthWidth, f_fontSizeMode2);
    painter->drawText(fifthRect, Qt::AlignLeft | Qt::AlignVCenter, QString::number(sInfo.sMoney, 'f', 2));

    pen.setColor("#ededed");
    painter->setPen(pen);
    painter->drawLine(xPos, yPos + nHeight - 1, xPos + nWidth, yPos + nHeight - 1);
}

AddReportLossListView::AddReportLossListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(68 * g_heightRate)
    , m_nSelectKeyId(-1)
{
    init();
}

void AddReportLossListView::appendItem(const AddReportLossSelectInfo &selectLossInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(selectLossInfo.nId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(selectLossInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, m_nItemHeight));
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(selectLossInfo.nId);
    }

    QVariant variant;
    variant.setValue(selectLossInfo);
    pItem->setData(variant, e_addReportLossSelectInfo);

    if (m_nSelectKeyId == selectLossInfo.nId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void AddReportLossListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

bool AddReportLossListView::isExistItem(int nKeyId)
{
       return m_ItemKeyIdMap.contains(nKeyId);
}

int AddReportLossListView::getSelectKeyId()
{
 return m_nSelectKeyId;
}

void AddReportLossListView::setSelectKeyId(int nKeyId)
{
    m_nSelectKeyId = nKeyId;
}

bool AddReportLossListView::getSelectItem(AddReportLossSelectInfo &selectLossInfo)
{
    if ((m_nSelectKeyId > 0) && m_ItemKeyIdMap.contains(m_nSelectKeyId))
    {
        QStandardItem* pItem = m_ItemKeyIdMap.value(m_nSelectKeyId);
        QVariant v_itemInfo = pItem->data(e_addReportLossSelectInfo);
        if (v_itemInfo.canConvert<AddReportLossSelectInfo>())//可以转换
        {
            selectLossInfo = v_itemInfo.value<AddReportLossSelectInfo>();
            return true;
        }
        return false;
    }
    return false;
}

void AddReportLossListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    AddReportLossSelectInfo lossInfo;
    QVariant v_itemInfo = index.data(e_addReportLossSelectInfo);
    if (v_itemInfo.canConvert<AddReportLossSelectInfo>())//可以转换
    {
        lossInfo = v_itemInfo.value<AddReportLossSelectInfo>();
        m_nSelectKeyId = lossInfo.nId;
        emit sigClickItem(lossInfo);
    }
}

void AddReportLossListView::init()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new AddReportLossDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
