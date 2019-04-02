#ifndef HTTPSTRUCTDATA_H
#define HTTPSTRUCTDATA_H

#include <QString>
#include <QDateTime>
#include "enumData.h"
#include <QVariant>

typedef struct CheckDetialInfo
{
    int nId;                //序号
    int id;                 //商品id
    int goodsId;
    QString sName;          //商品名称
    QString sCode;          //商品编号
    QString sUnit;          //单位
    QString sCategoryName;  //大类名称
    float sNumber;          //报损数量
    float fPrice;           //商品价格
    float sMoney;           //报损金额
    float fMarkNum;//箱数与件数的量比系数  如 5公斤/箱的5
    int sReason;        //报损原因  0:过期 1:损坏 2:丢失 3:其他
}AddReportLossSelectInfo, AddReportLossInfo;
Q_DECLARE_METATYPE(CheckDetialInfo)

struct ReportLossInfo
{
    int keyId;
    qint64 id;         //单号id
    QString InfoID;    //单号
    QString createName;     //制单人
    QString createTime;     //制单时间
    QString checkName;      //审核人
    QString checkTime;      //审核时间
    int status;       //状态  0:未审核 1:已审核
    QList<CheckDetialInfo> checkDetialInfo;
};
Q_DECLARE_METATYPE(ReportLossInfo)

struct AccountInfo
{
    int id;              //序号
    int keyId;
    QString sAccountID;  //员工工号
    QString sName;       //账号姓名
    QString sPasswd;     //账号密码
    QString sTelnumber;  //电话号码
    QString sPower;          //角色权限  003:店长 004:收银员 005:导购员
    bool status;         //状态  0:禁用 1:启用
};
Q_DECLARE_METATYPE(AccountInfo)

struct ShopInfo
{
    QString sCorpName; // 企业名称
    QString sShopName; // 商店名称
};

struct RegistResultInfo
{
    int nRegistResult; // 注册结果
    QString sCorpCode; // 企业ID
    //    QString sPosCode; // pos机号
    QString sAppKey; // 企业授权标识
    QString sAppSecret; // 企业认证密匙
};

struct SalemanInfo
{
    int nUserId	; //用户ID
    QString sPassword; // 用户密码
    QString sUserCode; //用户编码
    QString sUsername; //用户名
    QString sEmail; //用户邮箱
    QString sMobile; //手机
    int nSex; //性别
    QString sUserPic; //用户头像
    //    int nUserPrivilege; //用户权限

    QString sRoleCode; // 角色编码
    QList<QString> privilegeList; // 权限列表
    //    QString sRoleName; // 角色名称
    //    QString sRoleShowName; // 角色显示名称
    QString sLoginTime; // 登入时间
    QString sLogoutTime; // 登出时间
    QString sSubmitMoney; // 交款金额
    bool bShopHeader; // 是否是店长

    SalemanInfo()
        : nUserId( 0 )
        , sPassword( "" )
        , sUserCode( "" )
        , sUsername( "" )
        , sEmail( "" )
        , sMobile( "" )
        , nSex( 1 )
        , sUserPic( "" )
        , sRoleCode( "" ){}
};
//代理中使用，需要注册
Q_DECLARE_METATYPE( SalemanInfo )

struct LoginKPosInfo
{
    QString sToken; //访问标识
    SalemanInfo salemanInfo;
    QString sCorpCode; //公司编码
    QString sCorpName; // 公司名称
    int nShopID; // 门店ID
    QString sShopName; // 门店名称
    QString sShopCode; // 门店编号
    QString sPosCode; // 款机号
    float fPurseRemain; //钱包剩余金额
    QString sLastHandPurseTime; //上次交款时间
    int nLoginId;//登录信息ID
};

struct CategoryInfo_s
{
    QString sKeyId; // nId和bCustom的组合
    int nId; // 分类id
    QString sName; // 分类名称
    bool bCustom; // 是否是自定义分类
    QList<int> goodsIdList; // 商品ID列表
};

struct GoodsPriceInfo_s
{
    float fPrice;//商品价格
    float fMemberPrice; // 会员价
    QString sUpdateTime; // 价格更新时间
};

struct GoodsInfo_s
{
    QString sBarCode;//商品条码（主键）
    int nId;//商品id
    QString sCode;//商品编码id
    QString sName;//商品名称
    QString sShortName;//商品简称
    QString sPinYinName; // 拼音助记码
    QString sWuBiName; // 五笔助记码
    QString sPluCode; // plu码
    QString sPluName; // 商品Plu名称
    int nPluGrade; // 商品plu等级
    bool bStandard;//是否标品
    float fMarkNum;//箱数与件数的量比系数  如 5公斤/箱的5
    QString sSaleUnit;//销售单位： 元/公斤
    GoodsPriceInfo_s goodsPriceInfo;
    QString sSpeUnit;//要货单位，如50个/卷
    QString sCategoryName;//大类名称
};

