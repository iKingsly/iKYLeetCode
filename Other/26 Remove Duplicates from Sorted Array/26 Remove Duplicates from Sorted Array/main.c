//
//  main.c
//  26 Remove Duplicates from Sorted Array
//
//  Created by 郑钦洪 on 16/5/14.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 1) {
        return 0;
    }
    int count = 0;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i-1]){
            count++;
        }else{
            nums[i-count] = nums[i];
        }
    }
    return numsSize - count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[2] = {1,2};
    int num = removeDuplicates(a, 2);
    for (int i = 0; i < num; i++) {
        printf("%d",a[i]);
    }
    printf("Hello, World!\n");
    return 0;
}
