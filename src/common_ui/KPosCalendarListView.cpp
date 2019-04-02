#include "KPosCalendarListView.h"
#include <QPainter>
#include <QMouseEvent>

enum KPosCalendarType
{
    e_kPosCalendarInfo,
};

KPosCalendarDelegate::KPosCalendarDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void KPosCalendarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_kPosCalendarInfo);
    if (v_itemInfo.canConvert<CalendarInfo>())
    {
        CalendarInfo calendarInfo = v_itemInfo.value<CalendarInfo>();
        if (calendarInfo.nDay <= 0)
        {
            painter->restore();
            return;
        }

        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            QRect rect = option.rect;
            int nHeight = rect.height();
            int nWidth = rect.width();
            rect.setLeft(rect.left() + (nWidth - nHeight)/2);
            rect.setRight(rect.left() + nHeight);
            painter->drawPixmap(rect, QPixmap(":/shareImages/calendarRound.png"));
            bSelected = true;
        }

        paintContent(painter, option, calendarInfo, bSelected);
    }

    painter->restore();
}

void KPosCalendarDelegate::paintContent(QPainter *painter, const QStyleOptionViewItem &option, const CalendarInfo &calendarInfo, bool bSelected) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    int nWidth = option.rect.width();
    int nHeight = option.rect.height();
    QFont font;
    font.setPixelSize(12);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    if (bSelected)
    {
        pen.setColor("#ffffff");
    }
    else
    {
       pen.setColor("#666666");
    }
    painter->setPen(pen);
    QRect numRect(xPos, yPos, nWidth, nHeight);
    painter->drawText(numRect, Qt::AlignHCenter | Qt::AlignVCenter, QString::number(calendarInfo.nDay));
}

KPosCalendarListView::KPosCalendarListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_nItemHeight(24)
    , m_nItemWidth(29)
    , m_nYear(-1)
    , m_nMonth(-1)
{
    init();
}

void KPosCalendarListView::setYearAndMonth(int nYear, int nMonth)
{
    m_nYear = nYear;
    m_nMonth = nMonth;
}

void KPosCalendarListView::appendItem(const CalendarInfo &calendarInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(calendarInfo.nDay))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(calendarInfo.nDay, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(m_nItemWidth, m_nItemHeight));

    }
    else
    {
        pItem = m_ItemKeyIdMap.value(calendarInfo.nDay);
    }
    QVariant variant;
    variant.setValue(calendarInfo);
    pItem->setData(variant, e_kPosCalendarInfo);
    QString sKey = generateKey(m_nYear, m_nMonth, calendarInfo.nDay);
    if (sKey == m_sSelectedKeyId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void KPosCalendarListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void KPosCalendarListView::setDefualtDate(int nYear, int nMonth, int nDay)
{
    m_sSelectedKeyId = generateKey(nYear, nMonth, nDay);
}

void KPosCalendarListView::mousePressEvent(QMouseEvent *event)
{
    //获取选中状态
    QModelIndex index = indexAt(event->pos());

    CalendarInfo calendarInfo;
    QVariant v_itemInfo = index.data(e_kPosCalendarInfo);
    if (v_itemInfo.canConvert<CalendarInfo>())//可以转换
    {
        calendarInfo = v_itemInfo.value<CalendarInfo>();
        m_sSelectedKeyId = generateKey(m_nYear, m_nMonth, calendarInfo.nDay);
        emit sigClickDate(m_nYear, m_nMonth, calendarInfo.nDay);
    }

    QListView::mousePressEvent(event);
}

void KPosCalendarListView::init()
{
    setViewMode(IconMode);
    setMovement(Static);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setItemDelegateForColumn(0, new KPosCalendarDelegate(this));
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}

QString KPosCalendarListView::generateKey(int nYear, int nMonth, int nDay)
{
    return QString("%1+%2+%3").arg(nYear).arg(nMonth).arg(nDay);
}



