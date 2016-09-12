//
//  KDAlertView.h
//  KDBlockAlert
//
//  Created by Blankwonder on 11/20/12.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_IOS
#import <UIKit/UIKit.h>
#endif

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#if TARGET_OS_IOS

@interface KDAlertView : NSObject

- (instancetype)initWithTitle:(NSString *)title
                      message:(NSString *)message
            cancelButtonTitle:(NSString *)cancelButtonTitle
                  cancelAction:(void ( ^)(KDAlertView *alertView))cancelAction;

- (void)addButtonWithTitle:(NSString *)title action:(void ( ^)(KDAlertView *alertView))action;
- (void)show;

- (UIAlertView *)systemAlertView;

+ (void)showMessage:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle;
+ (void)showErrorMessage:(NSString *)message;

+ (KDAlertView *)presentingAlertView;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *message;

@end

#else

@interface KDAlertView : NSObject

- (instancetype)initWithTitle:(NSString *)title
                      message:(NSString *)message
            cancelButtonTitle:(NSString *)cancelButtonTitle
                 cancelAction:(void ( ^)(KDAlertView *alertView))cancelAction;

- (void)addButtonWithTitle:(NSString *)title action:(void ( ^)(KDAlertView *alertView))action;
- (void)showInWindow:(NSWindow *)window;

@property (nonatomic) NSAlertStyle alertStyle;

+ (void)showMessage:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle inWindow:(NSWindow *)window;
+ (void)showErrorMessage:(NSString *)message inWindow:(NSWindow *)window;

+ (KDAlertView *)presentingAlertView;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *message;

@end


#endif

#pragma clang diagnostic pop
