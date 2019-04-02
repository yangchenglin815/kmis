#include "KPosSetAgent.h"
#include "OnlineStateAgent.h"
#include "../util/HttpSignal.h"
#include "../util/KPosIni.h"
#include "../util/CommonFun.h"
#include "../data/enumData.h"
#include "../HttpClient/HttpClient.h"
#include "ThreadManager.h"
#include "../callOuterDll/ReceiptPictureMaker.h"

KPosSetAgent* KPosSetAgent::m_pInstance = NULL;

KPosSetAgent::KPosSetAgent(QObject *parent) : QObject(parent)
{
    init();
    initConnect();
    moveToThread(ThreadManager::getAgentThread());
    ThreadManager::getAgentThread()->start();
}

KPosSetAgent *KPosSetAgent::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new KPosSetAgent;
    }
    return m_pInstance;
}

void KPosSetAgent::downloadKPosSetRequest(QString sLastTime)
{
    if (OnlineStateAgent::instance()->isOnline())
    {
        HttpClient::instance()->downloadKPosSet(sLastTime);
    }
    else
    {
        emit sigDownloadKPosSetFinished();
    }
}

void KPosSetAgent::uploadKPosSetRequest(const KPosSet &kPosSet, bool bSync)
{
    HttpClient::instance()->uploadKPosSet(kPosSet, bSync);
}

void KPosSetAgent::addCustomCategoryRequest(QString sCategoryName, int nPos)
{
    HttpClient::instance()->addCustomCategory(sCategoryName, nPos);
}

void KPosSetAgent::delCustomCategoryRequest( int nCategroyId )
{
    HttpClient::instance()->deleteCustomCategory( nCategroyId );
}

void KPosSetAgent::getKPosSetInfo(KPosSet &kPosSet)
{
    m_kPosSetLocker.lock();
    kPosSet = m_kPosSet;
    m_kPosSetLocker.unlock();
}

void KPosSetAgent::setKPosSetInfo(const KPosSet &kPosSet)
{
    m_kPosSetLocker.lock();
    m_kPosSet = kPosSet;
    m_kPosSetLocker.unlock();
}

void KPosSetAgent::slot_onDownloadKPosSet(int nCode, QString sMsg, KPosSet kPosSet, QString sUpdateTime)
{
    Q_UNUSED( sMsg )

    m_lockDownDownSetLocker.lock();

    if (nCode == e_success)
    {
        if (!sUpdateTime.isEmpty())
        {
            if (kPosSet.posInfoSet.bChanged)
            {
                m_kPosSet.posInfoSet = kPosSet.posInfoSet;
                emit sigPosInfoChanged();
            }
            if(kPosSet.keySet.bChanged)
            {
                m_kPosSet.keySet = kPosSet.keySet;
                emit sigKeySetChanged();
            }
            if(kPosSet.goodSet.bChanged)
            {
                m_kPosSet.goodSet = kPosSet.goodSet;
                emit sigGoodSetChanged();
            }
            if( kPosSet.screenSet.bChanged )
            {
                m_kPosSet.screenSet = kPosSet.screenSet;
                emit sigScreenSetChanged(m_kPosSet.screenSet);
            }
            if(kPosSet.payWaySet.bChanged || kPosSet.virtualPaySet.bChanged)
            {
                m_kPosSet.payWaySet = kPosSet.payWaySet;
                m_kPosSet.virtualPaySet = kPosSet.virtualPaySet;
                emit sigPayWaySetChanged();
//                kPosSet.payWaySet.bChanged = false;
            }
            if(kPosSet.paramsSet.bChanged)
            {
                KPosIni::setReceiptShopName(kPosSet.paramsSet.shopSetParams.sReceiptShopName);
                m_kPosSet.paramsSet = kPosSet.paramsSet;
                emit sigParamsSetChanged();
            }
            if (kPosSet.receiptSet.bChanged)
            {
                m_kPosSet.receiptSet = kPosSet.receiptSet;
                ReceiptPictureMaker::setReceiptPrintOption(kPosSet.receiptSet);
            }
            if (kPosSet.categoryNodeSet.bChanged)
            {
                m_kPosSet.categoryNodeSet = kPosSet.categoryNodeSet;
            }
            KPosIni::setKPosSetLastUpdateTime(sUpdateTime);
            qDebug()<<QStringLiteral("KPosSetAgent配置下载有变化,%1").arg(sUpdateTime);
        }
        else
        {
            qDebug()<<QStringLiteral("KPosSetAgent成功，但配置下载无变化");
        }
    }
    else
    {
        // 本地操作
        qDebug()<<QStringLiteral("KPosSetAgent异常，配置下载无变化");
    }
    emit sigDownloadKPosSetFinished();

    m_lockDownDownSetLocker.unlock();
}

