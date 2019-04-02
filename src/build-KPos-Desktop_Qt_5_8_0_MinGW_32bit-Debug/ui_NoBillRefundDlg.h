/********************************************************************************
** Form generated from reading UI file 'NoBillRefundDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOBILLREFUNDDLG_H
#define UI_NOBILLREFUNDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <TitleBarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_NoBillRefundDlg
{
public:
    QGridLayout *gridLayout;
    TitleBarWidget *widget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QLabel *refundAmtLabel;
    QLabel *refundAmtValueLabel;
    QLabel *refundTypeLabel;
    QLabel *cashRefundLabel;
    QLabel *memRefundLabel;
    QPushButton *commitButton;

    void setupUi(QDialog *NoBillRefundDlg)
    {
        if (NoBillRefundDlg->objectName().isEmpty())
            NoBillRefundDlg->setObjectName(QStringLiteral("NoBillRefundDlg"));
        NoBillRefundDlg->resize(475, 354);
        gridLayout = new QGridLayout(NoBillRefundDlg);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new TitleBarWidget(NoBillRefundDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(NoBillRefundDlg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QLatin1String("QWidget#widget_2 {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(415, 234));
        widget_3->setMaximumSize(QSize(415, 234));
        widget_3->setStyleSheet(QLatin1String("QWidget#widget_3 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        refundAmtLabel = new QLabel(widget_3);
        refundAmtLabel->setObjectName(QStringLiteral("refundAmtLabel"));
        refundAmtLabel->setGeometry(QRect(25, 11, 80, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        refundAmtLabel->setFont(font);
        refundAmtValueLabel = new QLabel(widget_3);
        refundAmtValueLabel->setObjectName(QStringLiteral("refundAmtValueLabel"));
        refundAmtValueLabel->setGeometry(QRect(270, 11, 115, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        refundAmtValueLabel->setFont(font1);
        refundAmtValueLabel->setStyleSheet(QStringLiteral("color: rgb(234, 136, 82);"));
        refundAmtValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        refundTypeLabel = new QLabel(widget_3);
        refundTypeLabel->setObjectName(QStringLiteral("refundTypeLabel"));
        refundTypeLabel->setGeometry(QRect(25, 60, 80, 36));
        refundTypeLabel->setFont(font);
        cashRefundLabel = new QLabel(widget_3);
        cashRefundLabel->setObjectName(QStringLiteral("cashRefundLabel"));
        cashRefundLabel->setGeometry(QRect(113, 60, 84, 36));
        cashRefundLabel->setFont(font);
        cashRefundLabel->setStyleSheet(QLatin1String("QLabel#cashRefundLabel {\n"
"	border-image: url(:/shareImages/cash_normal.png);\n"
"}\n"
"\n"
"QLabe#cashRefundLabel {\n"
"	border-image: url(:/shareImages/cash_press.png);\n"
"}"));
        memRefundLabel = new QLabel(widget_3);
        memRefundLabel->setObjectName(QStringLiteral("memRefundLabel"));
        memRefundLabel->setGeometry(QRect(210, 60, 84, 36));
        memRefundLabel->setFont(font);
        memRefundLabel->setStyleSheet(QLatin1String("QLabel#memRefundLabel {\n"
"	border-image: url(:/shareImages/mem_normal.png);\n"
"}\n"
"\n"
"QLabe#memRefundLabel {\n"
"	border-image: url(:/shareImages/mem_press.png);\n"
"}"));
        commitButton = new QPushButton(widget_3);
        commitButton->setObjectName(QStringLiteral("commitButton"));
        commitButton->setGeometry(QRect(20, 150, 371, 70));
        commitButton->setFont(font);
        commitButton->setStyleSheet(QLatin1String("QPushButton#commitButton {\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#commitButton {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));

        horizontalLayout->addWidget(widget_3);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(NoBillRefundDlg);

        QMetaObject::connectSlotsByName(NoBillRefundDlg);
    } // setupUi

    void retranslateUi(QDialog *NoBillRefundDlg)
    {
        NoBillRefundDlg->setWindowTitle(QApplication::translate("NoBillRefundDlg", "NoBillRefundDlg", Q_NULLPTR));
        refundAmtLabel->setText(QApplication::translate("NoBillRefundDlg", "\351\200\200\346\254\276\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        refundAmtValueLabel->setText(QApplication::translate("NoBillRefundDlg", "\357\277\24527.02", Q_NULLPTR));
        refundTypeLabel->setText(QApplication::translate("NoBillRefundDlg", "\351\200\200\346\254\276\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        cashRefundLabel->setText(QString());
        memRefundLabel->setText(QString());
        commitButton->setText(QApplication::translate("NoBillRefundDlg", "\346\217\220\344\272\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NoBillRefundDlg: public Ui_NoBillRefundDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOBILLREFUNDDLG_H
