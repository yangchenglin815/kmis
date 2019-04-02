#ifndef SEARCHEDIT_H
#define SEARCHEDIT_H

#include <QWidget>
#include <QTimer>
#include "InputToolWidget.h"

namespace Ui {
class SearchEdit;
}

class SearchEdit : public QWidget
{
    Q_OBJECT

public:
    explicit SearchEdit(QWidget *parent = 0);
    ~SearchEdit();
    void setHintText(QString text); // 添加提示语
//    void startSearchTimer();
    QString getText();
    void setText(QString sText);
    void clearText();
    void setKeyboardPos(int nXPos, int nYPos, bool bHCenter=false);
    void autoSetKeyboardPos(int nOffX = 0, int nOffY = 0);
    void hideKeyboard();
    void setSearchFocus();
    void setLength(int length);
    void hideKeyboardButton();
    void setHolderText(QString sText);
    void setOuterLineColor(QString sColor = "#EA8852");
    void setSearchEditMaxLength(int maxLength);
    void resetStyleSheet();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_searchLineEdit_returnPressed();

    void on_keyboardButton_clicked();
//    void slot_timeout();
//    void slot_searchTimeout();
    void slot_addWord(QString sWord);
    void slot_delete();
    void slot_clear();
    void slot_cofirm();

//    void on_searchLineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    void initConnect();

signals:
    void sigSearchChanged(QString searchText);

private:
    Ui::SearchEdit *ui;
    QTimer timer;
//    QTimer searchTimer;
    QString sSearchText;
//    bool bStartSearchTimer;
    int m_nInputXPos;
    int m_nInputYPos;
    InputToolWidget* m_pInputToolWidget;
};

#endif // SEARCHEDIT_H