void KPosSetAgent::slot_onUploadKPosSet(int nCode, QString sMsg, QString sUpdateTime)
{
    Q_UNUSED( sMsg )

    if (nCode == e_success)
    {
        if (!sUpdateTime.isEmpty())
        {
            //KPosIni::setKPosSetLastUpdateTime(sUpdateTime);
        }
        qDebug()<<QString(QStringLiteral("配置上传成功: %1")).arg(sUpdateTime);
        emit sigStartUpdateThread();
    }
    else
    {
        qDebug()<<QStringLiteral("配置上传失败");
    }
}

void KPosSetAgent::slot_onAddCustomCategory(int nCode, QString sMsg, int nCategoryId)
{
    if (nCode == e_success)
    {
        emit sigStartUpdateThread();
    }
    emit sigOnAddCustomCategory(nCode, sMsg, nCategoryId);
}

void KPosSetAgent::slot_onDeleteCustomCategory(int nCode, QString sMsg, int nCategoryId)
{
    if (nCode == e_success)
    {
        emit sigStartUpdateThread();
    }
    emit sigOnDeleteCustomCategory(nCode, sMsg, nCategoryId);
}

void KPosSetAgent::initConnect()
{
    qRegisterMetaType<KPosSet>("KPosSet");
    connect(HttpSignal::instance(), SIGNAL(sigOnDownloadKPosSet(int, QString, KPosSet, QString))
            , this, SLOT(slot_onDownloadKPosSet(int, QString , KPosSet, QString)));
    connect(HttpSignal::instance(), SIGNAL(sigOnUploadKPosSet(int,QString,QString))
            , this, SLOT(slot_onUploadKPosSet(int,QString,QString)));
    connect(HttpSignal::instance(), SIGNAL(sigOnAddCustomCategory(int,QString,int))
            , this, SLOT(slot_onAddCustomCategory(int,QString,int)));
    connect(HttpSignal::instance(), SIGNAL(sigOnDeleteCustomCategory(int,QString,int))
            , this, SLOT(slot_onDeleteCustomCategory(int,QString,int)));
}

void KPosSetAgent::init()
{
    m_kPosSet.posInfoSet.bChanged = true; // Pos机基础信息
    m_kPosSet.keySet.bChanged = true; // 按键设置
    m_kPosSet.goodSet.bChanged = true; // 商品设置
    m_kPosSet.screenSet.bChanged = true; // 外显设置
    m_kPosSet.payWaySet.bChanged = true; // 支付设置
    m_kPosSet.paramsSet.bChanged = true; // 参数设置
    m_kPosSet.receiptSet.bChanged = true;
    initPosInfoSet(); // 初始化Pos信息
    initKeySet(); // 初始化按键列表
    initParamsSet(); // 参数设置初始化
    initPayWaySet(); // 初始化支付设置列表
    initReceiptPrintOption(); // 小票打印选项
}

void KPosSetAgent::initPosInfoSet()
{
    m_kPosSet.posInfoSet.sAppVersion = QString("POS-%1").arg(CommonFun::getAppVersion()); // 程序版本
    m_kPosSet.posInfoSet.sShopCode = KPosIni::getShopCode();  // 门店编号    门店ID
    m_kPosSet.posInfoSet.sShopName = KPosIni::getShopName(); // 门店名称
    m_kPosSet.posInfoSet.sCode = KPosIni::getPosCode(); // pos机编号
}

