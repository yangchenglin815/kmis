#include "RefundWithReceiptWidget.h"
#include "ui_RefundWithReceiptWidget.h"

RefundWithReceiptWidget::RefundWithReceiptWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RefundWithReceiptWidget)
{
    ui->setupUi(this);
    test();
}

RefundWithReceiptWidget::~RefundWithReceiptWidget()
{
    delete ui;
}

void RefundWithReceiptWidget::test()
{
    for (int i = 0; i < 10; i++)
    {
        RefundWithReceiptInfo *refundWithReceiptInfo = new RefundWithReceiptInfo;
        refundWithReceiptInfo->sRefundSequence = QString("20265845%1").arg(i%10);
        refundWithReceiptInfo->nPos = i + 1;
        if (i%3 == 0)
        {
          refundWithReceiptInfo->sRefundWay = QStringLiteral("支付宝");
          refundWithReceiptInfo->sRefundState = QStringLiteral("成功");
        }
        else if (i%3 == 1)
        {
            refundWithReceiptInfo->sRefundWay = QStringLiteral("微信");
            refundWithReceiptInfo->sRefundState = QStringLiteral("失败");
        }
        else
        {
            refundWithReceiptInfo->sRefundWay = QStringLiteral("其他");
            refundWithReceiptInfo->sRefundState = QStringLiteral("正在进行...");
        }
        refundWithReceiptInfo->nRefundSum = 12.34;
        m_refundInfoList.append(refundWithReceiptInfo);
    }
    generateRefundInfo();
}

void RefundWithReceiptWidget::generateRefundInfo()
{
    int nLen = m_refundInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        ui->listView->appendItem(*m_refundInfoList[i]);
    }
}