struct PayDetail_s {
    QString strOrderNum;//小票单号
    QString strPaymentOrderNum;//支付单号（现金支付单号：pos号+时间yyMMddhhmmss)
    int nPayMethod;//支付方式
    float fPayMoney;//支付金额
    int nPayIntegral;//支付积分
    int nStatus;//支付状态
    float fIntToAmt;//积分抵现， 以后不要了
    int nPayType;//支付类型1：付款  2：退款
    bool bVirtual;//虚拟支付， 以后不要了
    QDateTime dtCreate;//创建时间
    QDateTime dtComplete;//完成时间
    QString strComment;//备注信息，以后不要了
    QString strIntExchangeAmt;//1积分抵价， 以后不要了
    QString strAuthCode;//支付授权码

    PayDetail_s()
        : strOrderNum( "" )
        , strPaymentOrderNum( "" )
        , nPayMethod( PayNull )
        , fPayMoney( 0.00 )
        , nPayIntegral( 0 )
        , fIntToAmt( 0.00 )
        , bVirtual( false )
        , strIntExchangeAmt( "0" )
        , strAuthCode( "" ){}
};

struct KPosUpdateInfo
{
    int nUpdateType; // 更新类型 (enum KPosUpdateType)
    QString sAddress; // 下载地址
};

struct MemInfo_s {
    QString strCardNo;//会员卡号
    QString strName;
    QString strMobile;
    int nSex;
    QDateTime dtBirthday;
    int nMemTypeId;//会员类型ID，vip_level_id : 会员等级ID1-普通会员，2-白金会员，3-钻石会员
    int nMemLevelId;//会员等级ID
    QString strAccountBalance;//账户余额
    int nIntegral;//积分
    int nCardStatus;//卡状态：-1.删除(退卡), 0.挂失, 1.启用
    QDateTime dtShopping;//上次购物时间
    int nNewAddInt;//新增积分
    int nUseInt;//使用积分

    MemInfo_s()
        : strCardNo( "" )
        , strName( "" )
        , strMobile( "" )
        , nSex( -1 )
        , nMemTypeId( 1 )
        , nMemLevelId( 1 )
        , strAccountBalance( "" )
        , nIntegral( 0 )
        , nCardStatus( 1 )
        , nNewAddInt( 0 )
        , nUseInt( 0 ){}
};

//会员充值信息
struct MemRechargeInfo_s {
    QString strCorpID;// 企业编号
    QString strCardNo;//卡号
    QString strRechargeAmt;//会员充值金额
    EPayMethod ePayMethod;//支付方式
    QString strGiftAmt;//赠送金额
    int nGiftIntegral;//赠送积分
    int nShopId;// 门店ID
    int nUserId;//员工id
    QString strPayCode;//付款码
    int nStatus;//充值状态：0：充值失败，1：充值成功
};


struct MemRegisterInfo_s {
    MemInfo_s stMemInfo;
    QString strPayPwd;//支付密码
    bool bPaypwd;//1:有密码，0：没有密码
    EDocumentType eDocumentType;//证件类型
    QString strDocumentNum;//证件号码
    QString strAddress;//详细地址
    int nOPeratorId;//操作员Id
    QString strIntExchangeAmt;//1积分抵价
    QString strIntToAmt;//积分抵价现金
    QString strMaxGiftAmt;//最大赠送金额
    QString strRechargeAmt1;//充值基准金额1
    QString strRechargeAmt2;//充值基准金额2
    QString strRechargeAmt3;//充值基准金额3
    QString strGiftAmt1;//赠送基准金额1
    QString strGiftAmt2;//赠送基准金额2
    QString strGiftAmt3;//赠送基准金额3
    QString strSaleAmt;//消费基准金额
    QString strGiftIntegral;//赠送基准积分

    MemRegisterInfo_s()
        : strPayPwd( "" )
        , bPaypwd( false )
        , eDocumentType( ePleaseSelect )
        , strDocumentNum( "" )
        , strAddress( "" )
        , nOPeratorId( -1 )
        , strIntExchangeAmt( "0.00" )
        , strIntToAmt( "0.00" )
        , strMaxGiftAmt( "0" )
        , strGiftAmt1( "0" )
        , strSaleAmt( "0" )
        , strGiftIntegral( "0" ){}
};

//会员等级
struct MemGradeInfo_s {
    int nId;//等级Id
    int nTypeId;//会员类型Id
    QString strLevelName;//等级名字
};

//会员类型
struct MemTypeInfo_s {
    int nId;//会员类型Id
    QString strTypeName;//钻石VIP

    QList<MemGradeInfo_s> listMemGrade;
};

//业务员
struct OperatorInfo_s {
    int nId;
    QString strName;
};

// 退货原因
struct RefundGoodsReason
{
    int nId; // 原因id
    QString sContent; // 原因内容
};

// 支付储值卡信息
struct PayStoreCardInfo
{
    QString sCardID; // 卡id
    QString sCardNum; // 卡号
    float fCardBalance; // 卡余额
};

// 登录记录
struct LoginRecordInfo
{
    int nUserId	; //用户ID
    QString sLoginTime; // 登入时间
    QString sLoginOutTime; // 登出时间
};

// 交款信息接口
struct ClentCashSubmit_s
{
    QString uuid;
    QString submit_amount; // 交款金额
    QString operate_at;  //交款时间
    QString last_submit_at; //上次交款时间
    int status; //状态 0交款成功 1无网络
    QString user_code;//操作人编号
    QString login_at;//登录时间点
    QString logout_at;//登出时间点
    QString submit_code;//交款编号
};

#endif // HTTPSTRUCTDATA_H
