#include "BCSManageWidget.h"
#include "ui_BCSManageWidget.h"
#include "enumData.h"
#include "../util/ThreadManager.h"
#include <QMessageBox>
#include <QProcess>
#include <QTcpSocket>
#include "TipsDlg.h"

BCSManageWidget::BCSManageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BCSManageWidget)
    , m_nOnePageCount(7)
    , m_nTotalPage(1)
    , m_nCurPage(1)
    , m_pBCSAddDlg(NULL)
    , m_pCtrl(NULL)
{
    ui->setupUi(this);
//    test();
    initConnect();
//    moveToThread(ThreadManager::getAgentThread());
//    ThreadManager::getAgentThread()->start();
    initButtons();
}

BCSManageWidget::~BCSManageWidget()
{
    delete ui;
}

void BCSManageWidget::init()
{
    if (m_pCtrl != NULL)
    {
        m_pCtrl->getBarcodeScaleListRequest();
    }
}

void BCSManageWidget::setCtrl(BarCodeScalesCtrl *pBarCodeScalesCtrl)
{
    if (m_pCtrl == NULL)
    {
        m_pCtrl = pBarCodeScalesCtrl;
        connect(m_pCtrl, SIGNAL(sigOnCheckBcsState(QString, bool)) , this, SLOT(slot_onCheckBcsState(QString, bool)));
        connect(m_pCtrl, SIGNAL(sigOnCheckBcsStateFinish()), this, SLOT(slot_onCheckBcsStateFinish()));
        connect(m_pCtrl, SIGNAL(sigOnGetBarcodeScaleCode(int,QString,QString)), this, SLOT(slot_onGetBarcodeScaleCode(int,QString,QString)));
        connect(m_pCtrl, SIGNAL(sigOnGetGoodsGroupList(int,QString,QList<BCSGroupManageLeftInfo>)),
                this, SLOT(slot_onGetGoodsGroupList(int,QString,QList<BCSGroupManageLeftInfo>)));
        connect(m_pCtrl, SIGNAL(sigOnGetBarcodeScaleList(int,QString,QList<BarCodeScaleInfo>)),
                this, SLOT(slot_onGetBarcodeScaleList(int,QString,QList<BarCodeScaleInfo>)));
        connect(m_pCtrl, SIGNAL(sigOnAddBarcodeScale(int,QString)),
                this, SLOT(slot_onAddBarcodeScale(int,QString)));
        connect(m_pCtrl, SIGNAL(sigOnDeleteScale(int,QString,QString)),
                this, SLOT(slot_onDeleteScale(int,QString,QString)));
    }

}

void BCSManageWidget::getInfoList(QList<BarCodeScaleInfo>  &infoList)
{
    infoList = m_infoList;
}

void BCSManageWidget::getLeftInfoList(QList<BCSGroupManageLeftInfo> &leftInfoList)
{
    leftInfoList = m_leftInfoList;
}

void BCSManageWidget::on_updateButton_clicked()
{
    // 刷新
    int nlen = m_infoList.length();
    for(int i = 0 ; i < nlen; i++)
    {
        if(m_infoList[i].nState != e_bcsForbidLink){
            m_infoList[i].nState = e_bcsForwaitLink;
        }
    }
    generateUI();

    if (m_pCtrl != NULL)
    {
        m_pCtrl->checkBcsState(m_infoList);
    }

}

void BCSManageWidget::on_deleteButton_clicked()
{
//    // 删除

    QString scaleId = ui->listView->getSelectKeyId();
    if (m_pCtrl != NULL)
    {
        m_pCtrl->deleteScaleRequestRequest(scaleId);
    }

//    if (scaleId >= 1)
//    {
////       m_infoList.removeAt(nSeq - 1);
//       generateUI();
//       initButtons();
//    }
}

void BCSManageWidget::on_forbidButton_clicked()
{
    // 禁用
    int nSeq = ui->listView->getSelectSeq();
    if (nSeq >= 1)
    {
        m_infoList[nSeq - 1].nState = e_bcsForbidLink;
        generateUI();
        initButtons();
    }
}

void BCSManageWidget::on_startUseButton_clicked()
{
    // 启动
    int nSeq = ui->listView->getSelectSeq();
    if (nSeq >= 1)
    {
        m_infoList[nSeq - 1].nState = e_bcsLink;
        generateUI();
        initButtons();
    }
}

void BCSManageWidget::on_addButton_clicked()
{
    if (m_pCtrl != NULL)
    {
        m_pCtrl->getBarcodeScaleCodeRequest();
    }
}

void BCSManageWidget::on_lastPageButton_clicked()
{
    m_nCurPage--;
    checkCurPageButtonState();
    generateUI();
}

void BCSManageWidget::on_nextPageButton_clicked()
{
    m_nCurPage++;
    checkCurPageButtonState();
    generateUI();
}

void BCSManageWidget::slot_clickListItem(BarCodeScaleInfo itemInfo)
{
    initButtons();
}


void BCSManageWidget::slot_onCheckBcsState(QString sKeyId, bool bState)
{
    updateInfoState(sKeyId, bState);
    generateUI();
}

