#ifndef INPUTTOOLWIDGET_H
#define INPUTTOOLWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QSqlQuery>

namespace Ui {
class InputToolWidget;
}

class InputToolWidget : public QWidget
{
    Q_OBJECT

public: 
    explicit InputToolWidget(QWidget *parent = 0);
    ~InputToolWidget();
//    static InputToolWidget *instance();
    void clearLabel(); //清空中文键盘label的内容

private:
    void handleWord(QString sWord);
    void init();
    void initForm();                //初始化UI
    void initProperty();            //初始化属性
    void setChinese(int index);     //设置当前汉字
    void clearChinese();            //清空当前汉字信息
    void selectChinese();           //查询汉字
    void showChinese();             //显示查询到的汉字

private slots:
    // 字符
    void on_qButton_clicked();
    void on_wButton_clicked();
    void on_eButton_clicked();
    void on_rButton_clicked();
    void on_tButton_clicked();
    void on_yButton_clicked();
    void on_uButton_clicked();
    void on_iButton_clicked();
    void on_oButton_clicked();
    void on_pButton_clicked();
    void on_aButton_clicked();
    void on_jButton_clicked();
    void on_fButton_clicked();
    void on_kButton_clicked();
    void on_dButton_clicked();
    void on_hButton_clicked();
    void on_sButton_clicked();
    void on_gButton_clicked();
    void on_lButton_clicked();
    void on_zButton_clicked();
    void on_xButton_clicked();
    void on_cButton_clicked();
    void on_vButton_clicked();
    void on_bButton_clicked();
    void on_nButton_clicked();
    void on_mButton_clicked();
    // 数字
    void on_num1Button_clicked();
    void on_num2Button_clicked();
    void on_num3Button_clicked();
    void on_num4Button_clicked();
    void on_num5Button_clicked();
    void on_num6Button_clicked();
    void on_num7Button_clicked();
    void on_num8Button_clicked();
    void on_num9Button_clicked();
    void on_num0Button_clicked();
    void on_dotButton_clicked();
    //
    void on_upperWordButton_clicked();
    void on_deleteWordButton_clicked();
    void on_deleteWord2Button_clicked();
    void on_changeInputMethodButton_clicked();
    void on_confirmButton_clicked();
    void focusChanged(QWidget *oldWidget, QWidget *nowWidget);

    void on_upPageBtn_clicked();

    void on_downPageBtn_clicked();

signals:
//    void sigWord(QString sWord);
//    void sigDeleteWord();
//    void sigClear();
    void sigConfirm();

private:
    Ui::InputToolWidget *ui;
    QSqlDatabase dataBase;
    QList<QPushButton*> m_wordButtonList;  //字母标签数组
    QList<QPushButton*> m_numButtonList;   //数字标签数组
    QList<QLabel *> lblCh;                 //汉字标签数组
    QLineEdit *currentLineEdit;            //当前焦点的文本框
    bool isEn;                             //英文输入法
    QStringList currentPY;                 //当前拼音链表
    QStringList allPY;                     //所有拼音链表
    int currentPY_index;                   //当前拼音索引
    int currentPY_count;                   //当前拼音数量
//    static InputToolWidget* m_pInstance;
};

#endif // INPUTTOOLWIDGET_H
