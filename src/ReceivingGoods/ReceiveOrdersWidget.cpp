#include "ReceiveOrdersWidget.h"
#include "ui_ReceiveOrdersWidget.h"
#include "../data/enumData.h"
#include <QMessageBox>
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

ReceiveOrdersWidget::ReceiveOrdersWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReceiveOrdersWidget)
    , m_pCreateDeliveryOrderDlg(NULL)
    , m_sSearchStartDate("")
    , m_sSearchEndDate("")
    , m_pDeliveryOrderCtrl(NULL)
{
    ui->setupUi(this);
    initConnect();
}

ReceiveOrdersWidget::~ReceiveOrdersWidget()
{
    if (m_pCreateDeliveryOrderDlg != NULL)
    {
        m_pCreateDeliveryOrderDlg->deleteLater();
    }
    delete ui;
}

void ReceiveOrdersWidget::test()
{
    clearData();

    getDeliveryOrderList();


//    OrdersInfo ordersInfo;
//    QList<OrdersInfo> ordersInfoList;

//    // 水果--精品水果
//    int nOrderId = 36;
//    ordersInfo.sGoodsNameList<<QStringLiteral("澳橙")<<QStringLiteral("蛇果")<<QStringLiteral("青苹果")
//                                  <<QStringLiteral("凤梨")<<QStringLiteral("金果")<<QStringLiteral("绿果")
//                                 <<QStringLiteral("火龙果");
//    ordersInfo.sPriceList<<"31.60"<<"31.60"<<"31.60"<<"17.60"<<"10.00"<<"31.60"<<"11.00";
//    // 水果--大众水果
//    ordersInfo.sGoodsNameList<<QStringLiteral("沙甜桔")<<QStringLiteral("沙糖桔")<<QStringLiteral("红心柚")
//                                  <<QStringLiteral("黄金柚")<<QStringLiteral("皇冠梨")<<QStringLiteral("猕猴桃")
//                                 <<QStringLiteral("贡桔");
//    ordersInfo.sPriceList<<"5.36"<<"4.00"<<"7.00"<<"2.00"<<"7.96"<<"7.96"<<"7.96";
//    ordersInfo.sProviderName = QStringLiteral("水果供应商");
//    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
//    ordersInfoList.append(ordersInfo);
//    ordersInfo.clear();

//    // 蔬菜--叶菜
//    nOrderId++;
//    ordersInfo.sGoodsNameList<<QStringLiteral("菠菜")<<QStringLiteral("苦苣")<<QStringLiteral("香菜")
//                                  <<QStringLiteral("菜心")<<QStringLiteral("油菜")<<QStringLiteral("小白菜")
//                                 <<QStringLiteral("生菜");
//    ordersInfo.sPriceList<<"5.18"<<"10.78"<<"13.96"<<"9.98"<<"7.50"<<"7.98"<<"7.96";
//    // 蔬菜--根茎
//    ordersInfo.sGoodsNameList<<QStringLiteral("苦苣")<<QStringLiteral("苦瓜")<<QStringLiteral("青萝卜")
//                                  <<QStringLiteral("白萝卜")<<QStringLiteral("藕")<<QStringLiteral("青笋")
//                                 <<QStringLiteral("地瓜");
//    ordersInfo.sPriceList<<"4.80"<<"8.00"<<"0.80"<<"1.30"<<"4.00"<<"2.98"<<"1.60";
//    // 蔬菜--菌菇
//    ordersInfo.sGoodsNameList<<QStringLiteral("白玉菇")<<QStringLiteral("平菇")<<QStringLiteral("海鲜菇")
//                                  <<QStringLiteral("金针菇")<<QStringLiteral("杏鲍菇")<<QStringLiteral("秀珍菇")
//                                 <<QStringLiteral("香菇");
//    ordersInfo.sPriceList<<"15.50"<<"1.00"<<"8.80"<<"6.30"<<"7.30"<<"12.29"<<"7.80";
//    // 蔬菜--咸菜
//    ordersInfo.sGoodsNameList<<QStringLiteral("辣白菜")<<QStringLiteral("八宝菜")<<QStringLiteral("糖蒜")
//                                  <<QStringLiteral("泡椒")<<QStringLiteral("五仁酱丁")<<QStringLiteral("萝卜条")
//                                 <<QStringLiteral("宫廷黄瓜");
//    ordersInfo.sPriceList<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00";
//    ordersInfo.sProviderName = QStringLiteral("蔬菜供应商");
//    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
//    ordersInfoList.append(ordersInfo);
//    ordersInfo.clear();

//    // 甘果--坚果
//    nOrderId++;
//    ordersInfo.sGoodsNameList<<QStringLiteral("云南核桃")<<QStringLiteral("巴旦木")<<QStringLiteral("五香瓜子")
//                                  <<QStringLiteral("东北榛子")<<QStringLiteral("板栗")<<QStringLiteral("碧根果")
//                                 <<QStringLiteral("开心果");
//    ordersInfo.sPriceList<<"39.60"<<"71.60"<<"13.60"<<"59.60"<<"23.60"<<"65.00"<<"96.00";
//    // 甘果--果实
//    ordersInfo.sGoodsNameList<<QStringLiteral("和田枣")<<QStringLiteral("灰枣")<<QStringLiteral("蒜味花生")
//                                  <<QStringLiteral("夏果")<<QStringLiteral("小杏核")<<QStringLiteral("桂圆干");
//    ordersInfo.sPriceList<<"37.60"<<"1.00"<<"13.60"<<"71.60"<<"29.60"<<"1.00";
//    ordersInfo.sProviderName = QStringLiteral("甘果供应商");
//    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
//    ordersInfoList.append(ordersInfo);
//    ordersInfo.clear();

//    // 熟食--熏酱猪货
//    nOrderId++;
//    ordersInfo.sGoodsNameList<<QStringLiteral("猪头肉")<<QStringLiteral("猪肝")<<QStringLiteral("猪耳朵")
//                                  <<QStringLiteral("猪蹄")<<QStringLiteral("猪肘花")<<QStringLiteral("猪肺")
//                                 <<QStringLiteral("猪肉皮");
//    ordersInfo.sPriceList<<"29.98"<<"45.00"<<"65.60"<<"50.00"<<"60.00"<<"19.80"<<"19.80";
//    // 熟食--鸡货
//    ordersInfo.sGoodsNameList<<QStringLiteral("鹌鹑蛋")<<QStringLiteral("扒鸡")<<QStringLiteral("童子鸡")
//                                  <<QStringLiteral("五香鸡")<<QStringLiteral("松花鸡腿")<<QStringLiteral("泡椒凤爪")
//                                 <<QStringLiteral("五香凤爪");
//    ordersInfo.sPriceList<<"32.00"<<"37.60"<<"29.00"<<"28.00"<<"32.00"<<"36.00"<<"36.00";
//    // 熟食--鸭货
//    ordersInfo.sGoodsNameList<<QStringLiteral("鸭胸")<<QStringLiteral("酱鸭")<<QStringLiteral("咸水鸭")
//                                  <<QStringLiteral("鸭翅")<<QStringLiteral("鸭翅中")<<QStringLiteral("白条鸭");
//    ordersInfo.sPriceList<<"19.80"<<"36.00"<<"45.60"<<"49.60"<<"13.60"<<"1.00";
//    // 熟食--肠类
//    ordersInfo.sGoodsNameList<<QStringLiteral("肥肠")<<QStringLiteral("白蒜肠")<<QStringLiteral("松仁肚")
//                                  <<QStringLiteral("排骨肠")<<QStringLiteral("麻辣肠")<<QStringLiteral("丹麦肠")
//                                 <<QStringLiteral("哈尔滨红肠");
//    ordersInfo.sPriceList<<"79.60"<<"38.00"<<"32.00"<<"38.00"<<"59.60"<<"19.80"<<"31.60";
//    ordersInfo.sProviderName = QStringLiteral("熟食供应商");
//    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
//    ordersInfoList.append(ordersInfo);
//    ordersInfo.clear();

//    // 牛羊肉--牛肉
//    nOrderId++;
//    ordersInfo.sGoodsNameList<<QStringLiteral("牛上脑")<<QStringLiteral("牛腩")<<QStringLiteral("牛肋条")
//                                  <<QStringLiteral("牛腱子")<<QStringLiteral("牛脑心")<<QStringLiteral("金钱腱")
//                                 <<QStringLiteral("牛林");
//    ordersInfo.sPriceList<<"60.00"<<"51.60"<<"55.00"<<"57.80"<<"76.00"<<"76.00"<<"57.00";
//    // 牛羊肉--羊肉
//    ordersInfo.sGoodsNameList<<QStringLiteral("羊排")<<QStringLiteral("羊蝎子")<<QStringLiteral("羊肉")
//                                  <<QStringLiteral("羊蹄子")<<QStringLiteral("羊里脊")<<QStringLiteral("羊肝")
//                                 <<QStringLiteral("羊肚");
//    ordersInfo.sPriceList<<"41.80"<<"21.60"<<"1.00"<<"25.00"<<"69.60"<<"16.00"<<"25.00";
//    ordersInfo.sProviderName = QStringLiteral("牛羊肉供应商");
//    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
//    ordersInfoList.append(ordersInfo);
//    ordersInfo.clear();

//    // 水产--活鲜
//    nOrderId++;
//    ordersInfo.sGoodsNameList<<QStringLiteral("岛子鱼")<<QStringLiteral("海鲈鱼")<<QStringLiteral("百花鱼")
//                                  <<QStringLiteral("鲜多宝")<<QStringLiteral("三文鱼")<<QStringLiteral("海桂鱼")
//                                 <<QStringLiteral("毛蛤");
//    ordersInfo.sPriceList<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00";
//    // 水产--冰鲜
//    ordersInfo.sGoodsNameList<<QStringLiteral("鱿鱼圈")<<QStringLiteral("冻金昌鱼")<<QStringLiteral("秋刀鱼")
//                                  <<QStringLiteral("黄蚬子")<<QStringLiteral("蛏子")<<QStringLiteral("文蛤");
//    ordersInfo.sPriceList<<"17.60"<<"39.60"<<"1.00"<<"1.00"<<"1.00"<<"1.00";
//    ordersInfo.sProviderName = QStringLiteral("水产供应商");
//    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
//    ordersInfoList.append(ordersInfo);
//    ordersInfo.clear();

//    // 豆制品--豆腐
//    nOrderId++;
//    ordersInfo.sGoodsNameList<<QStringLiteral("大豆腐")<<QStringLiteral("干豆腐")<<QStringLiteral("麻豆腐")
//                                  <<QStringLiteral("白玉内脂")<<QStringLiteral("脆皮豆腐")<<QStringLiteral("千叶豆腐")
//                                 <<QStringLiteral("鱼豆腐");
//    ordersInfo.sPriceList<<"2.50"<<"1.00"<<"1.00"<<"3.00"<<"11.96"<<"6.50"<<"1.00";
//    // 豆制品--豆干
//    ordersInfo.sGoodsNameList<<QStringLiteral("五香干")<<QStringLiteral("白干")<<QStringLiteral("香干")
//                                  <<QStringLiteral("熏干")<<QStringLiteral("孜然香干")<<QStringLiteral("麻辣香干");
//    ordersInfo.sPriceList<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00"<<"1.00";
//    ordersInfo.sProviderName = QStringLiteral("豆制品供应商");
//    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
//    ordersInfoList.append(ordersInfo);
//    ordersInfo.clear();

//    // 粮油--大米
//    nOrderId++;
//    ordersInfo.sGoodsNameList<<QStringLiteral("生态长粒香10kg")<<QStringLiteral("松花香10kg")<<QStringLiteral("香香王稻花香5kg")
//                                  <<QStringLiteral("松花江珍珠米25kg")<<QStringLiteral("金龙鱼原香稻米5kg")<<QStringLiteral("香香王稻花香25kg")
//                                 <<QStringLiteral("福临门寒香米5kg");
//    ordersInfo.sPriceList<<"55.00"<<"49.00"<<"35.00"<<"120.00"<<"62.50"<<"120.00"<<"42.00";
//    // 粮油--面食
//    ordersInfo.sGoodsNameList<<QStringLiteral("北京古船富强粉5kg")<<QStringLiteral("五得利金特精高筋小麦粉5kg")<<QStringLiteral("香雪麦纯小麦粉5kg")
//                                  <<QStringLiteral("香雪全麦粉5kg")<<QStringLiteral("利生麦芯粉5kg")<<QStringLiteral("五得利超精小麦粉5kg")
//                                 <<QStringLiteral("香雪麦纯富强粉5kg");
//    ordersInfo.sPriceList<<"20.00"<<"25.00"<<"25.00"<<"25.00"<<"25.00"<<"25.00"<<"25.00";
//    // 粮油--豆油
//    ordersInfo.sGoodsNameList<<QStringLiteral("金龙鱼黄金比例调和油五升")<<QStringLiteral("金龙鱼黄金比例食用调和油900ml")<<QStringLiteral("金龙鱼精炼一级大豆油900ml")
//                                  <<QStringLiteral("鲁花5S压榨一级花生油1L")<<QStringLiteral("鲁花5S压榨一级花生油1.8L")<<QStringLiteral("金龙鱼黄金比例食用调和油1.8L")
//                                 <<QStringLiteral("金龙鱼精炼一级大豆油1.8L");
//    ordersInfo.sPriceList<<"1.00"<<"13.80"<<"1.00"<<"1.00"<<"55.00"<<"25.50"<<"21.00";
//    // 粮油--调料
//    ordersInfo.sGoodsNameList<<QStringLiteral("枸杞")<<QStringLiteral("八角")<<QStringLiteral("花椒")
//                                  <<QStringLiteral("干辣椒")<<QStringLiteral("莲子")<<QStringLiteral("单晶冰糖")
//                                 <<QStringLiteral("大料");
//    ordersInfo.sPriceList<<"76.00"<<"40.00"<<"96.00"<<"33.60"<<"56.00"<<"9.96"<<"1.00";
//    ordersInfo.sProviderName = QStringLiteral("粮油供应商");
//    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
//    ordersInfoList.append(ordersInfo);
//    ordersInfo.clear();

//    // 禽蛋--禽类
//    nOrderId++;
//    ordersInfo.sGoodsNameList<<QStringLiteral("鸭子")<<QStringLiteral("乌鸡")<<QStringLiteral("柴鸡")
//                                  <<QStringLiteral("三黄鸡")<<QStringLiteral("鸡大腿")<<QStringLiteral("鸡翅根")
//                                 <<QStringLiteral("鸡爪");
//    ordersInfo.sPriceList<<"1.00"<<"31.60"<<"27.60"<<"15.00"<<"13.60"<<"19.60"<<"25.00";
//    // 禽蛋--蛋类
//    ordersInfo.sGoodsNameList<<QStringLiteral("鹌鹑蛋")<<QStringLiteral("咸鸭蛋")<<QStringLiteral("生鸭蛋")
//                                  <<QStringLiteral("松花蛋")<<QStringLiteral("鸡蛋")<<QStringLiteral("柴鸡蛋")
//                                 <<QStringLiteral("鸽子蛋");
//    ordersInfo.sPriceList<<"15.00"<<"17.00"<<"15.00"<<"17.60"<<"7.98"<<"8.58"<<"5.50";
//    ordersInfo.sProviderName = QStringLiteral("禽蛋供应商");
//    ordersInfo.sOrderId = QString("201600%1").arg(createTestOrderId(nOrderId));
//    ordersInfoList.append(ordersInfo);
//    ordersInfo.clear();


//    ReceiveOrderInfo* pReceiveOrderInfo = NULL;
//    ReceiveOrderGoodsInfo* pReceiveOrderGoodsInfo = NULL;
//    int nLen1 = ordersInfoList.length();
//    int nLen2 = 0;
//    for (int i = 0; i < nLen1; i++)
//    {
//        ordersInfo = ordersInfoList[i];

//        pReceiveOrderInfo = new ReceiveOrderInfo;
//        pReceiveOrderInfo->sOrderId = QString("201555666%1").arg(i); // 订单号
//        pReceiveOrderInfo->nOrderType = e_orderOrder; // 订单类型
//        pReceiveOrderInfo->sProviderName = ordersInfo.sProviderName; // 提供商名称
//        pReceiveOrderInfo->sProviderCode = ordersInfo.sOrderId; // 提供商编号
//        pReceiveOrderInfo->nNeedReceiveSumNum = 0; // 应收件数
//        pReceiveOrderInfo->fNeedReceiveSumValue = 0; // 应收数量
//        pReceiveOrderInfo->nRealReceiveSumNum = 0; // 实收件数
//        pReceiveOrderInfo->fRealReceiveSumValue = 0; // 实收数量
//        pReceiveOrderInfo->fSumPrice = 0.00f; // 金额
//        pReceiveOrderInfo->sUploadDate = "2016.02.16"; // 上传日期
//        pReceiveOrderInfo->sUploadTime = "12:20"; // 上传时间
//        pReceiveOrderInfo->nRecieveState = e_RecieveGoodsNotStart; // 收货状态 (已完成，收货中，未完成)

//        nLen2 = ordersInfo.sGoodsNameList.length();
//        for (int j = 0; j < nLen2; j++)
//        {
//            pReceiveOrderGoodsInfo = new ReceiveOrderGoodsInfo;
//            pReceiveOrderGoodsInfo->nGoodsId = 1000*i + j; // 商品id
//            pReceiveOrderGoodsInfo->sGoodName = ordersInfo.sGoodsNameList[j]; // 商品名称
//            pReceiveOrderGoodsInfo->sGoodsCode = QString("201555666%1%2").arg(i).arg(j); // 商品编号
//            pReceiveOrderGoodsInfo->sUnitSpecification = QString(QStringLiteral("%1.66公斤")).arg(j); // 规格单位
//            pReceiveOrderGoodsInfo->fUnitSpecificationValue = QString("%1.66").arg(j).toFloat(); // 规格单位值
//            pReceiveOrderGoodsInfo->sSpecification = QStringLiteral("箱"); // 规格
//            pReceiveOrderGoodsInfo->nNeedReceiveSumNum = 2 + qrand()%20; // 应收件数
//            pReceiveOrderInfo->nNeedReceiveSumNum += pReceiveOrderGoodsInfo->nNeedReceiveSumNum;
//            pReceiveOrderGoodsInfo->fNeedReceiveSumValue = pReceiveOrderGoodsInfo->nNeedReceiveSumNum * pReceiveOrderGoodsInfo->fUnitSpecificationValue; // 应收数量
//            pReceiveOrderInfo->fNeedReceiveSumValue += pReceiveOrderGoodsInfo->fNeedReceiveSumValue;
//            pReceiveOrderGoodsInfo->nRealReceiveSumNum = 0; // 实收件数
//            pReceiveOrderGoodsInfo->fRealReceiveSumValue = 0.00f; // 实收数量
//            pReceiveOrderGoodsInfo->fSumPrice = 0.00f; // 收货金额
//            pReceiveOrderGoodsInfo->bGoodsRecieveSave = false; // 收货商品是否保存
//            if (j % 2 == 0)
//            {
//                pReceiveOrderGoodsInfo->bStandardGoods = true;
//            }
//            else
//            {
//                pReceiveOrderGoodsInfo->bStandardGoods = false;
//            }

//            if (pReceiveOrderGoodsInfo->bStandardGoods)
//            {
//                pReceiveOrderGoodsInfo->standardInfo.fStandardWeight = pReceiveOrderGoodsInfo->fUnitSpecificationValue;
//                pReceiveOrderGoodsInfo->standardInfo.nReceiveNum = 0;
//                pReceiveOrderGoodsInfo->standardInfo.fReciveSumValue = 0.0f;
//                pReceiveOrderGoodsInfo->standardInfo.fPrice = 0.0f;
//            }
//            else
//            {
//                pReceiveOrderGoodsInfo->noStandardInfo.fAllWeidght = pReceiveOrderGoodsInfo->fUnitSpecificationValue;
//                pReceiveOrderGoodsInfo->noStandardInfo.fPeelWeight = 0.0f;
//                pReceiveOrderGoodsInfo->noStandardInfo.nReceiveNum = 0;
//                pReceiveOrderGoodsInfo->noStandardInfo.fPrice = 0.0f;

//                pReceiveOrderGoodsInfo->disperseInfo.fReciveSumValue = 0.0f;
//                pReceiveOrderGoodsInfo->disperseInfo.fPrice = 0.0f;
//            }

//            pReceiveOrderGoodsInfo->nWeighType = e_receiveWeighNull;
//            pReceiveOrderInfo->receiveOrderGoodsInfoList.append(pReceiveOrderGoodsInfo);
//        }

//        m_receiveOrderInfoList.append(pReceiveOrderInfo);
//    }

//    ui->receiveOrdersMainWidget->initData(m_receiveOrderInfoList);
}

