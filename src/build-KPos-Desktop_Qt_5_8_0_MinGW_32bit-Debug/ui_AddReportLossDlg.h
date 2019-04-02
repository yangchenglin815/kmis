/********************************************************************************
** Form generated from reading UI file 'AddReportLossDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDREPORTLOSSDLG_H
#define UI_ADDREPORTLOSSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitleBarWidget.h"
#include "WndDigitalKeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_AddReportLossDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *saveTopWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *goodsNameLabel;
    QLabel *goodsCodeLabel;
    QWidget *saveMainWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lossNoLabel;
    QLineEdit *lossNoLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lollReasonLabel;
    QRadioButton *outofdateBtn;
    QRadioButton *badBtn;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *lossBtn;
    QRadioButton *anotherBtn;
    QLabel *hintLabel;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer;
    WndDigitalKeyboard *keyboardWidget;

    void setupUi(QDialog *AddReportLossDlg)
    {
        if (AddReportLossDlg->objectName().isEmpty())
            AddReportLossDlg->setObjectName(QStringLiteral("AddReportLossDlg"));
        AddReportLossDlg->resize(660, 377);
        verticalLayout = new QVBoxLayout(AddReportLossDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(AddReportLossDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 46));
        titleWidget->setMaximumSize(QSize(16777215, 46));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(AddReportLossDlg);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"	background-color:#505050;\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 12, 20, 24);
        widget_2 = new QWidget(mainWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(284, 0));
        widget_2->setMaximumSize(QSize(284, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        saveTopWidget = new QWidget(widget_2);
        saveTopWidget->setObjectName(QStringLiteral("saveTopWidget"));
        saveTopWidget->setMinimumSize(QSize(0, 64));
        saveTopWidget->setMaximumSize(QSize(16777215, 64));
        saveTopWidget->setStyleSheet(QLatin1String("QWidget#saveTopWidget{\n"
"	background-color:#fafafa;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(saveTopWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(18, 15, 0, 15);
        goodsNameLabel = new QLabel(saveTopWidget);
        goodsNameLabel->setObjectName(QStringLiteral("goodsNameLabel"));

        verticalLayout_3->addWidget(goodsNameLabel);

        goodsCodeLabel = new QLabel(saveTopWidget);
        goodsCodeLabel->setObjectName(QStringLiteral("goodsCodeLabel"));

        verticalLayout_3->addWidget(goodsCodeLabel);


        verticalLayout_2->addWidget(saveTopWidget);

        saveMainWidget = new QWidget(widget_2);
        saveMainWidget->setObjectName(QStringLiteral("saveMainWidget"));
        saveMainWidget->setStyleSheet(QLatin1String("QWidget#saveMainWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(saveMainWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, -1, 10, -1);
        lossNoLabel = new QLabel(saveMainWidget);
        lossNoLabel->setObjectName(QStringLiteral("lossNoLabel"));
        lossNoLabel->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(lossNoLabel);

        lossNoLineEdit = new QLineEdit(saveMainWidget);
        lossNoLineEdit->setObjectName(QStringLiteral("lossNoLineEdit"));
        lossNoLineEdit->setMinimumSize(QSize(0, 31));
        lossNoLineEdit->setMaximumSize(QSize(16777215, 16777215));
        lossNoLineEdit->setStyleSheet(QLatin1String("border-image: url(:/shareImages/editRect.png);\n"
"padding-left:10px;"));

        horizontalLayout_2->addWidget(lossNoLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, -1, 10, -1);
        lollReasonLabel = new QLabel(saveMainWidget);
        lollReasonLabel->setObjectName(QStringLiteral("lollReasonLabel"));
        lollReasonLabel->setMaximumSize(QSize(54, 16777215));

        horizontalLayout_3->addWidget(lollReasonLabel);

        outofdateBtn = new QRadioButton(saveMainWidget);
        outofdateBtn->setObjectName(QStringLiteral("outofdateBtn"));
        outofdateBtn->setMinimumSize(QSize(0, 35));
        outofdateBtn->setStyleSheet(QLatin1String("QRadioButton:indicator{\n"
"   width:22px;\n"
"   height:0px;\n"
"\n"
"}\n"
"QRadioButton{\n"
"border:1px groove \"#666666\";\n"
"border-radius:6px;\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QRadioButton:checked{\n"
"border:2px groove \"#EA8852\";\n"
"border-radius:6px;\n"
"padding:2px 4px;\n"
"}"));

        horizontalLayout_3->addWidget(outofdateBtn);

        badBtn = new QRadioButton(saveMainWidget);
        badBtn->setObjectName(QStringLiteral("badBtn"));
        badBtn->setMinimumSize(QSize(0, 35));
        badBtn->setStyleSheet(QLatin1String("QRadioButton:indicator{\n"
"   width:22px;\n"
"   height:0px;\n"
"\n"
"}\n"
"QRadioButton{\n"
"border:1px groove \"#666666\";\n"
"border-radius:6px;\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QRadioButton:checked{\n"
"border:2px groove \"#EA8852\";\n"
"border-radius:6px;\n"
"padding:2px 4px;\n"
"}"));

        horizontalLayout_3->addWidget(badBtn);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, -1, 10, -1);
        horizontalSpacer_2 = new QSpacerItem(54, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        lossBtn = new QRadioButton(saveMainWidget);
        lossBtn->setObjectName(QStringLiteral("lossBtn"));
        lossBtn->setMinimumSize(QSize(90, 35));
        lossBtn->setStyleSheet(QLatin1String("QRadioButton:indicator{\n"
"   width:22px;\n"
"   height:0px;\n"
"\n"
"}\n"
"QRadioButton{\n"
"border:1px groove \"#666666\";\n"
"border-radius:6px;\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QRadioButton:checked{\n"
"border:2px groove \"#EA8852\";\n"
"border-radius:6px;\n"
"padding:2px 4px;\n"
"}"));

        horizontalLayout_4->addWidget(lossBtn);

        anotherBtn = new QRadioButton(saveMainWidget);
        anotherBtn->setObjectName(QStringLiteral("anotherBtn"));
        anotherBtn->setMinimumSize(QSize(90, 35));
        anotherBtn->setStyleSheet(QLatin1String("QRadioButton:indicator{\n"
"   width:22px;\n"
"   height:0px;\n"
"\n"
"}\n"
"QRadioButton{\n"
"border:1px groove \"#666666\";\n"
"border-radius:6px;\n"
"padding:2px 4px;\n"
"}\n"
"\n"
"QRadioButton:checked{\n"
"border:2px groove \"#EA8852\";\n"
"border-radius:6px;\n"
"padding:2px 4px;\n"
"}"));

        horizontalLayout_4->addWidget(anotherBtn);


        verticalLayout_4->addLayout(horizontalLayout_4);

        hintLabel = new QLabel(saveMainWidget);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setMinimumSize(QSize(0, 18));
        hintLabel->setMaximumSize(QSize(16777215, 18));
        hintLabel->setStyleSheet(QStringLiteral("color:red;"));

        verticalLayout_4->addWidget(hintLabel);

        saveButton = new QPushButton(saveMainWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(0, 42));
        saveButton->setMaximumSize(QSize(16777215, 42));
        saveButton->setStyleSheet(QLatin1String("QPushButton{\n"
"color:#ffffff;\n"
"font-size:16px;\n"
"border-image: url(:/loginImage/commonButton.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/loginImage/commonButtonPressed.png);\n"
"}"));

        verticalLayout_4->addWidget(saveButton);


        verticalLayout_2->addWidget(saveMainWidget);


        horizontalLayout->addWidget(widget_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        keyboardWidget = new WndDigitalKeyboard(mainWidget);
        keyboardWidget->setObjectName(QStringLiteral("keyboardWidget"));
        keyboardWidget->setMinimumSize(QSize(304, 0));
        keyboardWidget->setMaximumSize(QSize(304, 16777215));

        horizontalLayout->addWidget(keyboardWidget);


        verticalLayout->addWidget(mainWidget);


        retranslateUi(AddReportLossDlg);

        QMetaObject::connectSlotsByName(AddReportLossDlg);
    } // setupUi

    void retranslateUi(QDialog *AddReportLossDlg)
    {
        AddReportLossDlg->setWindowTitle(QApplication::translate("AddReportLossDlg", "Dialog", Q_NULLPTR));
        goodsNameLabel->setText(QApplication::translate("AddReportLossDlg", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        goodsCodeLabel->setText(QApplication::translate("AddReportLossDlg", "\345\225\206\345\223\201\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        lossNoLabel->setText(QApplication::translate("AddReportLossDlg", "\346\212\245\346\215\237\346\225\260\351\207\217:", Q_NULLPTR));
        lollReasonLabel->setText(QApplication::translate("AddReportLossDlg", "\346\212\245\346\215\237\345\216\237\345\233\240:", Q_NULLPTR));
        outofdateBtn->setText(QApplication::translate("AddReportLossDlg", "\350\277\207\346\234\237", Q_NULLPTR));
        badBtn->setText(QApplication::translate("AddReportLossDlg", "\346\215\237\345\235\217", Q_NULLPTR));
        lossBtn->setText(QApplication::translate("AddReportLossDlg", "\344\270\242\345\244\261", Q_NULLPTR));
        anotherBtn->setText(QApplication::translate("AddReportLossDlg", "\345\205\266\344\273\226", Q_NULLPTR));
        hintLabel->setText(QString());
        saveButton->setText(QApplication::translate("AddReportLossDlg", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddReportLossDlg: public Ui_AddReportLossDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDREPORTLOSSDLG_H
