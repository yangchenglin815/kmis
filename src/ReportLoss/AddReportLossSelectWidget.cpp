#include "AddReportLossSelectWidget.h"
#include "ui_AddReportLossSelectWidget.h"

AddReportLossSelectWidget::AddReportLossSelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddReportLossSelectWidget)
  , m_nOnePageCount(6)
  , m_nTotalPage(1)
  , m_nCurPage(1)
{
    ui->setupUi(this);
    initConnect();
//    QList<AddReportLossSelectInfo> m_infoList;
//    AddReportLossSelectInfo info;
//    for(int i=0;i<20;i++){
//       info.id = i+1;
//       info.sCategoryName = "苹果";
//       info.sCode = QString("19880324003%1").arg(i);
//       info.sMoney = 255.00;
//       info.sName = "无籽沙瓤大西瓜精品美味升级版";
//       info.sUnit = "(公斤)";
//       info.sNumber = 25.00;
//       info.sReason = 2;
//       m_infoList.append(info);
//    }
//    initData(m_infoList);
}

AddReportLossSelectWidget::~AddReportLossSelectWidget()
{
    delete ui;
}

void AddReportLossSelectWidget::initData(const QList<AddReportLossSelectInfo> &lossInfoList)
{
    m_lossInfoList = lossInfoList;
    m_nCurPage = 1;
    updateUI();
}

void AddReportLossSelectWidget::appendData(const AddReportLossSelectInfo &lossInfo)
{
    int nPosition = getGoodsPosition(lossInfo.nId);
    if (nPosition < 0)
    {
        m_lossInfoList.append(lossInfo);
        updateUI(true);
    }
    else
    {
        m_lossInfoList[nPosition] = lossInfo;
        updateUI();
    }
}

int AddReportLossSelectWidget::getGoodsPosition(int nId)
{
    if (nId <= 0)
    {
        return -1;
    }

    int nLen = m_lossInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_lossInfoList[i].nId == nId)
        {
            return i;
        }
    }
    return -1;
}

bool AddReportLossSelectWidget::getSelectGoodsInfo(int nId, AddReportLossSelectInfo &goodsInfo)
{
    if (nId <= 0)
    {
        return false;
    }

    int nLen = m_lossInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_lossInfoList[i].id == nId)
        {
            goodsInfo = m_lossInfoList[i];
            return true;
        }
    }
    return false;
}

void AddReportLossSelectWidget::removeSelectItem()
{
    int nKeyId = ui->listView->getSelectKeyId();
    int nPosition = getGoodsPosition(nKeyId);
    if (nPosition >= 0)
    {
        m_lossInfoList.removeAt(nPosition);
        updateUI();
    }
}

int AddReportLossSelectWidget::getGoodsListLength()
{
    return m_lossInfoList.length();
}

bool AddReportLossSelectWidget::getSeletedItem(AddReportLossSelectInfo &lossInfo)
{
    return ui->listView->getSelectItem(lossInfo);
}

void AddReportLossSelectWidget::getGoodsInfoList(QList<AddReportLossSelectInfo> &goodsInfoList)
{
    goodsInfoList = m_lossInfoList;
}

void AddReportLossSelectWidget::slot_showLastPage()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void AddReportLossSelectWidget::slot_showNextPage()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void AddReportLossSelectWidget::updateUI(bool bToEndPage)
{
    int nLen = m_lossInfoList.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    if (bToEndPage)
    {
        m_nCurPage = m_nTotalPage;
    }

    checkCurPageButtonState();
    generateUI();
}

void AddReportLossSelectWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_lossInfoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        m_lossInfoList[i].nId = i+1;
        ui->listView->appendItem(m_lossInfoList[i]);
    }
}

void AddReportLossSelectWidget::checkCurPageButtonState()
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

void AddReportLossSelectWidget::initConnect()
{
    connect(ui->lastPageButton, SIGNAL(clicked()), this, SLOT(slot_showLastPage()));
    connect(ui->nextPageButton, SIGNAL(clicked()), this, SLOT(slot_showNextPage()));
    connect(ui->listView,  SIGNAL(sigClickItem(AddReportLossSelectInfo)), this, SIGNAL(sigClickItem(AddReportLossSelectInfo)));
    qRegisterMetaType<AddReportLossSelectInfo>("AddReportLossSelectInfo");
    connect(ui->listView, &AddReportLossListView::clicked,[=](){
        emit sig_Focus();
    });
}
