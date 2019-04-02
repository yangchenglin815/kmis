#ifndef WARNINGDLG_H
#define WARNINGDLG_H

#include <QDialog>

namespace Ui {
class WarningDlg;
}

class WarningDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WarningDlg(QWidget *parent = 0);
    ~WarningDlg();

    void setTitle(QString strTitle);
    QString getTitle();
    void setContent(QString strContent);
    QString getContent();
public slots:
    void slotSure();
private:
    void initConnect();
private:
    Ui::WarningDlg *ui;
};

#endif // WARNINGDLG_H