QString ReceiveOrdersWidget::createTestOrderId(int i)
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

void ReceiveOrdersWidget::getDeliveryOrderList()
{
    if (m_pDeliveryOrderCtrl == NULL)
    {
        m_pDeliveryOrderCtrl = new DeliveryOrderCtrl(this);
        qRegisterMetaType<QList<DeliveryOrderInfo_s> >("QList<DeliveryOrderInfo_s>");
        connect(m_pDeliveryOrderCtrl, SIGNAL(sigOnGetDeliveryOrderList(int,QString,QList<DeliveryOrderInfo_s>))
                , this, SLOT(slot_onGetDeliveryOrderList(int,QString,QList<DeliveryOrderInfo_s>)));
        connect(m_pDeliveryOrderCtrl, SIGNAL(sigOnStartReceiveGoods(int,QString,int)), this, SLOT(slot_onStartReceiveGoods(int,QString,int)));

        connect(m_pDeliveryOrderCtrl, SIGNAL(sigOnGetDeliveryDetail(int,QString,QList<DeliveryOrderDetailInfo_s>,int))
                , this, SLOT(slot_onGetDeliveryDetail(int,QString,QList<DeliveryOrderDetailInfo_s>,int)));

        ui->checkPage->initCtrl(m_pDeliveryOrderCtrl);
    }
    m_pDeliveryOrderCtrl->getDeliveryOrderListRequest(m_sSearchStartDate, m_sSearchEndDate);
}

