/********************************************************************************
** Form generated from reading UI file 'LoginWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "WndDigitalKeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QPushButton *closedButton;
    QWidget *loginInfoWidget;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_2;
    QWidget *page_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *numberLabel;
    QLineEdit *userNameEdit;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *storeNumberLabel;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *hintLabel;
    QPushButton *loginButton;
    QSpacerItem *verticalSpacer_3;
    WndDigitalKeyboard *keyboardWidget;
    QFrame *splitLine;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QStringLiteral("LoginWidget"));
        LoginWidget->resize(800, 600);
        closedButton = new QPushButton(LoginWidget);
        closedButton->setObjectName(QStringLiteral("closedButton"));
        closedButton->setGeometry(QRect(740, 10, 30, 30));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(closedButton->sizePolicy().hasHeightForWidth());
        closedButton->setSizePolicy(sizePolicy);
        closedButton->setMinimumSize(QSize(30, 30));
        closedButton->setFocusPolicy(Qt::NoFocus);
        closedButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/shareImages/close.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/shareImages/close_press.png);\n"
"}"));
        loginInfoWidget = new QWidget(LoginWidget);
        loginInfoWidget->setObjectName(QStringLiteral("loginInfoWidget"));
        loginInfoWidget->setGeometry(QRect(100, 135, 303, 301));
        loginInfoWidget->setMinimumSize(QSize(296, 301));
        loginInfoWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font-size:12px;"));
        verticalLayout_3 = new QVBoxLayout(loginInfoWidget);
        verticalLayout_3->setSpacing(18);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(18, 0, 18, 0);
        stackedWidget = new QStackedWidget(loginInfoWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(0, 80));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(86, 34, 95, 30));
        label_2->setMinimumSize(QSize(95, 30));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/shareImages/logo.png);"));
        label_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(119, 23, 28, 33));
        label->setMinimumSize(QSize(28, 33));
        label->setStyleSheet(QLatin1String("QLabel#label {	\n"
"	border-image: url(:/loginImage/lock.png);\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_2);

        verticalLayout_3->addWidget(stackedWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        numberLabel = new QLabel(loginInfoWidget);
        numberLabel->setObjectName(QStringLiteral("numberLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(numberLabel->sizePolicy().hasHeightForWidth());
        numberLabel->setSizePolicy(sizePolicy1);
        QFont font;
        numberLabel->setFont(font);
        numberLabel->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(51, 51, 51);"));

        horizontalLayout->addWidget(numberLabel);

        userNameEdit = new QLineEdit(loginInfoWidget);
        userNameEdit->setObjectName(QStringLiteral("userNameEdit"));
        userNameEdit->setMinimumSize(QSize(205, 30));
        userNameEdit->setStyleSheet(QLatin1String("border-image: url(:/shareImages/editRect.png);\n"
"padding-left:10px;"));

        horizontalLayout->addWidget(userNameEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        storeNumberLabel = new QLabel(loginInfoWidget);
        storeNumberLabel->setObjectName(QStringLiteral("storeNumberLabel"));
        sizePolicy1.setHeightForWidth(storeNumberLabel->sizePolicy().hasHeightForWidth());
        storeNumberLabel->setSizePolicy(sizePolicy1);
        storeNumberLabel->setFont(font);
        storeNumberLabel->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(51, 51, 51);"));

        horizontalLayout_2->addWidget(storeNumberLabel);

        passwordEdit = new QLineEdit(loginInfoWidget);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setMinimumSize(QSize(205, 30));
        passwordEdit->setStyleSheet(QLatin1String("border-image: url(:/shareImages/editRect.png);\n"
"color: rgb(51, 51, 51);\n"
"padding-left:10px;\n"
"font:8px;"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        hintLabel = new QLabel(loginInfoWidget);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setMinimumSize(QSize(205, 0));
        hintLabel->setStyleSheet(QStringLiteral("color:#fa7a7a;"));

        horizontalLayout_3->addWidget(hintLabel);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        loginButton = new QPushButton(loginInfoWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setMinimumSize(QSize(260, 45));
        loginButton->setStyleSheet(QLatin1String("QPushButton{\n"
"color:#ffffff;\n"
"font-size:16px;\n"
"border-image: url(:/loginImage/commonButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/loginImage/commonButtonPressed.png);\n"
"}"));

        verticalLayout_3->addWidget(loginButton);

        verticalSpacer_3 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        keyboardWidget = new WndDigitalKeyboard(LoginWidget);
        keyboardWidget->setObjectName(QStringLiteral("keyboardWidget"));
        keyboardWidget->setGeometry(QRect(420, 135, 302, 301));
        keyboardWidget->setMinimumSize(QSize(302, 301));
        splitLine = new QFrame(LoginWidget);
        splitLine->setObjectName(QStringLiteral("splitLine"));
        splitLine->setGeometry(QRect(410, 0, 2, 600));
        splitLine->setFrameShape(QFrame::VLine);
        splitLine->setFrameShadow(QFrame::Sunken);

        retranslateUi(LoginWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QApplication::translate("LoginWidget", "LoginWidget", Q_NULLPTR));
        closedButton->setText(QString());
        label_2->setText(QString());
        label->setText(QString());
        numberLabel->setText(QApplication::translate("LoginWidget", "\350\264\246\345\217\267\357\274\232", Q_NULLPTR));
        userNameEdit->setText(QString());
        userNameEdit->setPlaceholderText(QString());
        storeNumberLabel->setText(QApplication::translate("LoginWidget", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        hintLabel->setText(QString());
        loginButton->setText(QApplication::translate("LoginWidget", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
