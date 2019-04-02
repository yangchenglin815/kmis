#ifndef CONSTDATA_H
#define CONSTDATA_H

#include <QString>
// http 相关
//const QString c_sHttpHostIP = "http://121.43.63.111:8800/";
//const QString c_sHttpHostIP = "http://192.168.1.220";
const QString c_sHttpHostIP = "http://192.168.1.41";
extern float g_heightRate;
extern float g_widthRate;
extern bool isQHD;//是否宽屏比例

//const QString c_sHttpAddress = c_sHttpHostIP + "/gateway?";
//const QString c_sHttpAPP_Key = "20160918000001";
const QString c_sHttpServerVersion = "1.0";
//const QString c_sHttpAPP_Secret = "E44DA6E95045B7712FE40362F3CF2D16";

const QString c_sHttpGetShopInfoAction = "orgz.info.get"; // 获取门店信息
const QString c_sHttpRegisterPosAction = "client.register"; // kpos注册
const QString c_sHttpCheckRegisterResultAction = "client.register.status"; // kpos注册状态检查
const QString c_sHttpLoginKPosAction = "user.account.login"; // 用户登录kpos
const QString c_sHttpLogoutKPosAction = "user.account.logout"; // 用户登出
const QString c_sHttpGetCategoryAction = "client.category.list"; // 商品分类列表获取
const QString c_sHttpGetAllGoodsAction = "client.product.list"; // 商品列表获取
const QString c_sHttpGetAllGoodsPriceAction = "orgz.product.price.download"; // 商品价格获取
const QString c_sHttpOnlineCheckAction = "client.online.check"; // 在线状态检查
const QString c_sHttpUploadReceiptAction = "client.receipt.upload"; // 小票上传
const QString c_sHttpCheckKPosUpdateAction = "client.app.upgrade"; // 软件更新
const QString c_sHttpUploadKposSetAction = "client.setup.upload"; // KPos设置上传
const QString c_sHttpDownloadKPosSetAction = "client.setup.download"; // KPos设置下载
const QString c_sHttpAddCustomCategoryAction = "client.pcategory.create"; // 添加自定义分类
const QString c_sHttpUpdateCustomCategoryAction = "client.pcategory.update"; // 修改自定义分类
const QString c_sHttpDeleteCustomCategoryAction = "client.pcategory.delete"; // 删除自定义分类
const QString c_sHttpUploadScreenAdAction = "client.file.upload"; // 文件上传
const QString c_sHttpUploadClientCashSubmit = "client.cash.submit";//交款
const QString c_sHttpUploadClientCashSubmitSync = "client.cash.submit.sync";//离线交款

// 退货
const QString c_sHttpGetRefundGoodsReasonListAction = "client.goods.return.reason"; // 退货原因列表
const QString c_sHttpSearchReceiptAction = "client.receipt.content.list"; // 获取销售小票

// 要货
const QString c_sHttpGetOrderCategoryAction = "orgz.category.list"; // 获取要货分类列表(大类或中类)
const QString c_sHttpGetOrderGoodsAction = "orgz.req.product.list"; // 获取分页的商品
const QString c_sHttpCreateOrderCardAction = "orgz.req.order.create"; // 生成要货卡
const QString c_sHttpRemoveOrderCardAction = "orgz.req.order.remove"; // 删除要货卡

// 要货卡审核
const QString c_sHttpGetOrderCardListAction = "orgz.req.order.list"; // 获取要货卡列表
const QString c_sHttpGetOrderCardListDetailAction = "orgz.req.order.detail"; // 获取要货卡明细
const QString c_sHttpUpdateOrderCardListDetatilAction = "orgz.req.order.update"; // 更新要货卡明细
const QString c_sHttpUploadOrderCardAction = "orgz.req.order.upload"; // 上传要货卡

// 收货
const QString c_sHttpGetDeliveryOrderListAction = "delivery.order.list"; // 送货单列表
const QString c_sHttpReceiveGoodsStartAction = "recv.order.start"; // 开始收货
const QString c_sHttpReceiveGoodsEndAction = "recv.order.end"; // 结束收货
const QString c_sHttpGetDeliveryDetailAction = "delivery.order.detail"; // 获取送货单明细
const QString c_sHttpGetReceiveGoodsDetailAction = "recv.order.read"; // 获取收货物品明细
const QString c_sHttpSaveReceiveGoodsAction = "recv.order.save"; // 保存收货

