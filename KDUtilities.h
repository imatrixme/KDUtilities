//
//  KDCUtil.h
//  koudaixiang
//
//  Created by Liu Yachen on 2/13/12.
//  Copyright (c) 2012 Suixing Tech. All rights reserved.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_IOS
#import "KDUtilities+iOS.h"
#endif


#define KDUtilRemoveNotificationCenterObserverDealloc - (void)dealloc{ [[NSNotificationCenter defaultCenter] removeObserver:self]; }

#define KDUtilDefineWeakSelfRef __weak __typeof(self) weakSelf = self;
#define KDUtilDefineStrongSelfRefFromWeakSelfRef __strong __typeof(self) strongSelf = weakSelf;

#define KDUtilThrowNoImplementationException @throw [NSException exceptionWithName:NSInternalInconsistencyException reason:[NSString stringWithFormat:@"This method has not been implemented: %@", NSStringFromSelector(_cmd)] userInfo:nil];

//#define weakify(var) __weak typeof(var) AHKWeak_##var = var;
//#define strongify(var) \
//_Pragma("clang diagnostic push") \
//_Pragma("clang diagnostic ignored \"-Wshadow\"") \
//__strong typeof(var) var = AHKWeak_##var; \
//_Pragma("clang diagnostic pop")


NS_INLINE BOOL KDUtilIsObjectNull(id object) {
    return object == nil || object == [NSNull null];
}

NS_INLINE BOOL KDUtilIsStringValid(NSString *str) {
    return str != nil && (id)str != [NSNull null] && ![str isEqualToString:@""];
}

NS_INLINE NSString *KDUtilStringWithInvalidPlaceholder(NSString *str, NSString *placeholder) {
    return KDUtilIsStringValid(str) ? str : placeholder;
}

extern NSNumber *KDUtilIntegerValueNumberGuard(id obj);
extern NSString *KDUtilStringGuard(id obj);

extern void KDAssert(BOOL eval, NSString *format, ...);

@interface NSObject (KDUtilitiesNotNull)

- (BOOL)KD_notNull;

@end

#define KDSimpleError(reason) [NSError errorWithDomain:@"KDSimpleError" code:0 userInfo:@{NSLocalizedDescriptionKey: reason}]


extern BOOL KDUtilIsOSMajorVersionHigherOrEqual(int version);

#if DEBUG
#define KDUtilConfirmOnMainThread _KDUtilConfirmOnMainThread();

NS_INLINE void _KDUtilConfirmOnMainThread() {
    KDAssert([NSThread isMainThread], @"KDUtilConfirmOnMainThread");
}
#else
#define KDUtilConfirmOnMainThread {}
#endif


@interface NSNumber (KDUtilities)

- (void)KD_forLoop:(void (^)(int i))block;

@end
