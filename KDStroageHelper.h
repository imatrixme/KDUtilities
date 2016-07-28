//
//  KDStroageHelper.h
//  Beacon Calendar
//
//  Created by Blankwonder on 8/4/14.
//
//

#import <Foundation/Foundation.h>

@interface KDStroageHelper : NSObject

+ (NSString *)documentDirectoryPath;
+ (NSString *)libraryDirectoryPath;
+ (NSString *)cacheDirectoryPath;
+ (NSString *)temporaryDirectoryPath;

+ (NSString *)applicationSupportDirectoryPathWithName:(NSString *)name;

+ (void)writeDataToLibrary:(NSData *)data identifier:(NSString *)identifier;
+ (NSData *)dataFromLibraryWithIdentifier:(NSString *)identifier;
+ (void)deleteDataFromLibraryWithIdentifier:(NSString *)identifier;
+ (NSDate *)dataModificationDateWithIdentifier:(NSString *)identifier;
+ (void)setDataModificationDate:(NSDate *)date identifier:(NSString *)identifier;

+ (void)deleteAllData;

@end
