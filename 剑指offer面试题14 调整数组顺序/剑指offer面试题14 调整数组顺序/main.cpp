//
//  main.cpp
//  剑指offer面试题14 调整数组顺序
//
//  Created by 郑钦洪 on 16/6/9.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
void ReorderOddEven(int *pData, unsigned int length){
    if (pData==NULL || length <= 1) {
        return;
    }
    int *pBegin = pData;
    int *pEnd = pData + length - 1;
    
    while (pBegin < pEnd) {
        while (pBegin < pEnd && (*pBegin & 0x1) != 0) { // 知道pBegin指向偶数
            pBegin++;
        }
        while (pBegin < pEnd && (*pEnd & 0x1) == 0) { // 直到pEnd指向奇数
            pEnd--;
        }
        
        if (pBegin < pEnd) {
            int temp = *pEnd;
            *pEnd = *pBegin;
            *pBegin = temp;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int test[6] = {1,2,3,4,5,6};
    ReorderOddEven(test, 6);
    for (int i = 0 ; i < 6; i++) {
        printf("%d\n",test[i]);
    }
    return 0;
}
