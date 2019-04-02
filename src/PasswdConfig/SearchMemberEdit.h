#ifndef SEARCHMEMBEREDIT_H
#define SEARCHMEMBEREDIT_H

#include <QWidget>
#include <QTimer>
#include "InputToolWidget.h"

namespace Ui {
class SearchMemberEdit;
}

class SearchMemberEdit : public QWidget
{
    Q_OBJECT

public:
    explicit SearchMemberEdit(QWidget *parent = 0);
    ~SearchMemberEdit();
    void setHintText(QString text); // 添加提示语
    QString getText();
    void setText(QString sText);
    void clearText();
    void setKeyboardPos(int nXPos, int nYPos);
    void autoSetKeyboardPos(int nOffX = 0, int nOffY = 0);
    void hideKeyboard();
    void setSearchFocus();

signals:
    void sigSearchChanged(QString searchText);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void slot_addWord(QString sWord);
    void slot_delete();
    void slot_clear();
    void slot_cofirm();
    void on_keyboardButton_clicked();

private:
    Ui::SearchMemberEdit *ui;
    int m_nInputXPos;
    int m_nInputYPos;
    QTimer timer;
    QString sSearchText;
    InputToolWidget* m_pInputToolWidget;
    void initConnect();
};

#endif // SEARCHMEMBEREDIT_H
