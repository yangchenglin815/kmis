#include "CategoryListView.h"
#include "../KPosSet/AdjustPositionWidget.h"
#include "../data/constData.h"
#include <QApplication>
#include <QDebug>

enum CategorySellItemROLE
{
    e_CategorySellItemInfo = Qt::UserRole + 1,
};

CategoryDelegate::CategoryDelegate(QWidget *parent)
    : QStyledItemDelegate( parent )
    , m_pButton(NULL)
    , m_nPicLen(19)
    , m_bSetPage(false)
{
    init();
}

CategoryDelegate::~CategoryDelegate()
{
    if (m_pButton != NULL)
    {
        m_pButton->deleteLater();
        m_pButton = NULL;
    }
}

void CategoryDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();

    QVariant vItemInfo = index.data(e_CategorySellItemInfo);
    if( vItemInfo.canConvert<CategoryInfo>() )
    {
        CategoryInfo categoryInfo = vItemInfo.value<CategoryInfo>();
        if((option.state & QStyle::State_Selected) && categoryInfo.nId >0)
        {
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/goods_category_btn_press.png"));
        }
        else
        {
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/goods_category_btn_normal.png"));
        }
        if (categoryInfo.nId >0)
        {
            paintContent(painter, option, categoryInfo);
        }
    }

    painter->restore();
}

void CategoryDelegate::setSetPageFlag(bool bSetPage)
{
    m_bSetPage = bSetPage;
}

//用来处理代理的单击和双击事件
bool CategoryDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    QMouseEvent *pEvent = static_cast<QMouseEvent*>(event);
    QPoint mousePoint = pEvent->pos();
    int nPicXPos = option.rect.x() + option.rect.width() - m_nPicLen;
    QRect deleteRect = QRect(nPicXPos, option.rect.y(), m_nPicLen, m_nPicLen);
    if (event->type() == QEvent::MouseButtonPress) // 鼠标按下
    {
        QVariant vItemInfo = index.data(e_CategorySellItemInfo);
        if(vItemInfo.canConvert<CategoryInfo>())
        {
            CategoryInfo categoryInfo = vItemInfo.value<CategoryInfo>();
            if (categoryInfo.nId > 0)
            {
                if (m_bSetPage)
                {
                    if (deleteRect.contains(mousePoint))
                    {
                        emit sigDeleteCategory(categoryInfo.sKeyId);
                    }
                    else
                    {
                        emit sigItemClicked(categoryInfo.sKeyId);
                    }
                }
                else
                {
                    emit sigItemClicked(categoryInfo.sKeyId);
                }

            }
        }
    }
    else if (event->type() == QEvent::MouseButtonDblClick) // 鼠标双击
    {
        if (m_bSetPage)
        {
            QVariant vItemInfo = index.data(e_CategorySellItemInfo);
            if(vItemInfo.canConvert<CategoryInfo>())
            {
                CategoryInfo categoryInfo = vItemInfo.value<CategoryInfo>();
                if (categoryInfo.nId > 0)
                {
                    if (!deleteRect.contains(mousePoint))
                    {
                        emit sigItemDbClicked(categoryInfo.sKeyId);
                    }
                }
            }
        }
    }

    return QStyledItemDelegate::editorEvent(event, model, option, index);
}

void CategoryDelegate::paintContent( QPainter *painter, const QStyleOptionViewItem &option, CategoryInfo &stCategory ) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    QFont font;
    const int nfontSize = 12*g_widthRate;
    font.setPixelSize(nfontSize);
    font.setFamily("微软雅黑");
    painter->setFont(font);
    QPen pen;
    pen.setColor( "#ffffff");
    painter->setPen(pen);

    int nlen = stCategory.sName.length();
    if(nlen > 4)//当大于4个字符时候
    {
        QRect textRect = QRect(xPos + 18 * g_widthRate, yPos + 12 * g_widthRate, nfontSize * 4, option.rect.height());
        painter->drawText(textRect, Qt::TextWrapAnywhere, stCategory.sName);
    }
    else{
        QRect textRect = QRect(xPos, yPos, option.rect.width(), option.rect.height());
        painter->drawText(textRect, Qt::AlignCenter, stCategory.sName);
    }

    if (m_bSetPage && stCategory.bCustom)
    {
        QStyleOptionButton button;
        int nPicXPos = xPos + option.rect.width() - m_nPicLen;
        button.rect = QRect(nPicXPos, yPos, m_nPicLen, m_nPicLen);
        QApplication::style()->drawControl(QStyle::CE_PushButton, &button, painter, m_pButton);
    }
}

void CategoryDelegate::init()
{
    m_pButton = new QPushButton;
    m_pButton->setFocusPolicy( Qt::NoFocus );
    m_pButton->resize(m_nPicLen, m_nPicLen);
    m_pButton->setStyleSheet("border:none;border-image:url(:/kPosSetImage/close.png)");
}

