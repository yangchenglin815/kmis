#include "ReceiveProviderWidget.h"
#include "ui_ReceiveProviderWidget.h"
#include "../data/constData.h"

ReceiveProviderWidget::ReceiveProviderWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReceiveProviderWidget)
    , m_nOnePageCount(8)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    initConnect();
    ui->searchEdit->setHintText(QStringLiteral("请输入供应商名字或编号"));
//    test();
}

ReceiveProviderWidget::~ReceiveProviderWidget()
{
    delete ui;
}

void ReceiveProviderWidget::test()
{
    m_rootReceiveProviderInfo.nId = c_nNegativeNumber;
    m_rootReceiveProviderInfo.sCode = "";
    m_rootReceiveProviderInfo.sName = QStringLiteral("全部");

    QList<QString> strList;
    strList<<QStringLiteral("水果")<<QStringLiteral("蔬菜")<<QStringLiteral("干果")
          <<QStringLiteral("熟食")<<QStringLiteral("牛羊肉")<<QStringLiteral("水产")
         <<QStringLiteral("豆制品")<<QStringLiteral("粮油")<<QStringLiteral("禽蛋");

    int nLen = strList.length();
    ReceiveProviderInfo receiveProviderInfo;
    for (int i = 0; i < nLen; i++)
    {
        receiveProviderInfo.nId = i;
        receiveProviderInfo.sName = strList[i];
        receiveProviderInfo.sCode = QString("GY201500122%1").arg(i);
        m_receiveProviderInfoList.append(receiveProviderInfo);
    }

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

void ReceiveProviderWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void ReceiveProviderWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void ReceiveProviderWidget::slot_searchChanged(QString searchText)
{
    if (searchText.isEmpty())
    {
        test();
    }
    else
    {
        int nLen = m_receiveProviderInfoList.length();
        QMap<QString, ReceiveProviderInfo> receiveProviderInfoMap;
        for (int i = 0; i < nLen; i++)
        {
            if (m_receiveProviderInfoList[i].sName.contains(searchText)
                    || m_receiveProviderInfoList[i].sCode.contains(searchText))
            {
                receiveProviderInfoMap.insert(m_receiveProviderInfoList[i].sCode, m_receiveProviderInfoList[i]);
            }
        }
        m_receiveProviderInfoList = receiveProviderInfoMap.values();
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

}

void ReceiveProviderWidget::slot_clickProveder(int nProviderId)
{
    if (nProviderId >= 0)
    {
        int nLen = m_receiveProviderInfoList.length();
        for (int i = 0; i < nLen; i++)
        {
            if (m_receiveProviderInfoList[i].nId == nProviderId)
            {
                emit sigClickProvider(m_receiveProviderInfoList[i]);
            }
        }
    }
    else
    {
        emit sigClickProvider(m_rootReceiveProviderInfo);
    }
}

void ReceiveProviderWidget::initConnect()
{
    connect(ui->searchEdit, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
    connect(ui->listView, SIGNAL(sigClickProvider(int)), this, SLOT(slot_clickProveder(int)));
}

void ReceiveProviderWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    ui->listView->appendItem(m_rootReceiveProviderInfo);
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_receiveProviderInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        ui->listView->appendItem(m_receiveProviderInfoList[i]);
    }
}

void ReceiveProviderWidget::checkCurPageButtonState()
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
