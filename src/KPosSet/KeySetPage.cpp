#include "KeySetPage.h"
#include "ui_KeySetPage.h"
#include "../util/EnumToString.h"
#include "../util/GlobalSignal.h"
#include <QMessageBox>
#include <QDebug>
#include "TipsDlg.h"

KeySetPage::KeySetPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeySetPage),
    m_pHomeKeySortDlg(NULL),
    m_pRefundKeySortDlg(NULL)
{
    ui->setupUi(this);
    init();
//    test();
}

KeySetPage::~KeySetPage()
{
    if (m_pHomeKeySortDlg != NULL)
    {
        m_pHomeKeySortDlg->deleteLater();
    }

    delete ui;
}

void KeySetPage::initData(const KeySet &keySet)
{
    m_defaultKeySet = keySet;
    QList<KeySetInfo> keySetInfoList;
    keySetInfoList.append(keySet.homeKeyList);
    keySetInfoList.append(keySet.refundKeyList);
    initKeyWidgetList(keySetInfoList);
}

void KeySetPage::uploadData(KPosSet &kPosSet)
{
    kPosSet.keySet.bChanged = false;

    QList<KeySetInfo> keySetInfoList;
    keySetInfoList.append(m_defaultKeySet.homeKeyList);
    keySetInfoList.append(m_defaultKeySet.refundKeyList);
    int nLen = keySetInfoList.length();
    if (nLen != m_keyWidgetList.length())
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("按键设置的数据有问题,上传失败！"));
        return;
    }

    KeySet tempKeySet = m_defaultKeySet;
    tempKeySet.bChanged = false;
    int nHomeKeyLen = m_defaultKeySet.homeKeyList.length();

    int keyId = -1;
    bool bOpenEye = false;
    KeySetInfo keySetInfo;
    for (int i = 0; i < nHomeKeyLen; i++)
    {
        keyId = m_keyWidgetList[i]->getKeyId();
        bOpenEye = m_keyWidgetList[i]->isEyeOpen();
        keySetInfo = m_defaultKeySet.homeKeyList[i];
        if ((keySetInfo.nKeyId != keyId)
                || (keySetInfo.bStartUsed != bOpenEye))
        {
            tempKeySet.bChanged = true;
            tempKeySet.homeKeyList[i].nKeyId = keyId;
            tempKeySet.homeKeyList[i].bStartUsed = bOpenEye;
        }
    }

    for (int i = nHomeKeyLen; i < nLen; i++)
    {
        keyId = m_keyWidgetList[i]->getKeyId();
        bOpenEye = m_keyWidgetList[i]->isEyeOpen();
        keySetInfo = m_defaultKeySet.refundKeyList[i-nHomeKeyLen];
        if ((keySetInfo.nKeyId != keyId)
                || (keySetInfo.bStartUsed != bOpenEye))
        {
            tempKeySet.bChanged = true;
            tempKeySet.refundKeyList[i-nHomeKeyLen].nKeyId = keyId;
            tempKeySet.refundKeyList[i-nHomeKeyLen].bStartUsed = bOpenEye;
        }
    }

    if (tempKeySet.bChanged)
    {
        kPosSet.keySet = tempKeySet;
    }
}

void KeySetPage::slot_clickHomeKeyId(int nKeyId, int nHomeKeyPos)
{
    m_keyWidgetList[nHomeKeyPos]->setContent(nKeyId);
    m_keyWidgetList[nHomeKeyPos]->addEye();
}

void KeySetPage::slot_HomeKeyFinished(QList<int> keyIdList)
{
    Q_UNUSED( keyIdList )
//    int nLen1 = keyIdList.length();
//    int nLen2 = m_curKeySet.homeKeyList.length();
//    for (int i = 0; i < nLen1 && i < nLen2; i++)
//    {
//        m_curKeySet.homeKeyList[i].nKeyId = keyIdList[i];
//        m_curKeySet.homeKeyList[i].bStartUsed = true;
//    }

    if (m_pHomeKeySortDlg != NULL)
    {
        m_pHomeKeySortDlg->hide();
    }
}

void KeySetPage::slot_clickRefundKeyId(int nKeyId, int nKeyPos)
{
    int nHomeKeylen = m_defaultKeySet.homeKeyList.length();
    m_keyWidgetList[nKeyPos + nHomeKeylen]->setContent(nKeyId);
    m_keyWidgetList[nKeyPos + nHomeKeylen]->addEye();
}

void KeySetPage::slot_RefundKeyFinished(QList<int> keyIdList)
{
    Q_UNUSED( keyIdList )
//    int nLen1 = keyIdList.length();
//    int nLen2 = m_curKeySet.refundKeyList.length();
//    for (int i = 0; i < nLen1 && i < nLen2; i++)
//    {
//        m_curKeySet.refundKeyList[i].nKeyId = keyIdList[i];
//        m_curKeySet.refundKeyList[i].bStartUsed = true;
//    }

    if (m_pRefundKeySortDlg != NULL)
    {
        m_pRefundKeySortDlg->hide();
    }
}

void KeySetPage::init()
{
    m_keyWidgetList.append(ui->homeKey1Widget);
    m_keyWidgetList.append(ui->homeKey2Widget);
    m_keyWidgetList.append(ui->homeKey3Widget);
    m_keyWidgetList.append(ui->homeKey4Widget);
    m_keyWidgetList.append(ui->homeKey5Widget);
    m_keyWidgetList.append(ui->homeKey6Widget);
    m_keyWidgetList.append(ui->homeKey7Widget);
    m_keyWidgetList.append(ui->homeKey8Widget);
    m_keyWidgetList.append(ui->homeKey9Widget);
    m_keyWidgetList.append(ui->homeKey10Widget);
    m_keyWidgetList.append(ui->homeKey11Widget);
    m_keyWidgetList.append(ui->homeKey12Widget);
    m_keyWidgetList.append(ui->homeKey13Widget);

    m_keyWidgetList.append(ui->refundKey1Widget);
    m_keyWidgetList.append(ui->refundKey2Widget);
    m_keyWidgetList.append(ui->refundKey3Widget);

    int nLen = m_keyWidgetList.length();
    for (int i = 0; i < nLen; i++)
    {
       m_keyWidgetList[i]->setPosition(i);
    }
}

void KeySetPage::initKeyWidgetList(QList<KeySetInfo> keySetInfolist)
{
    int nKeysLen1 = keySetInfolist.length();
    int nKeysLen2 = m_keyWidgetList.length();
    if (nKeysLen1 != nKeysLen2)
    {
        TipsDlg::instance()->releaseCtrl(QStringLiteral("按键设置的数据有问题，初始化失败！"));
        return;
    }

    KeySetInfo keySetInfo;
    PressKeyWidget* pressKeyWidget = NULL;
    for (int i = 0; i < nKeysLen1; i++)
    {
        keySetInfo = keySetInfolist[i];
        pressKeyWidget = m_keyWidgetList[i];
        pressKeyWidget->setEyeState(keySetInfo.bStartUsed);
        if (keySetInfo.bStartUsed)
        {
            pressKeyWidget->addEye();
        }
        else
        {
            pressKeyWidget->addGray_Eye();
        }
        pressKeyWidget->setContent(keySetInfo.nKeyId);
    }
}

