#ifndef DLGCOMMON_H
#define DLGCOMMON_H

#include <QDialog>

namespace Ui {
class DlgCommon;
}

class DlgCommon : public QDialog
{
    Q_OBJECT

public:
    explicit DlgCommon(QWidget *parent = 0, bool bAccept = false );
    ~DlgCommon();

    void init_connect();
public:
    void set_title( QString str_title );
    QString get_title();

    void set_content( QString str_content );
    QString get_content();

    void set_btn_sure_text( QString str_sure );
    void set_btn_cancel_text( QString str_cancel );

    void hideCancelButton();
    void hideDeleteButton();
    void showDeleteButton();
    void hideSureButton();
    void hideBottomWidget();
    void showBottomWidget();

public slots:
    void slot_dlg_close();
    void slot_sure();
    void slot_cancel();
signals:
    void sig_dlg_close();
    void sig_btn_sure();
    void sig_btn_cancel();
private:
    Ui::DlgCommon *ui;

    bool m_bAccept;
};

#endif // DLGCOMMON_H
