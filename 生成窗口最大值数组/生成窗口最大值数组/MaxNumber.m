//
//  MaxNumber.m
//  生成窗口最大值数组
//
//  Created by 郑钦洪 on 16/7/26.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#import "MaxNumber.h"

@implementation MaxNumber
- (NSMutableArray *)getMaxWindowsWithNumbers:(NSArray *)arr andWindows:(int) w {
    NSMutableArray *results = [NSMutableArray array];
    if (arr == nil || arr.count <= 0 || w < 1 || arr.count < w) {
        return nil;
    }
    
    NSMutableArray *qMax = [NSMutableArray arrayWithCapacity:w];
    int index = 0;
    for (int i = 0; i < arr.count; i++) {
        while (qMax.count &&  arr[((int)qMax.lastObject)] <= arr[i]) {
            [qMax removeLastObject];
        }
        [qMax addObject:@(i)];
        if ( (int)[qMax firstObject] == i - w) {
            [qMax removeObjectAtIndex:0];
        }
        if (i >= w - 1) {
            [results addObject:arr[(int)[qMax firstObject]]];
        }
    }
    return results;
}
@end
