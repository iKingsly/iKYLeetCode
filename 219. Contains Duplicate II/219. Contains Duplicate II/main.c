//
//  main.c
//  219. Contains Duplicate II
//
//  Created by 郑钦洪 on 16/5/15.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[2] = {1,2};
    containsNearbyDuplicate(nums, 2, 2);
    return 0;
}

int containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (numsSize < 2) {
        return -1;
    }
    int min = INT32_MAX;
    int max = INT32_MIN;
    for (int i = 0; i < numsSize; i++) {
        min = min < nums[i] ? min : nums[i];
        max = max > nums[i] ? max:nums[i];
    }
    
    int *flagNums = malloc(sizeof(int) * (max - min) + 100);
    
    for (int i = 0; i < max - min + 100; i++) {
        flagNums[i] = 0;
    }
    for(int i = 0; i < numsSize; i++){
        if (flagNums[nums[i]-min+100]) {
            if (i+flagNums[nums[i]-min+100]<=k) {
                return 1;
            }
        }else{
            flagNums[nums[i]-min] = i;
        }
    }
    return -1;
}