#include "Inquire.h"
#include "ui_Inquire.h"
#include <QDebug>
#include "../data/enumData.h"
#include "../data/constData.h"
#include "../util/CommonFun.h"
#include "ScreenInfo.h"

//#ifdef Q_OS_WIN
//#pragma execution_character_set("utf-8")
//#endif

Inquire::Inquire(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inquire)
  , m_nOnePageCount(7)
  , m_nTotalPage(1)
  , m_nCurPage(1)
{
    ui->setupUi(this);
   ScreenInfo::resetGrid(this);
    initConnect();
}

Inquire::~Inquire()
{
    delete ui;
}

void Inquire::initData(QString sTotal,const QList<InStockOrderSearchInfo> &orderInfoList)
{
    m_backUpOrderInfoList = orderInfoList;
    ui->totalLabel->setText(QString("￥%1").arg(sTotal));
    initSearchData(orderInfoList);
}

void Inquire::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void Inquire::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void Inquire::slot_searchChanged(QString searchText)
{
    if (searchText.isEmpty())
    {
        initSearchData(m_backUpOrderInfoList);
    }
    else
    {
        QList<InStockOrderSearchInfo> orderInfoList;
        InStockOrderSearchInfo searchInfo;
        int nLen = m_backUpOrderInfoList.length();
        for (int i = 0; i < nLen; i++)
        {
            searchInfo = m_backUpOrderInfoList[i];
            if ((searchInfo.sCode == searchText)
                    || (searchInfo.sBarCode == searchText)
                    || searchInfo.sName.contains(searchText)
                    || searchInfo.sPinYinName.contains(searchText)
                    || searchInfo.sWuBiName.contains(searchText))
            {
                orderInfoList.append(searchInfo);
            }
        }
        initSearchData(orderInfoList);
    }
}

void Inquire::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_orderInfoList.length();
    for (int i = nStartPos; (i < nEndPos) && (i < nCount); i++)
    {
        m_orderInfoList[i].sSeq = QString::number(i+1);
        ui->listView->appendItem(m_orderInfoList[i]);
    }
}

void Inquire::checkCurPageButtonState()
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

void Inquire::initConnect()
{
    connect(ui->searchWidget, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
}

void Inquire::initSearchData(const QList<InStockOrderSearchInfo> &orderInfoList)
{
    m_orderInfoList = orderInfoList;
    int nLen = m_orderInfoList.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    checkCurPageButtonState();
    generateUI();
}

