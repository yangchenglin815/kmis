#include "ReceiptDetialWidget.h"
#include "ui_ReceiptDetialWidget.h"
#include "ReceiptPictureMaker.h"

ReceiptDetialWidget::ReceiptDetialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReceiptDetialWidget)
  , m_nOnePageCount(8)
  , m_nTotalPage(1)
  , m_nCurPage(1)
{
    ui->setupUi(this);
//    test();
}

ReceiptDetialWidget::~ReceiptDetialWidget()
{
    delete ui;
}

void ReceiptDetialWidget::initData(const QList<SaleDetails> &itemInfoList, const SaleHead &saleHead, const QList<PaymentDetailInfo> &paymentInfoList)
{
    m_InfoList = itemInfoList;
    m_paymentDetialInfo = paymentInfoList;
    m_saleHead = saleHead;
    ui->receiptDetialWidget->initData(saleHead, paymentInfoList);
    ui->receiptDetialWidget->update();
    int nCount = m_InfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void ReceiptDetialWidget::on_nextButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void ReceiptDetialWidget::on_printButton_clicked()
{
    ReceiptPictureMaker::instance()->printSaleDetialReceipt(m_saleHead, m_paymentDetialInfo, m_InfoList);
}

void ReceiptDetialWidget::on_lastButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void ReceiptDetialWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->receiptListView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_InfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->receiptListView->appendItems(m_InfoList[i]);
    }
}

void ReceiptDetialWidget::checkCurPageButtonState()
{
    if (m_nCurPage <= 1)
    {
        m_nCurPage = 1;
        ui->lastButton->setEnabled(false);
    }
    else
    {
        ui->lastButton->setEnabled(true);
    }

    if (m_nCurPage < m_nTotalPage)
    {
        ui->nextButton->setEnabled(true);
    }
    else
    {
        m_nCurPage = m_nTotalPage;
        ui->nextButton->setEnabled(false);
    }
}

void ReceiptDetialWidget::test()
{
//    int nLen = 10;
//    ReceiptDetialInfo *info = NULL;
//    for(int i=0; i<nLen; i++){
//        info = new ReceiptDetialInfo;
//        info->id = i+1;
//        info->sGoodsName = "周末特价红富士苹果";
//        info->sGoodsCode = QString("010000%1").arg(i);
//        info->sGoodsUnit = "(公斤)";
//        info->sGoodsPrice = 999.99;
//        info->sGoodsNum = 99.999;
//        info->sGoodsSumPrice = 999998.00;
//        info->status = 1;
//        m_InfoList.append(*info);
//    }
//    initData(m_InfoList);
}

void ReceiptDetialWidget::init()
{

}

void ReceiptDetialWidget::initconnect()
{

}
