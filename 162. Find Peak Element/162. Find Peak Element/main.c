//
//  main.c
//  162. Find Peak Element
//
//  Created by 郑钦洪 on 16/5/17.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize-1;
    while (left < right) {
        int mid1 = left + (right - left)/2;
        int mid2 = mid1 + 1;
        if (nums[mid1] < nums[mid2]) {
            left = mid2;
        }else {
            right = mid1;
        }
    }
    return left;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[4] = {1,2,3,1};
    int a = findPeakElement(nums, 4);
    printf("%d",a);
    return 0;
}
