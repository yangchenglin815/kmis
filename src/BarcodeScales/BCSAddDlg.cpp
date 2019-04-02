#include "BCSAddDlg.h"
#include "ui_BCSAddDlg.h"
#include "../data/constData.h"
#include <QListView>

BCSAddDlg::BCSAddDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSAddDlg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->titleWidget->setTitleText(QStringLiteral("新增条码秤"));
    initConnect();
}

BCSAddDlg::~BCSAddDlg()
{
    delete ui;
}

void BCSAddDlg::setBcsCode(QString sBcsCode)
{
    ui->bcsCodeLabel->setText(sBcsCode);
}

void BCSAddDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));

    //数字键盘
    connect( ui->DigitalKeyWnd, SIGNAL( sigText(QString)), this, SLOT( slot_setText(QString) ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigDelete()), this, SLOT( slot_deleteValue() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigClear()), this, SLOT( slot_clearZero() ) );
    connect( ui->DigitalKeyWnd, SIGNAL( sigConfirm()), this, SLOT( slot_Confirm() ) );

    //商品组信息

    for(int i = 0 ; i<m_infoList.length() ; i++)
    {
        ui->goodsGroupComboBox->addItem(m_infoList[i].sGroupName);
    }
}

//软键盘输入
void BCSAddDlg::firstClick()
{
    if( m_bFirst ) {
        QLineEdit *p_wnd = NULL;
        bool b_has_focus = getCurFocusWnd( p_wnd );
        if( !b_has_focus ) return;

        p_wnd->setText( "" );

        m_bFirst = false;
    }
}

//输入数字
void BCSAddDlg::slot_setText( QString strText )
{
    firstClick();
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    QString sText = p_wnd->text();
    QString newText = sText.append( strText );

    QStringList textList = p_wnd->text().split(".");
    QStringList newTextList = newText.split(".");

    if(textList.length() == 4 )
    {
        if(newTextList.last().length() >= 4)
        {
            return;
        }
        if(strText == ".")
        {
            return;
        }
    }
    else if(newTextList.last().length() >= 3)
    {
            newText.append(".");
    }
    if(textList.last().length() == 0 && strText == ".")
    {
        return;
    }




    p_wnd->setText( newText );

}

void BCSAddDlg::slot_deleteValue()
{
    if( m_bFirst ) {
        m_bFirst = false;
    }

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    QString str_value = p_wnd->text();
    str_value.remove( str_value.length() - 1, 1);
    p_wnd->setText( str_value );
}

void BCSAddDlg::slot_clearZero()
{
    firstClick();

    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;

    p_wnd->setText( "" );
}

void BCSAddDlg::slot_Confirm()
{
    QLineEdit *p_wnd = NULL;
    bool b_has_focus = getCurFocusWnd( p_wnd );
    if( !b_has_focus ) return;
}

bool BCSAddDlg::getCurFocusWnd( QLineEdit *&pEditWnd )
{
    pEditWnd = (QLineEdit*)focusWidget();

    if( pEditWnd == ui->IPLineEdit)
    {
        return true;
    }
    return false;
}

//保存条码秤
void BCSAddDlg::on_pushFrom_clicked()
{
    QString ipText = ui->IPLineEdit->text();
    QStringList ipTextList = ipText.split(".");
    if(ipTextList.length() < 4)
    {
        return;
    }

    BarCodeScaleInfo bcsInfo;
    bcsInfo.sCode = ui->bcsCodeLabel->text();
    bcsInfo.sIP = ipText;
    bcsInfo.sModel = ui->typeComboBox->currentText();
    bcsInfo.sGoodsGroupName = ui->goodsGroupComboBox->currentText();
    bcsInfo.sGoodsGroup = QString::number(m_groupNameIDMap.value(bcsInfo.sGoodsGroupName));
    emit sigAddBarcodeScale(bcsInfo);

//    BarCodeScaleInfo scaleInfo;
//    scaleInfo.sIP = ui->IPLineEdit->text();
//    scaleInfo.sModel = ui->comboBox->currentText();
//    scaleInfo.sGoodsGroup = ui->comboBox_2->currentText();
//    scaleInfo.nState = 1;
//    emit sigAddInfoList(scaleInfo);
//    this->hide();
}

void BCSAddDlg::setLeftInfo(QList<BCSGroupManageLeftInfo> m_leftInfoList)
{
    m_infoList = m_leftInfoList;
    ui->goodsGroupComboBox->clear();
    ui->goodsGroupComboBox->setView(new QListView());
    ui->typeComboBox->setView(new QListView());
    m_groupNameIDMap.clear();
//    m_groupNameIDMap.insert(QStringLiteral("默认商品组"), c_nDefaultGoodsGroupId);
//    ui->goodsGroupComboBox->addItem(QStringLiteral("默认商品组"));
    for(int i = 0 ; i<m_infoList.length() ; i++)
    {
        m_groupNameIDMap.insert(m_infoList[i].sGroupName, m_infoList[i].nGroupId);
        ui->goodsGroupComboBox->addItem(m_infoList[i].sGroupName);
    }
}
