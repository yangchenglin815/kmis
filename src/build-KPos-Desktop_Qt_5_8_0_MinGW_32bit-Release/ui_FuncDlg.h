/********************************************************************************
** Form generated from reading UI file 'FuncDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCDLG_H
#define UI_FUNCDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <WndDigitalKeyboard.h>
#include "SearchEdit.h"
#include "TitleBarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_FuncDlg
{
public:
    QGridLayout *gridLayout;
    TitleBarWidget *titleWidget;
    QWidget *inputWidget;
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QLabel *noLabel;
    QLabel *noValueLabel;
    QLabel *nameLabel;
    QLabel *passwdLabel;
    QLabel *telLabel;
    QLabel *powerLabel;
    QLineEdit *passwdEdit;
    QLineEdit *telEdit;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QPushButton *saveButton;
    QLabel *tipLabel;
    SearchEdit *nameWidget;
    QFrame *line;
    QWidget *keyboardWidget;
    QGridLayout *gridLayout_2;
    WndDigitalKeyboard *keyboardWgt;

    void setupUi(QDialog *FuncDlg)
    {
        if (FuncDlg->objectName().isEmpty())
            FuncDlg->setObjectName(QStringLiteral("FuncDlg"));
        FuncDlg->resize(726, 600);
        FuncDlg->setStyleSheet(QLatin1String("QDialog#FuncDlg {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        gridLayout = new QGridLayout(FuncDlg);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(FuncDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 40));
        titleWidget->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(titleWidget, 0, 0, 1, 4);

        inputWidget = new QWidget(FuncDlg);
        inputWidget->setObjectName(QStringLiteral("inputWidget"));
        inputWidget->setMinimumSize(QSize(300, 560));
        inputWidget->setMaximumSize(QSize(300, 560));
        gridLayout_3 = new QGridLayout(inputWidget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(15, 6, 15, 140);
        widget = new QWidget(inputWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 300));
        widget->setMaximumSize(QSize(16777215, 375));
        widget->setStyleSheet(QLatin1String("QWidget#widget {\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{\n"
"border-image:url(:/setImage/radio_select.png);\n"
"}\n"
""));
        noLabel = new QLabel(widget);
        noLabel->setObjectName(QStringLiteral("noLabel"));
        noLabel->setGeometry(QRect(12, 17, 71, 30));
        noLabel->setMinimumSize(QSize(0, 30));
        noLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        noLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        noValueLabel = new QLabel(widget);
        noValueLabel->setObjectName(QStringLiteral("noValueLabel"));
        noValueLabel->setGeometry(QRect(92, 17, 151, 30));
        noValueLabel->setMinimumSize(QSize(0, 30));
        noValueLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(4, 97, 81, 30));
        nameLabel->setMinimumSize(QSize(0, 30));
        nameLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        passwdLabel = new QLabel(widget);
        passwdLabel->setObjectName(QStringLiteral("passwdLabel"));
        passwdLabel->setGeometry(QRect(15, 142, 71, 30));
        passwdLabel->setMinimumSize(QSize(0, 30));
        passwdLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        passwdLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        telLabel = new QLabel(widget);
        telLabel->setObjectName(QStringLiteral("telLabel"));
        telLabel->setGeometry(QRect(16, 186, 71, 30));
        telLabel->setMinimumSize(QSize(0, 30));
        telLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        telLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        powerLabel = new QLabel(widget);
        powerLabel->setObjectName(QStringLiteral("powerLabel"));
        powerLabel->setGeometry(QRect(6, 222, 81, 30));
        powerLabel->setMinimumSize(QSize(0, 30));
        powerLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        powerLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        passwdEdit = new QLineEdit(widget);
        passwdEdit->setObjectName(QStringLiteral("passwdEdit"));
        passwdEdit->setGeometry(QRect(98, 143, 150, 30));
        passwdEdit->setMinimumSize(QSize(150, 30));
        passwdEdit->setStyleSheet(QLatin1String("border-image: url(:/shareImages/editRect.png);\n"
"padding-left:10px;"));
        telEdit = new QLineEdit(widget);
        telEdit->setObjectName(QStringLiteral("telEdit"));
        telEdit->setGeometry(QRect(99, 187, 150, 30));
        telEdit->setMinimumSize(QSize(150, 30));
        telEdit->setStyleSheet(QLatin1String("border-image: url(:/shareImages/editRect.png);\n"
"padding-left:10px;"));
        radioButton1 = new QRadioButton(widget);
        radioButton1->setObjectName(QStringLiteral("radioButton1"));
        radioButton1->setGeometry(QRect(99, 229, 51, 16));
        radioButton1->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"\n"
""));
        radioButton2 = new QRadioButton(widget);
        radioButton2->setObjectName(QStringLiteral("radioButton2"));
        radioButton2->setGeometry(QRect(158, 229, 61, 16));
        radioButton2->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        radioButton3 = new QRadioButton(widget);
        radioButton3->setObjectName(QStringLiteral("radioButton3"));
        radioButton3->setGeometry(QRect(99, 261, 89, 16));
        radioButton3->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        saveButton = new QPushButton(widget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(27, 305, 220, 44));
        saveButton->setMinimumSize(QSize(220, 44));
        saveButton->setStyleSheet(QLatin1String("QPushButton#saveButton {\n"
"	font:14px;\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#saveButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));
        tipLabel = new QLabel(widget);
        tipLabel->setObjectName(QStringLiteral("tipLabel"));
        tipLabel->setGeometry(QRect(30, 283, 221, 16));
        tipLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;"));
        tipLabel->setAlignment(Qt::AlignCenter);
        nameWidget = new SearchEdit(widget);
        nameWidget->setObjectName(QStringLiteral("nameWidget"));
        nameWidget->setGeometry(QRect(97, 98, 150, 30));
        nameWidget->setStyleSheet(QLatin1String("QWidget#nameWidget{\n"
"	border: 1px solid #EA8852;\n"
"}\n"
""));

        gridLayout_3->addWidget(widget, 0, 0, 1, 1);


        gridLayout->addWidget(inputWidget, 1, 0, 1, 1);

        line = new QFrame(FuncDlg);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(2, 0));
        line->setMaximumSize(QSize(2, 16777215));
        line->setStyleSheet(QStringLiteral("background-color: rgb(102, 102, 102);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 1, 1, 1);

        keyboardWidget = new QWidget(FuncDlg);
        keyboardWidget->setObjectName(QStringLiteral("keyboardWidget"));
        keyboardWidget->setMinimumSize(QSize(400, 0));
        gridLayout_2 = new QGridLayout(keyboardWidget);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(10, 44, 15, 193);
        keyboardWgt = new WndDigitalKeyboard(keyboardWidget);
        keyboardWgt->setObjectName(QStringLiteral("keyboardWgt"));
        keyboardWgt->setMinimumSize(QSize(303, 303));

        gridLayout_2->addWidget(keyboardWgt, 0, 0, 1, 1);


        gridLayout->addWidget(keyboardWidget, 1, 2, 1, 1);


        retranslateUi(FuncDlg);

        QMetaObject::connectSlotsByName(FuncDlg);
    } // setupUi

    void retranslateUi(QDialog *FuncDlg)
    {
        FuncDlg->setWindowTitle(QApplication::translate("FuncDlg", "Dialog", Q_NULLPTR));
        noLabel->setText(QApplication::translate("FuncDlg", "\345\221\230\345\267\245\345\267\245\345\217\267:", Q_NULLPTR));
        noValueLabel->setText(QApplication::translate("FuncDlg", "0001", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("FuncDlg", "*\345\221\230\345\267\245\345\247\223\345\220\215:", Q_NULLPTR));
        passwdLabel->setText(QApplication::translate("FuncDlg", "*\345\221\230\345\267\245\345\257\206\347\240\201:", Q_NULLPTR));
        telLabel->setText(QApplication::translate("FuncDlg", "\346\211\213\346\234\272\345\217\267\347\240\201:", Q_NULLPTR));
        powerLabel->setText(QApplication::translate("FuncDlg", "*\350\247\222\350\211\262\346\235\203\351\231\220:", Q_NULLPTR));
        radioButton1->setText(QApplication::translate("FuncDlg", "\345\272\227\351\225\277", Q_NULLPTR));
        radioButton2->setText(QApplication::translate("FuncDlg", "\346\224\266\351\223\266\345\221\230", Q_NULLPTR));
        radioButton3->setText(QApplication::translate("FuncDlg", "\345\257\274\350\264\255\345\221\230", Q_NULLPTR));
        saveButton->setText(QApplication::translate("FuncDlg", "\344\277\235\345\255\230", Q_NULLPTR));
        tipLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FuncDlg: public Ui_FuncDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCDLG_H
