/********************************************************************************
** Form generated from reading UI file 'ReplaceCardWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACECARDWIDGET_H
#define UI_REPLACECARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplaceCardWidget
{
public:
    QWidget *widget;
    QLineEdit *cardIdEdit;
    QLabel *cardIdLabel;
    QLabel *warningLabel;
    QWidget *widget_2;
    QLabel *documentIdLabel;
    QLabel *payPwdValueLabel;
    QLabel *payPwdLabel;
    QLabel *nameQueryLabel;
    QLabel *phoneValueQueryLabel;
    QLabel *sexQueryLabel;
    QLabel *phoneQueryLabel;
    QLabel *birthdayValueLabel;
    QLabel *nameValueQueryLabel;
    QLabel *birthdayLabel;
    QLabel *documentTypeValueLabel;
    QLabel *sexValueQueryLabel;
    QLabel *documentTypeLabel;
    QLabel *documentIdValueLabel;
    QLabel *addressValueLabel;
    QLabel *memGradeLabel;
    QLabel *memGradeValueLabel;
    QLabel *addressLabel;
    QLabel *memTypeLabel;
    QLabel *memTypeValueLabel;
    QWidget *widget_6;
    QLabel *balanceLabel;
    QLabel *integValueLabel;
    QLabel *balanceValueLabel;
    QLabel *integLabel;
    QWidget *widget_7;
    QPushButton *commitReplaceButton;

    void setupUi(QWidget *ReplaceCardWidget)
    {
        if (ReplaceCardWidget->objectName().isEmpty())
            ReplaceCardWidget->setObjectName(QStringLiteral("ReplaceCardWidget"));
        ReplaceCardWidget->resize(282, 506);
        ReplaceCardWidget->setMinimumSize(QSize(282, 506));
        widget = new QWidget(ReplaceCardWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 281, 67));
        widget->setStyleSheet(QLatin1String("QWidget#widget {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        cardIdEdit = new QLineEdit(widget);
        cardIdEdit->setObjectName(QStringLiteral("cardIdEdit"));
        cardIdEdit->setGeometry(QRect(80, 18, 170, 33));
        cardIdEdit->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        cardIdLabel = new QLabel(widget);
        cardIdLabel->setObjectName(QStringLiteral("cardIdLabel"));
        cardIdLabel->setGeometry(QRect(20, 18, 41, 33));
        cardIdLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        cardIdLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        warningLabel = new QLabel(widget);
        warningLabel->setObjectName(QStringLiteral("warningLabel"));
        warningLabel->setGeometry(QRect(80, 50, 171, 16));
        warningLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(249, 79, 79);"));
        widget_2 = new QWidget(ReplaceCardWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 67, 281, 291));
        widget_2->setStyleSheet(QLatin1String("QWidget#widget_2 {	\n"
"	background-color: rgb(250, 250, 250);\n"
"}"));
        documentIdLabel = new QLabel(widget_2);
        documentIdLabel->setObjectName(QStringLiteral("documentIdLabel"));
        documentIdLabel->setGeometry(QRect(13, 178, 80, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        documentIdLabel->setFont(font);
        documentIdLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        documentIdLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        payPwdValueLabel = new QLabel(widget_2);
        payPwdValueLabel->setObjectName(QStringLiteral("payPwdValueLabel"));
        payPwdValueLabel->setGeometry(QRect(100, 94, 175, 20));
        payPwdValueLabel->setFont(font);
        payPwdValueLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        payPwdLabel = new QLabel(widget_2);
        payPwdLabel->setObjectName(QStringLiteral("payPwdLabel"));
        payPwdLabel->setGeometry(QRect(13, 94, 80, 20));
        payPwdLabel->setFont(font);
        payPwdLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        payPwdLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        nameQueryLabel = new QLabel(widget_2);
        nameQueryLabel->setObjectName(QStringLiteral("nameQueryLabel"));
        nameQueryLabel->setGeometry(QRect(13, 2, 80, 30));
        nameQueryLabel->setFont(font);
        nameQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        nameQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        phoneValueQueryLabel = new QLabel(widget_2);
        phoneValueQueryLabel->setObjectName(QStringLiteral("phoneValueQueryLabel"));
        phoneValueQueryLabel->setGeometry(QRect(100, 65, 175, 20));
        phoneValueQueryLabel->setFont(font);
        phoneValueQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        sexQueryLabel = new QLabel(widget_2);
        sexQueryLabel->setObjectName(QStringLiteral("sexQueryLabel"));
        sexQueryLabel->setGeometry(QRect(13, 35, 80, 20));
        sexQueryLabel->setFont(font);
        sexQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        sexQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        phoneQueryLabel = new QLabel(widget_2);
        phoneQueryLabel->setObjectName(QStringLiteral("phoneQueryLabel"));
        phoneQueryLabel->setGeometry(QRect(10, 65, 80, 20));
        phoneQueryLabel->setFont(font);
        phoneQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        phoneQueryLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        birthdayValueLabel = new QLabel(widget_2);
        birthdayValueLabel->setObjectName(QStringLiteral("birthdayValueLabel"));
        birthdayValueLabel->setGeometry(QRect(100, 122, 175, 20));
        birthdayValueLabel->setFont(font);
        birthdayValueLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        nameValueQueryLabel = new QLabel(widget_2);
        nameValueQueryLabel->setObjectName(QStringLiteral("nameValueQueryLabel"));
        nameValueQueryLabel->setGeometry(QRect(100, 2, 175, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        nameValueQueryLabel->setFont(font1);
        nameValueQueryLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        birthdayLabel = new QLabel(widget_2);
        birthdayLabel->setObjectName(QStringLiteral("birthdayLabel"));
        birthdayLabel->setGeometry(QRect(13, 122, 80, 20));
        birthdayLabel->setFont(font);
        birthdayLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        birthdayLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        documentTypeValueLabel = new QLabel(widget_2);
        documentTypeValueLabel->setObjectName(QStringLiteral("documentTypeValueLabel"));
        documentTypeValueLabel->setGeometry(QRect(100, 150, 175, 20));
        documentTypeValueLabel->setFont(font1);
        documentTypeValueLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        sexValueQueryLabel = new QLabel(widget_2);
        sexValueQueryLabel->setObjectName(QStringLiteral("sexValueQueryLabel"));
        sexValueQueryLabel->setGeometry(QRect(100, 35, 175, 20));
        sexValueQueryLabel->setFont(font);
        sexValueQueryLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        documentTypeLabel = new QLabel(widget_2);
        documentTypeLabel->setObjectName(QStringLiteral("documentTypeLabel"));
        documentTypeLabel->setGeometry(QRect(13, 150, 80, 20));
        documentTypeLabel->setFont(font);
        documentTypeLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        documentTypeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        documentIdValueLabel = new QLabel(widget_2);
        documentIdValueLabel->setObjectName(QStringLiteral("documentIdValueLabel"));
        documentIdValueLabel->setGeometry(QRect(100, 178, 175, 20));
        documentIdValueLabel->setFont(font1);
        documentIdValueLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        addressValueLabel = new QLabel(widget_2);
        addressValueLabel->setObjectName(QStringLiteral("addressValueLabel"));
        addressValueLabel->setGeometry(QRect(90, 206, 175, 20));
        addressValueLabel->setFont(font1);
        addressValueLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        memGradeLabel = new QLabel(widget_2);
        memGradeLabel->setObjectName(QStringLiteral("memGradeLabel"));
        memGradeLabel->setGeometry(QRect(3, 260, 80, 20));
        memGradeLabel->setFont(font);
        memGradeLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        memGradeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        memGradeValueLabel = new QLabel(widget_2);
        memGradeValueLabel->setObjectName(QStringLiteral("memGradeValueLabel"));
        memGradeValueLabel->setGeometry(QRect(90, 260, 175, 20));
        memGradeValueLabel->setFont(font1);
        memGradeValueLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        addressLabel = new QLabel(widget_2);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));
        addressLabel->setGeometry(QRect(3, 206, 80, 20));
        addressLabel->setFont(font);
        addressLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        addressLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        memTypeLabel = new QLabel(widget_2);
        memTypeLabel->setObjectName(QStringLiteral("memTypeLabel"));
        memTypeLabel->setGeometry(QRect(3, 234, 80, 20));
        memTypeLabel->setFont(font);
        memTypeLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        memTypeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        memTypeValueLabel = new QLabel(widget_2);
        memTypeValueLabel->setObjectName(QStringLiteral("memTypeValueLabel"));
        memTypeValueLabel->setGeometry(QRect(90, 234, 175, 20));
        memTypeValueLabel->setFont(font1);
        memTypeValueLabel->setStyleSheet(QString::fromUtf8("font:12px;\n"
"font:bold;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        widget_6 = new QWidget(ReplaceCardWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(0, 359, 282, 82));
        widget_6->setMinimumSize(QSize(282, 82));
        widget_6->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 250);"));
        balanceLabel = new QLabel(widget_6);
        balanceLabel->setObjectName(QStringLiteral("balanceLabel"));
        balanceLabel->setGeometry(QRect(3, 10, 60, 30));
        balanceLabel->setFont(font);
        balanceLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        balanceLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        integValueLabel = new QLabel(widget_6);
        integValueLabel->setObjectName(QStringLiteral("integValueLabel"));
        integValueLabel->setGeometry(QRect(90, 43, 175, 30));
        integValueLabel->setFont(font1);
        integValueLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font:bold;\n"
"color: rgb(243, 133, 72);\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        integValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        balanceValueLabel = new QLabel(widget_6);
        balanceValueLabel->setObjectName(QStringLiteral("balanceValueLabel"));
        balanceValueLabel->setGeometry(QRect(90, 10, 175, 30));
        balanceValueLabel->setFont(font1);
        balanceValueLabel->setStyleSheet(QString::fromUtf8("font:18px;\n"
"font:bold;\n"
"color: rgb(243, 133, 72);\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        balanceValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        integLabel = new QLabel(widget_6);
        integLabel->setObjectName(QStringLiteral("integLabel"));
        integLabel->setGeometry(QRect(3, 43, 60, 30));
        integLabel->setFont(font);
        integLabel->setStyleSheet(QString::fromUtf8("font:14px;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);"));
        integLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        widget_7 = new QWidget(ReplaceCardWidget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(0, 440, 282, 68));
        widget_7->setMinimumSize(QSize(282, 68));
        widget_7->setStyleSheet(QLatin1String("QWidget#widget_7 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        commitReplaceButton = new QPushButton(widget_7);
        commitReplaceButton->setObjectName(QStringLiteral("commitReplaceButton"));
        commitReplaceButton->setGeometry(QRect(10, 10, 255, 44));
        commitReplaceButton->setMinimumSize(QSize(255, 44));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        commitReplaceButton->setFont(font2);
        commitReplaceButton->setFocusPolicy(Qt::NoFocus);
        commitReplaceButton->setStyleSheet(QLatin1String("QPushButton#commitReplaceButton {\n"
"	font:14px;\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#commitReplaceButton:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));

        retranslateUi(ReplaceCardWidget);

        QMetaObject::connectSlotsByName(ReplaceCardWidget);
    } // setupUi

    void retranslateUi(QWidget *ReplaceCardWidget)
    {
        ReplaceCardWidget->setWindowTitle(QApplication::translate("ReplaceCardWidget", "ReplaceCardWidget", Q_NULLPTR));
        cardIdLabel->setText(QApplication::translate("ReplaceCardWidget", "\345\215\241\345\217\267", Q_NULLPTR));
        warningLabel->setText(QString());
        documentIdLabel->setText(QApplication::translate("ReplaceCardWidget", "\350\257\201\344\273\266\345\217\267\357\274\232", Q_NULLPTR));
        payPwdValueLabel->setText(QString());
        payPwdLabel->setText(QApplication::translate("ReplaceCardWidget", "\346\224\257\344\273\230\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        nameQueryLabel->setText(QApplication::translate("ReplaceCardWidget", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        phoneValueQueryLabel->setText(QString());
        sexQueryLabel->setText(QApplication::translate("ReplaceCardWidget", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        phoneQueryLabel->setText(QApplication::translate("ReplaceCardWidget", "\346\211\213\346\234\272\345\217\267\357\274\232", Q_NULLPTR));
        birthdayValueLabel->setText(QString());
        nameValueQueryLabel->setText(QString());
        birthdayLabel->setText(QApplication::translate("ReplaceCardWidget", "\347\224\237\346\227\245\357\274\232", Q_NULLPTR));
        documentTypeValueLabel->setText(QString());
        sexValueQueryLabel->setText(QString());
        documentTypeLabel->setText(QApplication::translate("ReplaceCardWidget", "\350\257\201\344\273\266\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        documentIdValueLabel->setText(QString());
        addressValueLabel->setText(QString());
        memGradeLabel->setText(QApplication::translate("ReplaceCardWidget", "\344\274\232\345\221\230\347\255\211\347\272\247\357\274\232", Q_NULLPTR));
        memGradeValueLabel->setText(QString());
        addressLabel->setText(QApplication::translate("ReplaceCardWidget", "\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        memTypeLabel->setText(QApplication::translate("ReplaceCardWidget", "\344\274\232\345\221\230\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        memTypeValueLabel->setText(QString());
        balanceLabel->setText(QApplication::translate("ReplaceCardWidget", "\344\275\231\351\242\235\357\274\232", Q_NULLPTR));
        integValueLabel->setText(QString());
        balanceValueLabel->setText(QString());
        integLabel->setText(QApplication::translate("ReplaceCardWidget", "\347\247\257\345\210\206\357\274\232", Q_NULLPTR));
        commitReplaceButton->setText(QApplication::translate("ReplaceCardWidget", "\346\217\220\344\272\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReplaceCardWidget: public Ui_ReplaceCardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACECARDWIDGET_H
