#include "SalemanListView.h"
#include "../KPosSet/AdjustPositionWidget.h"
#include <QApplication>
#include <QDebug>

enum SalemanItemROLE
{
    e_salemanItemInfo = Qt::UserRole + 1,
};

SalemanDelegate::SalemanDelegate(QWidget *parent)
    : QStyledItemDelegate( parent )
    , m_pButton(NULL)
    , m_nPicLen(19)
{
    init();
}

SalemanDelegate::~SalemanDelegate()
{
    if (m_pButton != NULL)
    {
        m_pButton->deleteLater();
        m_pButton = NULL;
    }
}

void SalemanDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();

    QVariant vItemInfo = index.data(e_salemanItemInfo);
    if( vItemInfo.canConvert<SalemanInfo>() )
    {
        SalemanInfo stSalemanInfo = vItemInfo.value<SalemanInfo>();
        if((option.state & QStyle::State_Selected) && stSalemanInfo.nUserId >0)
        {
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/saleman_press.png"));
        }
        else
        {
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/saleman_normal.png"));
        }
        if (stSalemanInfo.nUserId >0)
        {
            paintContent(painter, option, stSalemanInfo);
        }
    }

    painter->restore();
}

//用来处理代理的单击和双击事件
bool SalemanDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonPress) // 鼠标按下
    {
        QVariant vItemInfo = index.data(e_salemanItemInfo);
        if(vItemInfo.canConvert<SalemanInfo>())
        {
            SalemanInfo stSalemanInfo = vItemInfo.value<SalemanInfo>();
            if (stSalemanInfo.nUserId > 0)
            {
                emit sigItemClicked(stSalemanInfo.nUserId);
            }
        }
    }

    return QStyledItemDelegate::editorEvent(event, model, option, index);
}

void SalemanDelegate::paintContent( QPainter *painter, const QStyleOptionViewItem &option, SalemanInfo &stSalemanInfo ) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    QFont font;
    font.setPixelSize(16);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    if( (option.state & QStyle::State_Selected) && stSalemanInfo.nUserId >0 ) {
        pen.setColor( "#ffffff");
    } else {
        pen.setColor( "#ed8c55");
    }
    painter->setPen(pen);
    QRect textRect = QRect(xPos, yPos, option.rect.width(), option.rect.height());
    painter->drawText(textRect, Qt::AlignCenter, stSalemanInfo.sUsername);
}

void SalemanDelegate::init()
{
    m_pButton = new QPushButton;
    m_pButton->resize(m_nPicLen, m_nPicLen);
    m_pButton->setStyleSheet("border:none;border-image:url(:/kPosSetImage/close.png)");
}

SalemanListView::SalemanListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_pSalemanDelegate(NULL)
    , m_nItemHeight(44)
    , m_nItemWidth(90)
    , m_nSelectedUserId( -1 )
    , m_nSelectedPos(-1)
{
    init();
    initConnect();
//    setAttribute( Qt::WA_TranslucentBackground, true );//背景透明
}

SalemanListView::~SalemanListView()
{

}

void SalemanListView::appendItem(const SalemanInfo &stSalemanInfo )
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemUserIdMap.contains(stSalemanInfo.nUserId))
    {
        pItem = new QStandardItem;
        m_ItemUserIdMap.insert(stSalemanInfo.nUserId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(m_nItemWidth, m_nItemHeight));//设置图元大小
    }
    else
    {
        pItem = m_ItemUserIdMap.value(stSalemanInfo.nUserId);
    }
    QVariant variant;
    variant.setValue(stSalemanInfo);
    pItem->setData(variant, e_salemanItemInfo );

//    if ( m_nSelectedUserId == stSalemanInfo.nUserId )
//    {
//        this->setCurrentIndex(pItem->index());
//    }
}

void SalemanListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemUserIdMap.clear();
}

void SalemanListView::setSelectedUserId(int nSalemanUserId )
{
    m_nSelectedUserId = nSalemanUserId;
}

int SalemanListView::getSelectedUserId()
{
    return m_nSelectedUserId;
}

void SalemanListView::mousePressEvent(QMouseEvent *event)
{
    //获取选中状态
    QModelIndex index = indexAt(event->pos());
    int nRow = index.row();
    if (nRow >= 0)
    {
        m_nSelectedPos = nRow;
        this->setCurrentIndex(index);
    }

    QListView::mousePressEvent(event);
}

void SalemanListView::slot_itemClicked(int nSalemanUserId)
{
    if ( m_nSelectedUserId != nSalemanUserId)
    {
        m_nSelectedUserId = nSalemanUserId;
        emit sigItemClicked(m_nSelectedUserId);
    }
}

void SalemanListView::init()
{
    //拥有下面三行代码，listView可以一行显示多列；如果没有下面三行代码，listView一行只能显示为一列
    setViewMode(IconMode);
    setMovement(Static);
    setSpacing(8);

    //没有滚动条
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pSalemanDelegate = new SalemanDelegate(this);
    setItemDelegateForColumn(0, m_pSalemanDelegate);//设置图元代理forColumn
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode( SingleSelection );//单选
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}

void SalemanListView::initConnect()
{
    connect(m_pSalemanDelegate, SIGNAL(sigItemClicked(int)), this, SLOT(slot_itemClicked(int)));
}
