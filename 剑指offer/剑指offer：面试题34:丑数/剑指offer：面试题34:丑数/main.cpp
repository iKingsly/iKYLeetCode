//
//  main.cpp
//  剑指offer：面试题34:丑数
//
//  Created by 郑钦洪 on 16/6/24.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int Min(int num1, int num2, int num3) {
    int min = (num1 < num2) ? num1 : num2;
    min = (min < num3) ? min : num3;
    return min;
}

int GetUglyNumber (int index) {
    if (index < 0) {
        return -1;
    }
    int *pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;
    
    int *pMultiply2 = pUglyNumbers;
    int *pMultiply3 = pUglyNumbers;
    int *pMultiply5 = pUglyNumbers;
    
    while (nextUglyIndex < index) {
        int min = Min(*pMultiply2, *pMultiply3, *pMultiply5);
        pUglyNumbers[nextUglyIndex] = min;
        while (*pMultiply2 * 2 < pUglyNumbers[nextUglyIndex]) {
            ++pMultiply2;
        }
        while (*pMultiply3 * 3 < pUglyNumbers[nextUglyIndex]) {
            ++pMultiply3;
        }
        while (*pMultiply5 * 5 < pUglyNumbers[nextUglyIndex]) {
            ++pMultiply5;
        }
        ++nextUglyIndex;
    }
    int ugly = pUglyNumbers[nextUglyIndex - 1];
    delete [] pUglyNumbers;
    return ugly;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
