#include "EnumToString.h"
#include "../data/enumData.h"
#include "../data/constData.h"

QString EnumToString::keySetTypeToString(int type)
{
    if (type == e_homeElse)
    {
        return QStringLiteral("其他");
    }
    else if (type == e_homeMember)
    {
        return QStringLiteral("会员");
    }
    else if (type == e_homePending)
    {
        return QStringLiteral("挂单");
    }
    else if (type == e_homeCancel)
    {
        return QStringLiteral("取消");
    }
    else if (type == e_homeTrimMoney)
    {
        return QStringLiteral("整单取消");
    }
    else if (type == e_homeDiscount)
    {
        return QStringLiteral("折扣");
    }
    else if (type == e_lastReceipt)
    {
        return QStringLiteral("上张小票");
    }
    else if (type == e_homeFastCreateDocument)
    {
        return QStringLiteral("快速建档");
    }
    else if (type == e_homeTrimBox)
    {
        return QStringLiteral("清零");
    }
    else if (type == e_homeDiscountAll)
    {
        return QStringLiteral("整单折扣");
    }
    else if (type == e_homePurse)
    {
        return QStringLiteral("钱箱");
    }
    else if (type == e_homeRefundGoods)
    {
        return QStringLiteral("退货");
    }
    else if (type == e_homeLock)
    {
        return QStringLiteral("锁屏");
    }
    else if( type == e_homeModifyNum )
    {
        return QStringLiteral("修改数量");
    }
    else if (type == e_refundGoods)
    {
        return QStringLiteral("退货");
    }
    else if (type == e_refundAllGoods)
    {
        return QStringLiteral("整单退货");
    }
    else if (type == e_refundModifyNum)
    {
        return QStringLiteral("修改数量");
    }
    else
    {
        return QString(QStringLiteral("未知类型:%1")).arg(type);
    }
}

QString EnumToString::recieveGoodsStateToString(int type)
{
    if (type == e_RecieveOrderFinish) // 已完成
    {
        return QStringLiteral("已完成");
    }
    else if (type == e_RecieveOrderDoing)// 正在收货
    {
        return QStringLiteral("收货中");
    }
    else if (type == e_RecieveOrderNotStart)// 未收货
    {
        return QStringLiteral("未收货");
    }
    else
    {
        return QString(QStringLiteral("未知类型:%1")).arg(type);
    }
}

QString EnumToString::stockingTypeToString(int type)
{
    if (type == e_systemStocking)// 总部盘点
    {
        return QStringLiteral("总部盘点");
    }
    else if (type == e_tempStocking)// 临时盘点
    {
        return QStringLiteral("临时盘点");
    }
    else if (type == e_cycleStocking) // 循环盘点
    {
        return QStringLiteral("循环盘点");
    }
    else
    {
        return QString(QStringLiteral("未知类型:%1")).arg(type);
    }
}

QString EnumToString::stockingStateToString(int type)
{
    if (type == e_stockingNoStart)// 未开始
    {
        return QStringLiteral("未开始");
    }
    else if (type == e_stockingDoing)// 进行中
    {
        return QStringLiteral("进行中");
    }
    else if (type == e_stockingHaveDiffer) // 出差异
    {
        return QStringLiteral("出差异");
    }
    else if (type == e_stockingAdjust)// 已调整
    {
        return QStringLiteral("已调整");
    }
    else if (type == e_stockingDrop) // 废弃
    {
        return QStringLiteral("废弃");
    }
    else
    {
        return QString(QStringLiteral("未知类型:%1")).arg(type);
    }
}

QString EnumToString::stockSateToString(int type)
{
    if (type == e_stockOrderNotCheck)// 未审核
    {
        return QStringLiteral("未审核");
    }
    else if (type == e_stockOrderCheckFinish)// 已审核
    {
        return QStringLiteral("已审核");
    }
    else if (type == e_stockOrderAdd)// 将要新增
    {
        return QStringLiteral("将要新增");
    }
    else
    {
        return QStringLiteral("未知类型:%1").arg(type);
    }
}

