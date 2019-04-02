/********************************************************************************
** Form generated from reading UI file 'BirthdayCalendarDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIRTHDAYCALENDARDLG_H
#define UI_BIRTHDAYCALENDARDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BirthdayCalendarDlg
{
public:
    QWidget *widget;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *yearEdit;
    QLineEdit *monthEdit;
    QLabel *label;
    QLineEdit *dayEdit;

    void setupUi(QWidget *BirthdayCalendarDlg)
    {
        if (BirthdayCalendarDlg->objectName().isEmpty())
            BirthdayCalendarDlg->setObjectName(QStringLiteral("BirthdayCalendarDlg"));
        BirthdayCalendarDlg->resize(404, 96);
        BirthdayCalendarDlg->setMinimumSize(QSize(404, 96));
        widget = new QWidget(BirthdayCalendarDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 404, 96));
        widget->setMinimumSize(QSize(404, 96));
        widget->setStyleSheet(QLatin1String("QWidget#widget {\n"
"	border-image: url(:/member/birthdayCalendar.png);\n"
"}"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 30, 20, 30));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 30, 20, 30));
        yearEdit = new QLineEdit(widget);
        yearEdit->setObjectName(QStringLiteral("yearEdit"));
        yearEdit->setGeometry(QRect(29, 30, 72, 30));
        monthEdit = new QLineEdit(widget);
        monthEdit->setObjectName(QStringLiteral("monthEdit"));
        monthEdit->setGeometry(QRect(150, 30, 72, 30));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(111, 30, 20, 30));
        dayEdit = new QLineEdit(widget);
        dayEdit->setObjectName(QStringLiteral("dayEdit"));
        dayEdit->setGeometry(QRect(270, 30, 72, 30));
        dayEdit->setMinimumSize(QSize(72, 30));

        retranslateUi(BirthdayCalendarDlg);

        QMetaObject::connectSlotsByName(BirthdayCalendarDlg);
    } // setupUi

    void retranslateUi(QWidget *BirthdayCalendarDlg)
    {
        BirthdayCalendarDlg->setWindowTitle(QApplication::translate("BirthdayCalendarDlg", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("BirthdayCalendarDlg", "\346\234\210", Q_NULLPTR));
        label_3->setText(QApplication::translate("BirthdayCalendarDlg", "\346\227\245", Q_NULLPTR));
        label->setText(QApplication::translate("BirthdayCalendarDlg", "\345\271\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BirthdayCalendarDlg: public Ui_BirthdayCalendarDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIRTHDAYCALENDARDLG_H
