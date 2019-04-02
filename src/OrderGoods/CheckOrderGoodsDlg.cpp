#include "CheckOrderGoodsDlg.h"
#include "ui_CheckOrderGoodsDlg.h"
#include "../data/enumData.h"

CheckOrderGoodsDlg::CheckOrderGoodsDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CheckOrderGoodsDlg)
    , m_pOrderGoodsCheckCtrl(NULL)
    , m_pDlgCommon(NULL)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    initConnect();
}

CheckOrderGoodsDlg::~CheckOrderGoodsDlg()
{
    if (m_pDlgCommon != NULL)
    {
        m_pDlgCommon->deleteLater();
    }

    delete ui;
}

//void CheckOrderGoodsDlg::setUploadFinishedFlage(bool bUploadFinished)
//{
//    if (bUploadFinished)
//    {
//        setTitleText(QStringLiteral("要货明细"));
//    }
//    else
//    {
//        setTitleText(QStringLiteral("审核"));
//    }
//    ui->checkOrderGoodsWidget->test(bUploadFinished);
//}

//void CheckOrderGoodsDlg::initData(CheckOrderCategoryDetailInfo *pCheckOrderCategoryDetailInfo)
//{
//    if (pCheckOrderCategoryDetailInfo->bUploadFinish)
//    {
//        setTitleText(QStringLiteral("要货明细"));
//    }
//    else
//    {
//        setTitleText(QStringLiteral("审核"));
//    }
//    ui->checkOrderGoodsWidget->initData(pCheckOrderCategoryDetailInfo);
//}

void CheckOrderGoodsDlg::initData(const QList<OrderCardDetailInfo_s> &orderCardDetailInfoList, bool bUploadFinish
                                  , const QList<int> &orderCardIdList, OrderGoodsCheckCtrl *pOrderGoodsCheckCtrl)
{
    m_orderCardIdList = orderCardIdList;
    if (m_pOrderGoodsCheckCtrl == NULL)
    {
        m_pOrderGoodsCheckCtrl = pOrderGoodsCheckCtrl;
        connect(m_pOrderGoodsCheckCtrl, SIGNAL(sigOnUpdateOrderCardListDetail(int,QString)), this, SLOT(slot_onUpdateOrderCardListDetail(int,QString)));
    }

    if (bUploadFinish)
    {
        setTitleText(QStringLiteral("要货明细"));
    }
    else
    {
        setTitleText(QStringLiteral("审核"));
    }
    ui->checkOrderGoodsWidget->initData(orderCardDetailInfoList, bUploadFinish);
}

void CheckOrderGoodsDlg::slot_orderNumberChanged(QMap<int, int> changedMap)
{
    if (m_pOrderGoodsCheckCtrl != NULL)
    {
        m_pOrderGoodsCheckCtrl->updateOrderCardListDetailRequest(changedMap, m_orderCardIdList);
    }
    if (m_pDlgCommon == NULL)
    {
        m_pDlgCommon = new DlgCommon;
        m_pDlgCommon->hideBottomWidget();
    }
    m_pDlgCommon->hideDeleteButton();
    m_pDlgCommon->set_title(QStringLiteral("提示"));
    m_pDlgCommon->set_content(QStringLiteral("正在更新要货卡..."));
    m_pDlgCommon->exec();
}

void CheckOrderGoodsDlg::slot_onUpdateOrderCardListDetail(int nCode, QString sMsg)
{
    if (m_pDlgCommon == NULL)
    {
        m_pDlgCommon = new DlgCommon;
        m_pDlgCommon->hideBottomWidget();
    }
    m_pDlgCommon->showDeleteButton();
    m_pDlgCommon->set_title(QStringLiteral("提示"));

    if (nCode == e_success)
    {
        m_pDlgCommon->set_content(QStringLiteral("要货卡更新成功"));
    }
    else
    {
        m_pDlgCommon->set_content(QString(QStringLiteral("要货卡更新失败，%1")).arg(sMsg));
    }
}

void CheckOrderGoodsDlg::setTitleText(QString titleText)
{
    ui->titleWidget->setTitleText(titleText);
}

void CheckOrderGoodsDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
    connect(ui->checkOrderGoodsWidget, SIGNAL(sigOrderNumberChanged(QMap<int,int>))
            , this, SLOT(slot_orderNumberChanged(QMap<int,int>)));
}
