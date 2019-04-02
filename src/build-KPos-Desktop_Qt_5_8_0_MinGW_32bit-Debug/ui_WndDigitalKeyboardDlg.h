/********************************************************************************
** Form generated from reading UI file 'WndDigitalKeyboardDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WNDDIGITALKEYBOARDDLG_H
#define UI_WNDDIGITALKEYBOARDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>
#include <WndDigitalKeyboard.h>

QT_BEGIN_NAMESPACE

class Ui_WndDigitalKeyboardDlg
{
public:
    QVBoxLayout *verticalLayout;
    TitleBarWidget *titleWnd;
    QWidget *skinWidget;
    QHBoxLayout *horizontalLayout;
    WndDigitalKeyboard *keyboardWidget;

    void setupUi(QDialog *WndDigitalKeyboardDlg)
    {
        if (WndDigitalKeyboardDlg->objectName().isEmpty())
            WndDigitalKeyboardDlg->setObjectName(QStringLiteral("WndDigitalKeyboardDlg"));
        WndDigitalKeyboardDlg->resize(248, 288);
        verticalLayout = new QVBoxLayout(WndDigitalKeyboardDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWnd = new TitleBarWidget(WndDigitalKeyboardDlg);
        titleWnd->setObjectName(QStringLiteral("titleWnd"));
        titleWnd->setMinimumSize(QSize(0, 40));
        titleWnd->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(titleWnd);

        skinWidget = new QWidget(WndDigitalKeyboardDlg);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        horizontalLayout = new QHBoxLayout(skinWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        keyboardWidget = new WndDigitalKeyboard(skinWidget);
        keyboardWidget->setObjectName(QStringLiteral("keyboardWidget"));

        horizontalLayout->addWidget(keyboardWidget);


        verticalLayout->addWidget(skinWidget);


        retranslateUi(WndDigitalKeyboardDlg);

        QMetaObject::connectSlotsByName(WndDigitalKeyboardDlg);
    } // setupUi

    void retranslateUi(QDialog *WndDigitalKeyboardDlg)
    {
        WndDigitalKeyboardDlg->setWindowTitle(QApplication::translate("WndDigitalKeyboardDlg", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WndDigitalKeyboardDlg: public Ui_WndDigitalKeyboardDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WNDDIGITALKEYBOARDDLG_H