void ReceiveOrdersWidget::clearData()
{
    int nLen1 = m_receiveOrderInfoList.length();
    int nLen2 = 0;
    ReceiveOrderInfo* pReceiveOrderInfo = NULL;
    ReceiveOrderGoodsInfo* pReceiveOrderGoodsInfo = NULL;
    for (int i = 0; i < nLen1; i++)
    {
        pReceiveOrderInfo = m_receiveOrderInfoList[i];
        nLen2 = pReceiveOrderInfo->receiveOrderGoodsInfoList.length();
        for (int j = 0; j < nLen2; j++)
        {
            pReceiveOrderGoodsInfo = pReceiveOrderInfo->receiveOrderGoodsInfoList[j];
            delete pReceiveOrderGoodsInfo;
        }
        delete pReceiveOrderInfo;
    }
    m_receiveOrderInfoList.clear();
}

void ReceiveOrdersWidget::slot_search(QString providerText, QString receiptTypeText, QString dateStartText, QString dateEndText)
{
    Q_UNUSED( providerText )
    Q_UNUSED( receiptTypeText )
    Q_UNUSED( dateStartText )
    Q_UNUSED( dateEndText )
}

void ReceiveOrdersWidget::slot_checkReceiveOrder(int nOrderId)
{
    if (m_pDeliveryOrderCtrl != NULL)
    {
        m_pDeliveryOrderCtrl->startReceiveGoodsRequest(nOrderId);
    }
}

