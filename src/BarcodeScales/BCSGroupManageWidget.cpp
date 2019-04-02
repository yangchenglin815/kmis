#include "BCSGroupManageWidget.h"
#include "ui_BCSGroupManageWidget.h"
#include <QMessageBox>
#include "TipsDlg.h"

BCSGroupManageWidget::BCSGroupManageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BCSGroupManageWidget)
    , m_pCtrl(NULL)
    , m_pBCSRelateDlg(NULL)
    , m_pBCSAddGoodsGroupDlg(NULL)
{
    ui->setupUi(this);
    initConnect();
    ui->deleteButton->setEnabled(false);
    ui->relateButton->setEnabled(false);
    ui->editButton->setEnabled(false);
}

BCSGroupManageWidget::~BCSGroupManageWidget()
{
    delete ui;
}

void BCSGroupManageWidget::setCtrl(BarCodeScalesCtrl *pCtrl)
{
    if (m_pCtrl == NULL)
    {
        m_pCtrl = pCtrl;
        connect(m_pCtrl, SIGNAL(sigOnCreateGoodsGroup(int,QString,BCSGroupManageLeftInfo))
                ,this, SLOT(slot_onCreateGoodsGroup(int,QString,BCSGroupManageLeftInfo)));

        connect(m_pCtrl, SIGNAL(sigOnGetGoodsGroupList(int,QString,QList<BCSGroupManageLeftInfo>))
                ,this, SLOT(slot_onGetGoodsGroupList(int,QString,QList<BCSGroupManageLeftInfo>)));
    }
}

void BCSGroupManageWidget::init()
{
    if (m_pCtrl != NULL)
    {
        m_pCtrl->getGoodsGroupListRequest();
    }
}

void BCSGroupManageWidget::on_relateButton_clicked()
{
    if(m_pBCSRelateDlg == NULL)
    {
        m_pBCSRelateDlg = new BCSRelateDlg;
    }
//    m_pBCSRelateDlg->setInfoList(m_infoScaleList);
    m_pBCSRelateDlg->activateWindow();
    m_pBCSRelateDlg->exec();
}

void BCSGroupManageWidget::on_deleteButton_clicked()
{

}

void BCSGroupManageWidget::on_editButton_clicked()
{
    int nGroupId = ui->bcsLeftWidget->getSelectGroupId();
    emit sigEditBcsGroup(nGroupId);
}

void BCSGroupManageWidget::on_addButton_clicked()
{
    if (m_pBCSAddGoodsGroupDlg == NULL)
    {
        m_pBCSAddGoodsGroupDlg = new BCSAddGoodsGroupDlg;
        connect(m_pBCSAddGoodsGroupDlg, SIGNAL(sigAddGoodsGroup(QString))
                , this, SLOT(slot_addGoodsGroup(QString)));
    }
    m_pBCSAddGoodsGroupDlg->activateWindow();
    m_pBCSAddGoodsGroupDlg->showNormal();
}

void BCSGroupManageWidget::slot_clickLeftItem(QList<BCSGroupManageRightInfo> rightInfoList)
{
    ui->deleteButton->setEnabled(true);
    ui->relateButton->setEnabled(true);
    ui->editButton->setEnabled(true);
    ui->bcsRightWidget->initData(rightInfoList);
}

void BCSGroupManageWidget::slot_addGoodsGroup(QString sName)
{
    if (m_pCtrl != NULL)
    {
       m_pCtrl->createGoodsGroupRequest(sName);
    }
}

void BCSGroupManageWidget::slot_onCreateGoodsGroup(int nCode, QString sMsg, BCSGroupManageLeftInfo bcsGroupManageLeftInfo)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("创建商品组失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->bcsLeftWidget->appendData(bcsGroupManageLeftInfo);
    }
}

void BCSGroupManageWidget::slot_onGetGoodsGroupList(int nCode, QString sMsg, QList<BCSGroupManageLeftInfo> leftInfoList)
{
    if(nCode != e_success)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("获取商品组列表失败, nCode:%1, sMsg:%2").arg(nCode).arg(sMsg));
    }
    else
    {
        ui->bcsLeftWidget->initData(leftInfoList);
    }
}

void BCSGroupManageWidget::initConnect()
{
    qRegisterMetaType<QList<BCSGroupManageRightInfo> >("QList<BCSGroupManageRightInfo>");
    connect(ui->bcsLeftWidget, SIGNAL(sigClickItem(QList<BCSGroupManageRightInfo>)), this, SLOT(slot_clickLeftItem(QList<BCSGroupManageRightInfo>)));
}
