/********************************************************************************
** Form generated from reading UI file 'ResetKeyWgt.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETKEYWGT_H
#define UI_RESETKEYWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitleWithReturnWidget.h"
#include "WndDigitalKeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_ResetKeyWgt
{
public:
    QVBoxLayout *verticalLayout_4;
    TitleWithReturnWidget *titleWgt;
    QWidget *homeWgt;
    WndDigitalKeyboard *keyboardWgt;
    QWidget *resetKeyInfoWgt;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *oldKeyLbl;
    QLineEdit *oldKey;
    QHBoxLayout *horizontalLayout_3;
    QLabel *newKeyLbl;
    QLineEdit *newKey;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *newKeyRepeat;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QLabel *tipLabel;
    QPushButton *confirmBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ResetKeyWgt)
    {
        if (ResetKeyWgt->objectName().isEmpty())
            ResetKeyWgt->setObjectName(QStringLiteral("ResetKeyWgt"));
        ResetKeyWgt->resize(800, 600);
        verticalLayout_4 = new QVBoxLayout(ResetKeyWgt);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        titleWgt = new TitleWithReturnWidget(ResetKeyWgt);
        titleWgt->setObjectName(QStringLiteral("titleWgt"));
        titleWgt->setMinimumSize(QSize(0, 52));
        titleWgt->setMaximumSize(QSize(16777215, 52));

        verticalLayout_4->addWidget(titleWgt);

        homeWgt = new QWidget(ResetKeyWgt);
        homeWgt->setObjectName(QStringLiteral("homeWgt"));
        homeWgt->setMaximumSize(QSize(16777215, 16777215));
        homeWgt->setStyleSheet(QStringLiteral("background-color: rgb(81, 80, 80);"));
        keyboardWgt = new WndDigitalKeyboard(homeWgt);
        keyboardWgt->setObjectName(QStringLiteral("keyboardWgt"));
        keyboardWgt->setGeometry(QRect(420, 135, 302, 301));
        keyboardWgt->setMinimumSize(QSize(302, 301));
        resetKeyInfoWgt = new QWidget(homeWgt);
        resetKeyInfoWgt->setObjectName(QStringLiteral("resetKeyInfoWgt"));
        resetKeyInfoWgt->setGeometry(QRect(100, 135, 303, 301));
        resetKeyInfoWgt->setMinimumSize(QSize(296, 301));
        resetKeyInfoWgt->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font-size:12px;"));
        verticalLayout_3 = new QVBoxLayout(resetKeyInfoWgt);
        verticalLayout_3->setSpacing(18);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(18, 0, 18, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 50, -1, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        oldKeyLbl = new QLabel(resetKeyInfoWgt);
        oldKeyLbl->setObjectName(QStringLiteral("oldKeyLbl"));
        oldKeyLbl->setMinimumSize(QSize(77, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        oldKeyLbl->setFont(font);
        oldKeyLbl->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"\n"
""));
        oldKeyLbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(oldKeyLbl);

        oldKey = new QLineEdit(resetKeyInfoWgt);
        oldKey->setObjectName(QStringLiteral("oldKey"));
        oldKey->setMinimumSize(QSize(100, 30));
        oldKey->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        oldKey->setFont(font1);
        oldKey->setStyleSheet(QLatin1String("border-image: url(:/shareImages/editRect.png);\n"
"padding-left:10px;"));

        horizontalLayout->addWidget(oldKey);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        newKeyLbl = new QLabel(resetKeyInfoWgt);
        newKeyLbl->setObjectName(QStringLiteral("newKeyLbl"));
        newKeyLbl->setMinimumSize(QSize(77, 0));
        newKeyLbl->setFont(font);
        newKeyLbl->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color: rgb(51, 51, 51);\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        newKeyLbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(newKeyLbl);

        newKey = new QLineEdit(resetKeyInfoWgt);
        newKey->setObjectName(QStringLiteral("newKey"));
        newKey->setMinimumSize(QSize(100, 30));
        newKey->setFont(font1);
        newKey->setStyleSheet(QLatin1String("border-image: url(:/shareImages/editRect.png);\n"
"padding-left:10px;"));

        horizontalLayout_3->addWidget(newKey);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(resetKeyInfoWgt);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(77, 0));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color: rgb(51, 51, 51);\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        newKeyRepeat = new QLineEdit(resetKeyInfoWgt);
        newKeyRepeat->setObjectName(QStringLiteral("newKeyRepeat"));
        newKeyRepeat->setMinimumSize(QSize(100, 30));
        newKeyRepeat->setFont(font1);
        newKeyRepeat->setStyleSheet(QLatin1String("border-image: url(:/shareImages/editRect.png);\n"
"padding-left:10px;"));

        horizontalLayout_2->addWidget(newKeyRepeat);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(85, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        tipLabel = new QLabel(resetKeyInfoWgt);
        tipLabel->setObjectName(QStringLiteral("tipLabel"));
        tipLabel->setMinimumSize(QSize(90, 0));
        tipLabel->setStyleSheet(QString::fromUtf8("color:#fa7a7a;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_4->addWidget(tipLabel);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        confirmBtn = new QPushButton(resetKeyInfoWgt);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));
        confirmBtn->setMinimumSize(QSize(260, 45));
        confirmBtn->setFont(font);
        confirmBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#ffffff;\n"
"font-size:16px;\n"
"border-image: url(:/loginImage/commonButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/loginImage/commonButtonPressed.png);\n"
"}"));

        verticalLayout_3->addWidget(confirmBtn);

        verticalSpacer = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addWidget(homeWgt);

        verticalLayout_4->setStretch(0, 52);
        verticalLayout_4->setStretch(1, 548);

        retranslateUi(ResetKeyWgt);

        QMetaObject::connectSlotsByName(ResetKeyWgt);
    } // setupUi

    void retranslateUi(QWidget *ResetKeyWgt)
    {
        ResetKeyWgt->setWindowTitle(QApplication::translate("ResetKeyWgt", "Widget", Q_NULLPTR));
        oldKeyLbl->setText(QApplication::translate("ResetKeyWgt", "\345\216\237\345\257\206\347\240\201:", Q_NULLPTR));
        newKeyLbl->setText(QApplication::translate("ResetKeyWgt", "\346\226\260\345\257\206\347\240\201:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ResetKeyWgt", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201:", Q_NULLPTR));
        tipLabel->setText(QString());
        confirmBtn->setText(QApplication::translate("ResetKeyWgt", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ResetKeyWgt: public Ui_ResetKeyWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETKEYWGT_H
