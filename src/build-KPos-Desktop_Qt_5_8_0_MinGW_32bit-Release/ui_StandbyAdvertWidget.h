/********************************************************************************
** Form generated from reading UI file 'StandbyAdvertWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STANDBYADVERTWIDGET_H
#define UI_STANDBYADVERTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StandbyAdvertWidget
{
public:

    void setupUi(QWidget *StandbyAdvertWidget)
    {
        if (StandbyAdvertWidget->objectName().isEmpty())
            StandbyAdvertWidget->setObjectName(QStringLiteral("StandbyAdvertWidget"));
        StandbyAdvertWidget->resize(416, 325);

        retranslateUi(StandbyAdvertWidget);

        QMetaObject::connectSlotsByName(StandbyAdvertWidget);
    } // setupUi

    void retranslateUi(QWidget *StandbyAdvertWidget)
    {
        StandbyAdvertWidget->setWindowTitle(QApplication::translate("StandbyAdvertWidget", "StandbyAdvertWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StandbyAdvertWidget: public Ui_StandbyAdvertWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STANDBYADVERTWIDGET_H