void ReceiveOrdersWidget::slot_back()
{
    ui->receiveOrdersMainWidget->updateData();
    ui->stackedWidget->setCurrentWidget(ui->receivePage);
}

void ReceiveOrdersWidget::slot_returnClicked()
{
    if (ui->stackedWidget->currentWidget() == ui->checkPage)
    {
        slot_back();
    }
    else
    {
        emit sigReturnClicked();
    }
}

void ReceiveOrdersWidget::slot_createOrder(ReceiveProviderInfo receiveProviderInfo)
{
////    ReceiveOrderInfo*

//    ReceiveOrderInfo* pReceiveOrderInfo = NULL;
//    ReceiveOrderGoodsInfo* pReceiveOrderGoodsInfo = NULL;
//    pReceiveOrderInfo = new ReceiveOrderInfo;

//    *pReceiveOrderInfo = receiveProviderInfo;
//    int nLen = receiveProviderInfo.receiveOrderGoodsInfoList.length();
//    pReceiveOrderInfo->receiveOrderGoodsInfoList.clear();
//    for (int i = 0; i < nLen; i++)
//    {
//        pReceiveOrderGoodsInfo = new ReceiveOrderGoodsInfo;
//        *pReceiveOrderGoodsInfo = *receiveProviderInfo.receiveOrderGoodsInfoList[i];
//        pReceiveOrderInfo->receiveOrderGoodsInfoList.append(pReceiveOrderGoodsInfo);
//    }

//    m_receiveOrderInfoList.append(pReceiveOrderInfo);
//    ui->receiveOrdersMainWidget->appendData(pReceiveOrderInfo);

    static int index = 0;
    index++;
    ReceiveOrderInfo *pReceiveOrderInfo = new ReceiveOrderInfo;
    pReceiveOrderInfo->sCode = QString("11115666%1").arg(index); // 订单号 ,应该从后台取
    pReceiveOrderInfo->nOrderType = e_orderOrder; // 订单类型
    pReceiveOrderInfo->sProviderName = receiveProviderInfo.sName; // 提供商名称
    pReceiveOrderInfo->sProviderCode = receiveProviderInfo.sCode; // 提供商编号
    pReceiveOrderInfo->nNeedReceiveSumNum = 0; // 应收件数
    pReceiveOrderInfo->fNeedReceiveSumValue = 0; // 应收数量
    pReceiveOrderInfo->nRealReceiveSumNum = 0; // 实收件数
    pReceiveOrderInfo->fRealReceiveSumValue = 0; // 实收数量
    pReceiveOrderInfo->fSumPrice = 0.00f; // 金额
    pReceiveOrderInfo->sUploadDate = "2016.02.16"; // 上传日期
    pReceiveOrderInfo->sUploadTime = "12:20"; // 上传时间
    pReceiveOrderInfo->nRecieveState = e_RecieveOrderNotStart; // 收货状态 (已完成，收货中，未完成)

    int nLen = receiveProviderInfo.goodsForCreateInfoList.length();
    GoodsForCreateInfo* pGoodsForCreateInfo = NULL;
    ReceiveOrderGoodsInfo *pReceiveOrderGoodsInfo = NULL;
    for (int i = 0; i < nLen; i++)
    {
        pGoodsForCreateInfo = receiveProviderInfo.goodsForCreateInfoList[i];

        pReceiveOrderGoodsInfo = new ReceiveOrderGoodsInfo;
        pReceiveOrderGoodsInfo->nGoodsId = pGoodsForCreateInfo->nGoodsId; // 商品id
        pReceiveOrderGoodsInfo->sGoodName = pGoodsForCreateInfo->sGoodName; // 商品名称
        pReceiveOrderGoodsInfo->sGoodsCode = pGoodsForCreateInfo->sGoodsCode; // 商品编号
        pReceiveOrderGoodsInfo->sUnitSpecification = pGoodsForCreateInfo->sUnitSpecification; // 规格单位
        pReceiveOrderGoodsInfo->fUnitSpecificationValue = pGoodsForCreateInfo->fUnitSpecificationValue; // 规格单位值
//        pReceiveOrderGoodsInfo->sSpecification = pGoodsForCreateInfo->sSpecification; // 规格
        pReceiveOrderGoodsInfo->nNeedReceiveSumNum = 0; // 应收件数
        pReceiveOrderGoodsInfo->fNeedReceiveSumValue = 0; // 应收数量
        pReceiveOrderGoodsInfo->nRealReceiveSumNum = 0; // 实收件数
        pReceiveOrderGoodsInfo->fRealReceiveSumValue = 0.00f; // 实收数量
        pReceiveOrderGoodsInfo->fSumPrice = 0.00f; // 收货金额
        pReceiveOrderGoodsInfo->bGoodsRecieveFinish = false; // 收货商品是否保存
        pReceiveOrderGoodsInfo->bStandardGoods = pGoodsForCreateInfo->bStandardGoods;
        if (pReceiveOrderGoodsInfo->bStandardGoods)
        {
            pReceiveOrderGoodsInfo->standardInfo.fStandardWeight = pReceiveOrderGoodsInfo->fUnitSpecificationValue;
            pReceiveOrderGoodsInfo->standardInfo.nReceiveNum = 0;
            pReceiveOrderGoodsInfo->standardInfo.fReciveSumValue = 0.0f;
            pReceiveOrderGoodsInfo->standardInfo.fPrice = 0.0f;
        }
        else
        {
            pReceiveOrderGoodsInfo->noStandardInfo.fAllWeidght = pReceiveOrderGoodsInfo->fUnitSpecificationValue;
            pReceiveOrderGoodsInfo->noStandardInfo.fPeelWeight = 0.0f;
            pReceiveOrderGoodsInfo->noStandardInfo.nReceiveNum = 0;
            pReceiveOrderGoodsInfo->noStandardInfo.fPrice = 0.0f;

            pReceiveOrderGoodsInfo->disperseInfo.fReciveSumValue = 0.0f;
            pReceiveOrderGoodsInfo->disperseInfo.fPrice = 0.0f;
        }

        pReceiveOrderGoodsInfo->nWeighType = e_receiveWeighNull;
        pReceiveOrderInfo->receiveOrderGoodsInfoList.append(pReceiveOrderGoodsInfo);
    }

    ui->receiveOrdersMainWidget->appendData(pReceiveOrderInfo);
    m_receiveOrderInfoList.append(pReceiveOrderInfo);
}

