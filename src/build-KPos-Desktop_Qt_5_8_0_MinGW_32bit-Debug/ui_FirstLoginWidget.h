/********************************************************************************
** Form generated from reading UI file 'FirstLoginWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTLOGINWIDGET_H
#define UI_FIRSTLOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <WndDigitalKeyboard.h>

QT_BEGIN_NAMESPACE

class Ui_FirstLoginWidget
{
public:
    QFrame *splitLine;
    WndDigitalKeyboard *keyboardWidget;
    QPushButton *closedButton;
    QStackedWidget *stackedWidget;
    QWidget *registPage;
    QVBoxLayout *verticalLayout;
    QWidget *FirstLginInfoWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *firstLoginLabel;
    QWidget *loginInfoWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *corpIDLabel;
    QLineEdit *corpIDEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *shopIDLabel;
    QLineEdit *shopIDEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *hintLabel;
    QPushButton *uploadButton;
    QWidget *waitPage;
    QVBoxLayout *verticalLayout_3;
    QWidget *topWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *corpNameLabel;
    QLabel *shopNameLabel;
    QWidget *widget_2;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *waitTimeLabel;

    void setupUi(QDialog *FirstLoginWidget)
    {
        if (FirstLoginWidget->objectName().isEmpty())
            FirstLoginWidget->setObjectName(QStringLiteral("FirstLoginWidget"));
        FirstLoginWidget->resize(800, 600);
        FirstLoginWidget->setMinimumSize(QSize(800, 600));
        splitLine = new QFrame(FirstLoginWidget);
        splitLine->setObjectName(QStringLiteral("splitLine"));
        splitLine->setGeometry(QRect(400, 0, 2, 600));
        splitLine->setMinimumSize(QSize(2, 600));
        splitLine->setFrameShape(QFrame::VLine);
        splitLine->setFrameShadow(QFrame::Sunken);
        keyboardWidget = new WndDigitalKeyboard(FirstLoginWidget);
        keyboardWidget->setObjectName(QStringLiteral("keyboardWidget"));
        keyboardWidget->setGeometry(QRect(418, 135, 302, 300));
        keyboardWidget->setMinimumSize(QSize(302, 300));
        keyboardWidget->setMaximumSize(QSize(302, 300));
        closedButton = new QPushButton(FirstLoginWidget);
        closedButton->setObjectName(QStringLiteral("closedButton"));
        closedButton->setGeometry(QRect(760, 10, 30, 30));
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
        stackedWidget = new QStackedWidget(FirstLoginWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(87, 135, 296, 302));
        stackedWidget->setMinimumSize(QSize(294, 301));
        registPage = new QWidget();
        registPage->setObjectName(QStringLiteral("registPage"));
        verticalLayout = new QVBoxLayout(registPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FirstLginInfoWidget = new QWidget(registPage);
        FirstLginInfoWidget->setObjectName(QStringLiteral("FirstLginInfoWidget"));
        FirstLginInfoWidget->setMinimumSize(QSize(296, 302));
        FirstLginInfoWidget->setMaximumSize(QSize(296, 302));
        verticalLayout_4 = new QVBoxLayout(FirstLginInfoWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        firstLoginLabel = new QLabel(FirstLginInfoWidget);
        firstLoginLabel->setObjectName(QStringLiteral("firstLoginLabel"));
        firstLoginLabel->setMinimumSize(QSize(294, 55));
        firstLoginLabel->setMaximumSize(QSize(16777215, 55));
        firstLoginLabel->setStyleSheet(QLatin1String("color:#ea8852;\n"
"background-color: #ffffff;\n"
"border-bottom: 1px solid #ededed;\n"
""));

        verticalLayout_4->addWidget(firstLoginLabel);

        loginInfoWidget = new QWidget(FirstLginInfoWidget);
        loginInfoWidget->setObjectName(QStringLiteral("loginInfoWidget"));
        loginInfoWidget->setMinimumSize(QSize(296, 247));
        loginInfoWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        gridLayout = new QGridLayout(loginInfoWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(12);
        gridLayout->setContentsMargins(18, 40, 18, 40);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        corpIDLabel = new QLabel(loginInfoWidget);
        corpIDLabel->setObjectName(QStringLiteral("corpIDLabel"));
        corpIDLabel->setMinimumSize(QSize(0, 30));
        QFont font;
        corpIDLabel->setFont(font);
        corpIDLabel->setStyleSheet(QStringLiteral("font-size:14px;"));

        horizontalLayout->addWidget(corpIDLabel);

        corpIDEdit = new QLineEdit(loginInfoWidget);
        corpIDEdit->setObjectName(QStringLiteral("corpIDEdit"));
        corpIDEdit->setMinimumSize(QSize(180, 30));
        corpIDEdit->setStyleSheet(QLatin1String("/*border-image: url(:/shareImages/editRect.png);\n"
"font-size:12px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;*/\n"
""));

        horizontalLayout->addWidget(corpIDEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        shopIDLabel = new QLabel(loginInfoWidget);
        shopIDLabel->setObjectName(QStringLiteral("shopIDLabel"));
        shopIDLabel->setMinimumSize(QSize(0, 30));
        shopIDLabel->setFont(font);
        shopIDLabel->setStyleSheet(QStringLiteral("font-size:14px;"));

        horizontalLayout_2->addWidget(shopIDLabel);

        shopIDEdit = new QLineEdit(loginInfoWidget);
        shopIDEdit->setObjectName(QStringLiteral("shopIDEdit"));
        shopIDEdit->setMinimumSize(QSize(180, 30));
        shopIDEdit->setStyleSheet(QLatin1String("border-image: url(:/shareImages/editRect.png);\n"
"font-size:12px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));

        horizontalLayout_2->addWidget(shopIDEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        hintLabel = new QLabel(loginInfoWidget);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setStyleSheet(QStringLiteral("color:#ea8852;"));

        horizontalLayout_3->addWidget(hintLabel);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        uploadButton = new QPushButton(loginInfoWidget);
        uploadButton->setObjectName(QStringLiteral("uploadButton"));
        uploadButton->setMinimumSize(QSize(260, 45));
        uploadButton->setStyleSheet(QLatin1String("QPushButton{\n"
"color:#ffffff;\n"
"font-size:16px;\n"
"border-image: url(:/loginImage/commonButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/loginImage/commonButtonPressed.png);\n"
"}"));

        gridLayout->addWidget(uploadButton, 1, 0, 1, 1);


        verticalLayout_4->addWidget(loginInfoWidget);


        verticalLayout->addWidget(FirstLginInfoWidget);

        stackedWidget->addWidget(registPage);
        waitPage = new QWidget();
        waitPage->setObjectName(QStringLiteral("waitPage"));
        waitPage->setStyleSheet(QStringLiteral("background-color:#ffffff;"));
        verticalLayout_3 = new QVBoxLayout(waitPage);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(waitPage);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 55));
        topWidget->setMaximumSize(QSize(16777215, 55));
        topWidget->setStyleSheet(QLatin1String("QWidget#topWidget{\n"
"	border-bottom: 1px solid #ededed;\n"
"}\n"
""));
        verticalLayout_5 = new QVBoxLayout(topWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(15, 10, 0, 10);
        corpNameLabel = new QLabel(topWidget);
        corpNameLabel->setObjectName(QStringLiteral("corpNameLabel"));
        corpNameLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#999999;"));

        verticalLayout_5->addWidget(corpNameLabel);

        shopNameLabel = new QLabel(topWidget);
        shopNameLabel->setObjectName(QStringLiteral("shopNameLabel"));
        shopNameLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#999999;"));

        verticalLayout_5->addWidget(shopNameLabel);


        verticalLayout_3->addWidget(topWidget);

        widget_2 = new QWidget(waitPage);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 160, 140, 20));
        label_2->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#999999;"));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 130, 80, 21));
        label->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 46, 60, 60));
        label_3->setMinimumSize(QSize(60, 60));
        label_3->setMaximumSize(QSize(60, 60));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/shareImages/upload_success.png);"));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 200, 41, 16));
        label_6->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#999999;"));
        waitTimeLabel = new QLabel(widget_2);
        waitTimeLabel->setObjectName(QStringLiteral("waitTimeLabel"));
        waitTimeLabel->setGeometry(QRect(145, 200, 101, 16));
        waitTimeLabel->setStyleSheet(QString::fromUtf8("font-size:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#ea8852;"));

        verticalLayout_3->addWidget(widget_2);

        stackedWidget->addWidget(waitPage);

        retranslateUi(FirstLoginWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FirstLoginWidget);
    } // setupUi

    void retranslateUi(QDialog *FirstLoginWidget)
    {
        FirstLoginWidget->setWindowTitle(QApplication::translate("FirstLoginWidget", "FirstLoginWidget", Q_NULLPTR));
        closedButton->setText(QString());
        firstLoginLabel->setText(QApplication::translate("FirstLoginWidget", "    \351\246\226\346\254\241\347\231\273\345\275\225\344\277\241\346\201\257\347\241\256\350\256\244", Q_NULLPTR));
        corpIDLabel->setText(QApplication::translate("FirstLoginWidget", "\344\274\201\344\270\232\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        corpIDEdit->setPlaceholderText(QApplication::translate("FirstLoginWidget", "\350\257\267\345\234\250\346\255\244\350\276\223\345\205\245\346\202\250\347\232\204\344\274\201\344\270\232\347\274\226\345\217\267", Q_NULLPTR));
        shopIDLabel->setText(QApplication::translate("FirstLoginWidget", "\351\227\250\345\272\227\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        shopIDEdit->setPlaceholderText(QApplication::translate("FirstLoginWidget", "\350\257\267\345\234\250\346\255\244\350\276\223\345\205\245\346\202\250\347\232\204\351\227\250\345\272\227\347\274\226\345\217\267", Q_NULLPTR));
        hintLabel->setText(QApplication::translate("FirstLoginWidget", "\347\273\204\347\273\207\347\274\226\345\217\267\346\210\226\351\227\250\345\272\227\347\274\226\345\217\267\351\224\231\350\257\257\357\274\201", Q_NULLPTR));
        uploadButton->setText(QApplication::translate("FirstLoginWidget", "\344\270\212\344\274\240\347\224\263\350\257\267", Q_NULLPTR));
        corpNameLabel->setText(QApplication::translate("FirstLoginWidget", "\344\274\201\344\270\232\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        shopNameLabel->setText(QApplication::translate("FirstLoginWidget", "\351\227\250\345\272\227\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("FirstLoginWidget", "\350\257\267\350\200\220\345\277\203\347\255\211\345\276\205\347\256\241\347\220\206\345\221\230\345\256\241\346\240\270", Q_NULLPTR));
        label->setText(QApplication::translate("FirstLoginWidget", "\345\267\262\344\270\212\344\274\240\346\210\220\345\212\237", Q_NULLPTR));
        label_3->setText(QString());
        label_6->setText(QApplication::translate("FirstLoginWidget", "\345\267\262\347\255\211\345\276\205", Q_NULLPTR));
        waitTimeLabel->setText(QApplication::translate("FirstLoginWidget", "10s", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FirstLoginWidget: public Ui_FirstLoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTLOGINWIDGET_H
