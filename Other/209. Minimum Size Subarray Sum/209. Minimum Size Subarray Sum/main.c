//
//  main.c
//  209. Minimum Size Subarray Sum
//
//  Created by 郑钦洪 on 16/5/15.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
int minSubArrayLen(int s, int* nums, int numsSize) {
    int l = 0, r = 0, sum = nums[0], min = INT32_MAX;

    while (r < numsSize) {
        if (sum >= s) {
            min = min > (r - l + 1) ? (r-l + 1) : min;
            sum -= nums[l++];
            continue;
        }else{
            sum += nums[++r];
        }
    }
    return min == INT32_MAX ? 0 : min;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[6] = {2,3,1,2,4,3};
    minSubArrayLen(7, nums, 6);
    return 0;
}
