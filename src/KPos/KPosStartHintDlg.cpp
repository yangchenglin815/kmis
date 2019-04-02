#include "KPosStartHintDlg.h"

KPosStartHintDlg* KPosStartHintDlg::m_pInstance = NULL;

KPosStartHintDlg::KPosStartHintDlg(QWidget *parent)
    : DlgCommon(parent)
{
    this->hideCancelButton();
    this->hideDeleteButton();
    this->set_title(QStringLiteral("提示"));
    initConnect();
}

void KPosStartHintDlg::initConnect()
{
    connect(this, SIGNAL(sig_btn_sure()), this, SLOT(slot_confirm()));
}

void KPosStartHintDlg::slot_confirm()
{
    this->hide();
}

KPosStartHintDlg *KPosStartHintDlg::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new KPosStartHintDlg;
    }
    return m_pInstance;
}
