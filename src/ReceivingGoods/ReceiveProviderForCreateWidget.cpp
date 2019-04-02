#include "ReceiveProviderForCreateWidget.h"
#include "ui_ReceiveProviderForCreateWidget.h"
#include <QDebug>

ReceiveProviderForCreateWidget::ReceiveProviderForCreateWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReceiveProviderForCreateWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    ui->searchEdit->setHintText(QStringLiteral("输入供应商名称或编号"));
    initConnect();
}

ReceiveProviderForCreateWidget::~ReceiveProviderForCreateWidget()
{
    delete ui;
}

void ReceiveProviderForCreateWidget::initData(const QList<ReceiveProviderInfo *> &receiveProviderInfoList)
{
    m_receiveProviderInfoList = receiveProviderInfoList;
    m_nCurPage = 1;
    int nCount = m_receiveProviderInfoList.length();
    m_nTotalPage = nCount / m_nOnePageCount + ((nCount % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

void ReceiveProviderForCreateWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void ReceiveProviderForCreateWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void ReceiveProviderForCreateWidget::slot_searchChanged(QString searchText)
{
    emit sigSearchChanged(searchText);
}

void ReceiveProviderForCreateWidget::slot_clickProveder(int nProviderId)
{
    emit sigClickProvider(nProviderId);
}

void ReceiveProviderForCreateWidget::initConnect()
{
    connect(ui->searchEdit, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
    connect(ui->listView, SIGNAL(sigClickProvider(int)), this, SLOT(slot_clickProveder(int)));
}

void ReceiveProviderForCreateWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_receiveProviderInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(*(m_receiveProviderInfoList[i]));
    }
}

void ReceiveProviderForCreateWidget::checkCurPageButtonState()
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
