/********************************************************************************
** Form generated from reading UI file 'AdjustPositionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTPOSITIONWIDGET_H
#define UI_ADJUSTPOSITIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdjustPositionWidget
{
public:
    QWidget *keyBoardWidget;
    QGridLayout *gridLayout;
    QPushButton *num5Button;
    QPushButton *num4Button;
    QPushButton *num7Button;
    QPushButton *num2Button;
    QPushButton *num1Button;
    QPushButton *num8Button;
    QPushButton *deleteButton;
    QPushButton *num6Button;
    QPushButton *num3Button;
    QPushButton *num0Button;
    QPushButton *num9Button;
    QPushButton *enterButton;
    QWidget *adjustSkinWidget;
    QPushButton *leftArrowButton;
    QPushButton *rightArrowButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *AdjustPositionWidget)
    {
        if (AdjustPositionWidget->objectName().isEmpty())
            AdjustPositionWidget->setObjectName(QStringLiteral("AdjustPositionWidget"));
        AdjustPositionWidget->resize(370, 347);
        keyBoardWidget = new QWidget(AdjustPositionWidget);
        keyBoardWidget->setObjectName(QStringLiteral("keyBoardWidget"));
        keyBoardWidget->setGeometry(QRect(0, 56, 370, 282));
        keyBoardWidget->setStyleSheet(QLatin1String("QWidget#keyBoardWidget{\n"
"border-image: url(:/kPosSetImage/adjust/keyBoardSkin.png);\n"
"}"));
        gridLayout = new QGridLayout(keyBoardWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(7);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(15, 10, 15, 20);
        num5Button = new QPushButton(keyBoardWidget);
        num5Button->setObjectName(QStringLiteral("num5Button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(num5Button->sizePolicy().hasHeightForWidth());
        num5Button->setSizePolicy(sizePolicy);
        num5Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKey.png);\n"
"	font-size:27px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#868686;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num5Button, 1, 1, 1, 1);

        num4Button = new QPushButton(keyBoardWidget);
        num4Button->setObjectName(QStringLiteral("num4Button"));
        sizePolicy.setHeightForWidth(num4Button->sizePolicy().hasHeightForWidth());
        num4Button->setSizePolicy(sizePolicy);
        num4Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKey.png);\n"
"	font-size:27px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#868686;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num4Button, 1, 0, 1, 1);

        num7Button = new QPushButton(keyBoardWidget);
        num7Button->setObjectName(QStringLiteral("num7Button"));
        sizePolicy.setHeightForWidth(num7Button->sizePolicy().hasHeightForWidth());
        num7Button->setSizePolicy(sizePolicy);
        num7Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKey.png);\n"
"	font-size:27px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#868686;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num7Button, 2, 0, 1, 1);

        num2Button = new QPushButton(keyBoardWidget);
        num2Button->setObjectName(QStringLiteral("num2Button"));
        sizePolicy.setHeightForWidth(num2Button->sizePolicy().hasHeightForWidth());
        num2Button->setSizePolicy(sizePolicy);
        num2Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKey.png);\n"
"	font-size:27px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#868686;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num2Button, 0, 1, 1, 1);

        num1Button = new QPushButton(keyBoardWidget);
        num1Button->setObjectName(QStringLiteral("num1Button"));
        sizePolicy.setHeightForWidth(num1Button->sizePolicy().hasHeightForWidth());
        num1Button->setSizePolicy(sizePolicy);
        num1Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKey.png);\n"
"	font-size:27px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#868686;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num1Button, 0, 0, 1, 1);

        num8Button = new QPushButton(keyBoardWidget);
        num8Button->setObjectName(QStringLiteral("num8Button"));
        sizePolicy.setHeightForWidth(num8Button->sizePolicy().hasHeightForWidth());
        num8Button->setSizePolicy(sizePolicy);
        num8Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKey.png);\n"
"	font-size:27px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#868686;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num8Button, 2, 1, 1, 1);

        deleteButton = new QPushButton(keyBoardWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setStyleSheet(QLatin1String("QPushButton{	\n"
"	border-image: url(:/kPosSetImage/adjust/delete.png);\n"
"}\n"
"\n"
"QPushButton:pressed{	\n"
"	border-image: url(:/kPosSetImage/adjust/delete_pressed.png);\n"
"}"));

        gridLayout->addWidget(deleteButton, 0, 4, 1, 1);

        num6Button = new QPushButton(keyBoardWidget);
        num6Button->setObjectName(QStringLiteral("num6Button"));
        sizePolicy.setHeightForWidth(num6Button->sizePolicy().hasHeightForWidth());
        num6Button->setSizePolicy(sizePolicy);
        num6Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKey.png);\n"
"	font-size:27px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#868686;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num6Button, 1, 2, 1, 1);

        num3Button = new QPushButton(keyBoardWidget);
        num3Button->setObjectName(QStringLiteral("num3Button"));
        sizePolicy.setHeightForWidth(num3Button->sizePolicy().hasHeightForWidth());
        num3Button->setSizePolicy(sizePolicy);
        num3Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKey.png);\n"
"	font-size:27px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#868686;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num3Button, 0, 2, 1, 1);

        num0Button = new QPushButton(keyBoardWidget);
        num0Button->setObjectName(QStringLiteral("num0Button"));
        sizePolicy.setHeightForWidth(num0Button->sizePolicy().hasHeightForWidth());
        num0Button->setSizePolicy(sizePolicy);
        num0Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKey.png);\n"
"	font-size:27px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#868686;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num0Button, 1, 4, 1, 1);

        num9Button = new QPushButton(keyBoardWidget);
        num9Button->setObjectName(QStringLiteral("num9Button"));
        sizePolicy.setHeightForWidth(num9Button->sizePolicy().hasHeightForWidth());
        num9Button->setSizePolicy(sizePolicy);
        num9Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKey.png);\n"
"	font-size:27px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#868686;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/adjust/numberKeyPressed.png);\n"
"}"));

        gridLayout->addWidget(num9Button, 2, 2, 1, 1);

        enterButton = new QPushButton(keyBoardWidget);
        enterButton->setObjectName(QStringLiteral("enterButton"));
        sizePolicy.setHeightForWidth(enterButton->sizePolicy().hasHeightForWidth());
        enterButton->setSizePolicy(sizePolicy);
        enterButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/enter.png);\n"
"}\n"
"\n"
"QPushButton:pressed{	\n"
"	border-image: url(:/kPosSetImage/adjust/enterPressed.png);\n"
"}"));

        gridLayout->addWidget(enterButton, 2, 4, 1, 1);

        adjustSkinWidget = new QWidget(AdjustPositionWidget);
        adjustSkinWidget->setObjectName(QStringLiteral("adjustSkinWidget"));
        adjustSkinWidget->setGeometry(QRect(118, 0, 133, 49));
        adjustSkinWidget->setMinimumSize(QSize(133, 49));
        adjustSkinWidget->setMaximumSize(QSize(133, 49));
        adjustSkinWidget->setStyleSheet(QLatin1String("QWidget#adjustSkinWidget{\n"
"	border-image: url(:/kPosSetImage/adjust/adjustPositionRect.png);\n"
"}"));
        leftArrowButton = new QPushButton(adjustSkinWidget);
        leftArrowButton->setObjectName(QStringLiteral("leftArrowButton"));
        leftArrowButton->setGeometry(QRect(13, 20, 15, 18));
        leftArrowButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/leftArrow.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	border-image: url(:/kPosSetImage/adjust/leftArrowPressed.png);\n"
"}\n"
""));
        rightArrowButton = new QPushButton(adjustSkinWidget);
        rightArrowButton->setObjectName(QStringLiteral("rightArrowButton"));
        rightArrowButton->setGeometry(QRect(105, 20, 15, 18));
        rightArrowButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/kPosSetImage/adjust/rightArrow.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/adjust/rightArrowPressed.png);\n"
"}\n"
""));
        lineEdit = new QLineEdit(adjustSkinWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(31, 16, 72, 26));
        lineEdit->setStyleSheet(QString::fromUtf8("border: 1px solid #ea8852;\n"
"font-size:16px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"padding-left:0px;"));
        lineEdit->setMaxLength(6);
        lineEdit->setAlignment(Qt::AlignCenter);

        retranslateUi(AdjustPositionWidget);

        QMetaObject::connectSlotsByName(AdjustPositionWidget);
    } // setupUi

    void retranslateUi(QWidget *AdjustPositionWidget)
    {
        AdjustPositionWidget->setWindowTitle(QApplication::translate("AdjustPositionWidget", "Form", Q_NULLPTR));
        num5Button->setText(QApplication::translate("AdjustPositionWidget", "5", Q_NULLPTR));
        num4Button->setText(QApplication::translate("AdjustPositionWidget", "4", Q_NULLPTR));
        num7Button->setText(QApplication::translate("AdjustPositionWidget", "7", Q_NULLPTR));
        num2Button->setText(QApplication::translate("AdjustPositionWidget", "2", Q_NULLPTR));
        num1Button->setText(QApplication::translate("AdjustPositionWidget", "1", Q_NULLPTR));
        num8Button->setText(QApplication::translate("AdjustPositionWidget", "8", Q_NULLPTR));
        deleteButton->setText(QString());
        num6Button->setText(QApplication::translate("AdjustPositionWidget", "6", Q_NULLPTR));
        num3Button->setText(QApplication::translate("AdjustPositionWidget", "3", Q_NULLPTR));
        num0Button->setText(QApplication::translate("AdjustPositionWidget", "0", Q_NULLPTR));
        num9Button->setText(QApplication::translate("AdjustPositionWidget", "9", Q_NULLPTR));
        enterButton->setText(QString());
        leftArrowButton->setText(QString());
        rightArrowButton->setText(QString());
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AdjustPositionWidget: public Ui_AdjustPositionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTPOSITIONWIDGET_H