QString EnumToString::adjustPriceStateToString(int type)
{
    if (type == e_adjustPriceOrderNotCheck)
    {
        return QStringLiteral("未审核");
    }
    else if (type == e_adjustPriceOrderCheckFinish)
    {
        return QStringLiteral("已审核");
    }
    else if (type == e_adjustPriceOrderAdd)
    {
        return QStringLiteral("将要新增");
    }
    else
    {
        return QStringLiteral("未知类型:%1").arg(type);
    }
}

QString EnumToString::orderCardTypeToString(int type)
{
    if (type == e_orderCardNormal)
    {
        return QStringLiteral("正常");
    }
    else if (type == e_orderCardUrgent)
    {
        return QStringLiteral("加急");
    }
    else if (type == e_orderCardForbid)
    {
        return QStringLiteral("禁止");
    }
    else
    {
        return QStringLiteral("未知:%1").arg(type);
    }
}

QString EnumToString::bcsLinkStateToString(int type)
{
    if (type == e_bcsLink)
    {
        return QStringLiteral("联接");
    }
    else if (type == e_bcsOffLink)
    {
        return QStringLiteral("断开");
    }
    else if (type == e_bcsForbidLink)
    {
        return QStringLiteral("禁用");
    }
    else if(type == e_bcsForwaitLink)
    {
        return QStringLiteral("等待");
    }
    else
    {
        return QStringLiteral("未检测");
    }
}

QString EnumToString::bcsSendDownState(int type)
{
    if (type == e_bcsSendDownSuccess)
    {
        return QStringLiteral("成功");
    }
    else if (type == e_bcsSendDownFailed)
    {
        return QStringLiteral("失败");
    }
    else if(type == e_bcsSendDownWait)
    {
        return QStringLiteral("等待");
    }
    else
    {
        return QStringLiteral("未知:%1").arg(type);
    }
}

QString EnumToString::sexToString( int nSex )
{
    QString strSex = "";
    switch ( nSex ) {
    case e_woman:
        strSex = "女";
        break;
    case e_man:
        strSex = "男";
        break;
//    case e_nullSex:
//        strSex = "未知";
//        break;
    default:
        strSex = "未知";
        break;
    }

    return strSex;
}

QString EnumToString::payMethodToString(int nPayMethod )
{
    QString strPayMethod = "";

    switch( nPayMethod ) {
    case PayCash:
        strPayMethod = "现金";
        break;
    case UnionPay:
        strPayMethod = "银联";
        break;
    case PayMemCard:
        strPayMethod = "会员卡";
        break;
    case PayStoreCard:
        strPayMethod = "储值卡";
        break;
    case PayAlipay:
        strPayMethod = "支付宝";
        break;
    case PayWeChat:
        strPayMethod = "微信支付";
        break;
    case ApplePay:
        strPayMethod = "PAY";
        break;
    case JdWallet:
        strPayMethod = "京东钱包";
        break;
    case Coupon:
        strPayMethod = "优惠券";
        break;
    case IntegralToCansh:
        strPayMethod = "积分抵现";
        break;
    case VirtualPayPage:
        strPayMethod = "虚拟";
        break;
    case PayCityCard:
        strPayMethod = "市民卡";
        break;
    case PayFengCha:
        strPayMethod = "果麦";
        break;
    case PayCheck:
        strPayMethod = "支票";
        break;
    case PayBills:
        strPayMethod = "欠单";
        break;
    case PayEntityCard:
        strPayMethod = "实体卡";
        break;
    case PayOther:
        strPayMethod = "其他";
        break;
    case e_virtualPay:
        strPayMethod = "虚拟支付";
    default:
        break;
    }

    return strPayMethod;
}