// 改价
const QString c_sGetAdjustPriceOrderListAction = "orgz.product.price.order.list"; // 获取改价单列表
const QString c_sCheckAdjustPriceOrderAction = "orgz.product.price.order.audit"; // 审核改价单
const QString c_sRemoveAdjustPriceOrderAction = "orgz.product.price.order.delete"; // 删除改价单
const QString c_sSearchAdjustPriceOrderAction = "orgz.product.price.order.content"; // 查看改价单
const QString c_sSaveAdjustPriceOrderAction = "orgz.product.price.content.save"; // 保存改价单

// 盘点
const QString c_sGetStockOrderListAction = "orgz.inventory.order.list"; // 获取盘点单列表
const QString c_sCheckStockOrderAction = "orgz.inventory.order.audit"; // 审核盘点单
const QString c_sRemoveStockOrderAction = "orgz.inventory.order.delete"; // 删除盘点单
const QString c_sSearchStockOrderAction = "orgz.inventory.order.content"; // 查看盘点单
const QString c_sSaveStockOrderAction = "orgz.inventory.content.save"; // 保存盘点单
const QString c_sGetStockGoodsInfoAction = "orgz.product.batch.get"; // 获取库存商品信息

//入库
const QString c_sGetInStockOrderListAction = "orgz.instock.order.list"; // 获取入库单列表
const QString c_sCheckInStockOrderAction = "orgz.instock.order.audit"; // 审核
const QString c_sRemoveInStockOrderAction = "orgz.instock.order.delete"; // 删除入库单
const QString c_sInquireInStockOrderAction = "orgz.instock.order.content.get"; // 查看入库单明细
const QString c_sAddInStockOrderAction = "orgz.instock.order.add"; // 新增入库单
const QString c_sEditInStockOrderAction = "orgz.instock.order.edit"; // 编辑入库单


//出库
const QString c_sGetOutStockOrderListAction = "orgz.outstock.order.list"; // 获取出库单列表
const QString c_sCheckOutStockOrderAction = "orgz.outstock.order.audit"; // 审核
const QString c_sRemoveOutStockOrderAction = "orgz.outstock.order.delete"; // 删除出库单
const QString c_sInquireOutStockOrderAction = "orgz.outstock.order.content.get"; // 查看出库单明细
const QString c_sAddOutStockOrderAction = "orgz.outstock.order.add"; // 新增出库单
const QString c_sEditOutStockOrderAction = "orgz.outstock.order.edit"; // 编辑出库单

//快速建档
const QString c_sHttpGetQuickGoodsInfoAction = "orgz.product.code.get"; // 获取商品编码，plu，规格
const QString c_sHttpCreateQuickGoodsAction = "orgz.product.create"; // 创建快速建档商品

//支付
const QString c_sHttpCreatePaymentAction = "client.payment.create"; // 创建支付
const QString c_sHttpCreatePayMemberCardAction = c_sHttpCreatePaymentAction; // 会员卡支付
const QString c_sHttpQueryPaymentAction = "client.payment.query";
const QString c_sHttpRevokePaymentAction = "client.payment.reverse";//撤销
const QString c_sHttpClosePaymentAction = "client.payment.close";
const QString c_sHttpUpdateMemberIntegralAction = "orgz.member.account.update"; // 结算后，更新会员积分

//会员信息
const QString c_sHttpQueryMemInfo = "client.vip.info";//"tmall.miaoshop.member.get";
const QString c_sHttpRechargeMem = "client.vip.recharge"; // 会员充值
const QString c_sHttpRegisterMem = "client.vip.register"; // 会员注册
const QString c_sHttpPwdModifyMem = "client.vip.pwchange"; // 会员修改密码
const QString c_sHttpSetStatusMemCard = "client.vip.set.status";
const QString c_sHttpReplaceCard = "client.vip.cardreplace";//换卡接口

//会员类型列表和会员等级列表
const QString c_sHttpMemTypeList = "client.vip.type.list";
const QString c_sHttpMemGradeList = "client.vip.level.list";

//业务员列表
const QString c_sHttpOPeratorList = "client.vip.cashierlist";
const QString c_sHttpAllUserList = "orgz.user.info.get";

//银行卡

// 充值卡
const QString c_sHttpGetPayCodeAction = "client.scan.paycode"; // 获取充值卡信息