void BCSManageWidget::slot_onCheckBcsStateFinish()
{
    // 状态检查完毕
}

void BCSManageWidget::slot_onGetBarcodeScaleCode(int nCode, QString sMsg, QString sBcsCode)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("获取条码秤编号失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        if(m_pBCSAddDlg == NULL)
        {
            m_pBCSAddDlg = new BCSAddDlg;
            connect(m_pBCSAddDlg, SIGNAL(sigAddBarcodeScale(BarCodeScaleInfo)), this, SLOT(slot_addBarcodeScale(BarCodeScaleInfo)));
        }
        m_pBCSAddDlg->setLeftInfo(m_leftInfoList);
        m_pBCSAddDlg->setBcsCode(sBcsCode);
        m_pBCSAddDlg->activateWindow();
        m_pBCSAddDlg->exec();
    }
}

void BCSManageWidget::slot_onGetGoodsGroupList(int nCode, QString sMsg, QList<BCSGroupManageLeftInfo> leftInfoList)
{
    if(nCode == e_success)
    {
        m_leftInfoList = leftInfoList;
    }
}

void BCSManageWidget::slot_onGetBarcodeScaleList(int nCode, QString sMsg, QList<BarCodeScaleInfo> scaleInfoList)
{
        if(nCode != e_success)
        {
             TipsDlg::instance()->releaseCtrl(QStringLiteral("获取条码秤列表失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
             return;
        }

        m_infoList = scaleInfoList;
        int nLen = m_infoList.length();
        m_nTotalPage = nLen / m_nOnePageCount + ((nLen % m_nOnePageCount == 0) ? 0 : 1);
        if (m_nTotalPage <= 0)
        {
            m_nTotalPage = 1;
        }

        generateUI();
        on_updateButton_clicked();
}

void BCSManageWidget::slot_onAddBarcodeScale(int nCode, QString sMsg)
{
    if(nCode != e_success)
    {
         TipsDlg::instance()->releaseCtrl(QStringLiteral("新增条码秤失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
         return;
    }
    m_pBCSAddDlg->hide();
    init();
}

void BCSManageWidget::slot_onDeleteScale(int nCode, QString sMsg, QString scaleId)
{
    if(nCode != e_success)
    {
         TipsDlg::instance()->releaseCtrl(QStringLiteral("删除条码秤失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
         return;
    }

    for(int i = 0; i < m_infoList.length(); i++)
    {
        if(m_infoList[i].sKeyId == scaleId)
        {
            m_infoList.removeAt(i);
            generateUI();
            initButtons();
            break;
        }
    }


}

void BCSManageWidget::slot_addBarcodeScale(BarCodeScaleInfo bcsInfo)
{
    if (m_pCtrl != NULL)
    {
        int nGoodsGroupId = bcsInfo.sGoodsGroup.toInt();
        m_pCtrl->addBarcodeScaleRequest(bcsInfo.sCode, bcsInfo.sModel, bcsInfo.sIP, nGoodsGroupId); //
    }
}

void BCSManageWidget::generateUI()
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

void BCSManageWidget::checkCurPageButtonState()
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

void BCSManageWidget::initButtons()
{

    QString sSelectKeyId = ui->listView->getSelectKeyId();
    if (sSelectKeyId.isEmpty())
    {
        ui->deleteButton->setEnabled(false);
        ui->forbidButton->setEnabled(false);
        ui->startUseButton->setEnabled(false);
    }
    else
    {
        ui->deleteButton->setEnabled(true);
        BarCodeScaleInfo bcsInfo;
        ui->listView->getSelectItemInfo(bcsInfo);
        if (bcsInfo.nState == e_bcsLink)
        {
            ui->forbidButton->setEnabled(true);
            ui->startUseButton->setEnabled(false);
        }
        else if (bcsInfo.nState == e_bcsForbidLink)
        {
            ui->forbidButton->setEnabled(false);
            ui->startUseButton->setEnabled(true);
        }
        else if (bcsInfo.nState == e_bcsOffLink)
        {
            ui->forbidButton->setEnabled(true);
            ui->startUseButton->setEnabled(true);
        }
    }
}

void BCSManageWidget::initConnect()
{
    qRegisterMetaType<BarCodeScaleInfo>("BarCodeScaleInfo");
    connect(ui->listView, SIGNAL(sigClickItem(BarCodeScaleInfo)), this, SLOT(slot_clickListItem(BarCodeScaleInfo)));
    //    connect(ui->listView, SIGNAL(slot_updateAloneState(QString, QString )), this, SLOT(slot_updateAloneState(QString, QString )));

}

//更新单条条码秤状态
void BCSManageWidget::updateInfoState(QString sKeyId, bool bState)
{
    int nLen = m_infoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_infoList[i].sKeyId == sKeyId)
        {
            if (m_infoList[i].nState != e_bcsForbidLink)
            {
                m_infoList[i].nState = bState ? e_bcsLink : e_bcsOffLink;
                generateUI();
                break;
            }
        }
    }
}

