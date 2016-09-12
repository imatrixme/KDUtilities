//
//  KDABridge.m
//  Surge Dashboard
//
//  Created by Blankwonder on 7/30/16.
//  Copyright © 2016 Yach. All rights reserved.
//

#import "KDABridge.h"

@implementation NSTextField (KDABridge)

- (NSString *)text {
    return self.stringValue;
}

- (void)setText:(NSString *)text {
    self.stringValue = text ?: @"";
}

@end

@implementation NSButton (KDABridge)

- (void)setSelected:(BOOL)selected {
    self.state = selected ? NSOnState : NSOffState;
}

- (BOOL)selected {
    return self.state == NSOnState;
}

@end