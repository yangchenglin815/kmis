#include "ReceiptDetialInfoWidget.h"
#include "constData.h"
#include <QMouseEvent>
#include <QPainter>
#include "EnumToString.h"

ReceiptDetialInfoWidget::ReceiptDetialInfoWidget(QWidget *parent) : QWidget(parent)
{

}

void ReceiptDetialInfoWidget::initData(const SaleHead &saleHead, const QList<PaymentDetailInfo> &paymentInfoList)
{
   m_saleHead = saleHead;
   m_paymentInfoList = paymentInfoList;
}

void ReceiptDetialInfoWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), QBrush("#fafafa"));

    QFont font;
    font.setPixelSize(f_fontSizeMode2*g_widthRate);
    font.setFamily(f_fontStyle);
    painter.setFont(font);
    QPen pen;
    pen.setColor("#000000");
    painter.setPen(pen);

    int nHeight = this->height();
    int nWidth = this->width();
    int xPos = 0;
    int yPos = 0;

    static const int leftSpace = 10*g_widthRate;
    // *宽度 坐标
    static const int c_sColWidth = nWidth - 2*leftSpace;
    static const int sWidth = 8;
    int sXPos = xPos + leftSpace;
    int sYPos = yPos + leftSpace;
    // 正文部分
    static const int topSpace = 20*g_widthRate;
    int nXPos = sXPos + sWidth;
    int nYPos = sYPos + topSpace;
    static const int c_nColWidth = c_sColWidth - 2*sWidth;

    for(int i=0; i<c_sColWidth/sWidth; i++){
        QRect rect(sXPos + sWidth*i, sYPos, sWidth, sWidth);
        painter.drawText(rect, "*");
    }

    QRect rect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("门店号 : %1").arg(m_saleHead.nShopId));

    nYPos += topSpace;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("款机号 : %1").arg(m_saleHead.strPosId));

    nYPos += topSpace;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("收银员 : %1").arg(m_saleHead.strCashierName));

    nYPos += topSpace;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("导购员 : %1").arg(m_saleHead.strShoppingName));

    nYPos += topSpace;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("小票编号 : %1").arg(m_saleHead.strOrderNum));

    nYPos += topSpace;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("交易时间 : %1").arg(m_saleHead.dtCompleteTime.toString("yyyy-MM-dd hh:mm:ss")));

    nYPos += topSpace + sWidth;
    QPen spen(QBrush(QColor(f_fontColorGray)), 1, Qt::DashLine);
    painter.setPen(spen);
    painter.drawLine(sXPos,nYPos, c_sColWidth, nYPos);

    pen.setColor(QColor(f_fontColorBlack));
    painter.setPen(pen);
    nYPos += topSpace/2;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("总计金额 : %1").arg(m_saleHead.fOughtAmt));

    nYPos += topSpace;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("总计数量 : %1").arg(m_saleHead.nSaleTotalNum));

    nYPos += topSpace;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("总优惠金额 : %1").arg(m_saleHead.fAllDisAmt));

    nYPos += topSpace;
    pen.setWidth(4);
    painter.setPen(pen);
    painter.drawPoint(nXPos + sWidth, nYPos + f_fontSizeMode1/2);

    rect.setRect(nXPos + 2*sWidth, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("折扣优惠 : %1").arg(m_saleHead.fGrantDisRate));

    nYPos += topSpace;
    painter.drawPoint(nXPos + sWidth, nYPos + f_fontSizeMode1/2);

    rect.setRect(nXPos + 2*sWidth, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("抹零 : %1").arg(m_saleHead.sSmallChangeAmt));

    nYPos += topSpace;
    painter.drawPoint(nXPos + sWidth, nYPos + f_fontSizeMode1/2);

    rect.setRect(nXPos + 2*sWidth, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("优惠券 : %1").arg(m_saleHead.fCouponDisAmt));

    nYPos += topSpace;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("应收金额 : %1").arg(m_saleHead.fFactorAmt));

    nYPos += topSpace;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("实收金额 : %1").arg(m_saleHead.fFactorAmt + m_saleHead.fProfitLoss));

    nYPos += topSpace;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, QStringLiteral("找零金额 : %1").arg(m_saleHead.actChange));

    nYPos += topSpace + sWidth;
    QPen spen1(QBrush(QColor(f_fontColorGray)), 1, Qt::DashLine);
    painter.setPen(spen1);
    painter.drawLine(sXPos,nYPos, c_sColWidth, nYPos);

    pen.setColor(QColor(f_fontColorBlack));
    painter.setPen(pen);
    nYPos += topSpace/2;
    rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
    painter.drawText(rect, "付款方式");

    int nLen = m_paymentInfoList.length();
    for(int i=0; i<nLen; i++){
        nYPos += topSpace;
        rect.setRect(nXPos, nYPos, c_nColWidth, f_fontSizeMode1);
        QString str = EnumToString::payMethodToString(m_paymentInfoList[i].ePayMethod);
        painter.drawText(rect, QString("%1 : %2").arg(str).arg(m_paymentInfoList[i].fPaymentSum));
    }

    for(int i=0; i<c_sColWidth/sWidth; i++){
        QRect rect(sXPos + sWidth*i, nHeight - topSpace, sWidth, sWidth);
        painter.drawText(rect, "*");
    }
}

