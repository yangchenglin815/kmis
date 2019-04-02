/********************************************************************************
** Form generated from reading UI file 'GridWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRIDWIDGET_H
#define UI_GRIDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GridWidget
{
public:

    void setupUi(QWidget *GridWidget)
    {
        if (GridWidget->objectName().isEmpty())
            GridWidget->setObjectName(QStringLiteral("GridWidget"));
        GridWidget->resize(400, 300);

        retranslateUi(GridWidget);

        QMetaObject::connectSlotsByName(GridWidget);
    } // setupUi

    void retranslateUi(QWidget *GridWidget)
    {
        GridWidget->setWindowTitle(QApplication::translate("GridWidget", "GridWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GridWidget: public Ui_GridWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRIDWIDGET_H
