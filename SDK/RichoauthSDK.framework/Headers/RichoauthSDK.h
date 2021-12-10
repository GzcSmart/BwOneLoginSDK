//
//  RichoauthLoging.h
//  RichoauthSDKDemo
//
//  Created by 潘玉琳 on 2019/7/19.
//  Copyright © 2019 潘玉琳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RichUIModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface RichoauthSDK : NSObject

/*声明一个block
 @param resultDic 网络返回的data的解析结果
 */
typedef void (^richSuccessBlock) (NSDictionary * _Nonnull resultDic);
/**
 声明一个block
 @param error 网络返回的错误或者其它错误
 */
typedef void (^richFailureBlock) (id error);
/*声明一个block
 @param resultDic 返回点击其他登录方式的回调
 */
typedef void (^richOtherBlock) (NSDictionary * _Nonnull resultDic);
/*声明一个block
@param successDismiss 主调取消页面成功返回回调
*/
typedef void (^richDisMissVcSuccessBlock) (BOOL successDismiss);

//初始化方法
+(void)initLoginWithId:(NSString*)apiId appSecret:(NSString*)appSecret;

//修改UIModel修改界面如不要使用默认的就可以调用
+(void)changeShareUIModel:(RichUIModel*)richUiModel;

//预登录,调用loginWithBack 这个之前必须使用一下预登录方法
//************注意注意注意*************
//preLoginWithBack 方法要调用成功之后才可以调用 loginWithBack 这个方法

+(void)preLoginWithBack:(richSuccessBlock)successBlock failBlock:(richFailureBlock)failBlock;

//调用登录界面进行免密码认证的功能
/*
===============================================================
======= 注意注意一定要先调用preLoginWithBack进行预登录才有用=======
===============================================================
successBlock 成功返回回调
failBlock    失败返回回调
otherBlock   其他方式的回调(返回,其他登入方式)
 controller 当前跳转控制器
 */
+(void)loginWithController:(UIViewController*)controller  successBlock:(richSuccessBlock)successBlock failBlock:(richFailureBlock)failBlock  otherBlock:(richOtherBlock)otherBlock;
/**获取完整手机号码
 token：   一键登录置换的token值
 */
+(void)getCompleteNumberWithToken:(NSString*)token successBlock:(richSuccessBlock)successBlock failBlock:(richFailureBlock)failBlock;
/**获取手机号码校验*/
+(void)getVerifyTokenSuccessBlock:(richSuccessBlock)successBlock failBlock:(richFailureBlock)failBlock;

/**手机号码校验*/
+(void)verifyCodesWithToken:(NSString*)token andPhoneNumber:(NSString *)phoneNumber successBlock:(richSuccessBlock)successBlock failBlock:(richFailureBlock)failBlock;


/* getSimInfo
 //networkType 类型NSString
 //值 == 0.无网络; 1.数据流量; 2.wifi; 3.数据+wifi
 //carrier 类型NSNumber
 //值 == 0.未知(未插sim卡，其它运营商等); 1.中国移动mobil;2.中国联通unicom;3.中国电信telecom
 */
+(NSDictionary*)getSimInfo;
/*
 打印预登录时间和登录时间
 */
+(void)logTime;

//手动取消登录页面
+(void)disMissVCWithSuccessBlock:(richDisMissVcSuccessBlock)successBlock;


@end

NS_ASSUME_NONNULL_END
