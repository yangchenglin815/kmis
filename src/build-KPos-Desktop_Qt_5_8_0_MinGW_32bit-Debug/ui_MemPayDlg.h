/********************************************************************************
** Form generated from reading UI file 'MemPayDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMPAYDLG_H
#define UI_MEMPAYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_MemPayDlg
{
public:
    QGridLayout *gridLayout;
    TitleBarWidget *titleWidget;
    QWidget *widget_2;
    QLabel *payPasswdLabel;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *pwdErrorLabel;
    QPushButton *sureButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *MemPayDlg)
    {
        if (MemPayDlg->objectName().isEmpty())
            MemPayDlg->setObjectName(QStringLiteral("MemPayDlg"));
        MemPayDlg->resize(370, 231);
        MemPayDlg->setMinimumSize(QSize(370, 231));
        gridLayout = new QGridLayout(MemPayDlg);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(MemPayDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 40));
        titleWidget->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(titleWidget, 0, 0, 1, 1);

        widget_2 = new QWidget(MemPayDlg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(33, 33));
        widget_2->setStyleSheet(QLatin1String("QWidget#widget_2 {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        payPasswdLabel = new QLabel(widget_2);
        payPasswdLabel->setObjectName(QStringLiteral("payPasswdLabel"));
        payPasswdLabel->setGeometry(QRect(49, 48, 80, 33));
        payPasswdLabel->setMinimumSize(QSize(0, 31));
        QFont font;
        payPasswdLabel->setFont(font);
        payPasswdLabel->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(255, 255, 255);"));
        payPasswdLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_1 = new QLineEdit(widget_2);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        lineEdit_1->setEnabled(true);
        lineEdit_1->setGeometry(QRect(135, 48, 31, 31));
        lineEdit_1->setMinimumSize(QSize(31, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        lineEdit_1->setFont(font1);
        lineEdit_1->setFocusPolicy(Qt::NoFocus);
        lineEdit_1->setMaxLength(1);
        lineEdit_1->setEchoMode(QLineEdit::Password);
        lineEdit_1->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setGeometry(QRect(165, 48, 31, 31));
        lineEdit_2->setMinimumSize(QSize(31, 31));
        lineEdit_2->setFont(font1);
        lineEdit_2->setFocusPolicy(Qt::NoFocus);
        lineEdit_2->setMaxLength(1);
        lineEdit_2->setEchoMode(QLineEdit::Password);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_3 = new QLineEdit(widget_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(true);
        lineEdit_3->setGeometry(QRect(195, 48, 31, 31));
        lineEdit_3->setMinimumSize(QSize(31, 31));
        lineEdit_3->setFont(font1);
        lineEdit_3->setFocusPolicy(Qt::NoFocus);
        lineEdit_3->setMaxLength(1);
        lineEdit_3->setEchoMode(QLineEdit::Password);
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_4 = new QLineEdit(widget_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setEnabled(true);
        lineEdit_4->setGeometry(QRect(225, 48, 31, 31));
        lineEdit_4->setMinimumSize(QSize(31, 31));
        lineEdit_4->setFont(font1);
        lineEdit_4->setFocusPolicy(Qt::NoFocus);
        lineEdit_4->setMaxLength(1);
        lineEdit_4->setEchoMode(QLineEdit::Password);
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_5 = new QLineEdit(widget_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setEnabled(true);
        lineEdit_5->setGeometry(QRect(255, 48, 31, 31));
        lineEdit_5->setMinimumSize(QSize(31, 31));
        lineEdit_5->setFont(font1);
        lineEdit_5->setFocusPolicy(Qt::NoFocus);
        lineEdit_5->setMaxLength(1);
        lineEdit_5->setEchoMode(QLineEdit::Password);
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_6 = new QLineEdit(widget_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setEnabled(true);
        lineEdit_6->setGeometry(QRect(285, 48, 31, 31));
        lineEdit_6->setMinimumSize(QSize(31, 31));
        lineEdit_6->setFont(font1);
        lineEdit_6->setFocusPolicy(Qt::NoFocus);
        lineEdit_6->setMaxLength(1);
        lineEdit_6->setEchoMode(QLineEdit::Password);
        lineEdit_6->setAlignment(Qt::AlignCenter);
        pwdErrorLabel = new QLabel(widget_2);
        pwdErrorLabel->setObjectName(QStringLiteral("pwdErrorLabel"));
        pwdErrorLabel->setGeometry(QRect(135, 82, 211, 33));
        pwdErrorLabel->setMinimumSize(QSize(0, 31));
        pwdErrorLabel->setFont(font1);
        pwdErrorLabel->setStyleSheet(QLatin1String("/*color: rgb(250, 122, 122);*/\n"
"color: rgb(250, 122, 122);"));
        pwdErrorLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        sureButton = new QPushButton(widget_2);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        sureButton->setGeometry(QRect(20, 117, 156, 42));
        sureButton->setMinimumSize(QSize(156, 42));
        sureButton->setFont(font1);
        sureButton->setFocusPolicy(Qt::NoFocus);
        sureButton->setStyleSheet(QString::fromUtf8("QPushButton#sureButton {\n"
"	color: rgb(255, 255, 255);\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#sureButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));
        cancelButton = new QPushButton(widget_2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(194, 117, 156, 42));
        cancelButton->setMinimumSize(QSize(156, 42));
        cancelButton->setFont(font1);
        cancelButton->setFocusPolicy(Qt::NoFocus);
        cancelButton->setStyleSheet(QLatin1String("QPushButton#cancelButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/shareImages/cancel_normal.png);\n"
"}\n"
"\n"
"QPushButton#cancelButton:pressed {\n"
"	border-image: url(:/shareImages/cancel_press.png);\n"
"}"));

        gridLayout->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(MemPayDlg);

        QMetaObject::connectSlotsByName(MemPayDlg);
    } // setupUi

    void retranslateUi(QDialog *MemPayDlg)
    {
        MemPayDlg->setWindowTitle(QApplication::translate("MemPayDlg", "MemPayDlg", Q_NULLPTR));
        payPasswdLabel->setText(QApplication::translate("MemPayDlg", "\346\224\257\344\273\230\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        lineEdit_1->setText(QString());
        pwdErrorLabel->setText(QString());
        sureButton->setText(QApplication::translate("MemPayDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("MemPayDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MemPayDlg: public Ui_MemPayDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMPAYDLG_H
