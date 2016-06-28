//
//  main.cpp
//  剑指offer:面试题40:数组中只出现一次的数字
//
//  Created by 郑钦洪 on 16/6/28.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
unsigned int FindFirstBitIs1 (int num) {
    int indexBit = 0;
    while (((num & 1) == 0 ) && (indexBit < 8 * sizeof(int))) {
        num = num >> 1;
        ++ indexBit;
    }
    return indexBit;
}

bool isBit1 (int num, unsigned int indexBit) {
    num = num >> indexBit;
    return (num & 1);
}


void FindNumsAppearOnce (int data[], int length, int *num1, int *num2) {
    if (data == NULL || length < 2) {
        return;
    }
    int resultExclusiveOr = 0;
    for (int i = 0; i < length; i++) {
        resultExclusiveOr ^= data[i];
    }
    
    unsigned int BitNumber = FindFirstBitIs1(resultExclusiveOr);
    
    *num1 = *num2 = 0;
    for (int j = 0 ; j < length; j++) {
        if (isBit1(data[j], BitNumber)) {
            *num1 ^= data[j];
        } else {
            *num2 ^= data[j];
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int data[] = {2,4,3,6,3,2,5,5};
    int a,b;
    FindNumsAppearOnce(data, 8, &a, &b);
    printf("a %d \nb %d\n",a,b);
    return 0;
}
