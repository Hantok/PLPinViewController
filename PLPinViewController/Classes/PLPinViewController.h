//
//  PLPinViewController.h
//  Pods
//
//  Created by Ash Thwaites on 17/09/2016.
//
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PLPinViewControllerAction) {
    PLPinViewControllerActionCreate = 0,
    PLPinViewControllerActionChange,
    PLPinViewControllerActionEnter
};

@class PLPinViewController;
@class PLPinAppearance;

@protocol PLPinViewControllerDelegate <NSObject>

@optional

- (void)pinViewControllerDidCancel:(PLPinViewController *)controller;
- (void)pinViewControllerDidLogout:(PLPinViewController *)controller;
- (void)pinViewController:(PLPinViewController *)controller didChangePin:(NSString*)pin;
- (void)pinViewController:(PLPinViewController *)controller didEnterPin:(NSString*)pin;
- (BOOL)pinViewController:(PLPinViewController *)controller shouldAcceptPin:(NSString*)pin;
- (void)pinViewController:(PLPinViewController *)controller didSetPin:(NSString*)pin;
- (void)pinViewController:(PLPinViewController *)controller didPressBiometric:(id)sender;

@end

@interface PLPinViewController : UIViewController

@property (weak) id<PLPinViewControllerDelegate> pinDelegate;
@property (nonatomic, assign) BOOL enableCancel;
@property (nonatomic, assign) NSInteger pinLength;
@property (nonatomic, assign) BOOL enableBiometric;

+ (void)showControllerWithAction:(PLPinViewControllerAction)action enableCancel:(BOOL)enableCancel pinLength:(NSInteger)pinLength delegate:(id<PLPinViewControllerDelegate>)delegate animated:(BOOL)animated biometric:(BOOL)biometric;



+(void)dismiss;


-(void)presentContainedViewController:(UIViewController *)viewControllerToPresent animated:(BOOL)animated;

@end
