/********************************************************************************
** Form generated from reading UI file 'AddOutStkDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOUTSTKDLG_H
#define UI_ADDOUTSTKDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitleBarWidget.h"
#include "WndDigitalKeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_AddOutStkDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWidget;
    QWidget *mainWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *saveTopWidget;
    QLabel *goodsNameLabel;
    QLabel *goodsCodeLabel;
    QLabel *goodsKindLabel;
    QLabel *goodsUnitLabel;
    QWidget *saveMainWidget;
    QVBoxLayout *verticalLayout_4;
    QFrame *mainFrame;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *priceLedit;
    QLineEdit *countLedit;
    QLineEdit *boxNumLedit;
    QLabel *subTotalLb;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer;
    WndDigitalKeyboard *keyboardWidget;

    void setupUi(QDialog *AddOutStkDlg)
    {
        if (AddOutStkDlg->objectName().isEmpty())
            AddOutStkDlg->setObjectName(QStringLiteral("AddOutStkDlg"));
        AddOutStkDlg->resize(660, 406);
        verticalLayout = new QVBoxLayout(AddOutStkDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(AddOutStkDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 40));
        titleWidget->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(titleWidget);

        mainWidget = new QWidget(AddOutStkDlg);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget{\n"
"        background-color:#505050;\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 2, 20, 2);
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
        saveTopWidget->setMinimumSize(QSize(0, 129));
        saveTopWidget->setMaximumSize(QSize(16777215, 64));
        saveTopWidget->setStyleSheet(QLatin1String("QWidget#saveTopWidget{\n"
"        background-color:#fafafa;\n"
"}"));
        goodsNameLabel = new QLabel(saveTopWidget);
        goodsNameLabel->setObjectName(QStringLiteral("goodsNameLabel"));
        goodsNameLabel->setGeometry(QRect(18, 5, 231, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        goodsNameLabel->setFont(font);
        goodsCodeLabel = new QLabel(saveTopWidget);
        goodsCodeLabel->setObjectName(QStringLiteral("goodsCodeLabel"));
        goodsCodeLabel->setGeometry(QRect(18, 28, 231, 16));
        goodsCodeLabel->setFont(font);
        goodsKindLabel = new QLabel(saveTopWidget);
        goodsKindLabel->setObjectName(QStringLiteral("goodsKindLabel"));
        goodsKindLabel->setGeometry(QRect(18, 51, 231, 16));
        goodsKindLabel->setFont(font);
        goodsUnitLabel = new QLabel(saveTopWidget);
        goodsUnitLabel->setObjectName(QStringLiteral("goodsUnitLabel"));
        goodsUnitLabel->setGeometry(QRect(18, 74, 231, 16));
        goodsUnitLabel->setFont(font);

        verticalLayout_2->addWidget(saveTopWidget);

        saveMainWidget = new QWidget(widget_2);
        saveMainWidget->setObjectName(QStringLiteral("saveMainWidget"));
        saveMainWidget->setStyleSheet(QLatin1String("QWidget#saveMainWidget{\n"
"        background-color:#ffffff;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(saveMainWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        mainFrame = new QFrame(saveMainWidget);
        mainFrame->setObjectName(QStringLiteral("mainFrame"));
        label_2 = new QLabel(mainFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 15, 111, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(mainFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 55, 61, 21));
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(mainFrame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 85, 61, 31));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(mainFrame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 130, 111, 31));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        priceLedit = new QLineEdit(mainFrame);
        priceLedit->setObjectName(QStringLiteral("priceLedit"));
        priceLedit->setGeometry(QRect(115, 10, 144, 31));
        priceLedit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        countLedit = new QLineEdit(mainFrame);
        countLedit->setObjectName(QStringLiteral("countLedit"));
        countLedit->setGeometry(QRect(115, 50, 144, 31));
        countLedit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        boxNumLedit = new QLineEdit(mainFrame);
        boxNumLedit->setObjectName(QStringLiteral("boxNumLedit"));
        boxNumLedit->setGeometry(QRect(115, 90, 144, 31));
        boxNumLedit->setStyleSheet(QLatin1String("font-size:14px;\n"
"color: rgb(102, 102, 102);\n"
"padding-left:10px;"));
        subTotalLb = new QLabel(mainFrame);
        subTotalLb->setObjectName(QStringLiteral("subTotalLb"));
        subTotalLb->setGeometry(QRect(115, 130, 144, 31));
        QPalette palette;
        QBrush brush(QColor(250, 250, 250, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        subTotalLb->setPalette(palette);
        subTotalLb->setStyleSheet(QLatin1String("font-size:14px;\n"
"background-color: rgb(250, 250, 250);\n"
"padding-left:10px;"));

        verticalLayout_4->addWidget(mainFrame);

        saveButton = new QPushButton(saveMainWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(0, 42));
        saveButton->setMaximumSize(QSize(16777215, 42));
        QFont font2;
        saveButton->setFont(font2);
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
        keyboardWidget->setMinimumSize(QSize(294, 294));
        keyboardWidget->setMaximumSize(QSize(294, 294));

        horizontalLayout->addWidget(keyboardWidget);


        verticalLayout->addWidget(mainWidget);


        retranslateUi(AddOutStkDlg);

        QMetaObject::connectSlotsByName(AddOutStkDlg);
    } // setupUi

    void retranslateUi(QDialog *AddOutStkDlg)
    {
        AddOutStkDlg->setWindowTitle(QApplication::translate("AddOutStkDlg", "Dialog", Q_NULLPTR));
        goodsNameLabel->setText(QApplication::translate("AddOutStkDlg", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        goodsCodeLabel->setText(QApplication::translate("AddOutStkDlg", "\345\225\206\345\223\201\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        goodsKindLabel->setText(QApplication::translate("AddOutStkDlg", "      \345\244\247\347\261\273\357\274\232", Q_NULLPTR));
        goodsUnitLabel->setText(QApplication::translate("AddOutStkDlg", "\350\247\204\346\240\274\345\215\225\344\275\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddOutStkDlg", "\345\207\272\345\272\223\345\217\202\350\200\203\345\215\225\344\273\267\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("AddOutStkDlg", "\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddOutStkDlg", "\344\273\266\351\207\217\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddOutStkDlg", "\345\217\202\350\200\203\345\260\217\350\256\241\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        priceLedit->setText(QApplication::translate("AddOutStkDlg", "0.00", Q_NULLPTR));
        countLedit->setText(QApplication::translate("AddOutStkDlg", "0.00", Q_NULLPTR));
        boxNumLedit->setText(QApplication::translate("AddOutStkDlg", "0.00", Q_NULLPTR));
        subTotalLb->setText(QString());
        saveButton->setText(QApplication::translate("AddOutStkDlg", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddOutStkDlg: public Ui_AddOutStkDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOUTSTKDLG_H
