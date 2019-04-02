#include "PosInfoSetPage.h"
#include "ui_PosInfoSetPage.h"
#include "../data/enumData.h"
#include "../data/constData.h"

PosInfoSetPage::PosInfoSetPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PosInfoSetPage)
{
    ui->setupUi(this);
    pingbi();

    QList<QString> strList;
    strList<<c_sOnlyPc<<c_sMettLerBalance<<c_sWinTecBalance;
    ui->posModelComBox->initListWidget(strList);
    ui->posModelComBox->setContent("");
}

PosInfoSetPage::~PosInfoSetPage()
{
    delete ui;
}

void PosInfoSetPage::initData(const PosInfoSet &posInfoSet)
{
    ui->curVersionLabel->setText(posInfoSet.sAppVersion);
    ui->shopCodeLabel->setText(posInfoSet.sShopCode);
    ui->shopNameLabel->setText(posInfoSet.sShopName);
    ui->posCodeLabel->setText(posInfoSet.sCode);
//    ui->posModelComBox->setContent(posInfoSet.sPosModel);
    m_defaultKPosInfo = posInfoSet;
}

void PosInfoSetPage::uploadData(KPosSet &kPosSet)
{
    kPosSet.posInfoSet.bChanged = false;

    PosInfoSet tempPosInfoSet = m_defaultKPosInfo;
    tempPosInfoSet.bChanged = false;

//    if (tempPosInfoSet.sPosModel != ui->posModelComBox->getContent())
//    {
//        tempPosInfoSet.sPosModel = ui->posModelComBox->getContent();
//        tempPosInfoSet.bChanged = true;
//    }

    if (tempPosInfoSet.bChanged)
    {
        kPosSet.posInfoSet = tempPosInfoSet;
    }
}

//void PosInfoSetPage::on_balckSkinButton_clicked()
//{
//    ui->balckSkinButton->setSelectedState(true);
//    ui->flatSkinButton->setSelectedState(false);
//    ui->smartButton->setSelectedState(false);
//    m_nCurKPosInfo.nSkinType = e_blackSkin;
//}

//void PosInfoSetPage::on_flatSkinButton_clicked()
//{
//    ui->balckSkinButton->setSelectedState(false);
//    ui->flatSkinButton->setSelectedState(true);
//    ui->smartButton->setSelectedState(false);
//    m_nCurKPosInfo.nSkinType = e_flatSkin;
//}

//void PosInfoSetPage::on_smartButton_clicked()
//{
//    ui->balckSkinButton->setSelectedState(false);
//    ui->flatSkinButton->setSelectedState(false);
//    ui->smartButton->setSelectedState(true);
//    m_nCurKPosInfo.nSkinType = e_smartSkin;
//}

void PosInfoSetPage::pingbi()
{
//    ui->balckSkinButton->setSkinType(e_blackSkin);
//    ui->flatSkinButton->setSkinType(e_flatSkin);
//    ui->smartButton->setSkinType(e_smartSkin);
    ui->posModelLabel->hide();
    ui->posModelComBox->hide();
    ui->posTestButton->hide();

    ui->skinSetLabel->hide();
    ui->balckSkinButton->hide();
    ui->flatSkinButton->hide();
    ui->smartButton->hide();
    ui->balckSkinLabel->hide();
    ui->flatSkinLabel->hide();
    ui->smartLabel->hide();
}
