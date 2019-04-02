#include "ReceiptRefundDlg.h"
#include "ui_ReceiptRefundDlg.h"

ReceiptRefundDlg::ReceiptRefundDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReceiptRefundDlg)
    , m_nOnePageCount(2)
    , m_nCurPage(1)
    , m_nTotalPage(1)
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint );
    ui->titleWidget->setTitleText(QStringLiteral("有小票退款"));
    initConnect();
    test();
}

ReceiptRefundDlg::~ReceiptRefundDlg()
{
    delete ui;
}

void ReceiptRefundDlg::test()
{
    for (int i = 0; i < 10; i++)
    {
        RefundWithReceiptInfo refundWithReceiptInfo;
        refundWithReceiptInfo.sRefundSequence = QString("20265845%1").arg(i);
        if (i%3 == 0)
        {
          refundWithReceiptInfo.sRefundWay = QStringLiteral("支付宝");
          refundWithReceiptInfo.sRefundState = QStringLiteral("成功");
        }
        else if (i%3 == 1)
        {
            refundWithReceiptInfo.sRefundWay = QStringLiteral("微信");
            refundWithReceiptInfo.sRefundState = QStringLiteral("失败");
        }
        else
        {
            refundWithReceiptInfo.sRefundWay = QStringLiteral("其他");
            refundWithReceiptInfo.sRefundState = QStringLiteral("正在进行...");
        }
        refundWithReceiptInfo.nRefundSum = 12.34;
        m_refundInfoList.append(refundWithReceiptInfo);
    }

    int nLen = m_refundInfoList.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    m_nCurPage = 1;
    checkCurPageButtonState();
    generateUI();
}

void ReceiptRefundDlg::on_cashRefundButton_clicked()
{

}

void ReceiptRefundDlg::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void ReceiptRefundDlg::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void ReceiptRefundDlg::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_refundInfoList.length();
    for (int i = nStartPos; (i < nEndPos) && (i < nCount); i++)
    {
        m_refundInfoList[i].nPos = i + 1;
        ui->listView->appendItem(m_refundInfoList[i]);
    }
}

void ReceiptRefundDlg::checkCurPageButtonState()
{
    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        ui->lastPageButton->setEnabled(false);
    }
    else
    {
        ui->lastPageButton->setEnabled(true);
    }

    if (m_nCurPage < m_nTotalPage)
    {
        ui->nextPageButton->setEnabled(true);
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        ui->nextPageButton->setEnabled(false);
    }
}

void ReceiptRefundDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
}