CategoryListView::CategoryListView(QWidget *parent)
    : QListView(parent)
    , m_pStandardItemModel(NULL)
    , m_pCategoryDelegate(NULL)
    , m_nItemHeight(54)
    , m_nItemWidth(82)
    , m_sSelectedKeyId("")
    , m_nSelectedPos(-1)
    , m_nStartPosition(0)
    , m_bSetPage(false)
    , m_bDbClick(false)
{
    init();
    initConnect();
//    setAttribute( Qt::WA_TranslucentBackground, true );//背景透明
}

CategoryListView::~CategoryListView()
{

}

void CategoryListView::setWidth(int width)
{
    m_nItemWidth = width;
}

void CategoryListView::setHeight(int height)
{
    m_nItemHeight = height;
}

void CategoryListView::appendItem(const CategoryInfo &stCategoryInfo )
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (!m_ItemKeyIdMap.contains(stCategoryInfo.sKeyId))
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(stCategoryInfo.sKeyId, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(m_nItemWidth, m_nItemHeight));//设置图元大小
    }
    else
    {
        pItem = m_ItemKeyIdMap.value(stCategoryInfo.sKeyId);
    }
    QVariant variant;
    variant.setValue(stCategoryInfo);
    pItem->setData(variant, e_CategorySellItemInfo );

    if (m_sSelectedKeyId == stCategoryInfo.sKeyId)
    {
        this->setCurrentIndex(pItem->index());
    }
}

void CategoryListView::clearItems()
{
    m_pStandardItemModel->clear();
    m_ItemKeyIdMap.clear();
}

void CategoryListView::setSelectedKeyId( QString strCurCategoryKeyId )
{
    m_sSelectedKeyId = strCurCategoryKeyId;
}

bool CategoryListView::isSelectedEmptyKeyId()
{
    return m_sSelectedKeyId.isEmpty();
}

QString CategoryListView::getSelectedKeyId()
{
    return m_sSelectedKeyId;
}

void CategoryListView::setSetPageFlag(bool bSetPage)
{
    m_bSetPage = bSetPage;
    if (m_pCategoryDelegate != NULL)
    {
        m_pCategoryDelegate->setSetPageFlag(bSetPage);
    }
}

void CategoryListView::setStartPosition(int nStartPosition)
{
    m_nStartPosition = nStartPosition;
}

void CategoryListView::mousePressEvent(QMouseEvent *event)
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

void CategoryListView::mouseDoubleClickEvent(QMouseEvent *event)
{  
    QListView::mouseDoubleClickEvent(event);
}

void CategoryListView::slot_itemClicked(QString strCategoryKeyId)
{
    if (m_sSelectedKeyId != strCategoryKeyId)
    {
        m_sSelectedKeyId = strCategoryKeyId;
        emit sigItemClicked(m_sSelectedKeyId);
    }

    if (m_bSetPage)
    {
        AdjustPositionWidget::instance()->hide();
        if (!m_timer.isActive())
        {
            m_timer.start(500);
        }
    }
}

void CategoryListView::slot_itemDbClicked(QString strCategoryKeyId)
{
    m_bDbClick = true;
    emit sigItemDbClicked(strCategoryKeyId);
}

void CategoryListView::slot_deleteCategory(QString strCategoryKeyId)
{
    emit sigDeleteCategory(strCategoryKeyId);
}

void CategoryListView::slot_checkClickType()
{
    m_timer.stop();
    if (m_bDbClick)
    {
        m_bDbClick = false;
        return;
    }

    showAdjustWidget();
}

void CategoryListView::init()
{
    //拥有下面三行代码，listView可以一行显示多列；如果没有下面三行代码，listView一行只能显示为一列
    setViewMode(IconMode);
    setMovement(Static);
    setSpacing(0);

    //没有滚动条
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pCategoryDelegate = new CategoryDelegate(this);
    setItemDelegateForColumn(0, m_pCategoryDelegate);//设置图元代理forColumn
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode( SingleSelection );//单选
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}

void CategoryListView::initConnect()
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(slot_checkClickType()));
    connect(m_pCategoryDelegate, SIGNAL(sigItemClicked(QString)), this, SLOT(slot_itemClicked(QString)));
    connect(m_pCategoryDelegate, SIGNAL(sigItemDbClicked(QString)), this, SLOT(slot_itemDbClicked(QString)));
    connect(m_pCategoryDelegate, SIGNAL(sigDeleteCategory(QString)), this, SLOT(slot_deleteCategory(QString)));
}

void CategoryListView::showAdjustWidget()
{
    AdjustPositionWidget *pInstance = AdjustPositionWidget::instance();
    int nAdjustWidgetWidth = pInstance->width();
    const int nArrowHeight = 9;
    QPoint globalPoint = this->mapToGlobal(QPoint(0, 0));
    int nXPos = globalPoint.x() - (nAdjustWidgetWidth - this->width())/2;
    int nYPos = globalPoint.y() + this->height() - nArrowHeight;
    pInstance->setPosition(m_nStartPosition + m_nSelectedPos + 1);
    pInstance->setOwnerType(e_categorySet);
    pInstance->move(nXPos, nYPos);
    pInstance->activateWindow();
    pInstance->showNormal();
}