void KPosSetAgent::initKeySet()
{
    // 初始化按键列表
    QList<int> homeIdList;
    homeIdList<<e_homeMember<<e_homePending<<e_homeCancel<<e_homeTrimMoney<<e_homeDiscount
             <<e_lastReceipt<<e_homeFastCreateDocument<<e_homeTrimBox<<e_homeDiscountAll
             <<e_homePurse<<e_homeRefundGoods<<e_homeLock<<e_homeModifyNum;
    int nHomeLen = homeIdList.length();
    KeySetInfo stKey;
    for (int i = 0; i < nHomeLen; i++)
    {
        stKey.nKeyId = homeIdList[i];
        if ((stKey.nKeyId == e_homeFastCreateDocument)
                || (stKey.nKeyId == e_homeDiscountAll))
        {
           stKey.bStartUsed = false;
        }
        else
        {
            stKey.bStartUsed = true;
        }
        m_kPosSet.keySet.homeKeyList.append(stKey);
    }

    QList<int> refundIdList;
    refundIdList<<e_refundGoods<<e_refundAllGoods<<e_refundModifyNum;
    int nRefundLen = refundIdList.length();
    for (int i = 0; i < nRefundLen; i++)
    {
        stKey.nKeyId = refundIdList[i];
        stKey.bStartUsed = true;
        m_kPosSet.keySet.refundKeyList.append(stKey);
    }
}

void KPosSetAgent::initParamsSet()
{
    // 参数设置初始化
    m_kPosSet.paramsSet.systemSetParams.nDataSaveDays = 3; // 销售数据保存时间
    m_kPosSet.paramsSet.systemSetParams.nGoodsMaxNumber = 1000; // 销售时单品最大数量
    m_kPosSet.paramsSet.systemSetParams.bDiscountOnMember = false; // 会员价打折基础
    m_kPosSet.paramsSet.systemSetParams.bDiscountOnDiscount = true; // 是否可以折上折
    m_kPosSet.paramsSet.systemSetParams.bDiscardZero = true; // 是否可以抹零
    m_kPosSet.paramsSet.systemSetParams.bFillReasonForRefund = false; // 是否选择退货原因

    m_kPosSet.paramsSet.shopSetParams.bChangePriceBySeller = true; // 收银员是否有打折改价权限
    m_kPosSet.paramsSet.shopSetParams.bCreateGoodsBySeller = true; // 是否允许收银员快速建档
    m_kPosSet.paramsSet.shopSetParams.bOpenCashboxBySeller = true; // 只有店长才能打开钱箱
    m_kPosSet.paramsSet.shopSetParams.bSellZeroGoodsBySeller = true; // 前台是否允许销售售价为零的商品
    m_kPosSet.paramsSet.shopSetParams.bHandinCashBySeller = true; // 收银员是否交款
    m_kPosSet.paramsSet.shopSetParams.bChooseSeller = true; // 结算是否选择业务员
    m_kPosSet.paramsSet.shopSetParams.nPendingListMaxLength = 0; // 最大挂单数
    m_kPosSet.paramsSet.shopSetParams.nLockWaitTimeLenth = 0; // 锁屏等待时间
    m_kPosSet.paramsSet.shopSetParams.sReceiptShopName = "";
}

