#include "CreateDeliveryOrderDlg.h"
#include "ui_CreateDeliveryOrderDlg.h"
#include <QDebug>

struct OrdersInfo
{
    QString sProviderName;
    QString sOrderId;
    QList<QString> sGoodsNameList;
    QList<QString> sPriceList;
    void clear()
    {
        sGoodsNameList.clear();
        sPriceList.clear();
    }
};

CreateDeliveryOrderDlg::CreateDeliveryOrderDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateDeliveryOrderDlg)
    , m_pSelectedReceiveProviderInfo(NULL)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->titleWidget->setTitleText(QStringLiteral("创建手工收货单"));
    initConnect();
    test();
}

CreateDeliveryOrderDlg::~CreateDeliveryOrderDlg()
{
    delete ui;
}

void CreateDeliveryOrderDlg::showProviderPage()
{
    ui->stackedWidget->setCurrentWidget(ui->providerPage);
}

void CreateDeliveryOrderDlg::test()
{
//    ReceiveProviderInfo* pReceiveProviderInfo = NULL;
//    GoodsForCreateInfo* pGoodsForCreateInfo = NULL;
//    clearData();
//    for (int i = 0; i < 20; i++)
//    {
//        pReceiveProviderInfo = new ReceiveProviderInfo;
//        pReceiveProviderInfo->nId = i;
//        pReceiveProviderInfo->sName = QString(QStringLiteral("德州电锯供应商%1")).arg(i);
//        pReceiveProviderInfo->sCode = QString("GY201500122%1").arg(i);
//        for (int j = 0; j < 20; j++)
//        {
//            pGoodsForCreateInfo = new GoodsForCreateInfo;
//            pGoodsForCreateInfo->nGoodsId = j;
//            pGoodsForCreateInfo->sGoodName = QString(QStringLiteral("爽口大栗子%1")).arg(j);
//            pGoodsForCreateInfo->sGoodsCode = QString("23215455666%1").arg(j);
//            pGoodsForCreateInfo->sUnitSpecification = QString(QStringLiteral("%1.11公斤")).arg(j);
//            pGoodsForCreateInfo->fUnitSpecificationValue = QString("%1.11").arg(j).toFloat();
//            pGoodsForCreateInfo->sSpecification = QStringLiteral("箱");
//            if (j % 2 == 0)
//            {
//                pGoodsForCreateInfo->bStandardGoods = true;
//            }
//            else
//            {
//                pGoodsForCreateInfo->bStandardGoods = false;
//            }
//            pReceiveProviderInfo->goodsForCreateInfoList.append(pGoodsForCreateInfo);
//        }
//        m_receiveProviderInfoList.append(pReceiveProviderInfo);
//    }
//    ui->providerPage->initData(m_receiveProviderInfoList);

    OrdersInfo ordersInfo;
    QList<OrdersInfo> ordersInfoList;

    // 水果--精品水果
    int nOrderId = 36;
    ordersInfo.sGoodsNameList<<QStringLiteral("澳橙")<<QStringLiteral("蛇果")<<QStringLiteral("青苹果")
                                  <<QStringLiteral("凤梨")<<QStringLiteral("金果")<<QStringLiteral("绿果")
                                 <<QStringLiteral("火龙果");
    ordersInfo.sPriceList<<"31.60"<<"31.60"<<"31.60"<<"17.60"<<"10.00"<<"31.60"<<"11.00";
    // 水果--大众水果
    ordersInfo.sGoodsNameList<<QStringLiteral("沙甜桔")<<QStringLiteral("沙糖桔")<<QStringLiteral("红心柚")
                                  <<QStringLiteral("黄金柚")<<QStringLiteral("皇冠梨")<<QStringLiteral("猕猴桃")
                                 <<QStringLiteral("贡桔");
    ordersInfo.sPriceList<<"5.36"<<"4.00"<<"7.00"<<"2.00"<<"7.96"<<"7.96"<<"7.96";
    ordersInfo.sProviderName = QStringLiteral("水果供应商");
    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
    ordersInfoList.append(ordersInfo);
    ordersInfo.clear();

    // 蔬菜--叶菜
    nOrderId++;
    ordersInfo.sGoodsNameList<<QStringLiteral("菠菜")<<QStringLiteral("苦苣")<<QStringLiteral("香菜")
                                  <<QStringLiteral("菜心")<<QStringLiteral("油菜")<<QStringLiteral("小白菜")
                                 <<QStringLiteral("生菜");
    ordersInfo.sPriceList<<"5.18"<<"10.78"<<"13.96"<<"9.98"<<"7.50"<<"7.98"<<"7.96";
    // 蔬菜--根茎
    ordersInfo.sGoodsNameList<<QStringLiteral("苦苣")<<QStringLiteral("苦瓜")<<QStringLiteral("青萝卜")
                                  <<QStringLiteral("白萝卜")<<QStringLiteral("藕")<<QStringLiteral("青笋")
                                 <<QStringLiteral("地瓜");
    ordersInfo.sPriceList<<"4.80"<<"8.00"<<"0.80"<<"1.30"<<"4.00"<<"2.98"<<"1.60";
    // 蔬菜--菌菇
    ordersInfo.sGoodsNameList<<QStringLiteral("白玉菇")<<QStringLiteral("平菇")<<QStringLiteral("海鲜菇")
                                  <<QStringLiteral("金针菇")<<QStringLiteral("杏鲍菇")<<QStringLiteral("秀珍菇")
                                 <<QStringLiteral("香菇");
    ordersInfo.sPriceList<<"15.50"<<"1.00"<<"8.80"<<"6.30"<<"7.30"<<"12.29"<<"7.80";
    // 蔬菜--咸菜
    ordersInfo.sGoodsNameList<<QStringLiteral("辣白菜")<<QStringLiteral("八宝菜")<<QStringLiteral("糖蒜")
                                  <<QStringLiteral("泡椒")<<QStringLiteral("五仁酱丁")<<QStringLiteral("萝卜条")
                                 <<QStringLiteral("宫廷黄瓜");
    ordersInfo.sPriceList<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00";
    ordersInfo.sProviderName = QStringLiteral("蔬菜供应商");
    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
    ordersInfoList.append(ordersInfo);
    ordersInfo.clear();

    // 甘果--坚果
    nOrderId++;
    ordersInfo.sGoodsNameList<<QStringLiteral("云南核桃")<<QStringLiteral("巴旦木")<<QStringLiteral("五香瓜子")
                                  <<QStringLiteral("东北榛子")<<QStringLiteral("板栗")<<QStringLiteral("碧根果")
                                 <<QStringLiteral("开心果");
    ordersInfo.sPriceList<<"39.60"<<"71.60"<<"13.60"<<"59.60"<<"23.60"<<"65.00"<<"96.00";
    // 甘果--果实
    ordersInfo.sGoodsNameList<<QStringLiteral("和田枣")<<QStringLiteral("灰枣")<<QStringLiteral("蒜味花生")
                                  <<QStringLiteral("夏果")<<QStringLiteral("小杏核")<<QStringLiteral("桂圆干");
    ordersInfo.sPriceList<<"37.60"<<"1.00"<<"13.60"<<"71.60"<<"29.60"<<"1.00";
    ordersInfo.sProviderName = QStringLiteral("甘果供应商");
    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
    ordersInfoList.append(ordersInfo);
    ordersInfo.clear();

    // 熟食--熏酱猪货
    nOrderId++;
    ordersInfo.sGoodsNameList<<QStringLiteral("猪头肉")<<QStringLiteral("猪肝")<<QStringLiteral("猪耳朵")
                                  <<QStringLiteral("猪蹄")<<QStringLiteral("猪肘花")<<QStringLiteral("猪肺")
                                 <<QStringLiteral("猪肉皮");
    ordersInfo.sPriceList<<"29.98"<<"45.00"<<"65.60"<<"50.00"<<"60.00"<<"19.80"<<"19.80";
    // 熟食--鸡货
    ordersInfo.sGoodsNameList<<QStringLiteral("鹌鹑蛋")<<QStringLiteral("扒鸡")<<QStringLiteral("童子鸡")
                                  <<QStringLiteral("五香鸡")<<QStringLiteral("松花鸡腿")<<QStringLiteral("泡椒凤爪")
                                 <<QStringLiteral("五香凤爪");
    ordersInfo.sPriceList<<"32.00"<<"37.60"<<"29.00"<<"28.00"<<"32.00"<<"36.00"<<"36.00";
    // 熟食--鸭货
    ordersInfo.sGoodsNameList<<QStringLiteral("鸭胸")<<QStringLiteral("酱鸭")<<QStringLiteral("咸水鸭")
                                  <<QStringLiteral("鸭翅")<<QStringLiteral("鸭翅中")<<QStringLiteral("白条鸭");
    ordersInfo.sPriceList<<"19.80"<<"36.00"<<"45.60"<<"49.60"<<"13.60"<<"1.00";
    // 熟食--肠类
    ordersInfo.sGoodsNameList<<QStringLiteral("肥肠")<<QStringLiteral("白蒜肠")<<QStringLiteral("松仁肚")
                                  <<QStringLiteral("排骨肠")<<QStringLiteral("麻辣肠")<<QStringLiteral("丹麦肠")
                                 <<QStringLiteral("哈尔滨红肠");
    ordersInfo.sPriceList<<"79.60"<<"38.00"<<"32.00"<<"38.00"<<"59.60"<<"19.80"<<"31.60";
    ordersInfo.sProviderName = QStringLiteral("熟食供应商");
    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
    ordersInfoList.append(ordersInfo);
    ordersInfo.clear();

    // 牛羊肉--牛肉
    nOrderId++;
    ordersInfo.sGoodsNameList<<QStringLiteral("牛上脑")<<QStringLiteral("牛腩")<<QStringLiteral("牛肋条")
                                  <<QStringLiteral("牛腱子")<<QStringLiteral("牛脑心")<<QStringLiteral("金钱腱")
                                 <<QStringLiteral("牛林");
    ordersInfo.sPriceList<<"60.00"<<"51.60"<<"55.00"<<"57.80"<<"76.00"<<"76.00"<<"57.00";
    // 牛羊肉--羊肉
    ordersInfo.sGoodsNameList<<QStringLiteral("羊排")<<QStringLiteral("羊蝎子")<<QStringLiteral("羊肉")
                                  <<QStringLiteral("羊蹄子")<<QStringLiteral("羊里脊")<<QStringLiteral("羊肝")
                                 <<QStringLiteral("羊肚");
    ordersInfo.sPriceList<<"41.80"<<"21.60"<<"1.00"<<"25.00"<<"69.60"<<"16.00"<<"25.00";
    ordersInfo.sProviderName = QStringLiteral("牛羊肉供应商");
    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
    ordersInfoList.append(ordersInfo);
    ordersInfo.clear();

    // 水产--活鲜
    nOrderId++;
    ordersInfo.sGoodsNameList<<QStringLiteral("岛子鱼")<<QStringLiteral("海鲈鱼")<<QStringLiteral("百花鱼")
                                  <<QStringLiteral("鲜多宝")<<QStringLiteral("三文鱼")<<QStringLiteral("海桂鱼")
                                 <<QStringLiteral("毛蛤");
    ordersInfo.sPriceList<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00";
    // 水产--冰鲜
    ordersInfo.sGoodsNameList<<QStringLiteral("鱿鱼圈")<<QStringLiteral("冻金昌鱼")<<QStringLiteral("秋刀鱼")
                                  <<QStringLiteral("黄蚬子")<<QStringLiteral("蛏子")<<QStringLiteral("文蛤");
    ordersInfo.sPriceList<<"17.60"<<"39.60"<<"1.00"<<"1.00"<<"1.00"<<"1.00";
    ordersInfo.sProviderName = QStringLiteral("水产供应商");
    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
    ordersInfoList.append(ordersInfo);
    ordersInfo.clear();

    // 豆制品--豆腐
    nOrderId++;
    ordersInfo.sGoodsNameList<<QStringLiteral("大豆腐")<<QStringLiteral("干豆腐")<<QStringLiteral("麻豆腐")
                                  <<QStringLiteral("白玉内脂")<<QStringLiteral("脆皮豆腐")<<QStringLiteral("千叶豆腐")
                                 <<QStringLiteral("鱼豆腐");
    ordersInfo.sPriceList<<"2.50"<<"1.00"<<"1.00"<<"3.00"<<"11.96"<<"6.50"<<"1.00";
    // 豆制品--豆干
    ordersInfo.sGoodsNameList<<QStringLiteral("五香干")<<QStringLiteral("白干")<<QStringLiteral("香干")
                                  <<QStringLiteral("熏干")<<QStringLiteral("孜然香干")<<QStringLiteral("麻辣香干");
    ordersInfo.sPriceList<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00";
    ordersInfo.sProviderName = QStringLiteral("豆制品供应商");
    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
    ordersInfoList.append(ordersInfo);
    ordersInfo.clear();

    // 粮油--大米
    nOrderId++;
    ordersInfo.sGoodsNameList<<QStringLiteral("生态长粒香10kg")<<QStringLiteral("松花香10kg")<<QStringLiteral("香香王稻花香5kg")
                                  <<QStringLiteral("松花江珍珠米25kg")<<QStringLiteral("金龙鱼原香稻米5kg")<<QStringLiteral("香香王稻花香25kg")
                                 <<QStringLiteral("福临门寒香米5kg");
    ordersInfo.sPriceList<<"55.00"<<"49.00"<<"35.00"<<"120.00"<<"62.50"<<"120.00"<<"42.00";
    // 粮油--面食
    ordersInfo.sGoodsNameList<<QStringLiteral("北京古船富强粉5kg")<<QStringLiteral("五得利金特精高筋小麦粉5kg")<<QStringLiteral("香雪麦纯小麦粉5kg")
                                  <<QStringLiteral("香雪全麦粉5kg")<<QStringLiteral("利生麦芯粉5kg")<<QStringLiteral("五得利超精小麦粉5kg")
                                 <<QStringLiteral("香雪麦纯富强粉5kg");
    ordersInfo.sPriceList<<"20.00"<<"25.00"<<"25.00"<<"25.00"<<"25.00"<<"25.00"<<"25.00";
    // 粮油--豆油
    ordersInfo.sGoodsNameList<<QStringLiteral("金龙鱼黄金比例调和油五升")<<QStringLiteral("金龙鱼黄金比例食用调和油900ml")<<QStringLiteral("金龙鱼精炼一级大豆油900ml")
                                  <<QStringLiteral("鲁花5S压榨一级花生油1L")<<QStringLiteral("鲁花5S压榨一级花生油1.8L")<<QStringLiteral("金龙鱼黄金比例食用调和油1.8L")
                                 <<QStringLiteral("金龙鱼精炼一级大豆油1.8L");
    ordersInfo.sPriceList<<"1.00"<<"13.80"<<"1.00"<<"1.00"<<"55.00"<<"25.50"<<"21.00";
    // 粮油--调料
    ordersInfo.sGoodsNameList<<QStringLiteral("枸杞")<<QStringLiteral("八角")<<QStringLiteral("花椒")
                                  <<QStringLiteral("干辣椒")<<QStringLiteral("莲子")<<QStringLiteral("单晶冰糖")
                                 <<QStringLiteral("大料");
    ordersInfo.sPriceList<<"76.00"<<"40.00"<<"96.00"<<"33.60"<<"56.00"<<"9.96"<<"1.00";
    ordersInfo.sProviderName = QStringLiteral("粮油供应商");
    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
    ordersInfoList.append(ordersInfo);
    ordersInfo.clear();

    // 禽蛋--禽类
    nOrderId++;
    ordersInfo.sGoodsNameList<<QStringLiteral("鸭子")<<QStringLiteral("乌鸡")<<QStringLiteral("柴鸡")
                                  <<QStringLiteral("三黄鸡")<<QStringLiteral("鸡大腿")<<QStringLiteral("鸡翅根")
                                 <<QStringLiteral("鸡爪");
    ordersInfo.sPriceList<<"1.00"<<"31.60"<<"27.60"<<"15.00"<<"13.60"<<"19.60"<<"25.00";
    // 禽蛋--蛋类
    ordersInfo.sGoodsNameList<<QStringLiteral("鹌鹑蛋")<<QStringLiteral("咸鸭蛋")<<QStringLiteral("生鸭蛋")
                                  <<QStringLiteral("松花蛋")<<QStringLiteral("鸡蛋")<<QStringLiteral("柴鸡蛋")
                                 <<QStringLiteral("鸽子蛋");
    ordersInfo.sPriceList<<"15.00"<<"17.00"<<"15.00"<<"17.60"<<"7.98"<<"8.58"<<"5.50";
    ordersInfo.sProviderName = QStringLiteral("禽蛋供应商");
    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
    ordersInfoList.append(ordersInfo);
    ordersInfo.clear();

    clearData();
    ReceiveProviderInfo* pReceiveProviderInfo = NULL;
    GoodsForCreateInfo* pGoodsForCreateInfo = NULL;
    int nLen1 = ordersInfoList.length();
    int nLen2 = 0;
    for (int i = 0; i < nLen1; i++)
    {
        ordersInfo = ordersInfoList[i];

        pReceiveProviderInfo = new ReceiveProviderInfo;
        pReceiveProviderInfo->nId = i;
        pReceiveProviderInfo->sName = ordersInfo.sProviderName;
        pReceiveProviderInfo->sCode = QString("GY201500122%1").arg(i);

        nLen2 = ordersInfo.sGoodsNameList.length();
        for (int j = 0; j < nLen2; j++)
        {
            pGoodsForCreateInfo = new GoodsForCreateInfo;
            pGoodsForCreateInfo->nGoodsId = j;
            pGoodsForCreateInfo->sGoodName = ordersInfo.sGoodsNameList[j];
            pGoodsForCreateInfo->sGoodsCode = QString("23215455666%1").arg(j);
            pGoodsForCreateInfo->sUnitSpecification = QString(QStringLiteral("%1.11公斤")).arg(j);
            pGoodsForCreateInfo->fUnitSpecificationValue = QString("%1.11").arg(j).toFloat();
            pGoodsForCreateInfo->sSpecification = QStringLiteral("箱");
            if (j % 2 == 0)
            {
                pGoodsForCreateInfo->bStandardGoods = true;
            }
            else
            {
                pGoodsForCreateInfo->bStandardGoods = false;
            }
            pReceiveProviderInfo->goodsForCreateInfoList.append(pGoodsForCreateInfo);
        }
        m_receiveProviderInfoList.append(pReceiveProviderInfo);
    }
    ui->providerPage->initData(m_receiveProviderInfoList);
}

