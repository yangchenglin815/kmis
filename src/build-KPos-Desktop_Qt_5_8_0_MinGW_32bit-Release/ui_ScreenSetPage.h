/********************************************************************************
** Form generated from reading UI file 'ScreenSetPage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENSETPAGE_H
#define UI_SCREENSETPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "KPosComboBox.h"

QT_BEGIN_NAMESPACE

class Ui_ScreenSetPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *skinWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *topWidget;
    QLabel *printerModelLabel;
    QLabel *isPrintLabel;
    QRadioButton *numberScreenRButton;
    QRadioButton *colorScreenRButton;
    QPushButton *printerTestButton;
    QFrame *line;
    QRadioButton *noPrintButton;
    QRadioButton *noScreenRButton;
    QLabel *customerDisplayTypeLabel;
    QRadioButton *englishScreenRButton;
    QRadioButton *chineseScreenRButton;
    QRadioButton *yesPrintButton;
    KPosComboBox *painterModelComBox;
    QWidget *middleWidget;
    QPushButton *addADButton;
    QLabel *localUploadLabel;
    QPushButton *pushButton;
    QWidget *widget_3;
    QWidget *widget_4;
    QWidget *widget;
    QWidget *widget_2;
    QPushButton *pushButton_2;
    QLabel *headquartersUploadLabel;
    QWidget *widget_5;
    QWidget *bottomWidget;
    QLabel *eleScalePortLabel;
    QLabel *customerModelLabel;
    QFrame *line_2;
    KPosComboBox *clientScreenModelComBox;
    KPosComboBox *clientScreenPortComBox;
    QLabel *cardReaderPortLabel;
    QPushButton *cardReaderTestButton;
    QLabel *cardReaderModelLabel;
    KPosComboBox *eBalancePortComboBox;
    QLabel *customerPortLabel;
    QPushButton *clientScreenPortTestButton;
    QLabel *eleScaleModelLabel;
    KPosComboBox *cardReaderModelComBox;
    KPosComboBox *cardReaderPortComboBox;
    KPosComboBox *eBalanceModelComboBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ScreenSetPage)
    {
        if (ScreenSetPage->objectName().isEmpty())
            ScreenSetPage->setObjectName(QStringLiteral("ScreenSetPage"));
        ScreenSetPage->resize(607, 513);
        verticalLayout = new QVBoxLayout(ScreenSetPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        skinWidget = new QWidget(ScreenSetPage);
        skinWidget->setObjectName(QStringLiteral("skinWidget"));
        skinWidget->setStyleSheet(QLatin1String("QWidget#skinWidget{\n"
"	background-color:#ffffff;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(skinWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 18, 0, 0);
        topWidget = new QWidget(skinWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(0, 111));
        topWidget->setMaximumSize(QSize(16777215, 111));
        printerModelLabel = new QLabel(topWidget);
        printerModelLabel->setObjectName(QStringLiteral("printerModelLabel"));
        printerModelLabel->setGeometry(QRect(0, 0, 100, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        printerModelLabel->setFont(font);
        printerModelLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        isPrintLabel = new QLabel(topWidget);
        isPrintLabel->setObjectName(QStringLiteral("isPrintLabel"));
        isPrintLabel->setGeometry(QRect(0, 32, 100, 30));
        isPrintLabel->setFont(font);
        isPrintLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        numberScreenRButton = new QRadioButton(topWidget);
        numberScreenRButton->setObjectName(QStringLiteral("numberScreenRButton"));
        numberScreenRButton->setGeometry(QRect(210, 72, 90, 30));
        numberScreenRButton->setFont(font);
        numberScreenRButton->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        colorScreenRButton = new QRadioButton(topWidget);
        colorScreenRButton->setObjectName(QStringLiteral("colorScreenRButton"));
        colorScreenRButton->setGeometry(QRect(500, 72, 90, 30));
        colorScreenRButton->setFont(font);
        colorScreenRButton->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        printerTestButton = new QPushButton(topWidget);
        printerTestButton->setObjectName(QStringLiteral("printerTestButton"));
        printerTestButton->setGeometry(QRect(300, 0, 90, 30));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(printerTestButton->sizePolicy().hasHeightForWidth());
        printerTestButton->setSizePolicy(sizePolicy);
        printerTestButton->setFont(font);
        printerTestButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/kPosSetImage/buttonNormal.png);\n"
"color:#ffffff;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/kPosSetImage/buttonPressed.png);\n"
"}"));
        line = new QFrame(topWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 72, 571, 1));
        line->setMinimumSize(QSize(0, 1));
        line->setMaximumSize(QSize(16777215, 1));
        line->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        noPrintButton = new QRadioButton(topWidget);
        noPrintButton->setObjectName(QStringLiteral("noPrintButton"));
        noPrintButton->setGeometry(QRect(194, 32, 51, 30));
        noPrintButton->setFont(font);
        noScreenRButton = new QRadioButton(topWidget);
        noScreenRButton->setObjectName(QStringLiteral("noScreenRButton"));
        noScreenRButton->setGeometry(QRect(110, 72, 90, 30));
        noScreenRButton->setFont(font);
        noScreenRButton->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        customerDisplayTypeLabel = new QLabel(topWidget);
        customerDisplayTypeLabel->setObjectName(QStringLiteral("customerDisplayTypeLabel"));
        customerDisplayTypeLabel->setGeometry(QRect(0, 72, 100, 30));
        customerDisplayTypeLabel->setFont(font);
        customerDisplayTypeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        englishScreenRButton = new QRadioButton(topWidget);
        englishScreenRButton->setObjectName(QStringLiteral("englishScreenRButton"));
        englishScreenRButton->setGeometry(QRect(300, 72, 90, 30));
        englishScreenRButton->setFont(font);
        englishScreenRButton->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        chineseScreenRButton = new QRadioButton(topWidget);
        chineseScreenRButton->setObjectName(QStringLiteral("chineseScreenRButton"));
        chineseScreenRButton->setGeometry(QRect(400, 72, 90, 30));
        chineseScreenRButton->setFont(font);
        chineseScreenRButton->setStyleSheet(QStringLiteral("color: rgb(51, 51, 51);"));
        yesPrintButton = new QRadioButton(topWidget);
        yesPrintButton->setObjectName(QStringLiteral("yesPrintButton"));
        yesPrintButton->setGeometry(QRect(134, 32, 51, 30));
        yesPrintButton->setFont(font);
        painterModelComBox = new KPosComboBox(topWidget);
        painterModelComBox->setObjectName(QStringLiteral("painterModelComBox"));
        painterModelComBox->setGeometry(QRect(110, 0, 190, 30));

        verticalLayout_2->addWidget(topWidget);

        middleWidget = new QWidget(skinWidget);
        middleWidget->setObjectName(QStringLiteral("middleWidget"));
        middleWidget->setMinimumSize(QSize(0, 120));
        middleWidget->setMaximumSize(QSize(16777215, 120));
        addADButton = new QPushButton(middleWidget);
        addADButton->setObjectName(QStringLiteral("addADButton"));
        addADButton->setGeometry(QRect(500, 40, 63, 63));
        addADButton->setFont(font);
        addADButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/kPosSetImage/addAD.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/kPosSetImage/addADPressed.png);\n"
"}"));
        localUploadLabel = new QLabel(middleWidget);
        localUploadLabel->setObjectName(QStringLiteral("localUploadLabel"));
        localUploadLabel->setGeometry(QRect(333, 0, 71, 30));
        localUploadLabel->setFont(font);
        pushButton = new QPushButton(middleWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(253, 60, 15, 18));
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/kPosSetImage/right.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/right_press.png);\n"
"}"));
        widget_3 = new QWidget(middleWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(333, 40, 63, 63));
        widget_4 = new QWidget(middleWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(403, 40, 63, 63));
        widget = new QWidget(middleWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(43, 40, 63, 63));
        widget_2 = new QWidget(middleWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(113, 40, 63, 63));
        pushButton_2 = new QPushButton(middleWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(473, 60, 15, 18));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/kPosSetImage/right.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-image: url(:/kPosSetImage/right_press.png);\n"
"}"));
        headquartersUploadLabel = new QLabel(middleWidget);
        headquartersUploadLabel->setObjectName(QStringLiteral("headquartersUploadLabel"));
        headquartersUploadLabel->setGeometry(QRect(43, 0, 71, 30));
        headquartersUploadLabel->setFont(font);
        widget_5 = new QWidget(middleWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(183, 40, 63, 63));

        verticalLayout_2->addWidget(middleWidget);

        bottomWidget = new QWidget(skinWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 261));
        bottomWidget->setMaximumSize(QSize(16777215, 261));
        eleScalePortLabel = new QLabel(bottomWidget);
        eleScalePortLabel->setObjectName(QStringLiteral("eleScalePortLabel"));
        eleScalePortLabel->setGeometry(QRect(0, 220, 100, 30));
        eleScalePortLabel->setFont(font);
        eleScalePortLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        customerModelLabel = new QLabel(bottomWidget);
        customerModelLabel->setObjectName(QStringLiteral("customerModelLabel"));
        customerModelLabel->setGeometry(QRect(0, 0, 100, 30));
        customerModelLabel->setFont(font);
        customerModelLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line_2 = new QFrame(bottomWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(20, 170, 571, 1));
        line_2->setMinimumSize(QSize(0, 1));
        line_2->setMaximumSize(QSize(16777215, 1));
        line_2->setStyleSheet(QStringLiteral("border: 1px solid #ededed;"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        clientScreenModelComBox = new KPosComboBox(bottomWidget);
        clientScreenModelComBox->setObjectName(QStringLiteral("clientScreenModelComBox"));
        clientScreenModelComBox->setGeometry(QRect(110, 0, 272, 30));
        clientScreenPortComBox = new KPosComboBox(bottomWidget);
        clientScreenPortComBox->setObjectName(QStringLiteral("clientScreenPortComBox"));
        clientScreenPortComBox->setGeometry(QRect(110, 50, 190, 30));
        cardReaderPortLabel = new QLabel(bottomWidget);
        cardReaderPortLabel->setObjectName(QStringLiteral("cardReaderPortLabel"));
        cardReaderPortLabel->setGeometry(QRect(0, 130, 100, 30));
        cardReaderPortLabel->setFont(font);
        cardReaderPortLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cardReaderTestButton = new QPushButton(bottomWidget);
        cardReaderTestButton->setObjectName(QStringLiteral("cardReaderTestButton"));
        cardReaderTestButton->setGeometry(QRect(300, 130, 90, 30));
        cardReaderTestButton->setFont(font);
        cardReaderTestButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/kPosSetImage/buttonNormal.png);\n"
"color:#ffffff;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/kPosSetImage/buttonPressed.png);\n"
"}"));
        cardReaderModelLabel = new QLabel(bottomWidget);
        cardReaderModelLabel->setObjectName(QStringLiteral("cardReaderModelLabel"));
        cardReaderModelLabel->setGeometry(QRect(0, 90, 100, 30));
        cardReaderModelLabel->setFont(font);
        cardReaderModelLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        eBalancePortComboBox = new KPosComboBox(bottomWidget);
        eBalancePortComboBox->setObjectName(QStringLiteral("eBalancePortComboBox"));
        eBalancePortComboBox->setGeometry(QRect(110, 220, 272, 30));
        customerPortLabel = new QLabel(bottomWidget);
        customerPortLabel->setObjectName(QStringLiteral("customerPortLabel"));
        customerPortLabel->setGeometry(QRect(0, 50, 100, 30));
        customerPortLabel->setFont(font);
        customerPortLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        clientScreenPortTestButton = new QPushButton(bottomWidget);
        clientScreenPortTestButton->setObjectName(QStringLiteral("clientScreenPortTestButton"));
        clientScreenPortTestButton->setGeometry(QRect(300, 50, 90, 30));
        clientScreenPortTestButton->setFont(font);
        clientScreenPortTestButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/kPosSetImage/buttonNormal.png);\n"
"color:#ffffff;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/kPosSetImage/buttonPressed.png);\n"
"}"));
        eleScaleModelLabel = new QLabel(bottomWidget);
        eleScaleModelLabel->setObjectName(QStringLiteral("eleScaleModelLabel"));
        eleScaleModelLabel->setGeometry(QRect(0, 180, 100, 30));
        eleScaleModelLabel->setFont(font);
        eleScaleModelLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cardReaderModelComBox = new KPosComboBox(bottomWidget);
        cardReaderModelComBox->setObjectName(QStringLiteral("cardReaderModelComBox"));
        cardReaderModelComBox->setGeometry(QRect(110, 90, 272, 30));
        cardReaderPortComboBox = new KPosComboBox(bottomWidget);
        cardReaderPortComboBox->setObjectName(QStringLiteral("cardReaderPortComboBox"));
        cardReaderPortComboBox->setGeometry(QRect(110, 130, 190, 30));
        eBalanceModelComboBox = new KPosComboBox(bottomWidget);
        eBalanceModelComboBox->setObjectName(QStringLiteral("eBalanceModelComboBox"));
        eBalanceModelComboBox->setGeometry(QRect(110, 180, 272, 30));

        verticalLayout_2->addWidget(bottomWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(skinWidget);


        retranslateUi(ScreenSetPage);

        QMetaObject::connectSlotsByName(ScreenSetPage);
    } // setupUi

    void retranslateUi(QWidget *ScreenSetPage)
    {
        ScreenSetPage->setWindowTitle(QApplication::translate("ScreenSetPage", "Form", Q_NULLPTR));
        printerModelLabel->setText(QApplication::translate("ScreenSetPage", "\346\211\223\345\215\260\346\234\272\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        isPrintLabel->setText(QApplication::translate("ScreenSetPage", "\346\230\257\345\220\246\346\211\223\345\215\260\357\274\232", Q_NULLPTR));
        numberScreenRButton->setText(QApplication::translate("ScreenSetPage", " \346\225\260\345\255\227\345\256\242\346\230\276", Q_NULLPTR));
        colorScreenRButton->setText(QApplication::translate("ScreenSetPage", " \345\275\251\345\261\217\345\256\242\346\230\276", Q_NULLPTR));
        printerTestButton->setText(QApplication::translate("ScreenSetPage", "\346\265\213\350\257\225", Q_NULLPTR));
        noPrintButton->setText(QApplication::translate("ScreenSetPage", "\345\220\246", Q_NULLPTR));
        noScreenRButton->setText(QApplication::translate("ScreenSetPage", " \346\227\240\345\256\242\346\230\276\350\256\276\345\244\207", Q_NULLPTR));
        customerDisplayTypeLabel->setText(QApplication::translate("ScreenSetPage", "\345\256\242\346\230\276\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        englishScreenRButton->setText(QApplication::translate("ScreenSetPage", " \350\213\261\346\226\207\345\256\242\346\230\276", Q_NULLPTR));
        chineseScreenRButton->setText(QApplication::translate("ScreenSetPage", " \344\270\255\346\226\207\345\256\242\346\230\276", Q_NULLPTR));
        yesPrintButton->setText(QApplication::translate("ScreenSetPage", "\346\230\257", Q_NULLPTR));
        addADButton->setText(QString());
        localUploadLabel->setText(QApplication::translate("ScreenSetPage", "\346\234\254\345\234\260\344\270\212\344\274\240\357\274\232", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        headquartersUploadLabel->setText(QApplication::translate("ScreenSetPage", "\346\200\273\351\203\250\344\270\212\344\274\240\357\274\232", Q_NULLPTR));
        eleScalePortLabel->setText(QApplication::translate("ScreenSetPage", "\347\224\265\345\255\220\347\247\244\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        customerModelLabel->setText(QApplication::translate("ScreenSetPage", "\345\256\242\346\230\276\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        cardReaderPortLabel->setText(QApplication::translate("ScreenSetPage", "\350\257\273\345\215\241\345\231\250\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        cardReaderTestButton->setText(QApplication::translate("ScreenSetPage", "\346\265\213\350\257\225", Q_NULLPTR));
        cardReaderModelLabel->setText(QApplication::translate("ScreenSetPage", "\350\257\273\345\215\241\345\231\250\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        customerPortLabel->setText(QApplication::translate("ScreenSetPage", "\345\256\242\346\230\276\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        clientScreenPortTestButton->setText(QApplication::translate("ScreenSetPage", "\346\265\213\350\257\225", Q_NULLPTR));
        eleScaleModelLabel->setText(QApplication::translate("ScreenSetPage", "\347\224\265\345\255\220\347\247\244\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScreenSetPage: public Ui_ScreenSetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSETPAGE_H