void KeySetPage::checkIsChanged(KPosSet& kPosSet)
{
    Q_UNUSED( kPosSet )
//     kPosSet.keySet.bChanged = false;

////    int curHomeKeyListLen = m_curKeySet.homeKeyList.length();
////    int defaultHomeKeyListLen = m_defaultKeySet.homeKeyList.length();
////    int curRefundKeyListLen = m_curKeySet.refundKeyList.length();
////    int defalutRefundKeyListLen = m_defaultKeySet.refundKeyList.length();
////    if(curHomeKeyListLen != defaultHomeKeyListLen || curRefundKeyListLen != defalutRefundKeyListLen)
////    {
////        return;
////    }

//    bool bChanged = false;
//    KeySetInfo curKeySetInfo;
//    KeySetInfo defaultKeySetInfo;
//    for (int i = 0; i < curHomeKeyListLen; i++)
//    {
//        curKeySetInfo = m_curKeySet.homeKeyList[i];
//        defaultKeySetInfo = m_defaultKeySet.homeKeyList[i];
//        if ((curKeySetInfo.nKeyId != defaultKeySetInfo.nKeyId)
//                || (curKeySetInfo.bStartUsed != defaultKeySetInfo.bStartUsed))
//        {
//            bChanged = true;
//            break;
//        }
//    }

//    if (!bChanged)
//    {
//        for (int i = 0; i < curRefundKeyListLen; i++)
//        {
//            curKeySetInfo = m_curKeySet.refundKeyList[i];
//            defaultKeySetInfo = m_defaultKeySet.refundKeyList[i];
//            if ((curKeySetInfo.nKeyId != defaultKeySetInfo.nKeyId)
//                    || (curKeySetInfo.bStartUsed != defaultKeySetInfo.bStartUsed))
//            {
//                bChanged = true;
//                break;
//            }
//        }
//    }

//    if (bChanged)
//    {
//        kPosSet.keySet.bChanged = true;
//        kPosSet.keySet.homeKeyList.clear();
//        kPosSet.keySet.refundKeyList.clear();
//        kPosSet.keySet.homeKeyList.append(m_curKeySet.homeKeyList);
//        kPosSet.keySet.refundKeyList.append(m_curKeySet.refundKeyList);
//    }
}

void KeySetPage::on_homeKeySortButton_clicked()
{
    int nHomeKeysLen = m_defaultKeySet.homeKeyList.length();
    for (int i = 0; i < nHomeKeysLen; i++)
    {
//       m_homeKeyWidgetList[i]->setContent(QString::number(i+1));
       m_keyWidgetList[i]->setEyeState(true);
       m_keyWidgetList[i]->addEye_Gray();
    }

    if (m_pHomeKeySortDlg == NULL)
    {
        m_pHomeKeySortDlg = new HomeKeySortDlg;
        connect(m_pHomeKeySortDlg, SIGNAL(sigClickKeyId(int, int)), this, SLOT(slot_clickHomeKeyId(int, int)));
        connect(m_pHomeKeySortDlg, SIGNAL(sigFinished(QList<int>)), this, SLOT(slot_HomeKeyFinished(QList<int>)));
    }
    m_pHomeKeySortDlg->reInit();
    QPoint globalPoint = ui->homeKeySortButton->mapToGlobal(QPoint(0, 0));
    int nXPos = globalPoint.x() - m_pHomeKeySortDlg->width() + ui->homeKeySortButton->width();
    int nOffY = 10;
    int nYPos = globalPoint.y() + ui->homeKeySortButton->height() + nOffY;
    m_pHomeKeySortDlg->move(nXPos, nYPos);
    m_pHomeKeySortDlg->exec();
}

void KeySetPage::on_refundKeySortButton_clicked()
{
    int nHomeKeyLen = m_defaultKeySet.homeKeyList.length();
    int nRefundKeysLen = m_defaultKeySet.refundKeyList.length();
    for (int i = nHomeKeyLen; i < nHomeKeyLen + nRefundKeysLen; i++)
    {
//        m_refundKeyWidgetList[i]->setContent(QString::number(i+1));
        m_keyWidgetList[i]->setEyeState(true);
        m_keyWidgetList[i]->addEye_Gray();
    }

    if (m_pRefundKeySortDlg == NULL)
    {
        m_pRefundKeySortDlg = new RefundKeySortDlg;
        connect(m_pRefundKeySortDlg, SIGNAL(sigClickKeyId(int, int)), this, SLOT(slot_clickRefundKeyId(int, int)));
        connect(m_pRefundKeySortDlg, SIGNAL(sigFinished(QList<int>)), this, SLOT(slot_RefundKeyFinished(QList<int>)));
    }
    m_pRefundKeySortDlg->reInit();
    QPoint globalPoint = ui->refundKeySortButton->mapToGlobal(QPoint(0, 0));
    int nXPos = globalPoint.x() - m_pRefundKeySortDlg->width() + ui->homeKeySortButton->width();
    int nOffY = 0;
    int nYPos = globalPoint.y() + ui->homeKeySortButton->height() + nOffY;
    m_pRefundKeySortDlg->move(nXPos, nYPos);
    m_pRefundKeySortDlg->exec();
}
