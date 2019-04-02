#include "PaymentDetailView.h"
#include <QPainter>
#include <QMouseEvent>
#include "EnumToString.h"
#include "CommonFun.h"

static const int c_nItemHeight = 56;
static int nbuttonLeftXPos;
static int nbuttonRightXPos;

enum PaymentDetailItemROLE
{
    e_PaymentDetailItemInfo = Qt::UserRole + 1
};

PaymentDetailDelegate::PaymentDetailDelegate()
{

}

void PaymentDetailDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QVariant v_itemInfo = index.data(e_PaymentDetailItemInfo);
    if (v_itemInfo.canConvert<PaymentDetailInfo>())
    {
        bool bSelected = false;
        if (option.state & QStyle::State_Selected)
        {
            bSelected = true;
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/rect.png"));
        }
        else
        {
            bSelected = false;
        }
        PaymentDetailInfo paymentDetailInfo = v_itemInfo.value<PaymentDetailInfo>();
        if( paymentDetailInfo.ePayMethod == Coupon ) {
            bSelected = true;
            painter->drawPixmap(option.rect, QPixmap(":/saleImage/rect.png"));
        }
        paintPaymentDetailInfo(painter, option, paymentDetailInfo, bSelected, paymentDetailInfo.eButtonStatus );
    }

    painter->restore();
}

void PaymentDetailDelegate::paintPaymentDetailInfo(QPainter *painter, const QStyleOptionViewItem &option, const PaymentDetailInfo &rInfo, bool bSelected, EButtonStatus eButtonStatus ) const
{
    int xPos = option.rect.x();
    int yPos = option.rect.y();
    static const int c_nLeftMargin = 0;
    const int c_nFirstStartX = xPos + c_nLeftMargin;
    static const int c_nFirstColWidth = 60;
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

    // 第一列序号
    QRect textRect(c_nFirstStartX, yPos, c_nFirstColWidth, c_nItemHeight);
    painter->drawText(textRect, Qt::AlignHCenter | Qt::AlignVCenter, QString::number(rInfo.nPos));

    // 第二列支付方式
    const int c_nSecondStartX = c_nFirstStartX + c_nFirstColWidth;
    static const int c_nSecondColWidth = 82;
    QRect textRect2(c_nSecondStartX, yPos, c_nSecondColWidth, c_nItemHeight);
    QString strPayMethod = EnumToString::payMethodToString( rInfo.ePayMethod );
    painter->drawText(textRect2, Qt::AlignHCenter | Qt::AlignVCenter, strPayMethod );

    // 第三列支付金额
    const int c_nThirdStartX = c_nSecondStartX + c_nSecondColWidth;
    static const int c_nThirdColWidth = 115;
    QRect textRect3(c_nThirdStartX, yPos, c_nThirdColWidth, c_nItemHeight);
    if( rInfo.ePayMethod == PayMemCard && rInfo.strIntExchangeAmt.toFloat() != 0 ) {
        float fMemAll = rInfo.fPaymentSum + rInfo.nPayIntegral * rInfo.strIntExchangeAmt.toFloat();
        QString strMemAll = CommonFun::floatToString( fMemAll );
        painter->drawText(textRect3, Qt::AlignHCenter | Qt::AlignVCenter, strMemAll );
    } else {
        painter->drawText(textRect3, Qt::AlignHCenter | Qt::AlignVCenter, QString("￥%1").arg(rInfo.fPaymentSum));
    }
    // 第四列支付状态
    if ( rInfo.ePaymentState == e_PayFailed )
    {
        QPen pen2;
        pen2.setColor("#ea8852");
        painter->setPen(pen2);
    }
    else
    {
        QPen pen2;
        if (bSelected)
        {
           pen2.setColor("#ffffff");
        }
        else
        {
            pen2.setColor("#666666");
        }
        painter->setPen(pen2);
    }

    const int c_nFourthStartX = c_nThirdStartX + c_nThirdColWidth;
    static const int c_nFourthColWidth = 90;
    QRect textRect4(c_nFourthStartX, yPos, c_nFourthColWidth, c_nItemHeight);
    QString strPayStatus = PayStatusToString( rInfo.ePaymentState );
    painter->drawText(textRect4, Qt::AlignHCenter | Qt::AlignVCenter, strPayStatus );

    // 第五列操作按钮
    const int c_nButtonPicWidth = 80;
    const int c_nButtonPicHeight = 40;
    const int c_nButtonPicTopMargin = (c_nItemHeight - c_nButtonPicHeight)/2;
    const int c_nFifthWidth = 122;
    const int c_nFifthStartX = option.rect.width() - c_nFifthWidth;
    const int c_nFifthStartY = yPos + c_nButtonPicTopMargin;
    QRect pixmapRect5(c_nFifthStartX, c_nFifthStartY, c_nButtonPicWidth, c_nButtonPicHeight);

    QPixmap buttonPixmap = QPixmap(":/paymentImage/refund_disable.png");
//    if( eButtonStatus == eDisAble ) {
//        buttonPixmap = QPixmap(":/paymentImage/refund_disable.png");
//    } else if( eButtonStatus == ePress ) {
//        buttonPixmap = QPixmap(":/paymentImage/refund_press.png");
//    } else if( eButtonStatus == eNormal ) {
//        buttonPixmap = QPixmap(":/paymentImage/refund_nomal.png");
//    }
    buttonPixmap = buttonPixmap.scaled(c_nButtonPicWidth, c_nButtonPicHeight);
    painter->drawPixmap(pixmapRect5, buttonPixmap);

    QFont buttonFont;
    buttonFont.setPixelSize(12);
    buttonFont.setFamily("微软雅黑");
    painter->setFont(buttonFont);
    QPen buttonPen;
    buttonPen.setColor("#ffffff");
    painter->setPen(buttonPen);
    QRect textRect5(c_nFifthStartX - 4, yPos, c_nButtonPicWidth, c_nItemHeight);
    painter->drawText(textRect5, Qt::AlignHCenter | Qt::AlignVCenter, QStringLiteral("退款"));
    nbuttonLeftXPos = c_nFifthStartX;
    nbuttonRightXPos = c_nFifthStartX + c_nButtonPicWidth;

    // 分割线
    QPen linePen;
    linePen.setColor("#ededed");
    painter->setPen(linePen);
    painter->drawLine(xPos, yPos + c_nItemHeight-1, xPos + option.rect.width(), yPos + c_nItemHeight-1);
}

