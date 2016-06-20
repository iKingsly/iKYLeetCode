//
//  main.cpp
//  剑指offer:面试题31:连续子数组的最大和
//
//  Created by 郑钦洪 on 16/6/20.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int FindGreatestSumOfSubArray(int *pData, int nLength) {
    if (pData == NULL || (nLength < 1)) {
        return -1;
    }
    int maxSum = 0;
    int Great = 0;
    for (int i = 0; i < nLength; i++) {
        if (Great <= 0) {
            Great = pData[i];
        } else {
            Great += pData[i];
        }
        
        if (Great > maxSum) {
            maxSum = Great;
        }
    }
    return maxSum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int numbers[] = {1,-2,3,10,-4,7,2,-5};
    int result = FindGreatestSumOfSubArray(numbers, 8);
    printf("%d\n",result);
    return 0;
}
