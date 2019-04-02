#include "BCSGroupManageLeftWidget.h"
#include "ui_BCSGroupManageLeftWidget.h"

BCSGroupManageLeftWidget::BCSGroupManageLeftWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BCSGroupManageLeftWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
{
    ui->setupUi(this);
//    test();
    initConnect();
}

BCSGroupManageLeftWidget::~BCSGroupManageLeftWidget()
{
    delete ui;
}

//void BCSGroupManageLeftWidget::test()
//{
//    BCSGroupManageLeftInfo itemInfo;
//    for (int i = 0; i < 20; i++)
//    {
//        itemInfo.sKeyId = QString::number(i+1);
////        itemInfo.sSeq; // 序号
//        itemInfo.sGroupNum = QString("00%1").arg(i+1); // 组号
//        itemInfo.sGroupName = QString("称重秤组名%1").arg(i+1); // 组名
//        m_infoList.append(itemInfo);
//    }

//    int nLen = m_infoList.length();
//    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
//    if (m_nTotalPage <= 0)
//    {
//        m_nTotalPage = 1;
//    }

//    generateUI();
//}

void BCSGroupManageLeftWidget::appendData(const BCSGroupManageLeftInfo &bcsGroupManageLeftInfo)
{
    m_infoList.append(bcsGroupManageLeftInfo);
    int nLen = m_infoList.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    m_nCurPage = m_nTotalPage;
    generateUI();
}

int BCSGroupManageLeftWidget::getSelectGroupId()
{
    return ui->listView->getSelectKeyId();
}

void BCSGroupManageLeftWidget::initData(const QList<BCSGroupManageLeftInfo> &leftInfoList)
{
    m_infoList = leftInfoList;
    int nLen = m_infoList.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }

    checkCurPageButtonState();
    generateUI();
}

void BCSGroupManageLeftWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void BCSGroupManageLeftWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void BCSGroupManageLeftWidget::slot_clickListItem()
{
    int nGroupId = getSelectGroupId();
    QList<BCSGroupManageRightInfo> rightInfoList;
    getRightInfoList(nGroupId, rightInfoList);
    emit sigClickItem(rightInfoList);
}

void BCSGroupManageLeftWidget::generateUI()
{
    ui->pageLabel->setText(QString(QStringLiteral("%1/%2页")).arg(m_nCurPage).arg(m_nTotalPage));
    ui->listView->clearItems();
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_infoList.length();
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        m_infoList[i].sSeq = QString::number(i+1);
        ui->listView->appendItem(m_infoList[i]);
    }
}

void BCSGroupManageLeftWidget::checkCurPageButtonState()
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

void BCSGroupManageLeftWidget::initConnect()
{
    connect(ui->listView, SIGNAL(sigClickItem()), this, SLOT(slot_clickListItem()));
}

void BCSGroupManageLeftWidget::getRightInfoList(int nGroupId, QList<BCSGroupManageRightInfo> &rightInfoList)
{
    int nLen = m_infoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_infoList[i].nGroupId == nGroupId)
        {
            rightInfoList = m_infoList[i].rightInfoList;
            break;
        }
    }
}