QString CreateDeliveryOrderDlg::createTestOrderId(int i)
{
    if (i >= 0 && i <= 9)
    {
        return QString("000%1").arg(i);
    }
    else if (i >= 10 && i <= 99)
    {
        return QString("00%1").arg(i);
    }
    else if (i >= 100 && i <= 999)
    {
        return QString("0%1").arg(i);
    }
    else if (i >= 1000 && i <= 9999)
    {
        return QString("%1").arg(i);
    }
    else
    {
        return QString::number(i);
    }
}

void CreateDeliveryOrderDlg::slot_clickProvider(int nProviderId)
{
    int nLen = m_receiveProviderInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        if (m_receiveProviderInfoList[i]->nId == nProviderId)
        {
            m_pSelectedReceiveProviderInfo = m_receiveProviderInfoList[i];
            ui->goodsPage->initData(m_pSelectedReceiveProviderInfo->goodsForCreateInfoList);
        }
    }
    ui->stackedWidget->setCurrentWidget(ui->goodsPage);
}

void CreateDeliveryOrderDlg::slot_lastStep()
{
    ui->stackedWidget->setCurrentWidget(ui->providerPage);
}

void CreateDeliveryOrderDlg::slot_searchChanged(QString text)
{
    if (!text.isEmpty())
    {
        int nLen = m_receiveProviderInfoList.length();
        QList<ReceiveProviderInfo*> receiveProviderInfoList;
        for (int i = 0; i < nLen; i++)
        {
            if (m_receiveProviderInfoList[i]->sName.contains(text) ||
                    m_receiveProviderInfoList[i]->sCode.contains(text))
            {
                receiveProviderInfoList.append(m_receiveProviderInfoList[i]);
            }
        }
        ui->providerPage->initData(receiveProviderInfoList);
    }
    else
    {
        ui->providerPage->initData(m_receiveProviderInfoList);
    }
}

