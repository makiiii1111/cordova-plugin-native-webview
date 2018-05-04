//
//  CDVNativeWebView.h
//
//  Created by Luke Wuu on 09/04/2018.
//
#import <Cordova/CDVPlugin.h>
#import <WebKit/WebKit.h>

@protocol CDVShareDelegate <NSObject>
- (void)shareToWechatFriend;
- (void)shareToWechatTimeline;
@end

@interface CDVNativeWebView : CDVPlugin <UIViewControllerTransitioningDelegate, CDVShareDelegate>
- (void)open:(CDVInvokedUrlCommand *)command;
@end

@interface CDVNativeWebViewController : UIViewController <WKNavigationDelegate>
@property (nonatomic) BOOL enableShare;
@property (nonatomic, strong) UIColor *navBarColor;
@property (nonatomic, strong) UIColor *progressBarColor;
@property (nonatomic, strong) UIColor *iconButtonColor;
@property (nonatomic, weak) id<CDVShareDelegate> delegate;

- (id)initWithUrl:(NSString *)url;
- (void)start;
@end

@interface CDVNativeWebViewUtils : NSObject
+ (UIColor *)getColorByHexString:(NSString *)hexString;
@end

@interface PersentAnimation : NSObject <UIViewControllerAnimatedTransitioning>
@end


@interface DismissAnimation : NSObject <UIViewControllerAnimatedTransitioning>
@end

@interface SwapeRightInteractiveTransition : UIPercentDrivenInteractiveTransition
@property (nonatomic, assign) BOOL interacting;
- (void)wireToViewController:(UIViewController *)viewController;
@end

