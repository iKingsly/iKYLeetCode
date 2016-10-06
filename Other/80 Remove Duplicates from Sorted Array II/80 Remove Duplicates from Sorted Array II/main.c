//
//  main.c
//  80 Remove Duplicates from Sorted Array II
//
//  Created by 郑钦洪 on 16/5/18.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 3)
        return numsSize;

    int head = 2;
    for (int i = 2; i<numsSize; i++) {
        if (nums[head-2] != nums[i]) {
            nums[head++] = nums[i];
        }
    }
    return head;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[6] = {1,1,1,2,2,3};
    
    int result = removeDuplicates(nums, 6);
    printf("%d",result);
    return 0;
}
