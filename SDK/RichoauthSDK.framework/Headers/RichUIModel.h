//
//  RichUIModel.h
//  RichoauthSDK
//
//  Created by 潘玉琳 on 2019/12/16.
//  Copyright © 2019 潘玉琳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, RICHPresentationDirection){
    RICHPresentationDirectionBottom = 0,  //底部  present默认效果
    RICHPresentationDirectionRight,       //右边  导航栏效果
    RICHPresentationDirectionTop,         //上面
    RICHPresentationDirectionLeft,        //左边
};

@interface RichUIModel : NSObject

/**
 导航栏相关属性
 */
//.导航栏背景颜色
@property(nonatomic,strong)UIColor  * barColor;
//.导航栏文字
@property(nonatomic,strong)NSString  * barText;
//.导航栏返回图标
@property(nonatomic,strong)UIImage  * backBtnImage;
//.导航栏文字颜色
@property(nonatomic,strong)UIColor  * barTextColor;
//.设置移动卡登录页面导航栏高度
@property(nonatomic,assign)CGFloat uaCustomBarHeight;
//.设置导航栏底部线隐藏
@property(nonatomic,assign)BOOL  navBottomLineHidden;

/*登入页面背景图片*/
@property(nonatomic,strong)UIImage  * viewBackImg;


/*logo的图片设置*/
@property(nonatomic,strong)UIImage  * iconImage;
/**LOGO图片宽度*/
@property (nonatomic,assign) CGFloat logoWidth;
/**LOGO图片高度*/
@property (nonatomic,assign) CGFloat logoHeight;
/**LOGO图片偏移量*/
@property (nonatomic,assign) CGFloat logoOffsetY;


/**手机号码显示相关属性*/
//设置手机号码的颜色
@property(nonatomic,strong)UIColor  * numberColor;
//号码栏Y偏移量
@property (nonatomic,assign)CGFloat numberOffsetY;

//移动卡号码栏Y偏移量
@property (nonatomic,assign)CGFloat txMobliNumberOffsetY;
//手机号码字体
@property (nonatomic,assign)CGFloat  numberFont;



/** 品牌logo 相关属性*/
//设置移动卡隐私协议提示语颜色
@property(nonatomic,strong)UIColor  * sloganTextColor;
//品牌logo图片及标签的Y偏移量
@property (nonatomic,assign) CGFloat sloganLabelOffsetY;
//品牌标签的字体大小
@property (nonatomic,assign) CGFloat brandLabelTextSize;



/**登录按钮相关属性*/
//.登入按钮背景图片 激活,失效,高亮 --不适用联通卡
@property(nonatomic,strong)NSArray  * loginBtnImgs;
//.登入按钮背景颜色值 激活,失效,高亮;
@property(nonatomic,strong)NSArray  * loginBtnColors;
//.登入按钮字体颜色
@property(nonatomic,strong)UIColor   * loginBtnTextColor;
//.修改登录按钮文本
@property(nonatomic,strong)NSString  * logBtnText;
/**登录按钮宽度*/
@property (nonatomic,assign) CGFloat logBtnWidth;
//登录按钮高度
 //若需单独修改登录按钮的高度，宽度logBtnWidth不传值或者传0即可
@property (nonatomic,assign) CGFloat logBtnHeight;

//移动卡登录按钮的左右边距 注意:按钮呈现的宽度在竖屏时必须大于屏幕的一半,横屏时必须大于屏幕的三分之一
 //示例:@[@50,@70] 只能两个元素
@property (nonatomic, strong) NSArray <NSNumber *> *logBtnOriginLR;

//登录按钮Y偏移量
@property (nonatomic,assign) CGFloat logBtnOffsetY;



/**其他方式登录相关属性*/
//.切换按钮文本
@property(nonatomic,strong)NSString   * changeBtnText;
//.切换按钮字体颜色
@property(nonatomic,strong)UIColor   * changeBtnTextColor;
//.切换按钮隐藏
@property(nonatomic,assign)BOOL       changeBtnHidden;
//其他方式登录Y偏移量*/
@property (nonatomic,assign) CGFloat otherWayLogBtnOffsetY;
/**字体大小*/
@property (nonatomic,assign) CGFloat otherWayLogBtnTextSize;



/**隐私协议相关属性*/
//.添加协议
@property(nonatomic,strong)NSArray * agreement;
//.协议是否打开--默认打开
@property(nonatomic,assign)BOOL agreementOn;

//.修改隐私协议的文字颜色
@property(nonatomic,strong)UIColor  * privacyColor;
//设置隐私文本颜色
@property(nonatomic,strong)UIColor  * privacyTextColor;
/**隐私协议标签Y偏移量
 该控件底部（bottom）相对于屏幕（safeArea）底部（bottom）的距离
 */
@property (nonatomic,assign) CGFloat privacyLabelOffsetY;



/**复选框相关属性*/
//.设置隐私复选框的宽，高（必须12以上），移动和联通可设置
@property(nonatomic,assign)CGFloat checkBoxWH;
//复选框未选中时图片
@property (nonatomic,strong) UIImage *uncheckedImg;
//、复选框选中时图片
@property (nonatomic,strong) UIImage *checkedImg;


/**是否系统关闭登录页面*/
@property (nonatomic,assign) BOOL dismissCurrentVC;

