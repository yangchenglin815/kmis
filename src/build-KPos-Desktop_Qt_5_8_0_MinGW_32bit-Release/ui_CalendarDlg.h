/********************************************************************************
** Form generated from reading UI file 'CalendarDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARDLG_H
#define UI_CALENDARDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalendarDlg
{
public:
    QComboBox *yearsBox;
    QComboBox *monthBox;
    QComboBox *dayBox;
    QLabel *yearLabel;
    QLabel *monthLabel;
    QLabel *dayLabel;
    QWidget *widget;
    QPushButton *dayButton_01;
    QPushButton *dayButton_02;
    QPushButton *dayButton_03;
    QPushButton *dayButton_04;
    QPushButton *dayButton_05;
    QPushButton *dayButton_06;
    QPushButton *dayButton_07;
    QPushButton *dayButton_08;
    QPushButton *dayButton_09;
    QPushButton *dayButton_10;
    QPushButton *dayButton_11;
    QPushButton *dayButton_12;
    QPushButton *dayButton_13;
    QPushButton *dayButton_14;
    QPushButton *dayButton_15;
    QPushButton *dayButton_16;
    QPushButton *dayButton_17;
    QPushButton *dayButton_18;
    QPushButton *dayButton_19;
    QPushButton *dayButton_20;
    QPushButton *dayButton_21;
    QPushButton *dayButton_22;
    QPushButton *dayButton_23;
    QPushButton *dayButton_24;
    QPushButton *dayButton_25;
    QPushButton *dayButton_26;
    QPushButton *dayButton_27;
    QPushButton *dayButton_28;
    QPushButton *dayButton_29;
    QPushButton *dayButton_30;
    QPushButton *dayButton_31;

    void setupUi(QDialog *CalendarDlg)
    {
        if (CalendarDlg->objectName().isEmpty())
            CalendarDlg->setObjectName(QStringLiteral("CalendarDlg"));
        CalendarDlg->resize(505, 350);
        CalendarDlg->setStyleSheet(QLatin1String("QDialog#CalendarDlg {\n"
"	border-image: url(:/shareImages/calendar.png);\n"
"}"));
        yearsBox = new QComboBox(CalendarDlg);
        yearsBox->setObjectName(QStringLiteral("yearsBox"));
        yearsBox->setGeometry(QRect(40, 44, 95, 35));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        yearsBox->setFont(font);
        monthBox = new QComboBox(CalendarDlg);
        monthBox->setObjectName(QStringLiteral("monthBox"));
        monthBox->setGeometry(QRect(180, 44, 95, 35));
        monthBox->setFont(font);
        dayBox = new QComboBox(CalendarDlg);
        dayBox->setObjectName(QStringLiteral("dayBox"));
        dayBox->setGeometry(QRect(320, 44, 95, 35));
        dayBox->setFont(font);
        yearLabel = new QLabel(CalendarDlg);
        yearLabel->setObjectName(QStringLiteral("yearLabel"));
        yearLabel->setGeometry(QRect(138, 46, 40, 35));
        yearLabel->setFont(font);
        monthLabel = new QLabel(CalendarDlg);
        monthLabel->setObjectName(QStringLiteral("monthLabel"));
        monthLabel->setGeometry(QRect(280, 44, 40, 35));
        monthLabel->setFont(font);
        dayLabel = new QLabel(CalendarDlg);
        dayLabel->setObjectName(QStringLiteral("dayLabel"));
        dayLabel->setGeometry(QRect(418, 44, 40, 35));
        dayLabel->setFont(font);
        widget = new QWidget(CalendarDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 80, 481, 261));
        widget->setStyleSheet(QStringLiteral(""));
        dayButton_01 = new QPushButton(widget);
        dayButton_01->setObjectName(QStringLiteral("dayButton_01"));
        dayButton_01->setGeometry(QRect(40, 10, 40, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        dayButton_01->setFont(font1);
        dayButton_01->setFlat(true);
        dayButton_02 = new QPushButton(widget);
        dayButton_02->setObjectName(QStringLiteral("dayButton_02"));
        dayButton_02->setGeometry(QRect(100, 10, 40, 40));
        dayButton_02->setFont(font1);
        dayButton_02->setFlat(true);
        dayButton_03 = new QPushButton(widget);
        dayButton_03->setObjectName(QStringLiteral("dayButton_03"));
        dayButton_03->setGeometry(QRect(160, 10, 40, 40));
        dayButton_03->setFont(font1);
        dayButton_03->setFlat(true);
        dayButton_04 = new QPushButton(widget);
        dayButton_04->setObjectName(QStringLiteral("dayButton_04"));
        dayButton_04->setGeometry(QRect(220, 10, 40, 40));
        dayButton_04->setFont(font1);
        dayButton_04->setFlat(true);
        dayButton_05 = new QPushButton(widget);
        dayButton_05->setObjectName(QStringLiteral("dayButton_05"));
        dayButton_05->setGeometry(QRect(280, 10, 40, 40));
        dayButton_05->setFont(font1);
        dayButton_05->setFlat(true);
        dayButton_06 = new QPushButton(widget);
        dayButton_06->setObjectName(QStringLiteral("dayButton_06"));
        dayButton_06->setGeometry(QRect(340, 10, 40, 40));
        dayButton_06->setFont(font1);
        dayButton_06->setFlat(true);
        dayButton_07 = new QPushButton(widget);
        dayButton_07->setObjectName(QStringLiteral("dayButton_07"));
        dayButton_07->setGeometry(QRect(400, 10, 40, 40));
        dayButton_07->setFont(font1);
        dayButton_07->setFlat(true);
        dayButton_08 = new QPushButton(widget);
        dayButton_08->setObjectName(QStringLiteral("dayButton_08"));
        dayButton_08->setGeometry(QRect(40, 60, 40, 40));
        dayButton_08->setFont(font1);
        dayButton_08->setFlat(true);
        dayButton_09 = new QPushButton(widget);
        dayButton_09->setObjectName(QStringLiteral("dayButton_09"));
        dayButton_09->setGeometry(QRect(100, 60, 40, 40));
        dayButton_09->setFont(font1);
        dayButton_09->setFlat(true);
        dayButton_10 = new QPushButton(widget);
        dayButton_10->setObjectName(QStringLiteral("dayButton_10"));
        dayButton_10->setGeometry(QRect(160, 60, 40, 40));
        dayButton_10->setFont(font1);
        dayButton_10->setFlat(true);
        dayButton_11 = new QPushButton(widget);
        dayButton_11->setObjectName(QStringLiteral("dayButton_11"));
        dayButton_11->setGeometry(QRect(220, 60, 40, 40));
        dayButton_11->setFont(font1);
        dayButton_11->setFlat(true);
        dayButton_12 = new QPushButton(widget);
        dayButton_12->setObjectName(QStringLiteral("dayButton_12"));
        dayButton_12->setGeometry(QRect(280, 60, 40, 40));
        dayButton_12->setFont(font1);
        dayButton_12->setFlat(true);
        dayButton_13 = new QPushButton(widget);
        dayButton_13->setObjectName(QStringLiteral("dayButton_13"));
        dayButton_13->setGeometry(QRect(340, 60, 40, 40));
        dayButton_13->setFont(font1);
        dayButton_13->setFlat(true);
        dayButton_14 = new QPushButton(widget);
        dayButton_14->setObjectName(QStringLiteral("dayButton_14"));
        dayButton_14->setGeometry(QRect(400, 60, 40, 40));
        dayButton_14->setFont(font1);
        dayButton_14->setFlat(true);
        dayButton_15 = new QPushButton(widget);
        dayButton_15->setObjectName(QStringLiteral("dayButton_15"));
        dayButton_15->setGeometry(QRect(40, 110, 40, 40));
        dayButton_15->setFont(font1);
        dayButton_15->setFlat(true);
        dayButton_16 = new QPushButton(widget);
        dayButton_16->setObjectName(QStringLiteral("dayButton_16"));
        dayButton_16->setGeometry(QRect(100, 110, 40, 40));
        dayButton_16->setFont(font1);
        dayButton_16->setFlat(true);
        dayButton_17 = new QPushButton(widget);
        dayButton_17->setObjectName(QStringLiteral("dayButton_17"));
        dayButton_17->setGeometry(QRect(160, 110, 40, 40));
        dayButton_17->setFont(font1);
        dayButton_17->setFlat(true);
        dayButton_18 = new QPushButton(widget);
        dayButton_18->setObjectName(QStringLiteral("dayButton_18"));
        dayButton_18->setGeometry(QRect(220, 110, 40, 40));
        dayButton_18->setFont(font1);
        dayButton_18->setFlat(true);
        dayButton_19 = new QPushButton(widget);
        dayButton_19->setObjectName(QStringLiteral("dayButton_19"));
        dayButton_19->setGeometry(QRect(280, 110, 40, 40));
        dayButton_19->setFont(font1);
        dayButton_19->setFlat(true);
        dayButton_20 = new QPushButton(widget);
        dayButton_20->setObjectName(QStringLiteral("dayButton_20"));
        dayButton_20->setGeometry(QRect(340, 110, 40, 40));
        dayButton_20->setFont(font1);
        dayButton_20->setFlat(true);
        dayButton_21 = new QPushButton(widget);
        dayButton_21->setObjectName(QStringLiteral("dayButton_21"));
        dayButton_21->setGeometry(QRect(400, 110, 40, 40));
        dayButton_21->setFont(font1);
        dayButton_21->setFlat(true);
        dayButton_22 = new QPushButton(widget);
        dayButton_22->setObjectName(QStringLiteral("dayButton_22"));
        dayButton_22->setGeometry(QRect(40, 160, 40, 40));
        dayButton_22->setFont(font1);
        dayButton_22->setFlat(true);
        dayButton_23 = new QPushButton(widget);
        dayButton_23->setObjectName(QStringLiteral("dayButton_23"));
        dayButton_23->setGeometry(QRect(100, 160, 40, 40));
        dayButton_23->setFont(font1);
        dayButton_23->setFlat(true);
        dayButton_24 = new QPushButton(widget);
        dayButton_24->setObjectName(QStringLiteral("dayButton_24"));
        dayButton_24->setGeometry(QRect(160, 160, 40, 40));
        dayButton_24->setFont(font1);
        dayButton_24->setFlat(true);
        dayButton_25 = new QPushButton(widget);
        dayButton_25->setObjectName(QStringLiteral("dayButton_25"));
        dayButton_25->setGeometry(QRect(220, 160, 40, 40));
        dayButton_25->setFont(font1);
        dayButton_25->setFlat(true);
        dayButton_26 = new QPushButton(widget);
        dayButton_26->setObjectName(QStringLiteral("dayButton_26"));
        dayButton_26->setGeometry(QRect(280, 160, 40, 40));
        dayButton_26->setFont(font1);
        dayButton_26->setFlat(true);
        dayButton_27 = new QPushButton(widget);
        dayButton_27->setObjectName(QStringLiteral("dayButton_27"));
        dayButton_27->setGeometry(QRect(340, 160, 40, 40));
        dayButton_27->setFont(font1);
        dayButton_27->setFlat(true);
        dayButton_28 = new QPushButton(widget);
        dayButton_28->setObjectName(QStringLiteral("dayButton_28"));
        dayButton_28->setGeometry(QRect(400, 160, 40, 40));
        dayButton_28->setFont(font1);
        dayButton_28->setFlat(true);
        dayButton_29 = new QPushButton(widget);
        dayButton_29->setObjectName(QStringLiteral("dayButton_29"));
        dayButton_29->setGeometry(QRect(40, 210, 40, 40));
        dayButton_29->setFont(font1);
        dayButton_29->setFlat(true);
        dayButton_30 = new QPushButton(widget);
        dayButton_30->setObjectName(QStringLiteral("dayButton_30"));
        dayButton_30->setGeometry(QRect(100, 210, 40, 40));
        dayButton_30->setFont(font1);
        dayButton_30->setFlat(true);
        dayButton_31 = new QPushButton(widget);
        dayButton_31->setObjectName(QStringLiteral("dayButton_31"));
        dayButton_31->setGeometry(QRect(160, 210, 40, 40));
        dayButton_31->setFont(font1);
        dayButton_31->setFlat(true);

        retranslateUi(CalendarDlg);

        QMetaObject::connectSlotsByName(CalendarDlg);
    } // setupUi

    void retranslateUi(QDialog *CalendarDlg)
    {
        CalendarDlg->setWindowTitle(QApplication::translate("CalendarDlg", "CalendarDlg", Q_NULLPTR));
        monthBox->clear();
        monthBox->insertItems(0, QStringList()
         << QApplication::translate("CalendarDlg", "1", Q_NULLPTR)
         << QApplication::translate("CalendarDlg", "2", Q_NULLPTR)
         << QApplication::translate("CalendarDlg", "3", Q_NULLPTR)
         << QApplication::translate("CalendarDlg", "4", Q_NULLPTR)
         << QApplication::translate("CalendarDlg", "5", Q_NULLPTR)
         << QApplication::translate("CalendarDlg", "6", Q_NULLPTR)
         << QApplication::translate("CalendarDlg", "7", Q_NULLPTR)
         << QApplication::translate("CalendarDlg", "8", Q_NULLPTR)
         << QApplication::translate("CalendarDlg", "9", Q_NULLPTR)
         << QApplication::translate("CalendarDlg", "10", Q_NULLPTR)
         << QApplication::translate("CalendarDlg", "11", Q_NULLPTR)
         << QApplication::translate("CalendarDlg", "12", Q_NULLPTR)
        );
        yearLabel->setText(QApplication::translate("CalendarDlg", "\345\271\264", Q_NULLPTR));
        monthLabel->setText(QApplication::translate("CalendarDlg", "\346\234\210", Q_NULLPTR));
        dayLabel->setText(QApplication::translate("CalendarDlg", "\346\227\245", Q_NULLPTR));
        dayButton_01->setText(QApplication::translate("CalendarDlg", "1", Q_NULLPTR));
        dayButton_02->setText(QApplication::translate("CalendarDlg", "2", Q_NULLPTR));
        dayButton_03->setText(QApplication::translate("CalendarDlg", "3", Q_NULLPTR));
        dayButton_04->setText(QApplication::translate("CalendarDlg", "4", Q_NULLPTR));
        dayButton_05->setText(QApplication::translate("CalendarDlg", "5", Q_NULLPTR));
        dayButton_06->setText(QApplication::translate("CalendarDlg", "6", Q_NULLPTR));
        dayButton_07->setText(QApplication::translate("CalendarDlg", "7", Q_NULLPTR));
        dayButton_08->setText(QApplication::translate("CalendarDlg", "8", Q_NULLPTR));
        dayButton_09->setText(QApplication::translate("CalendarDlg", "9", Q_NULLPTR));
        dayButton_10->setText(QApplication::translate("CalendarDlg", "10", Q_NULLPTR));
        dayButton_11->setText(QApplication::translate("CalendarDlg", "11", Q_NULLPTR));
        dayButton_12->setText(QApplication::translate("CalendarDlg", "12", Q_NULLPTR));
        dayButton_13->setText(QApplication::translate("CalendarDlg", "13", Q_NULLPTR));
        dayButton_14->setText(QApplication::translate("CalendarDlg", "14", Q_NULLPTR));
        dayButton_15->setText(QApplication::translate("CalendarDlg", "15", Q_NULLPTR));
        dayButton_16->setText(QApplication::translate("CalendarDlg", "16", Q_NULLPTR));
        dayButton_17->setText(QApplication::translate("CalendarDlg", "17", Q_NULLPTR));
        dayButton_18->setText(QApplication::translate("CalendarDlg", "18", Q_NULLPTR));
        dayButton_19->setText(QApplication::translate("CalendarDlg", "19", Q_NULLPTR));
        dayButton_20->setText(QApplication::translate("CalendarDlg", "20", Q_NULLPTR));
        dayButton_21->setText(QApplication::translate("CalendarDlg", "21", Q_NULLPTR));
        dayButton_22->setText(QApplication::translate("CalendarDlg", "22", Q_NULLPTR));
        dayButton_23->setText(QApplication::translate("CalendarDlg", "23", Q_NULLPTR));
        dayButton_24->setText(QApplication::translate("CalendarDlg", "24", Q_NULLPTR));
        dayButton_25->setText(QApplication::translate("CalendarDlg", "25", Q_NULLPTR));
        dayButton_26->setText(QApplication::translate("CalendarDlg", "26", Q_NULLPTR));
        dayButton_27->setText(QApplication::translate("CalendarDlg", "27", Q_NULLPTR));
        dayButton_28->setText(QApplication::translate("CalendarDlg", "28", Q_NULLPTR));
        dayButton_29->setText(QApplication::translate("CalendarDlg", "29", Q_NULLPTR));
        dayButton_30->setText(QApplication::translate("CalendarDlg", "30", Q_NULLPTR));
        dayButton_31->setText(QApplication::translate("CalendarDlg", "31", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalendarDlg: public Ui_CalendarDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARDLG_H
