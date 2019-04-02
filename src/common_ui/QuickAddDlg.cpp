#include "QuickAddDlg.h"
#include "ui_QuickAddDlg.h"
#include "TipsDlg.h"
#include "CommonFun.h"
#include <QStyledItemDelegate>
#include <QDebug>
#include <QMessageBox>

//#ifdef Q_OS_WIN
//#pragma execution_character_set("utf-8")
//#endif

QuickAddDlg::QuickAddDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QuickAddDlg)
    , m_pSaleCtrl(NULL)
    , m_pBigNode(NULL)
    , m_pMiddleNode(NULL)
    , m_pSmallNode(NULL)
    , m_goodsCode("")
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
//    setModal(true);
    initUI();
    initConnect();
//    initComBox();
}

QuickAddDlg::~QuickAddDlg()
{
    delete ui;
}

void QuickAddDlg::setCtrl(SaleCtrl *pSaleCtrl)
{
    if (m_pSaleCtrl == NULL)
    {
        m_pSaleCtrl = pSaleCtrl;
        connect(m_pSaleCtrl, &SaleCtrl::sigOnGetQuickGoodsInfo, this, &QuickAddDlg::slot_onGetQuickGoodsInfo);
        connect(m_pSaleCtrl, &SaleCtrl::sigOnCreateQuickGoods, this, &QuickAddDlg::slot_onCreateQuickGoods);
    }
}

void QuickAddDlg::getCategoryNodeList()
{
    m_goodsCode = "";
    m_bigCategoryGoodsCodeMap.clear(); // 大类和新建商品code的Map
    m_units = ""; // 商品规格单位
    m_sPlu = "";

    if (m_pSaleCtrl != NULL)
    {
        m_pSaleCtrl->getCategoryNodeList(m_categoryNodeList);
//        for(index=0;index<m_categoryNodeList.length();index++)
//        {
//            m_pBigNode=m_categoryNodeList.at(index);
//            bigMap.insert(m_pBigNode.sName,m_pBigNode);
//            for(mid=0;mid<m_pBigNode.nodeyList.length();mid++) {
//                m_pMiddleNode=m_pBigNode.nodeyList.at(mid);
//                midMap.insert(m_pMiddleNode.sName,m_pMiddleNode);
//                for(sub=0;sub<m_pMiddleNode.nodeyList.length();sub++) {
//                    m_pSmallNode=m_pMiddleNode.nodeyList.at(sub);
//                    smallMap.insert(m_pSmallNode.sName,m_pSmallNode);
//                }
//            }
//        }
    }

    initComBox();
    ui->submitBtn->setEnabled(true);
}

void QuickAddDlg::showEvent(QShowEvent *)
{
    QPoint globalPoint = ui->goodsNameWidget->mapToGlobal(QPoint(0, 0));
    int nXPos = 0;
    int nYPos = globalPoint.y() + ui->goodsNameWidget->height();
    ui->goodsNameWidget->setKeyboardPos(nXPos, nYPos, true);
}

void QuickAddDlg::initUI()
{
    ui->titleLabel->setText(QStringLiteral("快速建档"));
    ui->barCodelEdit->setValidator(new QIntValidator(0,10000000));
    ui->getGoodslEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));
    ui->referPricelEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));
    ui->memPricelEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));
    ui->pricelEdit->setValidator(new QDoubleValidator(0.00, 1000000.00, 2, this));

//    QStyledItemDelegate* itemDelegate = new QStyledItemDelegate();

//    ui->basicUnitCBox->setItemDelegate(itemDelegate);
//    ui->mKindcBox->setItemDelegate(itemDelegate);
//    ui->bKindcBox->setItemDelegate(itemDelegate);
//    ui->sKindcBox->setItemDelegate(itemDelegate);
//    ui->wUnitCBox->setItemDelegate(itemDelegate);
//    ui->weighTypeCBox->setItemDelegate(itemDelegate);

//    m_info.cId=0001;
//    m_info.goodsName="测试";

    ui->goodsNameWidget->hideKeyboardButton();
    ui->goodsNameWidget->setHolderText("");
    ui->goodsNameWidget->setOuterLineColor();
}

void QuickAddDlg::initComBox()
{
    m_pBigNode = NULL;
    m_pMiddleNode = NULL;
    m_pSmallNode = NULL;
    initBigComboBox();
    initMiddleComboBox();
    initSamllComboBox();
}

void QuickAddDlg::on_submitBtn_clicked()
{
    if (!checkSubmit())
    {
        return;
    }

    if (m_pBigNode == NULL)
    {
        return;
    }

    QString sBelongCId = "";
    if (m_pSmallNode != NULL)
    {
        sBelongCId = m_pSmallNode->sId;
    }
    else if (m_pMiddleNode != NULL)
    {
        sBelongCId = m_pMiddleNode->sId;
    }
    if (sBelongCId.isEmpty())
    {
        return;
    }

    ProductInfo productInfo;
    productInfo.cId = sBelongCId;
    productInfo.goodsName = ui->goodsNameWidget->getText();
    productInfo.member_price = ui->memPricelEdit->text().toFloat();
    productInfo.min_spec_unit = unitMap[ui->basicUnitCBox->currentText()];
    productInfo.order_spec_num = ui->getGoodslEdit->text().toFloat();
    productInfo.order_spec_unit = unitMap[ui->wUnitCBox->currentText()] ;
    productInfo.product_base_code=ui->barCodelEdit->text();
    productInfo.product_code=m_goodsCode;
    productInfo.reference_bid_price=ui->referPricelEdit->text().toFloat();
    productInfo.reference_selling_price=ui->pricelEdit->text().toFloat();
    productInfo.weight_type=ui->weighTypeCBox->currentIndex() + 1;
    if (m_pSaleCtrl != NULL)
    {
        ui->submitBtn->setEnabled(false);
//        QString sUUId = CommonFun::getUUID();
//        qDebug()<<"111 "<<sUUId;
        m_pSaleCtrl->createQuickGoodsRequest(productInfo);
    }
}

void QuickAddDlg::on_closeButton_clicked()
{
    close();
}

void QuickAddDlg::on_bKindcBox_currentIndexChanged(int index)
{
    m_pBigNode = &m_categoryNodeList[index];
    initMiddleComboBox();
    if ((m_pBigNode != NULL) && (m_pBigNode->nodeyList.length() > 0))
    {
        on_mKindcBox_currentIndexChanged(0);
    }
    if (m_pSaleCtrl != NULL)
    {
        if (!m_bigCategoryGoodsCodeMap.contains(m_pBigNode->sCode))
        {
           ui->productNumLb->setText(QStringLiteral("正在搜索商品编号..."));
//           m_bigCategoryGoodsCodeMap.insert(m_pBigNode->sCode, "");
           m_pSaleCtrl->getQuickGoodsInfoRequest(m_pBigNode->sCode);
        }
        else
        {
            ui->productNumLb->setText(QStringLiteral("商品编号： %1").arg(m_bigCategoryGoodsCodeMap.value(m_pBigNode->sCode)));
        }
    }
}

void QuickAddDlg::on_mKindcBox_currentIndexChanged(int index)
{
    m_pMiddleNode = &m_pBigNode->nodeyList[index];
    qDebug()<<"mid cid"<<m_pMiddleNode->sId;
    initSamllComboBox();
}

void QuickAddDlg::on_sKindcBox_currentIndexChanged(int index)
{
    m_pSmallNode = &m_pMiddleNode->nodeyList[index];
    qDebug()<<"small cid"<<m_pSmallNode->sId;
}

void QuickAddDlg::slot_onGetQuickGoodsInfo(int nCode, QString sMsg, QString plu, QString goodCode, QString unit, QString sBigCategoryCode)
{
    if (nCode != e_success)
    {
        m_bigCategoryGoodsCodeMap.remove(sBigCategoryCode);
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("%1,%2").arg(nCode).arg(sMsg));
        return;
    }

    m_bigCategoryGoodsCodeMap.insert(sBigCategoryCode, goodCode);
    m_goodsCode = goodCode;
    ui->productNumLb->setText(QStringLiteral("商品编号： %1").arg(goodCode));

    if (!unit.isEmpty() && (unit != m_units))
    {
        m_units = unit;
        initUnitsBox();
    }
    if (!plu.isEmpty() && (plu != m_sPlu))
    {
        m_sPlu = plu;
        int nIndex = ui->weighTypeCBox->currentIndex();
        on_weighTypeCBox_currentIndexChanged(nIndex);
    }
}

void QuickAddDlg::slot_onCreateQuickGoods(int nCode, QString sMsg)
{
    ui->submitBtn->setEnabled(true);
    if (nCode != e_success)
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("%1,%2").arg(nCode).arg(sMsg));
        return;
    }

    this->hide();
    if (m_pSaleCtrl != NULL)
    {
        m_pSaleCtrl->startUpdateThread();
    }
}

void QuickAddDlg::initBigComboBox()
{
    int nBigLen = m_categoryNodeList.count();
    if (nBigLen <= 0)
    {
        return;
    }

    disconnect(ui->bKindcBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_bKindcBox_currentIndexChanged(int)));
    ui->bKindcBox->clear();
    for (int i = 0; i < nBigLen; i++)
    {
        ui->bKindcBox->addItem(m_categoryNodeList[i].sName);
    }

    connect(ui->bKindcBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_bKindcBox_currentIndexChanged(int)));
    if (nBigLen > 0)
    {
        if (m_pBigNode == NULL)
        {
            m_pBigNode = &m_categoryNodeList[0];
            on_bKindcBox_currentIndexChanged(0);
        }
    }
    else
    {
        m_pBigNode = NULL;
    }
}

void QuickAddDlg::initMiddleComboBox()
{
    if (m_pBigNode == NULL)
    {
        return;
    }

    disconnect(ui->mKindcBox,SIGNAL(currentIndexChanged(int)),this,SLOT(on_mKindcBox_currentIndexChanged(int)));
    ui->mKindcBox->clear();
    int nMiddleLen = m_pBigNode->nodeyList.length();
    for (int i = 0; i < nMiddleLen; i++)
    {
        ui->mKindcBox->addItem(m_pBigNode->nodeyList[i].sName);
    }
    connect(ui->mKindcBox,SIGNAL(currentIndexChanged(int)),this,SLOT(on_mKindcBox_currentIndexChanged(int)));

    if (nMiddleLen > 0)
    {
        if (m_pMiddleNode == NULL)
        {
           m_pMiddleNode = &m_pBigNode->nodeyList[0];
        }
    }
    else
    {
        m_pMiddleNode = NULL;
    }
}

