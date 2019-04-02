#include "YearCalendarListView.h"
#include <QDebug>

static const int c_nItemHeight = 20;
static const int c_nItemWidth = 48;
//int gHorizontalSpace = 3;//水平间隔
//int gVerticalSPace = 3;//垂直间隔
//static int nButtonLeftXPos = 0;
//static int nButtonRightXPos = 0;
//static int nButtonTopYPos = 0;
//static int nButtonBottomYPos = 0;

enum YearCalendarItemROLE
{
    e_YearCalendarItemInfo = Qt::UserRole + 1,
};


YearCalendarDelegate::YearCalendarDelegate( QWidget *parent )
    : QStyledItemDelegate( parent )
{

}

void YearCalendarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();

    QVariant vItemInfo = index.data( e_YearCalendarItemInfo );
    if( vItemInfo.canConvert<CategoryInfo>() ) {
        YearInfo stYearInfo = vItemInfo.value<YearInfo>();

        paintYearBtn( painter, option, stYearInfo );
    }

    painter->restore();
}

void YearCalendarDelegate::paintYearBtn(QPainter *painter, const QStyleOptionViewItem &option, YearInfo &stYearInfo) const
{

}

void YearCalendarDelegate::drawYearImage(QPainter *painter, QRect textRect, bool bSelected) const
{

}

YearCalendarListView::YearCalendarListView(QWidget *parent)
    : QListView(parent)
    , m_nCurYearId( 1980 )
{
    init();
}

YearCalendarListView::~YearCalendarListView()
{

}

void YearCalendarListView::appendItem(const YearInfo &rInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_mapItemKeyId.contains( rInfo.nId))
    {
        pItem = new QStandardItem;
        m_mapItemKeyId.insert( rInfo.nId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(c_nItemWidth, c_nItemHeight));//设置图元大小
    }
    else
    {
        pItem = m_mapItemKeyId.value( rInfo.nId);
    }
    QVariant variant;
    variant.setValue( rInfo );
    pItem->setData(variant, e_YearCalendarItemInfo );

    if ( m_nCurYearId == rInfo.nYearId )
    {
        this->setCurrentIndex( pItem->index() );
    }

}

void YearCalendarListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_mapItemKeyId.clear();
}

void YearCalendarListView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent( event );

    //获取选中状态
    QModelIndex index = indexAt(event->pos());
    YearInfo stYearInfo;
    QVariant v_itemInfo = index.data( e_YearCalendarItemInfo );
    if (!v_itemInfo.canConvert<YearInfo>())//可以转换
    {
        return;
    }
    stYearInfo = v_itemInfo.value<YearInfo>();
    m_stYearInfo = stYearInfo;

    if( m_nCurYearId != stYearInfo.nYearId ) {
        m_nCurYearId = stYearInfo.nYearId;
        this->setCurrentIndex( index );//使用当前索引，选中图元
        emit sig_yearInfoClicked( m_nCurYearId );
    }
}

void YearCalendarListView::init()
{
    //拥有下面三行代码，listView可以一行显示多列；如果没有下面三行代码，listView一行只能显示为一列
    setViewMode(IconMode);
    setMovement(Static);
    setSpacing(26);

    //没有滚动条
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setItemDelegateForColumn( 0, new YearCalendarDelegate(this));//设置图元代理forColumn
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode( SingleSelection );//单选
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}
