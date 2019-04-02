#include "BCSWidget.h"
#include "ui_BCSWidget.h"
#include "MTScaleAPIDll.h"
#include <QDateTime>
#include <QDebug>

BCSWidget::BCSWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BCSWidget)
    , m_pSelectedButton(NULL)
    , m_pBCSSendDownDlg(NULL)
    , m_pCtrl(NULL)
{
    ui->setupUi(this);
    on_bcsManageButton_clicked();
    initConnect();
}

BCSWidget::~BCSWidget()
{
    delete ui;
}

void BCSWidget::setCtrl(BarCodeScalesCtrl *pCtrl)
{
    if (m_pCtrl == NULL)
    {
        m_pCtrl = pCtrl;
        ui->bcsManagePage->setCtrl(pCtrl);
        ui->bcsGroupManagePage->setCtrl(pCtrl);
    }
}

void BCSWidget::init()
{
    ui->bcsManagePage->init();
    ui->bcsGroupManagePage->init();

    //屏蔽商品组
    ui->bcsGoodsGroupButton->hide();
    ui->bcsGroupManagePage->hide();
}

void BCSWidget::on_bcsManageButton_clicked()
{
    setButtonQss(ui->bcsManageButton);
    ui->stackedWidget->setCurrentWidget(ui->bcsManagePage);
}

void BCSWidget::on_bcsGoodsGroupButton_clicked()
{
    setButtonQss(ui->bcsGoodsGroupButton);
    ui->stackedWidget->setCurrentWidget(ui->bcsGroupManagePage);
}

void BCSWidget::on_bcsSendDownButton_clicked()
{
//    QList<BarCodeScaleInfo> m_SendList;//需要下发的条码秤列表
//    BarCodeScaleInfo sendInfo;
//    for (int i = 0; i < 5; i++)
//    {
//        sendInfo.sKeyId = QString::number(i+1);
//        sendInfo.sSeq = i+1; // 序号
//        sendInfo.sCode = QString("00%1").arg(i+1); // 编号
//        sendInfo.sModel = QStringLiteral("托利多RL00"); // 型号
//        sendInfo.sIP = QString("192.168.3.117").arg(i+1);// IP
//        sendInfo.nState = i%2; // 状态
//        m_SendList.append(sendInfo);
//    }

    if(m_pBCSSendDownDlg == NULL)
    {
        m_pBCSSendDownDlg = new BCSSendDownDlg;
        m_pBCSSendDownDlg->setCtrl(m_pCtrl);
    }
    QList<BarCodeScaleInfo>  infoList;
    ui->bcsManagePage->getInfoList(infoList);
    m_pBCSSendDownDlg->setInfoList(infoList);

    QList<BCSGroupManageLeftInfo> leftInfoList;
    ui->bcsManagePage->getLeftInfoList(leftInfoList);
    m_pBCSSendDownDlg->setLeftInfoList(leftInfoList);

    m_pBCSSendDownDlg->test();
    m_pBCSSendDownDlg->activateWindow();
    //m_pBCSSendDownDlg->showNormal();
    m_pBCSSendDownDlg->exec();

}

void BCSWidget::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SIGNAL(sigReturnClicked()));
    connect(ui->bcsGroupManagePage, SIGNAL(sigEditBcsGroup(int)), this, SIGNAL(sigEditBcsGroup(int)));
//    connect(ui->bcsGroupManagePage, SIGNAL(sigAddBcsGroup()), this, SIGNAL(sigAddBcsGroup()));
//    connect(ui->bcsManagePage, SIGNAL(), this, SIGNAL());
}

void BCSWidget::setButtonQss(QPushButton *pButton)
{
    static const QString c_sNormalQss = "font-family: '微软雅黑'; font-size: 14px; color: #FFFFFF;"
                                        "background-color:qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 #5D5D5D, stop:1 #595959);"
                                        "border: 1px solid #363636; border-top-left-radius:8px; border-top-right-radius:8px;"
                                        "border-bottom-right-radius:0px; border-bottom-left-radius:0px;";

    static const QString c_sSelectedQss = "font-family:'微软雅黑';font-size: 14px; color: #333333; background: #FFFFFF;"
                                        "border: 1px solid #363636;border-top-left-radius:8px; border-top-right-radius:8px;"
                                        "border-bottom-right-radius:0px;border-bottom-left-radius:0px;";

    if (m_pSelectedButton != pButton)
    {
        if (pButton != NULL)
        {
           pButton->setStyleSheet(c_sSelectedQss);
        }
        if (m_pSelectedButton != NULL)
        {
            m_pSelectedButton->setStyleSheet(c_sNormalQss);
        }
        m_pSelectedButton = pButton;
    }
}
