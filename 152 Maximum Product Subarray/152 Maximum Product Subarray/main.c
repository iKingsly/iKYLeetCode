//
//  main.c
//  152 Maximum Product Subarray
//
//  Created by 郑钦洪 on 16/5/19.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int max(int a, int b){
    return a > b ? a : b;
}
int min(int a,int b){
    return a < b ? a : b;
}
int maxProduct(int* nums, int numsSize) {
    if(nums == NULL || numsSize < 1){
        return 0;
    }
    int dp_pre_min = nums[0];
    int dp_pre_max = nums[0];
    int dp_max = dp_pre_max;
    
    for (int i = 1; i < numsSize; i++) {
        int dp_cur_max = max(max(nums[i], dp_pre_max * nums[i]), dp_pre_min * nums[i]);
        int dp_cur_min = min(min(nums[i], dp_pre_max * nums[i]), dp_pre_min * nums[i]);
        if (dp_max < dp_cur_max) {
            dp_max = dp_cur_max;
        }
    
        dp_pre_max = dp_cur_max;
        dp_pre_min = dp_cur_min;

    }

    return dp_max;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