EPayMethod EnumToString::payMethodToEnum(QString strPayMethod)
{
    EPayMethod ePayMethod = PayCash;
    if( strPayMethod == "现金" ) {
        ePayMethod = PayCash;
    } else if( strPayMethod == "银联" ) {
        ePayMethod = UnionPay;
    } else if( strPayMethod == "会员卡" ) {
        ePayMethod = PayMemCard;
    } else if( strPayMethod == "储值卡" ) {
        ePayMethod = PayStoreCard;
    } else if( strPayMethod == "支付宝" ) {
        ePayMethod = PayAlipay;
    } else if( strPayMethod == "微信支付" ) {
        ePayMethod = PayWeChat;
    } else if( strPayMethod == "PAY" ) {
        ePayMethod = ApplePay;
    } else if( strPayMethod == "京东钱包" ) {
        ePayMethod = JdWallet;
    } else if( strPayMethod == "银联卡" ) {
        ePayMethod = UnionPay;
    } else if( strPayMethod == "优惠券" ) {
        ePayMethod = Coupon;
    } else if( strPayMethod == "虚拟" ) {
        ePayMethod = VirtualPayPage;
    } else if( strPayMethod == "市民卡" ) {
        ePayMethod = PayCityCard;
    } else if( strPayMethod == "果麦" ) {
        ePayMethod = PayFengCha;
    } else if( strPayMethod == "支票" ) {
        ePayMethod = PayCheck;
    } else if( strPayMethod == "欠单" ) {
        ePayMethod = PayBills;
    } else if( strPayMethod == "实体卡" ) {
        ePayMethod = PayEntityCard;
    } else if( strPayMethod == "其他" ) {
        ePayMethod = PayOther;
    }

    return ePayMethod;
}

QString EnumToString::documentTypeToString( EDocumentType eDocumentType )
{
    QString strDocumentType = "";
    switch( eDocumentType ) {
    case eIdentityCard:
        strDocumentType = "身份证";
        break;
    case eOfficerCard:
        strDocumentType = "军官证";
        break;
    case ePassportCard:
        strDocumentType = "护照";
        break;
    case eStudentCard:
        strDocumentType = "学生证";
        break;
    case eOtherCard:
        strDocumentType = "其他";
        break;
    default:
        strDocumentType = "其他";
        break;
    }

    return strDocumentType;
}

EDocumentType EnumToString::documentTypeToInt( QString strDocumentType )
{
    EDocumentType eDocumentType = eIdentityCard;
    if( strDocumentType == "请选择" ) {
        eDocumentType = ePleaseSelect;
    } else if( strDocumentType == "身份证" ) {
        eDocumentType = eIdentityCard;
    } else if( strDocumentType == "军官证" ) {
        eDocumentType = eOfficerCard;
    } else if( strDocumentType == "护照" ) {
        eDocumentType = ePassportCard;
    } else if( strDocumentType == "学生证" ) {
        eDocumentType = eStudentCard;
    } else if( strDocumentType == "其他" ) {
        eDocumentType = eOtherCard;
    }

    return eDocumentType;
}

EDropType EnumToString::dropTypeToInt( QString strDropType )
{
    EDropType eDropType = eDropNull;
    if(strDropType == QStringLiteral("不处理"))
    {
        eDropType = eUntreated;
    }
    else if(strDropType == QStringLiteral("舍弃"))
    {
        eDropType = eAbandon;
    }
    else if(strDropType == QStringLiteral("四舍五入"))
    {
        eDropType = eRounding;
    }
    else if(strDropType == QStringLiteral("进位"))
    {
        eDropType = eCarry;
    }
    else
    {
        eDropType = eUntreated;
    }

    return eDropType;
}

QString EnumToString::dropTypeToString(int nDropType)
{
    if (nDropType == eUntreated)
    {
        return QStringLiteral("不处理") ;
    }
    else if (nDropType == eAbandon)
    {
        return QStringLiteral("舍弃");
    }
    else if (nDropType == eRounding)
    {
        return QStringLiteral("四舍五入");
    }
    else if (nDropType == eCarry)
    {
        return QStringLiteral("进位");
    }
    else
    {
        return QStringLiteral("不处理");
    }
}
