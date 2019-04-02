#ifndef ADDCUSTOMCATEGORYDLG_H
#define ADDCUSTOMCATEGORYDLG_H

#include <QDialog>
#include "InputToolWidget.h"

namespace Ui {
class AddCustomCategoryDlg;
}

class AddCustomCategoryDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomCategoryDlg(QWidget *parent = 0);
    ~AddCustomCategoryDlg();
    void clearData();
    void setHintText(QString sHintText);
    void setConfirmButtonEnable(bool flag);

protected:
//    void showEvent(QShowEvent *);
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_confirmButton_clicked();

private:
    void initConnect();

signals:
    void sigAddCategory(QString sCategoryName, int nPos );

private:
    Ui::AddCustomCategoryDlg *ui;
    InputToolWidget* m_pInputToolWidget;
    int m_nInputXPos;
    int m_nInputYPos;
};

#endif // ADDCUSTOMCATEGORYDLG_H
