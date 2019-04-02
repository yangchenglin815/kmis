/********************************************************************************
** Form generated from reading UI file 'DlgCommon.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCOMMON_H
#define UI_DLGCOMMON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgCommon
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *titleLabel;
    QPushButton *deleteBtn;
    QLabel *contextLabel;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *sureBtn;
    QPushButton *cancelBtn;

    void setupUi(QWidget *DlgCommon)
    {
        if (DlgCommon->objectName().isEmpty())
            DlgCommon->setObjectName(QStringLiteral("DlgCommon"));
        DlgCommon->resize(370, 231);
        DlgCommon->setMinimumSize(QSize(370, 231));
        DlgCommon->setStyleSheet(QLatin1String("QWidget#DlgCommon {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        verticalLayout = new QVBoxLayout(DlgCommon);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new QWidget(DlgCommon);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 42));
        titleWidget->setMaximumSize(QSize(16777215, 42));
        titleWidget->setStyleSheet(QLatin1String("QWidget#titleWidget {\n"
"	border-image: url(:/shareImages/title_bar.png);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(titleWidget);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 5, 5, 5);
        titleLabel = new QLabel(titleWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setMinimumSize(QSize(0, 30));
        titleLabel->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel#titleLabel {\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:16px;\n"
"	color: rgb(255, 255, 255);\n"
"	border-width: 0px;\n"
"}"));
        titleLabel->setFrameShape(QFrame::NoFrame);
        titleLabel->setFrameShadow(QFrame::Plain);
        titleLabel->setLineWidth(1);

        horizontalLayout_2->addWidget(titleLabel);

        deleteBtn = new QPushButton(titleWidget);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        deleteBtn->setMinimumSize(QSize(33, 33));
        deleteBtn->setMaximumSize(QSize(33, 33));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        deleteBtn->setFont(font1);
        deleteBtn->setFocusPolicy(Qt::NoFocus);
        deleteBtn->setStyleSheet(QLatin1String("QPushButton#deleteBtn {\n"
"	border-image: url(:/shareImages/close.png);\n"
"}\n"
"\n"
"QPushButton#deleteBtn:pressed {\n"
"	border-image: url(:/shareImages/close_press.png);\n"
"}"));

        horizontalLayout_2->addWidget(deleteBtn);


        verticalLayout->addWidget(titleWidget);

        contextLabel = new QLabel(DlgCommon);
        contextLabel->setObjectName(QStringLiteral("contextLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contextLabel->sizePolicy().hasHeightForWidth());
        contextLabel->setSizePolicy(sizePolicy);
        contextLabel->setMinimumSize(QSize(310, 0));
        contextLabel->setMaximumSize(QSize(310, 16777215));
        contextLabel->setFont(font);
        contextLabel->setStyleSheet(QString::fromUtf8("font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"font-size:16px;"));
        contextLabel->setAlignment(Qt::AlignCenter);
        contextLabel->setWordWrap(true);

        verticalLayout->addWidget(contextLabel, 0, Qt::AlignHCenter);

        bottomWidget = new QWidget(DlgCommon);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 62));
        bottomWidget->setMaximumSize(QSize(16777215, 62));
        horizontalLayout = new QHBoxLayout(bottomWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sureBtn = new QPushButton(bottomWidget);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sureBtn->sizePolicy().hasHeightForWidth());
        sureBtn->setSizePolicy(sizePolicy1);
        sureBtn->setMinimumSize(QSize(152, 42));
        sureBtn->setMaximumSize(QSize(152, 42));
        sureBtn->setFont(font);
        sureBtn->setFocusPolicy(Qt::NoFocus);
        sureBtn->setStyleSheet(QString::fromUtf8("QPushButton#sureBtn {\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/sure_normal.png);\n"
"}\n"
"\n"
"QPushButton#sureBtn:pressed {\n"
"	border-image: url(:/shareImages/sure_press.png);\n"
"}"));

        horizontalLayout->addWidget(sureBtn);

        cancelBtn = new QPushButton(bottomWidget);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        sizePolicy1.setHeightForWidth(cancelBtn->sizePolicy().hasHeightForWidth());
        cancelBtn->setSizePolicy(sizePolicy1);
        cancelBtn->setMinimumSize(QSize(152, 42));
        cancelBtn->setMaximumSize(QSize(152, 42));
        cancelBtn->setFont(font);
        cancelBtn->setFocusPolicy(Qt::NoFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton#cancelBtn {\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255, 255, 255);\n"
"	font-size:16px;\n"
"	border-image: url(:/shareImages/cancel_normal.png);\n"
"}\n"
"\n"
"QPushButton#cancelBtn:pressed {\n"
"	border-image: url(:/shareImages/cancel_press.png);\n"
"}"));

        horizontalLayout->addWidget(cancelBtn);


        verticalLayout->addWidget(bottomWidget);


        retranslateUi(DlgCommon);

        QMetaObject::connectSlotsByName(DlgCommon);
    } // setupUi

    void retranslateUi(QWidget *DlgCommon)
    {
        DlgCommon->setWindowTitle(QApplication::translate("DlgCommon", "DlgCommon", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("DlgCommon", "\347\216\260\351\207\221", Q_NULLPTR));
        deleteBtn->setText(QString());
        contextLabel->setText(QApplication::translate("DlgCommon", "\346\230\257\345\220\246\347\241\256\350\256\244\346\224\257\344\273\230?", Q_NULLPTR));
        sureBtn->setText(QApplication::translate("DlgCommon", "\347\241\256\345\256\232", Q_NULLPTR));
        cancelBtn->setText(QApplication::translate("DlgCommon", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DlgCommon: public Ui_DlgCommon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCOMMON_H
