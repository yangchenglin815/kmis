#include "BCSSendDownDlg.h"
#include "ui_BCSSendDownDlg.h"
#include "../data/enumData.h"
#include "MTScaleAPIDll.h"
#include <QDateTime>
#include <QDebug>

BCSSendDownDlg::BCSSendDownDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BCSSendDownDlg)
    , m_nOnePageCount(3)
    , m_nTotalPage(1)
    , m_nCurPage(1)
    , m_pCtrl(NULL)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->titleWidget->setTitleText(QStringLiteral("下发条码秤"));
    initConnect();
}

BCSSendDownDlg::~BCSSendDownDlg()
{
    delete ui;
}

void BCSSendDownDlg::test()
{
    ui->confirmButton->setEnabled(false);

//    BarCodeScaleInfo sendInfo;
//    for (int i = 0; i < 5; i++)
//    {
//        sendInfo.sKeyId = QString::number(i+1);
//        sendInfo.sCode = QString("00%1").arg(i+1); // 编号
//        sendInfo.sModel = QStringLiteral("托利多RL00"); // 型号
//        sendInfo.sIP = QStringLiteral("192.168.3.11%1").arg(i+3);// IP
//        sendInfo.nState = e_bcsSendDownWait; // 状态
//        m_infoList.append(sendInfo);
//    }

    int nLen = m_infoList.length();
    m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
    if (m_nTotalPage <= 0)
    {
        m_nTotalPage = 1;
    }
    for(int i =0; i < m_infoList.length(); i++)
    {
        m_infoList[i].nState = e_bcsSendDownWait;
    }

    checkCurPageButtonState();
    generateUI();

    if (m_pCtrl != NULL)
    {
        m_pCtrl->sendDownBcs(m_infoList , m_leftInfoList);
    }
}

void BCSSendDownDlg::setCtrl(BarCodeScalesCtrl *pCtrl)
{
    if (m_pCtrl == NULL)
    {
        m_pCtrl = pCtrl;
        connect(m_pCtrl, SIGNAL(sigOnSendDownBcsState(QString,bool)), this, SLOT(slot_onSendDownBcsState(QString,bool)));
        connect(m_pCtrl, SIGNAL(sigOnSendDownBcsFinish()), this, SLOT(slot_onSendDownBcsFinish()));
    }
}

void BCSSendDownDlg::setInfoList(QList<BarCodeScaleInfo> scaleInfo)
{
    m_infoList = scaleInfo;
}

void BCSSendDownDlg::setLeftInfoList(QList<BCSGroupManageLeftInfo> leftInfoList)
{
    m_leftInfoList = leftInfoList;
}

void BCSSendDownDlg::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void BCSSendDownDlg::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void BCSSendDownDlg::generateUI()
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

void BCSSendDownDlg::checkCurPageButtonState()
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

void BCSSendDownDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
}

void BCSSendDownDlg::updateSendDownData(QString sKey, bool bSuccess)
{

    int nLen = m_infoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_infoList[i].sKeyId == sKey)
        {
            m_infoList[i].nState = bSuccess ? e_bcsSendDownSuccess : e_bcsSendDownFailed;

            if(bSuccess)
            {
                m_SuccessScaleId.append(m_infoList[i].sKeyId);
            }
        }
    }
}

void BCSSendDownDlg::on_confirmButton_clicked()
{
    this->hide();
}

void BCSSendDownDlg::slot_onSendDownBcsState(QString sKey, bool bSuccess)
{
    //上传下发完成时间

    updateSendDownData(sKey, bSuccess);
    generateUI();
}

//下发完成
void BCSSendDownDlg::slot_onSendDownBcsFinish()
{
    ui->confirmButton->setEnabled(true);

    //上传下发成功信息
    if (m_pCtrl != NULL && m_SuccessScaleId.length() != 0)
    {
        m_pCtrl->updateScaleProductIssueRequest(m_SuccessScaleId);
        m_SuccessScaleId = QList<QString>();
    }

}
