#ifndef KPOSSTARTHINTDLG_H
#define KPOSSTARTHINTDLG_H

#include "DlgCommon.h"

class KPosStartHintDlg : public DlgCommon
{
    Q_OBJECT
public:
    static KPosStartHintDlg* instance();

private:
    explicit KPosStartHintDlg(QWidget *parent = 0);
    void initConnect();

private slots:
    void slot_confirm();

private:
    static KPosStartHintDlg* m_pInstance;
};

#endif // KPOSSTARTHINTDLG_H
