/********************************************************************************
** Form generated from reading UI file 'SalemanInfoDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALEMANINFODLG_H
#define UI_SALEMANINFODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <SalemanListView.h>
#include <TitleBarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_SalemanInfoDlg
{
public:
    QGridLayout *gridLayout;
    TitleBarWidget *titleWidget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    SalemanListView *listView;
    QLabel *label;
    QPushButton *upPageBtn;
    QPushButton *downPageBtn;
    QFrame *line;

    void setupUi(QDialog *SalemanInfoDlg)
    {
        if (SalemanInfoDlg->objectName().isEmpty())
            SalemanInfoDlg->setObjectName(QStringLiteral("SalemanInfoDlg"));
        SalemanInfoDlg->resize(374, 280);
        gridLayout = new QGridLayout(SalemanInfoDlg);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new TitleBarWidget(SalemanInfoDlg);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 45));
        titleWidget->setMaximumSize(QSize(16777215, 45));

        gridLayout->addWidget(titleWidget, 0, 0, 1, 1);

        widget_2 = new QWidget(SalemanInfoDlg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QLatin1String("QWidget#widget_2 {\n"
"	border-image: url(:/shareImages/dlg_background.png);\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 14, 20, 23);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QLatin1String("QWidget#widget_3 {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        listView = new SalemanListView(widget_3);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(12, 30, 306, 116));
        listView->setFocusPolicy(Qt::NoFocus);
        listView->setStyleSheet(QStringLiteral("border:0px;"));
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 54, 21));
        label->setStyleSheet(QString::fromUtf8("font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font:14px;\n"
"color: rgb(51, 51, 51);"));
        upPageBtn = new QPushButton(widget_3);
        upPageBtn->setObjectName(QStringLiteral("upPageBtn"));
        upPageBtn->setGeometry(QRect(170, 150, 87, 37));
        upPageBtn->setMinimumSize(QSize(87, 37));
        upPageBtn->setMaximumSize(QSize(87, 37));
        upPageBtn->setFocusPolicy(Qt::NoFocus);
        upPageBtn->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border:none;\n"
"	border-image: url(:/saleImage/btn-up-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border-image: url(:/saleImage/btn-up-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	border-image: url(:/saleImage/btn-up-disable.png);\n"
"}"));
        downPageBtn = new QPushButton(widget_3);
        downPageBtn->setObjectName(QStringLiteral("downPageBtn"));
        downPageBtn->setGeometry(QRect(260, 150, 87, 37));
        downPageBtn->setMinimumSize(QSize(87, 37));
        downPageBtn->setMaximumSize(QSize(87, 37));
        downPageBtn->setFocusPolicy(Qt::NoFocus);
        downPageBtn->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border:none;\n"
"	border-image: url(:/saleImage/btn-down-nomal.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border-image: url(:/saleImage/btn-down-pess.png);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	border-image: url(:/saleImage/btn-down-disabled.png);\n"
"}"));
        line = new QFrame(widget_3);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(260, 159, 2, 21));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(widget_3);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(SalemanInfoDlg);

        QMetaObject::connectSlotsByName(SalemanInfoDlg);
    } // setupUi

    void retranslateUi(QDialog *SalemanInfoDlg)
    {
        SalemanInfoDlg->setWindowTitle(QApplication::translate("SalemanInfoDlg", "SalemanInfoDlg", Q_NULLPTR));
        label->setText(QApplication::translate("SalemanInfoDlg", "\350\257\267\351\200\211\346\213\251\357\274\232", Q_NULLPTR));
        upPageBtn->setText(QString());
        downPageBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SalemanInfoDlg: public Ui_SalemanInfoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEMANINFODLG_H
