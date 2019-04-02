#include "AddCustomCategoryDlg.h"
#include "ui_AddCustomCategoryDlg.h"
#include <QDesktopWidget>

AddCustomCategoryDlg::AddCustomCategoryDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCustomCategoryDlg)
    , m_pInputToolWidget(NULL)
    , m_nInputXPos(0)
    , m_nInputYPos(0)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    ui->titleWidget->setTitleText(QStringLiteral("添加分类"));
    ui->positionLineEdit->setValidator(new QIntValidator(0, 10000, this));
    ui->nameLineEdit->installEventFilter(this);
    ui->positionLineEdit->installEventFilter(this);
    ui->nameLineEdit->setPlaceholderText(QStringLiteral("请输入分类名，最多8位"));
    ui->positionLineEdit->setPlaceholderText(QStringLiteral("请输入数字，最多4位"));

    m_pInputToolWidget = new InputToolWidget;
    initConnect();
}

AddCustomCategoryDlg::~AddCustomCategoryDlg()
{
    delete ui;
}

void AddCustomCategoryDlg::clearData()
{
    ui->hintLabel->setText("");
    ui->nameLineEdit->setText("");
    ui->positionLineEdit->setText("");
}

void AddCustomCategoryDlg::setHintText(QString sHintText)
{
    ui->hintLabel->setText(sHintText);
}

void AddCustomCategoryDlg::setConfirmButtonEnable(bool flag)
{
    ui->confirmButton->setEnabled(flag);
}

//void AddCustomCategoryDlg::showEvent(QShowEvent *)
//{
//    QPoint globalPoint = ui->positionLineEdit->mapToGlobal(QPoint(0, 0));
//    const int nOffx = 11;
//    m_nInputXPos = nOffx;
//    m_nInputYPos = globalPoint.y() + ui->positionLineEdit->height();
//}

bool AddCustomCategoryDlg::eventFilter(QObject *watched, QEvent *event)
{
    bool flag = QWidget::eventFilter(watched, event);
    if ((watched == ui->nameLineEdit) || (watched == ui->positionLineEdit))         //首先判断控件
    {
        if(event->type()==QEvent::MouseButtonPress )
        {
            int nXPos = (800 - m_pInputToolWidget->width())/2; // 暂时考虑800*600的
            int nYPos = 0;
            if (watched == ui->nameLineEdit)
            {
                QPoint globalPoint = ui->nameLineEdit->mapToGlobal(QPoint(0, 0));
                nYPos = globalPoint.y() + ui->nameLineEdit->height();
            }
            else
            {
                QPoint globalPoint = ui->positionLineEdit->mapToGlobal(QPoint(0, 0));
                nYPos = globalPoint.y() + ui->positionLineEdit->height();
            }
            m_pInputToolWidget->move(nXPos, nYPos);
            m_pInputToolWidget->activateWindow();
            m_pInputToolWidget->clearLabel();
            m_pInputToolWidget->showNormal();
        }
    }
    return flag;
}

void AddCustomCategoryDlg::on_confirmButton_clicked()
{
    QString sCategoryName = ui->nameLineEdit->text();
    int nPos = ui->positionLineEdit->text().toInt();
    if (sCategoryName.isEmpty())
    {
        ui->hintLabel->setText("分类名不能为空！");
    }
    else if (nPos <= 0)
    {
        ui->hintLabel->setText("位置要大于等于1");
    }
    else
    {
        emit sigAddCategory(sCategoryName, nPos);
    }
}

void AddCustomCategoryDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
}
