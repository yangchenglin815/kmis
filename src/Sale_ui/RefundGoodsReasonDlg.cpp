#include "RefundGoodsReasonDlg.h"
#include "ui_RefundGoodsReasonDlg.h"

#include <QDebug>

RefundGoodsReasonDlg::RefundGoodsReasonDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RefundGoodsReasonDlg)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->titleWidget->setTitleText(QStringLiteral("退货理由"));
    initConnect();
    m_lineEditList.append(ui->reason1Edit);
    m_lineEditList.append(ui->reason2Edit);
    m_lineEditList.append(ui->reason3Edit);
    m_lineEditList.append(ui->reason4Edit);
    int nLen = m_lineEditList.length();
    for (int i = 0; i < nLen; i++)
    {
        m_lineEditList[i]->installEventFilter(this);
    }
}

RefundGoodsReasonDlg::~RefundGoodsReasonDlg()
{
    delete ui;
}

void RefundGoodsReasonDlg::setReasonList(const QList<RefundGoodsReason> &reasonList)
{
    m_reasonList = reasonList;
    int nLen = reasonList.length();
    int nLineEditLen = m_lineEditList.length();
    for (int i = 0; i < nLineEditLen; i++)
    {
        if (i < nLen)
        {
           m_lineEditList[i]->setText(reasonList[i].sContent);
           m_lineEditList[i]->show();
        }
        else
        {
            m_lineEditList[i]->setText("");
            m_lineEditList[i]->hide();
        }
    }
}

bool RefundGoodsReasonDlg::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        if (watched == ui->reason1Edit)
        {
            clickReason(0);
        }
        else if (watched == ui->reason2Edit)
        {
            clickReason(1);
        }
        else if (watched == ui->reason3Edit)
        {
            clickReason(2);
        }
        else if (watched == ui->reason4Edit)
        {
            clickReason(3);
        }
    }
    return QDialog::eventFilter(watched, event);
}

void RefundGoodsReasonDlg::clickReason(int nPos)
{
    this->hide();
    sigClickReason(m_reasonList[nPos].nId);
}

void RefundGoodsReasonDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
}
