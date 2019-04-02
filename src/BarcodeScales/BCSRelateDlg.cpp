#include "BCSRelateDlg.h"
#include "ui_BCSRelateDlg.h"

BCSRelateDlg::BCSRelateDlg(QWidget *parent) :
    QDialog(parent)
  , ui(new Ui::BCSRelateDlg)
  , m_nOnePageCount(3)
  , m_nTotalPage(1)
  , m_nCurPage(1)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->titleWidget->setTitleText(QStringLiteral("关联条码秤"));
    test();
    initConnect();
}

BCSRelateDlg::~BCSRelateDlg()
{
    delete ui;
}

void BCSRelateDlg::test()
{
//    BarCodeScaleInfo itemInfo;
//    for (int i = 0; i < 15; i++)
//    {
//        itemInfo.sKeyId = QString::number(i+1);// 主键id
//        itemInfo.sCode = QString("00%1").arg(i+1); // 编号
//        itemInfo.sModel = QStringLiteral("托利多RL00"); // 型号
//        itemInfo.sIP = QStringLiteral("192.168.3.117");// IP
//        itemInfo.nState = i%2; // 状态
//        m_infoList.append(itemInfo);
//    }

//    int nLen = m_infoList.length();
//    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
//    if (m_nTotalPage <= 0)
//    {
//        m_nTotalPage = 1;
//    }
//    BCSManageWidget *ptr = (BCSManageWidget*)parentWidget();
//    ptr->getInfoList(m_infoList);
    checkCurPageButtonState();
    generateUI();
}

void BCSRelateDlg::setInfoList(QList<BarCodeScaleInfo> infoList)
{
    m_infoList = infoList;
}

void BCSRelateDlg::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void BCSRelateDlg::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void BCSRelateDlg::generateUI()
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

void BCSRelateDlg::checkCurPageButtonState()
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

void BCSRelateDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
    connect(ui->topWidget, SIGNAL(sigSelectBox(bool)), this, SLOT(slot_selectBox(bool)));
}

void BCSRelateDlg::on_confirmButton_clicked()
{
    this->hide();
}

void BCSRelateDlg::slot_selectBox(bool bSelectAll)
{
    int nStartPos = (m_nCurPage - 1) * m_nOnePageCount;
    int nEndPos = m_nCurPage * m_nOnePageCount;
    int nCount = m_infoList.length();
    QList<QString> keyIdList;
    for (int i = nStartPos; i < nEndPos && i < nCount; i++)
    {
        keyIdList.append(m_infoList[i].sKeyId);
    }

    if (bSelectAll)
    {
        ui->listView->appendSelectKeyIds(keyIdList);
    }
    else
    {
        ui->listView->removeSelectKeyIds(keyIdList);
    }

    generateUI();
}
