/********************************************************************************
** Form generated from reading UI file 'ScanCodeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANCODEDLG_H
#define UI_SCANCODEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_ScanCodeDlg
{
public:
    QGridLayout *gridLayout;
    TitleBarWidget *titleBar;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QLabel *label;

    void setupUi(QDialog *ScanCodeDlg)
    {
        if (ScanCodeDlg->objectName().isEmpty())
            ScanCodeDlg->setObjectName(QStringLiteral("ScanCodeDlg"));
        ScanCodeDlg->resize(370, 231);
        gridLayout = new QGridLayout(ScanCodeDlg);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        titleBar = new TitleBarWidget(ScanCodeDlg);
        titleBar->setObjectName(QStringLiteral("titleBar"));
        titleBar->setMinimumSize(QSize(370, 40));

        gridLayout->addWidget(titleBar, 0, 0, 1, 1);

        widget = new QWidget(ScanCodeDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(370, 191));
        widget->setStyleSheet(QStringLiteral("border-image: url(:/shareImages/dlg_background.png);"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(14);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(152, 38, 151, 52);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral("border-image: url(:/statementImage/scan_code.png);"));

        verticalLayout->addWidget(widget_2);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 16px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(ScanCodeDlg);

        QMetaObject::connectSlotsByName(ScanCodeDlg);
    } // setupUi

    void retranslateUi(QDialog *ScanCodeDlg)
    {
        ScanCodeDlg->setWindowTitle(QApplication::translate("ScanCodeDlg", "ScanCodeDlg", Q_NULLPTR));
        label->setText(QApplication::translate("ScanCodeDlg", "\350\257\267\346\211\253\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScanCodeDlg: public Ui_ScanCodeDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANCODEDLG_H
