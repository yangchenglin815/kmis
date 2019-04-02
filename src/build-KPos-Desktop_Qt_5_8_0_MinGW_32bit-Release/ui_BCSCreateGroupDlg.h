/********************************************************************************
** Form generated from reading UI file 'BCSCreateGroupDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCSCREATEGROUPDLG_H
#define UI_BCSCREATEGROUPDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_BCSCreateGroupDlg
{
public:

    void setupUi(QDialog *BCSCreateGroupDlg)
    {
        if (BCSCreateGroupDlg->objectName().isEmpty())
            BCSCreateGroupDlg->setObjectName(QStringLiteral("BCSCreateGroupDlg"));
        BCSCreateGroupDlg->resize(400, 300);

        retranslateUi(BCSCreateGroupDlg);

        QMetaObject::connectSlotsByName(BCSCreateGroupDlg);
    } // setupUi

    void retranslateUi(QDialog *BCSCreateGroupDlg)
    {
        BCSCreateGroupDlg->setWindowTitle(QApplication::translate("BCSCreateGroupDlg", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BCSCreateGroupDlg: public Ui_BCSCreateGroupDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCSCREATEGROUPDLG_H
