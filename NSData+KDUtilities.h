//
//  NSData+KDUtilities.h
//  Kata
//
//  Created by Blankwonder on 6/27/15.
//  Copyright © 2015 Daxiang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (KDUtilities)

- (NSString *)stringWithUTF8Encoding;
- (NSString *)stringWithEncoding:(NSStringEncoding)encoding;
- (NSString *)stringValue;
- (NSArray *)componentsSeparatedByData:(NSData *)separator;

- (NSString *)KD_MD5;

@end