QString PaymentDetailDelegate::PayTypeToString( EPaymentType ePaymentType ) const
{
    QString strPayType = "";
    switch( ePaymentType ) {
    case e_Payment:
        strPayType = "付款";
        break;
    case e_Refund:
        strPayType = "退款";
        break;
    default:
        strPayType = "其他";
        break;
    }
    return strPayType;
}

QString PaymentDetailDelegate::PayStatusToString( EPaymentState ePaymentState ) const
{
    QString strPayStatus = "";
    switch( ePaymentState ) {
    case e_PaySuccess:
        strPayStatus = "成功";
        break;
    case e_PayFailed:
        strPayStatus = "失败";
        break;
    case e_PayRefund:
        strPayStatus = "已退款";
        break;
    default:
        strPayStatus = "其他";
        break;
    }

    return strPayStatus;
}


PaymentDetailView::PaymentDetailView(QWidget *parent)
    : QListView(parent)
{
    init();
}

PaymentDetailView::~PaymentDetailView()
{
    clearItem();
}

void PaymentDetailView::appendItem(const PaymentDetailInfo &rInfo)
{
    if (m_pStandardItemModel == NULL)
    {
        return;
    }

    QStandardItem* pItem = NULL;
    if (m_ItemKeyIdMap.contains(rInfo.nPos ))// 更新
    {
        pItem = m_ItemKeyIdMap.value(rInfo.nPos);
    }
    else // 添加
    {
        pItem = new QStandardItem;
        m_ItemKeyIdMap.insert(rInfo.nPos, pItem);
        m_pStandardItemModel->appendRow(pItem);
        pItem->setSizeHint(QSize(0, c_nItemHeight));
    }

    QVariant variant;
    variant.setValue(rInfo);
    pItem->setData(variant, e_PaymentDetailItemInfo);

    setEnabled( true );
}

void PaymentDetailView::clearItem()
{
    if (m_pStandardItemModel != NULL)
    {
        m_pStandardItemModel->clear();
    }
    m_ItemKeyIdMap.clear();
}

void PaymentDetailView::mousePressEvent(QMouseEvent *event)
{
    QListView::mousePressEvent(event);
    QModelIndex index = indexAt(event->pos());
    QVariant v_orderItemInfo = index.data(e_PaymentDetailItemInfo);
    if (!v_orderItemInfo.canConvert<PaymentDetailInfo>())
    {
        return;
    }

    PaymentDetailInfo paymentDetailInfo = v_orderItemInfo.value<PaymentDetailInfo>();
    if (event->pos().x() >= nbuttonLeftXPos && event->pos().x() <= nbuttonRightXPos)
    {
        //if( paymentDetailInfo.eButtonStatus == ePress ) return;

        if( paymentDetailInfo.ePayType != e_Refund && paymentDetailInfo.ePaymentState == e_PaySuccess ) {
            setEnabled( false );
            paymentDetailInfo.eButtonStatus = ePress;
            appendItem( paymentDetailInfo );

            float fIntToAmt = 0.00;
            if( paymentDetailInfo.ePayMethod == PayMemCard && paymentDetailInfo.strIntExchangeAmt.toFloat() > 0 ) {
                fIntToAmt = paymentDetailInfo.nPayIntegral * paymentDetailInfo.strIntExchangeAmt.toFloat();
            }
            //emit sigButtonClicked( paymentDetailInfo.ePayMethod, paymentDetailInfo.strPaymentOrderNum, paymentDetailInfo.fPaymentSum + fIntToAmt, paymentDetailInfo.bVirtual );
        }
    }
}

void PaymentDetailView::mouseReleaseEvent( QMouseEvent *event)
{
    QListView::mouseReleaseEvent(event);
    QModelIndex index = indexAt(event->pos());
    QVariant v_orderItemInfo = index.data(e_PaymentDetailItemInfo);
    if (!v_orderItemInfo.canConvert<PaymentDetailInfo>())
    {
        return;
    }

    PaymentDetailInfo paymentDetailInfo = v_orderItemInfo.value<PaymentDetailInfo>();
    if (event->pos().x() >= nbuttonLeftXPos && event->pos().x() <= nbuttonRightXPos)
    {
        if( paymentDetailInfo.ePayType != e_Refund && paymentDetailInfo.ePaymentState == e_PaySuccess ) {
            paymentDetailInfo.eButtonStatus = eNormal;
            appendItem( paymentDetailInfo );
            //emit sigButtonRelease( paymentDetailInfo.ePayMethod, paymentDetailInfo.strPaymentOrderNum );
        }
    }
}

void PaymentDetailView::init()
{
    setItemDelegateForColumn(0, new PaymentDetailDelegate);
    setEditTriggers(QAbstractItemView::NoEditTriggers); // 只读
    setSelectionMode( QAbstractItemView::NoSelection );//listView不能选中
    m_pStandardItemModel = new QStandardItemModel(this);
    this->setModel(m_pStandardItemModel);
}

