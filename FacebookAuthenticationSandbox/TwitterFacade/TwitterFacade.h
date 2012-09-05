//
//  Created by aistomin on 1/18/12.
//
//


#import <Foundation/Foundation.h>
#import "MGTwitterEngineDelegate.h"
#import "SA_OAuthTwitterController.h"
#import "SA_OAuthTwitterEngine.h"

@class ViewController;

typedef void(^TwitterEnterCredentialsCallback)(UIViewController *);
typedef void(^TwitterUserCallback)(NSString *);

@interface TwitterFacade : NSObject<SA_OAuthTwitterControllerDelegate, MGTwitterEngineDelegate>

@property(nonatomic, copy) TwitterEnterCredentialsCallback onEnterCredentials;
@property(nonatomic, copy) TwitterUserCallback onSessionRestored;
@property(nonatomic, copy) TwitterUserCallback onLoggedIn;
@property(nonatomic, copy) Callback onLoginError;
@property(nonatomic, copy) Callback onLoginCanceled;
@property(nonatomic, copy) Callback onLoggedOut;
@property(nonatomic, retain) SA_OAuthTwitterEngine* engine;


- (id)initWithAppConsumerKey:(NSString *)appConsumerKey appConsumerSecret:(NSString *)appConsumerSecret;

- (BOOL)isAuthorized;

- (void)login;

- (void)restoreSession;

- (void)logout;

@end