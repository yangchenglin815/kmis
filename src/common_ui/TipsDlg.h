#ifndef TIPSDLG_H
#define TIPSDLG_H

#include <QDialog>

namespace Ui {
class TipsDlg;
}

class TipsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit TipsDlg(QWidget *parent = 0);
    ~TipsDlg();
    static TipsDlg* instance();
    bool isPrased;//是否已处理完成
    bool isMasked;//是否遮罩
    void maskUI(const QString& str);//遮罩
    void releaseCtrl(const QString& str);//释放控制
    void workDone();

signals:
    void sig_masked();
    void sig_releaseCtrl();//释放控制,取消遮罩状态
private slots:
    void on_deleteBtn_clicked();

private:
    Ui::TipsDlg *ui;
private:
    static TipsDlg* m_pInstance;
};

#endif // TIPSDLG_H