/**页面弹出动画效果*/
// 授权页面推出的动画效果：参考RichPresentationDirection枚举
@property (nonatomic, assign) RICHPresentationDirection presentType;


@property(nonatomic,assign)NSTimeInterval preLoginTime;
@property(nonatomic,assign)NSTimeInterval loginTime;


-(void)setPresentType:(RICHPresentationDirection)presentType;
-(RICHPresentationDirection)presentType;

-(void)setLogBtnOriginLR:(NSArray <NSNumber *> *)logBtnOriginLR;
-(NSArray <NSNumber *> *)logBtnOriginLR;

-(void)setLogBtnWidth:(CGFloat)logBtnWidth;
-(CGFloat)logBtnWidth;

-(void)setDismissCurrentVC:(BOOL)dismissCurrentVC;
-(BOOL)dismissCurrentVC;

- (void)setTxMobliNumberOffsetY:(CGFloat)txMobliNumberOffsetY;
-(CGFloat)txMobliNumberOffsetY;

-(void)setLogBtnHeight:(CGFloat)logBtnHeight;
-(CGFloat)logBtnHeight;

-(void)setLogoOffsetY:(CGFloat)logoOffsetY;
-(CGFloat)logoOffsetY;

-(void)setLogoWidth:(CGFloat)logoWidth;
-(CGFloat)logoWidth;

-(void)setLogoHeight:(CGFloat)logoHeight;
-(CGFloat)logoHeight;

-(void)setBrandLabelTextSize:(CGFloat)brandLabelTextSize;
-(CGFloat)brandLabelTextSize;


-(void)setIconImage:(UIImage *)iconImage;
-(UIImage*)iconImage;

-(void)setViewBackImg:(UIImage *)viewBackImg;
-(UIImage*)viewBackImg;

-(void)setBarColor:(UIColor *)barColor;
-(UIColor*)barColor;

-(void)setBarText:(NSString *)barText;
-(NSString*)barText;

-(void)setBackBtnImage:(UIImage *)backBtnImage;
-(UIImage*)backBtnImage;

-(void)setBarTextColor:(UIColor *)barTextColor;
-(UIColor*)barTextColor;

-(void)setLoginBtnImgs:(NSArray *)loginBtnImgs;
-(NSArray*)loginBtnImgs;

-(void)setLoginBtnColors:(NSArray *)loginBtnColors;
-(NSArray*)loginBtnColors;

-(void)setLoginBtnTextColor:(UIColor *)loginBtnTextColor;
-(UIColor*)loginBtnTextColor;

-(void)setChangeBtnText:(NSString *)changeBtnText;
-(NSString*)changeBtnText;

-(void)setChangeBtnTextColor:(UIColor *)changeBtnTextColor;
-(UIColor*)changeBtnTextColor;

-(void)setChangeBtnHidden:(BOOL )changeBtnHidden;
-(BOOL)changeBtnHidden;

-(void)setAgreement:(NSArray *)agreement;
-(NSArray*)agreement;

-(void)setAgreementOn:(BOOL)agreementOn;
-(BOOL)agreementOn;

-(void)setPrivacyColor:(UIColor *)privacyColor;
-(UIColor*)privacyColor;

-(void)setLogBtnText:(NSString *)logBtnText;
-(NSString*)logBtnText;

-(void)setUaCustomBarHeight:(CGFloat )uaCustomBarHeight;
-(CGFloat)uaCustomBarHeight;

-(void)setCheckBoxWH:(CGFloat )checkBoxWH;
-(CGFloat)checkBoxWH;

-(void)setUncheckedImg:(UIImage * )uncheckedImg;
-(UIImage *)uncheckedImg;


-(void)setCheckedImg:(UIImage * )checkedImg;
-(UIImage *)checkedImg;


- (void)setSloganTextColor:(UIColor *)sloganTextColor;
-(UIColor *)sloganTextColor;

- (void)setPrivacyTextColor:(UIColor *)privacyTextColor;
-(UIColor *)privacyTextColor;

- (void)setNumberColor:(UIColor *)numberColor;
-(UIColor *)numberColor;

- (void)setNavBottomLineHidden:(BOOL)navBottomLineHidden;
-(BOOL)navBottomLineHidden;

- (void)setNumberOffsetY:(CGFloat)numberOffsetY;
-(CGFloat)numberOffsetY;

- (void)setSloganLabelOffsetY:(CGFloat)sloganLabelOffsetY;
-(CGFloat)sloganLabelOffsetY;

- (void)setNumberFont:(CGFloat)numberFont;
-(CGFloat)numberFont;

- (void)setLogBtnOffsetY:(CGFloat)logBtnOffsetY;
-(CGFloat)logBtnOffsetY;


- (void)setOtherWayLogBtnOffsetY:(CGFloat)otherWayLogBtnOffsetY;
-(CGFloat)otherWayLogBtnOffsetY;


- (void)setPrivacyLabelOffsetY:(CGFloat)privacyLabelOffsetY;
-(CGFloat)privacyLabelOffsetY;


- (void)setOtherWayLogBtnTextSize:(CGFloat)otherWayLogBtnTextSize;
-(CGFloat)otherWayLogBtnTextSize;


@end

NS_ASSUME_NONNULL_END