void ReceiveOrdersWidget::slot_createDeliveryOrder()
{
    if (m_pCreateDeliveryOrderDlg == NULL)
    {
        m_pCreateDeliveryOrderDlg = new CreateDeliveryOrderDlg;
        qRegisterMetaType<ReceiveProviderInfo>("ReceiveProviderInfo");
        connect(m_pCreateDeliveryOrderDlg, SIGNAL(sigCreateOrder(ReceiveProviderInfo)),
                                this, SLOT(slot_createOrder(ReceiveProviderInfo)));
    }
    QPoint globalPoint = this->mapToGlobal(QPoint(0, 0));
    int nXPos = globalPoint.x() + (this->width() - m_pCreateDeliveryOrderDlg->width()) / 2;
    int nYPos = globalPoint.y() + (this->height() - m_pCreateDeliveryOrderDlg->height()) / 2;
    m_pCreateDeliveryOrderDlg->move(nXPos, nYPos);
    m_pCreateDeliveryOrderDlg->showProviderPage();
    m_pCreateDeliveryOrderDlg->showNormal();
}

void ReceiveOrdersWidget::slot_onGetDeliveryOrderList(int nCode, QString sMsg, QList<DeliveryOrderInfo_s> deliveryOrderInfoList)
{
    if (nCode != e_success)
    {
        QMessageBox::information(this, QStringLiteral("提示")
                                 , QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
        return;
    }

    ReceiveOrderInfo* pReceiveOrderInfo = NULL;
    int nLen = deliveryOrderInfoList.length();
    for (int i = 0; i < nLen; i++)
    {
        DeliveryOrderInfo_s &deliveryOrderInfo_s = deliveryOrderInfoList[i];

        pReceiveOrderInfo = new ReceiveOrderInfo;
        pReceiveOrderInfo->nId = deliveryOrderInfo_s.nId; // 送货单id
        pReceiveOrderInfo->sCode = deliveryOrderInfo_s.sCode; // 送货单编号
        pReceiveOrderInfo->nOrderType = deliveryOrderInfo_s.nOrderType; // 订单类型
        pReceiveOrderInfo->sProviderName = deliveryOrderInfo_s.sProviderName; // 提供商名称
        pReceiveOrderInfo->sProviderCode = deliveryOrderInfo_s.sProviderCode; // 提供商编号
        pReceiveOrderInfo->nNeedReceiveSumNum = deliveryOrderInfo_s.nNeedReceiveSumNum; // 应收件数
        pReceiveOrderInfo->fNeedReceiveSumValue = deliveryOrderInfo_s.fNeedReceiveSumValue; // 应收数量
        pReceiveOrderInfo->nRealReceiveSumNum = deliveryOrderInfo_s.nRealReceiveSumNum; // 实收件数
        pReceiveOrderInfo->fRealReceiveSumValue = deliveryOrderInfo_s.fRealReceiveSumValue; // 实收数量
        pReceiveOrderInfo->fSumPrice = deliveryOrderInfo_s.fSumPrice; // 金额
        pReceiveOrderInfo->sUploadDate = deliveryOrderInfo_s.sUploadDate; // 上传日期
        pReceiveOrderInfo->sUploadTime = deliveryOrderInfo_s.sUploadTime; // 上传时间
        pReceiveOrderInfo->nRecieveState = deliveryOrderInfo_s.nRecieveState; // 收货状态 (已完成，收货中，未完成)
        m_receiveOrderInfoList.append(pReceiveOrderInfo);
    }
    ui->receiveOrdersMainWidget->initData(m_receiveOrderInfoList);
}

void ReceiveOrdersWidget::slot_onStartReceiveGoods(int nCode, QString sMsg, int nDeliveryId)
{
    if (nCode != e_success)
    {
        QMessageBox::information(this, QStringLiteral("提示")
                                 , QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
        return;
    }

    if (m_pDeliveryOrderCtrl != NULL)
    {
        m_pDeliveryOrderCtrl->getDeliveryDetailRequest(nDeliveryId);
    }
}

void ReceiveOrdersWidget::slot_onGetDeliveryDetail(int nCode, QString sMsg, QList<DeliveryOrderDetailInfo_s> deliveryOrderDetailInfoList, int nDeliveryId)
{
    if (nCode != e_success)
    {
        QMessageBox::information(this, QStringLiteral("提示")
                                 , QString(QStringLiteral("出现异常--错误码:%1, 错误信息:%2")).arg(nCode).arg(sMsg));
        return;
    }

    int nLen = m_receiveOrderInfoList.length();
    ReceiveOrderInfo* pReceiveOrderInfo = NULL;
    for (int i = 0; i < nLen; i++)
    {
        pReceiveOrderInfo = m_receiveOrderInfoList[i];
        if (pReceiveOrderInfo->nId == nDeliveryId)
        {
            ui->checkPage->initData(deliveryOrderDetailInfoList, pReceiveOrderInfo);
            ui->stackedWidget->setCurrentWidget(ui->checkPage);
        }
    }
}

void ReceiveOrdersWidget::initConnect()
{
    connect(ui->receiveOrdersTopWidget, SIGNAL(sigSearch(QString,QString,QString,QString)), this, SLOT(slot_search(QString,QString,QString,QString)));
    connect(ui->receiveOrdersMainWidget, SIGNAL(sigCheckReceiveOrder(int)), this, SLOT(slot_checkReceiveOrder(int)));
    connect(ui->receiveOrdersMainWidget, SIGNAL(sigCreateDeliveryOrder()), this, SLOT(slot_createDeliveryOrder()));
    connect(ui->checkPage, SIGNAL(sigBack()), this, SLOT(slot_back()));
    connect(ui->titleWidget, SIGNAL(sigReturnClicked()), this, SLOT(slot_returnClicked()));
}