// 条码秤
const QString c_sHttpCreateGoodsGroupAction = "product.group.name.create"; // 创建商品组
const QString c_sHttpGetGoodsGroupListAction = "product.group.list"; // 商品组列表获取
const QString c_sHttpSaveGoodsGroupAction = "product.group.content.save"; // 商品组内容保存
const QString c_sHttpGetBarcodeScaleCodeAction = "orgz.scale.code.get"; // 获取条码秤编号
const QString c_sHttpAddBarcodeScaleAction = "orgz.scale.add"; // 添加条码秤
const QString c_sHttpGetBarcodeScaleListAction = "orgz.scale.list"; // 获取条码秤列表
const QString c_sHttpUpdateScaleProductIssueAction = "orgz.scale.product.issue"; // 更新下发条码秤时间
const QString c_sHttpDeleteScaleAction = "orgz.scale.delete"; // 删除条码秤发条码秤时间
const QString c_sHttpResetPasswdAction = "user.password.update"; //修改用户密码



const QString c_sAppName = "KPos";
// 数据库相关
const QString c_sPosDB_SqliteConnectionName = "posDB_Sqlite";
const QString c_py_SqliteConnectionName = "py_Sqlite";

const QString c_sPosDB_SqliteName = "KPos.db";
const QString c_py_SqliteName = "py.db";

const QString c_nNullString = "NULL";

// 小票
const QString c_sReceiptBarCodeName = "receiptBarCode.png"; // 小票条形码
const QString c_sReceiptQRCodeName = "receiptQRCode.jpg"; // 小票二维码

// 定义负数
const int c_nNegativeNumber = -100;

// 取消商品
const int c_nCancelSaleGoods = -1; // 删除商品
const int c_nFinishSaleGoods = 1; // 完成

// pos机
const QString c_sOnlyPc = "ONLYPC";//只有pc
const QString c_sMettLerBalance = "METTLER";//梅特勒
const QString c_sWinTecBalance = "WINTEC";//中科银泰
const QString c_sUANBalance = "UAN";//有安

//主机类型
const int c_sIntegratedScale = 0;//pc一体秤
const int c_sAssembleScale  = 1;//组装显示器

//电子计价秤型号
const int c_sDahuaPricingScale  = 0;//大华计价秤

// 网络响应异常
const QString c_sNetError = QStringLiteral("网络连接异常");
const QString c_sServerJsonError = QStringLiteral("服务器数据异常");

// 主题色
const QString c_sThemeColor = "#505050";

// 角色权限
const QString c_sSaleCode = "0100"; // 销售
const QString c_sReportCode = "0200"; // 报表
const QString c_sStockCode = "0300"; // 盘点
const QString c_sOrderGoodsCode = "0400"; // 要货
const QString c_sAccountManageCode = "0600"; // 账号管理
const QString c_sSetCode = "0800"; // 设置
const QString c_sModifyPasswordCode = "0900"; // 修改密码
const QString c_sAdjustPriceCode = "1000"; // 调价

// 默认商品组id
const int c_nDefaultGoodsGroupId = 0;

// 字体
const QString f_fontStyle = "微软雅黑";
const int f_fontSizeMode1 = 14;
const int f_fontSizeMode2 = 12;
const QString f_fontColorWhite = "#ffffff";
const QString f_fontColorBlack = "#333333";
const QString f_fontColorOrange = "#EA8852";
const QString f_fontColorGreen = "#75AB57";
const QString f_fontColorGray = "#999999";

// 员工管理
const QString c_sShopKeeper = "003"; // 店长
const QString c_sSaleman = "004"; // 收银员
const QString c_sSaleGuide = "005"; // 导购员
const QString c_sGetEmployeeManageOrderListAction = "orgz.user.info.get";
const QString c_sUpdateEmployeeStatusOrderAction = "orgz.user.status.update";
const QString c_sGetEmployeeScodeOrderAction = "orgz.user.code.get";
const QString c_sEditEmployeeOrderAction = "orgz.user.info.edit";

// 员工管理状态
const int c_sRemoveEmployee = -1; // 删除员工
const int c_sStartEmployee = 1; // 启用
const int c_sStopEmployee = 0; // 禁用

// 报损
const QString c_sGetReportLossOrderListAction = "orgz.stockloss.order.list";
const QString c_sAddReportLossOrderListAction = "orgz.stockloss.order.add";
const QString c_sEditReportLossOrderListAction = "orgz.stockloss.order.edit";
const QString c_sDeleteReportLossOrderListAction = "orgz.stockloss.order.delete";
const QString c_sCheckReportLossOrderListAction = "orgz.stockloss.order.audit";
const QString c_sGetReportLossDetialAction = "orgz.stockloss.order.content";

// 销售明细
const QString c_sGetSaleDetialOrderListAction = "client.receipt.list";

// 商品管理
const QString c_sGetGoodsManageOrderListAction = "orgz.product.manage.list";

#endif
