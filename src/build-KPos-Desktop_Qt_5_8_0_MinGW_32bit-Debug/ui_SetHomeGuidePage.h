/********************************************************************************
** Form generated from reading UI file 'SetHomeGuidePage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETHOMEGUIDEPAGE_H
#define UI_SETHOMEGUIDEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetHomeGuidePage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;

    void setupUi(QWidget *SetHomeGuidePage)
    {
        if (SetHomeGuidePage->objectName().isEmpty())
            SetHomeGuidePage->setObjectName(QStringLiteral("SetHomeGuidePage"));
        SetHomeGuidePage->resize(800, 600);
        SetHomeGuidePage->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(SetHomeGuidePage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SetHomeGuidePage);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout->addWidget(widget);


        retranslateUi(SetHomeGuidePage);

        QMetaObject::connectSlotsByName(SetHomeGuidePage);
    } // setupUi

    void retranslateUi(QWidget *SetHomeGuidePage)
    {
        SetHomeGuidePage->setWindowTitle(QApplication::translate("SetHomeGuidePage", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetHomeGuidePage: public Ui_SetHomeGuidePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETHOMEGUIDEPAGE_H
