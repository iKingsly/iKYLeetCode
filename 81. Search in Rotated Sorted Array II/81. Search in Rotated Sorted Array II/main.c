//
//  main.c
//  81. Search in Rotated Sorted Array II
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
    return begin;
}
int SearchSubArray(int *nums, int begin,int end, int target){
    if (nums[begin] == target) {
        return 1;
    }else{
        int mid = (begin + end)/2;
        if (nums[mid] < target) {
            SearchSubArray(nums,mid + 1,end,target);
        }else{
            SearchSubArray(nums,begin,mid-1,target);
        }
    }
    return -1;
}
int search(int* nums, int numsSize, int target) {
    int index = findMin(nums,numsSize);
    if (target < nums[index]) { // 在左边
       return SearchSubArray(nums,0,index,target);
    }else{// 在右边
       return SearchSubArray(nums,index,numsSize-1,target);
    }
}
int main(int argc, const char * argv[]) {
    int nums[6] = {3,4,5,0,1,2};
    int result = search(nums, 6, 5);
    printf("Hello, World!\n");
    return 0;
}