void CreateDeliveryOrderDlg::slot_confirmCreateOrder(QList<GoodsForCreateInfo *> goodsForCreateInfoList)
{
    ReceiveProviderInfo pReceiveProviderInfo = *m_pSelectedReceiveProviderInfo;
    pReceiveProviderInfo.goodsForCreateInfoList = goodsForCreateInfoList;
    emit sigCreateOrder(pReceiveProviderInfo);
    this->hide();
}

void CreateDeliveryOrderDlg::initConnect()
{
    connect(ui->titleWidget, SIGNAL(sig_close_wnd()), this, SLOT(hide()));
    connect(ui->providerPage, SIGNAL(sigClickProvider(int)), this, SLOT(slot_clickProvider(int)));
    connect(ui->providerPage, SIGNAL(sigSearchChanged(QString)), this, SLOT(slot_searchChanged(QString)));
    connect(ui->goodsPage, SIGNAL(sigLastStep()), this, SLOT(slot_lastStep()));
    qRegisterMetaType<QList<GoodsForCreateInfo*> >("QList<GoodsForCreateInfo*>");
    connect(ui->goodsPage, SIGNAL(sigConfirmCreateOrder(QList<GoodsForCreateInfo*>)),
            this, SLOT(slot_confirmCreateOrder(QList<GoodsForCreateInfo*>)));
}

void CreateDeliveryOrderDlg::clearData()
{
    int nLen = m_receiveProviderInfoList.length();
    int nLen2 = 0;
    ReceiveProviderInfo* pReceiveProviderInfo;
    QList<GoodsForCreateInfo*> goodsForCreateInfoList;
    for (int i = 0; i < nLen; i++)
    {
        pReceiveProviderInfo = m_receiveProviderInfoList[i];
        goodsForCreateInfoList = pReceiveProviderInfo->goodsForCreateInfoList;
        nLen2 = goodsForCreateInfoList.length();
        for (int j = 0; j < nLen2; j++)
        {
            delete goodsForCreateInfoList[i];
        }
        delete pReceiveProviderInfo;
    }
    m_receiveProviderInfoList.clear();
}
