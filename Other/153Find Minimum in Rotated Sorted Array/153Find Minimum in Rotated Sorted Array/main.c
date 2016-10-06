//
//  main.c
//  153Find Minimum in Rotated Sorted Array
//
//  Created by 郑钦洪 on 16/5/18.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
int findMin(int* nums, int numsSize) {
    if(nums == NULL || numsSize < 0){
        return -1;
    }
    int begin = 0, end = numsSize - 1;
    while (begin < end) { // 相等的时候退出
        int mid = (begin + end)/2; // 中间值
        if (nums[mid] > nums[end]) { // 如果中点比较大 那么begin等于中点＋1
            begin = mid+1;
        }else{ // 如果中点小于end 那么end往前走，这里要保留mid
            end = mid;
        }
    }
    return nums[begin];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[2] = {2,1};
    int result = findMin(nums, 2);
    printf("%d",result);
    return 0;
}