//初始化支付设置
void KPosSetAgent::initPayWaySet()
{
    PayWayInfoSet payWayInfo;
    // 现金支付
    payWayInfo.nPayType = e_PayCash; //现金支付
    payWayInfo.bStartUse = true; // 是否启动
    payWayInfo.bChargeMember = true; // 是否用于会员充值
    payWayInfo.bVirtualPay = false; // 是否虚拟支付
    payWayInfo.nDropType = eRounding; //　分的圆整方式,4表示不处理
    m_kPosSet.payWaySet.payWayInfoSetList.append(payWayInfo);

    // 支付宝
    payWayInfo.nPayType = e_PayAlipay; //支付宝
    payWayInfo.bStartUse = true; // 是否启动
    payWayInfo.bChargeMember = true; // 是否用于会员充值
    payWayInfo.bVirtualPay = false; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
    m_kPosSet.payWaySet.payWayInfoSetList.append(payWayInfo);

    //实体卡
    payWayInfo.nPayType = e_PayEntityCard; //实体卡
    payWayInfo.bStartUse = true; // 是否启动
    payWayInfo.bChargeMember = true; // 是否用于会员充值
    payWayInfo.bVirtualPay = true; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
    m_kPosSet.payWaySet.payWayInfoSetList.append(payWayInfo);

    payWayInfo.nPayType = e_PayVirtual; //虚拟支付
    payWayInfo.bStartUse = true; // 是否启动
    payWayInfo.bChargeMember = true; // 是否用于会员充值
    payWayInfo.bVirtualPay = true; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
    m_kPosSet.payWaySet.payWayInfoSetList.append(payWayInfo);

    // 优惠券支付
    payWayInfo.nPayType = e_PayCoupon;//优惠券
    payWayInfo.bStartUse = true;// 是否启动
    payWayInfo.bChargeMember = false; // 是否用于会员充值
    payWayInfo.bVirtualPay = false; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated;//= 分的圆整方式,4表示不处理
    m_kPosSet.payWaySet.payWayInfoSetList.append(payWayInfo);

//    // 银联支付
//    payWayInfo.nPayType = e_PayUnion; //银联支付
//    payWayInfo.bStartUse = true; // 是否启动
//    payWayInfo.bChargeMember = true; // 是否用于会员充值
//    payWayInfo.bVirtualPay = true; // 是否虚拟支付
//    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
//    m_kPosSet.payWaySet.payWayInfoSetList.append(payWayInfo);

//    // 储值卡
//    payWayInfo.nPayType = e_PayStoreCard; //储值卡
//    payWayInfo.bStartUse = true; // 是否启动
//    payWayInfo.bChargeMember = true; // 是否用于会员充值
//    payWayInfo.bVirtualPay = false; // 是否虚拟支付
//    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
//    m_kPosSet.payWaySet.payWayInfoSetList.append(payWayInfo);

    // 会员卡支付
    payWayInfo.nPayType = e_PayMemCard; //会员卡支付
    payWayInfo.bStartUse = false; // 是否启动
    payWayInfo.bChargeMember = false; // 是否用于会员充值
    payWayInfo.bVirtualPay = false; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
    m_kPosSet.payWaySet.payWayInfoSetList.append( payWayInfo );


    // 微信支付
    payWayInfo.nPayType = e_PayWeChat; //微信支付
    payWayInfo.bStartUse = false; // 是否启动
    payWayInfo.bChargeMember = true; // 是否用于会员充值
    payWayInfo.bVirtualPay = false; // 是否虚拟支付
    payWayInfo.nDropType = eUntreated; //　分的圆整方式,4表示不处理
    m_kPosSet.payWaySet.payWayInfoSetList.append(payWayInfo);
}

void KPosSetAgent::initReceiptPrintOption()
{
    m_kPosSet.receiptSet.sQRCode = "http://www.bejson.com/"; // 二维码数据，后台配置
    m_kPosSet.receiptSet.sHeadContent = QStringLiteral("欢迎光临"); // 头部语，后台配置
    m_kPosSet.receiptSet.sHeadWords = KPosIni::getReceiptShopName(); // 头部文字，后台配置
    m_kPosSet.receiptSet.sTailContent = QStringLiteral("本店商品无质量问题不可以退换"); // 尾部语，后台配置
    m_kPosSet.receiptSet.sPicturePath = ""; // 自定义图片，后台配置
    m_kPosSet.receiptSet.option.bGoodsCode = false; // 打印商品编码
    m_kPosSet.receiptSet.option.bCountCategory = true; // 打印分类小计
    m_kPosSet.receiptSet.option.bAddGoodsNumAfterGoodsName = true; // 商品数量(x1)添加到商品名后
    m_kPosSet.receiptSet.option.bPrice = true; // 打印单价
    m_kPosSet.receiptSet.option.bGoodsNameInOneRow = true; // 商品名称独占一行 （暂时不做）
    m_kPosSet.receiptSet.option.bUnit = true; // 打印单位
    m_kPosSet.receiptSet.option.bForbidBigFont = false; // 禁止大写字体
    m_kPosSet.receiptSet.option.bShortGoodsName = false; // 打印商品简称
    // 会员的打印选项
    m_kPosSet.receiptSet.option.memberInfo.bShowInfo = true; // 是否显示会员信息
    m_kPosSet.receiptSet.option.memberInfo.bShowIntegral = true; // 是否显示积分
    m_kPosSet.receiptSet.option.memberInfo.bShowAccountAndRemain = true; // 显示账号和余额

    ReceiptPictureMaker::setReceiptPrintOption(m_kPosSet.receiptSet);
}
