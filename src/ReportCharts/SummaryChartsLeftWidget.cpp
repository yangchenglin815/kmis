#include "SummaryChartsLeftWidget.h"
#include "ui_SummaryChartsLeftWidget.h"

SummaryChartsLeftWidget::SummaryChartsLeftWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SummaryChartsLeftWidget)
    , m_nOnePageCount(13)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    test();
}

SummaryChartsLeftWidget::~SummaryChartsLeftWidget()
{
    delete ui;
}

void SummaryChartsLeftWidget::test()
{
    SummaryChartsInfo* pSummaryChartsInfo = NULL;
    float fSaleSumMoney = 0.0f;
    float fPeopleSumMoney = 0.0f;
    for (int i = 0; i < 24; i++)
    {
        pSummaryChartsInfo = new SummaryChartsInfo;
        if (i < 10)
        {
            pSummaryChartsInfo->sTimePeriod = QString("0%1:00-0%1:59").arg(i);// 时段
        }
        else
        {
            pSummaryChartsInfo->sTimePeriod = QString("%1:00-%1:59").arg(i);// 时段
        }
        pSummaryChartsInfo->fSaleMoney = QString("%1.%2").arg(qrand()%1000).arg(qrand()%100).toFloat(); // 销售额
        fSaleSumMoney += pSummaryChartsInfo->fSaleMoney;
        pSummaryChartsInfo->nPeopleNumber = QString("%1").arg(1 + qrand()%100).toInt(); // 客流量
        fPeopleSumMoney += pSummaryChartsInfo->nPeopleNumber;
        pSummaryChartsInfo->fPeoplePrice = pSummaryChartsInfo->fSaleMoney / pSummaryChartsInfo->nPeopleNumber;// 客单价
        m_summaryChartsInfoList.append(pSummaryChartsInfo);
    }

    ui->saleSumMoneyLabel->setText(QString::number(fSaleSumMoney, 'f', 2));
    ui->peopleSumNumberLabel->setText(QString::number(fPeopleSumMoney, 'f', 2));

    m_nCurPage = 1;
    int nCount = m_summaryChartsInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void SummaryChartsLeftWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void SummaryChartsLeftWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void SummaryChartsLeftWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_summaryChartsInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(*(m_summaryChartsInfoList[i]));
    }
}

void SummaryChartsLeftWidget::checkCurPageButtonState()
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
