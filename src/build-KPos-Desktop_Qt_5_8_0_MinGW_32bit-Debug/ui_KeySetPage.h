/********************************************************************************
** Form generated from reading UI file 'KeySetPage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYSETPAGE_H
#define UI_KEYSETPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "PressKeyWidget.h"

QT_BEGIN_NAMESPACE

class Ui_KeySetPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *skinWidget;
    QLabel *homeKeyLabel;
    QPushButton *refundKeySortButton;
    QPushButton *homeOtherButton;
    QPushButton *homeKeySortButton;
    QPushButton *pushButton;
    QLabel *refundKeyLabel;
    PressKeyWidget *homeKey1Widget;
    PressKeyWidget *homeKey2Widget;
    PressKeyWidget *homeKey3Widget;
    PressKeyWidget *homeKey4Widget;
    PressKeyWidget *homeKey5Widget;
    PressKeyWidget *homeKey6Widget;
    PressKeyWidget *homeKey7Widget;
    PressKeyWidget *homeKey8Widget;
    PressKeyWidget *homeKey9Widget;
    PressKeyWidget *homeKey10Widget;
    PressKeyWidget *homeKey11Widget;
    PressKeyWidget *homeKey12Widget;
    PressKeyWidget *refundKey1Widget;
    PressKeyWidget *refundKey2Widget;
    PressKeyWidget *refundKey3Widget;
    PressKeyWidget *homeKey13Widget;
    QPushButton *pushButton_2;

    void setupUi(QWidget *KeySetPage)
    {
        if (KeySetPage->objectName().isEmpty())
            KeySetPage->setObjectName(QStringLiteral("KeySetPage"));
        KeySetPage->resize(607, 513);
        verticalLayout = new QVBoxLayout(KeySetPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        skinWidget = new QWidget(KeySetPage);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        homeKeyLabel = new QLabel(skinWidget);
        homeKeyLabel->setObjectName(QStringLiteral("homeKeyLabel"));
        homeKeyLabel->setGeometry(QRect(0, 13, 77, 52));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        homeKeyLabel->setFont(font);
        homeKeyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        refundKeySortButton = new QPushButton(skinWidget);
        refundKeySortButton->setObjectName(QStringLiteral("refundKeySortButton"));
        refundKeySortButton->setGeometry(QRect(467, 329, 128, 30));
        refundKeySortButton->setFont(font);
        refundKeySortButton->setStyleSheet(QLatin1String("QPushButton#refundKeySortButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/setImage/sort_normal.png);\n"
"}\n"
"\n"
"QPushButton#refundKeySortButton:pressed {\n"
"	border-image: url(:/setImage/sort_press.png);\n"
"}"));
        homeOtherButton = new QPushButton(skinWidget);
        homeOtherButton->setObjectName(QStringLiteral("homeOtherButton"));
        homeOtherButton->setGeometry(QRect(77, 13, 86, 52));
        homeOtherButton->setFont(font);
        homeOtherButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border-image: url(:/setImage/key_btn_disable.png);"));
        homeKeySortButton = new QPushButton(skinWidget);
        homeKeySortButton->setObjectName(QStringLiteral("homeKeySortButton"));
        homeKeySortButton->setGeometry(QRect(467, 201, 128, 30));
        homeKeySortButton->setFont(font);
        homeKeySortButton->setStyleSheet(QLatin1String("QPushButton#homeKeySortButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/setImage/sort_normal.png);\n"
"}\n"
"\n"
"QPushButton#homeKeySortButton:pressed {\n"
"	border-image: url(:/setImage/sort_press.png);\n"
"}"));
        pushButton = new QPushButton(skinWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(77, 242, 86, 52));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/setImage/key_btn_disable.png);\n"
"color: rgb(255, 255, 255);"));
        refundKeyLabel = new QLabel(skinWidget);
        refundKeyLabel->setObjectName(QStringLiteral("refundKeyLabel"));
        refundKeyLabel->setGeometry(QRect(0, 242, 77, 52));
        refundKeyLabel->setFont(font);
        refundKeyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        homeKey1Widget = new PressKeyWidget(skinWidget);
        homeKey1Widget->setObjectName(QStringLiteral("homeKey1Widget"));
        homeKey1Widget->setGeometry(QRect(185, 13, 86, 52));
        homeKey2Widget = new PressKeyWidget(skinWidget);
        homeKey2Widget->setObjectName(QStringLiteral("homeKey2Widget"));
        homeKey2Widget->setGeometry(QRect(293, 13, 86, 52));
        homeKey3Widget = new PressKeyWidget(skinWidget);
        homeKey3Widget->setObjectName(QStringLiteral("homeKey3Widget"));
        homeKey3Widget->setGeometry(QRect(401, 13, 86, 52));
        homeKey4Widget = new PressKeyWidget(skinWidget);
        homeKey4Widget->setObjectName(QStringLiteral("homeKey4Widget"));
        homeKey4Widget->setGeometry(QRect(509, 13, 86, 52));
        homeKey5Widget = new PressKeyWidget(skinWidget);
        homeKey5Widget->setObjectName(QStringLiteral("homeKey5Widget"));
        homeKey5Widget->setGeometry(QRect(77, 78, 86, 52));
        homeKey6Widget = new PressKeyWidget(skinWidget);
        homeKey6Widget->setObjectName(QStringLiteral("homeKey6Widget"));
        homeKey6Widget->setGeometry(QRect(185, 78, 86, 52));
        homeKey7Widget = new PressKeyWidget(skinWidget);
        homeKey7Widget->setObjectName(QStringLiteral("homeKey7Widget"));
        homeKey7Widget->setGeometry(QRect(293, 78, 86, 52));
        homeKey8Widget = new PressKeyWidget(skinWidget);
        homeKey8Widget->setObjectName(QStringLiteral("homeKey8Widget"));
        homeKey8Widget->setGeometry(QRect(401, 78, 86, 52));
        homeKey9Widget = new PressKeyWidget(skinWidget);
        homeKey9Widget->setObjectName(QStringLiteral("homeKey9Widget"));
        homeKey9Widget->setGeometry(QRect(509, 78, 86, 52));
        homeKey10Widget = new PressKeyWidget(skinWidget);
        homeKey10Widget->setObjectName(QStringLiteral("homeKey10Widget"));
        homeKey10Widget->setGeometry(QRect(77, 143, 86, 52));
        homeKey11Widget = new PressKeyWidget(skinWidget);
        homeKey11Widget->setObjectName(QStringLiteral("homeKey11Widget"));
        homeKey11Widget->setGeometry(QRect(185, 143, 86, 52));
        homeKey12Widget = new PressKeyWidget(skinWidget);
        homeKey12Widget->setObjectName(QStringLiteral("homeKey12Widget"));
        homeKey12Widget->setGeometry(QRect(293, 143, 86, 52));
        refundKey1Widget = new PressKeyWidget(skinWidget);
        refundKey1Widget->setObjectName(QStringLiteral("refundKey1Widget"));
        refundKey1Widget->setGeometry(QRect(293, 242, 86, 52));
        refundKey2Widget = new PressKeyWidget(skinWidget);
        refundKey2Widget->setObjectName(QStringLiteral("refundKey2Widget"));
        refundKey2Widget->setGeometry(QRect(401, 242, 86, 52));
        refundKey3Widget = new PressKeyWidget(skinWidget);
        refundKey3Widget->setObjectName(QStringLiteral("refundKey3Widget"));
        refundKey3Widget->setGeometry(QRect(509, 242, 86, 52));
        homeKey13Widget = new PressKeyWidget(skinWidget);
        homeKey13Widget->setObjectName(QStringLiteral("homeKey13Widget"));
        homeKey13Widget->setGeometry(QRect(400, 143, 86, 52));
        pushButton_2 = new QPushButton(skinWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(185, 242, 86, 52));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QLatin1String("border-image: url(:/setImage/key_btn_disable.png);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(skinWidget);


        retranslateUi(KeySetPage);

        QMetaObject::connectSlotsByName(KeySetPage);
    } // setupUi

    void retranslateUi(QWidget *KeySetPage)
    {
        KeySetPage->setWindowTitle(QApplication::translate("KeySetPage", "Form", Q_NULLPTR));
        homeKeyLabel->setText(QApplication::translate("KeySetPage", "\351\246\226\351\241\265\346\214\211\351\224\256\357\274\232", Q_NULLPTR));
        refundKeySortButton->setText(QApplication::translate("KeySetPage", "\351\200\200\346\254\276\346\214\211\351\224\256\344\275\215\347\275\256\346\216\222\345\272\217", Q_NULLPTR));
        homeOtherButton->setText(QApplication::translate("KeySetPage", "1 \345\205\266\344\273\226", Q_NULLPTR));
        homeKeySortButton->setText(QApplication::translate("KeySetPage", "\351\246\226\351\241\265\346\214\211\351\224\256\344\275\215\347\275\256\346\216\222\345\272\217", Q_NULLPTR));
        pushButton->setText(QString());
        refundKeyLabel->setText(QApplication::translate("KeySetPage", "\351\200\200\346\254\276\346\214\211\351\224\256\357\274\232", Q_NULLPTR));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KeySetPage: public Ui_KeySetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYSETPAGE_H