void QuickAddDlg::initSamllComboBox()
{
    if (m_pMiddleNode == NULL)
    {
        return;
    }

    disconnect(ui->sKindcBox, SIGNAL(currentIndexChanged(int)),this,SLOT(on_sKindcBox_currentIndexChanged(int)));
    ui->sKindcBox->clear();
    int nSmallLen = m_pMiddleNode->nodeyList.length();
    for (int i = 0; i < nSmallLen; i++)
    {
        ui->sKindcBox->addItem(m_pMiddleNode->nodeyList[i].sName);
    }
    connect(ui->sKindcBox, SIGNAL(currentIndexChanged(int)),this,SLOT(on_sKindcBox_currentIndexChanged(int)));
    if (nSmallLen > 0)
    {
        on_sKindcBox_currentIndexChanged(0);
    }
    else
    {
        m_pSmallNode = NULL;
    }
}

void QuickAddDlg::initUnitsBox()
{
    if (m_units.isEmpty())
    {
        return;
    }
    ui->basicUnitCBox->clear();
    ui->wUnitCBox->clear();
    unitMap.clear();

    QList<QString> unitList = m_units.split(";");
    int nLen = unitList.length();
    QList<QString> strList;
    for (int i = 0; i < nLen; i++)
    {
        strList = unitList[i].split(",");
        if (strList.length() == 2)
        {
            unitMap.insert(strList[1], strList[0]);
        }
    }

    QStringList keyList = unitMap.keys();

    ui->basicUnitCBox->addItems(keyList);
    ui->wUnitCBox->addItems(keyList);
}

bool QuickAddDlg::checkSubmit()
{
    bool bFlag = false;
    if (ui->goodsNameWidget->getText().isEmpty())
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("商品名称不能为空"));
        ui->goodsNameWidget->setSearchFocus();
    }
    else if (ui->barCodelEdit->text().isEmpty())
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("商品条码或plu码不能为空"));
        ui->barCodelEdit->setFocus();
    }
    else if (ui->getGoodslEdit->text().isEmpty())
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("要货规格不能为空"));
        ui->getGoodslEdit->setFocus();
    }
    else if (ui->referPricelEdit->text().isEmpty())
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("参考进价不能为空"));
        ui->referPricelEdit->setFocus();
    }
    else if (ui->memPricelEdit->text().isEmpty())
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("售价不能为空"));
        ui->memPricelEdit->setFocus();
    }
    else if (ui->pricelEdit->text().isEmpty())
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("会员价不能为空"));
        ui->pricelEdit->setFocus();
    }
    else
    {
        bFlag = true;
    }
    return bFlag;
}

void QuickAddDlg::on_weighTypeCBox_currentIndexChanged(int index)
{
    if ((index == 1) || (index == 2))
    {
        ui->pluLabel->setText("PLU码：");
        ui->barCodelEdit->setText(m_sPlu);
        ui->barCodelEdit->setEnabled(false);
    }
    else
    {
        ui->pluLabel->setText("条码：");
        ui->barCodelEdit->setText("");
        ui->barCodelEdit->setEnabled(true);
    }
}

void QuickAddDlg::on_basicUnitCBox_currentTextChanged(const QString &arg1)
{
    ui->wUnitlabel->setText(arg1);
}

void QuickAddDlg::slot_Text(QString sText)
{
    QWidget *pWidget = QApplication::focusWidget();
    if (pWidget->inherits("QLineEdit"))
    {
        dynamic_cast<QLineEdit*>(pWidget)->insert(sText);
    }
}

void QuickAddDlg::slot_Delete()
{
    QWidget *pWidget = QApplication::focusWidget();
    if (pWidget->inherits("QLineEdit"))
    {
        dynamic_cast<QLineEdit*>(pWidget)->backspace();
    }
}

void QuickAddDlg::slot_Clear()
{
    QWidget *pWidget = QApplication::focusWidget();
    if (pWidget->inherits("QLineEdit"))
    {
        dynamic_cast<QLineEdit*>(pWidget)->clear();
    }
}

void QuickAddDlg::slot_Confirm()
{
    on_submitBtn_clicked();
}

void QuickAddDlg::initConnect()
{
    connect(ui->DigitalKeyWnd, SIGNAL(sigText(QString)), this, SLOT(slot_Text(QString)));
    connect(ui->DigitalKeyWnd, SIGNAL(sigDelete()), this, SLOT(slot_Delete()));
    connect(ui->DigitalKeyWnd, SIGNAL(sigClear()), this, SLOT(slot_Clear()));
    connect(ui->DigitalKeyWnd, SIGNAL(sigConfirm()), this, SLOT(slot_Confirm()));
}
