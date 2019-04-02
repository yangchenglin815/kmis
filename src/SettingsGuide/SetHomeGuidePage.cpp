#include "SetHomeGuidePage.h"
#include "ui_SetHomeGuidePage.h"

SetHomeGuidePage::SetHomeGuidePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetHomeGuidePage)
{
    ui->setupUi(this);
    setStyleSheet("#widget{border-image:url(:/KPosSetGuideImage/index_sz.png);}");
}

SetHomeGuidePage::~SetHomeGuidePage()
{
    delete ui;
}
